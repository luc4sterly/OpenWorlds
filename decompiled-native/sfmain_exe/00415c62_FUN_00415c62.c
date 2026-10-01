// 00415c62 FUN_00415c62 [Global]
// program: sfmain.exe

void __fastcall FUN_00415c62(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  HWND pHVar1;
  int iVar2;
  undefined4 local_20;
  
  iVar2 = param_2;
  pHVar1 = GetDlgItem(in_EAX,0xc1d);
  EnableWindow(pHVar1,iVar2);
  iVar2 = param_2;
  pHVar1 = GetDlgItem(in_EAX,0x3f7);
  EnableWindow(pHVar1,iVar2);
  iVar2 = param_2;
  pHVar1 = GetDlgItem(in_EAX,1);
  EnableWindow(pHVar1,iVar2);
  if (param_2 == 0) {
    local_20 = 2;
  }
  else {
    local_20 = 0xc1d;
  }
  pHVar1 = GetDlgItem(in_EAX,local_20);
  SetFocus(pHVar1);
  return;
}


