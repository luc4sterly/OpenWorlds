// 10047b30 __hextodec [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __hextodec
   
   Library: Visual Studio 1998 Release */

uint __cdecl __hextodec(uint param_1)

{
  uint uVar1;
  
  if (DAT_1005bb4c < 2) {
    uVar1 = *(ushort *)(PTR_DAT_1005b940 + param_1 * 2) & 4;
  }
  else {
    uVar1 = __isctype(param_1,4);
  }
  if (uVar1 != 0) {
    return param_1;
  }
  return (param_1 & 0xffffffdf) - 7;
}


