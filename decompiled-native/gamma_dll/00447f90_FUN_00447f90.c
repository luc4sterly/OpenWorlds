// 00447f90 FUN_00447f90 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00447f90(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + -2;
  if (puVar2 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *puVar2 = &PTR_FUN_0047ab20;
      param_1[-1] = &PTR_FUN_0047ab78;
      *param_1 = &PTR_FUN_0047abc8;
      param_1[-1] = &PTR_FUN_0047ac78;
      *param_1 = &PTR_FUN_0047acc8;
      piVar1 = (int *)param_1[3];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      *param_1 = &PTR_FUN_0047a004;
      FUN_00446370(param_1 + 1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(puVar2);
      }
    }
    else {
      FUN_00451710((int)puVar2,&LAB_00447ab0);
    }
  }
  return puVar2;
}


