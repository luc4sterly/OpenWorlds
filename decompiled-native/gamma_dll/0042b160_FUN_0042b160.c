// 0042b160 FUN_0042b160 [Global]
// programa: gamma.dll

void __thiscall FUN_0042b160(void *this,int *param_1,uint param_2)

{
  uint *this_00;
  uint *this_01;
  int iVar1;
  int iVar2;
  int iVar3;
  int local_24;
  int local_20;
  int *local_1c;
  uint local_18;
  undefined4 local_14;
  
  FUN_0042b380(this,&local_24,(int *)&param_2);
  if (local_24 == (int)this + 4) {
    local_14 = DAT_00474738;
    local_18 = param_2;
    local_1c = *(int **)((int)this + 0xc);
    FUN_0042b3f0(this,&local_20,local_1c,&local_18);
    local_24 = local_20;
  }
  iVar1 = *(int *)(local_24 + 0x10);
  *(int *)(local_24 + 0x10) = *(int *)(local_24 + 0x10) + 1;
  if (iVar1 == 0) {
    this_00 = FUN_0042c7f0();
    if (this_00 == (uint *)0x0) {
      return;
    }
    this_01 = FUN_0042fc50();
    if (this_01 == (uint *)0x0) {
      return;
    }
    iVar1 = FUN_0042ca00(this_00,param_2);
    if (iVar1 == 0) {
      return;
    }
    iVar2 = FUN_0042bd30(iVar1);
    for (iVar3 = *(int *)(iVar2 + 8); iVar3 != *(int *)(iVar2 + 4) * 0x104 + *(int *)(iVar2 + 8);
        iVar3 = iVar3 + 0x104) {
      FUN_0042ffd0(this_01,param_1,(char *)(iVar3 + 4));
    }
    iVar3 = FUN_0042bd50(iVar1);
    for (iVar1 = *(int *)(iVar3 + 8); iVar1 != *(int *)(iVar3 + 4) * 0x104 + *(int *)(iVar3 + 8);
        iVar1 = iVar1 + 0x104) {
      FUN_0042ffd0(this_01,param_1,(char *)(iVar1 + 4));
    }
  }
  return;
}


