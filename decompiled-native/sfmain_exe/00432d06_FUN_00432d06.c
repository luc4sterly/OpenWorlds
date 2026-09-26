// 00432d06 FUN_00432d06 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_00432d06(undefined4 param_1,undefined4 param_2)

{
  HANDLE in_EAX;
  BOOL BVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  uint extraout_EDX;
  longlong lVar3;
  _INPUT_RECORD local_28;
  DWORD local_14;
  
  if (DAT_0043eae0 != 0) {
    if (DAT_0043eae0 < 2) {
      _DAT_004e5938 = _DAT_004e5938 + -1;
      uVar2 = _DAT_004e5934;
      if (_DAT_004e5934 == 0) {
        DAT_0043eae0 = 2;
      }
      else if (_DAT_004e5938 == 0) {
        DAT_0043eae0 = 0;
      }
      goto LAB_00432e09;
    }
    if (DAT_0043eae0 == 2) {
      DAT_0043eae0 = (uint)(_DAT_004e5938 != 0);
      uVar2 = _DAT_004e5930;
      goto LAB_00432e09;
    }
  }
  do {
    BVar1 = ReadConsoleInputA(in_EAX,&local_28,1,&local_14);
    if (BVar1 == 0) {
      uVar2 = 0xffffffff;
      goto LAB_00432e09;
    }
    lVar3 = FUN_004324e9(extraout_ECX,extraout_EDX);
  } while ((int)lVar3 == 0);
  _DAT_004e5938 = local_28.Event.KeyEvent.wRepeatCount - 1;
  uVar2 = (uint)(byte)local_28.Event.MouseEvent.dwControlKeyState._2_1_;
  if (((local_28.Event.KeyEvent.dwControlKeyState._1_1_ & 1) == 0) && (uVar2 != 0)) {
    _DAT_004e5934 = uVar2;
    if (_DAT_004e5938 != 0) {
      DAT_0043eae0 = 1;
    }
  }
  else {
    _DAT_004e5930 = (uint)local_28.Event.KeyEvent.wVirtualScanCode;
    _DAT_004e5934 = 0;
    DAT_0043eae0 = 2;
    uVar2 = _DAT_004e5934;
  }
LAB_00432e09:
  return CONCAT44(param_2,uVar2);
}


