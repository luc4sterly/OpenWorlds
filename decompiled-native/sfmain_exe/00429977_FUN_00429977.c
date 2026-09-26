// 00429977 FUN_00429977 [Global]
// programa: sfmain.exe

int FUN_00429977(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar2;
  int local_10;
  
  local_10 = Ordinal_16();
  if (local_10 == -1) {
    iVar1 = Ordinal_111();
    if (iVar1 == 0x2733) {
      local_10 = 0;
    }
    else {
      FUN_004296b9(s__s__d_recv__d___d__error__>__d_0043759f);
      FUN_004296b9(s_WSA_error____d_004374de);
      DAT_004623b8 = DAT_004623b8 + 1;
      FUN_004173ab(extraout_ECX_00,DAT_004623b8);
    }
  }
  else {
    if (local_10 < 0) {
      FUN_004296b9(s__s__d_Negative_bytes__004375e0);
      uVar2 = extraout_ECX_01;
    }
    else {
      DAT_004623ac = DAT_004623ac + local_10;
      FUN_004173ab(extraout_ECX,DAT_004623ac);
      uVar2 = extraout_ECX_02;
    }
    DAT_0043d6b4 = DAT_0043d6b4 + 1;
    FUN_004173ab(uVar2,DAT_0043d6b4);
  }
  return local_10;
}


