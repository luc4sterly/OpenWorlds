// 1004bd40 __mbtowc_lk [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __mbtowc_lk
   
   Library: Visual Studio 1998 Release */

uint __cdecl __mbtowc_lk(LPWSTR param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_2 == (byte *)0x0) || (param_3 == 0)) {
    return 0;
  }
  bVar1 = *param_2;
  if (bVar1 == 0) {
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
    return 0;
  }
  if (DAT_1005ccf8 != 0) {
    if ((PTR_DAT_1005b940[(uint)bVar1 * 2 + 1] & 0x80) == 0) {
      iVar2 = MultiByteToWideChar(DAT_1005cd08,9,(LPCSTR)param_2,1,param_1,
                                  (uint)(param_1 != (LPWSTR)0x0));
      if (iVar2 != 0) {
        return 1;
      }
      piVar3 = FUN_100490e0();
      *piVar3 = 0x2a;
      return 0xffffffff;
    }
    if (((((int)DAT_1005bb4c < 2) || ((int)param_3 < (int)DAT_1005bb4c)) ||
        (iVar2 = MultiByteToWideChar(DAT_1005cd08,9,(LPCSTR)param_2,DAT_1005bb4c,param_1,
                                     (uint)(param_1 != (LPWSTR)0x0)), iVar2 == 0)) &&
       ((param_3 < DAT_1005bb4c || (param_2[1] == 0)))) {
      piVar3 = FUN_100490e0();
      *piVar3 = 0x2a;
      return 0xffffffff;
    }
    return DAT_1005bb4c;
  }
  if (param_1 != (LPWSTR)0x0) {
    *param_1 = (ushort)bVar1;
  }
  return 1;
}


