// 100163e0 FUN_100163e0 [Global]
// programa: RWL21.DLL

undefined4 * FUN_100163e0(FILE *param_1)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  byte *pbVar7;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  bool bVar12;
  int local_58;
  int local_54;
  byte local_50 [80];
  
  piVar5 = FUN_10037030(DAT_1005a0d4);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    FUN_1000cba0(3);
  }
  else {
    *piVar5 = 0;
    piVar5[1] = 0;
    piVar5[2] = -1;
    piVar5[3] = -1;
    piVar5[4] = -1;
    piVar5[5] = 0;
    piVar5[6] = 0;
    piVar5[7] = 0;
    piVar5[8] = 0;
    piVar5[9] = -1;
    iVar6 = RwGetDebugScriptState();
    piVar5[10] = iVar6;
    bVar3 = RwGetTextureDithering();
    piVar5[0xc] = CONCAT31(extraout_var,bVar3);
    iVar6 = RwGetTextureGammaCorrection();
    piVar5[0xe] = iVar6;
    iVar6 = RwGetTextureMipmapState();
    piVar5[0x10] = iVar6;
    cVar4 = _RwGetTextureColorMatching_0();
    piVar5[0x12] = CONCAT31(extraout_var_00,cVar4);
    cVar4 = _RwGetTextureOwnPalette_0();
    piVar5[0x14] = CONCAT31(extraout_var_01,cVar4);
    piVar5[0xb] = 0;
    piVar5[0xd] = 0;
    piVar5[0xf] = 0;
    piVar5[0x11] = 0;
    piVar5[0x13] = 0;
    piVar5[0x15] = 0;
    piVar5[0x16] = 0;
    piVar5[0x17] = 0;
    piVar5[0x18] = 0;
  }
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar1 = DAT_1005dfc8;
    piVar2 = DAT_1005dfcc;
  }
  else {
    piVar1 = piVar5;
    piVar2 = piVar5;
    if (DAT_1005dfcc != (int *)0x0) {
      piVar5[0x17] = (int)DAT_1005dfcc;
      DAT_1005dfcc[0x18] = (int)piVar5;
      piVar1 = DAT_1005dfc8;
    }
  }
  DAT_1005dfcc = piVar2;
  DAT_1005dfc8 = piVar1;
  if (piVar5 != (int *)0x0) {
    iVar6 = RwGetDeviceInfo(2,&local_54,4);
    if ((iVar6 == 0) || (local_54 == 0)) {
      piVar5[0x16] = 0;
    }
    else {
      piVar5[0x16] = 1;
    }
    piVar5[9] = 0;
    piVar5[8] = 0;
    local_58 = 1;
    do {
      piVar5[9] = piVar5[9] + 1;
      iVar6 = FUN_100206d0(param_1,(char *)local_50,0x19);
      if (iVar6 < 0) {
        FUN_1000cba0(5);
        local_58 = 0;
      }
      else {
        if ((iVar6 == 1) && (local_50[0] != 0x23)) {
          pbVar7 = local_50;
          bVar3 = local_50[0];
          while (bVar3 != 0) {
            bVar3 = *pbVar7;
            if (('@' < (char)bVar3) && ((char)bVar3 < '[')) {
              *pbVar7 = bVar3 + 0x20;
            }
            pbVar10 = pbVar7 + 1;
            pbVar7 = pbVar7 + 1;
            bVar3 = *pbVar10;
          }
          iVar6 = 0;
          pcVar8 = s_modelbegin_1005a260;
          do {
            pbVar7 = local_50;
            pbVar10 = (byte *)pcVar8;
            do {
              bVar3 = *pbVar7;
              bVar12 = bVar3 < *pbVar10;
              if (bVar3 != *pbVar10) {
LAB_10016576:
                iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                goto LAB_1001657b;
              }
              if (bVar3 == 0) break;
              bVar3 = pbVar7[1];
              bVar12 = bVar3 < pbVar10[1];
              if (bVar3 != pbVar10[1]) goto LAB_10016576;
              pbVar7 = pbVar7 + 2;
              pbVar10 = pbVar10 + 2;
            } while (bVar3 != 0);
            iVar9 = 0;
LAB_1001657b:
            if (iVar9 == 0) {
              local_58 = (*(code *)(&PTR_FUN_1005a27c)[iVar6 * 8])(param_1);
              break;
            }
            pcVar8 = pcVar8 + 0x20;
            iVar6 = iVar6 + 1;
          } while (pcVar8 < &DAT_1005aa80);
          if ((&PTR_FUN_1005a27c)[iVar6 * 8] == (undefined *)0x0) {
            FUN_1000cba0(4);
            local_58 = 0;
          }
        }
        if (local_58 != 1) break;
        do {
          iVar6 = _fgetc(param_1);
          if (iVar6 == -1) break;
        } while (iVar6 != 10);
      }
    } while (local_58 == 1);
    if (local_58 == 0) {
      puVar11 = (undefined4 *)0x0;
      FUN_1000f2b0(DAT_1005dfcc);
    }
    else {
      puVar11 = (undefined4 *)piVar5[8];
      if (puVar11 == (undefined4 *)0x0) {
        FUN_1000cba0(0x28);
      }
    }
    piVar5[8] = 0;
    piVar5 = DAT_1005dfcc;
    if (DAT_1005dfcc == (int *)0x0) {
      FUN_1000cba0(0x22);
    }
    else {
      if (DAT_1005dfcc == DAT_1005dfc8) {
        DAT_1005dfcc = (int *)0x0;
        DAT_1005dfc8 = (int *)0x0;
      }
      else {
        DAT_1005dfcc = (int *)DAT_1005dfcc[0x17];
        DAT_1005dfcc[0x18] = 0;
      }
      iVar6 = FUN_1000f2b0(piVar5);
      FUN_10037010(DAT_1005a0d4,piVar5);
      if (iVar6 != 0) {
        return puVar11;
      }
    }
    if (puVar11 != (undefined4 *)0x0) {
      RwDestroyClump(puVar11);
    }
  }
  return (undefined4 *)0x0;
}


