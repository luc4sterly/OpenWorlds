// 00410412 FUN_00410412 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00410412(undefined4 param_1,int param_2)

{
  POINT pt;
  HWND in_EAX;
  BOOL BVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_48;
  HCURSOR local_44;
  HCURSOR local_40;
  tagPOINT local_34;
  tagRECT local_2c;
  HWND local_1c;
  int local_18;
  
  local_18 = param_2;
  if (DAT_0043d32c != DAT_0043d328) {
    local_1c = in_EAX;
    GetWindowRect(in_EAX,&local_2c);
    GetCursorPos(&local_34);
    pt.y = local_34.y;
    pt.x = local_34.x;
    BVar1 = PtInRect(&local_2c,pt);
    param_1 = extraout_ECX;
    if (BVar1 != 0) {
      if ((*(int *)(local_18 + 0x654) == 0) && (DAT_0043d530 == 0)) {
        local_44 = DAT_0043d54c;
      }
      else {
        if (DAT_0043d32c == 0) {
          local_40 = DAT_0043d554;
        }
        else {
          local_40 = DAT_0043d550;
        }
        local_44 = local_40;
      }
      SetCursor(local_44);
      UpdateWindow(local_1c);
      param_1 = extraout_ECX_00;
    }
    DAT_0043d328 = DAT_0043d32c;
  }
  if (DAT_0043d328 == 0) {
    if (DAT_0043d584 == 0) {
      if (*(int *)(local_18 + 0x4c40) == 0) {
        local_70 = 0;
      }
      else {
        local_70 = 4;
      }
      _DAT_004393c4 = local_70 | 0x40000000;
      *(undefined4 *)(local_18 + 0x4c40) = 0;
      if (*(int *)(local_18 + 0x4c44) == 0) {
        local_6c = 0;
      }
      else {
        local_6c = 2;
      }
      _DAT_004393c4 = _DAT_004393c4 | local_6c;
      if (*(int *)(local_18 + 0x4c4c) == 0) {
        local_68 = 0;
      }
      else {
        local_68 = 0x10;
      }
      _DAT_004393c4 = _DAT_004393c4 | local_68;
      local_64 = (uint)(DAT_0043d560 != 0);
      _DAT_004393c4 = _DAT_004393c4 | local_64;
      if (DAT_0043d564 == 0) {
        local_60 = 0;
      }
      else {
        local_60 = 0x80000;
      }
      _DAT_004393c4 = _DAT_004393c4 | local_60;
      if (DAT_0043d568 == 0) {
        local_5c = 0;
      }
      else {
        local_5c = 0x20;
      }
      _DAT_004393c4 = _DAT_004393c4 | local_5c;
      if (DAT_0043d56c == 0) {
        local_58 = 0;
      }
      else {
        local_58 = 0x200;
      }
      _DAT_004393c4 = _DAT_004393c4 | local_58;
      if (DAT_0043d570 == 0) {
        local_54 = 0;
      }
      else {
        local_54 = 0x1000;
      }
      _DAT_004393c4 = _DAT_004393c4 | local_54;
      if (DAT_0043d574 == 0) {
        local_50 = 0;
      }
      else {
        local_50 = 0x20000;
      }
      _DAT_004393c4 = _DAT_004393c4 | local_50;
      if ((DAT_0043d50c == -1) ||
         (uVar2 = Ordinal_14(*(undefined4 *)(local_18 + 0x18)), param_1 = extraout_ECX_01,
         (uVar2 & 0xf0000000) == 0xe0000000)) {
        local_48 = 0;
      }
      else {
        local_48 = 0x4000;
      }
      _DAT_004393c4 = _DAT_004393c4 | local_48;
      FUN_0042c5c6(param_1,&DAT_00445b40);
      param_1 = extraout_ECX_02;
    }
    FUN_0041017b(param_1,local_18);
  }
  return;
}


