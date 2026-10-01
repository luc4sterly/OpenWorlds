// 00406d78 FUN_00406d78 [Global]
// program: run.exe

int * __cdecl FUN_00406d78(int param_1,int param_2)

{
  uint *_Size;
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar3 = (uint *)(param_1 * param_2);
  puVar4 = puVar3;
  if (puVar3 < (uint *)0xffffffe1) {
    if (puVar3 == (uint *)0x0) {
      puVar4 = (uint *)0x1;
    }
    puVar4 = (uint *)((int)puVar4 + 0xfU & 0xfffffff0);
  }
  do {
    if (puVar4 < (uint *)0xffffffe1) {
      if (DAT_0040ce64 == 3) {
        if (puVar3 <= DAT_0040ce5c) {
          piVar1 = FUN_00403f65(puVar3);
          _Size = puVar3;
joined_r0x00406de1:
          if (piVar1 != (int *)0x0) {
            _memset(piVar1,0,(size_t)_Size);
            return piVar1;
          }
        }
      }
      else if ((DAT_0040ce64 == 2) && (puVar4 <= DAT_0040b314)) {
        piVar1 = FUN_00404a08((uint)puVar4 >> 4);
        _Size = puVar4;
        goto joined_r0x00406de1;
      }
      piVar1 = HeapAlloc(DAT_0040ce60,8,(SIZE_T)puVar4);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_0040bb94 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_00403bae(puVar4);
    if (iVar2 == 0) {
      return (int *)0x0;
    }
  } while( true );
}


