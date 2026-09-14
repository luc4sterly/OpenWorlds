// 004296f0 FUN_004296f0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_004296f0(int param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 *this;
  undefined3 extraout_var;
  int iVar3;
  undefined **local_32c;
  char local_328 [255];
  undefined1 local_229;
  undefined4 local_228;
  undefined1 local_221;
  undefined **local_220;
  char local_21c [255];
  undefined1 local_11d;
  int local_11c;
  undefined **local_118;
  char local_114 [255];
  undefined1 local_15;
  int local_14;
  
  local_32c = &PTR_LAB_00471ff8;
  FUN_0044d6d0(local_328,(char *)(param_1 + 4),0xff);
  local_221 = DAT_0049dbc0;
  local_229 = 0;
  local_228 = 0;
  this = (undefined4 *)
         FUN_00429ad0(DAT_0049ff70,DAT_0049ff6c * 0x108 + DAT_0049ff70,(int)&local_32c);
  if (this != (undefined4 *)(DAT_0049ff6c * 0x108 + DAT_0049ff70)) {
    bVar2 = FUN_004274b0(this,param_1);
    if (CONCAT31(extraout_var,bVar2) == 0) goto LAB_00429852;
  }
  iVar1 = DAT_00473890;
  local_220 = &PTR_LAB_00471ff8;
  FUN_0044d6d0(local_21c,(char *)(param_1 + 4),0xff);
  iVar3 = (int)this - DAT_0049ff70;
  local_11c = iVar1;
  local_11d = 0;
  FUN_00429bb0(&DAT_0049ff68,this,(undefined4 *)0x1,(int)&local_220);
  iVar1 = DAT_00473890;
  local_220 = &PTR_LAB_00471ff8;
  local_118 = &PTR_LAB_00471ff8;
  this = (undefined4 *)((iVar3 / 0x108) * 0x108 + DAT_0049ff70);
  FUN_0044d6d0(local_114,(char *)(param_1 + 4),0xff);
  local_14 = iVar1;
  local_15 = 0;
  FUN_0042a100(&DAT_0049ff38,(int)&local_118);
  DAT_00473890 = DAT_00473890 + 1;
LAB_00429852:
  return this[0x41];
}


