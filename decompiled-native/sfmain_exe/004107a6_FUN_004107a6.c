// 004107a6 FUN_004107a6 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004107a6(undefined4 param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (DAT_0043d32c == 0) {
    if (DAT_0043d560 != 0) {
      FUN_0040faaf(param_1);
      param_1 = extraout_ECX;
    }
    if (DAT_0043d564 != 0) {
      FUN_0040fb69(param_1);
      param_1 = extraout_ECX_00;
    }
    if (DAT_0043d568 != 0) {
      FUN_0040f631(param_1);
      param_1 = extraout_ECX_01;
    }
    if (DAT_0043d56c != 0) {
      FUN_0040f778();
      param_1 = extraout_ECX_02;
    }
    if (DAT_0043d570 != 0) {
      FUN_0040f804(param_1);
      param_1 = extraout_ECX_03;
    }
    if (DAT_0043d574 != 0) {
      FUN_0040f8a8(param_1);
    }
    DAT_00445b54 = DAT_004393d8 + 0x1c;
    if (DAT_0043d568 == 0) {
      local_24 = 0;
    }
    else {
      local_24 = 0x20;
    }
    _DAT_004393c4 = local_24 | 0x40000000;
    if (DAT_0043d56c == 0) {
      local_20 = 0;
    }
    else {
      local_20 = 0x200;
    }
    _DAT_004393c4 = _DAT_004393c4 | local_20;
    if (DAT_0043d570 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = 0x1000;
    }
    _DAT_004393c4 = _DAT_004393c4 | local_1c;
    if (DAT_0043d584 == 2) {
      DAT_00445b54 = FUN_00425d7e(DAT_004627d4,DAT_00462780,DAT_0043d628);
      DAT_004627d4 = DAT_004627d4 + 1;
      DAT_00462784 = DAT_00462784 + DAT_004627ac;
    }
    else if (DAT_0043d584 == 1) {
      DAT_00445b54 = FUN_00429f80(DAT_0043d628,0);
      DAT_00462784 = DAT_00462784 + DAT_004627ac;
    }
    DAT_0043d628 = 0;
  }
  return;
}


