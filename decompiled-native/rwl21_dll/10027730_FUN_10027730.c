// 10027730 FUN_10027730 [Global]
// program: RWL21.DLL

uint FUN_10027730(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  uint *puVar12;
  int *piVar13;
  int *piVar14;
  longlong lVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  byte bStack_f65;
  int *piStack_f60;
  int *piStack_f50;
  int iStack_f4c;
  int aiStack_f44 [11];
  int iStack_f18;
  undefined4 uStack_f14;
  int iStack_f10;
  undefined1 uStack_f0a;
  int aiStack_f08 [34];
  uint auStack_e80 [928];
  
  piVar13 = param_1 + 0x10;
  bVar9 = *(byte *)(param_1[0xf] + 0x48) & 0x3f;
  iStack_f4c = *(byte *)((int)param_1 + 0x3a) - 1;
  iVar11 = iStack_f4c;
  bVar10 = bVar9;
  if (0 < iStack_f4c) {
    do {
      iVar1 = *piVar13;
      piVar13 = piVar13 + 1;
      bVar6 = *(byte *)(iVar1 + 0x48) & 0x3f;
      bVar9 = bVar9 & bVar6;
      bVar10 = bVar10 | bVar6;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  auStack_e80[0] = bVar10 & 0xffffff03;
  uVar7 = (uint)bVar9 << 8 | auStack_e80[0];
  if (bVar9 == 0) {
    pcVar2 = (code *)*DAT_1005ad24;
    if ((bVar10 & 3) != 0) {
      puVar12 = auStack_e80;
      piStack_f60 = aiStack_f08;
      iVar11 = (param_1 + 0xf)[iStack_f4c];
      bStack_f65 = *(byte *)(iVar11 + 0x48) & 3;
      piStack_f50 = param_1 + 0xf;
      do {
        iVar1 = *piStack_f50;
        bVar10 = *(byte *)(iVar1 + 0x48) & 3;
        if ((bStack_f65 & bVar10) == 0) {
          if (bStack_f65 != 0) {
            fVar5 = *(float *)(iVar1 + 0xc) / (*(float *)(iVar1 + 0xc) - *(float *)(iVar11 + 0xc));
            lVar15 = __ftol();
            iVar8 = (int)lVar15;
            if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
              iVar3 = *(int *)(iVar1 + 0x68);
              uVar16 = rwFixMul(iVar8,*(int *)(iVar11 + 0x68) - iVar3);
              iVar4 = *(int *)(iVar1 + 100);
              uVar17 = rwFixMul(iVar8,*(int *)(iVar11 + 100) - iVar4);
              puVar12[0x1a] = iVar3 + (int)uVar16;
              puVar12[0x19] = iVar4 + (int)uVar17;
            }
            iVar3 = *(int *)(iVar1 + 0x58);
            uVar16 = rwFixMul(iVar8,*(int *)(iVar11 + 0x58) - iVar3);
            puVar12[0x16] = (int)uVar16 + iVar3;
            iVar3 = *(int *)(iVar1 + 0x5c);
            uVar16 = rwFixMul(iVar8,*(int *)(iVar11 + 0x5c) - iVar3);
            puVar12[0x17] = (int)uVar16 + iVar3;
            iVar3 = *(int *)(iVar1 + 0x60);
            uVar16 = rwFixMul(iVar8,*(int *)(iVar11 + 0x60) - iVar3);
            puVar12[0x18] = (int)uVar16 + iVar3;
            puVar12[4] = (uint)((*(float *)(iVar11 + 0x10) - *(float *)(iVar1 + 0x10)) * fVar5 +
                               *(float *)(iVar1 + 0x10));
            puVar12[5] = (uint)((*(float *)(iVar11 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar5 +
                               *(float *)(iVar1 + 0x14));
            puVar12[3] = 0;
            *(byte *)(puVar12 + 0x12) = *(byte *)(iVar11 + 0x48) & 0xfd | 1;
            *piStack_f60 = (int)puVar12;
            puVar12 = puVar12 + 0x1d;
            piStack_f60 = piStack_f60 + 1;
          }
          if (bVar10 == 0) {
            *piStack_f60 = iVar1;
            piStack_f60 = piStack_f60 + 1;
          }
          else {
            fVar5 = *(float *)(iVar11 + 0xc) / (*(float *)(iVar11 + 0xc) - *(float *)(iVar1 + 0xc));
            lVar15 = __ftol();
            iVar8 = (int)lVar15;
            if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
              iVar3 = *(int *)(iVar11 + 0x68);
              uVar16 = rwFixMul(iVar8,*(int *)(iVar1 + 0x68) - iVar3);
              iVar4 = *(int *)(iVar11 + 100);
              uVar17 = rwFixMul(iVar8,*(int *)(iVar1 + 100) - iVar4);
              puVar12[0x1a] = iVar3 + (int)uVar16;
              puVar12[0x19] = iVar4 + (int)uVar17;
            }
            iVar3 = *(int *)(iVar11 + 0x58);
            uVar16 = rwFixMul(iVar8,*(int *)(iVar1 + 0x58) - iVar3);
            puVar12[0x16] = (int)uVar16 + iVar3;
            iVar3 = *(int *)(iVar11 + 0x5c);
            uVar16 = rwFixMul(iVar8,*(int *)(iVar1 + 0x5c) - iVar3);
            puVar12[0x17] = (int)uVar16 + iVar3;
            iVar3 = *(int *)(iVar11 + 0x60);
            uVar16 = rwFixMul(iVar8,*(int *)(iVar1 + 0x60) - iVar3);
            puVar12[0x18] = (int)uVar16 + iVar3;
            puVar12[4] = (uint)((*(float *)(iVar1 + 0x10) - *(float *)(iVar11 + 0x10)) * fVar5 +
                               *(float *)(iVar11 + 0x10));
            puVar12[5] = (uint)((*(float *)(iVar1 + 0x14) - *(float *)(iVar11 + 0x14)) * fVar5 +
                               *(float *)(iVar11 + 0x14));
            puVar12[3] = 0;
            *(byte *)(puVar12 + 0x12) = *(byte *)(iVar1 + 0x48) & 0xfd | 1;
            *piStack_f60 = (int)puVar12;
            puVar12 = puVar12 + 0x1d;
            piStack_f60 = piStack_f60 + 1;
          }
        }
        iStack_f4c = iStack_f4c + -1;
        iVar11 = iVar1;
        bStack_f65 = bVar10;
        piStack_f50 = piStack_f50 + 1;
      } while (-1 < iStack_f4c);
      piVar13 = param_1;
      piVar14 = aiStack_f44;
      for (iVar11 = 10; iVar11 != 0; iVar11 = iVar11 + -1) {
        *piVar14 = *piVar13;
        piVar13 = piVar13 + 1;
        piVar14 = piVar14 + 1;
      }
      uStack_f0a = (undefined1)((int)piStack_f60 - (int)aiStack_f08 >> 2);
      iStack_f18 = param_1[0xb];
      uStack_f14 = 0;
      iStack_f10 = param_1[0xd];
      param_1 = aiStack_f44;
    }
    uVar7 = (*pcVar2)(param_1);
    uVar7 = (uint)piStack_f60 | uVar7;
  }
  return uVar7;
}


