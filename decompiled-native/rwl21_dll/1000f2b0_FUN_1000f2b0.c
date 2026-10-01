// 1000f2b0 FUN_1000f2b0 [Global]
// program: RWL21.DLL

undefined4 FUN_1000f2b0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)param_1[6];
  do {
    if (puVar2 == (undefined4 *)0x0) break;
    puVar1 = (undefined4 *)puVar2[0x29];
    iVar3 = FUN_1000f440(puVar2);
    puVar2 = puVar1;
  } while (iVar3 != 0);
  param_1[7] = 0;
  param_1[6] = 0;
  puVar2 = (undefined4 *)param_1[5];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[2];
    (**(code **)(PTR_DAT_1005b69c + 0x358))(*puVar2);
    if (((undefined4 *)puVar2[1] != (undefined4 *)0x0) &&
       (iVar3 = RwDestroyClump((undefined4 *)puVar2[1]), iVar3 == 0)) break;
    FUN_10037010(DAT_1005a0d8,puVar2);
    puVar2 = puVar1;
  }
  param_1[5] = 0;
  if (*param_1 != 0) {
    if (-1 < param_1[2]) {
      do {
        iVar3 = FUN_1001d750();
        if (iVar3 <= param_1[2]) break;
        iVar3 = FUN_1001d780();
      } while (iVar3 != 0);
      param_1[2] = -1;
    }
    if (-1 < param_1[3]) {
      do {
        iVar3 = FUN_1001d740((int)DAT_1005dfd0);
        if (iVar3 <= param_1[3]) break;
        iVar3 = FUN_1001d720(DAT_1005dfd0);
      } while (iVar3 != 0);
      param_1[3] = -1;
    }
    if (-1 < param_1[4]) {
      do {
        iVar3 = FUN_10019b40();
        if (iVar3 <= param_1[4]) break;
        iVar3 = RwPopCurrentMaterial();
      } while (iVar3 != 0);
      param_1[4] = -1;
    }
  }
  if ((undefined4 *)param_1[8] != (undefined4 *)0x0) {
    RwDestroyClump((undefined4 *)param_1[8]);
  }
  *param_1 = 0;
  param_1[8] = 0;
  param_1[9] = -1;
  param_1[1] = 0;
  if (param_1[10] != 0) {
    RwSetDebugScriptState(param_1[10]);
  }
  if (param_1[0xc] != 0) {
    RwSetTextureDithering(param_1[0xc]);
  }
  if (param_1[0xe] != 0) {
    RwSetTextureGammaCorrection(param_1[0xe]);
  }
  if (param_1[0x10] != 0) {
    RwSetTextureMipmapState(param_1[0x10]);
  }
  if (param_1[0x12] != 0) {
    _RwSetTextureColorMatching_4(param_1[0x12]);
  }
  if (param_1[0x14] != 0) {
    _RwSetTextureOwnPalette_4(param_1[0x14]);
  }
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x14] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xf] = 0;
  param_1[0x11] = 0;
  return 1;
}


