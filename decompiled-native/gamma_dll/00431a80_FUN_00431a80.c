// 00431a80 FUN_00431a80 [Global]
// programa: gamma.dll

void __thiscall FUN_00431a80(void *this,float param_1,int param_2,void *param_3,float *param_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined **local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined **local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined **local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined **local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34 [4];
  undefined4 local_24 [5];
  
  FUN_004287c0(this,&local_64,param_1);
  *(undefined4 *)(param_2 + 4) = local_60;
  *(undefined4 *)(param_2 + 8) = local_5c;
  *(undefined4 *)(param_2 + 0xc) = local_58;
  local_64 = &PTR_LAB_00473390;
  FUN_00428900(this,&local_54,param_1);
  local_70 = local_50;
  local_74 = &PTR_LAB_004732e8;
  local_54 = &PTR_LAB_004732e8;
  local_6c = local_4c;
  local_68 = local_48;
  if (*(int *)((int)this + 0x44) != 0) {
    FUN_00429520(&local_44,(int)&local_74,DAT_00475198);
    local_70 = local_40;
    local_6c = local_3c;
    local_44 = &PTR_LAB_004732e8;
    local_68 = local_38;
  }
  FUN_00429600(local_34,(int)&local_74);
  puVar2 = local_34;
  puVar1 = FUN_0042fa20();
  FUN_00429380(local_24,(int)puVar1,(int)puVar2);
  FUN_00428e20(param_3,(int)local_24);
  FUN_00428e50(local_24);
  *param_4 = param_1 * *(float *)((int)this + 0x40);
  return;
}


