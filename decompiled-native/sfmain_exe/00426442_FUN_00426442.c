// 00426442 FUN_00426442 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00426442(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  
  if (_DAT_004bb688 == 0) {
    _DAT_004bb688 = 1;
    iVar1 = FUN_0040aacc(param_1,(undefined1 *)0x4b7740);
    FUN_004080a4(extraout_ECX,(undefined1 *)0x4b7740);
    *(int *)(in_EAX + 0x14) = iVar1;
    _DAT_004bb688 = 0;
  }
  else {
    FUN_004296b9(s_Tried_to_re_enter_lpc10decomp__0043736e);
    *(undefined4 *)(in_EAX + 0x14) = 0;
  }
  return;
}


