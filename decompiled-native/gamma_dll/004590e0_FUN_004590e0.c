// 004590e0 FUN_004590e0 [Global]
// program: gamma.dll

int * __cdecl FUN_004590e0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_0049ebcc;
  do {
    if (*piVar1 == param_1) {
      return piVar1;
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 2;
  } while (iVar2 < 0x23);
  return (int *)0x0;
}


