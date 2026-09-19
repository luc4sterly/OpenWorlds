// 100306b0 RwDestroyScene [Global]
// programa: RWL21.DLL

undefined1 RwDestroyScene(undefined4 *param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
                    /* 0x306b0  65  RwDestroyScene */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (DAT_1005adb0 != param_1) {
    RwForAllLightsInScene((int)param_1,RwDestroyLight);
    puVar2 = FUN_1002be50((int)param_1,(uint *)param_1[1]);
    param_1[1] = puVar2;
    iVar1 = param_1[7];
    while (iVar1 != 0) {
      iVar1 = param_1[7];
      param_1[7] = iVar1 + -1;
      puVar3 = *(undefined4 **)(param_1[3] + (iVar1 + -1) * 4);
      if ((puVar3 == (undefined4 *)0x0) || (puVar3[0x11] != 1)) {
        puVar3 = (undefined4 *)0x0;
      }
      if (puVar3 == (undefined4 *)0x0) {
        FUN_1000cba0(0x65);
      }
      else {
        *(undefined4 *)(puVar3[0x12] + 0xb8) = 0;
        FUN_10004010((undefined4 *)puVar3[0x12]);
        iVar1 = puVar3[0x11];
        if (iVar1 != 1) {
          if (iVar1 == 2) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar3[0x13]);
            puVar3[0x13] = 0;
            puVar3[0x12] = 0;
          }
          else if (iVar1 != 3) {
            FUN_1000cba0(0x65);
          }
        }
        puVar3[0x11] = 0;
        FUN_10037010(DAT_1005adac,puVar3);
      }
      iVar1 = param_1[7];
    }
    puVar3 = (undefined4 *)param_1[2];
    while (puVar3 != (undefined4 *)0x0) {
      param_1[2] = puVar3[4];
      if ((puVar3 == (undefined4 *)0x0) || (puVar3[0x11] != 1)) {
        puVar3 = (undefined4 *)0x0;
      }
      if (puVar3 == (undefined4 *)0x0) {
        FUN_1000cba0(0x65);
      }
      else {
        *(undefined4 *)(puVar3[0x12] + 0xb8) = 0;
        FUN_10004010((undefined4 *)puVar3[0x12]);
        iVar1 = puVar3[0x11];
        if (iVar1 != 1) {
          if (iVar1 == 2) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar3[0x13]);
            puVar3[0x13] = 0;
            puVar3[0x12] = 0;
          }
          else if (iVar1 != 3) {
            FUN_1000cba0(0x65);
          }
        }
        puVar3[0x11] = 0;
        FUN_10037010(DAT_1005adac,puVar3);
      }
      puVar3 = (undefined4 *)param_1[2];
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1[3]);
    param_1[3] = 0;
    FUN_10037010(DAT_1005ada8,param_1);
    return 1;
  }
  FUN_1000cba0(0x1a);
  return 0;
}


