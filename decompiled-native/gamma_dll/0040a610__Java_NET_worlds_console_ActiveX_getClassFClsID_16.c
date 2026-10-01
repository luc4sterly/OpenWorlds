// 0040a610 _Java_NET_worlds_console_ActiveX_getClassFClsID@16 [Global]
// program: gamma.dll

LPUNKNOWN _Java_NET_worlds_console_ActiveX_getClassFClsID_16
                    (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  LPCSTR lpMultiByteStr;
  int cchWideChar;
  LPWSTR lpWideCharStr;
  HRESULT HVar1;
  LPUNKNOWN pIVar2;
  LPCOLESTR lpsz;
  CLSID local_20;
  
                    /* 0xa610  14  _Java_NET_worlds_console_ActiveX_getClassFClsID@16 */
  lpMultiByteStr = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  cchWideChar = MultiByteToWideChar(0,8,lpMultiByteStr,-1,(LPWSTR)0x0,0);
  if (cchWideChar == 0) {
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpMultiByteStr);
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
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpMultiByteStr);
  }
  if (lpsz == (LPCOLESTR)0x0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
                 s_nActiveX_getClassFClsID__Couldn__0046e134);
    return (LPUNKNOWN)0x0;
  }
  HVar1 = CLSIDFromString(lpsz,&local_20);
  Ordinal_6(lpsz);
  if (HVar1 == 0) {
    pIVar2 = _Java_NET_worlds_console_ActiveX_getClass_16(param_1,0,&local_20.Data1,param_4);
    return pIVar2;
  }
  FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
               s_nActiveX_getClassFClsID__Couldn__0046e168);
  return (LPUNKNOWN)0x0;
}


