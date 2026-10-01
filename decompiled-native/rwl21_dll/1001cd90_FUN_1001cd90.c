// 1001cd90 FUN_1001cd90 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_1001cd90(float *param_1,float param_2,float param_3,float param_4)

{
  float *pfVar1;
  float *pfVar2;
  float10 fVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (((ABS(param_2) == 0.0) && (ABS(param_3) == 0.0)) && (ABS(param_4) == 0.0)) {
    FUN_1000cba0(0x20);
    return (float *)0x0;
  }
  param_1[8] = param_2;
  pfVar1 = param_1 + 8;
  param_1[9] = param_3;
  param_1[10] = param_4;
  fVar3 = rwLengthNormaliseVector(pfVar1,pfVar1);
  if (fVar3 <= (float10)_DAT_10052180) {
    FUN_1000cba0(7);
  }
  else {
    RwCrossProduct(param_1 + 4,pfVar1,&fStack_c);
    fVar3 = rwLengthNormaliseVector(&fStack_c,&fStack_c);
    if ((float10)_DAT_10052180 < fVar3) {
      *param_1 = fStack_c;
      param_1[1] = fStack_8;
      param_1[2] = fStack_4;
    }
  }
  pfVar2 = param_1 + 4;
  RwCrossProduct(pfVar1,param_1,pfVar2);
  fVar3 = rwLengthNormaliseVector(pfVar2,pfVar2);
  if (fVar3 <= (float10)_DAT_10052180) {
    FUN_1000cba0(7);
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 1;
  return param_1;
}


