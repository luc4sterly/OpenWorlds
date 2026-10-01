// 1001af40 FUN_1001af40 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_1001af40(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = param_1[0xf];
  uVar3 = (uint)*(byte *)((int)param_1 + 0x3a);
  iVar4 = uVar3 - 2;
  piVar5 = param_1 + uVar3 + 0xd;
  iVar2 = param_1[uVar3 + 0xe];
  iVar6 = param_1[uVar3 + 0xd];
  if (param_2 == 0) {
    do {
      piVar5 = piVar5 + -1;
      iVar4 = iVar4 + -1;
      FUN_1001afb0(param_1,iVar1,iVar6,iVar2);
      iVar2 = iVar6;
      iVar6 = *piVar5;
    } while (0 < iVar4);
  }
  else {
    do {
      piVar5 = piVar5 + -1;
      iVar4 = iVar4 + -1;
      FUN_1001afb0(param_1,iVar1,iVar2,iVar6);
      iVar2 = iVar6;
      iVar6 = *piVar5;
    } while (0 < iVar4);
  }
  return 0;
}


