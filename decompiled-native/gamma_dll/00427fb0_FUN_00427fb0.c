// 00427fb0 FUN_00427fb0 [Global]
// program: gamma.dll

void __cdecl FUN_00427fb0(float *param_1,float *param_2,float *param_3)

{
  *param_1 = param_2[1] * param_3[2] - param_3[1] * param_2[2];
  param_1[1] = param_2[2] * *param_3 - param_3[2] * *param_2;
  param_1[2] = *param_2 * param_3[1] - *param_3 * param_2[1];
  return;
}


