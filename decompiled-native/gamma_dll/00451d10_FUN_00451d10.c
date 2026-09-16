// 00451d10 FUN_00451d10 [Global]
// programa: gamma.dll

byte * FUN_00451d10(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if (*param_1 == 0xff) {
      bVar1 = 0xff;
    }
    else {
      bVar1 = (&DAT_00482818)[*param_1];
    }
    *param_1 = bVar1;
  }
  return param_2;
}


