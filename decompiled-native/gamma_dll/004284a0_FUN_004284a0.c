// 004284a0 FUN_004284a0 [Global]
// programa: gamma.dll

uint FUN_004284a0(byte param_1)

{
  uint uVar1;
  
  if (param_1 == 0xff) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)(byte)(&DAT_00482918)[param_1];
  }
  return uVar1;
}


