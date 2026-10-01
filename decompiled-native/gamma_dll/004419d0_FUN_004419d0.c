// 004419d0 FUN_004419d0 [Global]
// program: gamma.dll

undefined4 FUN_004419d0(int param_1,undefined4 *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  ulonglong uVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + -0x48);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + -0xa4) == 0) {
    *param_2 = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  if (*(int *)(param_1 + 0x40) < 2) {
    *param_2 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 0x40) - 1;
    uVar2 = FUN_00453c30(*(uint *)(param_1 + 0x44),*(uint *)(param_1 + 0x48),uVar1,
                         (int)uVar1 >> 0x1f);
    *param_2 = (int)uVar2;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


