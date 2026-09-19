// 10016720 FUN_10016720 [Global]
// programa: RWL21.DLL

undefined4 FUN_10016720(void)

{
  undefined4 *puVar1;
  byte bVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  bool bVar7;
  
  DAT_1005dfd0 = FUN_1001d3a0(8);
  if (DAT_1005dfd0 == (int *)0x0) {
    return 0;
  }
  DAT_1005a0d0 = FUN_100371c0(s_creationcontextlist_1005abd8,0xa8);
  DAT_1005a0d4 = FUN_100371c0(s_parsecontextlist_1005abc4,100);
  DAT_1005a0d8 = FUN_100371c0(s_prototypenodelist_1005abb0,0xc);
  if (((DAT_1005a0d0 != (undefined4 *)0x0) && (DAT_1005a0d4 != (undefined4 *)0x0)) &&
     (DAT_1005a0d8 != (undefined4 *)0x0)) {
    DAT_1005dfc8 = (undefined4 *)0x0;
    DAT_1005dfcc = (undefined4 *)0x0;
    *(undefined4 *)(PTR_DAT_1005b69c + 0x2c8) = 0;
    puVar4 = FUN_10037030((int)DAT_1005a0d4);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
      FUN_1000cba0(3);
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0xffffffff;
      puVar4[4] = 0xffffffff;
      puVar4[5] = 0;
      puVar4[6] = 0;
      puVar4[7] = 0;
      puVar4[8] = 0;
      puVar4[9] = 0xffffffff;
      uVar5 = RwGetDebugScriptState();
      puVar4[10] = uVar5;
      bVar2 = RwGetTextureDithering();
      puVar4[0xc] = CONCAT31(extraout_var,bVar2);
      iVar6 = RwGetTextureGammaCorrection();
      puVar4[0xe] = iVar6;
      iVar6 = RwGetTextureMipmapState();
      puVar4[0x10] = iVar6;
      cVar3 = _RwGetTextureColorMatching_0();
      puVar4[0x12] = CONCAT31(extraout_var_00,cVar3);
      cVar3 = _RwGetTextureOwnPalette_0();
      puVar4[0x14] = CONCAT31(extraout_var_01,cVar3);
      puVar4[0xb] = 0;
      puVar4[0xd] = 0;
      puVar4[0xf] = 0;
      puVar4[0x11] = 0;
      puVar4[0x13] = 0;
      puVar4[0x15] = 0;
      puVar4[0x16] = 0;
      puVar4[0x17] = 0;
      puVar4[0x18] = 0;
    }
    if (puVar4 == (undefined4 *)0x0) {
      bVar7 = false;
    }
    else {
      puVar1 = puVar4;
      if (DAT_1005dfcc != (undefined4 *)0x0) {
        puVar4[0x17] = DAT_1005dfcc;
        DAT_1005dfcc[0x18] = puVar4;
        puVar1 = DAT_1005dfc8;
      }
      DAT_1005dfc8 = puVar1;
      bVar7 = puVar4 != (undefined4 *)0x0;
      DAT_1005dfcc = puVar4;
    }
    if (bVar7) {
      return 1;
    }
  }
  return 0;
}


