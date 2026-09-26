// 1002ee30 flsall [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 1998 Release */

int __cdecl flsall(int param_1)

{
  void *_File;
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int _Index;
  int local_4;
  
  iVar3 = 0;
  _Index = 0;
  local_4 = 0;
  __lock(2);
  if (0 < DAT_10043450) {
    iVar4 = 0;
    do {
      _File = *(void **)(DAT_10042448 + iVar4);
      if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
        FID_conflict___lock_file2(_Index,_File);
        pFVar1 = *(FILE **)(DAT_10042448 + iVar4);
        if ((pFVar1->_flag & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = __fflush_lk(pFVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if (((param_1 == 0) && ((pFVar1->_flag & 2U) != 0)) &&
                  (iVar2 = __fflush_lk(pFVar1), iVar2 == -1)) {
            local_4 = -1;
          }
        }
        FID_conflict___lock_file2(_Index,*(void **)(DAT_10042448 + iVar4));
      }
      iVar4 = iVar4 + 4;
      _Index = _Index + 1;
    } while (_Index < DAT_10043450);
  }
  FUN_1002deb0(2);
  if (param_1 != 1) {
    iVar3 = local_4;
  }
  return iVar3;
}


