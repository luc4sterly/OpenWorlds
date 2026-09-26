// 1002a150 FUN_1002a150 [Global]
// programa: RWL21.DLL

uint FUN_1002a150(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  byte bVar10;
  byte bVar11;
  uint *puVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  ushort uVar16;
  longlong lVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  byte bStack_f6d;
  float fStack_f6c;
  int *piStack_f60;
  float fStack_f58;
  int *piStack_f54;
  int iStack_f4c;
  int aiStack_f44 [11];
  int iStack_f18;
  undefined4 uStack_f14;
  int iStack_f10;
  undefined1 uStack_f0a;
  int aiStack_f08 [34];
  uint auStack_e80 [928];
  
  piStack_f54 = param_1 + 0xf;
  piVar14 = param_1 + 0x10;
  bVar10 = *(byte *)(*piStack_f54 + 0x48) & 0x3f;
  iStack_f4c = *(byte *)((int)param_1 + 0x3a) - 1;
  iVar13 = iStack_f4c;
  bVar11 = bVar10;
  if (0 < iStack_f4c) {
    do {
      iVar1 = *piVar14;
      piVar14 = piVar14 + 1;
      bVar7 = *(byte *)(iVar1 + 0x48) & 0x3f;
      bVar10 = bVar10 & bVar7;
      bVar11 = bVar11 | bVar7;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  auStack_e80[0] = (uint)bVar10;
  uVar8 = bVar11 & 0xc | auStack_e80[0] << 8;
  if (bVar10 == 0) {
    pcVar2 = *(code **)(DAT_1005ad24 + ((bVar11 & 0xf) & 0xfffffff3) * 4);
    auStack_e80[0] = 0;
    if ((bVar11 & 0xc) != 0) {
      puVar12 = auStack_e80;
      piStack_f60 = aiStack_f08;
      iVar13 = piStack_f54[iStack_f4c];
      bStack_f6d = *(byte *)(iVar13 + 0x48) & 0xc;
      fStack_f58 = *(float *)(iVar13 + 0x14) - *(float *)(iVar13 + 0x10);
      do {
        iVar1 = *piStack_f54;
        fVar5 = *(float *)(iVar1 + 0x14) - *(float *)(iVar1 + 0x10);
        bVar11 = *(byte *)(iVar1 + 0x48);
        bVar10 = bVar11 & 0xc;
        if ((bStack_f6d & bVar10) == 0) {
          if (bStack_f6d != 0) {
            if ((bStack_f6d & 4) == 0) {
              fVar6 = fVar5 / (fVar5 - fStack_f58);
              lVar17 = __ftol();
              iVar9 = (int)lVar17;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar1 + 0x68);
                uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar1 + 100);
                uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 100) - iVar4);
                puVar12[0x1a] = iVar3 + (int)uVar18;
                puVar12[0x19] = iVar4 + (int)uVar19;
              }
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x58) - *(int *)(iVar1 + 0x58));
              puVar12[0x16] = *(int *)(iVar1 + 0x58) + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x5c) - *(int *)(iVar1 + 0x5c));
              puVar12[0x17] = *(int *)(iVar1 + 0x5c) + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x60) - *(int *)(iVar1 + 0x60));
              puVar12[0x18] = *(int *)(iVar1 + 0x60) + (int)uVar18;
              puVar12[3] = (uint)((*(float *)(iVar13 + 0xc) - *(float *)(iVar1 + 0xc)) * fVar6 +
                                 *(float *)(iVar1 + 0xc));
              puVar12[5] = (uint)((*(float *)(iVar13 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar6 +
                                 *(float *)(iVar1 + 0x14));
              puVar12[4] = puVar12[5];
              bVar7 = *(byte *)(iVar13 + 0x48) & 0xf8 | 8;
              *(byte *)(puVar12 + 0x12) = bVar7;
              if (puVar12[3] < 0x80000001) {
                if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                  fStack_f6c = (float)puVar12[5];
                }
                else {
                  fStack_f6c = 1.0;
                }
                uVar16 = (ushort)((float)puVar12[3] < fStack_f6c) << 8 |
                         (ushort)((float)puVar12[3] == fStack_f6c) << 0xe;
                goto LAB_1002a4ac;
              }
LAB_1002a4bf:
              *(byte *)(puVar12 + 0x12) = bVar7 | 1;
            }
            else {
              fVar6 = *(float *)(iVar1 + 0x10) /
                      (*(float *)(iVar1 + 0x10) - *(float *)(iVar13 + 0x10));
              lVar17 = __ftol();
              iVar9 = (int)lVar17;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar1 + 0x68);
                uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar1 + 100);
                uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 100) - iVar4);
                puVar12[0x1a] = iVar3 + (int)uVar18;
                puVar12[0x19] = iVar4 + (int)uVar19;
              }
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x58) - *(int *)(iVar1 + 0x58));
              puVar12[0x16] = *(int *)(iVar1 + 0x58) + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x5c) - *(int *)(iVar1 + 0x5c));
              puVar12[0x17] = *(int *)(iVar1 + 0x5c) + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x60) - *(int *)(iVar1 + 0x60));
              puVar12[0x18] = *(int *)(iVar1 + 0x60) + (int)uVar18;
              puVar12[3] = (uint)((*(float *)(iVar13 + 0xc) - *(float *)(iVar1 + 0xc)) * fVar6 +
                                 *(float *)(iVar1 + 0xc));
              puVar12[5] = (uint)((*(float *)(iVar13 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar6 +
                                 *(float *)(iVar1 + 0x14));
              puVar12[4] = 0;
              bVar7 = *(byte *)(iVar13 + 0x48) & 0xf4 | 4;
              *(byte *)(puVar12 + 0x12) = bVar7;
              if (0x80000000 < puVar12[3]) goto LAB_1002a4bf;
              if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                fStack_f6c = (float)puVar12[5];
              }
              else {
                fStack_f6c = 1.0;
              }
              uVar16 = (ushort)((float)puVar12[3] < fStack_f6c) << 8 |
                       (ushort)((float)puVar12[3] == fStack_f6c) << 0xe;
LAB_1002a4ac:
              *(byte *)(puVar12 + 0x12) = (uVar16 != 0) - 1U & 2 | bVar7;
            }
            *piStack_f60 = (int)puVar12;
            puVar12 = puVar12 + 0x1d;
            piStack_f60 = piStack_f60 + 1;
          }
          if (bVar10 == 0) {
            *piStack_f60 = iVar1;
          }
          else {
            if ((bVar11 & 4) == 0) {
              fStack_f58 = fStack_f58 / (fStack_f58 - fVar5);
              lVar17 = __ftol();
              iVar9 = (int)lVar17;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar13 + 0x68);
                uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar13 + 100);
                uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 100) - iVar4);
                puVar12[0x1a] = iVar3 + (int)uVar18;
                puVar12[0x19] = iVar4 + (int)uVar19;
              }
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x58) - *(int *)(iVar13 + 0x58));
              puVar12[0x16] = *(int *)(iVar13 + 0x58) + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x5c) - *(int *)(iVar13 + 0x5c));
              puVar12[0x17] = *(int *)(iVar13 + 0x5c) + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x60) - *(int *)(iVar13 + 0x60));
              puVar12[0x18] = *(int *)(iVar13 + 0x60) + (int)uVar18;
              puVar12[3] = (uint)((*(float *)(iVar1 + 0xc) - *(float *)(iVar13 + 0xc)) * fStack_f58
                                 + *(float *)(iVar13 + 0xc));
              puVar12[5] = (uint)((*(float *)(iVar1 + 0x14) - *(float *)(iVar13 + 0x14)) *
                                  fStack_f58 + *(float *)(iVar13 + 0x14));
              puVar12[4] = puVar12[5];
              bVar11 = *(byte *)(iVar1 + 0x48) & 0xf8 | 8;
              *(byte *)(puVar12 + 0x12) = bVar11;
              if (puVar12[3] < 0x80000001) {
                if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                  fStack_f6c = (float)puVar12[5];
                }
                else {
                  fStack_f6c = 1.0;
                }
                uVar16 = (ushort)((float)puVar12[3] < fStack_f6c) << 8 |
                         (ushort)((float)puVar12[3] == fStack_f6c) << 0xe;
                goto LAB_1002a72d;
              }
LAB_1002a740:
              *(byte *)(puVar12 + 0x12) = bVar11 | 1;
            }
            else {
              fVar6 = *(float *)(iVar13 + 0x10) /
                      (*(float *)(iVar13 + 0x10) - *(float *)(iVar1 + 0x10));
              lVar17 = __ftol();
              iVar9 = (int)lVar17;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar13 + 0x68);
                uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar13 + 100);
                uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 100) - iVar4);
                puVar12[0x1a] = iVar3 + (int)uVar18;
                puVar12[0x19] = iVar4 + (int)uVar19;
              }
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x58) - *(int *)(iVar13 + 0x58));
              puVar12[0x16] = *(int *)(iVar13 + 0x58) + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x5c) - *(int *)(iVar13 + 0x5c));
              puVar12[0x17] = *(int *)(iVar13 + 0x5c) + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x60) - *(int *)(iVar13 + 0x60));
              puVar12[0x18] = *(int *)(iVar13 + 0x60) + (int)uVar18;
              puVar12[3] = (uint)((*(float *)(iVar1 + 0xc) - *(float *)(iVar13 + 0xc)) * fVar6 +
                                 *(float *)(iVar13 + 0xc));
              puVar12[5] = (uint)((*(float *)(iVar1 + 0x14) - *(float *)(iVar13 + 0x14)) * fVar6 +
                                 *(float *)(iVar13 + 0x14));
              puVar12[4] = 0;
              bVar11 = *(byte *)(iVar1 + 0x48) & 0xf4 | 4;
              *(byte *)(puVar12 + 0x12) = bVar11;
              if (0x80000000 < puVar12[3]) goto LAB_1002a740;
              if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                fStack_f6c = (float)puVar12[5];
              }
              else {
                fStack_f6c = 1.0;
              }
              uVar16 = (ushort)((float)puVar12[3] < fStack_f6c) << 8 |
                       (ushort)((float)puVar12[3] == fStack_f6c) << 0xe;
LAB_1002a72d:
              *(byte *)(puVar12 + 0x12) = (uVar16 != 0) - 1U & 2 | bVar11;
            }
            *piStack_f60 = (int)puVar12;
            puVar12 = puVar12 + 0x1d;
          }
          piStack_f60 = piStack_f60 + 1;
        }
        iStack_f4c = iStack_f4c + -1;
        iVar13 = iVar1;
        bStack_f6d = bVar10;
        fStack_f58 = fVar5;
        piStack_f54 = piStack_f54 + 1;
      } while (-1 < iStack_f4c);
      piVar14 = param_1;
      piVar15 = aiStack_f44;
      for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *piVar15 = *piVar14;
        piVar14 = piVar14 + 1;
        piVar15 = piVar15 + 1;
      }
      uStack_f0a = (undefined1)((int)piStack_f60 - (int)aiStack_f08 >> 2);
      iStack_f18 = param_1[0xb];
      uStack_f14 = 0;
      iStack_f10 = param_1[0xd];
      param_1 = aiStack_f44;
    }
    uVar8 = (*pcVar2)(param_1);
    uVar8 = (uint)piStack_f60 | uVar8;
  }
  return uVar8;
}


