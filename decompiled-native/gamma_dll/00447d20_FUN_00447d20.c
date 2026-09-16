// 00447d20 FUN_00447d20 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00447d20(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = &PTR_FUN_0047aa20;
      param_1[1] = &PTR_FUN_0047aa78;
      param_1[2] = &PTR_FUN_0047aac8;
      DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
      *param_1 = &PTR_FUN_0047ab20;
      param_1[1] = &PTR_FUN_0047ab78;
      param_1[2] = &PTR_FUN_0047abc8;
      param_1[1] = &PTR_FUN_0047ac78;
      param_1[2] = &PTR_FUN_0047acc8;
      piVar1 = (int *)param_1[5];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      param_1[2] = &PTR_FUN_0047a004;
      FUN_00446370(param_1 + 3);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00447dc0);
    }
  }
  return param_1;
}


