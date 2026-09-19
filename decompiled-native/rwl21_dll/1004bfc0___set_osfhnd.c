// 1004bfc0 __set_osfhnd [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 1998 Release */

int __cdecl __set_osfhnd(int param_1,intptr_t param_2)

{
  int iVar1;
  int *piVar2;
  ulong *puVar3;
  
  if ((uint)param_1 < DAT_1005f7d0) {
    piVar2 = (int *)((int)&DAT_1005f6d0 + ((int)(param_1 & 0xffffffe7U) >> 3));
    iVar1 = (param_1 & 0x1fU) * 0x24;
    if (*(int *)(*piVar2 + iVar1) == -1) {
      if (DAT_1005bb74 == 1) {
        if (param_1 == 0) {
          SetStdHandle(0xfffffff6,(HANDLE)param_2);
        }
        else if (param_1 == 1) {
          SetStdHandle(0xfffffff5,(HANDLE)param_2);
        }
        else if (param_1 == 2) {
          SetStdHandle(0xfffffff4,(HANDLE)param_2);
        }
      }
      *(intptr_t *)(*piVar2 + iVar1) = param_2;
      return 0;
    }
  }
  piVar2 = FUN_100490e0();
  *piVar2 = 9;
  puVar3 = FUN_100490f0();
  *puVar3 = 0;
  return -1;
}


