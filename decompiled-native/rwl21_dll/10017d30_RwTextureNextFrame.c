// 10017d30 RwTextureNextFrame [Global]
// programa: RWL21.DLL

int RwTextureNextFrame(int param_1)

{
  int iVar1;
  
                    /* 0x17d30  503  RwTextureNextFrame */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_1000cba0(0x6e);
    return 0;
  }
  iVar1 = (*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x10)) % *(int *)(param_1 + 0xc);
  if (iVar1 < 0) {
    iVar1 = iVar1 + *(int *)(param_1 + 0xc);
  }
  iVar1 = RwSetTextureFrame(param_1,iVar1);
  return iVar1;
}


