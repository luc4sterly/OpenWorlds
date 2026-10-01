// 00449e40 FUN_00449e40 [Global]
// program: gamma.dll

undefined4 FUN_00449e40(undefined4 param_1,undefined4 *param_2)

{
  LPVOID pvVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  pvVar1 = CoTaskMemAlloc(8);
  *param_2 = pvVar1;
  if ((short *)*param_2 == (short *)0x0) {
    return 0x8007000e;
  }
  FUN_0044b290((short *)*param_2,(short *)&DAT_0047b028);
  return 0;
}


