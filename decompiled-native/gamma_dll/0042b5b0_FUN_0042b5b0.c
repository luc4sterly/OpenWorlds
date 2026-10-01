// 0042b5b0 FUN_0042b5b0 [Global]
// program: gamma.dll

void __cdecl FUN_0042b5b0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(*param_1 + 4);
  if (*(int **)(*param_1 + 4) == (int *)0x0) {
    while (piVar2 = (int *)(*(uint *)(*param_1 + 8) & 0xfffffffe), *param_1 != *piVar2) {
      *param_1 = (int)piVar2;
    }
    *param_1 = (int)piVar2;
  }
  else {
    do {
      piVar1 = piVar2;
      piVar2 = (int *)*piVar1;
    } while (piVar2 != (int *)0x0);
    *param_1 = (int)piVar1;
  }
  return;
}


