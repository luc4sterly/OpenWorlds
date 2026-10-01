// 1000bd40 FUN_1000bd40 [Global]
// program: RWDL8D21.DLL

int * FUN_1000bd40(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(**(code **)(DAT_10077da8 + 0x34c))(8);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(DAT_10077da8 + 0x34c))(*param_1);
    piVar1[1] = iVar2;
    if (iVar2 != 0) {
      iVar3 = 0;
      if (0 < *param_1) {
        do {
          iVar3 = iVar3 + 1;
          *(undefined1 *)(iVar2 + -1 + iVar3) = *(undefined1 *)(param_1[1] + -1 + iVar3);
        } while (iVar3 < *param_1);
      }
      *piVar1 = *param_1;
      return piVar1;
    }
    (**(code **)(DAT_10077da8 + 0x358))(piVar1);
  }
  return (int *)0x0;
}


