// 00427040 FUN_00427040 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00427040(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float *pfVar10;
  
  pfVar10 = param_1;
  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *pfVar10 = 0.0;
    pfVar10 = pfVar10 + 1;
  }
  param_1[0xf] = 1.0;
  param_1[10] = param_1[0xf];
  param_1[5] = param_1[10];
  *param_1 = param_1[5];
  fVar4 = param_2[3];
  fVar1 = param_2[2];
  fVar2 = param_2[1];
  fVar3 = *param_2;
  fVar7 = (float)_DAT_00471d38 / (fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2 + fVar1 * fVar1);
  fVar5 = fVar1 * fVar7;
  fVar6 = fVar4 * fVar7;
  fVar8 = fVar3 * fVar2 * fVar7;
  fVar7 = fVar2 * fVar2 * fVar7;
  *param_1 = (float)_DAT_00471d40 - (fVar1 * fVar5 + fVar4 * fVar6);
  param_1[1] = fVar2 * fVar5 + fVar3 * fVar6;
  param_1[2] = fVar2 * fVar6 - fVar3 * fVar5;
  param_1[4] = fVar2 * fVar5 - fVar3 * fVar6;
  param_1[5] = (float)_DAT_00471d40 - (fVar7 + fVar4 * fVar6);
  param_1[6] = fVar1 * fVar6 + fVar8;
  param_1[8] = fVar2 * fVar6 + fVar3 * fVar5;
  param_1[9] = fVar1 * fVar6 - fVar8;
  param_1[10] = (float)_DAT_00471d40 - (fVar7 + fVar1 * fVar5);
  return;
}


