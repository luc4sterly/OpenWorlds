// 10043cb0 FUN_10043cb0 [Global]
// programa: RWL21.DLL

undefined4 FUN_10043cb0(LPCSTR param_1,int param_2)

{
  int iVar1;
  int iVar2;
  FILE *pFVar3;
  
  iVar1 = FUN_100459d0(param_1,0);
  iVar2 = FUN_100459d0(param_1,2);
  if (param_2 == 1) {
    if (iVar1 == 0) {
      pFVar3 = FID_conflict___wfopen(param_1,&DAT_1005ad0c);
      if (pFVar3 != (FILE *)0x0) {
        _fclose(pFVar3);
        return 0;
      }
    }
  }
  else if (((param_2 == 2) && (iVar1 == 0)) && (iVar2 != -1)) {
    pFVar3 = FID_conflict___wfopen(param_1,&DAT_1005b78c);
    if (pFVar3 != (FILE *)0x0) {
      _fclose(pFVar3);
      return 0;
    }
  }
  return 1;
}


