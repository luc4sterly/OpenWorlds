// 100371c0 FUN_100371c0 [Global]
// programa: RWL21.DLL

undefined4 * FUN_100371c0(undefined4 param_1,uint param_2)

{
  undefined4 *puVar1;
  
  if ((int)param_2 < 1) {
    return (undefined4 *)0x0;
  }
  if (0xff4 < (int)param_2) {
    return (undefined4 *)0x0;
  }
  puVar1 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_1;
    if ((int)param_2 < 5) {
      param_2 = 4;
    }
    puVar1[2] = param_2;
    puVar1[3] = (int)(0xff4 / (ulonglong)param_2);
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    FUN_10036fa0(&DAT_1005b328,puVar1);
  }
  return puVar1;
}


