// 00447c60 FUN_00447c60 [Global]
// program: gamma.dll

int __fastcall FUN_00447c60(int *param_1)

{
  int iVar1;
  int local_18;
  int local_14;
  
  if (param_1[0x11] == 1) {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x2c))(param_1,&local_18);
    if (-1 < iVar1) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
      param_1[0xf] = local_18;
      param_1[0x10] = local_14;
      param_1[0xd] = param_1[0xf];
      param_1[0xe] = param_1[0x10];
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
    }
  }
  return iVar1;
}


