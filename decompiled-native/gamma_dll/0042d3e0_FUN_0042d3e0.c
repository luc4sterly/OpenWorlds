// 0042d3e0 FUN_0042d3e0 [Global]
// program: gamma.dll

void __thiscall FUN_0042d3e0(void *this,int *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  undefined1 local_858 [264];
  undefined **local_750 [65];
  int local_64c;
  undefined **local_648;
  char acStack_644 [255];
  undefined1 local_545;
  undefined1 local_544 [264];
  undefined1 local_43c [264];
  undefined **local_334;
  undefined1 local_330;
  undefined **local_230;
  char acStack_22c [256];
  undefined **local_12c [71];
  
  uVar3 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar3;
  while (iVar1 = *(int *)((int)this + 0xf0), iVar1 != 0x106) {
    if (iVar1 != 0x10a) {
      FUN_0042c6a0(local_858,param_1[3],iVar1);
      FUN_00451670();
    }
    FUN_004280b0(&DAT_0049eeb8,&DAT_0049eeb8);
    FUN_00427410(local_750,&DAT_0049eeb8,0xff);
    local_334 = &PTR_LAB_00471ff8;
    local_330 = 0;
    bVar2 = FUN_00427480(local_750,(int)&local_334);
    local_334 = &PTR_LAB_00471ff8;
    if (CONCAT31(extraout_var,bVar2) != 0) {
      FUN_00427410(&local_230,s_invalid_action_name__004749b0,0xff);
      local_64c = param_1[3];
      local_648 = &PTR_LAB_00471ff8;
      FUN_0044d6d0(acStack_644,acStack_22c,0xff);
      local_545 = 0;
      FUN_00451670();
      local_230 = &PTR_LAB_00471ff8;
    }
    uVar3 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar3;
    if (*(int *)((int)this + 0xf0) != 0x101) {
      FUN_0042c6a0(local_544,param_1[3],*(int *)((int)this + 0xf0));
      FUN_00451670();
    }
    uVar3 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar3;
    if (*(int *)((int)this + 0xf0) != 0x10a) {
      FUN_0042c6a0(local_43c,param_1[3],*(int *)((int)this + 0xf0));
      FUN_00451670();
    }
    FUN_0042e720((void *)(param_2 + 0x10),(int)local_750);
    FUN_00427410(local_12c,&DAT_0049eeb8,0xff);
    FUN_0042e720((void *)(param_2 + 0x1c),(int)local_12c);
    local_750[0] = &PTR_LAB_00471ff8;
    local_12c[0] = &PTR_LAB_00471ff8;
    uVar3 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar3;
  }
  return;
}


