// 1001c150 FUN_1001c150 [Global]
// programa: RWL21.DLL

float * __fastcall FUN_1001c150(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  float *pfVar5;
  float *pfVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  undefined8 uVar10;
  float *pfVar11;
  float fStack_14;
  float fStack_8;
  float fStack_4;
  
  if (*(char *)(param_3 + 0x10) != '\0') {
    uVar10 = FUN_100510e0(param_1,param_2,param_3,param_4);
    return (float *)uVar10;
  }
  fVar7 = rwLengthNormaliseVector(param_4,param_3);
  pfVar4 = param_4 + 8;
  param_4[3] = 0.0;
  fVar8 = rwLengthNormaliseVector(param_4 + 4,param_3 + 4);
  param_4[7] = 0.0;
  fVar9 = rwLengthNormaliseVector(pfVar4,param_3 + 8);
  param_4[0xb] = 0.0;
  param_4[0xc] = param_3[0xc];
  fVar1 = param_3[0xd];
  param_4[0xd] = fVar1;
  fVar2 = param_3[0xe];
  param_4[0xe] = fVar2;
  param_4[0xf] = param_3[0xf];
  if (0 < (int)(float)fVar7) {
    pfVar5 = pfVar4;
    pfVar6 = param_4;
    if ((int)(float)fVar8 < 1) {
      pfVar4 = param_4 + 4;
      goto LAB_1001c2bf;
    }
    if ((int)(float)fVar9 < 1) {
      pfVar5 = param_4;
      pfVar6 = param_4 + 4;
      goto LAB_1001c2bf;
    }
    uVar10 = RwDotProduct(fVar1,fVar2);
    fStack_8 = (float)extraout_ST0;
    uVar10 = RwDotProduct(extraout_ECX,(int)((ulonglong)uVar10 >> 0x20));
    fStack_4 = (float)extraout_ST0_00;
    RwDotProduct(extraout_ECX_00,(int)((ulonglong)uVar10 >> 0x20));
    fStack_14 = (float)extraout_ST0_01;
    if (0x80000000 < (uint)fStack_8) {
      fStack_8 = -fStack_8;
    }
    if (0x80000000 < (uint)fStack_4) {
      fStack_4 = -fStack_4;
    }
    if (0x80000000 < (uint)fStack_14) {
      fStack_14 = -fStack_14;
    }
    if (fStack_4 <= fStack_8) {
      if (fStack_14 <= fStack_4) {
        pfVar5 = param_4;
        pfVar6 = param_4 + 4;
      }
      else {
        pfVar4 = param_4 + 4;
      }
      goto LAB_1001c2bf;
    }
    if (fStack_14 <= fStack_8) {
      pfVar5 = param_4;
      pfVar6 = param_4 + 4;
      goto LAB_1001c2bf;
    }
  }
  pfVar5 = param_4 + 4;
  pfVar6 = pfVar4;
  pfVar4 = param_4;
LAB_1001c2bf:
  pfVar11 = pfVar4;
  pfVar3 = (float *)RwCrossProduct(pfVar5,pfVar6,pfVar4);
  rwLengthNormaliseVector(pfVar3,pfVar11);
  pfVar4 = (float *)RwCrossProduct(pfVar4,pfVar5,pfVar6);
  rwLengthNormaliseVector(pfVar4,pfVar6);
  *(undefined1 *)((int)param_4 + 0x41) = 1;
  *(undefined1 *)(param_4 + 0x10) = 0;
  return param_4;
}


