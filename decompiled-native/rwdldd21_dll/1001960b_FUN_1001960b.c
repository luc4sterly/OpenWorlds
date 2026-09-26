// 1001960b FUN_1001960b [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001960b(void)

{
  uint uVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  short *psVar12;
  short *psVar13;
  undefined4 *puVar14;
  bool in_ZF;
  longlong lVar15;
  uint uVar16;
  int iStack00000004;
  int *piStack00000010;
  int *in_stack_00000020;
  int in_stack_00000024;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*in_stack_00000020 + 0x30) & 0x80) != 0) || (in_stack_00000024 == 0)) {
    piStack00000010 = in_stack_00000020 + 0xf;
    uVar16 = 0;
    iStack00000004 = *(byte *)((int)in_stack_00000020 + 0x3a) - 1;
    if (*(byte *)((int)in_stack_00000020 + 0x3a) != 0) {
      fVar3 = (float)DAT_10042034;
      fVar4 = (float)DAT_10042038;
      puVar10 = &DAT_10038b8c;
      do {
        iVar9 = DAT_100362d0;
        piVar6 = piStack00000010 + 1;
        iVar7 = *piStack00000010;
        puVar10[-5] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar3;
        puVar10[-4] = (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar4;
        puVar10[-3] = (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614;
        puVar10[-2] = 0x3f800000;
        uVar1 = *(uint *)(*in_stack_00000020 + 8);
        puVar10[-1] = ((*(byte *)(((*(uint *)(iVar7 + 0x58) & 0x1f0000) >> 0xb) +
                                  ((uVar1 & 0xf800) >> 0xb) + iVar9) | 0xffffffe0) << 0x10 |
                       (uint)*(byte *)(((*(uint *)(iVar7 + 0x5c) & 0x1f0000) >> 0xb) +
                                       ((uVar1 & 0x7c0) >> 6) + iVar9) << 8 |
                      (uint)*(byte *)(((*(uint *)(iVar7 + 0x60) & 0x1f0000) >> 0xb) + (uVar1 & 0x1f)
                                     + iVar9)) << 3;
        piStack00000010 = piVar6;
        if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
          if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
            lVar15 = __ftol();
            *puVar10 = *(undefined4 *)(DAT_1003a020 + (int)lVar15 * 4);
          }
          else {
            *puVar10 = 0;
          }
        }
        else {
          *puVar10 = 0xff000000;
        }
        uVar16 = uVar16 + 1;
        puVar10[1] = 0;
        puVar10[2] = 0;
        iVar7 = iStack00000004 + -1;
        bVar2 = 0 < iStack00000004;
        puVar10 = puVar10 + 8;
        iStack00000004 = iVar7;
      } while (bVar2);
    }
    iVar9 = (*(int *)(DAT_1003a024 + 0x34) + uVar16 * -8) - *(int *)(DAT_1003a024 + 0x30);
    iVar7 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    if (((iVar7 == uVar16 * 0x20 || (int)(iVar7 + uVar16 * -0x20) < 0) ||
        (iVar9 == 0x6c || iVar9 + -0x6c < 0)) && (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
      return 0;
    }
    if (0 < (int)uVar16) {
      puVar10 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar7 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar10 != &DAT_10038b78) {
        puVar11 = &DAT_10038b78;
        puVar14 = puVar10;
        for (iVar9 = (uVar16 & 0x7ffffff) << 3; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar14 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar14 = puVar14 + 1;
        }
        for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined1 *)puVar14 = *(undefined1 *)puVar11;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
          puVar14 = (undefined4 *)((int)puVar14 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar16 * 0x20;
      DAT_10039078 = *(undefined1 **)(DAT_1003a024 + 0x30);
      DAT_10038b70 = 0;
      **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
      *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
      *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      if (*(int *)(DAT_1003a024 + 0x84) != 0) {
        *(undefined4 *)(DAT_1003a024 + 0x84) = 0;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
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
      iVar9 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar9) {
        *(int *)(DAT_1003a024 + 0x98) = iVar9;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar9;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar9;
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
      sVar8 = (short)((uint)((int)puVar10 - iVar7) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar8;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar8;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar16;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar16 + -2;
      iVar7 = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar13 = *(short **)(DAT_1003a024 + 0x30);
      psVar12 = psVar13;
      if (1 < (int)(uVar16 - 1)) {
        do {
          *psVar12 = sVar8;
          sVar5 = sVar8 + (short)iVar7;
          if (in_stack_00000024 == 0) {
            psVar12[1] = sVar5 + 1;
          }
          else {
            psVar12[1] = sVar5;
            sVar5 = sVar5 + 1;
          }
          psVar12[2] = sVar5;
          psVar13 = psVar12 + 4;
          psVar12[3] = 0x700;
          iVar7 = iVar7 + 1;
          psVar12 = psVar13;
        } while (iVar7 < (int)(uVar16 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar13;
    }
  }
  return 0;
}


