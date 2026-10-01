// 100482e0 __getstream [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __getstream
   
   Library: Visual Studio 1998 Release */

FILE * __cdecl __getstream(void)

{
  void *pvVar1;
  int iVar2;
  int _Index;
  FILE *pFVar3;
  
  _Index = 0;
  pFVar3 = (FILE *)0x0;
  __lock(2);
  if (0 < DAT_1005f6c0) {
    iVar2 = 0;
    do {
      pvVar1 = *(void **)(DAT_1005e6bc + iVar2);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = _malloc(0x38);
        *(void **)(DAT_1005e6bc + _Index * 4) = pvVar1;
        iVar2 = *(int *)(DAT_1005e6bc + _Index * 4);
        if (iVar2 != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(DAT_1005e6bc + _Index * 4) + 0x20));
          pFVar3 = *(FILE **)(DAT_1005e6bc + _Index * 4);
        }
        break;
      }
      if ((*(uint *)((int)pvVar1 + 0xc) & 0x83) == 0) {
        FID_conflict___lock_file2(_Index,pvVar1);
        if ((*(uint *)((int)*(void **)(DAT_1005e6bc + iVar2) + 0xc) & 0x83) == 0) {
          pFVar3 = *(FILE **)(DAT_1005e6bc + _Index * 4);
          break;
        }
        FID_conflict___lock_file2(_Index,*(void **)(DAT_1005e6bc + iVar2));
      }
      iVar2 = iVar2 + 4;
      _Index = _Index + 1;
    } while (_Index < DAT_1005f6c0);
  }
  if (pFVar3 != (FILE *)0x0) {
    pFVar3->_cnt = 0;
    pFVar3->_flag = 0;
    pFVar3->_base = (char *)0x0;
    pFVar3->_ptr = (char *)0x0;
    pFVar3->_tmpfname = (char *)0x0;
    pFVar3->_file = -1;
  }
  FUN_10047d00(2);
  return pFVar3;
}


