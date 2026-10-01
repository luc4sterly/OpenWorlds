// 100297e0 FUN_100297e0 [Global]
// program: RWL21.DLL

uint FUN_100297e0(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  uint *puVar14;
  int *piVar15;
  longlong lVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  byte bStack_f6d;
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
  
  piVar13 = param_1 + 0x10;
  iStack_f4c = *(byte *)((int)param_1 + 0x3a) - 1;
  bVar7 = *(byte *)(param_1[0xf] + 0x48) & 0x3f;
  iVar12 = iStack_f4c;
  bVar10 = bVar7;
  if (0 < iStack_f4c) {
    do {
      iVar1 = *piVar13;
      piVar13 = piVar13 + 1;
      bVar8 = *(byte *)(iVar1 + 0x48) & 0x3f;
      bVar7 = bVar7 & bVar8;
      bVar10 = bVar10 | bVar8;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  auStack_e80[0] = bVar10 & 0xffffff03;
  uVar11 = (uint)bVar7 << 8 | auStack_e80[0];
  if (bVar7 == 0) {
    pcVar2 = (code *)*DAT_1005ad24;
    if ((bVar10 & 3) != 0) {
      puVar14 = auStack_e80;
      piStack_f60 = aiStack_f08;
      iVar12 = (param_1 + 0xf)[iStack_f4c];
      bStack_f6d = *(byte *)(iVar12 + 0x48) & 3;
      fStack_f58 = *(float *)(iVar12 + 0x14) - *(float *)(iVar12 + 0xc);
      piStack_f54 = param_1 + 0xf;
      do {
        iVar1 = *piStack_f54;
        fVar5 = *(float *)(iVar1 + 0x14) - *(float *)(iVar1 + 0xc);
        bVar10 = *(byte *)(iVar1 + 0x48);
        bVar7 = bVar10 & 3;
        if ((bStack_f6d & bVar7) == 0) {
          if (bStack_f6d != 0) {
            if ((bStack_f6d & 1) == 0) {
              fVar6 = fVar5 / (fVar5 - fStack_f58);
              lVar16 = __ftol();
              iVar9 = (int)lVar16;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar1 + 0x68);
                uVar17 = rwFixMul(iVar9,*(int *)(iVar12 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar1 + 100);
                uVar18 = rwFixMul(iVar9,*(int *)(iVar12 + 100) - iVar4);
                puVar14[0x1a] = iVar3 + (int)uVar17;
                puVar14[0x19] = iVar4 + (int)uVar18;
              }
              iVar3 = *(int *)(iVar1 + 0x58);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar12 + 0x58) - iVar3);
              puVar14[0x16] = (int)uVar17 + iVar3;
              iVar3 = *(int *)(iVar1 + 0x5c);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar12 + 0x5c) - iVar3);
              puVar14[0x17] = (int)uVar17 + iVar3;
              iVar3 = *(int *)(iVar1 + 0x60);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar12 + 0x60) - iVar3);
              puVar14[0x18] = (int)uVar17 + iVar3;
              puVar14[4] = (uint)((*(float *)(iVar12 + 0x10) - *(float *)(iVar1 + 0x10)) * fVar6 +
                                 *(float *)(iVar1 + 0x10));
              fVar6 = (*(float *)(iVar12 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar6 +
                      *(float *)(iVar1 + 0x14);
              puVar14[5] = (uint)fVar6;
              puVar14[3] = (uint)fVar6;
              bVar8 = *(byte *)(iVar12 + 0x48) & 0xfe | 2;
            }
            else {
              fVar6 = *(float *)(iVar1 + 0xc) / (*(float *)(iVar1 + 0xc) - *(float *)(iVar12 + 0xc))
              ;
              lVar16 = __ftol();
              iVar9 = (int)lVar16;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar1 + 0x68);
                uVar17 = rwFixMul(iVar9,*(int *)(iVar12 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar1 + 100);
                uVar18 = rwFixMul(iVar9,*(int *)(iVar12 + 100) - iVar4);
                puVar14[0x1a] = iVar3 + (int)uVar17;
                puVar14[0x19] = iVar4 + (int)uVar18;
              }
              iVar3 = *(int *)(iVar1 + 0x58);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar12 + 0x58) - iVar3);
              puVar14[0x16] = (int)uVar17 + iVar3;
              iVar3 = *(int *)(iVar1 + 0x5c);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar12 + 0x5c) - iVar3);
              puVar14[0x17] = (int)uVar17 + iVar3;
              iVar3 = *(int *)(iVar1 + 0x60);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar12 + 0x60) - iVar3);
              puVar14[0x18] = (int)uVar17 + iVar3;
              puVar14[4] = (uint)((*(float *)(iVar12 + 0x10) - *(float *)(iVar1 + 0x10)) * fVar6 +
                                 *(float *)(iVar1 + 0x10));
              puVar14[5] = (uint)((*(float *)(iVar12 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar6 +
                                 *(float *)(iVar1 + 0x14));
              puVar14[3] = 0;
              bVar8 = *(byte *)(iVar12 + 0x48) & 0xfd | 1;
            }
            *(byte *)(puVar14 + 0x12) = bVar8;
            *piStack_f60 = (int)puVar14;
            puVar14 = puVar14 + 0x1d;
            piStack_f60 = piStack_f60 + 1;
          }
          if (bVar7 == 0) {
            *piStack_f60 = iVar1;
          }
          else {
            if ((bVar10 & 1) == 0) {
              fStack_f58 = fStack_f58 / (fStack_f58 - fVar5);
              lVar16 = __ftol();
              iVar9 = (int)lVar16;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar12 + 0x68);
                uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar12 + 100);
                uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 100) - iVar4);
                puVar14[0x1a] = iVar3 + (int)uVar17;
                puVar14[0x19] = iVar4 + (int)uVar18;
              }
              iVar3 = *(int *)(iVar12 + 0x58);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x58) - iVar3);
              puVar14[0x16] = (int)uVar17 + iVar3;
              iVar3 = *(int *)(iVar12 + 0x5c);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x5c) - iVar3);
              puVar14[0x17] = (int)uVar17 + iVar3;
              iVar3 = *(int *)(iVar12 + 0x60);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x60) - iVar3);
              puVar14[0x18] = (int)uVar17 + iVar3;
              puVar14[4] = (uint)((*(float *)(iVar1 + 0x10) - *(float *)(iVar12 + 0x10)) *
                                  fStack_f58 + *(float *)(iVar12 + 0x10));
              fVar6 = (*(float *)(iVar1 + 0x14) - *(float *)(iVar12 + 0x14)) * fStack_f58 +
                      *(float *)(iVar12 + 0x14);
              puVar14[5] = (uint)fVar6;
              puVar14[3] = (uint)fVar6;
              bVar10 = *(byte *)(iVar1 + 0x48) & 0xfe | 2;
            }
            else {
              fVar6 = *(float *)(iVar12 + 0xc) /
                      (*(float *)(iVar12 + 0xc) - *(float *)(iVar1 + 0xc));
              lVar16 = __ftol();
              iVar9 = (int)lVar16;
              if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
                iVar3 = *(int *)(iVar12 + 0x68);
                uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x68) - iVar3);
                iVar4 = *(int *)(iVar12 + 100);
                uVar18 = rwFixMul(iVar9,*(int *)(iVar1 + 100) - iVar4);
                puVar14[0x1a] = iVar3 + (int)uVar17;
                puVar14[0x19] = iVar4 + (int)uVar18;
              }
              iVar3 = *(int *)(iVar12 + 0x58);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x58) - iVar3);
              puVar14[0x16] = (int)uVar17 + iVar3;
              iVar3 = *(int *)(iVar12 + 0x5c);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x5c) - iVar3);
              puVar14[0x17] = (int)uVar17 + iVar3;
              iVar3 = *(int *)(iVar12 + 0x60);
              uVar17 = rwFixMul(iVar9,*(int *)(iVar1 + 0x60) - iVar3);
              puVar14[0x18] = (int)uVar17 + iVar3;
              puVar14[4] = (uint)((*(float *)(iVar1 + 0x10) - *(float *)(iVar12 + 0x10)) * fVar6 +
                                 *(float *)(iVar12 + 0x10));
              puVar14[5] = (uint)((*(float *)(iVar1 + 0x14) - *(float *)(iVar12 + 0x14)) * fVar6 +
                                 *(float *)(iVar12 + 0x14));
              puVar14[3] = 0;
              bVar10 = *(byte *)(iVar1 + 0x48) & 0xfd | 1;
            }
            *(byte *)(puVar14 + 0x12) = bVar10;
            *piStack_f60 = (int)puVar14;
            puVar14 = puVar14 + 0x1d;
          }
          piStack_f60 = piStack_f60 + 1;
        }
        iStack_f4c = iStack_f4c + -1;
        iVar12 = iVar1;
        bStack_f6d = bVar7;
        fStack_f58 = fVar5;
        piStack_f54 = piStack_f54 + 1;
      } while (-1 < iStack_f4c);
      piVar13 = param_1;
      piVar15 = aiStack_f44;
      for (iVar12 = 10; iVar12 != 0; iVar12 = iVar12 + -1) {
        *piVar15 = *piVar13;
        piVar13 = piVar13 + 1;
        piVar15 = piVar15 + 1;
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


