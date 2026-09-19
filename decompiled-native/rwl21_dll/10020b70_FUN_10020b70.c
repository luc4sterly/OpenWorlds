// 10020b70 FUN_10020b70 [Global]
// programa: RWL21.DLL

undefined4 * FUN_10020b70(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 8;
  if (8 < param_1) {
    iVar2 = param_1;
  }
  if (iVar2 == 8) {
    puVar1 = FUN_10037030(DAT_1005accc);
  }
  else {
    puVar1 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar2 * 4 + 0xc);
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  *puVar1 = 0;
  puVar1[1] = iVar2;
  return puVar1;
}


