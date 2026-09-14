// 004303a0 FUN_004303a0 [Global]
// programa: gamma.dll

char * __thiscall FUN_004303a0(void *this,char *param_1)

{
  undefined **local_41c [65];
  undefined4 local_318 [65];
  undefined4 local_214 [65];
  undefined4 local_110 [65];
  
  *(undefined4 *)((int)this + 0x1000) = 0;
  FUN_0044d6d0(this,param_1,0x400);
  *(undefined1 *)((int)this + 0x3ff) = 0;
  FUN_0042f8e0(local_41c);
  FUN_0044d650((int)this + 0x400,&DAT_00474d10);
  local_41c[0] = &PTR_LAB_00471ff8;
  FUN_0042f800(local_318);
  FUN_0042f950(local_214);
  FUN_0042f870(local_110);
  FUN_0044d650((int)this + 0x800,s__s_s_s_s_00474d18);
  return this;
}


