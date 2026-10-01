// 10050290 ___crtGetLocaleInfoW [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    ___crtGetLocaleInfoW
   
   Library: Visual Studio 1998 Release */

int __cdecl
___crtGetLocaleInfoW(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  size_t _Size;
  LPSTR lpLCData;
  
  iVar1 = DAT_1005d9a4;
  if (DAT_1005d9a4 == 0) {
    iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = 2;
    }
    else {
      iVar1 = 1;
    }
  }
  DAT_1005d9a4 = iVar1;
  if (iVar1 == 1) {
    iVar1 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (iVar1 == 2) {
    if (param_5 == 0) {
      param_5 = DAT_1005cd08;
    }
    _Size = GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
    if (_Size == 0) {
      return 0;
    }
    lpLCData = _malloc(_Size);
    if (lpLCData == (LPSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoA(param_1,param_2,lpLCData,_Size);
    if (iVar1 != 0) {
      if (param_4 == 0) {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,(LPWSTR)0x0,0);
      }
      else {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,param_3,param_4);
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


