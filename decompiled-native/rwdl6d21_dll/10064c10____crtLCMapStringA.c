// 10064c10 ___crtLCMapStringA [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 1998 Release */

int __cdecl
___crtLCMapStringA(_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwMapFlag,LPCSTR _LpSrcStr,
                  int _CchSrc,LPSTR _LpDestStr,int _CchDest,int _Code_page,BOOL _BError)

{
  int iVar1;
  LPCWSTR lpWideCharStr;
  int iVar2;
  LPCWSTR lpDestStr;
  
  if (DAT_1007a8c0 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_1007a8c0 = 1;
    }
    else {
      DAT_1007a8c0 = 2;
    }
  }
  if (0 < (int)_LpSrcStr) {
    _LpSrcStr = (LPCSTR)_strncnt((char *)_DwMapFlag,(size_t)_LpSrcStr);
  }
  if (DAT_1007a8c0 == 2) {
    iVar1 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                         (LPSTR)_CchSrc,(int)_LpDestStr);
    return iVar1;
  }
  if (DAT_1007a8c0 != 1) {
    return DAT_1007a8c0;
  }
  lpDestStr = (LPCWSTR)0x0;
  if (_CchDest == 0) {
    _CchDest = DAT_1007a720;
  }
  iVar1 = MultiByteToWideChar(_CchDest,9,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return 0;
  }
  lpWideCharStr = _malloc(iVar1 * 2);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  iVar2 = MultiByteToWideChar(_CchDest,1,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,lpWideCharStr,iVar1);
  if ((iVar2 != 0) &&
     (iVar2 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)0x0,0),
     iVar2 != 0)) {
    if (((uint)_LocaleName & 0x400) == 0) {
      lpDestStr = _malloc(iVar2 * 2);
      if ((lpDestStr == (LPCWSTR)0x0) ||
         (iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,lpDestStr,
                               iVar2), iVar1 == 0)) goto LAB_10064d8b;
      if (_LpDestStr == (LPSTR)0x0) {
        iVar2 = WideCharToMultiByte(_CchDest,0x220,lpDestStr,iVar2,(LPSTR)0x0,0,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        iVar1 = iVar2;
      }
      else {
        iVar2 = WideCharToMultiByte(_CchDest,0x220,lpDestStr,iVar2,(LPSTR)_CchSrc,(int)_LpDestStr,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        iVar1 = iVar2;
      }
    }
    else {
      if (_LpDestStr == (LPSTR)0x0) goto LAB_10064e22;
      if ((int)_LpDestStr < iVar2) goto LAB_10064d8b;
      iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)_CchSrc,
                           (int)_LpDestStr);
    }
    if (iVar1 != 0) {
LAB_10064e22:
      _free(lpWideCharStr);
      _free(lpDestStr);
      return iVar2;
    }
  }
LAB_10064d8b:
  _free(lpWideCharStr);
  _free(lpDestStr);
  return 0;
}


