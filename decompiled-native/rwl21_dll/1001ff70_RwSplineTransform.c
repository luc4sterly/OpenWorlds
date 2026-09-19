// 1001ff70 RwSplineTransform [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwSplineTransform(int *param_1,int param_2,float param_3,float *param_4,float *param_5)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float fVar11;
  int iVar12;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar13;
  float10 fVar14;
  longlong lVar15;
  float *pfVar16;
  float *pfVar17;
  float fVar18;
  float local_3c;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float *local_24;
  float *local_20;
  float *local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
                    /* 0x1ff70  496  RwSplineTransform */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return (float10)_DAT_100521f0;
  }
  pfVar1 = param_5 + 8;
  pfVar2 = param_5 + 4;
  pfVar8 = param_5 + 0xc;
  iVar12 = *param_1;
  if ((uint)param_3 < 0x80000001) {
    local_30 = param_3;
  }
  else {
    local_30 = -param_3;
  }
  param_3 = local_30;
  if ((param_1[1] == 2) || (0x3f800000 < (int)local_30)) {
    lVar15 = __ftol();
    local_30 = (float)lVar15;
    param_3 = (float)(extraout_ST0 - (float10)(int)local_30);
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      FUN_1000cba0(0x10);
      return (float10)_DAT_100521f0;
    }
    if ((int)param_3 < 0x3f000001) {
      param_3 = param_3 * _DAT_100521fc * param_3;
    }
    else {
      param_3 = (param_3 * _DAT_10052204 + param_3 * _DAT_10052200 * param_3) - _DAT_100521f4;
    }
  }
  if (param_3 == 1.0) {
    fVar11 = (float)(iVar12 + -4);
    fVar3 = 3.57331e-43;
    local_3c = 1.0;
  }
  else {
    local_30 = (float)(iVar12 + -3);
    lVar15 = __ftol();
    fVar11 = (float)lVar15;
    local_30 = fVar11;
    lVar15 = __ftol();
    fVar3 = (float)lVar15;
    local_3c = (float)(extraout_ST0_00 - (float10)(int)fVar3);
    local_30 = fVar3;
  }
  iVar12 = (int)fVar11 + 2;
  local_1c = (float *)(param_1 + (int)fVar11 * 3 + 4);
  pfVar6 = (float *)(param_1 + (int)fVar11 + iVar12 * 2 + 3);
  *(undefined1 *)((int)param_5 + 0x41) = 1;
  pfVar17 = (float *)(param_1 + iVar12 * 3 + 4);
  *(undefined1 *)(param_5 + 0x10) = 0;
  pfVar9 = (float *)(param_1 + (int)fVar11 + iVar12 * 2 + 9);
  iVar12 = (int)fVar3 * 4;
  pfVar4 = (float *)(DAT_1005ac9c + iVar12);
  pfVar5 = (float *)(DAT_1005ac98 + iVar12);
  fVar11 = (pfVar5[1] - *pfVar5) * local_3c + *pfVar5;
  pfVar5 = (float *)(DAT_1005ac94 + iVar12);
  fVar3 = (pfVar5[1] - *pfVar5) * local_3c + *pfVar5;
  pfVar5 = (float *)(DAT_1005ac90 + iVar12);
  fVar18 = (pfVar5[1] - *pfVar5) * local_3c + *pfVar5;
  pfVar5 = pfVar8;
  pfVar16 = pfVar17;
  pfVar10 = pfVar8;
  pfVar7 = pfVar8;
  local_24 = pfVar9;
  local_20 = pfVar6;
  pfVar4 = (float *)RwScaleVector(local_1c,(pfVar4[1] - *pfVar4) * local_3c + *pfVar4,pfVar8);
  pfVar6 = (float *)FUN_100428a0(pfVar4,pfVar6,fVar11,pfVar5);
  pfVar6 = (float *)FUN_100428a0(pfVar6,pfVar16,fVar3,pfVar10);
  FUN_100428a0(pfVar6,pfVar9,fVar18,pfVar7);
  RwScaleVector(pfVar8,0.03125,pfVar8);
  pfVar7 = (float *)(DAT_1005acac + iVar12);
  pfVar8 = (float *)(DAT_1005aca8 + iVar12);
  fVar11 = (pfVar8[1] - *pfVar8) * local_3c + *pfVar8;
  pfVar8 = (float *)(DAT_1005aca4 + iVar12);
  fVar3 = (pfVar8[1] - *pfVar8) * local_3c + *pfVar8;
  pfVar8 = &local_18;
  pfVar5 = (float *)(DAT_1005aca0 + iVar12);
  pfVar6 = &local_18;
  pfVar9 = &local_18;
  fVar18 = (pfVar5[1] - *pfVar5) * local_3c + *pfVar5;
  pfVar5 = local_20;
  pfVar16 = pfVar17;
  pfVar10 = local_24;
  pfVar7 = (float *)RwScaleVector(local_1c,(pfVar7[1] - *pfVar7) * local_3c + *pfVar7,&local_18);
  pfVar9 = (float *)FUN_100428a0(pfVar7,pfVar5,fVar11,pfVar9);
  pfVar6 = (float *)FUN_100428a0(pfVar9,pfVar16,fVar3,pfVar6);
  FUN_100428a0(pfVar6,pfVar10,fVar18,pfVar8);
  RwScaleVector(&local_18,0.03125,&local_18);
  pfVar10 = (float *)(DAT_1005acbc + iVar12);
  pfVar8 = (float *)(DAT_1005acb8 + iVar12);
  fVar11 = (pfVar8[1] - *pfVar8) * local_3c + *pfVar8;
  pfVar8 = (float *)(DAT_1005acb4 + iVar12);
  pfVar6 = (float *)(iVar12 + DAT_1005acb0);
  fVar3 = (pfVar8[1] - *pfVar8) * local_3c + *pfVar8;
  fVar18 = (pfVar6[1] - *pfVar6) * local_3c + *pfVar6;
  pfVar8 = local_c;
  pfVar6 = local_c;
  pfVar9 = local_c;
  pfVar5 = local_20;
  pfVar16 = local_24;
  pfVar10 = (float *)RwScaleVector(local_1c,(pfVar10[1] - *pfVar10) * local_3c + *pfVar10,local_c);
  pfVar9 = (float *)FUN_100428a0(pfVar10,pfVar5,fVar11,pfVar9);
  pfVar6 = (float *)FUN_100428a0(pfVar9,pfVar17,fVar3,pfVar6);
  FUN_100428a0(pfVar6,pfVar16,fVar18,pfVar8);
  RwScaleVector(local_c,0.03125,local_c);
  *pfVar1 = local_18;
  param_5[9] = local_14;
  param_5[10] = local_10;
  fVar13 = rwLengthNormaliseVector(pfVar1,pfVar1);
  if (fVar13 <= (float10)_DAT_100521f0) {
    *pfVar1 = 0.0;
    param_5[9] = 0.0;
    param_5[10] = 1.0;
  }
  RwCrossProduct(local_c,pfVar1,&local_30);
  fVar13 = rwLengthNormaliseVector(&local_30,&local_30);
  if (param_4 == (float *)0x0) {
    *pfVar2 = local_30;
    param_5[5] = fStack_2c;
    param_5[6] = fStack_28;
    if (0 < (int)(float)fVar13) goto LAB_100203d1;
  }
  else {
    *pfVar2 = *param_4;
    param_5[5] = param_4[1];
    param_5[6] = param_4[2];
    fVar14 = rwLengthNormaliseVector(pfVar2,pfVar2);
    if ((float10)_DAT_100521f0 < fVar14) goto LAB_100203d1;
  }
  param_5[5] = 1.0;
LAB_100203d1:
  RwCrossProduct(pfVar2,pfVar1,param_5);
  fVar14 = rwLengthNormaliseVector(param_5,param_5);
  if (fVar14 <= (float10)_DAT_100521f0) {
    *param_5 = 1.0;
  }
  if (param_4 != (float *)0x0) {
    RwCrossProduct(pfVar1,param_5,pfVar2);
    fVar14 = rwLengthNormaliseVector(pfVar2,pfVar2);
    if (fVar14 <= (float10)_DAT_100521f0) {
      param_5[5] = 1.0;
    }
  }
  param_5[3] = 0.0;
  param_5[7] = 0.0;
  param_5[0xf] = 1.0;
  param_5[0xb] = 0.0;
  return (float10)(float)fVar13;
}


