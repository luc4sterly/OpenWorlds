// 1004bce0 _mbtowc [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _mbtowc
   
   Library: Visual Studio 1998 Release */

int __cdecl _mbtowc(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = DAT_1005e6b4 == 0;
  if (bVar2) {
    _DAT_1005e6b8 = _DAT_1005e6b8 + 1;
  }
  else {
    __lock(0x13);
  }
  uVar1 = __mbtowc_lk(_DstCh,(byte *)_SrcCh,_SrcSizeInBytes);
  if (!bVar2) {
    FUN_10047d00(0x13);
    return uVar1;
  }
  _DAT_1005e6b8 = _DAT_1005e6b8 + -1;
  return uVar1;
}


