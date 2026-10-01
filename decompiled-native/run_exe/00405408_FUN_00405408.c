// 00405408 FUN_00405408 [Global]
// program: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00405408(uint param_1)

{
  int *piVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_0040cf80) {
    iVar2 = (param_1 & 0x1f) * 8;
    piVar1 = (int *)((&DAT_0040ce80)[(int)param_1 >> 5] + iVar2);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_004091a8 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00405461;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_00405461:
      *(undefined4 *)((&DAT_0040ce80)[(int)param_1 >> 5] + iVar2) = 0xffffffff;
      return 0;
    }
  }
  DAT_0040ba3c = 0;
  _DAT_0040ba38 = 9;
  return 0xffffffff;
}


