// 1000ef40 RwModelBegin [Global]
// programa: RWL21.DLL

undefined4 RwModelBegin(void)

{
  int *piVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int extraout_EDX;
  int extraout_EDX_00;
  
                    /* 0xef40  290  RwModelBegin */
  if ((*DAT_1005dfcc != 0) || (DAT_1005dfcc[7] != 0)) {
    FUN_1000cba0(0x21);
    return 0;
  }
  iVar4 = FUN_1001d750();
  piVar1 = DAT_1005dfcc;
  DAT_1005dfcc[2] = iVar4;
  iVar4 = FUN_1001d760(piVar1,extraout_EDX);
  if (iVar4 == 0) {
    return 0;
  }
  puVar5 = (undefined4 *)FUN_1001d770();
  FUN_1001c4a0(puVar5);
  iVar4 = FUN_1001d740((int)DAT_1005dfd0);
  piVar1 = DAT_1005dfcc;
  DAT_1005dfcc[3] = iVar4;
  iVar4 = FUN_1001d5c0(piVar1,extraout_EDX_00,DAT_1005dfd0);
  if (iVar4 != 0) {
    puVar5 = (undefined4 *)FUN_1001d710(DAT_1005dfd0);
    FUN_1001c4a0(puVar5);
    iVar4 = FUN_10019b40();
    DAT_1005dfcc[4] = iVar4;
    iVar4 = RwPushCurrentMaterial();
    if (iVar4 != 0) {
      puVar6 = (uint *)RwCurrentMaterial();
      FUN_1001b200(puVar6);
      iVar4 = RwGetDebugScriptState();
      DAT_1005dfcc[0xb] = iVar4;
      bVar2 = RwGetTextureDithering();
      DAT_1005dfcc[0xd] = CONCAT31(extraout_var,bVar2);
      iVar4 = RwGetTextureGammaCorrection();
      DAT_1005dfcc[0xf] = iVar4;
      iVar4 = RwGetTextureMipmapState();
      DAT_1005dfcc[0x11] = iVar4;
      cVar3 = _RwGetTextureColorMatching_0();
      DAT_1005dfcc[0x13] = CONCAT31(extraout_var_00,cVar3);
      cVar3 = _RwGetTextureOwnPalette_0();
      DAT_1005dfcc[0x15] = CONCAT31(extraout_var_01,cVar3);
      DAT_1005dfcc[5] = 0;
      *DAT_1005dfcc = 1;
      return 1;
    }
    return 0;
  }
  return 0;
}


