// 004144eb FUN_004144eb [Global]
// programa: sfmain.exe

undefined4 __fastcall
FUN_004144eb(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,short param_5)

{
  ULONG_PTR dwData;
  undefined4 extraout_ECX;
  undefined8 uVar1;
  UINT uCommand;
  
  if ((((0x10f < param_4) && (0x110 < param_4)) && (param_4 == 0x111)) && (-4 < param_5)) {
    if (param_5 < -2) {
      uVar1 = FUN_00429192(param_1,param_2);
      dwData = (ULONG_PTR)uVar1;
      uCommand = 0x101;
      uVar1 = FUN_00429192(extraout_ECX,(int)((ulonglong)uVar1 >> 0x20));
      WinHelpA(DAT_004627d0,(LPCSTR)uVar1,uCommand,dwData);
      DAT_0043d608 = 1;
    }
    else if (param_5 == 1) {
      EndDialog(param_3,1);
    }
  }
  return 0;
}


