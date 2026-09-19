// 1001fc90 RwSplinePoint [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * RwSplinePoint(int *param_1,int param_2,float param_3,float *param_4,float *param_5)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar8;
  longlong lVar9;
  float fVar10;
  float *pfVar11;
  float *pfVar12;
  float *pfVar13;
  float fVar14;
  float *pfVar15;
  float *pfVar16;
  float fVar17;
  float *pfVar18;
  float local_10;
  float local_c;
  
                    /* 0x1fc90  495  RwSplinePoint */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return (float *)0x0;
  }
  iVar5 = *param_1;
  if ((uint)param_3 < 0x80000001) {
    local_10 = param_3;
  }
  else {
    local_10 = -param_3;
  }
  param_3 = local_10;
  if ((param_1[1] == 2) || (0x3f800000 < (int)local_10)) {
    lVar9 = __ftol();
    param_3 = (float)(extraout_ST0 - (float10)(int)lVar9);
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      FUN_1000cba0(0x10);
      return (float *)0x0;
    }
    if ((int)param_3 < 0x3f000001) {
      param_3 = param_3 * _DAT_100521fc * param_3;
    }
    else {
      param_3 = (param_3 * _DAT_10052204 + param_3 * _DAT_10052200 * param_3) - _DAT_100521f4;
    }
  }
  if (param_3 == 1.0) {
    iVar5 = iVar5 + -4;
    iVar7 = 0xff;
    local_c = 1.0;
  }
  else {
    lVar9 = __ftol();
    iVar5 = (int)lVar9;
    lVar9 = __ftol();
    iVar7 = (int)lVar9;
    local_c = (float)(extraout_ST0_00 - (float10)iVar7);
  }
  iVar6 = iVar5 + 2;
  pfVar4 = (float *)(param_1 + iVar5 + iVar6 * 2 + 3);
  pfVar13 = (float *)(param_1 + iVar6 * 3 + 4);
  pfVar16 = (float *)(param_1 + iVar5 + iVar6 * 2 + 9);
  fVar10 = (*(float *)(DAT_1005ac98 + 4 + iVar7 * 4) - *(float *)(DAT_1005ac98 + iVar7 * 4)) *
           local_c + *(float *)(DAT_1005ac98 + iVar7 * 4);
  fVar14 = (*(float *)(DAT_1005ac94 + 4 + iVar7 * 4) - *(float *)(DAT_1005ac94 + iVar7 * 4)) *
           local_c + *(float *)(DAT_1005ac94 + iVar7 * 4);
  fVar17 = (*(float *)(DAT_1005ac90 + 4 + iVar7 * 4) - *(float *)(DAT_1005ac90 + iVar7 * 4)) *
           local_c + *(float *)(DAT_1005ac90 + iVar7 * 4);
  pfVar2 = pfVar4;
  pfVar11 = param_4;
  pfVar12 = pfVar13;
  pfVar3 = param_4;
  pfVar15 = pfVar16;
  pfVar18 = param_4;
  pfVar1 = (float *)RwScaleVector((float *)(param_1 + iVar5 * 3 + 4),
                                  (*(float *)(DAT_1005ac9c + 4 + iVar7 * 4) -
                                  *(float *)(DAT_1005ac9c + iVar7 * 4)) * local_c +
                                  *(float *)(DAT_1005ac9c + iVar7 * 4),param_4);
  pfVar2 = (float *)FUN_100428a0(pfVar1,pfVar2,fVar10,pfVar11);
  pfVar2 = (float *)FUN_100428a0(pfVar2,pfVar12,fVar14,pfVar3);
  FUN_100428a0(pfVar2,pfVar15,fVar17,pfVar18);
  RwScaleVector(param_4,0.03125,param_4);
  if (param_5 != (float *)0x0) {
    fVar10 = (*(float *)(DAT_1005aca8 + 4 + iVar7 * 4) - *(float *)(DAT_1005aca8 + iVar7 * 4)) *
             local_c + *(float *)(DAT_1005aca8 + iVar7 * 4);
    fVar14 = (*(float *)(DAT_1005aca4 + 4 + iVar7 * 4) - *(float *)(DAT_1005aca4 + iVar7 * 4)) *
             local_c + *(float *)(DAT_1005aca4 + iVar7 * 4);
    fVar17 = (*(float *)(DAT_1005aca0 + 4 + iVar7 * 4) - *(float *)(DAT_1005aca0 + iVar7 * 4)) *
             local_c + *(float *)(DAT_1005aca0 + iVar7 * 4);
    pfVar2 = param_5;
    pfVar11 = param_5;
    pfVar12 = param_5;
    pfVar3 = (float *)RwScaleVector((float *)(param_1 + iVar5 * 3 + 4),
                                    (*(float *)(DAT_1005acac + 4 + iVar7 * 4) -
                                    *(float *)(DAT_1005acac + iVar7 * 4)) * local_c +
                                    *(float *)(DAT_1005acac + iVar7 * 4),param_5);
    pfVar4 = (float *)FUN_100428a0(pfVar3,pfVar4,fVar10,pfVar2);
    pfVar4 = (float *)FUN_100428a0(pfVar4,pfVar13,fVar14,pfVar11);
    FUN_100428a0(pfVar4,pfVar16,fVar17,pfVar12);
    fVar8 = rwLengthNormaliseVector(param_5,param_5);
    if (fVar8 <= (float10)_DAT_100521f0) {
      param_5[1] = 1.0;
    }
  }
  return param_4;
}


