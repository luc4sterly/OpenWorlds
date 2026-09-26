// 00405391 FUN_00405391 [Global]
// programa: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00405391(uint param_1,HANDLE param_2)

{
  int iVar1;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0040cf80) {
    iVar1 = (param_1 & 0x1f) * 8;
    if (*(int *)((&DAT_0040ce80)[(int)param_1 >> 5] + iVar1) == -1) {
      if (DAT_004091a8 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_004053e7;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_004053e7:
      *(HANDLE *)((&DAT_0040ce80)[(int)param_1 >> 5] + iVar1) = param_2;
      return 0;
    }
  }
  DAT_0040ba3c = 0;
  _DAT_0040ba38 = 9;
  return 0xffffffff;
}


