// 004349d0 FUN_004349d0 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_004349d0(char *param_1)

{
  uint *puVar1;
  undefined **local_654 [65];
  undefined **local_550 [65];
  undefined **local_44c [65];
  undefined **local_348 [65];
  undefined **local_244 [65];
  undefined **local_140 [65];
  undefined **local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [5];
  undefined **local_18 [4];
  
  FUN_00427410(local_654,&DAT_004754f0,0xff);
  FUN_0042f840((int)local_654);
  local_654[0] = &PTR_LAB_00471ff8;
  FUN_00427410(local_550,&DAT_004754f8,0xff);
  FUN_0042f8b0((int)local_550);
  local_550[0] = &PTR_LAB_00471ff8;
  FUN_00427410(local_44c,param_1,0xff);
  FUN_0042f6b0((int)local_44c);
  local_44c[0] = &PTR_LAB_00471ff8;
  FUN_00427410(local_348,&DAT_00475500,0xff);
  FUN_0042f920((int)local_348);
  local_348[0] = &PTR_LAB_00471ff8;
  FUN_00427410(local_244,s_avatars_00475504,0xff);
  FUN_0042f6e0((int)local_244);
  local_244[0] = &PTR_LAB_00471ff8;
  FUN_00427410(local_140,s_avatars_00475504,0xff);
  FUN_0042f790((int)local_140);
  local_140[0] = &PTR_LAB_00471ff8;
  local_3c = &PTR_LAB_004732e8;
  local_38 = 0;
  local_30 = 0x3f800000;
  local_34 = 0x3f800000;
  FUN_00428f40(local_2c,(int)&local_3c,DAT_0047550c);
  FUN_0042f990((int)local_2c);
  FUN_00428e50(local_2c);
  local_3c = &PTR_LAB_004732e8;
  FUN_004295a0(local_18,DAT_00475510,0x49f3e8);
  FUN_0042f9b0((int)local_18);
  local_18[0] = &PTR_LAB_004732e8;
  FUN_0042f9d0(0x49f398);
  FUN_0042fa00(0x49f3f8);
  FUN_004298b0();
  puVar1 = FUN_0042c7f0();
  FUN_0042ca50(puVar1);
  return 1;
}


