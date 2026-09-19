// 1000a2d0 FUN_1000a2d0 [Global]
// programa: RWL21.DLL

undefined4 FUN_1000a2d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((param_1[0x43] != 0) && (param_1[0x40] != 0)) {
    *(undefined4 *)(param_1[0x40] + 0x18) = 0;
    *(undefined4 *)(param_1[0x40] + 0x28) = 0;
    *(undefined4 *)(param_1[0x40] + 0x1c) = 0;
    *(undefined4 *)(param_1[0x40] + 0x20) = 0;
    RwDestroyRaster((undefined4 *)param_1[0x40]);
  }
  if ((undefined4 *)param_1[0x41] != (undefined4 *)0x0) {
    RwDestroyRaster((undefined4 *)param_1[0x41]);
  }
  puVar1 = (undefined4 *)0x0;
  puVar2 = *(undefined4 **)(PTR_DAT_1005b69c + 0xc);
  do {
    if (puVar2 == (undefined4 *)0x0) {
LAB_1000a359:
      FUN_10037010(DAT_1005a090,param_1);
      return 1;
    }
    if (param_1 == puVar2) {
      if (puVar1 == (undefined4 *)0x0) {
        *(undefined4 *)(PTR_DAT_1005b69c + 0xc) = *puVar2;
      }
      else {
        *puVar1 = *puVar2;
      }
      goto LAB_1000a359;
    }
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


