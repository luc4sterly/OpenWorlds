// 1000f080 RwModelEnd [Global]
// programa: RWL21.DLL

undefined4 RwModelEnd(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
                    /* 0xf080  291  RwModelEnd */
  if (*DAT_1005dfcc == 0) {
    FUN_1000cba0(0x22);
    return 0;
  }
  *DAT_1005dfcc = 0;
  if (DAT_1005dfcc[7] == 0) {
    if (DAT_1005dfcc[1] != 0) {
      FUN_1000f2b0(DAT_1005dfcc);
      FUN_1000cba0(0x23);
      return 0;
    }
    iVar4 = DAT_1005dfcc[2];
    if ((0 < iVar4) && (iVar3 = FUN_1001d750(), iVar4 < iVar3)) {
      do {
        FUN_1001d780();
        iVar4 = FUN_1001d750();
      } while (DAT_1005dfcc[2] < iVar4);
    }
    DAT_1005dfcc[2] = -1;
    iVar4 = DAT_1005dfcc[3];
    if ((0 < iVar4) && (iVar3 = FUN_1001d740((int)DAT_1005dfd0), iVar4 < iVar3)) {
      do {
        FUN_1001d720(DAT_1005dfd0);
        iVar4 = FUN_1001d740((int)DAT_1005dfd0);
      } while (DAT_1005dfcc[3] < iVar4);
    }
    DAT_1005dfcc[3] = -1;
    iVar4 = DAT_1005dfcc[4];
    if ((0 < iVar4) && (iVar3 = FUN_10019b40(), iVar4 < iVar3)) {
      do {
        RwPopCurrentMaterial();
        iVar4 = FUN_10019b40();
      } while (DAT_1005dfcc[4] < iVar4);
    }
    DAT_1005dfcc[4] = -1;
    if (DAT_1005dfcc[0xb] != 0) {
      RwSetDebugScriptState(DAT_1005dfcc[0xb]);
    }
    if (DAT_1005dfcc[0xd] != 0) {
      RwSetTextureDithering(DAT_1005dfcc[0xd]);
    }
    if (DAT_1005dfcc[0xf] != 0) {
      RwSetTextureGammaCorrection(DAT_1005dfcc[0xf]);
    }
    if (DAT_1005dfcc[0x11] != 0) {
      RwSetTextureMipmapState(DAT_1005dfcc[0x11]);
    }
    if (DAT_1005dfcc[0x13] != 0) {
      _RwSetTextureColorMatching_4(DAT_1005dfcc[0x13]);
    }
    if (DAT_1005dfcc[0x15] != 0) {
      _RwSetTextureOwnPalette_4(DAT_1005dfcc[0x15]);
    }
    DAT_1005dfcc[0xb] = 0;
    DAT_1005dfcc[0xd] = 0;
    DAT_1005dfcc[0xf] = 0;
    DAT_1005dfcc[0x11] = 0;
    DAT_1005dfcc[0x13] = 0;
    DAT_1005dfcc[0x15] = 0;
    piVar5 = DAT_1005dfcc + 5;
    puVar2 = (undefined4 *)DAT_1005dfcc[5];
    while( true ) {
      if (puVar2 == (undefined4 *)0x0) {
        *piVar5 = 0;
        return 1;
      }
      puVar1 = (undefined4 *)puVar2[2];
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*puVar2);
      if (((undefined4 *)puVar2[1] != (undefined4 *)0x0) &&
         (iVar4 = RwDestroyClump((undefined4 *)puVar2[1]), iVar4 == 0)) break;
      FUN_10037010(DAT_1005a0d8,puVar2);
      puVar2 = puVar1;
    }
    *piVar5 = 0;
    return 0;
  }
  FUN_1000f2b0(DAT_1005dfcc);
  FUN_1000cba0(0x23);
  return 0;
}


