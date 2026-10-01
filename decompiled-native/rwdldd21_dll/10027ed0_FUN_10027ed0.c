// 10027ed0 FUN_10027ed0 [Global]
// program: RWDLDD21.DLL

undefined4 FUN_10027ed0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      if (param_1 != (int *)0x0) {
        if (param_1[1] != 0) {
          (**(code **)(DAT_100394fc + 0x358))(param_1[1]);
        }
        param_1[1] = 0;
        *param_1 = 0;
        (**(code **)(DAT_100394fc + 0x358))(param_1);
      }
      return 0;
    }
    if (param_1 != (int *)0x0) {
      iVar3 = 8;
      piVar2 = param_1;
      do {
        piVar2 = piVar2 + 1;
        iVar1 = FUN_10027ed0((int *)*piVar2);
        iVar3 = iVar3 + -1;
        *piVar2 = iVar1;
      } while (iVar3 != 0);
      (**(code **)(DAT_100394fc + 0x358))(param_1);
    }
  }
  return 0;
}


