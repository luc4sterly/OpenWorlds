// 10021050 FUN_10021050 [Global]
// programa: RWL21.DLL

undefined4 * FUN_10021050(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = FUN_10037030(DAT_1005acdc);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  puVar1[0xc] = 0;
  puVar1[0xf] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[7] = param_1;
  puVar1[8] = param_2;
  puVar1[9] = param_3;
  puVar1[1] = 0;
  iVar2 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar1);
  if (iVar2 == 0) {
    FUN_10037010(DAT_1005acdc,puVar1);
    return (undefined4 *)0x0;
  }
  return puVar1;
}


