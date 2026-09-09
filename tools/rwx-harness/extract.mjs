// Reference extractor for the RWX comparison harness.
//
// Parses a .rwx file with three-rwx-loader (the behavioral reference) and
// prints a canonical JSON summary to stdout, meant to be diffed against
// the equivalent output of the Java parser under construction.
//
// Deliberately strips the loader's own "rwx-scale-group" (a hardcoded 10x
// scale applied at the root by RWXLoader.js itself, lines ~2233-2239 -
// an Active Worlds unit convention baked into the JS *loader*, not
// something read from the .rwx text) so the comparison is apples-to-apples
// against a Java parser that emits raw RWX-unit geometry. See
// docs/rwx-format-reference.md for the full writeup.
import { JSDOM } from 'jsdom';
const dom = new JSDOM('<!DOCTYPE html>');
global.window = dom.window;
global.document = dom.window.document;
global.self = dom.window;

import fs from 'node:fs';
import path from 'node:path';
import RWXLoader from 'three-rwx-loader';
import { Matrix4, Vector3 } from 'three';

const rwxPath = process.argv[2];
if (!rwxPath) {
  console.error('usage: node extract.mjs <file.rwx> [resourcePath]');
  process.exit(2);
}
const resourcePath = process.argv[3] || path.dirname(rwxPath);
const text = fs.readFileSync(rwxPath, 'utf8');

const loader = new RWXLoader();
loader.setFlatten(false);
loader.setWaitFullLoad(true);
// Texture loading is disabled for the comparison harness: our test corpus
// only has .cmp-format Worlds textures on disk (no .jpg to match
// textureExtension), and letting the loader attempt+fail to load them
// corrupts the material's *color* too, not just the map - confirmed by
// direct inspection (every triangle's material comes back as flat gray
// "d8d8d8" with no map, regardless of the file's real Color/Texture
// commands, whenever texture loading is left enabled here). See
// docs/rwx-format-reference.md for the full writeup. Geometry (vertex
// positions/triangle indices) is unaffected either way - this only matters
// for material comparison.
loader.setEnableTextures(false);

function round(n, dp = 5) {
  const f = 10 ** dp;
  return Math.round(n * f) / f;
}

function extract(root) {
  const triangles = [];
  const materials = [];
  const materialIndex = new Map(); // dedupe by signature

  function materialKey(m) {
    const color = m.color ? m.color.getHexString() : null;
    const map = m.map ? m.map.name || m.map.source?.data?.src || 'texture' : null;
    return JSON.stringify({ color, opacity: round(m.opacity, 3), transparent: m.transparent, map });
  }

  function recordMaterial(m) {
    const key = materialKey(m);
    if (!materialIndex.has(key)) {
      materialIndex.set(key, materials.length);
      materials.push({
        color: m.color ? m.color.getHexString() : null,
        opacity: round(m.opacity, 3),
        transparent: !!m.transparent,
        map: m.map ? (m.map.name || 'texture') : null,
      });
    }
    return materialIndex.get(key);
  }

  function walk(node, parentMatrix) {
    const world = new Matrix4().multiplyMatrices(parentMatrix, node.matrix);

    if (node.geometry) {
      const geo = node.geometry;
      const pos = geo.attributes.position;
      const mats = Array.isArray(node.material) ? node.material : [node.material];
      const groups = geo.groups.length ? geo.groups : [{ start: 0, count: geo.index ? geo.index.count : pos.count, materialIndex: 0 }];

      for (const g of groups) {
        const matId = recordMaterial(mats[g.materialIndex] || mats[0]);
        const idx = geo.index;
        for (let i = g.start; i < g.start + g.count; i += 3) {
          const ia = idx ? idx.getX(i) : i;
          const ib = idx ? idx.getX(i + 1) : i + 1;
          const ic = idx ? idx.getX(i + 2) : i + 2;
          const va = new Vector3().fromBufferAttribute(pos, ia).applyMatrix4(world);
          const vb = new Vector3().fromBufferAttribute(pos, ib).applyMatrix4(world);
          const vc = new Vector3().fromBufferAttribute(pos, ic).applyMatrix4(world);
          triangles.push({
            v: [
              [round(va.x), round(va.y), round(va.z)],
              [round(vb.x), round(vb.y), round(vb.z)],
              [round(vc.x), round(vc.y), round(vc.z)],
            ],
            material: matId,
          });
        }
      }
    }

    for (const child of node.children) walk(child, world);
  }

  // Skip the loader's own root wrapper + the hardcoded 10x rwx-scale-group
  // (see file header) so units match a raw-RWX-unit Java parser.
  let start = root;
  const scaleGroup = root.children.find((c) => c.name === 'rwx-scale-group');
  const startMatrix = new Matrix4(); // identity - do NOT apply the 10x
  if (scaleGroup) {
    for (const child of scaleGroup.children) walk(child, startMatrix);
  } else {
    walk(root, startMatrix);
  }

  // Sort triangles for order-independent comparison (parsers may visit /
  // group geometry differently while producing the same model).
  triangles.sort((a, b) => JSON.stringify(a.v).localeCompare(JSON.stringify(b.v)));

  return {
    file: path.basename(rwxPath),
    triangleCount: triangles.length,
    vertexCount: triangles.length * 3,
    materialCount: materials.length,
    materials,
    triangles,
  };
}

loader.parse(rwxPath, text, resourcePath, (obj) => {
  try {
    const result = extract(obj);
    console.log(JSON.stringify(result));
  } catch (e) {
    console.error(JSON.stringify({ file: path.basename(rwxPath), error: String(e && e.stack || e) }));
    process.exitCode = 1;
  }
});

// Some texture-loading failures reject an unawaited internal Promise after
// parse() has already returned (see docs/rwx-format-reference.md) - they
// don't affect the geometry we already printed, so swallow them here
// instead of letting them crash the whole batch run.
process.on('unhandledRejection', () => {});
