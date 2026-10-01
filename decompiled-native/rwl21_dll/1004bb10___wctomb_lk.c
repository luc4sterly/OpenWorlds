// 1004bb10 __wctomb_lk [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __wctomb_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __wctomb_lk(LPSTR param_1,WCHAR param_2)

{
  int *piVar1;
  int iVar2;
  BOOL local_4;
  
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_1005ccf8 == 0) {
    if (0xff < (ushort)param_2) {
      piVar1 = FUN_100490e0();
      *piVar1 = 0x2a;
      return -1;
    }
    *param_1 = (CHAR)param_2;
    return 1;
  }
  local_4 = 0;
  iVar2 = WideCharToMultiByte(DAT_1005cd08,0x220,&param_2,1,param_1,DAT_1005bb4c,(LPCSTR)0x0,
                              &local_4);
  if ((iVar2 == 0) || (local_4 != 0)) {
    piVar1 = FUN_100490e0();
    *piVar1 = 0x2a;
    iVar2 = -1;
  }
  return iVar2;
}


