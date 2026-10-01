// 0040691f FUN_0040691f [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_0040691f(undefined4 param_1,undefined4 param_2)

{
  HANDLE in_EAX;
  BOOL BVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  uint extraout_EDX;
  longlong lVar3;
  _INPUT_RECORD local_28;
  DWORD local_14;
  
  if (DAT_00408f34 != 0) {
    if (DAT_00408f34 < 2) {
      DAT_0040b5e8 = DAT_0040b5e8 + -1;
      uVar2 = DAT_0040b5e4;
      if (DAT_0040b5e4 == 0) {
        DAT_00408f34 = 2;
      }
      else if (DAT_0040b5e8 == 0) {
        DAT_00408f34 = 0;
      }
      goto LAB_00406a22;
    }
    if (DAT_00408f34 == 2) {
      DAT_00408f34 = (uint)(DAT_0040b5e8 != 0);
      uVar2 = DAT_0040b5e0;
      goto LAB_00406a22;
    }
  }
  do {
    BVar1 = ReadConsoleInputA(in_EAX,&local_28,1,&local_14);
    if (BVar1 == 0) {
      uVar2 = 0xffffffff;
      goto LAB_00406a22;
    }
    lVar3 = FUN_004066d2(extraout_ECX,extraout_EDX);
  } while ((int)lVar3 == 0);
  DAT_0040b5e8 = local_28.Event.KeyEvent.wRepeatCount - 1;
  uVar2 = (uint)(byte)local_28.Event.MouseEvent.dwControlKeyState._2_1_;
  if (((local_28.Event.KeyEvent.dwControlKeyState._1_1_ & 1) == 0) && (uVar2 != 0)) {
    DAT_0040b5e4 = uVar2;
    if (DAT_0040b5e8 != 0) {
      DAT_00408f34 = 1;
    }
  }
  else {
    DAT_0040b5e0 = (uint)local_28.Event.KeyEvent.wVirtualScanCode;
    DAT_0040b5e4 = 0;
    DAT_00408f34 = 2;
    uVar2 = DAT_0040b5e4;
  }
LAB_00406a22:
  return CONCAT44(param_2,uVar2);
}


