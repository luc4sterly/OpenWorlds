// 0041107f FUN_0041107f [Global]
// programa: sfmain.exe

void __fastcall FUN_0041107f(undefined4 param_1,HDROP param_2)

{
  HWND in_EAX;
  LONG LVar1;
  undefined4 extraout_ECX;
  
  LVar1 = GetWindowLongA(in_EAX,0);
  DragQueryFileA(param_2,0,(LPSTR)(LVar1 + 0x138),0x104);
  DragFinish(param_2);
  FUN_00410ea0(extraout_ECX,(LPCSTR)(LVar1 + 0x138));
  return;
}


