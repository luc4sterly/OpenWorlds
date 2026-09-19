// 10049640 ___wtomb_environ [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    ___wtomb_environ
   
   Library: Visual Studio 1998 Release */

int __cdecl ___wtomb_environ(void)

{
  size_t _Size;
  char **_POption;
  int iVar1;
  int *piVar2;
  
  iVar1 = *DAT_1005bec0;
  piVar2 = DAT_1005bec0;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,(LPCWSTR)*piVar2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (_Size == 0) {
      return -1;
    }
    _POption = _malloc(_Size);
    if (_POption == (char **)0x0) {
      return -1;
    }
    iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*piVar2,-1,(LPSTR)_POption,_Size,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar1 == 0) break;
    piVar2 = piVar2 + 1;
    ___crtsetenv(_POption,0);
    iVar1 = *piVar2;
  }
  return -1;
}


