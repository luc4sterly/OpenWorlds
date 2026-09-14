// 004271c0 FUN_004271c0 [Global]
// programa: gamma.dll

void __cdecl FUN_004271c0(float *param_1,float *param_2,float *param_3,float param_4)

{
  *param_1 = (*param_3 - *param_2) * param_4 + *param_2;
  param_1[1] = (param_3[1] - param_2[1]) * param_4 + param_2[1];
  param_1[2] = (param_3[2] - param_2[2]) * param_4 + param_2[2];
  param_1[3] = (param_3[3] - param_2[3]) * param_4 + param_2[3];
  FUN_00426f40(param_1);
  return;
}


