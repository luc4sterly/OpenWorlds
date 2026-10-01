// 00402ab7 FUN_00402ab7 [Global]
// program: run.exe

int * __cdecl FUN_00402ab7(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_004091b8;
  if (DAT_004091b8 != param_1) {
    do {
      piVar1 = piVar1 + 3;
      if (&DAT_004091b8 + DAT_00409238 * 3 <= piVar1) break;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_004091b8 + DAT_00409238 * 3 <= piVar1) || (*piVar1 != param_1)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


