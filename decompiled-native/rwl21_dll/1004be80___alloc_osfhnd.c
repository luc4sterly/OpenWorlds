// 1004be80 __alloc_osfhnd [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __alloc_osfhnd
   
   Library: Visual Studio 1998 Release */

int __cdecl __alloc_osfhnd(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int _Filehandle;
  int *piVar3;
  int iVar4;
  int local_4;
  
  _Filehandle = -1;
  iVar4 = 0;
  piVar3 = &DAT_1005f6d0;
  __lock(0x12);
  local_4 = 0;
  do {
    puVar1 = (undefined4 *)*piVar3;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = _malloc(0x480);
      if (puVar1 != (undefined4 *)0x0) {
        DAT_1005f7d0 = DAT_1005f7d0 + 0x20;
        (&DAT_1005f6d0)[local_4] = puVar1;
        if (puVar1 < puVar1 + 0x120) {
          do {
            *(undefined1 *)(puVar1 + 1) = 0;
            puVar2 = puVar1 + 9;
            *puVar1 = 0xffffffff;
            *(undefined1 *)((int)puVar1 + 5) = 10;
            puVar1[2] = 0;
            puVar1 = puVar2;
          } while (puVar2 < (undefined4 *)((&DAT_1005f6d0)[local_4] + 0x480));
        }
        _Filehandle = local_4 << 5;
        __lock_fhandle(_Filehandle);
      }
      break;
    }
    if (puVar1 < puVar1 + 0x120) {
      do {
        if ((*(byte *)(puVar1 + 1) & 1) == 0) {
          if (puVar1[2] == 0) {
            __lock(0x11);
            if (puVar1[2] == 0) {
              InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
              puVar1[2] = puVar1[2] + 1;
            }
            FUN_10047d00(0x11);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
          if ((*(byte *)(puVar1 + 1) & 1) == 0) {
            *puVar1 = 0xffffffff;
            _Filehandle = iVar4 + ((int)puVar1 - *piVar3) / 0x24;
            break;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
        }
        puVar1 = puVar1 + 9;
      } while (puVar1 < (undefined4 *)(*piVar3 + 0x480));
    }
    if (_Filehandle != -1) break;
    iVar4 = iVar4 + 0x20;
    piVar3 = piVar3 + 1;
    local_4 = local_4 + 1;
  } while (piVar3 < &DAT_1005f7d0);
  FUN_10047d00(0x12);
  return _Filehandle;
}


