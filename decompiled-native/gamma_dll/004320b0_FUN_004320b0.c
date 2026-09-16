// 004320b0 FUN_004320b0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_004320b0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x38);
  param_2[1] = *(undefined4 *)(param_1 + 0x3c);
  return param_2;
}


