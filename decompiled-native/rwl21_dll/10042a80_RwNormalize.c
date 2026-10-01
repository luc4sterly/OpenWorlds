// 10042a80 RwNormalize [Global]
// program: RWL21.DLL

float * RwNormalize(float *param_1)

{
                    /* 0x42a80  293  RwNormalize */
  rwLengthNormaliseVector(param_1,param_1);
  return param_1;
}


