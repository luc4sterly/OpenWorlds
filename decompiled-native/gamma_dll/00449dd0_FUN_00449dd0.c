// 00449dd0 FUN_00449dd0 [Global]
// program: gamma.dll

void __fastcall FUN_00449dd0(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd0) + 0x130))();
  if (iVar1 < 0) {
    return;
  }
  FUN_004459e0(param_1);
  return;
}


