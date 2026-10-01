// 00449ef0 FUN_00449ef0 [Global]
// program: gamma.dll

void __thiscall FUN_00449ef0(void *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_004450a0(param_1,param_2);
  if (iVar1 < 0) {
    return;
  }
  (**(code **)(**(int **)((int)param_1 + 0xd0) + 0x134))(param_2);
  return;
}


