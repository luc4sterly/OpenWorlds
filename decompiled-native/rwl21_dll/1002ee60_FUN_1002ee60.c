// 1002ee60 FUN_1002ee60 [Global]
// program: RWL21.DLL

undefined4 * FUN_1002ee60(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if ((0 < param_1) && (param_1 < 4)) {
    puVar1 = FUN_10037030(DAT_1005adac);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[0x11] = param_1;
      puVar1[6] = param_2;
      puVar1[5] = param_3;
      *puVar1 = 0;
      puVar1[4] = 0;
      return puVar1;
    }
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  FUN_1000cba0(0x65);
  return (undefined4 *)0x0;
}


