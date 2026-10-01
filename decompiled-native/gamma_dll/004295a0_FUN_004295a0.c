// 004295a0 FUN_004295a0 [Global]
// program: gamma.dll

undefined4 * __cdecl FUN_004295a0(undefined4 *param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_3 + 4);
  fVar2 = *(float *)(param_3 + 8);
  fVar3 = *(float *)(param_3 + 0xc);
  *param_1 = &PTR_LAB_004732e8;
  param_1[1] = param_2 * fVar1;
  param_1[2] = param_2 * fVar2;
  param_1[3] = fVar3 * param_2;
  return param_1;
}


