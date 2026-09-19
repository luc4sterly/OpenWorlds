// 10017400 FUN_10017400 [Global]
// programa: RWL21.DLL

undefined4 * FUN_10017400(void)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_10037030(DAT_1005abf0);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    return puVar1;
  }
  FUN_1000cba0(3);
  return (undefined4 *)0x0;
}


