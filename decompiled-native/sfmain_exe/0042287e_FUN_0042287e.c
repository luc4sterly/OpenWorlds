// 0042287e FUN_0042287e [Global]
// program: sfmain.exe

void __fastcall FUN_0042287e(undefined4 param_1,BOOL param_2)

{
  HWND in_EAX;
  HWND pHVar1;
  BOOL BVar2;
  
  BVar2 = param_2;
  pHVar1 = GetDlgItem(in_EAX,0x413);
  EnableWindow(pHVar1,BVar2);
  BVar2 = param_2;
  pHVar1 = GetDlgItem(in_EAX,0x414);
  EnableWindow(pHVar1,BVar2);
  BVar2 = param_2;
  pHVar1 = GetDlgItem(in_EAX,4);
  EnableWindow(pHVar1,BVar2);
  pHVar1 = GetDlgItem(in_EAX,1);
  EnableWindow(pHVar1,param_2);
  return;
}


