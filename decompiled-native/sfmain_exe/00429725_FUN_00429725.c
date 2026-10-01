// 00429725 FUN_00429725 [Global]
// program: sfmain.exe

int FUN_00429725(void)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int unaff_EBX;
  int local_10;
  
  local_10 = Ordinal_19();
  if (local_10 == -1) {
    FUN_004296b9(s__s__d_send__d___d__error__>__d_004374be);
    Ordinal_111();
    FUN_004296b9(s_WSA_error____d_004374de);
    DAT_004623b4 = DAT_004623b4 + 1;
    FUN_004173ab(extraout_ECX_00,DAT_004623b4);
  }
  else if (local_10 < 0) {
    FUN_004296b9(s_send___returned__d__004374f2);
    local_10 = 0;
  }
  else {
    DAT_004623a8 = DAT_004623a8 + local_10;
    FUN_004173ab(extraout_ECX,DAT_004623a8);
    if (local_10 == unaff_EBX) {
      DAT_0043d6b8 = DAT_0043d6b8 + 1;
      FUN_004173ab(extraout_ECX_01,DAT_0043d6b8);
    }
    else {
      DAT_0043d6c0 = DAT_0043d6c0 + 1;
      FUN_004173ab(extraout_ECX_01,DAT_0043d6c0);
      FUN_004296b9(s__s__d_Output_lost__send___only_s_00437507);
    }
  }
  return local_10;
}


