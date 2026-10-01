// 100308e0 FUN_100308e0 [Global]
// program: RWL21.DLL

undefined4 FUN_100308e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  
  puVar2 = DAT_1005adb0;
  RwForAllLightsInScene((int)DAT_1005adb0,RwDestroyLight);
  puVar3 = FUN_1002be50((int)puVar2,(uint *)puVar2[1]);
  puVar2[1] = puVar3;
  iVar1 = puVar2[7];
  while (iVar1 != 0) {
    iVar1 = puVar2[7];
    puVar2[7] = iVar1 + -1;
    puVar4 = *(undefined4 **)(puVar2[3] + (iVar1 + -1) * 4);
    if ((puVar4 == (undefined4 *)0x0) || (puVar4[0x11] != 1)) {
      puVar4 = (undefined4 *)0x0;
    }
    if (puVar4 == (undefined4 *)0x0) {
      FUN_1000cba0(0x65);
    }
    else {
      *(undefined4 *)(puVar4[0x12] + 0xb8) = 0;
      FUN_10004010((undefined4 *)puVar4[0x12]);
      iVar1 = puVar4[0x11];
      if (iVar1 != 1) {
        if (iVar1 == 2) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar4[0x13]);
          puVar4[0x13] = 0;
          puVar4[0x12] = 0;
        }
        else if (iVar1 != 3) {
          FUN_1000cba0(0x65);
        }
      }
      puVar4[0x11] = 0;
      FUN_10037010(DAT_1005adac,puVar4);
    }
    iVar1 = puVar2[7];
  }
  puVar4 = (undefined4 *)puVar2[2];
  while (puVar4 != (undefined4 *)0x0) {
    puVar2[2] = puVar4[4];
    if ((puVar4 == (undefined4 *)0x0) || (puVar4[0x11] != 1)) {
      puVar4 = (undefined4 *)0x0;
    }
    if (puVar4 == (undefined4 *)0x0) {
      FUN_1000cba0(0x65);
    }
    else {
      *(undefined4 *)(puVar4[0x12] + 0xb8) = 0;
      FUN_10004010((undefined4 *)puVar4[0x12]);
      iVar1 = puVar4[0x11];
      if (iVar1 != 1) {
        if (iVar1 == 2) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar4[0x13]);
          puVar4[0x13] = 0;
          puVar4[0x12] = 0;
        }
        else if (iVar1 != 3) {
          FUN_1000cba0(0x65);
        }
      }
      puVar4[0x11] = 0;
      FUN_10037010(DAT_1005adac,puVar4);
    }
    puVar4 = (undefined4 *)puVar2[2];
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar2[3]);
  puVar2[3] = 0;
  FUN_10037010(DAT_1005ada8,puVar2);
  DAT_1005adb0 = (undefined4 *)0x0;
  FUN_100370f0();
  FUN_100370f0();
  return 1;
}


