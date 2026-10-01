// 0044d970 FUN_0044d970 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0044d970(void)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  do {
    in_ST0 = (float10)_DAT_00480a88 * in_ST0 -
             (float10)(unkint10)(((float10)_DAT_00480a88 * in_ST0) / (float10)3.141592653589793) *
             (float10)3.141592653589793;
  } while ((in_FPUStatusWord & 0x400) != 0);
  return in_ST0;
}


