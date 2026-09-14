// 00446530 FUN_00446530 [Global]
// programa: gamma.dll

undefined4 FUN_00446530(int *param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


