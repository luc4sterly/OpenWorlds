// 1001631b FUN_1001631b [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001631b(void)

{
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  short *psVar11;
  short *psVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  bool in_ZF;
  longlong lVar15;
  int iStack00000010;
  int *in_stack_00000018;
  int in_stack_0000001c;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  uVar7 = *(uint *)(*in_stack_00000018 + 8);
  iStack00000010 =
       ((*(byte *)(((in_stack_00000018[1] & 0x1f0000U) >> 0xb) + ((uVar7 & 0xf800) >> 0xb) +
                  DAT_100362d0) | 0xffffffe0) << 0x10 |
        (uint)*(byte *)(((in_stack_00000018[2] & 0x1f0000U) >> 0xb) + ((uVar7 & 0x7c0) >> 6) +
                       DAT_100362d0) << 8 |
       (uint)*(byte *)(((in_stack_00000018[3] & 0x1f0000U) >> 0xb) + (uVar7 & 0x1f) + DAT_100362d0))
       << 3;
  if (((*(byte *)(*in_stack_00000018 + 0x30) & 0x80) != 0) || (in_stack_0000001c == 0)) {
    piVar9 = in_stack_00000018 + 0xf;
    uVar7 = (uint)*(byte *)((int)in_stack_00000018 + 0x3a);
    uVar8 = 0;
    if (uVar7 != 0) {
      fVar1 = (float)DAT_10042034;
      fVar2 = (float)DAT_10042038;
      puVar13 = &DAT_10038b8c;
      do {
        uVar7 = uVar7 - 1;
        iVar4 = *piVar9;
        piVar9 = piVar9 + 1;
        puVar13[-5] = (float)*(int *)(iVar4 + 0x18) * _DAT_10034610 + fVar1;
        puVar13[-4] = (float)*(int *)(iVar4 + 0x1c) * _DAT_10034610 + fVar2;
        puVar13[-3] = (float)(ushort)~*(ushort *)(iVar4 + 0x22) * _DAT_10034614;
        puVar13[-2] = 0x3f800000;
        puVar13[-1] = iStack00000010;
        if (_DAT_1003607c <= *(float *)(iVar4 + 0x14)) {
          if (*(float *)(iVar4 + 0x14) <= _DAT_10036080) {
            lVar15 = __ftol();
            *puVar13 = *(undefined4 *)(DAT_1003a020 + (int)lVar15 * 4);
          }
          else {
            *puVar13 = 0;
          }
        }
        else {
          *puVar13 = 0xff000000;
        }
        uVar8 = uVar8 + 1;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar13 = puVar13 + 8;
      } while (0 < (int)uVar7);
    }
    iVar4 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + uVar8 * -8;
    if ((((int)((*(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28)) + uVar8 * -0x20) < 1
         ) || (iVar4 == 0x6c || iVar4 + -0x6c < 0)) &&
       (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
      return 0;
    }
    if (0 < (int)uVar8) {
      puVar13 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar4 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar13 != &DAT_10038b78) {
        puVar10 = &DAT_10038b78;
        puVar14 = puVar13;
        for (iVar5 = (uVar8 & 0x7ffffff) << 3; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar14 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar14 = puVar14 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar14 = (undefined4 *)((int)puVar14 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar8 * 0x20;
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
      iVar5 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar5) {
        *(int *)(DAT_1003a024 + 0x98) = iVar5;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar5;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar5;
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
      sVar6 = (short)((uint)((int)puVar13 - iVar4) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar6;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar6;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar8;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar8 + -2;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      iVar4 = 1;
      psVar12 = *(short **)(DAT_1003a024 + 0x30);
      psVar11 = psVar12;
      if (1 < (int)(uVar8 - 1)) {
        do {
          *psVar11 = sVar6;
          sVar3 = (short)iVar4 + sVar6;
          if (in_stack_0000001c == 0) {
            psVar11[1] = sVar3 + 1;
          }
          else {
            psVar11[1] = sVar3;
            sVar3 = sVar3 + 1;
          }
          psVar11[2] = sVar3;
          psVar12 = psVar11 + 4;
          psVar11[3] = 0x700;
          iVar4 = iVar4 + 1;
          psVar11 = psVar12;
        } while (iVar4 < (int)(uVar8 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar12;
    }
  }
  return 0;
}


