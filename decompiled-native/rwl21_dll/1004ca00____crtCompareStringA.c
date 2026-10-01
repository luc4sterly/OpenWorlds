// 1004ca00 ___crtCompareStringA [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    ___crtCompareStringA
   
   Library: Visual Studio 1998 Release */

int __cdecl
___crtCompareStringA
          (_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwCmpFlags,LPCSTR _LpString1,
          int _CchCount1,LPCSTR _LpString2,int _CchCount2,int _Code_page)

{
  LPCSTR in_EAX;
  int iVar1;
  BOOL BVar2;
  BYTE *pBVar3;
  PCNZWCH lpWideCharStr;
  int iVar4;
  LPWSTR local_20;
  LPCSTR local_18;
  _cpinfo local_14;
  
  if (DAT_1005cd10 == 0) {
    in_EAX = (LPCSTR)CompareStringA(0,0,"",1,"",1);
    if (in_EAX == (LPCSTR)0x0) {
      in_EAX = (LPCSTR)CompareStringW(0,0,L"",1,L"",1);
      if (in_EAX == (LPCSTR)0x0) {
        return 0;
      }
      DAT_1005cd10 = 1;
    }
    else {
      DAT_1005cd10 = 2;
    }
  }
  local_18 = in_EAX;
  if (0 < (int)_LpString1) {
    local_18 = (LPCSTR)_strncnt((char *)_DwCmpFlags,(size_t)_LpString1);
    _LpString1 = local_18;
  }
  if (0 < (int)_LpString2) {
    local_18 = (LPCSTR)_strncnt((char *)_CchCount1,(size_t)_LpString2);
    _LpString2 = local_18;
  }
  if (DAT_1005cd10 == 2) {
    iVar1 = CompareStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(PCNZCH)_DwCmpFlags,(int)_LpString1,
                           (PCNZCH)_CchCount1,(int)_LpString2);
    return iVar1;
  }
  if (DAT_1005cd10 == 1) {
    local_18 = (LPCSTR)0x0;
    local_20 = (LPWSTR)0x0;
    if (_CchCount2 == 0) {
      _CchCount2 = DAT_1005cd08;
    }
    if ((_LpString1 == (LPCSTR)0x0) || (_LpString2 == (LPCSTR)0x0)) {
      if (_LpString1 == _LpString2) {
        return 2;
      }
      if (1 < (int)_LpString2) {
        return 1;
      }
      if (1 < (int)_LpString1) {
        return 3;
      }
      BVar2 = GetCPInfo(_CchCount2,&local_14);
      if (BVar2 == 0) {
        return 0;
      }
      if (0 < (int)_LpString1) {
        if (local_14.MaxCharSize < 2) {
          return 3;
        }
        pBVar3 = local_14.LeadByte;
        while( true ) {
          if ((local_14.LeadByte[0] == 0) || (pBVar3[1] == 0)) {
            return 3;
          }
          if ((*pBVar3 <= *(byte *)_DwCmpFlags) && (*(byte *)_DwCmpFlags <= pBVar3[1])) break;
          pBVar3 = pBVar3 + 2;
          local_14.LeadByte[0] = *pBVar3;
        }
        return 2;
      }
      if (0 < (int)_LpString2) {
        if (local_14.MaxCharSize < 2) {
          return 1;
        }
        pBVar3 = local_14.LeadByte;
        while( true ) {
          if ((local_14.LeadByte[0] == 0) || (pBVar3[1] == 0)) {
            return 1;
          }
          if ((*pBVar3 <= *(byte *)_CchCount1) && (*(byte *)_CchCount1 <= pBVar3[1])) break;
          pBVar3 = pBVar3 + 2;
          local_14.LeadByte[0] = *pBVar3;
        }
        return 2;
      }
    }
    local_14.MaxCharSize =
         MultiByteToWideChar(_CchCount2,9,(LPCSTR)_DwCmpFlags,(int)_LpString1,(LPWSTR)0x0,0);
    if (local_14.MaxCharSize == 0) {
      return 0;
    }
    lpWideCharStr = _malloc(local_14.MaxCharSize * 2);
    if (lpWideCharStr == (PCNZWCH)0x0) {
      return 0;
    }
    iVar1 = MultiByteToWideChar(_CchCount2,1,(LPCSTR)_DwCmpFlags,(int)_LpString1,lpWideCharStr,
                                local_14.MaxCharSize);
    if ((((iVar1 != 0) &&
         (iVar1 = MultiByteToWideChar(_CchCount2,9,(LPCSTR)_CchCount1,(int)_LpString2,(LPWSTR)0x0,0)
         , iVar1 != 0)) && (local_20 = _malloc(iVar1 * 2), local_20 != (LPWSTR)0x0)) &&
       (iVar4 = MultiByteToWideChar(_CchCount2,1,(LPCSTR)_CchCount1,(int)_LpString2,local_20,iVar1),
       iVar4 != 0)) {
      local_18 = (LPCSTR)CompareStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,
                                        local_14.MaxCharSize,local_20,iVar1);
    }
    _free(lpWideCharStr);
    _free(local_20);
  }
  return (int)local_18;
}


