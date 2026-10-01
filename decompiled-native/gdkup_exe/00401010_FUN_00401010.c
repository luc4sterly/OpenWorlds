// 00401010 FUN_00401010 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00401010(undefined4 param_1,undefined4 param_2)

{
  LPCSTR in_EAX;
  int cchWideChar;
  LPWSTR lpWideCharStr;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined8 uVar1;
  undefined4 local_2c;
  
  cchWideChar = MultiByteToWideChar(0,8,in_EAX,-1,(LPWSTR)0x0,0);
  if (cchWideChar == 0) {
    local_2c = 0;
  }
  else {
    uVar1 = thunk_FUN_004026f4(extraout_ECX,extraout_EDX);
    lpWideCharStr = (LPWSTR)uVar1;
    if (lpWideCharStr == (LPWSTR)0x0) {
      local_2c = 0;
    }
    else {
      MultiByteToWideChar(0,8,in_EAX,-1,lpWideCharStr,cchWideChar);
      local_2c = Ordinal_2(lpWideCharStr);
      thunk_FUN_004026bc();
    }
  }
  return CONCAT44(param_2,local_2c);
}


