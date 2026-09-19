// 10005650 FUN_10005650 [Global]
// programa: RWL21.DLL

undefined4 * FUN_10005650(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  if (param_1 < 1) {
    param_1 = 8;
  }
  puVar1 = FUN_10037030(DAT_10058054);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  puVar1[0x22] = 0;
  puVar1[0x2e] = 0;
  puVar1[0x30] = 0;
  puVar1[0x25] = 0;
  puVar1[0x24] = 4;
  puVar1[0x23] = 1;
  puVar1[0x38] = 0;
  puVar1[0x37] = 1;
  puVar1[0x36] = 1;
  puVar1[0x31] = 0;
  puVar1[0x32] = 0;
  FUN_1001c4a0(puVar1);
  FUN_1001c4a0(puVar1 + 0x11);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    puVar1[0x2c] = 0;
  }
  FUN_1001c4a0(puVar1 + 0x3b);
  FUN_1001c4a0(puVar1 + 0x4c);
  puVar1[0x62] = 0;
  puVar1[0x5d] = 0;
  puVar1[0x5e] = 0;
  puVar1[0x5f] = 0;
  puVar1[0x60] = 0;
  puVar1[0x61] = 0;
  puVar1[0x39] = 0;
  puVar1[99] = 1;
  puVar1[0x28] = 0;
  puVar1[100] = 2;
  puVar1[0x3a] = 0;
  puVar1[0x2c] = 0;
  puVar1[0x65] = 0;
  *(undefined2 *)(puVar1 + 0x66) = 0;
  *(undefined1 *)((int)puVar1 + 0x19b) = 1;
  puVar2 = FUN_10020b70(0);
  puVar1[0x27] = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2 = FUN_10020b70(param_1);
    puVar1[0x26] = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      iVar3 = FUN_100328a0((int)puVar1,DAT_10058058);
      if (iVar3 != 0) {
        puVar2 = puVar1;
        uVar4 = RwDefaultScene();
        uVar5 = RwAddClumpToScene(uVar4,(uint)puVar2);
        uVar4 = DAT_10058058;
        if (uVar5 != 0) {
          if (puVar1 == (undefined4 *)0x0) {
            FUN_1000cba0(1);
            return (undefined4 *)0x0;
          }
          if ((DAT_10058058 & 0xfffffff8) != 0) {
            FUN_1000cba0(0x30);
            return puVar1;
          }
          if (((DAT_10058058 & 1) == 0) || ((puVar1[0x62] & 1) != 0)) {
            if (((DAT_10058058 & 1) != 0) || ((puVar1[0x62] & 1) == 0)) goto LAB_10005829;
            iVar3 = 0;
          }
          else {
            iVar3 = 1;
          }
          FUN_1002c070((int)puVar1,iVar3);
LAB_10005829:
          uVar4 = FUN_10033600((int)puVar1,uVar4);
          puVar1[0x62] = uVar4;
          return puVar1;
        }
      }
      uVar6 = FUN_10020be0((undefined4 *)puVar1[0x26]);
      puVar1[0x26] = uVar6;
    }
    uVar6 = FUN_10020be0((undefined4 *)puVar1[0x27]);
    puVar1[0x27] = uVar6;
  }
  FUN_10037010(DAT_10058054,puVar1);
  return (undefined4 *)0x0;
}


