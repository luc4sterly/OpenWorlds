// 1001ab20 RwSetMaterialTexture [Global]
// program: RWL21.DLL

uint * RwSetMaterialTexture(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x1ab20  425  RwSetMaterialTexture */
  if ((param_2 != 0) && (*(int *)(param_2 + 0x18) == 0)) {
    FUN_1000cba0(0x6e);
    return (uint *)0x0;
  }
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
    return (uint *)0x0;
  }
  if ((param_1[0xd] != 0) && (param_2 != 0)) {
    param_1[0xd] = param_2;
    goto LAB_1001aba7;
  }
  if (param_1 == (uint *)0x0) {
    iVar2 = 1;
LAB_1001ab93:
    FUN_1000cba0(iVar2);
    iVar2 = 0;
  }
  else {
    uVar1 = *param_1;
    if (0x3f < uVar1) {
      iVar2 = 0x67;
      goto LAB_1001ab93;
    }
    if (uVar1 < 4) {
      iVar2 = 1;
    }
    else if (uVar1 < 8) {
      iVar2 = 2;
    }
    else {
      iVar2 = 4 - (uint)(uVar1 < 0xc);
    }
  }
  param_1[0xd] = param_2;
  RwSetMaterialGeometrySampling(param_1,iVar2);
LAB_1001aba7:
  if (param_1[0xd] == 0) {
    return param_1;
  }
  if (*(int *)(*(int *)(param_1[0xd] + 0x18) + 0x1c) != *(int *)(PTR_DAT_1005b69c + 700)) {
    *(byte *)(param_1 + 0xc) = (byte)param_1[0xc] & 0xf7;
    return param_1;
  }
  *(byte *)(param_1 + 0xc) = (byte)param_1[0xc] | 8;
  return param_1;
}


