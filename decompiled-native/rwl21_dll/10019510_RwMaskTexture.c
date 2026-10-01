// 10019510 RwMaskTexture [Global]
// program: RWL21.DLL

uint RwMaskTexture(uint param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x19510  287  RwMaskTexture */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (param_2 == (int *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    puVar1 = FUN_100223e0(*(int **)(param_1 + 0x18),0,param_2);
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    RwDestroyRaster(*(undefined4 **)(param_1 + 0x1c));
    *(undefined4 **)(param_1 + 0x1c) = puVar1;
    RwSetTextureFrame(param_1,*(int *)(param_1 + 0x10));
  }
  iVar2 = (**(code **)(PTR_DAT_1005b69c + 0x2a4))(*(undefined4 *)(param_1 + 0x18),param_2);
  return (iVar2 == 0) - 1 & param_1;
}


