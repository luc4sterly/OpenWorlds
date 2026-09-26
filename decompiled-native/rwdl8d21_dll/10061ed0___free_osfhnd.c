// 10061ed0 __free_osfhnd [Global]
// programa: RWDL8D21.DLL

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
  
  if ((uint)param_1 < DAT_10079410) {
    piVar3 = (int *)((int)&DAT_10079310 + ((int)(param_1 & 0xffffffe7U) >> 3));
    iVar1 = (param_1 & 0x1fU) * 0x24;
    piVar2 = (int *)(*piVar3 + iVar1);
    if (((*(byte *)(piVar2 + 1) & 1) != 0) && (*piVar2 != -1)) {
      if (DAT_10075584 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_10061f35;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_10061f35:
      *(undefined4 *)(*piVar3 + iVar1) = 0xffffffff;
      return 0;
    }
  }
  piVar3 = FUN_1005fdb0();
  *piVar3 = 9;
  puVar4 = FUN_1005fdc0();
  *puVar4 = 0;
  return -1;
}


