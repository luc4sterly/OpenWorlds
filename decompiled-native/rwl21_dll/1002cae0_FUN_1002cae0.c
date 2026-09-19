// 1002cae0 FUN_1002cae0 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __fastcall FUN_1002cae0(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  uint *puVar7;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  int iVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  undefined8 uVar9;
  uint *puVar10;
  int local_4;
  
  if (param_3 == (uint *)0x0) {
    return (uint *)0x0;
  }
  uVar1 = param_3[6];
  uVar2 = param_3[0x11];
  if (uVar2 == 1) {
    uVar2 = *param_3;
    uVar5 = uVar2 & 0xffffff3f;
    *param_3 = uVar5;
    if (DAT_1005adec == 0) {
      uVar5 = uVar2 & 0xffffff1f;
    }
    else {
      uVar5 = uVar5 | 0x20;
    }
    *param_3 = uVar5;
    if (DAT_1005adf4 == (uint *)0x0) {
      if ((*param_3 & 0x30) != 0) {
        DAT_1005adf4 = param_3;
        param_3[1] = 0x4f000000;
        param_3[2] = 0x3c75c28f;
        param_3[3] = 0;
        *param_3 = *param_3 | 0x40;
        iVar8 = FUN_1002cea0((int)DAT_1005adf4,param_3);
        param_2 = extraout_EDX;
        if (iVar8 == 0) {
          *DAT_1005adf4 = *DAT_1005adf4 & 0xffffff9f;
          DAT_1005adf4 = (uint *)0x0;
          return param_3;
        }
      }
    }
    else {
      iVar8 = FUN_1002cea0((int)DAT_1005adf4,param_3);
      param_2 = extraout_EDX_00;
      if (iVar8 == 0) {
        return param_3;
      }
    }
    if ((*param_3 & 4) != 0) {
      *(uint **)(*(int *)(uVar1 + 0xc) + *(int *)(uVar1 + 0x1c) * 4) = param_3;
      *(int *)(uVar1 + 0x1c) = *(int *)(uVar1 + 0x1c) + 1;
    }
    puVar10 = (uint *)param_3[5];
    puVar7 = param_3;
    while (((puVar4 = puVar10, puVar4 != (uint *)0x0 && (puVar4[0x11] == 3)) &&
           ((puVar4[0x12] & 1) != 0))) {
      puVar10 = (uint *)puVar4[4];
      if ((puVar10 != (uint *)0x0) && (puVar7 != puVar10)) {
        FUN_1002cae0(puVar7,param_2,puVar10);
        param_2 = extraout_EDX_01;
      }
      puVar7 = puVar4;
      puVar10 = (uint *)puVar4[5];
    }
    if ((*param_3 & 4) == 0) {
      *(uint **)(*(int *)(uVar1 + 0xc) + *(int *)(uVar1 + 0x1c) * 4) = param_3;
      *(int *)(uVar1 + 0x1c) = *(int *)(uVar1 + 0x1c) + 1;
      return param_3;
    }
    puVar10 = (uint *)param_3[4];
    if ((uint *)param_3[4] == (uint *)0x0) {
      return param_3;
    }
    goto LAB_1002ce8c;
  }
  if (uVar2 == 2) {
    iVar8 = 0;
    local_4 = 0;
    if (0 < (int)param_3[0x12]) {
      do {
        iVar8 = iVar8 + 4;
        uVar3 = *(undefined4 *)((param_3[0x13] - 4) + iVar8);
        FUN_1002cae0(uVar3,param_2,(uint *)uVar3);
        local_4 = local_4 + 1;
        param_2 = extraout_EDX_02;
      } while (local_4 < (int)param_3[0x12]);
    }
    puVar7 = DAT_1005adf4;
    if (DAT_1005adf0 != 0) {
      return param_3;
    }
    if (DAT_1005adf4 == (uint *)0x0) {
      return param_3;
    }
    puVar10 = *(uint **)(*(int *)(uVar1 + 0xc) + -4 + *(int *)(uVar1 + 0x1c) * 4);
    if (DAT_1005adf4 == puVar10) {
      FUN_1001ec00((undefined4 *)DAT_1005adf4[3]);
      *puVar7 = *puVar7 & 0xffffff9f;
    }
    else {
      puVar10[3] = (uint)DAT_1005adf4;
      puVar7 = *(uint **)(*(int *)(uVar1 + 0xc) + -4 + *(int *)(uVar1 + 0x1c) * 4);
      *puVar7 = *puVar7 | 0x80;
    }
    DAT_1005adf4 = (uint *)0x0;
    return param_3;
  }
  if (uVar2 != 3) {
    FUN_1000cba0(0x65);
    return param_3;
  }
  puVar7 = param_3 + 0x12;
  *puVar7 = 0;
  if ((*param_3 & 0x10) != 0) {
    DAT_1005adf0 = DAT_1005adf0 + 1;
    iVar8 = *(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218);
    if (iVar8 == 1) {
      uVar9 = RwDotProduct(param_3 + 0x13,param_2);
      param_2 = (undefined4)((ulonglong)uVar9 >> 0x20);
      iVar6 = 3;
      iVar8 = extraout_ECX;
      if ((float10)_DAT_1005223c <=
          ((float10)(float)param_3[0x17] + (float10)(float)param_3[0x16]) * (float10)_DAT_10052238 +
          extraout_ST0) goto LAB_1002cd3f;
    }
    else {
      if (iVar8 != 2) {
        iVar6 = 2;
        goto LAB_1002cd3f;
      }
      uVar9 = RwDotProduct(param_3 + 0x13,param_2);
      param_2 = (undefined4)((ulonglong)uVar9 >> 0x20);
      iVar6 = 3;
      iVar8 = extraout_ECX_00;
      if ((float10)_DAT_1005223c <= -extraout_ST0_00) goto LAB_1002cd3f;
    }
    iVar6 = 1;
LAB_1002cd3f:
    if (iVar6 == 3) {
      DAT_1005adec = DAT_1005adec + 1;
      FUN_1002cae0(param_3[0x19],param_2,(uint *)param_3[0x19]);
      DAT_1005adec = DAT_1005adec + -1;
      *puVar7 = *puVar7 | 1;
      FUN_1002cae0(extraout_ECX_01,param_3[0x18],(uint *)param_3[0x18]);
    }
    else {
      FUN_1002cae0(iVar8,param_2,(uint *)param_3[0x18]);
      DAT_1005adec = DAT_1005adec + 1;
      *puVar7 = *puVar7 | 1;
      FUN_1002cae0(extraout_ECX_02,param_3[0x19],(uint *)param_3[0x19]);
      DAT_1005adec = DAT_1005adec + -1;
    }
    puVar7 = DAT_1005adf4;
    DAT_1005adf0 = DAT_1005adf0 + -1;
    if (DAT_1005adf0 != 0) {
      return param_3;
    }
    if (DAT_1005adf4 == (uint *)0x0) {
      return param_3;
    }
    puVar10 = *(uint **)(*(int *)(uVar1 + 0xc) + -4 + *(int *)(uVar1 + 0x1c) * 4);
    if (DAT_1005adf4 == puVar10) {
      FUN_1001ec00((undefined4 *)DAT_1005adf4[3]);
      *puVar7 = *puVar7 & 0xffffff9f;
    }
    else {
      puVar10[3] = (uint)DAT_1005adf4;
      puVar7 = *(uint **)(*(int *)(uVar1 + 0xc) + -4 + *(int *)(uVar1 + 0x1c) * 4);
      *puVar7 = *puVar7 | 0x80;
    }
    DAT_1005adf4 = (uint *)0x0;
    return param_3;
  }
  iVar8 = *(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218);
  if (iVar8 == 1) {
    uVar9 = RwDotProduct(param_3 + 0x13,param_2);
    param_2 = (undefined4)((ulonglong)uVar9 >> 0x20);
    iVar6 = 3;
    iVar8 = extraout_ECX_03;
    if (((float10)(float)param_3[0x17] + (float10)(float)param_3[0x16]) * (float10)_DAT_10052238 +
        extraout_ST0_01 < (float10)_DAT_1005223c) {
LAB_1002ce61:
      iVar6 = 1;
    }
  }
  else if (iVar8 == 2) {
    uVar9 = RwDotProduct(param_3 + 0x13,param_2);
    param_2 = (undefined4)((ulonglong)uVar9 >> 0x20);
    iVar6 = 3;
    iVar8 = extraout_ECX_04;
    if (-extraout_ST0_02 < (float10)_DAT_1005223c) goto LAB_1002ce61;
  }
  else {
    iVar6 = 2;
  }
  if (iVar6 == 3) {
    FUN_1002cae0(iVar8,param_2,(uint *)param_3[0x19]);
    *puVar7 = *puVar7 | 1;
    puVar7 = (uint *)param_3[0x18];
    param_2 = extraout_EDX_03;
    puVar10 = puVar7;
  }
  else {
    FUN_1002cae0(iVar8,param_2,(uint *)param_3[0x18]);
    *puVar7 = *puVar7 | 1;
    puVar7 = (uint *)param_3[0x19];
    param_2 = extraout_EDX_04;
    puVar10 = puVar7;
  }
LAB_1002ce8c:
  FUN_1002cae0(puVar7,param_2,puVar10);
  return param_3;
}


