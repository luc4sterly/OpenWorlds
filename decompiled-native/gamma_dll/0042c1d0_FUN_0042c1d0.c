// 0042c1d0 FUN_0042c1d0 [Global]
// program: gamma.dll

void FUN_0042c1d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    if (puVar2 != (undefined4 *)0x0) {
      if ((undefined4 *)*puVar2 != (undefined4 *)0x0) {
        FUN_0042c1d0((undefined4 *)*puVar2);
      }
      if ((undefined4 *)puVar2[1] != (undefined4 *)0x0) {
        FUN_0042c1d0((undefined4 *)puVar2[1]);
      }
      FUN_0042c350(puVar2 + 3);
      FUN_0042c330(puVar2);
    }
    puVar2 = (undefined4 *)puVar1[1];
    if (puVar2 != (undefined4 *)0x0) {
      if ((undefined4 *)*puVar2 != (undefined4 *)0x0) {
        FUN_0042c1d0((undefined4 *)*puVar2);
      }
      if ((undefined4 *)puVar2[1] != (undefined4 *)0x0) {
        FUN_0042c1d0((undefined4 *)puVar2[1]);
      }
      FUN_0042c350(puVar2 + 3);
      FUN_0042c330(puVar2);
    }
    FUN_0042c320(puVar1 + 3);
    FUN_0044e100(puVar1);
  }
  puVar1 = (undefined4 *)param_1[1];
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    if (puVar2 != (undefined4 *)0x0) {
      if ((undefined4 *)*puVar2 != (undefined4 *)0x0) {
        FUN_0042c1d0((undefined4 *)*puVar2);
      }
      if ((undefined4 *)puVar2[1] != (undefined4 *)0x0) {
        FUN_0042c1d0((undefined4 *)puVar2[1]);
      }
      FUN_0042c350(puVar2 + 3);
      FUN_0042c330(puVar2);
    }
    puVar2 = (undefined4 *)puVar1[1];
    if (puVar2 != (undefined4 *)0x0) {
      if ((undefined4 *)*puVar2 != (undefined4 *)0x0) {
        FUN_0042c1d0((undefined4 *)*puVar2);
      }
      if ((undefined4 *)puVar2[1] != (undefined4 *)0x0) {
        FUN_0042c1d0((undefined4 *)puVar2[1]);
      }
      FUN_0042c350(puVar2 + 3);
      FUN_0042c330(puVar2);
    }
    FUN_0042c320(puVar1 + 3);
    FUN_0044e100(puVar1);
  }
  param_1[0x44] = &PTR_LAB_00471ff8;
  param_1[3] = &PTR_LAB_00471ff8;
  FUN_0044e100(param_1);
  return;
}


