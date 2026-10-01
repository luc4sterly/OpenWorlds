// 10028360 FUN_10028360 [Global]
// program: RWL21.DLL

uint FUN_10028360(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  undefined4 uVar6;
  byte bVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  byte bVar11;
  undefined4 *puVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  longlong lVar16;
  undefined8 uVar17;
  byte bStack_f65;
  float fStack_f64;
  int *piStack_f60;
  uint uStack_f5c;
  int *piStack_f50;
  int iStack_f4c;
  int aiStack_f44 [11];
  int iStack_f18;
  undefined4 uStack_f14;
  int iStack_f10;
  undefined1 uStack_f0a;
  int aiStack_f08 [34];
  undefined4 uStack_e80;
  
  uVar6 = uStack_e80;
  piStack_f50 = param_1 + 0xf;
  piVar14 = param_1 + 0x10;
  iStack_f4c = *(byte *)((int)param_1 + 0x3a) - 1;
  bVar11 = *(byte *)(*piStack_f50 + 0x48) & 0x3f;
  iVar13 = iStack_f4c;
  bVar7 = bVar11;
  if (0 < iStack_f4c) {
    do {
      iVar1 = *piVar14;
      piVar14 = piVar14 + 1;
      bVar9 = *(byte *)(iVar1 + 0x48) & 0x3f;
      bVar7 = bVar7 & bVar9;
      bVar11 = bVar11 | bVar9;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  uStack_e80._0_2_ = (ushort)bVar11;
  uStack_e80._2_2_ = SUB42(uVar6,2);
  uStack_e80 = CONCAT22(uStack_e80._2_2_,(ushort)uStack_e80) & 0xffff000c;
  uVar10 = (uint)bVar7 << 8 | bVar11 & 0xc;
  if (bVar7 == 0) {
    pcVar2 = *(code **)(DAT_1005ad24 + ((bVar11 & 0xf) & 0xfffffff3) * 4);
    if ((bVar11 & 0xc) != 0) {
      puVar12 = &uStack_e80;
      piStack_f60 = aiStack_f08;
      iVar13 = piStack_f50[iStack_f4c];
      bStack_f65 = *(byte *)(piStack_f50[iStack_f4c] + 0x48) & 0xc;
      do {
        iVar1 = *piStack_f50;
        bVar7 = *(byte *)(iVar1 + 0x48) & 0xc;
        if ((bStack_f65 & bVar7) == 0) {
          if (bStack_f65 != 0) {
            fVar5 = *(float *)(iVar1 + 0x10) /
                    (*(float *)(iVar1 + 0x10) - *(float *)(iVar13 + 0x10));
            lVar16 = __ftol();
            iVar8 = (int)lVar16;
            if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
              iVar3 = *(int *)(iVar1 + 0x68);
              uVar17 = rwFixMul(iVar8,*(int *)(iVar13 + 0x68) - iVar3);
              iVar4 = *(int *)(iVar1 + 100);
              uStack_f5c = iVar3 + (int)uVar17;
              uVar17 = rwFixMul(iVar8,*(int *)(iVar13 + 100) - iVar4);
              puVar12[0x1a] = uStack_f5c;
              puVar12[0x19] = iVar4 + (int)uVar17;
            }
            uVar17 = rwFixMul(iVar8,*(int *)(iVar13 + 0x58) - *(int *)(iVar1 + 0x58));
            puVar12[0x16] = *(int *)(iVar1 + 0x58) + (int)uVar17;
            uVar17 = rwFixMul(iVar8,*(int *)(iVar13 + 0x5c) - *(int *)(iVar1 + 0x5c));
            puVar12[0x17] = *(int *)(iVar1 + 0x5c) + (int)uVar17;
            uVar17 = rwFixMul(iVar8,*(int *)(iVar13 + 0x60) - *(int *)(iVar1 + 0x60));
            puVar12[0x18] = *(int *)(iVar1 + 0x60) + (int)uVar17;
            puVar12[3] = (*(float *)(iVar13 + 0xc) - *(float *)(iVar1 + 0xc)) * fVar5 +
                         *(float *)(iVar1 + 0xc);
            puVar12[5] = (*(float *)(iVar13 + 0x14) - *(float *)(iVar1 + 0x14)) * fVar5 +
                         *(float *)(iVar1 + 0x14);
            puVar12[4] = 0;
            bVar11 = *(byte *)(iVar13 + 0x48) & 0xf4;
            bVar9 = bVar11 | 4;
            *(byte *)(puVar12 + 0x12) = bVar9;
            if ((uint)puVar12[3] < 0x80000001) {
              if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                fStack_f64 = (float)puVar12[5];
              }
              else {
                fStack_f64 = 1.0;
              }
              *(byte *)(puVar12 + 0x12) = ((float)puVar12[3] <= fStack_f64) - 1U & 2 | bVar9;
            }
            else {
              *(byte *)(puVar12 + 0x12) = bVar11 | 5;
            }
            *piStack_f60 = (int)puVar12;
            puVar12 = puVar12 + 0x1d;
            piStack_f60 = piStack_f60 + 1;
          }
          if (bVar7 == 0) {
            *piStack_f60 = iVar1;
          }
          else {
            fVar5 = *(float *)(iVar13 + 0x10) /
                    (*(float *)(iVar13 + 0x10) - *(float *)(iVar1 + 0x10));
            lVar16 = __ftol();
            iVar8 = (int)lVar16;
            if ((*param_1 != 0) && (*(int *)(*param_1 + 0x34) != 0)) {
              iVar3 = *(int *)(iVar13 + 0x68);
              uVar17 = rwFixMul(iVar8,*(int *)(iVar1 + 0x68) - iVar3);
              iVar4 = *(int *)(iVar13 + 100);
              uStack_f5c = iVar3 + (int)uVar17;
              uVar17 = rwFixMul(iVar8,*(int *)(iVar1 + 100) - iVar4);
              puVar12[0x1a] = uStack_f5c;
              puVar12[0x19] = iVar4 + (int)uVar17;
            }
            uVar17 = rwFixMul(iVar8,*(int *)(iVar1 + 0x58) - *(int *)(iVar13 + 0x58));
            puVar12[0x16] = *(int *)(iVar13 + 0x58) + (int)uVar17;
            uVar17 = rwFixMul(iVar8,*(int *)(iVar1 + 0x5c) - *(int *)(iVar13 + 0x5c));
            puVar12[0x17] = *(int *)(iVar13 + 0x5c) + (int)uVar17;
            uVar17 = rwFixMul(iVar8,*(int *)(iVar1 + 0x60) - *(int *)(iVar13 + 0x60));
            puVar12[0x18] = *(int *)(iVar13 + 0x60) + (int)uVar17;
            puVar12[3] = (*(float *)(iVar1 + 0xc) - *(float *)(iVar13 + 0xc)) * fVar5 +
                         *(float *)(iVar13 + 0xc);
            puVar12[5] = (*(float *)(iVar1 + 0x14) - *(float *)(iVar13 + 0x14)) * fVar5 +
                         *(float *)(iVar13 + 0x14);
            puVar12[4] = 0;
            bVar11 = *(byte *)(iVar1 + 0x48) & 0xf4;
            bVar9 = bVar11 | 4;
            *(byte *)(puVar12 + 0x12) = bVar9;
            if ((uint)puVar12[3] < 0x80000001) {
              if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
                fStack_f64 = (float)puVar12[5];
              }
              else {
                fStack_f64 = 1.0;
              }
              *(byte *)(puVar12 + 0x12) = ((float)puVar12[3] <= fStack_f64) - 1U & 2 | bVar9;
            }
            else {
              *(byte *)(puVar12 + 0x12) = bVar11 | 5;
            }
            *piStack_f60 = (int)puVar12;
            puVar12 = puVar12 + 0x1d;
          }
          piStack_f60 = piStack_f60 + 1;
        }
        iStack_f4c = iStack_f4c + -1;
        iVar13 = iVar1;
        bStack_f65 = bVar7;
        piStack_f50 = piStack_f50 + 1;
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
    uVar10 = (*pcVar2)(param_1);
    uVar10 = uStack_f5c | uVar10;
  }
  return uVar10;
}


