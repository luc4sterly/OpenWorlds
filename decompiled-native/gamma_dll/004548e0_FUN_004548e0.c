// 004548e0 FUN_004548e0 [Global]
// programa: gamma.dll

int __cdecl FUN_004548e0(uint param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  for (iVar3 = 0; (uint)(&DAT_00482458)[iVar3] < param_1; iVar3 = iVar3 + 1) {
  }
  if ((&DAT_0049edfc)[iVar3 * 3] == 0) {
    puVar1 = FUN_00454710(4000);
    if (puVar1 == (uint *)0x0) {
      return 0;
    }
    if ((puVar1[-1] & 1) == 0) {
      iVar2 = *(int *)(puVar1[-1] + 8);
    }
    else {
      iVar2 = (puVar1[-2] & 0xfffffff8) - 8;
    }
    FUN_004547f0(puVar1,0,(&DAT_0049edf8)[iVar3 * 3],iVar3,(int *)(puVar1 + 3),iVar2 - 0xc);
    (&DAT_0049edf8)[iVar3 * 3] = puVar1;
  }
  iVar2 = (&DAT_0049edfc)[iVar3 * 3];
  (&DAT_0049edfc)[iVar3 * 3] = *(undefined4 *)(iVar2 + 4);
  (&DAT_0049ee00)[iVar3 * 3] = (&DAT_0049ee00)[iVar3 * 3] + 1;
  return iVar2 + 4;
}


