// 00433e90 FUN_00433e90 [Global]
// programa: gamma.dll

int FUN_00433e90(uint param_1,char *param_2)

{
  bool bVar1;
  uint *this;
  int iVar2;
  undefined3 extraout_var;
  void *pvVar3;
  void *this_00;
  undefined1 local_114 [260];
  
  this = FUN_0042c7f0();
  if (this == (uint *)0x0) {
    return -1;
  }
  iVar2 = FUN_0042ca00(this,param_1);
  if (iVar2 == 0) {
    return -1;
  }
  iVar2 = FUN_0042bd40(iVar2);
  FUN_00427410(local_114,param_2,0xff);
  this_00 = *(void **)(iVar2 + 8);
  pvVar3 = (void *)(*(int *)(iVar2 + 4) * 0x104 + (int)this_00);
  for (; this_00 != pvVar3; this_00 = (void *)((int)this_00 + 0x104)) {
    bVar1 = FUN_00427480(this_00,(int)local_114);
    if (CONCAT31(extraout_var,bVar1) != 0) break;
  }
  if (this_00 == (void *)(*(int *)(iVar2 + 4) * 0x104 + *(int *)(iVar2 + 8))) {
    return -1;
  }
  return ((int)this_00 - *(int *)(iVar2 + 8)) / 0x104 + 1;
}


