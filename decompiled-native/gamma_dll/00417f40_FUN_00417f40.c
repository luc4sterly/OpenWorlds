// 00417f40 FUN_00417f40 [Global]
// program: gamma.dll

/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_00417f40(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined2 *puVar12;
  undefined1 *puVar13;
  undefined2 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined1 *puVar17;
  int local_38;
  int local_28;
  int local_24 [5];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  if (param_1 != 0) {
    local_24[0] = 0;
    local_28 = 0;
    RwGetCameraRenderOffset(param_1,&local_28,local_24);
    local_24[4] = 0;
    local_24[3] = 0;
    local_24[1] = 0;
    local_24[2] = 0;
    RwGetCameraViewport(param_1,local_24 + 1,local_24 + 2,local_24 + 3,local_24 + 4);
    iVar4 = RwGetCameraRaster(param_1);
    if (iVar4 != 0) {
      iVar5 = RwGetRasterDepth(iVar4);
      uVar6 = RwGetRasterStride(iVar4);
      iVar7 = RwGetRasterPixels(iVar4);
      if (iVar7 != 0) {
        if (iVar5 == 0x10) {
          iVar5 = (int)((uVar6 + 1) - (uint)(uVar6 < 0x80000000)) >> 1;
          iVar10 = 0;
          puVar8 = (undefined2 *)(local_28 * 2 + local_24[0] * iVar5 * 2 + iVar7);
          if (0 < local_24[4]) {
            do {
              puVar14 = puVar8 + local_24[3] + -1;
              puVar12 = puVar8;
              if (puVar8 < puVar14) {
                do {
                  uVar2 = *puVar12;
                  *puVar12 = *puVar14;
                  *puVar14 = uVar2;
                  puVar14 = puVar14 + -1;
                  puVar12 = puVar12 + 1;
                } while (puVar12 < puVar14);
              }
              iVar10 = iVar10 + 1;
              puVar8 = puVar8 + iVar5;
            } while (iVar10 < local_24[4]);
          }
        }
        else if (iVar5 == 0x20) {
          iVar5 = (int)(uVar6 + ((int)uVar6 >> 0x1f & 3U)) >> 2;
          local_38 = 0;
          puVar16 = (undefined4 *)(local_28 * 4 + local_24[0] * iVar5 * 4 + iVar7);
          if (0 < local_24[4]) {
            do {
              puVar9 = puVar16 + local_24[3] + -1;
              puVar15 = puVar16;
              if (puVar16 < puVar9) {
                do {
                  uVar3 = *puVar15;
                  *puVar15 = *puVar9;
                  *puVar9 = uVar3;
                  puVar9 = puVar9 + -1;
                  puVar15 = puVar15 + 1;
                } while (puVar15 < puVar9);
              }
              local_38 = local_38 + 1;
              puVar16 = puVar16 + iVar5;
            } while (local_38 < local_24[4]);
          }
        }
        else if (iVar5 == 8) {
          iVar5 = 0;
          puVar11 = (undefined1 *)(local_24[0] * uVar6 + iVar7 + local_28);
          if (0 < local_24[4]) {
            do {
              puVar13 = puVar11 + local_24[3] + -1;
              puVar17 = puVar11;
              if (puVar11 < puVar13) {
                do {
                  uVar1 = *puVar17;
                  *puVar17 = *puVar13;
                  *puVar13 = uVar1;
                  puVar13 = puVar13 + -1;
                  puVar17 = puVar17 + 1;
                } while (puVar17 < puVar13);
              }
              iVar5 = iVar5 + 1;
              puVar11 = puVar11 + uVar6;
            } while (iVar5 < local_24[4]);
          }
        }
        RwReleaseRasterPixels(iVar4,iVar7);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


