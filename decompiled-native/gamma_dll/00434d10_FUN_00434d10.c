// 00434d10 FUN_00434d10 [Global]
// programa: gamma.dll

void __cdecl FUN_00434d10(uint param_1,char *param_2)

{
  bool bVar1;
  uint *this;
  void *this_00;
  undefined3 extraout_var;
  undefined **local_628;
  char local_624 [255];
  undefined1 local_525;
  undefined **local_524 [65];
  undefined **local_420;
  char local_41c [256];
  undefined **local_31c;
  undefined1 local_318;
  undefined **local_218;
  char local_214 [256];
  undefined **local_114;
  char local_110 [256];
  
  *param_2 = '\0';
  this = FUN_0042c7f0();
  if (this == (uint *)0x0) {
    return;
  }
  this_00 = (void *)FUN_0042ca00(this,param_1);
  if (this_00 == (void *)0x0) {
    return;
  }
  FUN_00427410(local_524,s_geometry_00475514,0xff);
  FUN_0042bcb0(this_00,&local_420,local_524);
  local_628 = &PTR_LAB_00471ff8;
  FUN_0044d6d0(local_624,local_41c,0xff);
  local_31c = &PTR_LAB_00471ff8;
  local_525 = 0;
  local_318 = 0;
  local_420 = &PTR_LAB_00471ff8;
  local_524[0] = &PTR_LAB_00471ff8;
  bVar1 = FUN_00427480(&local_628,(int)&local_31c);
  local_31c = &PTR_LAB_00471ff8;
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return;
  }
  FUN_0042f750(&local_218);
  FUN_0044d6b0(param_2,local_214);
  local_218 = &PTR_LAB_00471ff8;
  FUN_0042f950(&local_114);
  FUN_0044d700(param_2,local_110);
  local_114 = &PTR_LAB_00471ff8;
  FUN_0044d700(param_2,local_624);
  return;
}


