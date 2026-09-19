// 10017120 RwEnvMapClump [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * RwEnvMapClump(float *param_1)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  int *piVar4;
  float *extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar5;
  int iVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  undefined8 uVar7;
  longlong lVar8;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float *local_8;
  float *local_4;
  
                    /* 0x17120  83  RwEnvMapClump */
  if (*(int *)(PTR_DAT_1005b69c + 0x10) == 0) {
    FUN_1000cba0(0x5c);
    return (float *)0x0;
  }
  if (param_1 != (float *)0x0) {
    FUN_100046c0((int)param_1);
    uVar5 = extraout_EDX;
    if (*(char *)((int)param_1 + 0x41) != '\0') {
      FUN_1001c650(param_1,param_1 + 0x11);
      *(undefined1 *)((int)param_1 + 0x41) = 0;
      uVar5 = extraout_EDX_00;
    }
    local_8 = param_1 + 0x15;
    pfVar2 = param_1 + 0x19;
    local_4 = pfVar2;
    pfVar3 = (float *)((int)param_1[0x22] + 0x3ac);
    for (iVar6 = *(int *)((int)param_1[0x22] + 8) + -9; -1 < iVar6; iVar6 = iVar6 + -1) {
      uVar7 = RwDotProduct(pfVar2,uVar5);
      local_18 = (float)extraout_ST0;
      RwDotProduct(pfVar3 + 0x13,(int)((ulonglong)uVar7 >> 0x20));
      local_14 = (float)extraout_ST0_00;
      RwDotProduct(local_4,pfVar3 + 0x13);
      local_10 = (float)extraout_ST0_01;
      rwLengthNormaliseVector(&local_18,&local_18);
      piVar4 = (int *)(PTR_DAT_1005b69c + 0x10);
      if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
        local_28 = param_1[8] * pfVar3[2] + param_1[0xc] +
                   *pfVar3 * *param_1 + param_1[4] * pfVar3[1];
        local_24 = param_1[9] * pfVar3[2] + param_1[0xd] +
                   param_1[1] * *pfVar3 + param_1[5] * pfVar3[1];
        local_20 = param_1[2] * *pfVar3 + param_1[6] * pfVar3[1] +
                   param_1[10] * pfVar3[2] + param_1[0xe];
        RwSubtractVector(&local_28,(float *)(*piVar4 + 0x34),&local_28);
      }
      else {
        local_28 = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x24);
        local_24 = *(float *)(*piVar4 + 0x28);
        local_20 = *(float *)(*piVar4 + 0x2c);
      }
      local_1c = local_28 * local_18 + local_20 * local_10;
      if (local_1c <= _DAT_10052128) {
        fVar1 = (local_24 * local_14 + local_1c) * _DAT_10052154;
        local_28 = local_28 - local_18 * fVar1;
        local_20 = local_20 - fVar1 * local_10;
      }
      else {
        fVar1 = (local_24 * local_14 - local_1c) * _DAT_10052154;
        local_28 = -(local_18 * fVar1 + local_28);
        local_20 = -(fVar1 * local_10 + local_20);
      }
      local_24 = local_24 - local_14 * fVar1;
      rwLengthNormaliseVector(&local_28,&local_28);
      if ((int)local_28 < 0x3f800001) {
        if ((uint)local_28 < 0xbf800001) {
          fStack_c = local_28;
        }
        else {
          fStack_c = -1.0;
        }
      }
      else {
        fStack_c = 1.0;
      }
      if ((int)local_24 < 0x3f800001) {
        if ((uint)local_24 < 0xbf800001) {
          local_1c = -local_24;
        }
        else {
          local_1c = 1.0;
        }
      }
      else {
        local_1c = -1.0;
      }
      lVar8 = __ftol();
      pfVar3[0x1a] = (float)((int)lVar8 + 0x8000U & 0xffff);
      lVar8 = __ftol();
      uVar5 = (undefined4)((ulonglong)lVar8 >> 0x20);
      pfVar3[0x19] = (float)((int)lVar8 + 0x8000U & 0xffff);
      pfVar2 = extraout_ECX;
      pfVar3 = pfVar3 + 0x1d;
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


