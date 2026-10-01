// 10021200 RwSetUserRasterParameters [Global]
// program: RWL21.DLL

undefined4 RwSetUserRasterParameters(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
                    /* 0x21200  487  RwSetUserRasterParameters */
  if ((*(uint *)(param_1 + 0x40) & 4) == 0) {
    FUN_1000cba0(0x5b);
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x3c);
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x28) != param_2)) {
    FUN_1000cba0(0x16);
    return 0;
  }
  *(int *)(param_1 + 0x28) = param_2;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 8;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  if (iVar1 != 0) {
    RwSetTextureFrame(iVar1,*(int *)(iVar1 + 0x10));
  }
  return 1;
}


