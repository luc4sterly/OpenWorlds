// 10033fd0 FUN_10033fd0 [Global]
// programa: RWL21.DLL

void FUN_10033fd0(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  puVar5 = *(undefined4 **)(param_3 + 0xac);
  piVar6 = *(int **)(param_3 + 0xa8);
  uVar1 = *(uint *)(param_3 + 0xa4);
  pcVar3 = FUN_10029210;
  if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) != 1) {
    pcVar3 = (code *)&LAB_10027510;
  }
  pcVar3 = (code *)FUN_1002a7d0(pcVar3,*(uint *)(param_3 + 0xbc));
  iVar2 = *piVar6;
  while (iVar2 != 0) {
    piVar6 = piVar6 + 1;
    uVar4 = param_2;
    if (uVar1 == 0) {
      uVar4 = param_1;
    }
    FUN_100274c0(uVar4);
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      uVar4 = *puVar5;
      puVar5 = puVar5 + 1;
      (*pcVar3)(uVar4);
    }
    uVar1 = (uint)(uVar1 == 0);
    iVar2 = *piVar6;
  }
  return;
}


