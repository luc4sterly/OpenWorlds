// 1001a41b FUN_1001a41b [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001a41b(void)

{
  uint uVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  short sVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  short *psVar13;
  short *psVar14;
  undefined4 *puVar15;
  bool in_ZF;
  longlong lVar16;
  uint uVar17;
  uint uStack00000004;
  int iStack0000000c;
  uint uStack00000010;
  int *piStack00000014;
  int *in_stack_00000028;
  int in_stack_0000002c;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (*(int *)(DAT_1003a024 + 0x70) == 0)) &&
     (*(byte *)(*in_stack_00000028 + 4) < 0x80)) {
    return 0;
  }
  if (((*(byte *)(*in_stack_00000028 + 0x30) & 0x80) != 0) || (in_stack_0000002c == 0)) {
    bVar8 = 0xff;
    if (*(int *)(DAT_1003a024 + 0x70) != 0) {
      bVar8 = *(byte *)(*in_stack_00000028 + 4);
    }
    uVar17 = 0;
    piStack00000014 = in_stack_00000028 + 0xf;
    iStack0000000c = *(byte *)((int)in_stack_00000028 + 0x3a) - 1;
    if (*(byte *)((int)in_stack_00000028 + 0x3a) != 0) {
      fVar3 = (float)DAT_10042034;
      fVar4 = (float)DAT_10042038;
      puVar11 = &DAT_10038b8c;
      do {
        piVar6 = piStack00000014 + 1;
        iVar7 = *piStack00000014;
        puVar11[-5] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar3;
        puVar11[-4] = (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar4;
        puVar11[-3] = (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614;
        puVar11[-2] = 0x3f800000;
        uVar1 = *(uint *)(*in_stack_00000028 + 8);
        uStack00000010 =
             (uint)*(byte *)(((*(uint *)(iVar7 + 0x58) & 0x1f0000) >> 0xb) +
                             ((uVar1 & 0xf800) >> 0xb) + DAT_100362d0);
        uStack00000004 =
             (uint)*(byte *)(((*(uint *)(iVar7 + 0x60) & 0x1f0000) >> 0xb) + (uVar1 & 0x1f) +
                            DAT_100362d0);
        puVar11[-1] = ((uint)*(byte *)(((*(uint *)(iVar7 + 0x5c) & 0x1f0000) >> 0xb) +
                                       ((uVar1 & 0x7c0) >> 6) + DAT_100362d0) << 8 |
                       uStack00000010 << 0x10 | uStack00000004 | (uint)bVar8 << 0x15) << 3;
        piStack00000014 = piVar6;
        if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
          if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
            lVar16 = __ftol();
            *puVar11 = *(undefined4 *)(DAT_1003a020 + (int)lVar16 * 4);
          }
          else {
            *puVar11 = 0;
          }
        }
        else {
          *puVar11 = 0xff000000;
        }
        uVar17 = uVar17 + 1;
        puVar11[1] = 0;
        puVar11[2] = 0;
        iVar7 = iStack0000000c + -1;
        bVar2 = 0 < iStack0000000c;
        puVar11 = puVar11 + 8;
        iStack0000000c = iVar7;
      } while (bVar2);
    }
    iVar9 = (*(int *)(DAT_1003a024 + 0x34) + uVar17 * -8) - *(int *)(DAT_1003a024 + 0x30);
    iVar7 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    if (((iVar7 == uVar17 * 0x20 || (int)(iVar7 + uVar17 * -0x20) < 0) ||
        (iVar9 == 0x16c || iVar9 + -0x16c < 0)) && (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0))
    {
      return 0;
    }
    if (0 < (int)uVar17) {
      puVar11 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar7 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar11 != &DAT_10038b78) {
        puVar12 = &DAT_10038b78;
        puVar15 = puVar11;
        for (iVar9 = (uVar17 & 0x7ffffff) << 3; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar15 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar15 = puVar15 + 1;
        }
        for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined1 *)puVar15 = *(undefined1 *)puVar12;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
          puVar15 = (undefined4 *)((int)puVar15 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar17 * 0x20;
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
      if (*(int *)(DAT_1003a024 + 0x70) == 0) {
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
        if (*(int *)(DAT_1003a024 + 0x6c) == 0) {
          if (*(int *)(DAT_1003a024 + 0x94) != 0xff) {
            *(undefined4 *)(DAT_1003a024 + 0x94) = 0xff;
            **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
            *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
            *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
            DAT_10038b70 = DAT_10038b70 + 1;
          }
        }
        else if (*(uint *)(DAT_1003a024 + 0x94) != (uint)*(byte *)(*in_stack_00000028 + 4)) {
          *(uint *)(DAT_1003a024 + 0x94) = (uint)*(byte *)(*in_stack_00000028 + 4);
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x40;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               (&DAT_1003a030)[(uint)*(byte *)(*in_stack_00000028 + 4) * 0x20];
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x41;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a034 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x42;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a038 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x43;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a03c + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x44;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a040 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x45;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a044 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x46;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a048 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x47;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a04c + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x48;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a050 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x49;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a054 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4a;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a058 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4b;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a05c + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4c;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a060 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4d;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a064 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4e;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a068 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4f;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a06c + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x50;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               (&DAT_1003a070)[(uint)*(byte *)(*in_stack_00000028 + 4) * 0x20];
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x51;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a074 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x52;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a078 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x53;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a07c + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x54;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a080 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x55;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a084 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x56;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a088 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x57;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a08c + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x58;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a090 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x59;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a094 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5a;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a098 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5b;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a09c + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5c;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a0a0 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5d;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a0a4 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5e;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a0a8 + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5f;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
               *(undefined4 *)(&DAT_1003a0ac + (uint)*(byte *)(*in_stack_00000028 + 4) * 0x80);
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 0x21;
        }
      }
      else {
        if (*(int *)(DAT_1003a024 + 0x94) != 0xff) {
          *(undefined4 *)(DAT_1003a024 + 0x94) = 0xff;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        if (*(int *)(DAT_1003a024 + 0x8c) == 0) {
          *(undefined4 *)(DAT_1003a024 + 0x8c) = 1;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x13;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 5;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x14;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 6;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          if (*(int *)(DAT_1003a024 + 0x7c) == 0) {
            **(undefined4 **)(DAT_1003a024 + 0x30) = 0x1b;
          }
          else {
            **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
          }
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 3;
        }
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
      sVar10 = (short)((uint)((int)puVar11 - iVar7) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar10;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar10;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar17;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar17 + -2;
      iVar7 = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar14 = *(short **)(DAT_1003a024 + 0x30);
      psVar13 = psVar14;
      if (1 < (int)(uVar17 - 1)) {
        do {
          *psVar13 = sVar10;
          sVar5 = sVar10 + (short)iVar7;
          if (in_stack_0000002c == 0) {
            psVar13[1] = sVar5 + 1;
          }
          else {
            psVar13[1] = sVar5;
            sVar5 = sVar5 + 1;
          }
          psVar13[2] = sVar5;
          psVar14 = psVar13 + 4;
          psVar13[3] = 0x700;
          iVar7 = iVar7 + 1;
          psVar13 = psVar14;
        } while (iVar7 < (int)(uVar17 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar14;
    }
  }
  return 0;
}


