// 0042b0bf FUN_0042b0bf [Global]
// program: sfmain.exe

void __fastcall FUN_0042b0bf(undefined4 param_1,WPARAM param_2)

{
  undefined4 *in_EAX;
  LPARAM unaff_EBX;
  
  if (in_EAX != (undefined4 *)0x0) {
    SendMessageA((HWND)*in_EAX,in_EAX[2],param_2,unaff_EBX);
  }
  return;
}


