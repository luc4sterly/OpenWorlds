// The screen and input of net.openworlds.awt.NativeScreen on SDL2: a window
// on Linux, the whole screen on the PSVita. Only built when the program uses
// it.
//
// One thread of its own (the "SDL thread") owns the window, the renderer and
// the event loop, as SDL wants: Java's compositor thread hands it pixels
// (nativePresent) and Java's input thread takes events from its queue
// (nativeNextEvent). Events are seven ints, as Screen.java describes.
//
// Input: the mouse (or the Vita's front touch screen, which SDL turns into
// a mouse) and the keyboard as they are; with a game controller (the Vita's
// buttons), the left stick moves a pointer the AWT draws, cross and circle
// are the left and right buttons, the d-pad and the right stick are the
// arrow keys (walking), L and R are Page Up and Page Down, start is Enter,
// select is Escape and triangle opens the keyboard (⚠️ VERIFY on a Vita).
#if __has_include("net/openworlds/awt/NativeScreen.h")
#include "net/openworlds/awt/NativeScreen.h"
#include "java/lang/String.h"
#include <atomic>
#include <cmath>
#include <condition_variable>
#include <cstring>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace {

// Screen.java's event kinds
enum { POINTER_MOVED = 1, POINTER_PRESSED = 2, POINTER_RELEASED = 3, WHEEL = 4, KEY_PRESSED = 5, KEY_RELEASED = 6, TEXT = 7, QUIT = 8 };

// java.awt.event.InputEvent masks, the old and the extended ones
const int SHIFT = 1 | (1 << 6), CTRL = 2 | (1 << 7), META = 4 | (1 << 8), ALT = 8 | (1 << 9);
const int BUTTON1_DOWN = 1 << 10, BUTTON2_DOWN = 1 << 11, BUTTON3_DOWN = 1 << 12;
// java.awt.event.KeyEvent locations
const int LOCATION_STANDARD = 1, LOCATION_LEFT = 2, LOCATION_RIGHT = 3, LOCATION_NUMPAD = 4;
const int CHAR_UNDEFINED = 0xFFFF;

struct Event {
    int v[7];
};

std::mutex lock;
std::condition_variable eventsReady;
std::condition_variable opened;
std::deque<Event> events;
std::vector<uint32_t> frame;
int width, height;
SDL_Rect dirty;
bool hasDirty;
bool started, ready;
std::string error;
std::atomic<bool> controller{false};
Uint32 wakeEvent;
// requests for the SDL thread
bool textRequested, textEnded;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
SDL_GameController *pad;

// the pointer driven by the left stick
float padX, padY;
int stickX, stickY;
// arrow keys held by the right stick, per axis: -1, 0 or 1
int heldX, heldY;
int mouseButtons;
// the character each pressed key typed, for its release
int keyChars[SDL_NUM_SCANCODES];

void push(int kind, int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0) {
    std::lock_guard<std::mutex> g(lock);
    events.push_back(Event{{kind, a, b, c, d, e, f}});
    eventsReady.notify_one();
}

int modifiers() {
    SDL_Keymod m = SDL_GetModState();
    int r = 0;
    if (m & KMOD_SHIFT) r |= SHIFT;
    if (m & KMOD_CTRL) r |= CTRL;
    if (m & KMOD_ALT) r |= ALT;
    if (m & KMOD_GUI) r |= META;
    return r | mouseButtons;
}

int buttonMask(int button) {
    return button == 2 ? BUTTON2_DOWN : button == 3 ? BUTTON3_DOWN : BUTTON1_DOWN;
}

/// SDL key → java.awt.event.KeyEvent.VK_* (0 if none) and its location.
int virtualKey(SDL_Keycode k, int &location) {
    location = LOCATION_STANDARD;
    if (k >= SDLK_a && k <= SDLK_z) return 'A' + (k - SDLK_a);
    if (k >= SDLK_0 && k <= SDLK_9) return '0' + (k - SDLK_0);
    if (k >= SDLK_F1 && k <= SDLK_F12) return 0x70 + (k - SDLK_F1);
    if (k >= SDLK_KP_1 && k <= SDLK_KP_9) {
        location = LOCATION_NUMPAD;
        return 0x61 + (k - SDLK_KP_1);
    }
    switch (k) {
        case SDLK_RETURN: return 0x0A;
        case SDLK_BACKSPACE: return 0x08;
        case SDLK_TAB: return 0x09;
        case SDLK_ESCAPE: return 0x1B;
        case SDLK_SPACE: return 0x20;
        case SDLK_DELETE: return 0x7F;
        case SDLK_INSERT: return 0x9B;
        case SDLK_HOME: return 0x24;
        case SDLK_END: return 0x23;
        case SDLK_PAGEUP: return 0x21;
        case SDLK_PAGEDOWN: return 0x22;
        case SDLK_LEFT: return 0x25;
        case SDLK_UP: return 0x26;
        case SDLK_RIGHT: return 0x27;
        case SDLK_DOWN: return 0x28;
        case SDLK_LSHIFT: location = LOCATION_LEFT; return 0x10;
        case SDLK_RSHIFT: location = LOCATION_RIGHT; return 0x10;
        case SDLK_LCTRL: location = LOCATION_LEFT; return 0x11;
        case SDLK_RCTRL: location = LOCATION_RIGHT; return 0x11;
        case SDLK_LALT: location = LOCATION_LEFT; return 0x12;
        case SDLK_RALT: location = LOCATION_RIGHT; return 0x12;
        case SDLK_LGUI: location = LOCATION_LEFT; return 0x20C;
        case SDLK_RGUI: location = LOCATION_RIGHT; return 0x20C;
        case SDLK_CAPSLOCK: return 0x14;
        case SDLK_PAUSE: return 0x13;
        case SDLK_PRINTSCREEN: return 0x9A;
        case SDLK_SCROLLLOCK: return 0x91;
        case SDLK_NUMLOCKCLEAR: location = LOCATION_NUMPAD; return 0x90;
        case SDLK_COMMA: return 0x2C;
        case SDLK_MINUS: return 0x2D;
        case SDLK_PERIOD: return 0x2E;
        case SDLK_SLASH: return 0x2F;
        case SDLK_SEMICOLON: return 0x3B;
        case SDLK_EQUALS: return 0x3D;
        case SDLK_LEFTBRACKET: return 0x5B;
        case SDLK_BACKSLASH: return 0x5C;
        case SDLK_RIGHTBRACKET: return 0x5D;
        case SDLK_BACKQUOTE: return 0xC0;
        case SDLK_QUOTE: return 0xDE;
        case SDLK_KP_0: location = LOCATION_NUMPAD; return 0x60;
        case SDLK_KP_ENTER: location = LOCATION_NUMPAD; return 0x0A;
        case SDLK_KP_PLUS: location = LOCATION_NUMPAD; return 0x6B;
        case SDLK_KP_MINUS: location = LOCATION_NUMPAD; return 0x6D;
        case SDLK_KP_MULTIPLY: location = LOCATION_NUMPAD; return 0x6A;
        case SDLK_KP_DIVIDE: location = LOCATION_NUMPAD; return 0x6F;
        case SDLK_KP_PERIOD: location = LOCATION_NUMPAD; return 0x6E;
        default: return 0;
    }
}

/// The character a key types without the text system (control characters), or CHAR_UNDEFINED.
int controlChar(SDL_Keycode k, int mods) {
    switch (k) {
        case SDLK_RETURN:
        case SDLK_KP_ENTER: return '\n';
        case SDLK_BACKSPACE: return '\b';
        case SDLK_TAB: return '\t';
        case SDLK_ESCAPE: return 0x1B;
        case SDLK_DELETE: return 0x7F;
        default: break;
    }
    // Ctrl+letter types the control character, as on Windows
    if ((mods & CTRL) && k >= SDLK_a && k <= SDLK_z)
        return 1 + (k - SDLK_a);
    return CHAR_UNDEFINED;
}

/// Decodes UTF-8 text into UTF-16 units.
std::vector<int> utf16(const char *s) {
    std::vector<int> out;
    const unsigned char *p = (const unsigned char *) s;
    while (*p) {
        int c = *p++, n = 0;
        if (c >= 0xF0) { c &= 0x07; n = 3; }
        else if (c >= 0xE0) { c &= 0x0F; n = 2; }
        else if (c >= 0xC0) { c &= 0x1F; n = 1; }
        for (; n > 0 && (*p & 0xC0) == 0x80; n--)
            c = (c << 6) | (*p++ & 0x3F);
        if (c >= 0x10000) {
            c -= 0x10000;
            out.push_back(0xD800 + (c >> 10));
            out.push_back(0xDC00 + (c & 0x3FF));
        } else {
            out.push_back(c);
        }
    }
    return out;
}

void key(bool press, int vk, int c, int location) {
    push(press ? KEY_PRESSED : KEY_RELEASED, 0, 0, vk, c, modifiers(), location);
}

void keyStroke(int vk) {
    key(true, vk, CHAR_UNDEFINED, LOCATION_STANDARD);
    key(false, vk, CHAR_UNDEFINED, LOCATION_STANDARD);
}

void keyEvent(const SDL_Event &e) {
    bool press = e.type == SDL_KEYDOWN;
    int location;
    int vk = virtualKey(e.key.keysym.sym, location);
    SDL_Scancode sc = e.key.keysym.scancode;
    int c;
    if (press) {
        c = controlChar(e.key.keysym.sym, modifiers());
        // the character comes as SDL_TEXTINPUT right after its key: it goes in the key's event
        SDL_Event next;
        if (c == CHAR_UNDEFINED && SDL_PeepEvents(&next, 1, SDL_PEEKEVENT, SDL_TEXTINPUT, SDL_TEXTINPUT) == 1) {
            std::vector<int> t = utf16(next.text.text);
            if (t.size() == 1) {
                SDL_PeepEvents(&next, 1, SDL_GETEVENT, SDL_TEXTINPUT, SDL_TEXTINPUT);
                c = t[0];
            }
        }
        if (sc >= 0 && sc < SDL_NUM_SCANCODES)
            keyChars[sc] = c;
    } else {
        c = sc >= 0 && sc < SDL_NUM_SCANCODES && keyChars[sc] ? keyChars[sc] : controlChar(e.key.keysym.sym, modifiers());
    }
    if (vk == 0 && c == CHAR_UNDEFINED)
        return;
    key(press, vk, c, location);
}

void pointer(int kind, int x, int y, int button) {
    push(kind, x, y, button, 0, modifiers(), 0);
}

void padButton(int button, bool down) {
    switch (button) {
        case SDL_CONTROLLER_BUTTON_A:
        case SDL_CONTROLLER_BUTTON_B: {
            int b = button == SDL_CONTROLLER_BUTTON_A ? 1 : 3;
            if (down) mouseButtons |= buttonMask(b); else mouseButtons &= ~buttonMask(b);
            pointer(down ? POINTER_PRESSED : POINTER_RELEASED, (int) padX, (int) padY, b);
            break;
        }
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT: key(down, 0x25, CHAR_UNDEFINED, LOCATION_STANDARD); break;
        case SDL_CONTROLLER_BUTTON_DPAD_UP: key(down, 0x26, CHAR_UNDEFINED, LOCATION_STANDARD); break;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: key(down, 0x27, CHAR_UNDEFINED, LOCATION_STANDARD); break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN: key(down, 0x28, CHAR_UNDEFINED, LOCATION_STANDARD); break;
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER: key(down, 0x21, CHAR_UNDEFINED, LOCATION_STANDARD); break;
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: key(down, 0x22, CHAR_UNDEFINED, LOCATION_STANDARD); break;
        case SDL_CONTROLLER_BUTTON_START: key(down, 0x0A, '\n', LOCATION_STANDARD); break;
        case SDL_CONTROLLER_BUTTON_BACK: key(down, 0x1B, 0x1B, LOCATION_STANDARD); break;
        case SDL_CONTROLLER_BUTTON_Y:
            if (down) {
                if (SDL_IsTextInputActive()) SDL_StopTextInput(); else SDL_StartTextInput();
            }
            break;
        default: break;
    }
}

/// The right stick as arrow keys: pressed past half way, released under a third.
void stickKeys(int value, int &held, int negativeKey, int positiveKey) {
    int want = value < -16384 ? -1 : value > 16384 ? 1 : (std::abs(value) < 10922 ? 0 : held);
    if (want == held) return;
    if (held != 0) key(false, held < 0 ? negativeKey : positiveKey, CHAR_UNDEFINED, LOCATION_STANDARD);
    held = want;
    if (held != 0) key(true, held < 0 ? negativeKey : positiveKey, CHAR_UNDEFINED, LOCATION_STANDARD);
}

/// Moves the pad's pointer by the left stick: up to ~600 pixels a second, slower near the middle.
void movePadPointer(float seconds) {
    auto speed = [](int v) {
        float f = v / 32767.0f;
        if (std::fabs(f) < 0.15f) return 0.0f;
        return f * std::fabs(f) * 600.0f;
    };
    float dx = speed(stickX) * seconds, dy = speed(stickY) * seconds;
    if (dx == 0 && dy == 0) return;
    float nx = std::fmin(std::fmax(padX + dx, 0.0f), (float) (width - 1));
    float ny = std::fmin(std::fmax(padY + dy, 0.0f), (float) (height - 1));
    if ((int) nx != (int) padX || (int) ny != (int) padY) {
        padX = nx;
        padY = ny;
        pointer(POINTER_MOVED, (int) padX, (int) padY, 0);
    } else {
        padX = nx;
        padY = ny;
    }
}

void handle(const SDL_Event &e) {
    switch (e.type) {
        case SDL_QUIT:
            push(QUIT);
            break;
        case SDL_MOUSEMOTION:
            // the pad's pointer follows the mouse or the touch, and goes on from there
            padX = (float) e.motion.x;
            padY = (float) e.motion.y;
            pointer(POINTER_MOVED, e.motion.x, e.motion.y, 0);
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: {
            bool down = e.type == SDL_MOUSEBUTTONDOWN;
            int b = e.button.button == SDL_BUTTON_LEFT ? 1 : e.button.button == SDL_BUTTON_MIDDLE ? 2 : e.button.button == SDL_BUTTON_RIGHT ? 3 : 0;
            if (b == 0) break;
            if (e.button.which == SDL_TOUCH_MOUSEID) {
                // a touch: the pad's pointer goes there too
                padX = (float) e.button.x;
                padY = (float) e.button.y;
                pointer(POINTER_MOVED, e.button.x, e.button.y, 0);
            }
            if (down) mouseButtons |= buttonMask(b); else mouseButtons &= ~buttonMask(b);
            pointer(down ? POINTER_PRESSED : POINTER_RELEASED, e.button.x, e.button.y, b);
            break;
        }
        case SDL_MOUSEWHEEL: {
            int dy = e.wheel.direction == SDL_MOUSEWHEEL_FLIPPED ? e.wheel.y : -e.wheel.y;
            if (dy != 0) push(WHEEL, (int) padX, (int) padY, dy, 0, modifiers(), 0);
            break;
        }
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            keyEvent(e);
            break;
        case SDL_TEXTINPUT:
            // text with no key of its own: the IME's
            for (int c : utf16(e.text.text))
                push(TEXT, 0, 0, 0, c, 0, 0);
            break;
        case SDL_CONTROLLERDEVICEADDED:
            if (!pad) {
                pad = SDL_GameControllerOpen(e.cdevice.which);
                if (pad) {
#if defined(__vita__)
                    // the stick's pointer is drawn by the AWT (a desktop has its own mouse pointer)
                    controller = true;
#endif
                    padX = width / 2.0f;
                    padY = height / 2.0f;
                }
            }
            break;
        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_CONTROLLERBUTTONUP:
            padButton(e.cbutton.button, e.type == SDL_CONTROLLERBUTTONDOWN);
            break;
        case SDL_CONTROLLERAXISMOTION:
            switch (e.caxis.axis) {
                case SDL_CONTROLLER_AXIS_LEFTX: stickX = e.caxis.value; break;
                case SDL_CONTROLLER_AXIS_LEFTY: stickY = e.caxis.value; break;
                case SDL_CONTROLLER_AXIS_RIGHTX: stickKeys(e.caxis.value, heldX, 0x25, 0x27); break;
                case SDL_CONTROLLER_AXIS_RIGHTY: stickKeys(e.caxis.value, heldY, 0x26, 0x28); break;
                default: break;
            }
            break;
        case SDL_WINDOWEVENT:
            if (e.window.event == SDL_WINDOWEVENT_EXPOSED || e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                std::lock_guard<std::mutex> g(lock);
                dirty = SDL_Rect{0, 0, width, height};
                hasDirty = true;
            }
            break;
        default:
            break;
    }
}

/// Shows what Java presented since the last time.
void draw() {
    SDL_Rect r;
    {
        std::lock_guard<std::mutex> g(lock);
        if (!hasDirty) return;
        r = dirty;
        hasDirty = false;
        SDL_UpdateTexture(texture, &r, frame.data() + r.y * width + r.x, width * 4);
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void sdlThread() {
    SDL_SetHint(SDL_HINT_TOUCH_MOUSE_EVENTS, "1");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    bool ok = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) == 0;
    if (ok) {
#if defined(__vita__)
        window = SDL_CreateWindow("OpenWorlds", 0, 0, width, height, SDL_WINDOW_FULLSCREEN);
#else
        window = SDL_CreateWindow("OpenWorlds", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
#endif
        renderer = window ? SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED) : nullptr;
        if (window && !renderer)
            renderer = SDL_CreateRenderer(window, -1, 0);
        texture = renderer ? SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height) : nullptr;
        ok = texture != nullptr;
        if (ok) {
            // the picture keeps its proportions in a window of any size; the mouse is mapped back
            SDL_RenderSetLogicalSize(renderer, width, height);
            wakeEvent = SDL_RegisterEvents(1);
#if defined(__vita__)
            SDL_StopTextInput();
#endif
        }
    }
    {
        std::lock_guard<std::mutex> g(lock);
        if (!ok) error = SDL_GetError();
        ready = ok;
        started = true;
        opened.notify_all();
    }
    if (!ok) return;
    Uint32 last = SDL_GetTicks();
    while (true) {
        SDL_Event e;
        // with a stick held the pointer moves at 60 Hz, otherwise wait for something to happen
        if (SDL_WaitEventTimeout(&e, (stickX || stickY) ? 16 : 100)) {
            if (e.type != wakeEvent) handle(e);
            while (SDL_PollEvent(&e))
                if (e.type != wakeEvent) handle(e);
        }
        Uint32 now = SDL_GetTicks();
        movePadPointer((now - last) / 1000.0f);
        last = now;
        bool start = false, end = false;
        {
            std::lock_guard<std::mutex> g(lock);
            start = textRequested;
            end = textEnded;
            textRequested = textEnded = false;
        }
        if (end && SDL_IsTextInputActive()) SDL_StopTextInput();
        if (start && !SDL_IsTextInputActive()) SDL_StartTextInput();
        draw();
    }
}

void wake() {
    if (wakeEvent) {
        SDL_Event e{};
        e.type = wakeEvent;
        SDL_PushEvent(&e);
    }
}

}

extern "C" {

jbool SM_net_openworlds_awt_NativeScreen_nativeOpen_Array1_int_R_boolean(jcontext ctx, jobject size) {
    std::unique_lock<std::mutex> g(lock);
    if (!started) {
        width = 960;
        height = 544;
#if !defined(__vita__)
        // OPENWORLDS_SCREEN=WIDTHxHEIGHT on a desktop (the Vita's screen by default)
        if (const char *s = getenv("OPENWORLDS_SCREEN")) {
            int w, h;
            if (sscanf(s, "%dx%d", &w, &h) == 2 && w >= 320 && h >= 200) {
                width = w;
                height = h;
            }
        }
#endif
        frame.assign((size_t) width * height, 0xFF000000u);
        std::thread(sdlThread).detach();
    }
    ctx->suspended = true;
    opened.wait(g, [] { return started; });
    ctx->suspended = false;
    g.unlock();
    SAFEPOINT();
    if (!ready) return false;
    auto data = (jint *) ((jarray) NULL_CHECK(size))->data;
    data[0] = width;
    data[1] = height;
    return true;
}

jobject SM_net_openworlds_awt_NativeScreen_nativeError_R_java_lang_String(jcontext ctx) {
    std::lock_guard<std::mutex> g(lock);
    return (jobject) stringFromNative(ctx, error.c_str());
}

void SM_net_openworlds_awt_NativeScreen_nativePresent_Array1_int_int_int_int_int_int_int(jcontext ctx, jobject pixels, jint w, jint h, jint x, jint y, jint rw, jint rh) {
    auto data = (const uint32_t *) ((jarray) NULL_CHECK(pixels))->data;
    if (w != width || h != height || rw <= 0 || rh <= 0) return;
    {
        std::lock_guard<std::mutex> g(lock);
        for (int row = y; row < y + rh; row++)
            memcpy(frame.data() + (size_t) row * width + x, data + (size_t) row * width + x, (size_t) rw * 4);
        if (hasDirty) {
            SDL_Rect r{x, y, rw, rh};
            SDL_UnionRect(&dirty, &r, &dirty);
        } else {
            dirty = SDL_Rect{x, y, rw, rh};
            hasDirty = true;
        }
    }
    wake();
}

jbool SM_net_openworlds_awt_NativeScreen_nativeNextEvent_Array1_int_int_R_boolean(jcontext ctx, jobject event, jint timeoutMillis) {
    Event e;
    {
        std::unique_lock<std::mutex> g(lock);
        ctx->suspended = true;
        bool got = eventsReady.wait_for(g, std::chrono::milliseconds(timeoutMillis), [] { return !events.empty(); });
        ctx->suspended = false;
        if (!got) {
            g.unlock();
            SAFEPOINT();
            return false;
        }
        e = events.front();
        events.pop_front();
    }
    SAFEPOINT();
    auto data = (jint *) ((jarray) NULL_CHECK(event))->data;
    for (int i = 0; i < 7; i++)
        data[i] = e.v[i];
    return true;
}

jbool SM_net_openworlds_awt_NativeScreen_nativeDrawsCursor_R_boolean(jcontext ctx) {
    return controller.load();
}

void SM_net_openworlds_awt_NativeScreen_nativeRequestText_java_lang_String_boolean_boolean_java_lang_String(jcontext ctx, jobject current, jbool multiline, jbool password, jobject title) {
    {
        std::lock_guard<std::mutex> g(lock);
        textRequested = true;
    }
    wake();
}

void SM_net_openworlds_awt_NativeScreen_nativeEndText(jcontext ctx) {
    {
        std::lock_guard<std::mutex> g(lock);
        textEnded = true;
    }
    wake();
}

}
#endif
