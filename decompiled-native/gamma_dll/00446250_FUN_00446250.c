// 00446250 FUN_00446250 [Global]
// programa: gamma.dll

undefined4 FUN_00446250(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = *(undefined4 *)(param_1 + 8);
  return 0;
}


