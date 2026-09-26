// 00403a63 FUN_00403a63 [Global]
// programa: run.exe

undefined4 FUN_00403a63(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  uint *lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;
  
  lpWideCharStr = (LPCWSTR)*DAT_0040ba68;
  puVar2 = DAT_0040ba68;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (uint *)0x0)) ||
       (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*puVar2,-1,(LPSTR)lpMultiByteStr,_Size,(LPCSTR)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_004017aa(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}


