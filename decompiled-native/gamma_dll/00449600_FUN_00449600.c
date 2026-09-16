// 00449600 FUN_00449600 [Global]
// programa: gamma.dll

int __thiscall FUN_00449600(int *param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION p_Var1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0x13c))(param_2);
  if (iVar2 < 0) {
    if (iVar2 == -0x7ffbfdd5) {
      return 0;
    }
    return iVar2;
  }
  if (param_1[5] == 1) {
    (**(code **)(*param_1 + 0xf4))();
    param_1[0x2b] = 0;
    p_Var1 = (LPCRITICAL_SECTION)(param_1 + 0x1d);
    EnterCriticalSection(p_Var1);
    if (param_1[5] == 0) {
      LeaveCriticalSection(p_Var1);
      return 0;
    }
    param_1[0x2b] = 1;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
    (**(code **)(*param_1 + 0xd8))(param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
    LeaveCriticalSection(p_Var1);
    SetEvent((HANDLE)param_1[0x15]);
  }
  iVar2 = (**(code **)(*param_1 + 0xd0))();
  if (iVar2 < 0) {
    param_1[0x2b] = 0;
    return 0;
  }
  (**(code **)(*param_1 + 0xf4))();
  param_1[0x2b] = 0;
  p_Var1 = (LPCRITICAL_SECTION)(param_1 + 0x1d);
  EnterCriticalSection(p_Var1);
  if (param_1[5] == 0) {
    LeaveCriticalSection(p_Var1);
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
  (**(code **)(*param_1 + 0x14c))(param_1[0x19]);
  (**(code **)(*param_1 + 0x114))();
  (**(code **)(*param_1 + 0x104))();
  (**(code **)(*param_1 + 0x110))();
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
  LeaveCriticalSection(p_Var1);
  return 0;
}


