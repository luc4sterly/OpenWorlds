// 00449390 FUN_00449390 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_00449390(int *param_1,int param_2)

{
  if (param_2 == 0) {
    return 1;
  }
  if (param_1[0x17] == 0) {
    return 1;
  }
  (**(code **)(*param_1 + 0xdc))(param_2);
  (**(code **)(*param_1 + 0x150))(param_2);
  (**(code **)(*param_1 + 0xe0))(param_2);
  return 0;
}


