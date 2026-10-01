// 00434f00 FUN_00434f00 [Global]
// program: gamma.dll

void __cdecl FUN_00434f00(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined **local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  if (param_1 != 0) {
    uVar1 = FUN_00419950();
    uVar2 = FUN_00419950();
    FUN_00418a50(uVar1,DAT_00475528,DAT_00475524,DAT_00475520,DAT_00475520);
    FUN_00418b10(uVar1,DAT_0047552c,DAT_0047552c,DAT_0047552c);
    FUN_00418bf0(param_1,uVar1);
    iVar3 = FUN_004196d0(param_1);
    if (iVar3 != 0) {
      local_44 = 0;
      local_48 = &PTR_LAB_00473390;
      local_3c = 0;
      local_40 = 0;
      FUN_004317e0(iVar3,(int)&local_48);
      FUN_00418ce0(uVar1,local_44,local_40,local_3c);
      FUN_00418c20(param_1,uVar1);
      local_38 = &PTR_LAB_00473390;
      local_2c = 0;
      local_34 = 0;
      local_30 = 0;
      FUN_00431990(iVar3,(int)&local_38);
      local_48 = &PTR_LAB_00473390;
      local_38 = &PTR_LAB_00473390;
    }
    FUN_00435690(param_1,&local_28,&local_24,&local_20);
    FUN_00419420(param_1,uVar1);
    iVar3 = FUN_00419540(param_1);
    if (iVar3 != 0) {
      FUN_004193c0(iVar3,uVar2);
      FUN_00418cb0(uVar1,uVar2);
    }
    FUN_00419860(uVar1,uVar2);
    local_1c = local_28;
    local_14 = local_20;
    local_18 = local_24;
    FUN_0041a080(&local_1c,uVar2);
    if (param_2 == 0) {
      local_18 = 0.0;
      local_1c = 0.0;
    }
    FUN_00418ce0(uVar1,-local_1c,-local_18,-local_14);
    FUN_00418c50(param_1,uVar1);
    FUN_004198f0();
    FUN_004198f0();
  }
  return;
}


