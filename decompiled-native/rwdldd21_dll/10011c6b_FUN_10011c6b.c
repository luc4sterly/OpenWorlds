// 10011c6b FUN_10011c6b [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10011c6b(void)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  short *psVar11;
  short *psVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  undefined4 *puVar17;
  float *pfVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  float *pfVar21;
  bool in_ZF;
  longlong lVar22;
  byte bVar23;
  uint uStack00000004;
  short sStack00000008;
  int iStack00000010;
  int iStack00000014;
  int iStack0000001c;
  int iStack00000020;
  int *piStack00000024;
  int iStack00000028;
  byte bStack0000002c;
  undefined3 uStack0000002d;
  undefined4 in_stack_00000030;
  int *in_stack_00000058;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  iStack00000010 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  iStack00000014 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
  uVar8 = *(uint *)(*in_stack_00000058 + 8);
  iStack00000020 =
       ((*(byte *)(((in_stack_00000058[2] & 0x1f0000U) >> 0xb) + ((uVar8 & 0x7c0) >> 6) +
                  DAT_100362d0) | 0xffffe000) << 8 |
        (uint)*(byte *)(((in_stack_00000058[1] & 0x1f0000U) >> 0xb) + ((uVar8 & 0xf800) >> 0xb) +
                       DAT_100362d0) << 0x10 |
       (uint)*(byte *)(((in_stack_00000058[3] & 0x1f0000U) >> 0xb) + (uVar8 & 0x1f) + DAT_100362d0))
       << 3;
  iVar16 = in_stack_00000058[0xf];
  iStack0000001c = 1;
  uVar8 = (uint)*(byte *)((int)in_stack_00000058 + 0x3a);
  uStack00000004 = 0;
  _bStack0000002c = CONCAT31(uStack0000002d,*(undefined1 *)(in_stack_00000058[uVar8 + 0xe] + 0x48));
  bVar23 = *(byte *)(iVar16 + 0x48);
  if (1 < *(byte *)((int)in_stack_00000058 + 0x3a)) {
    piVar15 = in_stack_00000058 + 0x10;
    do {
      if ((bVar23 & bStack0000002c & 0x3f) == 0) break;
      iVar16 = *piVar15;
      piVar15 = piVar15 + 1;
      iStack0000001c = iStack0000001c + 1;
      _bStack0000002c = CONCAT31(uStack0000002d,bVar23);
      bVar23 = *(byte *)(iVar16 + 0x48);
    } while (iStack0000001c < (int)uVar8);
  }
  if (*(int *)(DAT_1003a024 + 0x74) == 0) {
    if (iStack0000001c < (int)uVar8) {
      iStack00000028 = uVar8 - iStack0000001c;
      piStack00000024 = in_stack_00000058 + iStack0000001c + 0xf;
      do {
        uVar8 = uStack00000004;
        iVar7 = *piStack00000024;
        bVar1 = *(byte *)(iVar7 + 0x48);
        if ((bVar1 & bVar23 & 0x3f) == 0) {
          fVar2 = (float)DAT_10042034;
          fVar3 = (float)DAT_10042038;
          (&DAT_10038b78)[uStack00000004 * 8] =
               (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar2;
          iVar6 = uStack00000004 * 8;
          *(float *)(&DAT_10038b7c + uStack00000004 * 0x20) =
               (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar3;
          (&DAT_10038b80)[uStack00000004 * 8] =
               (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614;
          (&DAT_10038b84)[uStack00000004 * 8] = 0x3f800000;
          (&DAT_10038b88)[uStack00000004 * 8] = iStack00000020;
          if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
            if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
              lVar22 = __ftol();
              (&DAT_10038b8c)[uVar8 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar22 * 4);
            }
            else {
              (&DAT_10038b8c)[uStack00000004 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[uStack00000004 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[uVar8 * 8] = 0x3f800000;
          (&DAT_10038b94)[uVar8 * 8] = 0x3f800000;
          puVar17 = &DAT_10038b78 + iVar6;
          puVar19 = &DAT_10038bb8 + uVar8 * 8;
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar19 = *puVar17;
            puVar17 = puVar17 + 1;
            puVar19 = puVar19 + 1;
          }
          iVar6 = uStack00000004 + 1;
          (&DAT_10038b78)[iVar6 * 8] = (float)*(int *)(iVar16 + 0x18) * _DAT_10034610 + fVar2;
          *(float *)(&DAT_10038b7c + iVar6 * 0x20) =
               (float)*(int *)(iVar16 + 0x1c) * _DAT_10034610 + fVar3;
          (&DAT_10038b80)[iVar6 * 8] = (float)(ushort)~*(ushort *)(iVar16 + 0x22) * _DAT_10034614;
          (&DAT_10038b84)[iVar6 * 8] = 0x3f800000;
          (&DAT_10038b88)[iVar6 * 8] = iStack00000020;
          uStack00000004 = iVar6;
          if (_DAT_1003607c <= *(float *)(iVar16 + 0x14)) {
            if (*(float *)(iVar16 + 0x14) <= _DAT_10036080) {
              lVar22 = __ftol();
              (&DAT_10038b8c)[iVar6 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar22 * 4);
            }
            else {
              (&DAT_10038b8c)[iVar6 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[iVar6 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[iVar6 * 8] = 0x3f800000;
          (&DAT_10038b94)[iVar6 * 8] = 0x3f800000;
          pfVar18 = (float *)(&DAT_10038b78 + iVar6 * 8);
          pfVar21 = (float *)(&DAT_10038bb8 + iVar6 * 8);
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *pfVar21 = *pfVar18;
            pfVar18 = pfVar18 + 1;
            pfVar21 = pfVar21 + 1;
          }
          iVar6 = uStack00000004 + 1;
          uVar10 = *(int *)(iVar7 + 0x18) - *(int *)(iVar16 + 0x18);
          uVar13 = (int)uVar10 >> 0x1f;
          uVar8 = *(int *)(iVar7 + 0x1c) - *(int *)(iVar16 + 0x1c);
          uVar14 = (int)uVar8 >> 0x1f;
          if ((int)((uVar8 ^ uVar14) - uVar14) < (int)((uVar10 ^ uVar13) - uVar13)) {
            *(uint *)((int)&stack0x0000002c +
                     ((int)(uStack00000004 + -1 + ((int)(uStack00000004 + -1) >> 0x1f & 3U)) >> 2) *
                     4) = (uint)(*(int *)(iVar7 + 0x18) < *(int *)(iVar16 + 0x18));
            *(float *)(&DAT_10038b7c + iVar6 * 0x20) =
                 *(float *)(&DAT_10038b7c + iVar6 * 0x20) + _DAT_10034618;
            (&DAT_10038b9c)[iVar6 * 8] = (float)(&DAT_10038b9c)[iVar6 * 8] + _DAT_10034618;
          }
          else {
            *(uint *)((int)&stack0x0000002c +
                     ((int)(uStack00000004 + -1 + ((int)(uStack00000004 + -1) >> 0x1f & 3U)) >> 2) *
                     4) = (uint)(*(int *)(iVar16 + 0x1c) < *(int *)(iVar7 + 0x1c));
            (&DAT_10038b78)[iVar6 * 8] = (float)(&DAT_10038b78)[iVar6 * 8] + _DAT_10034618;
            (&DAT_10038b98)[iVar6 * 8] = (float)(&DAT_10038b98)[iVar6 * 8] + _DAT_10034618;
          }
          uStack00000004 = uStack00000004 + 3;
        }
        iStack00000028 = iStack00000028 + -1;
        iVar16 = iVar7;
        bVar23 = bVar1;
        piStack00000024 = piStack00000024 + 1;
      } while (iStack00000028 != 0);
    }
    uVar8 = uStack00000004;
    iVar7 = uStack00000004 * 0x20;
    iStack00000010 = iStack00000010 + uStack00000004 * -0x20;
    iVar16 = (int)uStack00000004 / 2;
    iStack00000014 = iStack00000014 - (iVar16 * 8 + 0x6c);
    if (((iStack00000010 < 1) || (iStack00000014 < 1)) &&
       (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
      return 0;
    }
    if (0 < (int)uStack00000004) {
      puVar17 = *(undefined4 **)(DAT_1003a024 + 0x28);
      sStack00000008 = (short)((uint)((int)puVar17 - *(int *)(DAT_1003a024 + 0x24)) >> 5);
      if (puVar17 != &DAT_10038b78) {
        puVar19 = &DAT_10038b78;
        for (iVar6 = (uVar8 & 0x7ffffff) << 3; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar17 = *puVar19;
          puVar19 = puVar19 + 1;
          puVar17 = puVar17 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar17 = *(undefined1 *)puVar19;
          puVar19 = (undefined4 *)((int)puVar19 + 1);
          puVar17 = (undefined4 *)((int)puVar17 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + iVar7;
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
      iVar7 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar7) {
        *(int *)(DAT_1003a024 + 0x98) = iVar7;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar7;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar7;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sStack00000008;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sStack00000008;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack00000004;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar16;
      iVar16 = 0;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar12 = *(short **)(DAT_1003a024 + 0x30);
      if (0 < (int)uStack00000004) {
        do {
          iVar7 = *(int *)((int)&stack0x0000002c + ((int)(iVar16 + (iVar16 >> 0x1f & 3U)) >> 2) * 4)
          ;
          sVar5 = sStack00000008 + (short)iVar16;
          *psVar12 = sVar5;
          if (iVar7 == 0) {
            psVar12[1] = sVar5 + 2;
            psVar12[2] = sVar5 + 1;
            psVar12[3] = 0x700;
            psVar12[4] = sVar5 + 1;
            psVar12[5] = sVar5 + 2;
            psVar12[6] = sVar5 + 3;
          }
          else {
            psVar12[1] = sVar5 + 1;
            psVar12[2] = sVar5 + 2;
            psVar12[3] = 0x700;
            psVar12[4] = sVar5 + 1;
            psVar12[5] = sVar5 + 3;
            psVar12[6] = sVar5 + 2;
          }
          psVar12[7] = 0x700;
          psVar12 = psVar12 + 8;
          iVar16 = iVar16 + 4;
        } while (iVar16 < (int)uStack00000004);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar12;
    }
  }
  else {
    if (iStack0000001c < (int)uVar8) {
      piVar15 = in_stack_00000058 + iStack0000001c + 0xf;
      iStack0000001c = uVar8 - iStack0000001c;
      do {
        uVar8 = uStack00000004;
        iVar7 = *piVar15;
        piVar15 = piVar15 + 1;
        bVar1 = *(byte *)(iVar7 + 0x48);
        if ((bVar1 & bVar23 & 0x3f) == 0) {
          fVar2 = (float)DAT_10042034;
          fVar3 = (float)DAT_10042038;
          (&DAT_10038b78)[uStack00000004 * 8] =
               (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar2;
          *(float *)(&DAT_10038b7c + uStack00000004 * 0x20) =
               (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar3;
          _bStack0000002c = ~(int)*(short *)(iVar7 + 0x22) & 0xffff;
          in_stack_00000030 = 0;
          (&DAT_10038b80)[uStack00000004 * 8] = (float)_bStack0000002c * _DAT_10034614;
          (&DAT_10038b84)[uStack00000004 * 8] = 0x3f800000;
          (&DAT_10038b88)[uStack00000004 * 8] = iStack00000020;
          if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
            if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
              lVar22 = __ftol();
              (&DAT_10038b8c)[uVar8 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar22 * 4);
            }
            else {
              (&DAT_10038b8c)[uStack00000004 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[uStack00000004 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[uVar8 * 8] = 0x3f800000;
          (&DAT_10038b94)[uVar8 * 8] = 0x3f800000;
          iVar6 = uStack00000004 + 1;
          (&DAT_10038b78)[iVar6 * 8] = (float)*(int *)(iVar16 + 0x18) * _DAT_10034610 + fVar2;
          *(float *)(&DAT_10038b7c + iVar6 * 0x20) =
               (float)*(int *)(iVar16 + 0x1c) * _DAT_10034610 + fVar3;
          _bStack0000002c = ~(int)*(short *)(iVar16 + 0x22) & 0xffff;
          in_stack_00000030 = 0;
          (&DAT_10038b80)[iVar6 * 8] = (float)_bStack0000002c * _DAT_10034614;
          (&DAT_10038b84)[iVar6 * 8] = 0x3f800000;
          (&DAT_10038b88)[iVar6 * 8] = iStack00000020;
          uStack00000004 = iVar6;
          if (_DAT_1003607c <= *(float *)(iVar16 + 0x14)) {
            if (*(float *)(iVar16 + 0x14) <= _DAT_10036080) {
              lVar22 = __ftol();
              (&DAT_10038b8c)[iVar6 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar22 * 4);
            }
            else {
              (&DAT_10038b8c)[iVar6 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[iVar6 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[iVar6 * 8] = 0x3f800000;
          (&DAT_10038b94)[iVar6 * 8] = 0x3f800000;
          uStack00000004 = uStack00000004 + 1;
        }
        iStack0000001c = iStack0000001c + -1;
        iVar16 = iVar7;
        bVar23 = bVar1;
      } while (iStack0000001c != 0);
    }
    uVar8 = uStack00000004;
    iVar16 = uStack00000004 * 0x20;
    iStack00000010 = iStack00000010 + uStack00000004 * -0x20;
    iStack00000014 = iStack00000014 + (-0x1b - uStack00000004) * 4;
    if (((iStack00000010 < 1) || (iStack00000014 < 1)) &&
       (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
      return 0;
    }
    if (0 < (int)uStack00000004) {
      puVar17 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar7 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar17 != &DAT_10038b78) {
        puVar19 = &DAT_10038b78;
        puVar20 = puVar17;
        for (iVar6 = (uVar8 & 0x7ffffff) << 3; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar20 = *puVar19;
          puVar19 = puVar19 + 1;
          puVar20 = puVar20 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar20 = *(undefined1 *)puVar19;
          puVar19 = (undefined4 *)((int)puVar19 + 1);
          puVar20 = (undefined4 *)((int)puVar20 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + iVar16;
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
      iVar16 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar16) {
        *(int *)(DAT_1003a024 + 0x98) = iVar16;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar16;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar16;
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
      sVar5 = (short)((uint)((int)puVar17 - iVar7) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar5;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar5;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack00000004;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 0xc) = 0;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 0x10;
      if (((uint)*(undefined1 **)(DAT_1003a024 + 0x30) & 7) == 0) {
        **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      }
      **(undefined1 **)(DAT_1003a024 + 0x30) = 2;
      *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 4;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)uStack00000004 / 2);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      iVar16 = 0;
      psVar12 = *(short **)(DAT_1003a024 + 0x30);
      psVar11 = psVar12;
      if (0 < (int)uStack00000004) {
        do {
          sVar4 = sVar5 + (short)iVar16;
          psVar12 = psVar11 + 2;
          *psVar11 = sVar4;
          iVar16 = iVar16 + 2;
          psVar11[1] = sVar4 + 1;
          psVar11 = psVar12;
        } while (iVar16 < (int)uStack00000004);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar12;
    }
  }
  return 0;
}


