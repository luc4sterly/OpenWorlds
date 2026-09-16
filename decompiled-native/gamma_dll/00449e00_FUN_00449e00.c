// 00449e00 FUN_00449e00 [Global]
// programa: gamma.dll

void __thiscall FUN_00449e00(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd0) + 0x138))(param_2);
  if (iVar1 < 0) {
    return;
  }
  FUN_00445090();
  return;
}


