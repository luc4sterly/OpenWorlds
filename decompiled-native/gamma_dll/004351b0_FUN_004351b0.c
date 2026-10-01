// 004351b0 FUN_004351b0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004351b0(void *this,int *param_1,uint param_2,short param_3,short param_4,short param_5,
            short param_6,uint param_7)

{
  void *this_00;
  void *this_01;
  int iVar1;
  undefined4 uVar2;
  undefined **local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34 [5];
  uint local_20;
  undefined4 local_1c;
  int local_18 [2];
  
  local_44 = &PTR_LAB_00473390;
  local_40 = (float)(int)param_3;
  local_3c = (float)(int)param_4;
  local_38 = (float)(int)param_5;
  FUN_00428f40(local_34,0x49f398,(float)(int)param_6 * (float)_DAT_00475530 * (float)_DAT_00475538);
  FUN_00427a20(&local_20,param_7);
  this_00 = *(void **)this;
  this_01 = *(void **)((int)this + 4);
  local_18[1] = 0;
  local_18[0] = 0;
  iVar1 = FUN_00427b00((int *)((int)this_01 + 0x30),local_18);
  if (iVar1 == 0) {
    uVar2 = FUN_00434670(this_01,(int)&local_44,local_34,&local_20);
    *(undefined4 *)((int)this_01 + 0x2c) = uVar2;
  }
  else {
    *(uint *)((int)this_01 + 0x30) = local_20;
    *(undefined4 *)((int)this_01 + 0x34) = local_1c;
    *(undefined4 *)((int)this_01 + 0x2c) = 1;
  }
  *(float *)((int)this_01 + 4) = local_40;
  *(float *)((int)this_01 + 8) = local_3c;
  *(float *)((int)this_01 + 0xc) = local_38;
  FUN_00428e20((void *)((int)this_01 + 0x10),(int)local_34);
  *(uint *)((int)this_01 + 0x24) = local_20;
  *(undefined4 *)((int)this_01 + 0x28) = local_1c;
  iVar1 = *(int *)((int)this_01 + 0x2c);
  FUN_00432a30(this_00,(int)&local_44,(int)local_34,(int *)&local_20);
  FUN_00432d10(this_00,param_1,param_2,iVar1,-1);
  FUN_00428e50(local_34);
  return;
}


