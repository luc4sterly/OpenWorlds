// 10069350 __free_osfhnd [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 1998 Release */

int __cdecl __free_osfhnd(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  ulong *puVar4;
  DWORD nStdHandle;
  
  if ((uint)param_1 < DAT_1008b450) {
    piVar3 = (int *)((int)&DAT_1008b350 + ((int)(param_1 & 0xffffffe7U) >> 3));
    iVar1 = (param_1 & 0x1fU) * 0x24;
    piVar2 = (int *)(*piVar3 + iVar1);
    if (((*(byte *)(piVar2 + 1) & 1) != 0) && (*piVar2 != -1)) {
      if (DAT_100875b4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_100693b5;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_100693b5:
      *(undefined4 *)(*piVar3 + iVar1) = 0xffffffff;
      return 0;
    }
  }
  piVar3 = FUN_10067230();
  *piVar3 = 9;
  puVar4 = FUN_10067240();
  *puVar4 = 0;
  return -1;
}


