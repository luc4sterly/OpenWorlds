// 00403946 FUN_00403946 [Global]
// program: run.exe

undefined4 FUN_00403946(void)

{
  LPCSTR lpMultiByteStr;
  int iVar1;
  PCNZWCH lpWideCharStr;
  undefined4 *puVar2;
  
  lpMultiByteStr = (LPCSTR)*DAT_0040ba60;
  puVar2 = DAT_0040ba60;
  while( true ) {
    if (lpMultiByteStr == (LPCSTR)0x0) {
      return 0;
    }
    iVar1 = MultiByteToWideChar(1,0,lpMultiByteStr,-1,(LPWSTR)0x0,0);
    if (((iVar1 == 0) || (lpWideCharStr = _malloc(iVar1 * 2), lpWideCharStr == (PCNZWCH)0x0)) ||
       (iVar1 = MultiByteToWideChar(1,0,(LPCSTR)*puVar2,-1,lpWideCharStr,iVar1), iVar1 == 0)) break;
    FUN_00401452(lpWideCharStr,0);
    lpMultiByteStr = (LPCSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}


