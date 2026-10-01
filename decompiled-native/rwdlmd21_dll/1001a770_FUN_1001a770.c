// 1001a770 FUN_1001a770 [Global]
// program: rwdlmd21.dll

undefined4 FUN_1001a770(int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar1 = param_1[0xf];
  uVar4 = (uint)*(byte *)((int)param_1 + 0x3a);
  piVar6 = param_1 + uVar4 + 0xd;
  iVar5 = uVar4 - 2;
  if (param_2 == 0) {
    pcVar2 = (code *)(&PTR_FUN_100874f8)[*(byte *)(*param_1 + 0x30) & DAT_10089dd4];
    iVar3 = param_1[uVar4 + 0xe];
    iVar7 = *piVar6;
    do {
      piVar6 = piVar6 + -1;
      iVar5 = iVar5 + -1;
      (*pcVar2)(param_1,iVar1,iVar7,iVar3);
      iVar3 = iVar7;
      iVar7 = *piVar6;
    } while (0 < iVar5);
  }
  else {
    pcVar2 = (code *)(&PTR_FUN_100874f8)[*(byte *)(*param_1 + 0x30) & DAT_10089dd4];
    iVar3 = param_1[uVar4 + 0xe];
    iVar7 = *piVar6;
    do {
      piVar6 = piVar6 + -1;
      iVar5 = iVar5 + -1;
      (*pcVar2)(param_1,iVar1,iVar3,iVar7);
      iVar3 = iVar7;
      iVar7 = *piVar6;
    } while (0 < iVar5);
  }
  return 0;
}


