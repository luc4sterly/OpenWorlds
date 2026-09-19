// 100030a0 FUN_100030a0 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_100030a0(int *param_1,undefined4 param_2,float *param_3,int param_4)

{
  float *pfVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  int *piVar6;
  int *piVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST0_07;
  float10 extraout_ST0_08;
  float10 extraout_ST0_09;
  undefined8 uVar9;
  float *pfVar10;
  float *local_48;
  float *local_40;
  float fStack_3c;
  float fStack_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  pfVar10 = &local_30;
  pfVar5 = local_c;
  if (param_4 == 0) {
    pfVar10 = local_18;
    pfVar5 = local_24;
  }
  pfVar1 = (float *)param_1[2];
  piVar7 = (int *)*param_1;
  local_48 = (float *)piVar7[2];
  RwSubtractVector(pfVar1,local_48,local_24);
  if (param_4 != 0) {
    RwDotProduct(param_4,extraout_EDX);
    pfVar4 = pfVar5;
    pfVar3 = (float *)RwScaleVector(param_3,(float)extraout_ST0,pfVar5);
    RwSubtractVector(local_24,pfVar3,pfVar4);
  }
  fVar8 = rwLengthNormaliseVector(local_c,pfVar5);
  if (fVar8 <= (float10)_DAT_10052070) {
    do {
      if (param_1 == piVar7) break;
      piVar7 = (int *)*piVar7;
      *(undefined4 *)*param_1 = 0;
      *(undefined4 *)(*param_1 + 4) = 0;
      *param_1 = (int)piVar7;
      piVar7[1] = (int)param_1;
      local_48 = (float *)piVar7[2];
      RwSubtractVector(pfVar1,local_48,local_24);
      if (param_4 != 0) {
        RwDotProduct(param_4,extraout_EDX_00);
        pfVar4 = pfVar5;
        pfVar3 = (float *)RwScaleVector(param_3,(float)extraout_ST0_00,pfVar5);
        RwSubtractVector(local_24,pfVar3,pfVar4);
      }
      fVar8 = rwLengthNormaliseVector(local_c,pfVar5);
    } while (fVar8 <= (float10)_DAT_10052070);
  }
  piVar6 = (int *)*piVar7;
  local_40 = (float *)piVar6[2];
  RwSubtractVector(local_48,local_40,local_18);
  if (param_4 != 0) {
    RwDotProduct(param_4,extraout_EDX_01);
    pfVar5 = pfVar10;
    pfVar4 = (float *)RwScaleVector(param_3,(float)extraout_ST0_01,pfVar10);
    RwSubtractVector(local_18,pfVar4,pfVar5);
  }
  fVar8 = rwLengthNormaliseVector(&local_30,pfVar10);
  if (fVar8 <= (float10)_DAT_10052070) {
    do {
      if (piVar6 == piVar7) break;
      piVar6 = (int *)*piVar6;
      *(undefined4 *)*piVar7 = 0;
      *(undefined4 *)(*piVar7 + 4) = 0;
      *piVar7 = (int)piVar6;
      piVar6[1] = (int)piVar7;
      local_40 = (float *)piVar6[2];
      RwSubtractVector(local_48,local_40,local_18);
      if (param_4 != 0) {
        RwDotProduct(param_4,extraout_EDX_02);
        pfVar5 = pfVar10;
        pfVar4 = (float *)RwScaleVector(param_3,(float)extraout_ST0_02,pfVar10);
        RwSubtractVector(local_18,pfVar4,pfVar5);
      }
      fVar8 = rwLengthNormaliseVector(&local_30,pfVar10);
    } while (fVar8 <= (float10)_DAT_10052070);
  }
  RwSubtractVector(local_40,pfVar1,&fStack_3c);
  if (param_4 != 0) {
    RwDotProduct(param_4,extraout_EDX_03);
    pfVar10 = &fStack_3c;
    pfVar5 = (float *)RwScaleVector(param_3,(float)extraout_ST0_03,&fStack_3c);
    RwSubtractVector(&fStack_3c,pfVar5,pfVar10);
  }
  pfVar10 = (float *)(param_1 + 5);
  rwLengthNormaliseVector(&fStack_3c,&fStack_3c);
  RwCrossProduct(&local_30,param_3,pfVar10);
  uVar9 = RwDotProduct(extraout_ECX,extraout_EDX_04);
  param_1[4] = (int)(float)extraout_ST0_04;
  param_1[3] = (int)(float)extraout_ST0_04;
  uVar9 = RwDotProduct(extraout_ECX_00,(int)((ulonglong)uVar9 >> 0x20));
  param_1[8] = (int)(float)-extraout_ST0_05;
  RwDotProduct(extraout_ECX_01,(int)((ulonglong)uVar9 >> 0x20));
  if ((float10)_DAT_10052070 < extraout_ST0_06 + (float10)(float)param_1[8]) {
    fVar2 = _DAT_10052088 / (float)(extraout_ST0_06 + (float10)(float)param_1[8]);
    RwScaleVector(pfVar10,fVar2,pfVar10);
    param_1[8] = (int)((float)param_1[8] * fVar2);
  }
  pfVar10 = (float *)(param_1 + 9);
  RwCrossProduct(local_c,param_3,pfVar10);
  uVar9 = RwDotProduct(extraout_ECX_02,extraout_EDX_05);
  fVar2 = (float)param_1[4];
  if ((float)extraout_ST0_07 <= (float)param_1[4]) {
    fVar2 = (float)extraout_ST0_07;
  }
  param_1[4] = (int)fVar2;
  uVar9 = RwDotProduct(extraout_ECX_03,(int)((ulonglong)uVar9 >> 0x20));
  param_1[0xc] = (int)(float)-extraout_ST0_08;
  RwDotProduct(extraout_ECX_04,(int)((ulonglong)uVar9 >> 0x20));
  if ((float10)_DAT_10052070 < extraout_ST0_09 + (float10)(float)param_1[0xc]) {
    fVar2 = _DAT_10052088 / (float)(extraout_ST0_09 + (float10)(float)param_1[0xc]);
    RwScaleVector(pfVar10,fVar2,pfVar10);
    param_1[0xc] = (int)((float)param_1[0xc] * fVar2);
  }
  fVar2 = (fStack_38 * local_30 - fStack_3c * local_2c) * param_3[2] +
          (local_34 * local_2c - fStack_38 * local_28) * *param_3 +
          (fStack_3c * local_28 - local_34 * local_30) * param_3[1];
  if ((float)param_1[4] <= fVar2) {
    fVar2 = (float)param_1[4];
  }
  param_1[4] = (int)fVar2;
  return (float10)(float)param_1[3];
}


