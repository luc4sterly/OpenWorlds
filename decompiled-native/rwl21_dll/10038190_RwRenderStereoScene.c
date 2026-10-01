// 10038190 RwRenderStereoScene [Global]
// program: RWL21.DLL

uint * RwRenderStereoScene(uint *param_1)

{
                    /* 0x38190  351  RwRenderStereoScene */
  if (DAT_1005b73c == 0) {
    return (uint *)0x0;
  }
  if (*(int *)(DAT_1005b73c + 0x46c) == 1) {
    RwRenderScene(param_1);
    return param_1;
  }
  RwBeginCameraUpdate(*(int *)(DAT_1005b73c + 0xc),DAT_1005b740);
  RwRenderScene(param_1);
  RwEndCameraUpdate(*(int *)(DAT_1005b73c + 0xc));
  RwBeginCameraUpdate(*(int *)(DAT_1005b73c + 0x23c),DAT_1005b740);
  RwRenderScene(param_1);
  RwEndCameraUpdate(*(int *)(DAT_1005b73c + 0x23c));
  return param_1;
}


