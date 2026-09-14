// 00445490 FUN_00445490 [Global]
// programa: gamma.dll

undefined4 FUN_00445490(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x1c);
  return 0;
}


