// 0042c6a0 FUN_0042c6a0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_0042c6a0(void *this,undefined4 param_1,int param_2)

{
  char local_50c [1024];
  undefined **local_10c;
  char local_108 [256];
  
  *(undefined4 *)this = param_1;
  *(undefined ***)((int)this + 4) = &PTR_LAB_00471ff8;
  *(undefined1 *)((int)this + 8) = 0;
  if (param_2 == -1) {
    FUN_0044d650((int)local_50c,s_unexpected_end_of_file_004748a4);
  }
  else if (param_2 == 0) {
    FUN_0044d650((int)local_50c,s_unexpected_token___s__004748bc);
  }
  else if (param_2 == 0x109) {
    FUN_0044d650((int)local_50c,s_unexpected_value___d__0047488c);
  }
  else if (param_2 == 0x10a) {
    FUN_0044d650((int)local_50c,s_unexpected_identifier___s__00474870);
  }
  else {
    FUN_0044d650((int)local_50c,s_unexpected_keyword___s__004748d4);
  }
  FUN_00427410(&local_10c,local_50c,0xff);
  FUN_0044d6d0((char *)((int)this + 8),local_108,0xff);
  *(undefined1 *)((int)this + 0x107) = 0;
  local_10c = &PTR_LAB_00471ff8;
  FUN_0044d5a0(&DAT_004748ec);
  return this;
}


