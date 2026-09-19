// 100428a0 FUN_100428a0 [Global]
// programa: RWL21.DLL

void FUN_100428a0(float *param_1,float *param_2,float param_3,float *param_4)

{
  *param_4 = *param_2 * param_3 + *param_1;
  param_4[1] = param_2[1] * param_3 + param_1[1];
  param_4[2] = param_2[2] * param_3 + param_1[2];
  return;
}


