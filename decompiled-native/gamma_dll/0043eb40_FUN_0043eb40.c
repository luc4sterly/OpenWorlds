// 0043eb40 FUN_0043eb40 [Global]
// programa: gamma.dll

undefined4 FUN_0043eb40(int param_1,LPCWSTR param_2)

{
  BOOL BVar1;
  CHAR aCStack_10c [260];
  
  if (param_2 == (LPCWSTR)0x0) {
    return 0x80004003;
  }
  WideCharToMultiByte(0,0,param_2,-1,aCStack_10c,0x104,(LPCSTR)0x0,(LPBOOL)0x0);
  BVar1 = IsWindow(*(HWND *)(param_1 + 0x18));
  if (BVar1 != 0) {
    SendMessageA(*(HWND *)(param_1 + 0x18),0x401,0,(LPARAM)aCStack_10c);
  }
  return 0;
}


