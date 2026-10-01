// 10030b90 FUN_10030b90 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_10030b90(float *param_1,int param_2)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  
  if ((param_1 != (float *)0x0) && (param_2 != 0)) {
    switch(param_1[99]) {
    case 1.4013e-45:
      goto switchD_10030bbb_caseD_1;
    case 2.8026e-45:
      pfVar1 = param_1 + 8;
      iVar2 = FUN_10009dc0(param_2);
      *pfVar1 = -*(float *)(iVar2 + 0x20);
      param_1[9] = -*(float *)(iVar2 + 0x24);
      pfVar4 = param_1 + 4;
      param_1[10] = -*(float *)(iVar2 + 0x28);
      fVar6 = rwLengthNormaliseVector(param_1,param_1);
      fVar7 = rwLengthNormaliseVector(pfVar4,pfVar4);
      RwCrossProduct(pfVar1,param_1,pfVar4);
      fVar5 = rwLengthNormaliseVector(pfVar4,pfVar4);
      if (fVar5 <= (float10)_DAT_10052248) {
        *pfVar4 = *(float *)(iVar2 + 0x10);
        param_1[5] = *(float *)(iVar2 + 0x14);
        param_1[6] = *(float *)(iVar2 + 0x18);
      }
      RwCrossProduct(pfVar4,pfVar1,param_1);
      rwLengthNormaliseVector(param_1,param_1);
      RwScaleVector(param_1,(float)fVar6,param_1);
      RwScaleVector(pfVar4,(float)fVar7,pfVar4);
      *(undefined1 *)((int)param_1 + 0x41) = 1;
      *(undefined1 *)(param_1 + 0x10) = 0;
      return param_1;
    case 4.2039e-45:
      pfVar1 = param_1 + 8;
      pfVar3 = (float *)FUN_10009dc0(param_2);
      *pfVar1 = -pfVar3[8];
      param_1[9] = -pfVar3[9];
      pfVar4 = param_1 + 4;
      param_1[10] = -pfVar3[10];
      fVar6 = rwLengthNormaliseVector(param_1,param_1);
      fVar7 = rwLengthNormaliseVector(pfVar4,pfVar4);
      RwCrossProduct(pfVar4,pfVar1,param_1);
      fVar5 = rwLengthNormaliseVector(param_1,param_1);
      if (fVar5 <= (float10)_DAT_10052248) {
        *param_1 = *pfVar3;
        param_1[1] = pfVar3[1];
        param_1[2] = pfVar3[2];
      }
      RwCrossProduct(pfVar1,param_1,pfVar4);
      rwLengthNormaliseVector(pfVar4,pfVar4);
      RwScaleVector(param_1,(float)fVar6,param_1);
      RwScaleVector(pfVar4,(float)fVar7,pfVar4);
      *(undefined1 *)((int)param_1 + 0x41) = 1;
      *(undefined1 *)(param_1 + 0x10) = 0;
      return param_1;
    case 5.60519e-45:
      pfVar4 = (float *)FUN_10009dc0(param_2);
      param_1[8] = -pfVar4[8];
      param_1[9] = -pfVar4[9];
      pfVar1 = param_1 + 4;
      param_1[10] = -pfVar4[10];
      fVar6 = rwLengthNormaliseVector(param_1,param_1);
      fVar7 = rwLengthNormaliseVector(pfVar1,pfVar1);
      RwScaleVector(pfVar4,-(float)fVar6,param_1);
      RwScaleVector(pfVar4 + 4,(float)fVar7,pfVar1);
      *(undefined1 *)((int)param_1 + 0x41) = 1;
      *(undefined1 *)(param_1 + 0x10) = 0;
switchD_10030bbb_caseD_1:
      return param_1;
    default:
      FUN_1000cba0(0x32);
      return (float *)0x0;
    }
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


