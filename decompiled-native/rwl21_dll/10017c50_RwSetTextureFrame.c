// 10017c50 RwSetTextureFrame [Global]
// programa: RWL21.DLL

int RwSetTextureFrame(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x17c50  473  RwSetTextureFrame */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 == 0) {
    FUN_1000cba0(0x6e);
    return 0;
  }
  if ((param_2 < 0) || (*(int *)(param_1 + 0xc) <= param_2)) {
    FUN_1000cba0(0x14);
    param_1 = 0;
  }
  else {
    *(int *)(param_1 + 0x10) = param_2;
    iVar2 = *(int *)(param_1 + 0x1c);
    *(int *)(param_1 + 4) =
         *(int *)(iVar1 + 0x28) * *(int *)(iVar1 + 0x1c) * param_2 + *(int *)(iVar1 + 0x18);
    if (iVar2 != 0) {
      *(int *)(param_1 + 8) =
           ((*(int *)(iVar1 + 0x1c) >> 2) + (*(int *)(iVar1 + 0x1c) >> 1)) * *(int *)(iVar2 + 0x28)
           * param_2 + *(int *)(iVar2 + 0x18);
      return param_1;
    }
  }
  return param_1;
}


