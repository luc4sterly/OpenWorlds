// 100428e0 RwScaleVector [Global]
// program: RWL21.DLL

void RwScaleVector(float *param_1,float param_2,float *param_3)

{
                    /* 0x428e0  362  RwScaleVector */
  *param_3 = *param_1 * param_2;
  param_3[1] = param_1[1] * param_2;
  param_3[2] = param_1[2] * param_2;
  return;
}


