// 0042cb90 FUN_0042cb90 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_0042cb90(void *this,void *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 local_358 [24];
  undefined1 *local_340;
  byte local_33c [36];
  byte local_318 [36];
  byte local_2f4 [36];
  int local_2d0 [30];
  undefined4 local_258;
  undefined **local_254;
  char local_250 [255];
  undefined1 local_151;
  undefined **local_150;
  char local_14c [280];
  int local_34 [2];
  undefined1 local_29;
  
  local_340 = local_358;
  *(undefined4 *)((int)this + 0xf4) = param_2;
  pbVar4 = (byte *)s___animation_registry_version_0_2_00474910;
  pbVar5 = local_33c;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pbVar5 = *(undefined4 *)pbVar4;
    pbVar4 = pbVar4 + 4;
    pbVar5 = pbVar5 + 4;
  }
  *pbVar5 = *pbVar4;
  pbVar4 = (byte *)s___animation_registry_version_0_3_00474934;
  pbVar5 = local_318;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pbVar5 = *(undefined4 *)pbVar4;
    pbVar4 = pbVar4 + 4;
    pbVar5 = pbVar5 + 4;
  }
  *pbVar5 = *pbVar4;
  FUN_0042a870(local_2d0,param_1,0);
  FUN_004049b0(*(void **)((int)param_1 + 4),local_34);
  local_29 = DAT_0049dc1d;
  piVar2 = (int *)FUN_00404a00(local_34);
  uVar1 = (**(code **)(*piVar2 + 0x14))(10);
  local_358[0] = uVar1;
  FUN_00404dc0(local_34);
  FUN_0041f300(param_1,(char *)local_2f4,0x21,(char)local_358._0_4_);
  iVar3 = FUN_0044d730(local_2f4,local_33c);
  if (iVar3 == 0) {
    FUN_0042d840(this,local_2d0);
  }
  else {
    iVar3 = FUN_0044d730(local_2f4,local_318);
    if (iVar3 == 0) {
      FUN_0042cda0(this,local_2d0);
    }
    else {
      FUN_00427410(&local_150,s_unrecognized_cookie_00474968,0xff);
      local_254 = &PTR_LAB_00471ff8;
      local_258 = 1;
      FUN_0044d6d0(local_250,local_14c,0xff);
      local_151 = 0;
      FUN_00451670();
      local_150 = &PTR_LAB_00471ff8;
    }
  }
  piVar2 = FUN_0042a960(local_2d0);
  return CONCAT31((int3)((uint)piVar2 >> 8),1);
}


