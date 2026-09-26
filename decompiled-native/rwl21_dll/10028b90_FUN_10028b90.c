// 10028b90 FUN_10028b90 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10028b90(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  byte bVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  byte bVar12;
  int iVar13;
  int *piVar14;
  undefined4 *puVar15;
  int *piVar16;
  ushort uVar17;
  longlong lVar18;
  undefined8 uVar19;
  undefined8 uVar20;
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
  undefined4 uStack_e80;
  
  uVar7 = uStack_e80;
  piStack_f54 = param_1 + 0xf;
  piVar14 = param_1 + 0x10;
  iStack_f4c = *(byte *)((int)param_1 + 0x3a) - 1;
  bVar12 = *(byte *)(*piStack_f54 + 0x48) & 0x3f;
  iVar13 = iStack_f4c;
  bVar8 = bVar12;
  if (0 < iStack_f4c) {
    do {
      iVar1 = *piVar14;
      piVar14 = piVar14 + 1;
      bVar10 = *(byte *)(iVar1 + 0x48) & 0x3f;
      bVar8 = bVar8 & bVar10;
      bVar12 = bVar12 | bVar10;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  uStack_e80._0_2_ = (ushort)bVar12;
  uStack_e80._2_2_ = SUB42(uVar7,2);
  uStack_e80 = CONCAT22(uStack_e80._2_2_,(ushort)uStack_e80) & 0xffff000c;
  uVar11 = (uint)bVar8 << 8 | bVar12 & 0xc;
  if (bVar8 == 0) {
    pcVar2 = *(code **)(DAT_1005ad24 + ((bVar12 & 0xf) & 0xfffffff3) * 4);
    if ((bVar12 & 0xc) != 0) {
      puVar15 = &uStack_e80;
      piStack_f60 = aiStack_f08;
      iVar13 = piStack_f54[iStack_f4c];
      bStack_f6d = *(byte *)(iVar13 + 0x48) & 0xc;
      fStack_f58 = _DAT_1005222c - *(float *)(iVar13 + 0x10);
      do {
        iVar1 = *piStack_f54;
        fVar6 = _DAT_1005222c - *(float *)(iVar1 + 0x10);
        bVar8 = *(byte *)(iVar1 + 0x48);
        bVar12 = bVar8 & 0xc;
        if ((bStack_f6d & bVar12) == 0) {
          if (bStack_f6d != 0) {
            if ((bStack_f6d & 4) == 0) {
              fVar5 = fVar6 / (fVar6 - fStack_f58);
              lVar18 = __ftol();
              iVar9 = (int)lVar18;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar1 + 0x68);
                uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar1 + 100);
                uVar20 = rwFixMul(iVar9,*(int *)(iVar13 + 100) - iVar4);
                puVar15[0x1a] = iVar3 + (int)uVar19;
                puVar15[0x19] = iVar4 + (int)uVar20;
              }
              iVar3 = *(int *)(iVar1 + 0x58);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 0x58) - iVar3);
              puVar15[0x16] = (int)uVar19 + iVar3;
              iVar3 = *(int *)(iVar1 + 0x5c);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 0x5c) - iVar3);
              puVar15[0x17] = (int)uVar19 + iVar3;
              iVar3 = *(int *)(iVar1 + 0x60);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 0x60) - iVar3);
              puVar15[0x18] = (int)uVar19 + iVar3;
              puVar15[3] = (*(float *)(iVar13 + 0xc) - *(float *)(iVar1 + 0xc)) * fVar5 +
                           *(float *)(iVar1 + 0xc);
              puVar15[5] = (*(float *)(iVar13 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar5 +
                           *(float *)(iVar1 + 0x14);
              puVar15[4] = 0x3f800000;
              bVar10 = *(byte *)(iVar13 + 0x48) & 0xf8 | 8;
              *(byte *)(puVar15 + 0x12) = bVar10;
              if ((uint)puVar15[3] < 0x80000001) {
                if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                  fStack_f6c = (float)puVar15[5];
                }
                else {
                  fStack_f6c = 1.0;
                }
                uVar17 = (ushort)((float)puVar15[3] < fStack_f6c) << 8 |
                         (ushort)((float)puVar15[3] == fStack_f6c) << 0xe;
                goto LAB_10028eea;
              }
LAB_10028efd:
              *(byte *)(puVar15 + 0x12) = bVar10 | 1;
            }
            else {
              fVar5 = *(float *)(iVar1 + 0x10) /
                      (*(float *)(iVar1 + 0x10) - *(float *)(iVar13 + 0x10));
              lVar18 = __ftol();
              iVar9 = (int)lVar18;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar1 + 0x68);
                uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar1 + 100);
                uVar20 = rwFixMul(iVar9,*(int *)(iVar13 + 100) - iVar4);
                puVar15[0x1a] = iVar3 + (int)uVar19;
                puVar15[0x19] = iVar4 + (int)uVar20;
              }
              iVar3 = *(int *)(iVar1 + 0x58);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 0x58) - iVar3);
              puVar15[0x16] = (int)uVar19 + iVar3;
              iVar3 = *(int *)(iVar1 + 0x5c);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 0x5c) - iVar3);
              puVar15[0x17] = (int)uVar19 + iVar3;
              iVar3 = *(int *)(iVar1 + 0x60);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar13 + 0x60) - iVar3);
              puVar15[0x18] = (int)uVar19 + iVar3;
              puVar15[3] = (*(float *)(iVar13 + 0xc) - *(float *)(iVar1 + 0xc)) * fVar5 +
                           *(float *)(iVar1 + 0xc);
              puVar15[5] = (*(float *)(iVar13 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar5 +
                           *(float *)(iVar1 + 0x14);
              puVar15[4] = 0;
              bVar10 = *(byte *)(iVar13 + 0x48) & 0xf4 | 4;
              *(byte *)(puVar15 + 0x12) = bVar10;
              if (0x80000000 < (uint)puVar15[3]) goto LAB_10028efd;
              if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                fStack_f6c = (float)puVar15[5];
              }
              else {
                fStack_f6c = 1.0;
              }
              uVar17 = (ushort)((float)puVar15[3] < fStack_f6c) << 8 |
                       (ushort)((float)puVar15[3] == fStack_f6c) << 0xe;
LAB_10028eea:
              *(byte *)(puVar15 + 0x12) = (uVar17 != 0) - 1U & 2 | bVar10;
            }
            *piStack_f60 = (int)puVar15;
            puVar15 = puVar15 + 0x1d;
            piStack_f60 = piStack_f60 + 1;
          }
          if (bVar12 == 0) {
            *piStack_f60 = iVar1;
          }
          else {
            if ((bVar8 & 4) == 0) {
              fStack_f58 = fStack_f58 / (fStack_f58 - fVar6);
              lVar18 = __ftol();
              iVar9 = (int)lVar18;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar13 + 0x68);
                uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar13 + 100);
                uVar20 = rwFixMul(iVar9,*(int *)(iVar1 + 100) - iVar4);
                puVar15[0x1a] = iVar3 + (int)uVar19;
                puVar15[0x19] = iVar4 + (int)uVar20;
              }
              uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 0x58) - *(int *)(iVar13 + 0x58));
              puVar15[0x16] = *(int *)(iVar13 + 0x58) + (int)uVar19;
              uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 0x5c) - *(int *)(iVar13 + 0x5c));
              puVar15[0x17] = *(int *)(iVar13 + 0x5c) + (int)uVar19;
              uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 0x60) - *(int *)(iVar13 + 0x60));
              puVar15[0x18] = *(int *)(iVar13 + 0x60) + (int)uVar19;
              puVar15[3] = (*(float *)(iVar1 + 0xc) - *(float *)(iVar13 + 0xc)) * fStack_f58 +
                           *(float *)(iVar13 + 0xc);
              puVar15[5] = (*(float *)(iVar1 + 0x14) - *(float *)(iVar13 + 0x14)) * fStack_f58 +
                           *(float *)(iVar13 + 0x14);
              puVar15[4] = 0x3f800000;
              bVar8 = *(byte *)(iVar1 + 0x48) & 0xf8 | 8;
              *(byte *)(puVar15 + 0x12) = bVar8;
              if ((uint)puVar15[3] < 0x80000001) {
                if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                  fStack_f6c = (float)puVar15[5];
                }
                else {
                  fStack_f6c = 1.0;
                }
                uVar17 = (ushort)((float)puVar15[3] < fStack_f6c) << 8 |
                         (ushort)((float)puVar15[3] == fStack_f6c) << 0xe;
                goto LAB_10029169;
              }
LAB_1002917c:
              *(byte *)(puVar15 + 0x12) = bVar8 | 1;
            }
            else {
              fVar5 = *(float *)(iVar13 + 0x10) /
                      (*(float *)(iVar13 + 0x10) - *(float *)(iVar1 + 0x10));
              lVar18 = __ftol();
              iVar9 = (int)lVar18;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar13 + 0x68);
                uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar13 + 100);
                uVar20 = rwFixMul(iVar9,*(int *)(iVar1 + 100) - iVar4);
                puVar15[0x1a] = iVar3 + (int)uVar19;
                puVar15[0x19] = iVar4 + (int)uVar20;
              }
              iVar3 = *(int *)(iVar13 + 0x58);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 0x58) - iVar3);
              puVar15[0x16] = (int)uVar19 + iVar3;
              iVar3 = *(int *)(iVar13 + 0x5c);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 0x5c) - iVar3);
              puVar15[0x17] = (int)uVar19 + iVar3;
              iVar3 = *(int *)(iVar13 + 0x60);
              uVar19 = rwFixMul(iVar9,*(int *)(iVar1 + 0x60) - iVar3);
              puVar15[0x18] = (int)uVar19 + iVar3;
              puVar15[3] = (*(float *)(iVar1 + 0xc) - *(float *)(iVar13 + 0xc)) * fVar5 +
                           *(float *)(iVar13 + 0xc);
              puVar15[5] = (*(float *)(iVar1 + 0x14) - *(float *)(iVar13 + 0x14)) * fVar5 +
                           *(float *)(iVar13 + 0x14);
              puVar15[4] = 0;
              bVar8 = *(byte *)(iVar1 + 0x48) & 0xf4 | 4;
              *(byte *)(puVar15 + 0x12) = bVar8;
              if (0x80000000 < (uint)puVar15[3]) goto LAB_1002917c;
              if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                fStack_f6c = (float)puVar15[5];
              }
              else {
                fStack_f6c = 1.0;
              }
              uVar17 = (ushort)((float)puVar15[3] < fStack_f6c) << 8 |
                       (ushort)((float)puVar15[3] == fStack_f6c) << 0xe;
LAB_10029169:
              *(byte *)(puVar15 + 0x12) = (uVar17 != 0) - 1U & 2 | bVar8;
            }
            *piStack_f60 = (int)puVar15;
            puVar15 = puVar15 + 0x1d;
          }
          piStack_f60 = piStack_f60 + 1;
        }
        iStack_f4c = iStack_f4c + -1;
        iVar13 = iVar1;
        bStack_f6d = bVar12;
        fStack_f58 = fVar6;
        piStack_f54 = piStack_f54 + 1;
      } while (-1 < iStack_f4c);
      piVar14 = param_1;
      piVar16 = aiStack_f44;
      for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *piVar16 = *piVar14;
        piVar14 = piVar14 + 1;
        piVar16 = piVar16 + 1;
      }
      uStack_f0a = (undefined1)((int)piStack_f60 - (int)aiStack_f08 >> 2);
      iStack_f18 = param_1[0xb];
      uStack_f14 = 0;
      iStack_f10 = param_1[0xd];
      param_1 = aiStack_f44;
    }
    uVar11 = (*pcVar2)(param_1);
    uVar11 = (uint)piStack_f60 | uVar11;
  }
  return uVar11;
}


