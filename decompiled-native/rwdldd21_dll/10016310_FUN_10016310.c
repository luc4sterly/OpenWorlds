// 10016310 FUN_10016310 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10016310(int *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  undefined4 *puVar13;
  short *psVar14;
  short *psVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  longlong lVar18;
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  uVar10 = *(uint *)(*param_1 + 8);
  bVar1 = *(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar10 & 0xf800) >> 0xb) + DAT_100362d0);
  bVar2 = *(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar10 & 0x7c0) >> 6) + DAT_100362d0);
  bVar3 = *(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar10 & 0x1f) + DAT_100362d0);
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    piVar12 = param_1 + 0xf;
    uVar10 = (uint)*(byte *)((int)param_1 + 0x3a);
    uVar11 = 0;
    if (uVar10 != 0) {
      fVar4 = (float)DAT_10042034;
      fVar5 = (float)DAT_10042038;
      puVar16 = &DAT_10038b8c;
      do {
        uVar10 = uVar10 - 1;
        iVar7 = *piVar12;
        piVar12 = piVar12 + 1;
        puVar16[-5] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar4;
        puVar16[-4] = (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar5;
        puVar16[-3] = (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614;
        puVar16[-2] = 0x3f800000;
        puVar16[-1] = ((bVar1 | 0xffffffe0) << 0x10 | (uint)bVar2 << 8 | (uint)bVar3) << 3;
        if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
          if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
            lVar18 = __ftol();
            *puVar16 = *(undefined4 *)(DAT_1003a020 + (int)lVar18 * 4);
          }
          else {
            *puVar16 = 0;
          }
        }
        else {
          *puVar16 = 0xff000000;
        }
        uVar11 = uVar11 + 1;
        puVar16[1] = 0;
        puVar16[2] = 0;
        puVar16 = puVar16 + 8;
      } while (0 < (int)uVar10);
    }
    iVar7 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + uVar11 * -8;
    if ((((int)((*(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28)) + uVar11 * -0x20) <
          1) || (iVar7 == 0x6c || iVar7 + -0x6c < 0)) &&
       (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
      return 0;
    }
    if (0 < (int)uVar11) {
      puVar16 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar7 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar16 != &DAT_10038b78) {
        puVar13 = &DAT_10038b78;
        puVar17 = puVar16;
        for (iVar8 = (uVar11 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar17 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar17 = puVar17 + 1;
        }
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined1 *)puVar17 = *(undefined1 *)puVar13;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
          puVar17 = (undefined4 *)((int)puVar17 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar11 * 0x20;
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
      if (*(int *)(DAT_1003a024 + 0x90) != 0) {
        *(undefined4 *)(DAT_1003a024 + 0x90) = 0;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 8;
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
      iVar8 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar8) {
        *(int *)(DAT_1003a024 + 0x98) = iVar8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar8;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar8;
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
      sVar9 = (short)((uint)((int)puVar16 - iVar7) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar9;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar9;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar11;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar11 + -2;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      iVar7 = 1;
      psVar15 = *(short **)(DAT_1003a024 + 0x30);
      psVar14 = psVar15;
      if (1 < (int)(uVar11 - 1)) {
        do {
          *psVar14 = sVar9;
          sVar6 = (short)iVar7 + sVar9;
          if (param_2 == 0) {
            psVar14[1] = sVar6 + 1;
          }
          else {
            psVar14[1] = sVar6;
            sVar6 = sVar6 + 1;
          }
          psVar14[2] = sVar6;
          psVar15 = psVar14 + 4;
          psVar14[3] = 0x700;
          iVar7 = iVar7 + 1;
          psVar14 = psVar15;
        } while (iVar7 < (int)(uVar11 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar15;
    }
  }
  return 0;
}


