// 004352f0 FUN_004352f0 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004352f0(void *this,int *param_1,uint param_2,short param_3,short param_4,short param_5,
            uint param_6)

{
  void *this_00;
  void *this_01;
  int iVar1;
  undefined4 uVar2;
  undefined **local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [5];
  uint local_8c;
  undefined4 local_88;
  undefined **local_84 [4];
  undefined **local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined **local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [5];
  undefined4 local_40 [5];
  undefined4 local_2c [5];
  int local_18 [2];
  
  this_00 = *(void **)this;
  FUN_00433610(this_00,local_84);
  local_74 = &PTR_LAB_004732e8;
  local_68 = 0;
  local_70 = (float)(int)param_3;
  local_6c = (float)(int)param_4;
  FUN_00428cd0(&local_64,(int)local_84,(int)&local_74);
  local_ac = local_60;
  local_a4 = local_58;
  local_74 = &PTR_LAB_004732e8;
  local_84[0] = &PTR_LAB_00473390;
  local_b0 = &PTR_LAB_00473390;
  local_64 = &PTR_LAB_00473390;
  local_a8 = local_5c;
  FUN_004336a0(this_00,local_54);
  FUN_00428f40(local_40,0x49f398,(float)(int)param_5 * (float)_DAT_00475530 * (float)_DAT_00475538);
  FUN_00429150(local_2c,(int)local_54,(int)local_40);
  FUN_00428df0(local_a0,(int)local_2c);
  FUN_00428e50(local_2c);
  FUN_00428e50(local_40);
  FUN_00428e50(local_54);
  FUN_00427a20(&local_8c,param_6);
  this_01 = *(void **)((int)this + 4);
  local_18[0] = 0;
  local_18[1] = 0;
  iVar1 = FUN_00427b00((int *)((int)this_01 + 0x30),local_18);
  if (iVar1 == 0) {
    uVar2 = FUN_00434670(this_01,(int)&local_b0,local_a0,&local_8c);
    *(undefined4 *)((int)this_01 + 0x2c) = uVar2;
  }
  else {
    *(uint *)((int)this_01 + 0x30) = local_8c;
    *(undefined4 *)((int)this_01 + 0x34) = local_88;
    *(undefined4 *)((int)this_01 + 0x2c) = 1;
  }
  *(undefined4 *)((int)this_01 + 4) = local_ac;
  *(undefined4 *)((int)this_01 + 8) = local_a8;
  *(undefined4 *)((int)this_01 + 0xc) = local_a4;
  FUN_00428e20((void *)((int)this_01 + 0x10),(int)local_a0);
  *(uint *)((int)this_01 + 0x24) = local_8c;
  *(undefined4 *)((int)this_01 + 0x28) = local_88;
  iVar1 = *(int *)((int)this_01 + 0x2c);
  FUN_00432a30(this_00,(int)&local_b0,(int)local_a0,(int *)&local_8c);
  FUN_00432d10(this_00,param_1,param_2,iVar1,-1);
  FUN_00428e50(local_a0);
  return;
}


