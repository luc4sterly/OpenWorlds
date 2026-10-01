// 00407f70 FUN_00407f70 [Global]
// program: gamma.dll

int * __fastcall FUN_00407f70(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  iVar1 = *param_1;
  lpCriticalSection = (LPCRITICAL_SECTION)(iVar1 + 0x10);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(iVar1 + 8) == 0) {
    *(undefined4 *)(iVar1 + 8) = 1;
  }
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
  if (*(int *)(iVar1 + 8) != 0) {
    iVar1 = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  *param_1 = iVar1;
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_0044e100(*(undefined4 **)(iVar1 + 0xc));
    DeleteCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x10));
    FUN_0044e100((undefined4 *)*param_1);
  }
  return param_1;
}


