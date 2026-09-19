// 100380f0 RwRenderStereoClump [Global]
// programa: RWL21.DLL

float * RwRenderStereoClump(float *param_1)

{
                    /* 0x380f0  350  RwRenderStereoClump */
  if (DAT_1005b73c == 0) {
    return (float *)0x0;
  }
  if (*(int *)(DAT_1005b73c + 0x46c) == 1) {
    RwRenderClump(param_1);
    return param_1;
  }
  RwBeginCameraUpdate(*(int *)(DAT_1005b73c + 0xc),DAT_1005b740);
  RwRenderClump(param_1);
  RwEndCameraUpdate(*(int *)(DAT_1005b73c + 0xc));
  RwBeginCameraUpdate(*(int *)(DAT_1005b73c + 0x23c),DAT_1005b740);
  RwRenderClump(param_1);
  RwEndCameraUpdate(*(int *)(DAT_1005b73c + 0x23c));
  return param_1;
}


