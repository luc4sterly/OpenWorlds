// 1005dfe0 ___crtGetStringTypeW [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    ___crtGetStringTypeW
   
   Library: Visual Studio 1998 Release */

BOOL __cdecl
___crtGetStringTypeW
          (DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  LPWORD pWVar1;
  BOOL in_EAX;
  BOOL BVar2;
  size_t _Size;
  LPCSTR lpMultiByteStr;
  int iVar3;
  LPWORD lpCharType;
  BOOL local_4;
  
  local_4 = in_EAX;
  if (DAT_10076744 == 0) {
    local_4 = GetStringTypeW(1,L"",1,(LPWORD)&local_4);
    if (local_4 == 0) {
      local_4 = GetStringTypeA(0,1,"",1,(LPWORD)&local_4);
      if (local_4 == 0) {
        return 0;
      }
      DAT_10076744 = 2;
    }
    else {
      DAT_10076744 = 1;
    }
  }
  if (DAT_10076744 != 1) {
    if (DAT_10076744 == 2) {
      lpCharType = (LPWORD)0x0;
      local_4 = 0;
      if (param_5 == 0) {
        param_5 = DAT_10076720;
      }
      _Size = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                 );
      if (_Size == 0) {
        return 0;
      }
      lpMultiByteStr = _calloc(1,_Size);
      if (lpMultiByteStr == (LPCSTR)0x0) {
        return 0;
      }
      iVar3 = WideCharToMultiByte(param_5,0x220,param_2,param_3,lpMultiByteStr,_Size,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      if ((iVar3 != 0) && (lpCharType = _malloc(_Size * 2 + 2), lpCharType != (LPWORD)0x0)) {
        if (param_6 == 0) {
          param_6 = DAT_10076710;
        }
        pWVar1 = lpCharType + param_3;
        *pWVar1 = 0xffff;
        pWVar1[-1] = 0xffff;
        local_4 = GetStringTypeA(param_6,param_1,lpMultiByteStr,_Size,lpCharType);
        if ((pWVar1[-1] == 0xffff) || (*pWVar1 != 0xffff)) {
          local_4 = 0;
        }
        else {
          FID_conflict__memcpy(param_4,lpCharType,param_3 * 2);
        }
      }
      _free(lpMultiByteStr);
      _free(lpCharType);
    }
    return local_4;
  }
  BVar2 = GetStringTypeW(param_1,param_2,param_3,param_4);
  return BVar2;
}


