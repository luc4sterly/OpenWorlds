// 00431700 FUN_00431700 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00431700(int param_1,undefined4 *param_2)

{
  *param_2 = &PTR_LAB_00473390;
  param_2[1] = *(undefined4 *)(param_1 + 0xc);
  param_2[2] = *(undefined4 *)(param_1 + 0x10);
  param_2[3] = *(undefined4 *)(param_1 + 0x14);
  return param_2;
}


