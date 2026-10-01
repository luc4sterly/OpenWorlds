// 004011a4 FUN_004011a4 [Global]
// program: run.exe

undefined4 __cdecl FUN_004011a4(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;
  int iVar3;
  PCNZWCH lpWideCharStr;
  
  if (DAT_0040cf84 != 0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = _malloc(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      FUN_004019f0(puVar2,param_1);
      iVar3 = FUN_004017aa(puVar2,1);
      if ((iVar3 == 0) &&
         ((DAT_0040ba68 == 0 ||
          ((((iVar3 = MultiByteToWideChar(1,0,(LPCSTR)param_1,-1,(LPWSTR)0x0,0), iVar3 != 0 &&
             (lpWideCharStr = _malloc(iVar3 * 2), lpWideCharStr != (PCNZWCH)0x0)) &&
            (iVar3 = MultiByteToWideChar(1,0,(LPCSTR)param_1,-1,lpWideCharStr,iVar3), iVar3 != 0))
           && (iVar3 = FUN_00401452(lpWideCharStr,0), iVar3 == 0)))))) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}


