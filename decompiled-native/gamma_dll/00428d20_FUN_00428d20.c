// 00428d20 FUN_00428d20 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_00428d20(undefined4 *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = *(float *)(param_2 + 0xc);
  fVar2 = *(float *)(param_3 + 0xc);
  fVar3 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_3 + 8);
  fVar5 = *(float *)(param_2 + 4);
  fVar6 = *(float *)(param_3 + 4);
  *param_1 = &PTR_LAB_00473390;
  param_1[1] = fVar5 - fVar6;
  param_1[2] = fVar3 - fVar4;
  param_1[3] = fVar1 - fVar2;
  return param_1;
}


