#!/usr/bin/env python3
"""Replace `native` method declarations with logging stub bodies, and build
a caller map (which classes call which native method) as a side artifact.
"""
import re
import sys
from pathlib import Path
from collections import defaultdict

SRC = Path(sys.argv[1])
CALLER_MAP_OUT = Path(sys.argv[2])
DRY_RUN = "--dry-run" in sys.argv

DECL_RE = re.compile(
    r'^(?P<indent>[ \t]*)'
    r'(?P<mods>(?:(?:public|private|protected|static|final|synchronized)\s+)*)'
    r'native\s+'
    r'(?P<ret>[\w][\w\[\]]*)\s+'
    r'(?P<name>\w+)\s*'
    r'\((?P<params>[^)]*)\)\s*'
    r'(?P<throws>throws\s+[\w,\s]+)?'
    r';[ \t]*$',
    re.MULTILINE,
)


def default_return(ret_type):
    ret_type = ret_type.strip()
    if ret_type == "void":
        return None
    if "[" in ret_type:
        return "null"
    if ret_type == "boolean":
        # Policy choice (not a fact about the original behavior): most
        # boolean natives gate "if (!check()) bail/exit" control flow at
        # startup (hardware/capability checks, single-instance sync, etc.).
        # Defaulting to `true` lets the mocked client push further into
        # real code (login, networking, UI) instead of exiting at the
        # first guard - which is the whole point of this tool. Flip
        # individual stubs to `false` once their real semantics are known.
        return "true"
    if ret_type == "long":
        return "0L"
    if ret_type == "float":
        return "0.0F"
    if ret_type == "double":
        return "0.0D"
    if ret_type == "char":
        return "'\\0'"
    if ret_type in ("byte", "short", "int"):
        return "0"
    return "null"  # any reference type (String, Object, custom class...)


def parse_params(params_str):
    params_str = params_str.strip()
    if not params_str:
        return []
    out = []
    for p in params_str.split(","):
        p = p.strip()
        m = re.match(r'^(.*\S)\s+(\w+)$', p)
        if m:
            out.append((m.group(1).strip(), m.group(2).strip()))
    return out


decl_count = 0
caller_map = defaultdict(list)  # "Class.method" -> list of "CallerClass:line"

java_files = sorted(SRC.rglob("*.java"))
file_texts = {f: f.read_text(errors="replace") for f in java_files}

# --- Pass 1: collect all native declarations (class, method, params) ---
declarations = []  # (file, class, method)
for f, text in file_texts.items():
    cls = f.stem
    for m in DECL_RE.finditer(text):
        declarations.append((f, cls, m.group("name")))

decl_by_method = defaultdict(list)
for f, cls, method in declarations:
    decl_by_method[method].append(cls)

# --- Pass 2: build caller map (qualified "Class.method(" or bare "method("
# inside the declaring class's own file) ---
for f, cls, method in declarations:
    key = f"{cls}.{method}"
    qualified_re = re.compile(re.escape(cls) + r'\.' + re.escape(method) + r'\s*\(')
    bare_re = re.compile(r'(?<!native )(?<!\w)' + re.escape(method) + r'\s*\(')
    for other_f, other_text in file_texts.items():
        other_cls = other_f.stem
        if other_f == f:
            for i, line in enumerate(other_text.splitlines(), 1):
                if bare_re.search(line) and "native" not in line:
                    caller_map[key].append(f"{other_cls}:{i} (self)")
        else:
            for i, line in enumerate(other_text.splitlines(), 1):
                if qualified_re.search(line):
                    caller_map[key].append(f"{other_cls}:{i}")

# --- Write caller map doc ---
out = []
out.append("# Call map of `native` methods (before the JNI mock)\n\n")
out.append(
    "Generated before converting each `native` into a logging stub, to find "
    "out which code paths actually exercise them at run time. `(self)` = "
    "unqualified call inside the file that declares the method itself.\n\n"
    "⚠️ **Known limitation, read before drawing conclusions**: this is a text "
    "grep (`Class.method(` qualified, or `method(` unqualified inside the "
    "same file). It does not understand polymorphism (calling through an "
    "interface or a superclass reference), nor `this.method()` invoked from "
    "a subclass, nor reflection. With this heuristic, **167 of the 365** "
    "methods come out as \"no calls found\" — that does NOT mean that all "
    "167 are dead code, only that this tool did not trivially find a call "
    "site for them. The only two cases confirmed as truly dead code "
    "(`PendingCacheDrone.nativeDestroy`, `Console.getVolumeInfo`) were "
    "verified separately, also cross-checking against the real exports of "
    "`gamma.dll` — see `docs/native-methods-map.md`. For any other method "
    "in this list, \"no calls found\" is a lead to investigate, not a "
    "conclusion.\n\n"
)
out.append(f"Total `native` declarations: **{len(declarations)}**\n\n")
for f, cls, method in sorted(declarations, key=lambda t: (t[1], t[2])):
    key = f"{cls}.{method}"
    callers = caller_map.get(key, [])
    out.append(f"### `{key}`\n")
    if callers:
        for c in callers:
            out.append(f"- {c}\n")
    else:
        out.append("- *(no calls found in the decompiled code)*\n")
    out.append("\n")
CALLER_MAP_OUT.write_text("".join(out))
print(f"Caller map written to {CALLER_MAP_OUT} ({len(declarations)} declarations)")

if DRY_RUN:
    sys.exit(0)

# --- Pass 3: rewrite native declarations into logging stubs ---
changed_files = 0
for f, text in file_texts.items():
    cls = f.stem

    def repl(m):
        global decl_count
        decl_count += 1
        indent = m.group("indent")
        mods = m.group("mods")
        ret = m.group("ret")
        name = m.group("name")
        params_str = m.group("params")
        throws = m.group("throws") or ""
        params = parse_params(params_str)
        arg_names = ", ".join(p[1] for p in params)
        log_args = f"new Object[]{{{arg_names}}}" if params else "new Object[0]"
        # Common "getter with fallback" convention in this codebase, e.g.
        # getIniString(String key, String default): when the LAST parameter
        # type matches a *reference* return type, echo it back instead of a
        # blind null - it's very likely the caller-supplied default, and
        # honoring it avoids spurious NPEs downstream (e.g.
        # ResourceBundle.getBundle(null,...)) for something the mock has no
        # way to know the "real" answer to anyway. Only for reference types
        # (where the generic default is null and a bare mismatch is a crash
        # risk) - NOT for boolean/numeric, where the blanket "push the
        # client further" policy (true / 0) is a deliberate choice and
        # shouldn't be silently overridden just because some unrelated
        # trailing parameter happens to share the same primitive type
        # (e.g. synchronizeStartup(String, boolean) is a real flag, not a
        # get-with-fallback pair).
        generic_default = default_return(ret)
        is_static = "static" in mods
        # Fluent "return this" builder convention, e.g.
        # Transform.scale(float,float,float) / Point3Temp.times(Transform):
        # mutate the receiver's native-backed state and return it so calls
        # chain (`a.scale(x).raise(y)`). When a non-static native's
        # declared return type is exactly its own enclosing class, a blind
        # `null` breaks every such chain with an NPE on the *next* call,
        # not this one - `this` is always a valid, correctly-typed, non-
        # null substitute (confirmed against real call sites - see
        # docs/worlds-chat-project.md sec. 4 - before generalizing this rule).
        if generic_default == "null" and not is_static and ret.strip() == cls:
            default = "this"
        elif generic_default == "null" and params and params[-1][0].strip() == ret.strip():
            default = params[-1][1]
        else:
            default = generic_default
        sig = f"{indent}{mods}{ret} {name}({params_str}){' ' + throws if throws else ''} {{"
        body = f"{indent}   NET.worlds.core.NativeMock.log(\"{cls}\", \"{name}\", {log_args});"
        if default is not None:
            body += f"\n{indent}   return {default};"
        return f"{sig}\n{body}\n{indent}}}"

    new_text, n = DECL_RE.subn(repl, text)
    if n:
        changed_files += 1
        f.write_text(new_text)

print(f"Rewrote {decl_count} native declarations across {changed_files} files")
