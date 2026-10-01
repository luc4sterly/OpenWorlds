// 10042aa0 RwAddVector [Global]
// program: RWL21.DLL

void RwAddVector(float *param_1,float *param_2,float *param_3)

{
                    /* 0x42aa0  17  RwAddVector */
  *param_3 = *param_2 + *param_1;
  param_3[1] = param_2[1] + param_1[1];
  param_3[2] = param_2[2] + param_1[2];
  return;
}


