// 100503c0 ___crtGetLocaleInfoA [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    ___crtGetLocaleInfoA
   
   Library: Visual Studio 1998 Release */

int __cdecl
___crtGetLocaleInfoA
          (_locale_t _Plocinfo,LPCWSTR _LocaleName,LCTYPE _LCType,LPSTR _LpLCData,int _CchData)

{
  int iVar1;
  LPWSTR lpLCData;
  
  iVar1 = DAT_1005d9a8;
  if (DAT_1005d9a8 == 0) {
    iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = 1;
    }
    else {
      iVar1 = 2;
    }
  }
  DAT_1005d9a8 = iVar1;
  if (iVar1 == 2) {
    iVar1 = GetLocaleInfoA((LCID)_Plocinfo,(LCTYPE)_LocaleName,(LPSTR)_LCType,(int)_LpLCData);
    return iVar1;
  }
  if (iVar1 == 1) {
    if (_CchData == 0) {
      _CchData = DAT_1005cd08;
    }
    iVar1 = GetLocaleInfoW((LCID)_Plocinfo,(LCTYPE)_LocaleName,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      return 0;
    }
    lpLCData = _malloc(iVar1 * 2);
    if (lpLCData == (LPWSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoW((LCID)_Plocinfo,(LCTYPE)_LocaleName,lpLCData,iVar1);
    if (iVar1 != 0) {
      if (_LpLCData == (LPSTR)0x0) {
        iVar1 = WideCharToMultiByte(_CchData,0x220,lpLCData,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0)
        ;
      }
      else {
        iVar1 = WideCharToMultiByte(_CchData,0x220,lpLCData,-1,(LPSTR)_LCType,(int)_LpLCData,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
      }
      if (iVar1 != 0) {
        _free(lpLCData);
        return iVar1;
      }
    }
    _free(lpLCData);
    iVar1 = 0;
  }
  return iVar1;
}


