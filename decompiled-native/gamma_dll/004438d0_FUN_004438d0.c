// 004438d0 FUN_004438d0 [Global]
// programa: gamma.dll

undefined4 FUN_004438d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x24);
  *(undefined2 *)(param_2 + 1) = *(undefined2 *)(param_1 + 0x28);
  *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(param_1 + 0x2a);
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  param_2[2] = *(undefined4 *)(param_1 + 0x2c);
  param_2[3] = uVar1;
  return 0;
}


