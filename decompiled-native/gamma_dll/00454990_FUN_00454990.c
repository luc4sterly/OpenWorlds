// 00454990 FUN_00454990 [Global]
// programa: gamma.dll

void __cdecl FUN_00454990(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  for (iVar3 = 0; (uint)(&DAT_00482458)[iVar3] < param_2; iVar3 = iVar3 + 1) {
  }
  *param_1 = (&DAT_0049edfc)[iVar3 * 3];
  (&DAT_0049edfc)[iVar3 * 3] = param_1 + -1;
  (&DAT_0049ee00)[iVar3 * 3] = (&DAT_0049ee00)[iVar3 * 3] + -1;
  if ((&DAT_0049ee00)[iVar3 * 3] == 0) {
    iVar2 = (&DAT_0049edf8)[iVar3 * 3];
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 4);
      FUN_00454790(iVar2);
      iVar2 = iVar1;
    }
    (&DAT_0049edf8)[iVar3 * 3] = 0;
    (&DAT_0049edfc)[iVar3 * 3] = 0;
  }
  return;
}


