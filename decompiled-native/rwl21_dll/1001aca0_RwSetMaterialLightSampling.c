// 1001aca0 RwSetMaterialLightSampling [Global]
// program: RWL21.DLL

uint * RwSetMaterialLightSampling(uint *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
                    /* 0x1aca0  420  RwSetMaterialLightSampling */
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
    return (uint *)0x0;
  }
  if (param_2 == 1) {
    uVar5 = 0;
  }
  else {
    if (param_2 != 2) {
      FUN_1000cba0(0x1d);
      return (uint *)0x0;
    }
    uVar5 = 1;
  }
  if (param_1 == (uint *)0x0) {
    iVar4 = 1;
  }
  else {
    uVar1 = *param_1;
    if (uVar1 < 0x40) {
      if (uVar1 < 4) {
        iVar4 = 1;
      }
      else if (uVar1 < 8) {
        iVar4 = 2;
      }
      else {
        iVar4 = 4 - (uint)(uVar1 < 0xc);
      }
      goto LAB_1001ad17;
    }
    iVar4 = 0x67;
  }
  FUN_1000cba0(iVar4);
  iVar4 = 0;
LAB_1001ad17:
  if (iVar4 != 1) {
    if (iVar4 == 2) {
      uVar5 = uVar5 + 4;
    }
    else {
      if (iVar4 != 4) {
        FUN_1000cba0(0x1b);
        return (uint *)0x0;
      }
      if ((char)param_1[1] != -1) {
        uVar5 = uVar5 + 2;
      }
      if (param_1[0xd] == 0) {
        uVar5 = uVar5 + 0xc;
      }
      else {
        uVar5 = uVar5 + 0x14;
      }
    }
  }
  piVar2 = (int *)param_1[0xf];
  iVar4 = 0;
  *param_1 = uVar5;
  if (*piVar2 < 1) {
    return param_1;
  }
  piVar6 = piVar2 + 2;
  do {
    iVar3 = *piVar6;
    if (*(int *)(iVar3 + 0x2c) == iVar3) {
      FUN_1001a1e0(iVar3);
    }
    piVar6 = piVar6 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < *piVar2);
  return param_1;
}


