// 10042910 rwLengthNormaliseVector [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* rwLengthNormaliseVector */

float10 __cdecl rwLengthNormaliseVector(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float10 extraout_ST0;
  float10 fVar7;
  float10 fVar8;
  float10 extraout_ST0_00;
  float local_4;
  
                    /* 0x42910  565  _rwLengthNormaliseVector */
  fVar1 = ABS(*param_2);
  fVar5 = ABS(param_2[1]);
  fVar2 = ABS(param_2[2]);
  local_4 = fVar5;
  if ((uint)fVar5 < (uint)fVar1) {
    local_4 = fVar1;
  }
  if ((uint)local_4 <= (uint)fVar2) {
    local_4 = fVar2;
  }
  if (local_4 == 0.0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    local_4 = 0.0;
  }
  else {
    uVar3 = (uint)local_4 & 0x7f800000;
    if (uVar3 < 0x3e000001) {
      iVar6 = 0x3e000000 - uVar3;
      fVar4 = *param_2;
      if (fVar1 != 0.0) {
        fVar4 = (float)((int)fVar4 + iVar6);
      }
      *param_1 = fVar4;
      fVar1 = param_2[1];
      if (fVar5 != 0.0) {
        fVar1 = (float)((int)fVar1 + iVar6);
      }
      param_1[1] = fVar1;
      fVar1 = param_2[2];
      if (fVar2 != 0.0) {
        fVar1 = (float)((int)fVar1 + iVar6);
      }
      param_1[2] = fVar1;
      RwDotProduct(param_2,fVar2);
      local_4 = (float)extraout_ST0_00;
      fVar7 = FUN_10041770((int *)&local_4);
      fVar8 = (float10)_DAT_100522f4 / fVar7;
      *param_1 = (float)((float10)*param_1 * fVar8);
      param_1[1] = (float)((float10)param_1[1] * fVar8);
      param_1[2] = (float)(fVar8 * (float10)param_1[2]);
      local_4 = (float)((int)(float)fVar7 - iVar6);
    }
    else {
      fVar4 = (float)(uVar3 + 0xc2000000);
      if ((uint)fVar4 < (uint)fVar1) {
        *param_1 = (float)((int)*param_2 - (int)fVar4);
      }
      else {
        *param_1 = 0.0;
      }
      if ((uint)fVar4 < (uint)fVar5) {
        param_1[1] = (float)((int)param_2[1] - (int)fVar4);
      }
      else {
        param_1[1] = 0.0;
      }
      if ((uint)fVar4 < (uint)fVar2) {
        param_1[2] = (float)((int)param_2[2] - (int)fVar4);
      }
      else {
        param_1[2] = 0.0;
      }
      RwDotProduct(param_2,fVar2);
      local_4 = (float)extraout_ST0;
      fVar7 = FUN_10041770((int *)&local_4);
      fVar8 = (float10)_DAT_100522f4 / fVar7;
      *param_1 = (float)((float10)*param_1 * fVar8);
      param_1[1] = (float)((float10)param_1[1] * fVar8);
      param_1[2] = (float)(fVar8 * (float10)param_1[2]);
      local_4 = (float)((int)(float)fVar7 + (int)fVar4);
    }
  }
  return (float10)local_4;
}


