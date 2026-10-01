// 00431b70 FUN_00431b70 [Global]
// program: gamma.dll

void __thiscall
FUN_00431b70(void *this,int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  float10 fVar1;
  undefined **local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined **local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined **local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined **local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [16];
  
  local_90 = &PTR_LAB_00473390;
  local_8c = *(undefined4 *)(param_1 + 4);
  local_88 = *(undefined4 *)(param_1 + 8);
  local_84 = *(undefined4 *)(param_1 + 0xc);
  local_80 = &PTR_LAB_004732e8;
  local_7c = *(undefined4 *)(param_2 + 4);
  local_78 = *(undefined4 *)(param_2 + 8);
  local_74 = *(undefined4 *)(param_2 + 0xc);
  local_70 = &PTR_LAB_00473390;
  local_6c = *(undefined4 *)(param_3 + 4);
  local_68 = *(undefined4 *)(param_3 + 8);
  local_64 = *(undefined4 *)(param_3 + 0xc);
  local_60 = &PTR_LAB_004732e8;
  local_5c = *(undefined4 *)(param_4 + 4);
  local_58 = *(undefined4 *)(param_4 + 8);
  local_54 = *(undefined4 *)(param_4 + 0xc);
  FUN_004286a0(local_50,(int)&local_90,(int)&local_80,(int)&local_70,(int)&local_60);
  FUN_00428740(this,(int)local_50);
  FUN_004287a0(local_50);
  local_90 = &PTR_LAB_00473390;
  local_60 = &PTR_LAB_004732e8;
  local_80 = &PTR_LAB_004732e8;
  local_70 = &PTR_LAB_00473390;
  fVar1 = FUN_00428a20((int)this);
  *(float *)((int)this + 0x40) = (float)fVar1;
  *(undefined4 *)((int)this + 0x44) = param_5;
  return;
}


