// 0040a420 FUN_0040a420 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_0040a420(int *param_1,undefined4 param_2)

{
  LPCSTR lpMultiByteStr;
  int cchWideChar;
  LPWSTR lpWideCharStr;
  undefined4 uVar1;
  
  lpMultiByteStr = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_2,0);
  cchWideChar = MultiByteToWideChar(0,8,lpMultiByteStr,-1,(LPWSTR)0x0,0);
  if (cchWideChar == 0) {
    (**(code **)(*param_1 + 0x2a8))(param_1,param_2,lpMultiByteStr);
    return 0;
  }
  lpWideCharStr = (LPWSTR)FUN_00450b60(cchWideChar * 2);
  if (lpWideCharStr == (LPWSTR)0x0) {
    FUN_00402800(s_nActiveX_0046e0a4,0x2b);
  }
  MultiByteToWideChar(0,8,lpMultiByteStr,-1,lpWideCharStr,cchWideChar);
  uVar1 = Ordinal_2(lpWideCharStr);
  FUN_00451780((undefined4 *)lpWideCharStr);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_2,lpMultiByteStr);
  return uVar1;
}


