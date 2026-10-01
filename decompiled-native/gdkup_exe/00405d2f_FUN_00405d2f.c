// 00405d2f FUN_00405d2f [Global]
// program: gdkup.exe

void __fastcall FUN_00405d2f(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 8);
  *(char **)(iVar1 + 0xc) = s_violation_of_function_exception_s_004085db;
  *(undefined1 *)(*(int *)(iVar1 + 8) + 0x1c) = 2;
  thunk_FUN_00407114(param_1,param_2);
  return;
}


