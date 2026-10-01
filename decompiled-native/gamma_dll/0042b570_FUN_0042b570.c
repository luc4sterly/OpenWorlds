// 0042b570 FUN_0042b570 [Global]
// program: gamma.dll

void __cdecl FUN_0042b570(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)*param_1;
  if (*(int *)*param_1 == 0) {
    while (piVar3 = (int *)(*(uint *)(*param_1 + 8) & 0xfffffffe), *param_1 == *piVar3) {
      *param_1 = (int)piVar3;
    }
    *param_1 = (int)piVar3;
  }
  else {
    do {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar2 + 4);
    } while (iVar1 != 0);
    *param_1 = iVar2;
  }
  return;
}


