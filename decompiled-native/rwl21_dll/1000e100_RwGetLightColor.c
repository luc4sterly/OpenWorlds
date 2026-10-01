// 1000e100 RwGetLightColor [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * RwGetLightColor(int param_1,float *param_2)

{
                    /* 0xe100  186  RwGetLightColor */
  if (param_1 != 0) {
    if (param_2 != (float *)0x0) {
      *param_2 = *(float *)(param_1 + 0x78) * _DAT_100520fc;
      param_2[1] = *(float *)(param_1 + 0x7c) * _DAT_100520fc;
      param_2[2] = *(float *)(param_1 + 0x80) * _DAT_100520fc;
      return param_2;
    }
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


