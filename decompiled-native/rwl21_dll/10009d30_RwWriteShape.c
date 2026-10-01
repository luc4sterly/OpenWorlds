// 10009d30 RwWriteShape [Global]
// program: RWL21.DLL

undefined4 RwWriteShape(char *param_1,int param_2)

{
  FILE *_File;
  int iVar1;
  
                    /* 0x9d30  526  RwWriteShape */
  if ((param_2 == 0) || (param_1 == (char *)0x0)) {
    FUN_1000cba0(1);
    return 0;
  }
  _File = FID_conflict___wfopen(param_1,&DAT_1005a08c);
  if (_File == (FILE *)0x0) {
    FUN_1000cba0(0xe);
    return 0;
  }
  iVar1 = FUN_100340b0(param_2,_File);
  if (iVar1 != 0) {
    iVar1 = _fclose(_File);
    if (iVar1 != -1) {
      return 1;
    }
    FUN_1000cba0(0xc);
    return 0;
  }
  return 0;
}


