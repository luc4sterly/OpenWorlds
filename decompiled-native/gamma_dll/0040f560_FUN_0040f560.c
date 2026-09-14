// 0040f560 FUN_0040f560 [Global]
// programa: gamma.dll

int * __cdecl FUN_0040f560(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    piVar1 = (int *)(&DAT_0049fccc)[iVar2];
    if ((piVar1 != (int *)0x0) && (*piVar1 == param_1)) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return (int *)0x0;
    }
  }
  return piVar1;
}


