// 100169c0 FUN_100169c0 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_100169c0(int *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  short sVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  undefined4 *puVar16;
  short *psVar17;
  short *psVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  longlong lVar21;
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar9 = FUN_10016310(param_1,param_2);
    return uVar9;
  }
  uVar13 = *(uint *)(*param_1 + 8);
  bVar1 = *(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar13 & 0x7c0) >> 6) + DAT_100362d0);
  bVar2 = *(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar13 & 0xf800) >> 0xb) + DAT_100362d0);
  bVar3 = *(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar13 & 0x1f) + DAT_100362d0);
  bVar4 = *(byte *)(*param_1 + 0x30);
  if (((bVar4 & 0x80) != 0) || (param_2 == 0)) {
    fVar5 = _DAT_1003461c;
    if ((bVar4 & 0x40) != 0) {
      fVar5 = _DAT_10034620;
    }
    piVar15 = param_1 + 0xf;
    uVar13 = (uint)*(byte *)((int)param_1 + 0x3a);
    uVar14 = 0;
    if (uVar13 != 0) {
      fVar6 = (float)DAT_10042034;
      fVar7 = (float)DAT_10042038;
      puVar19 = &DAT_10038b8c;
      do {
        uVar13 = uVar13 - 1;
        iVar10 = *piVar15;
        piVar15 = piVar15 + 1;
        puVar19[-5] = (float)*(int *)(iVar10 + 0x18) * _DAT_10034610 + fVar6;
        puVar19[-4] = (float)*(int *)(iVar10 + 0x1c) * _DAT_10034610 + fVar7;
        puVar19[-3] = (float)(ushort)~*(ushort *)(iVar10 + 0x22) * _DAT_10034614 - fVar5;
        puVar19[-2] = 0x3f800000;
        puVar19[-1] = ((bVar1 | 0xffffe000) << 8 | (uint)bVar2 << 0x10 | (uint)bVar3) << 3;
        if (_DAT_1003607c <= *(float *)(iVar10 + 0x14)) {
          if (*(float *)(iVar10 + 0x14) <= _DAT_10036080) {
            lVar21 = __ftol();
            *puVar19 = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
          }
          else {
            *puVar19 = 0;
          }
        }
        else {
          *puVar19 = 0xff000000;
        }
        uVar14 = uVar14 + 1;
        puVar19[1] = 0;
        puVar19[2] = 0;
        puVar19 = puVar19 + 8;
      } while (0 < (int)uVar13);
    }
    iVar10 = (*(int *)(DAT_1003a024 + 0x34) + uVar14 * -8) - *(int *)(DAT_1003a024 + 0x30);
    if ((((int)((*(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28)) + uVar14 * -0x20) <
          1) || (iVar10 == 0x6c || iVar10 + -0x6c < 0)) &&
       (iVar10 = FUN_10001080(DAT_1003a024), iVar10 == 0)) {
      return 0;
    }
    if (0 < (int)uVar14) {
      puVar19 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar10 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar19 != &DAT_10038b78) {
        puVar16 = &DAT_10038b78;
        puVar20 = puVar19;
        for (iVar11 = (uVar14 & 0x7ffffff) << 3; iVar11 != 0; iVar11 = iVar11 + -1) {
          *puVar20 = *puVar16;
          puVar16 = puVar16 + 1;
          puVar20 = puVar20 + 1;
        }
        for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {
          *(undefined1 *)puVar20 = *(undefined1 *)puVar16;
          puVar16 = (undefined4 *)((int)puVar16 + 1);
          puVar20 = (undefined4 *)((int)puVar20 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar14 * 0x20;
      DAT_10039078 = *(undefined1 **)(DAT_1003a024 + 0x30);
      DAT_10038b70 = 0;
      **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
      *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
      *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      if (*(int *)(DAT_1003a024 + 0x84) == 0) {
        *(undefined4 *)(DAT_1003a024 + 0x84) = 1;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 1;
      }
      if (*(int *)(DAT_1003a024 + 0x88) != 0) {
        *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 1;
      }
      if (*(int *)(DAT_1003a024 + 0x90) == 0) {
        *(undefined4 *)(DAT_1003a024 + 0x90) = 1;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 3;
      }
      if (*(int *)(DAT_1003a024 + 0x8c) != 0) {
        *(undefined4 *)(DAT_1003a024 + 0x8c) = 0;
        if (*(int *)(DAT_1003a024 + 0x7c) == 0) {
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x1b;
        }
        else {
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
        }
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 1;
      }
      if (*(int *)(DAT_1003a024 + 0x94) != 0xff) {
        *(undefined4 *)(DAT_1003a024 + 0x94) = 0xff;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 1;
      }
      iVar11 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar11) {
        *(int *)(DAT_1003a024 + 0x98) = iVar11;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar11;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar11;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 2;
      }
      **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      if (*(int *)(DAT_1003a024 + 0x80) == 0) {
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x15;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
      }
      else {
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x15;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 4;
      }
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      DAT_10038b70 = DAT_10038b70 + 2;
      *DAT_10039078 = 8;
      DAT_10039078[1] = 8;
      *(short *)(DAT_10039078 + 2) = (short)DAT_10038b70;
      DAT_10039078 = DAT_10039078 + 4;
      **(undefined1 **)(DAT_1003a024 + 0x30) = 9;
      *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 0x10;
      *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 10;
      sVar12 = (short)((uint)((int)puVar19 - iVar10) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar12;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar12;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar14;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 0xc) = 0;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 0x10;
      if (((uint)*(undefined1 **)(DAT_1003a024 + 0x30) & 7) == 0) {
        **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      }
      **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
      *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar14 + -2;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      iVar10 = 1;
      psVar18 = *(short **)(DAT_1003a024 + 0x30);
      psVar17 = psVar18;
      if (1 < (int)(uVar14 - 1)) {
        do {
          *psVar17 = sVar12;
          sVar8 = sVar12 + (short)iVar10;
          if (param_2 == 0) {
            psVar17[1] = sVar8 + 1;
          }
          else {
            psVar17[1] = sVar8;
            sVar8 = sVar8 + 1;
          }
          psVar17[2] = sVar8;
          psVar18 = psVar17 + 4;
          psVar17[3] = 0x700;
          iVar10 = iVar10 + 1;
          psVar17 = psVar18;
        } while (iVar10 < (int)(uVar14 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar18;
    }
  }
  return 0;
}


