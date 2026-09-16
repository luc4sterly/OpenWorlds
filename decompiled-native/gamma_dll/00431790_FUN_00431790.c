// 00431790 FUN_00431790 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00431790(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x40);
  param_2[1] = *(undefined4 *)(param_1 + 0x44);
  return param_2;
}


