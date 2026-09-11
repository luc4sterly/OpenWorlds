# `.cmp` Stage 1 corpus coverage report

This is the project's real closing criterion for `.cmp` Stage 1 work: nothing is
claimed "decoded" without passing through this harness against the real game
corpus, not just the 3 hand-captured tutorial files (`test4b`/`rustwood`/`sball`)
used in earlier sessions.

**Method**: for every file, `tools/gamma-dll-debug-harness/cmp_ground_truth.py`
runs the OFFICIAL `cmpview.exe` (Knowledge Adventure 1993-95,
`tools/gdk-sdk/cmpview.exe`) natively under Wine and reads its real decoded
pixels directly off the rendered window (auto-detecting the image's on-screen
position, not a hardcoded offset). This is INDEPENDENT of our own decoder -
cmpview.exe decodes any real `.cmp` file today, Stage 1 or not.

**Ground-truth method calibrated and cross-validated this session, with real
evidence, not just re-asserted**: against `test4b.cmp` (self-designed, exactly
known expected pixels - see `cmp-stage2-decoder/README.md`) this harness's own
extraction reproduces the documented 256px-each-of-4-colors result exactly,
zero noise. Against `sball.cmp` (already independently verified byte-exact by
our own decoder), this harness's freshly-extracted ground truth and our
decoder's output are pixel-IDENTICAL (`compare -metric AE` = 0/16384 pixels
differ). One real bug was found and fixed while building this: the naive
"first non-white pixel" scan locked onto cmpview.exe's own ~4px black
window-frame border instead of the real image - fixed by requiring a solid
run of non-white pixels, not just one pixel of difference.

Then, for each file, the existing Java pipeline (`net.freeworlds.cmp.CmpTexture`,
via the `CmpDecodeCli` wrapper in `cmp-stage2-decoder/`) attempts to decode the
SAME file, and if it succeeds, the two are pixel-diffed. **OK** = byte-exact
against real ground truth. **FAIL** = either our decoder threw (with the real
exception message) or it produced pixels that don't match. **NOT TESTED** =
even the ground-truth extraction itself failed for that file (reported
honestly, never silently skipped).

## Corpus

`assets/WorldsPlayer/GroundZero/content.zip` (already versioned, genuine 2001
install archive) has 159 real `.cmp` files under `tex/*.cmp`. This report
covers **all 159**, which includes (as a strict subset) the **47 unique
texture names the real `GroundZero.world` scene actually references**
(measured by `WorldViewer`'s own material resolution - see
`docs/render-pipeline-reference.md` - not a static grep of every `.rwx` file
in the directory, which counts models never placed in the scene). All 47 are
present and were ground-truthed successfully in this run - see the table
below for the current per-file decode status of each.

## Current result: ground-truth extraction is solid; decode is 0% (expected -
## Stage 1 doesn't exist yet)

**Ground truth succeeded for 159/159 files (100%)** - the harness itself
(the actual deliverable of this task) is real, reliable infrastructure, not a
prototype. **Decode succeeded for 0/159** - every real file fails the same
way, `CmpTexture.load` throwing `NoSuchFileException` on a `.palette.txt`
companion file that only exists for the 3 old hand-captured tutorial files.
This is the expected, honest baseline: Stage 1 (the Huffman bit-decoder that
turns raw `.cmp` bytes into the symbol streams `CmpTexture`/`CmpStage2`
consume) is a separate, parallel effort in this same session - see
`docs/cmp-texture-format-reference.md` for its status. Once Stage 1 exists,
re-running this exact harness (`python3
tools/gamma-dll-debug-harness/cmp_stage1_coverage.py <dir> --report
docs/cmp-stage1-coverage.md`) is the real, non-negotiable test of whether it
actually works against real files - not just the 3 tutorial ones.

**159 files tested: 0 OK, 159 FAIL, 0 NOT TESTED (total run time 502s)**

| file | status | dims | reason |
|---|---|---|---|
| `auboxcei.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/auboxcei.palette.txt |
| `auceil2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/auceil2.palette.txt |
| `aufloor1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/aufloor1.palette.txt |
| `auledge.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/auledge.palette.txt |
| `auramp1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/auramp1.palette.txt |
| `aured.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/aured.palette.txt |
| `ausquar2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/ausquar2.palette.txt |
| `auwall2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/auwall2.palette.txt |
| `avdoor.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/avdoor.palette.txt |
| `avdrl.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/avdrl.palette.txt |
| `avdrr.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/avdrr.palette.txt |
| `avdrrl.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/avdrrl.palette.txt |
| `avflr1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/avflr1.palette.txt |
| `avflr2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/avflr2.palette.txt |
| `avflr3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/avflr3.palette.txt |
| `basket.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/basket.palette.txt |
| `baskethandle.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/baskethandle.palette.txt |
| `bback1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bback1.palette.txt |
| `bback2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bback2.palette.txt |
| `bback3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bback3.palette.txt |
| `bback.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bback.palette.txt |
| `bbq_grill_side1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bbq_grill_side1.palette.txt |
| `bbq_grill_sides.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bbq_grill_sides.palette.txt |
| `bbq_inside1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bbq_inside1.palette.txt |
| `bbq_inside2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bbq_inside2.palette.txt |
| `bbq_inside3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bbq_inside3.palette.txt |
| `bbq_sides.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bbq_sides.palette.txt |
| `bkwl1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bkwl1.palette.txt |
| `bkwl2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bkwl2.palette.txt |
| `bkwl4.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bkwl4.palette.txt |
| `blabel1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/blabel1.palette.txt |
| `blink3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/blink3.palette.txt |
| `blktile.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/blktile.palette.txt |
| `bside1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bside1.palette.txt |
| `bside2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/bside2.palette.txt |
| `btop.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/btop.palette.txt |
| `cactus3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/cactus3.palette.txt |
| `coke_01a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/coke_01a.palette.txt |
| `coke_03b.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/coke_03b.palette.txt |
| `coke_03.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/coke_03.palette.txt |
| `cokecan1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/cokecan1.palette.txt |
| `cokecan2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/cokecan2.palette.txt |
| `cokecan3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/cokecan3.palette.txt |
| `coketop.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/coketop.palette.txt |
| `cstgbs3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/cstgbs3.palette.txt |
| `cstgtp3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/cstgtp3.palette.txt |
| `cstgwl3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/cstgwl3.palette.txt |
| `ctceil.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/ctceil.palette.txt |
| `ctflr.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/ctflr.palette.txt |
| `dcm1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/dcm1.palette.txt |
| `ddr1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/ddr1.palette.txt |
| `dgrass.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/dgrass.palette.txt |
| `dgrassx1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/dgrassx1.palette.txt |
| `dr1128.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/dr1128.palette.txt |
| `dr2128.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/dr2128.palette.txt |
| `enfloor3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/enfloor3.palette.txt |
| `enwall1a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/enwall1a.palette.txt |
| `enwall1b.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/enwall1b.palette.txt |
| `enwall2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/enwall2.palette.txt |
| `fence1a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/fence1a.palette.txt |
| `flr1c.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/flr1c.palette.txt |
| `flrlite3a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/flrlite3a.palette.txt |
| `flrlite3b.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/flrlite3b.palette.txt |
| `flrlite5a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/flrlite5a.palette.txt |
| `flrlite5.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/flrlite5.palette.txt |
| `flwside1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/flwside1.palette.txt |
| `frame1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/frame1.palette.txt |
| `gawall.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/gawall.palette.txt |
| `ggb_grill.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/ggb_grill.palette.txt |
| `goldceil.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/goldceil.palette.txt |
| `goldwall.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/goldwall.palette.txt |
| `grill_metal.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/grill_metal.palette.txt |
| `grnd1a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/grnd1a.palette.txt |
| `grnd1b.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/grnd1b.palette.txt |
| `grnd1c.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/grnd1c.palette.txt |
| `grnd1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/grnd1.palette.txt |
| `jtop2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/jtop2.palette.txt |
| `kevent1a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent1a.palette.txt |
| `kevent1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent1.palette.txt |
| `kevent2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent2.palette.txt |
| `kevent3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent3.palette.txt |
| `kevent4.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent4.palette.txt |
| `kevent5a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent5a.palette.txt |
| `kevent5.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent5.palette.txt |
| `kevent6.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent6.palette.txt |
| `kevent7.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent7.palette.txt |
| `kevent8.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kevent8.palette.txt |
| `kiwl1a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kiwl1a.palette.txt |
| `kiwl1b.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kiwl1b.palette.txt |
| `knews1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/knews1.palette.txt |
| `knews2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/knews2.palette.txt |
| `knews3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/knews3.palette.txt |
| `knews4.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/knews4.palette.txt |
| `knews5.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/knews5.palette.txt |
| `knews6.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/knews6.palette.txt |
| `knews7.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/knews7.palette.txt |
| `knews8.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/knews8.palette.txt |
| `kstore1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kstore1.palette.txt |
| `kstore2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kstore2.palette.txt |
| `kstore3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kstore3.palette.txt |
| `kstore4.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kstore4.palette.txt |
| `kstore5.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kstore5.palette.txt |
| `kstore6.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kstore6.palette.txt |
| `kstore7.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kstore7.palette.txt |
| `kstore8.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/kstore8.palette.txt |
| `labflr2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/labflr2.palette.txt |
| `leftb.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/leftb.palette.txt |
| `leftm.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/leftm.palette.txt |
| `ms6.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/ms6.palette.txt |
| `nsky.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/nsky.palette.txt |
| `pceil3a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/pceil3a.palette.txt |
| `pceil3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/pceil3.palette.txt |
| `pilar1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/pilar1.palette.txt |
| `plane1a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/plane1a.palette.txt |
| `plane1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/plane1.palette.txt |
| `plane2a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/plane2a.palette.txt |
| `plane2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/plane2.palette.txt |
| `plane3a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/plane3a.palette.txt |
| `plane3b.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/plane3b.palette.txt |
| `plane3c.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/plane3c.palette.txt |
| `plane3d.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/plane3d.palette.txt |
| `post1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/post1.palette.txt |
| `rd10.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd10.palette.txt |
| `rd11.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd11.palette.txt |
| `rd12.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd12.palette.txt |
| `rd1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd1.palette.txt |
| `rd2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd2.palette.txt |
| `rd3.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd3.palette.txt |
| `rd4.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd4.palette.txt |
| `rd5.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd5.palette.txt |
| `rd6.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd6.palette.txt |
| `rd7.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd7.palette.txt |
| `rd8.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd8.palette.txt |
| `rd9.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rd9.palette.txt |
| `rkgrnd.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rkgrnd.palette.txt |
| `rock1a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/rock1a.palette.txt |
| `roofb.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/roofb.palette.txt |
| `signau.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/signau.palette.txt |
| `signav.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/signav.palette.txt |
| `sky1a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/sky1a.palette.txt |
| `sky2a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/sky2a.palette.txt |
| `sky3a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/sky3a.palette.txt |
| `sky4a.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/sky4a.palette.txt |
| `sky.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/sky.palette.txt |
| `ss7.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/ss7.palette.txt |
| `ssky1.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/ssky1.palette.txt |
| `steak_side.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/steak_side.palette.txt |
| `steak_top.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/steak_top.palette.txt |
| `stn2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/stn2.palette.txt |
| `table_top.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/table_top.palette.txt |
| `top.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/top.palette.txt |
| `umbrella_bottom.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/umbrella_bottom.palette.txt |
| `umbrella_top.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/umbrella_top.palette.txt |
| `unexit.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/unexit.palette.txt |
| `vendbot.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/vendbot.palette.txt |
| `vendside2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/vendside2.palette.txt |
| `vendside.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/vendside.palette.txt |
| `vendtop2.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/vendtop2.palette.txt |
| `vendtop.cmp` | FAIL | 128x128 | decode: FAIL NoSuchFileException: /tmp/gz-content-extract/tex/vendtop.palette.txt |
