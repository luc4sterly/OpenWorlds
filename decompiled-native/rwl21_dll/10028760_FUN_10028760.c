// 10028760 FUN_10028760 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10028760(int *param_1)

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
  longlong lVar17;
  undefined8 uVar18;
  byte bStack_f6d;
  float fStack_f6c;
  int *piStack_f68;
  uint uStack_f64;
  float fStack_f5c;
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
      piStack_f68 = aiStack_f08;
      iVar13 = piStack_f54[iStack_f4c];
      bStack_f6d = *(byte *)(iVar13 + 0x48) & 0xc;
      fStack_f5c = _DAT_1005222c - *(float *)(iVar13 + 0x10);
      do {
        iVar1 = *piStack_f54;
        fVar6 = _DAT_1005222c - *(float *)(iVar1 + 0x10);
        bVar8 = *(byte *)(iVar1 + 0x48) & 0xc;
        if ((bStack_f6d & bVar8) == 0) {
          if (bStack_f6d != 0) {
            fVar5 = fVar6 / (fVar6 - fStack_f5c);
            lVar17 = __ftol();
            iVar9 = (int)lVar17;
            if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
              iVar3 = *(int *)(iVar1 + 0x68);
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x68) - iVar3);
              iVar4 = *(int *)(iVar1 + 100);
              uStack_f64 = iVar3 + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 100) - iVar4);
              puVar15[0x1a] = uStack_f64;
              puVar15[0x19] = iVar4 + (int)uVar18;
            }
            uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x58) - *(int *)(iVar1 + 0x58));
            puVar15[0x16] = *(int *)(iVar1 + 0x58) + (int)uVar18;
            uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x5c) - *(int *)(iVar1 + 0x5c));
            puVar15[0x17] = *(int *)(iVar1 + 0x5c) + (int)uVar18;
            uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 0x60) - *(int *)(iVar1 + 0x60));
            puVar15[0x18] = *(int *)(iVar1 + 0x60) + (int)uVar18;
            puVar15[3] = (*(float *)(iVar13 + 0xc) - *(float *)(iVar1 + 0xc)) * fVar5 +
                         *(float *)(iVar1 + 0xc);
            puVar15[5] = (*(float *)(iVar13 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar5 +
                         *(float *)(iVar1 + 0x14);
            puVar15[4] = 0x3f800000;
            bVar12 = *(byte *)(iVar13 + 0x48) & 0xf8;
            bVar10 = bVar12 | 8;
            *(byte *)(puVar15 + 0x12) = bVar10;
            if ((uint)puVar15[3] < 0x80000001) {
              if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                fStack_f6c = (float)puVar15[5];
              }
              else {
                fStack_f6c = 1.0;
              }
              *(byte *)(puVar15 + 0x12) = ((float)puVar15[3] <= fStack_f6c) - 1U & 2 | bVar10;
            }
            else {
              *(byte *)(puVar15 + 0x12) = bVar12 | 9;
            }
            *piStack_f68 = (int)puVar15;
            puVar15 = puVar15 + 0x1d;
            piStack_f68 = piStack_f68 + 1;
          }
          if (bVar8 == 0) {
            *piStack_f68 = iVar1;
          }
          else {
            fStack_f5c = fStack_f5c / (fStack_f5c - fVar6);
            lVar17 = __ftol();
            iVar9 = (int)lVar17;
            if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
              iVar3 = *(int *)(iVar13 + 0x68);
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x68) - iVar3);
              iVar4 = *(int *)(iVar13 + 100);
              uStack_f64 = iVar3 + (int)uVar18;
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 100) - iVar4);
              puVar15[0x1a] = uStack_f64;
              puVar15[0x19] = iVar4 + (int)uVar18;
            }
            uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x58) - *(int *)(iVar13 + 0x58));
            puVar15[0x16] = *(int *)(iVar13 + 0x58) + (int)uVar18;
            uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x5c) - *(int *)(iVar13 + 0x5c));
            puVar15[0x17] = *(int *)(iVar13 + 0x5c) + (int)uVar18;
            uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 0x60) - *(int *)(iVar13 + 0x60));
            puVar15[0x18] = *(int *)(iVar13 + 0x60) + (int)uVar18;
            puVar15[3] = (*(float *)(iVar1 + 0xc) - *(float *)(iVar13 + 0xc)) * fStack_f5c +
                         *(float *)(iVar13 + 0xc);
            puVar15[5] = (*(float *)(iVar1 + 0x14) - *(float *)(iVar13 + 0x14)) * fStack_f5c +
                         *(float *)(iVar13 + 0x14);
            puVar15[4] = 0x3f800000;
            bVar12 = *(byte *)(iVar1 + 0x48) & 0xf8;
            bVar10 = bVar12 | 8;
            *(byte *)(puVar15 + 0x12) = bVar10;
            if ((uint)puVar15[3] < 0x80000001) {
              if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                fStack_f6c = (float)puVar15[5];
              }
              else {
                fStack_f6c = 1.0;
              }
              *(byte *)(puVar15 + 0x12) = ((float)puVar15[3] <= fStack_f6c) - 1U & 2 | bVar10;
            }
            else {
              *(byte *)(puVar15 + 0x12) = bVar12 | 9;
            }
            *piStack_f68 = (int)puVar15;
            puVar15 = puVar15 + 0x1d;
          }
          piStack_f68 = piStack_f68 + 1;
        }
        iStack_f4c = iStack_f4c + -1;
        iVar13 = iVar1;
        bStack_f6d = bVar8;
        fStack_f5c = fVar6;
        piStack_f54 = piStack_f54 + 1;
      } while (-1 < iStack_f4c);
      piVar14 = param_1;
      piVar16 = aiStack_f44;
      for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *piVar16 = *piVar14;
        piVar14 = piVar14 + 1;
        piVar16 = piVar16 + 1;
      }
      uStack_f0a = (undefined1)((int)piStack_f68 - (int)aiStack_f08 >> 2);
      iStack_f18 = param_1[0xb];
      uStack_f14 = 0;
      iStack_f10 = param_1[0xd];
      param_1 = aiStack_f44;
    }
    uVar11 = (*pcVar2)(param_1);
    uVar11 = uStack_f64 | uVar11;
  }
  return uVar11;
}


