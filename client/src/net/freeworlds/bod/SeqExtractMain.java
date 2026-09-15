package net.freeworlds.bod;

import java.util.Map;

/**
 * CLI de verificacion para SeqParser: parsea cada .seq y resume version,
 * figura, joint raiz, duracion, joints y extras. Como con BodExtractMain,
 * no hay decoder de referencia independiente: la verificacion es
 * estructural (el parser exige consumir el archivo entero; cualquier
 * excepcion o byte sobrante = campo mal leido) mas coherencia de datos
 * (tiempos monotonos, cuaternion base de norma 1 en tracks 0x10).
 *
 * Uso: java -cp client/out net.freeworlds.bod.SeqExtractMain [-q] <file.seq> [...]
 *   -q: solo fallos y totales.
 */
public final class SeqExtractMain {
    public static void main(String[] args) throws Exception {
        boolean quiet = args.length > 0 && args[0].equals("-q");
        int first = quiet ? 1 : 0;
        if (args.length <= first) {
            System.err.println("Usage: SeqExtractMain [-q] <file.seq> [more.seq ...]");
            System.exit(2);
        }
        int ok = 0;
        int v1 = 0;
        int v7f = 0;
        int nonMonotonic = 0;
        int zeroBaseQuats = 0;
        int otherBadNorms = 0;
        for (int i = first; i < args.length; i++) {
            String path = args[i];
            SeqParser.SeqData d;
            try {
                d = SeqParser.parseFile(path);
            } catch (Exception e) {
                System.out.println("PARSE ERROR " + path + ": " + e);
                continue;
            }
            ok++;
            if (d.version == 1) {
                v1++;
            } else {
                v7f++;
            }
            int maxKeys = 0;
            for (Map.Entry<String, SeqParser.Track> e : d.joints.entrySet()) {
                SeqParser.Track t = e.getValue();
                maxKeys = Math.max(maxKeys, t.keys());
                for (int k = 1; k < t.keys(); k++) {
                    if (t.times[k] < t.times[k - 1]) {
                        nonMonotonic++;
                        System.out.println("NON-MONOTONIC " + path + " joint=" + e.getKey());
                        break;
                    }
                }
                if (t.sizeFlag == 0x10 && t.keys() > 0) {
                    float[] q = t.values[0];
                    double n = Math.sqrt(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]);
                    if (n == 0) {
                        zeroBaseQuats++;
                    } else if (Math.abs(n - 1) > 1e-3) {
                        otherBadNorms++;
                        System.out.println("NORM " + path + " joint=" + e.getKey() + " |q0|=" + n);
                    }
                }
            }
            if (!quiet) {
                System.out.println(path + ": version=0x" + Integer.toHexString(d.version)
                    + " figure=" + d.figure + " root=" + d.rootJoint + " duration=" + d.duration
                    + " joints=" + d.joints.size() + " extras=" + d.extras.size() + " maxKeys=" + maxKeys);
            }
        }
        int total = args.length - first;
        System.out.println(ok + " / " + total + " files fully consumed without error"
            + " (v1=" + v1 + ", 0x7f=" + v7f + "); non-monotonic tracks=" + nonMonotonic
            + "; zero base quats=" + zeroBaseQuats + "; other |q0|!=1=" + otherBadNorms);
    }
}
