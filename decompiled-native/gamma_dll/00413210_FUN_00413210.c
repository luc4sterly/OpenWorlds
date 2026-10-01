// 00413210 FUN_00413210 [Global]
// program: gamma.dll

int __cdecl
FUN_00413210(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = FUN_00418f90();
  if (iVar1 == 0) {
    FUN_00402800(s_nWObject_0046f6a4,0x142);
  }
  uVar2 = FUN_00418e70(iVar1,*param_1,param_2[1],param_2[2]);
  uVar3 = FUN_00418e70(iVar1,*param_2,param_2[1],param_2[2]);
  uVar4 = FUN_00418e70(iVar1,*param_2,param_2[1],param_1[2]);
  uVar5 = FUN_00418e70(iVar1,*param_1,param_2[1],param_1[2]);
  uVar6 = FUN_00418e70(iVar1,*param_1,param_1[1],param_2[2]);
  uVar7 = FUN_00418e70(iVar1,*param_2,param_1[1],param_2[2]);
  uVar8 = FUN_00418e70(iVar1,*param_2,param_1[1],param_1[2]);
  uVar9 = FUN_00418e70(iVar1,*param_1,param_1[1],param_1[2]);
  uVar10 = FUN_00419920();
  FUN_00419e90(uVar10,param_3,param_4,param_5);
  FUN_00419ef0(uVar10,DAT_0046f71c,DAT_0046f718,DAT_0046f718);
  FUN_00417a50(uVar10);
  local_70 = uVar2;
  local_6c = uVar3;
  local_68 = uVar4;
  local_64 = uVar5;
  FUN_00418e30(iVar1,4,&local_70);
  local_60 = uVar6;
  local_5c = uVar7;
  local_58 = uVar3;
  local_54 = uVar2;
  FUN_00418e30(iVar1,4,&local_60);
  local_50 = uVar7;
  local_4c = uVar8;
  local_48 = uVar4;
  local_44 = uVar3;
  FUN_00418e30(iVar1,4,&local_50);
  local_40 = uVar8;
  local_3c = uVar9;
  local_38 = uVar5;
  local_34 = uVar4;
  FUN_00418e30(iVar1,4,&local_40);
  local_30 = uVar9;
  local_2c = uVar6;
  local_28 = uVar2;
  local_24 = uVar5;
  FUN_00418e30(iVar1,4,&local_30);
  local_20 = uVar9;
  local_1c = uVar8;
  local_18 = uVar7;
  local_14 = uVar6;
  FUN_00418e30(iVar1,4,&local_20);
  FUN_00417a90(iVar1);
  FUN_004198c0();
  return iVar1;
}


