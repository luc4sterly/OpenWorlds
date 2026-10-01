// 0040f4a0 FUN_0040f4a0 [Global]
// program: gamma.dll

int __fastcall FUN_0040f4a0(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891d0);
  iVar1 = 0;
  do {
    if ((&DAT_0049fccc)[iVar1] == param_1) {
      (&DAT_0049fccc)[iVar1] = 0;
      break;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  if (4 < iVar1) {
    FUN_00402800(s_nWindow_0046e8c4,0x901);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004891d0);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  if (DAT_0049ff1c == param_1) {
    DAT_004a0008 = 0;
    DAT_0049ff1c = 0;
  }
  return param_1;
}


