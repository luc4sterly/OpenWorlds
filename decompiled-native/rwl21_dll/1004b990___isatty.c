// 1004b990 __isatty [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 1998 Release */

int __cdecl __isatty(int _FileHandle)

{
  if (DAT_1005f7d0 <= (uint)_FileHandle) {
    return 0;
  }
  return *(byte *)(*(int *)((int)&DAT_1005f6d0 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                  (_FileHandle & 0x1fU) * 0x24) & 0x40;
}


