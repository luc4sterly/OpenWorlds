// 1000b620 FUN_1000b620 [Global]
// program: RWDL8D21.DLL

undefined4 FUN_1000b620(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      if (param_1 != (int *)0x0) {
        if (param_1[1] != 0) {
          (**(code **)(DAT_10077da8 + 0x358))(param_1[1]);
        }
        param_1[1] = 0;
        *param_1 = 0;
        (**(code **)(DAT_10077da8 + 0x358))(param_1);
      }
      return 0;
    }
    if (param_1 != (int *)0x0) {
      iVar3 = 8;
      piVar2 = param_1;
      do {
        piVar2 = piVar2 + 1;
        iVar1 = FUN_1000b620((int *)*piVar2);
        iVar3 = iVar3 + -1;
        *piVar2 = iVar1;
      } while (iVar3 != 0);
      (**(code **)(DAT_10077da8 + 0x358))(param_1);
    }
  }
  return 0;
}


