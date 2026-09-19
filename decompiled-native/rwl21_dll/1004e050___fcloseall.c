// 1004e050 __fcloseall [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __fcloseall
   
   Library: Visual Studio 1998 Release */

int __cdecl __fcloseall(void)

{
  FILE *_File;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 3;
  __lock(2);
  if (3 < DAT_1005f6c0) {
    iVar4 = 0xc;
    do {
      _File = *(FILE **)(DAT_1005e6bc + iVar4);
      if (_File != (FILE *)0x0) {
        if ((_File->_flag & 0x83) != 0) {
          iVar1 = _fclose(_File);
          if (iVar1 != -1) {
            iVar2 = iVar2 + 1;
          }
        }
        if (0x4f < iVar4) {
          DeleteCriticalSection((LPCRITICAL_SECTION)(*(int *)(DAT_1005e6bc + iVar4) + 0x20));
          _free(*(void **)(DAT_1005e6bc + iVar4));
          *(undefined4 *)(DAT_1005e6bc + iVar4) = 0;
        }
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_1005f6c0);
  }
  FUN_10047d00(2);
  return iVar2;
}


