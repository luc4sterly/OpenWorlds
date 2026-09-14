// 0040a4d0 FUN_0040a4d0 [Global]
// programa: gamma.dll

HRESULT __cdecl FUN_0040a4d0(int *param_1,undefined4 param_2,LPIID param_3)

{
  LPCSTR lpMultiByteStr;
  int cchWideChar;
  LPWSTR lpWideCharStr;
  HRESULT HVar1;
  LPCOLESTR lpsz;
  
  lpMultiByteStr = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_2,0);
  cchWideChar = MultiByteToWideChar(0,8,lpMultiByteStr,-1,(LPWSTR)0x0,0);
  if (cchWideChar == 0) {
    (**(code **)(*param_1 + 0x2a8))(param_1,param_2,lpMultiByteStr);
    lpsz = (LPCOLESTR)0x0;
  }
  else {
    lpWideCharStr = (LPWSTR)FUN_00450b60(cchWideChar * 2);
    if (lpWideCharStr == (LPWSTR)0x0) {
      FUN_00402800(s_nActiveX_0046e0a4,0x2b);
    }
    MultiByteToWideChar(0,8,lpMultiByteStr,-1,lpWideCharStr,cchWideChar);
    lpsz = (LPCOLESTR)Ordinal_2(lpWideCharStr);
    FUN_00451780((undefined4 *)lpWideCharStr);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_2,lpMultiByteStr);
  }
  if (lpsz == (LPCOLESTR)0x0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
                 s_nActiveX__getIID___couldn_t_allo_0046e0b0);
    return 1;
  }
  HVar1 = IIDFromString(lpsz,param_3);
  Ordinal_6(lpsz);
  if (HVar1 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
                 s_nActiveX__Couldn_t_convert_Strin_0046e0dc);
  }
  return HVar1;
}


