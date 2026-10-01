// 10020be0 FUN_10020be0 [Global]
// program: RWL21.DLL

undefined4 FUN_10020be0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[1] == 8) {
      FUN_10037010(DAT_1005accc,param_1);
      return 0;
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))();
  }
  return 0;
}


