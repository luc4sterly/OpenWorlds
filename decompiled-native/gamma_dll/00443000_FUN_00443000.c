// 00443000 FUN_00443000 [Global]
// programa: gamma.dll

undefined4 * __fastcall FUN_00443000(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00451780((undefined4 *)puVar1[8]);
    FUN_00451780((undefined4 *)puVar1[10]);
    FUN_00451780((undefined4 *)puVar1[0xb]);
    FUN_00451780((undefined4 *)puVar1[0xd]);
    FUN_00451780((undefined4 *)puVar1[0xf]);
    iVar3 = 0;
    do {
      puVar2 = (undefined4 *)puVar1[iVar3 + 0x11];
      if (puVar2 != (undefined4 *)0x0) {
        FUN_00426ad0(puVar2);
        FUN_0044e100(puVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
    FUN_0044e100(puVar1);
  }
  return param_1;
}


