// 10013cd0 FUN_10013cd0 [Global]
// programa: RWDL8D21.DLL

undefined4 FUN_10013cd0(int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar1 = param_1[0xf];
  uVar4 = (uint)*(byte *)((int)param_1 + 0x3a);
  piVar7 = param_1 + uVar4 + 0xd;
  iVar5 = uVar4 - 2;
  if (param_2 == 0) {
    pcVar2 = (code *)(&PTR_FUN_10075350)[*(byte *)(*param_1 + 0x30) & DAT_10077d9c];
    iVar3 = param_1[uVar4 + 0xe];
    iVar6 = *piVar7;
    do {
      piVar7 = piVar7 + -1;
      iVar5 = iVar5 + -1;
      (*pcVar2)(param_1,iVar1,iVar6,iVar3);
      iVar3 = iVar6;
      iVar6 = *piVar7;
    } while (0 < iVar5);
  }
  else {
    pcVar2 = (code *)(&PTR_FUN_10075350)[*(byte *)(*param_1 + 0x30) & DAT_10077d9c];
    iVar3 = param_1[uVar4 + 0xe];
    iVar6 = *piVar7;
    do {
      piVar7 = piVar7 + -1;
      iVar5 = iVar5 + -1;
      (*pcVar2)(param_1,iVar1,iVar3,iVar6);
      iVar3 = iVar6;
      iVar6 = *piVar7;
    } while (0 < iVar5);
  }
  return 0;
}


