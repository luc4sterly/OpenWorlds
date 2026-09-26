// 00423f69 FUN_00423f69 [Global]
// programa: sfmain.exe

void __fastcall FUN_00423f69(undefined4 param_1,undefined4 param_2)

{
  MSG *in_EAX;
  BOOL BVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar3;
  
  if ((((DAT_0043d634 == (HWND)0x0) ||
       (BVar1 = IsDialogMessageA(DAT_0043d634,in_EAX), param_1 = extraout_ECX,
       param_2 = extraout_EDX, BVar1 == 0)) &&
      ((DAT_0043d640 == (HWND)0x0 ||
       (BVar1 = IsDialogMessageA(DAT_0043d640,in_EAX), param_1 = extraout_ECX_00,
       param_2 = extraout_EDX_00, BVar1 == 0)))) &&
     (((uVar3 = FUN_004167f3(param_1,param_2), (int)uVar3 == 0 &&
       (BVar1 = TranslateMDISysAccel(DAT_004627c8,in_EAX), BVar1 == 0)) &&
      (iVar2 = TranslateAcceleratorA(DAT_004627d0,DAT_004627cc,in_EAX), iVar2 == 0)))) {
    TranslateMessage(in_EAX);
    DispatchMessageA(in_EAX);
  }
  return;
}


