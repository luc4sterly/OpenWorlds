// 10027a90 FUN_10027a90 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10027a90(int *param_1)

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
  longlong lVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  byte bStack_f6d;
  int *piStack_f68;
  float fStack_f60;
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
  auStack_e80[0] = bVar11 & 0xffffff03;
  uVar8 = (uint)bVar10 << 8 | auStack_e80[0];
  if (bVar10 == 0) {
    pcVar2 = (code *)*DAT_1005ad24;
    if ((bVar11 & 3) != 0) {
      puVar12 = auStack_e80;
      piStack_f68 = aiStack_f08;
      iVar13 = piStack_f54[iStack_f4c];
      bStack_f6d = *(byte *)(iVar13 + 0x48) & 3;
      fStack_f60 = _DAT_1005222c - *(float *)(iVar13 + 0xc);
      do {
        iVar1 = *piStack_f54;
        fVar6 = _DAT_1005222c - *(float *)(iVar1 + 0xc);
        bVar11 = *(byte *)(iVar1 + 0x48) & 3;
        if ((bStack_f6d & bVar11) == 0) {
          if (bStack_f6d != 0) {
            fVar5 = fVar6 / (fVar6 - fStack_f60);
            lVar16 = __ftol();
            iVar9 = (int)lVar16;
            if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
              iVar3 = *(int *)(iVar1 + 0x68);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar13 + 0x68) - iVar3);
              iVar4 = *(int *)(iVar1 + 100);
              uVar18 = rwFixMul(iVar9,*(int *)(iVar13 + 100) - iVar4);
              puVar12[0x1a] = iVar3 + (int)uVar17;
              puVar12[0x19] = iVar4 + (int)uVar18;
            }
            iVar3 = *(int *)(iVar1 + 0x58);
            uVar17 = rwFixMul(iVar9,*(int *)(iVar13 + 0x58) - iVar3);
            puVar12[0x16] = (int)uVar17 + iVar3;
            iVar3 = *(int *)(iVar1 + 0x5c);
            uVar17 = rwFixMul(iVar9,*(int *)(iVar13 + 0x5c) - iVar3);
            puVar12[0x17] = (int)uVar17 + iVar3;
            iVar3 = *(int *)(iVar1 + 0x60);
            uVar17 = rwFixMul(iVar9,*(int *)(iVar13 + 0x60) - iVar3);
            puVar12[0x18] = (int)uVar17 + iVar3;
            puVar12[4] = (uint)((*(float *)(iVar13 + 0x10) - *(float *)(iVar1 + 0x10)) * fVar5 +
                               *(float *)(iVar1 + 0x10));
            puVar12[5] = (uint)((*(float *)(iVar13 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar5 +
                               *(float *)(iVar1 + 0x14));
            puVar12[3] = 0x3f800000;
            *(byte *)(puVar12 + 0x12) = *(byte *)(iVar13 + 0x48) & 0xfe | 2;
            *piStack_f68 = (int)puVar12;
            puVar12 = puVar12 + 0x1d;
            piStack_f68 = piStack_f68 + 1;
          }
          if (bVar11 == 0) {
            *piStack_f68 = iVar1;
            piStack_f68 = piStack_f68 + 1;
          }
          else {
            fStack_f60 = fStack_f60 / (fStack_f60 - fVar6);
            lVar16 = __ftol();
            iVar9 = (int)lVar16;
            if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
              iVar3 = *(int *)(iVar13 + 0x68);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x68) - iVar3);
              iVar4 = *(int *)(iVar13 + 100);
              uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 100) - iVar4);
              puVar12[0x1a] = iVar3 + (int)uVar17;
              puVar12[0x19] = iVar4 + (int)uVar18;
            }
            iVar3 = *(int *)(iVar13 + 0x58);
            uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x58) - iVar3);
            puVar12[0x16] = (int)uVar17 + iVar3;
            iVar3 = *(int *)(iVar13 + 0x5c);
            uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x5c) - iVar3);
            puVar12[0x17] = (int)uVar17 + iVar3;
            iVar3 = *(int *)(iVar13 + 0x60);
            uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x60) - iVar3);
            puVar12[0x18] = (int)uVar17 + iVar3;
            puVar12[4] = (uint)((*(float *)(iVar1 + 0x10) - *(float *)(iVar13 + 0x10)) * fStack_f60
                               + *(float *)(iVar13 + 0x10));
            puVar12[5] = (uint)((*(float *)(iVar1 + 0x14) - *(float *)(iVar13 + 0x14)) * fStack_f60
                               + *(float *)(iVar13 + 0x14));
            puVar12[3] = 0x3f800000;
            *(byte *)(puVar12 + 0x12) = *(byte *)(iVar1 + 0x48) & 0xfe | 2;
            *piStack_f68 = (int)puVar12;
            puVar12 = puVar12 + 0x1d;
            piStack_f68 = piStack_f68 + 1;
          }
        }
        iStack_f4c = iStack_f4c + -1;
        iVar13 = iVar1;
        bStack_f6d = bVar11;
        fStack_f60 = fVar6;
        piStack_f54 = piStack_f54 + 1;
      } while (-1 < iStack_f4c);
      piVar14 = param_1;
      piVar15 = aiStack_f44;
      for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *piVar15 = *piVar14;
        piVar14 = piVar14 + 1;
        piVar15 = piVar15 + 1;
      }
      uStack_f0a = (undefined1)((int)piStack_f68 - (int)aiStack_f08 >> 2);
      iStack_f18 = param_1[0xb];
      uStack_f14 = 0;
      iStack_f10 = param_1[0xd];
      param_1 = aiStack_f44;
    }
    uVar8 = (*pcVar2)(param_1);
    uVar8 = (uint)piStack_f68 | uVar8;
  }
  return uVar8;
}


