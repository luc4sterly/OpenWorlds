// 0044a450 FUN_0044a450 [Global]
// program: gamma.dll

undefined4 __thiscall
FUN_0044a450(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  ulonglong uVar9;
  undefined4 in_stack_ffffffd4;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_10;
  
  iVar6 = *(int *)(param_1 + 0xe8);
  if (iVar6 < 0) {
    uStack_28 = 0;
  }
  else if (*(int *)(param_1 + 0xd0) * 2 < iVar6) {
    uStack_28 = 0;
  }
  else {
    uStack_28 = 1;
  }
  iStack_24 = 1000;
  if (iVar6 < 0) goto LAB_0044a53a;
  bVar8 = param_3 == 0;
  uVar7 = param_3;
  if (bVar8) {
    bVar8 = param_2 == 0;
    uVar7 = param_2;
    if (!bVar8) goto LAB_0044a4b7;
  }
  else {
LAB_0044a4b7:
    if (!bVar8 && -1 < (int)uVar7) {
      uVar9 = FUN_00453c30(param_2,param_3,10000,0);
      iStack_24 = 1000 - (int)uVar9;
      if (iStack_24 < 500) {
        iStack_24 = 500;
      }
      goto LAB_0044a53a;
    }
  }
  iVar4 = *(int *)(param_1 + 0xe4);
  if (20000 < iVar4) {
    bVar8 = SBORROW4(param_3,-1);
    iVar3 = param_3 + 1;
    if (param_3 == 0xffffffff) {
      bVar8 = SBORROW4(param_2,-20000);
      iVar3 = param_2 + 20000;
      if (0xffffb1df < param_2) goto LAB_0044a53a;
    }
    if (bVar8 != iVar3 < 0) {
      if ((iVar4 < iVar6) && (iVar4 < iVar6 + 20000)) {
        iStack_24 = (iVar6 / ((iVar6 + 20000) - iVar4)) * 1000;
      }
      else {
        iStack_24 = 2000;
      }
      if (2000 < iStack_24) {
        iStack_24 = 2000;
      }
    }
  }
LAB_0044a53a:
  iVar6 = (*(uint *)(param_1 + 0xd0) + 1) - (uint)(*(uint *)(param_1 + 0xd0) < 0x80000000);
  uVar7 = iVar6 >> 1;
  if (*(int *)(param_1 + 0xa4) == 0) {
    uStack_10 = 0;
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x70) + 0x18);
    iVar4 = (**(code **)*puVar1)(puVar1,&DAT_00467078,&uStack_10);
    if (-1 < iVar4) {
      *(undefined4 *)(param_1 + 0xa4) = uStack_10;
    }
  }
  piVar2 = *(int **)(param_1 + 0xa4);
  if (piVar2 != (int *)0x0) {
    if (param_1 != 0) {
      param_1 = param_1 + 0xc;
    }
    uVar5 = (**(code **)(*piVar2 + 0xc))
                      (piVar2,param_1,uStack_28,iStack_24,uVar7 + param_2,
                       (iVar6 >> 0x1f) + param_3 + (uint)CARRY4(uVar7,param_2),param_4,param_5,
                       in_stack_ffffffd4);
    return uVar5;
  }
  return 1;
}


