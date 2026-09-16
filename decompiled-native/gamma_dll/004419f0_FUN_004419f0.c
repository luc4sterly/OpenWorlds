// 004419f0 FUN_004419f0 [Global]
// programa: gamma.dll

undefined4 FUN_004419f0(int param_1,int *param_2)

{
  DWORD DVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x48));
  if (*(int *)(param_1 + -0x60) == 0) {
    iVar2 = *(int *)(param_1 + 0x74);
  }
  else {
    DVar1 = timeGetTime();
    iVar2 = DVar1 - *(int *)(param_1 + 0x74);
  }
  if (iVar2 < 1) {
    *param_2 = 0;
  }
  else {
    iVar2 = MulDiv(100000,*(int *)(param_1 + 0x40),iVar2);
    *param_2 = iVar2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x48));
  return 0;
}


