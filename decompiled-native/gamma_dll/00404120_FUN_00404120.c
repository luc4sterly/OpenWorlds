// 00404120 FUN_00404120 [Global]
// program: gamma.dll

void __cdecl FUN_00404120(int param_1)

{
  int *piVar1;
  
  for (piVar1 = DAT_0049fcc0; (piVar1 != (int *)0x0 && (*piVar1 != param_1));
      piVar1 = (int *)piVar1[5]) {
  }
  return;
}


