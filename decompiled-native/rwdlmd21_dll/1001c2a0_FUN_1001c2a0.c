// 1001c2a0 FUN_1001c2a0 [Global]
// programa: rwdlmd21.dll

undefined4 FUN_1001c2a0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar1 = param_1[0xf];
  uVar3 = (uint)*(byte *)((int)param_1 + 0x3a);
  iVar4 = uVar3 - 2;
  piVar6 = param_1 + uVar3 + 0xd;
  iVar2 = param_1[uVar3 + 0xe];
  iVar5 = param_1[uVar3 + 0xd];
  if (param_2 == 0) {
    do {
      piVar6 = piVar6 + -1;
      iVar4 = iVar4 + -1;
      FUN_1001c310(param_1,iVar1,iVar5,iVar2);
      iVar2 = iVar5;
      iVar5 = *piVar6;
    } while (0 < iVar4);
  }
  else {
    do {
      piVar6 = piVar6 + -1;
      iVar4 = iVar4 + -1;
      FUN_1001c310(param_1,iVar1,iVar2,iVar5);
      iVar2 = iVar5;
      iVar5 = *piVar6;
    } while (0 < iVar4);
  }
  return 0;
}


