// 1004be50 _isspace [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _isspace
   
   Library: Visual Studio 1998 Release */

int __cdecl _isspace(int _C)

{
  int iVar1;
  
  if (1 < DAT_1005bb4c) {
    iVar1 = __isctype(_C,8);
    return iVar1;
  }
  return *(ushort *)(PTR_DAT_1005b940 + _C * 2) & 8;
}


