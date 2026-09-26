// 00401b19 FUN_00401b19 [Global]
// programa: gdkup.exe

uint __fastcall FUN_00401b19(undefined4 param_1,undefined4 param_2)

{
  char *in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  char local_214 [504];
  char *local_1c;
  undefined4 local_18;
  
  local_1c = in_EAX;
  local_18 = param_2;
  FUN_00402828(param_1,s_Assertion_failed__line_00408042);
  iVar1 = FUN_00402847();
  FUN_004028cf(extraout_ECX,local_214 + iVar1);
  FUN_004028ea(extraout_ECX_00,s_in_file_0040805a);
  FUN_004028ea(extraout_ECX_01,local_1c);
  FUN_004028ea(extraout_ECX_02,&DAT_00408064);
  uVar2 = FUN_00401ae0();
  return uVar2 & 0xffffff00;
}


