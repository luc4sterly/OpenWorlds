// 00432090 FUN_00432090 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00432090(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x30);
  param_2[1] = *(undefined4 *)(param_1 + 0x34);
  return param_2;
}


