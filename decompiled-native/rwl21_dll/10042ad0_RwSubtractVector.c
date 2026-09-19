// 10042ad0 RwSubtractVector [Global]
// programa: RWL21.DLL

void RwSubtractVector(float *param_1,float *param_2,float *param_3)

{
                    /* 0x42ad0  500  RwSubtractVector */
  *param_3 = *param_1 - *param_2;
  param_3[1] = param_1[1] - param_2[1];
  param_3[2] = param_1[2] - param_2[2];
  return;
}


