// 0042b280 FUN_0042b280 [Global]
// program: gamma.dll

void __thiscall FUN_0042b280(void *this,uint param_1)

{
  uint *this_00;
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar5;
  int local_14;
  
  FUN_0042b380(this,&local_14,(int *)&param_1);
  if (local_14 == (int)this + 4) {
    return;
  }
  *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + -1;
  if (*(int *)(local_14 + 0x10) < 1) {
    *(undefined4 *)(local_14 + 0x10) = 0;
    this_00 = FUN_0042c7f0();
    if (this_00 == (uint *)0x0) {
      return;
    }
    puVar1 = FUN_0042fc50();
    if (puVar1 == (uint *)0x0) {
      return;
    }
    iVar2 = FUN_0042ca00(this_00,param_1);
    if (iVar2 == 0) {
      return;
    }
    iVar3 = FUN_0042bd30(iVar2);
    uVar5 = extraout_EDX;
    for (iVar4 = *(int *)(iVar3 + 8); iVar4 != *(int *)(iVar3 + 4) * 0x104 + *(int *)(iVar3 + 8);
        iVar4 = iVar4 + 0x104) {
      FUN_004301c0(puVar1,uVar5,(char *)(iVar4 + 4));
      uVar5 = extraout_EDX_00;
    }
    iVar4 = FUN_0042bd50(iVar2);
    uVar5 = extraout_EDX_01;
    for (iVar2 = *(int *)(iVar4 + 8); iVar2 != *(int *)(iVar4 + 4) * 0x104 + *(int *)(iVar4 + 8);
        iVar2 = iVar2 + 0x104) {
      FUN_004301c0(puVar1,uVar5,(char *)(iVar2 + 4));
      uVar5 = extraout_EDX_02;
    }
  }
  return;
}


