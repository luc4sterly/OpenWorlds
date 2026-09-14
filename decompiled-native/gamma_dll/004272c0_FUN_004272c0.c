// 004272c0 FUN_004272c0 [Global]
// programa: gamma.dll

void __cdecl FUN_004272c0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = *param_3;
  fVar6 = param_2[1];
  fVar7 = param_3[3];
  fVar2 = param_3[1];
  fVar3 = *param_2;
  fVar8 = param_2[3];
  fVar4 = param_2[2];
  fVar5 = param_3[2];
  *param_1 = ((fVar3 * fVar1 - fVar6 * fVar2) - fVar4 * fVar5) - fVar8 * fVar7;
  param_1[1] = (fVar4 * fVar7 + fVar3 * fVar2 + fVar6 * fVar1) - fVar8 * fVar5;
  param_1[2] = (fVar8 * fVar2 + fVar3 * fVar5 + fVar4 * fVar1) - fVar6 * fVar7;
  param_1[3] = (fVar6 * fVar5 + fVar3 * fVar7 + fVar8 * fVar1) - fVar4 * fVar2;
  return;
}


