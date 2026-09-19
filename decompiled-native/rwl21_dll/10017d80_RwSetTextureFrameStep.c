// 10017d80 RwSetTextureFrameStep [Global]
// programa: RWL21.DLL

int RwSetTextureFrameStep(int param_1,int param_2)

{
  int iVar1;
  
                    /* 0x17d80  474  RwSetTextureFrameStep */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  if ((iVar1 <= param_2) && (-param_2 != iVar1 && param_2 <= -iVar1)) {
    FUN_1000cba0(0x15);
    return 0;
  }
  *(int *)(param_1 + 0x14) = param_2;
  return param_1;
}


