// 00451a10 FUN_00451a10 [Global]
// programa: gamma.dll

char * FUN_00451a10(char *param_1,char *param_2,short *param_3)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    *param_3 = (short)*param_1;
    param_3 = param_3 + 1;
  }
  return param_2;
}


