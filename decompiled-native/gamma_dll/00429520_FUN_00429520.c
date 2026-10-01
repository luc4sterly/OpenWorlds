// 00429520 FUN_00429520 [Global]
// program: gamma.dll

undefined4 * __cdecl FUN_00429520(undefined4 *param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_2 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar3 = *(float *)(param_2 + 0xc);
  *param_1 = &PTR_LAB_004732e8;
  param_1[1] = param_3 * fVar1;
  param_1[2] = param_3 * fVar2;
  param_1[3] = fVar3 * param_3;
  return param_1;
}


