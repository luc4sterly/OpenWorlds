// 004587c0 FUN_004587c0 [Global]
// programa: gamma.dll

void FUN_004587c0(void)

{
  int *piVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = (int *)FUN_00458a30();
  *piVar1 = *piVar1 + -1;
  if (0 < *piVar1) {
    return;
  }
  FUN_00450860();
  if (DAT_0049fa70 != (code *)0x0) {
    (*DAT_0049fa70)();
    DAT_0049fa70 = (code *)0x0;
  }
  iVar2 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)&DAT_0049ee28;
  do {
    DeleteCriticalSection(lpCriticalSection);
    lpCriticalSection = lpCriticalSection + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  if (DAT_0049ff50 != (code *)0x0) {
    (*DAT_0049ff50)();
    DAT_0049ff50 = (code *)0x0;
  }
  FUN_00454ad0();
  return;
}


