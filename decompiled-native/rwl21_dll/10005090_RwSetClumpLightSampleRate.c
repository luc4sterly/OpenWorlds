// 10005090 RwSetClumpLightSampleRate [Global]
// programa: RWL21.DLL

float10 RwSetClumpLightSampleRate(int param_1,float param_2)

{
  longlong lVar1;
  
                    /* 0x5090  386  RwSetClumpLightSampleRate */
  if (((uint)param_2 < 0x80000001) && ((int)param_2 < 0x3f800001)) {
    if (0 < (int)param_2) {
      lVar1 = __ftol();
      *(short *)(param_1 + 0x198) = (short)lVar1 + -1;
      return (float10)param_2;
    }
    *(undefined2 *)(param_1 + 0x198) = 0x3fff;
    return (float10)param_2;
  }
  return (float10)param_2;
}


