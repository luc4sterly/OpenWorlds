// 10019b50 RwDestroyMaterial [Global]
// program: RWL21.DLL

undefined4 RwDestroyMaterial(undefined4 *param_1)

{
  undefined4 uVar1;
  
                    /* 0x19b50  61  RwDestroyMaterial */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((uint)param_1[0x10] < 2) {
    uVar1 = FUN_10020be0((undefined4 *)param_1[0xf]);
    param_1[0xf] = uVar1;
    FUN_10037010(DAT_1005ac24,param_1);
    return 1;
  }
  param_1[0x10] = param_1[0x10] - 1;
  return 1;
}


