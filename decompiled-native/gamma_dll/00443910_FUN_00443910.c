// 00443910 FUN_00443910 [Global]
// program: gamma.dll

undefined4 FUN_00443910(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = *(undefined4 *)(param_1 + 0x14);
  return 0;
}


