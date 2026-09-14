// 0040a850 _Java_NET_worlds_console_ActiveX_getClass@16 [Global]
// programa: gamma.dll

LPUNKNOWN _Java_NET_worlds_console_ActiveX_getClass_16
                    (int *param_1,undefined4 param_2,ulong *param_3,undefined4 param_4)

{
  LPCSTR lpMultiByteStr;
  int cchWideChar;
  LPWSTR lpWideCharStr;
  LPCOLESTR lpsz;
  HRESULT HVar1;
  IID local_34;
  IID local_24;
  LPUNKNOWN local_14;
  
                    /* 0xa850  13  _Java_NET_worlds_console_ActiveX_getClass@16 */
  local_34.Data1 = *param_3;
  local_34._4_4_ = param_3[1];
  local_34.Data4._0_4_ = param_3[2];
  local_34.Data4._4_4_ = param_3[3];
  lpMultiByteStr = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  cchWideChar = MultiByteToWideChar(0,8,lpMultiByteStr,-1,(LPWSTR)0x0,0);
  if (cchWideChar == 0) {
    (**(code **)(*param_1 + 0x2a8))(param_1,param_4,lpMultiByteStr);
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
    (**(code **)(*param_1 + 0x2a8))(param_1,param_4,lpMultiByteStr);
  }
  if (lpsz == (LPCOLESTR)0x0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
                 s_nActiveX__getIID___couldn_t_allo_0046e0b0);
    HVar1 = 1;
  }
  else {
    HVar1 = IIDFromString(lpsz,&local_24);
    Ordinal_6(lpsz);
    if (HVar1 != 0) {
      FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
                   s_nActiveX__Couldn_t_convert_Strin_0046e0dc);
    }
  }
  if (HVar1 != 0) {
    return (LPUNKNOWN)0x0;
  }
  HVar1 = CoCreateInstance(&local_34,(LPUNKNOWN)0x0,7,&local_24,&local_14);
  if (HVar1 < 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
                 s_nActiveX_getClass__Requested_int_0046e214);
    return (LPUNKNOWN)0x0;
  }
  HVar1 = OleRun(local_14);
  if (HVar1 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
                 s_nActive_getClass__Unable_to_plac_0046e24c);
    return (LPUNKNOWN)0x0;
  }
  return local_14;
}


