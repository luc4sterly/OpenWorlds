// 00453de0 FUN_00453de0 [Global]
// programa: gamma.dll

BOOL __cdecl FUN_00453de0(uint param_1)

{
  LPVOID pvVar1;
  DWORD DVar2;
  uint *lpTlsValue;
  BOOL BVar3;
  
  pvVar1 = TlsGetValue(DAT_00482370);
  if (pvVar1 != (LPVOID)0x0) {
    return 1;
  }
  DVar2 = GetLastError();
  if (DVar2 == 0) {
    lpTlsValue = FUN_00454a10(600);
    if (lpTlsValue == (uint *)0x0) {
      return 0;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049eea0);
    *lpTlsValue = (uint)DAT_0049e758;
    DAT_0049e758 = lpTlsValue;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049eea0);
    lpTlsValue[1] = 0;
    lpTlsValue[2] = 1;
    lpTlsValue[3] = (uint)&DAT_00482374;
    lpTlsValue[4] = (uint)&DAT_00482374;
    lpTlsValue[5] = param_1;
    BVar3 = TlsSetValue(DAT_00482370,lpTlsValue);
    return BVar3;
  }
  return 0;
}


