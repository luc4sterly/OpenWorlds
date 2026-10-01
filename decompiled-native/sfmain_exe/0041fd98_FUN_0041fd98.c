// 0041fd98 FUN_0041fd98 [Global]
// program: sfmain.exe

void __fastcall FUN_0041fd98(undefined4 param_1)

{
  LPWAVEHDR in_EAX;
  HGLOBAL pvVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined8 uVar2;
  
  FUN_0041757d(param_1,in_EAX);
  if (in_EAX->lpData != (LPSTR)0x0) {
    pvVar1 = GlobalHandle(in_EAX->lpData);
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(in_EAX->lpData);
    GlobalFree(pvVar1);
  }
  pvVar1 = GlobalHandle(in_EAX);
  GlobalUnlock(pvVar1);
  pvVar1 = GlobalHandle(in_EAX);
  GlobalFree(pvVar1);
  DAT_0043d67c = DAT_0043d67c + -1;
  if (DAT_0043d67c == 0) {
    uVar2 = FUN_00417664(extraout_ECX,extraout_EDX);
    DAT_0043d514 = 0;
    DAT_0043d520 = 0;
    FUN_004152eb(extraout_ECX_00,(int)((ulonglong)uVar2 >> 0x20));
  }
  return;
}


