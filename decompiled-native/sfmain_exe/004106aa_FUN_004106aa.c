// 004106aa FUN_004106aa [Global]
// program: sfmain.exe

void __fastcall FUN_004106aa(undefined4 param_1,undefined1 *param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined8 uVar2;
  
  if (*(short *)(in_EAX + 0x4e42) == 0) {
    if ((((DAT_0043d590 == 0) || (DAT_0043d594 != 0)) && (DAT_0043d598 == 0)) &&
       (((iVar1 = FUN_0042984a(), iVar1 < 0 && (DAT_0043d594 == 0)) &&
        (DAT_0043d590 = 1, DAT_0043d634 != (HWND)0x0)))) {
      uVar2 = FUN_00429192(extraout_ECX,extraout_EDX);
      SetDlgItemTextA(DAT_0043d634,0x408,(LPCSTR)uVar2);
    }
    if (DAT_0043d590 != 0) {
      FUN_00429725();
    }
  }
  else {
    FUN_00421bcd((undefined1 *)(in_EAX + 0x674),param_2);
  }
  return;
}


