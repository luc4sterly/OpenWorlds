// 1002140b FUN_1002140b [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1002140b(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  short sVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  short *psVar13;
  short *psVar14;
  undefined4 unaff_EDI;
  undefined4 *puVar15;
  bool in_ZF;
  longlong lVar16;
  uint uVar17;
  uint uStack00000004;
  int *piStack00000008;
  float fStack0000000c;
  undefined4 in_stack_00000018;
  int in_stack_00000028;
  int *in_stack_00000030;
  int in_stack_00000034;
  byte bVar18;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (*(int *)(DAT_1003a024 + 0x70) == 0)) &&
     (*(byte *)(*in_stack_00000030 + 4) < 0x80)) {
    return 0;
  }
  bVar18 = *(byte *)(*in_stack_00000030 + 0x30);
  if (((bVar18 & 0x80) == 0) && (in_stack_00000034 != 0)) {
    return 0;
  }
  piVar5 = (int *)FUN_10001190(*(int *)(*in_stack_00000030 + 0x34),(uint)bVar18,&stack0x00000028);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  iVar6 = (**(code **)(*piVar5 + 0x10))(piVar5,*(undefined4 *)(DAT_1003a024 + 8),&stack0x00000024);
  if (iVar6 != 0) {
    return 0;
  }
  piStack00000008 = in_stack_00000030 + 0xf;
  uStack00000004 = 0;
  uVar17 = (uint)*(byte *)((int)in_stack_00000030 + 0x3a);
  if ((((*(byte *)(*in_stack_00000030 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) ||
     (DAT_10036068 == 0)) {
    fStack0000000c = 1.0;
  }
  else {
    fStack0000000c = *(float *)(*piStack00000008 + 0x14);
    if (1 < uVar17) {
      iVar6 = uVar17 - 1;
      piVar5 = piStack00000008;
      do {
        piVar5 = piVar5 + 1;
        if (*(float *)(*piVar5 + 0x14) < fStack0000000c) {
          fStack0000000c = *(float *)(*piVar5 + 0x14);
        }
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  if (uVar17 != 0) {
    fVar1 = (float)DAT_10042034;
    fVar2 = (float)DAT_10042038;
    puVar11 = &DAT_10038b8c;
    while( true ) {
      uVar17 = uVar17 - 1;
      piVar5 = piStack00000008 + 1;
      iVar6 = *piStack00000008;
      puVar11[-5] = (float)*(int *)(iVar6 + 0x18) * _DAT_10034610 + fVar1;
      puVar11[-4] = (float)*(int *)(iVar6 + 0x1c) * _DAT_10034610 + fVar2;
      puVar11[-3] = (float)(ushort)~*(ushort *)(iVar6 + 0x22) * _DAT_10034614;
      if ((((*(byte *)(*in_stack_00000030 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) ||
         (DAT_10036068 == 0)) {
        puVar11[-2] = 0x3f800000;
      }
      else {
        puVar11[-2] = fStack0000000c / *(float *)(iVar6 + 0x14);
      }
      bVar18 = (byte)((uint)unaff_EDI >> 0x18);
      if ((*(byte *)(*in_stack_00000030 + 0x30) & 1) == 0) {
        uVar7 = (uint)bVar18 << 0x18 | 0xffffff;
      }
      else {
        uVar7 = ((uint)*(byte *)(((*(uint *)(iVar6 + 0x58) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0
                                ) << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar6 + 0x5c) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0
                                ) << 8 |
                 (uint)*(byte *)(((*(uint *)(iVar6 + 0x60) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0
                                ) | (uint)bVar18 << 0x15) * 8;
      }
      puVar11[-1] = uVar7;
      piStack00000008 = piVar5;
      if (_DAT_1003607c <= *(float *)(iVar6 + 0x14)) {
        if (*(float *)(iVar6 + 0x14) <= _DAT_10036080) {
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
      uStack00000004 = uStack00000004 + 1;
      puVar11[1] = (float)*(int *)(iVar6 + 100) * _DAT_10034610;
      fVar3 = (float)*(int *)(iVar6 + 0x68) * _DAT_10034610;
      if ((int)uVar17 < 1) break;
      puVar11[2] = fVar3;
      puVar11 = puVar11 + 8;
    }
    puVar11[2] = fVar3;
  }
  uVar17 = uStack00000004;
  iVar8 = (*(int *)(DAT_1003a024 + 0x34) + uStack00000004 * -8) - *(int *)(DAT_1003a024 + 0x30);
  iVar6 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  iVar10 = uStack00000004 * 0x20;
  if (((iVar6 == iVar10 || (int)(iVar6 + uStack00000004 * -0x20) < 0) ||
      (iVar8 == 0x16c || iVar8 + -0x16c < 0)) && (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
    return 0;
  }
  if ((int)uStack00000004 < 1) {
    return 0;
  }
  puVar11 = *(undefined4 **)(DAT_1003a024 + 0x28);
  iVar6 = *(int *)(DAT_1003a024 + 0x24);
  if (puVar11 != &DAT_10038b78) {
    puVar12 = &DAT_10038b78;
    puVar15 = puVar11;
    for (iVar8 = (uVar17 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar15 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar15 = puVar15 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar15 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar15 = (undefined4 *)((int)puVar15 + 1);
    }
  }
  *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + iVar10;
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
  if ((((*(byte *)(*in_stack_00000030 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) ||
     (DAT_10036068 == 0)) {
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      goto LAB_100218ac;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x88) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x88) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
LAB_100218ac:
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
    else if (*(uint *)(DAT_1003a024 + 0x94) != (uint)*(byte *)(*in_stack_00000030 + 4)) {
      *(uint *)(DAT_1003a024 + 0x94) = (uint)*(byte *)(*in_stack_00000030 + 4);
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x40;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           (&DAT_1003a030)[(uint)*(byte *)(*in_stack_00000030 + 4) * 0x20];
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x41;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a034 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x42;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a038 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x43;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a03c + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x44;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a040 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x45;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a044 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x46;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a048 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x47;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a04c + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x48;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a050 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x49;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a054 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4a;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a058 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4b;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a05c + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4c;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a060 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4d;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a064 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4e;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a068 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4f;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a06c + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x50;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           (&DAT_1003a070)[(uint)*(byte *)(*in_stack_00000030 + 4) * 0x20];
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x51;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a074 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x52;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a078 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x53;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a07c + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x54;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a080 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x55;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a084 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x56;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a088 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x57;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a08c + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x58;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a090 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x59;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a094 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5a;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a098 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5b;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a09c + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5c;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a0 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5d;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a4 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5e;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a8 + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5f;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0ac + (uint)*(byte *)(*in_stack_00000030 + 4) * 0x80);
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
  iVar8 = *in_stack_00000030;
  bVar18 = *(byte *)(iVar8 + 0x30);
  if (((bVar18 & 4) == 0) && (DAT_100362b0 == 0)) {
    if (*(int *)(*(int *)(iVar8 + 0x34) + 0x1c) == 0) {
      uVar17 = *(uint *)(DAT_1003a024 + 100);
    }
    else if ((bVar18 & 0x10) == 0) {
      uVar17 = *(uint *)(DAT_1003a024 + 0x5c);
    }
    else {
      uVar17 = *(uint *)(DAT_1003a024 + 0x54);
    }
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar17) goto LAB_10022348;
  }
  else {
    if (*(int *)(*(int *)(iVar8 + 0x34) + 0x1c) == 0) {
      uVar17 = *(uint *)(DAT_1003a024 + 0x60);
    }
    else if ((bVar18 & 0x10) == 0) {
      uVar17 = *(uint *)(DAT_1003a024 + 0x58);
    }
    else {
      uVar17 = *(uint *)(DAT_1003a024 + 0x50);
    }
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar17) goto LAB_10022348;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar17;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar17;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar17;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_10022348:
  **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
  *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = in_stack_00000018;
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
  sVar9 = (short)((uint)((int)puVar11 - iVar6) >> 5);
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar9;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar9;
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
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uStack00000004 + -2;
  iVar6 = 1;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  psVar14 = *(short **)(DAT_1003a024 + 0x30);
  psVar13 = psVar14;
  if (1 < (int)(uStack00000004 - 1)) {
    do {
      *psVar13 = sVar9;
      sVar4 = sVar9 + (short)iVar6;
      if (in_stack_00000028 == 0) {
        psVar13[1] = sVar4 + 1;
      }
      else {
        psVar13[1] = sVar4;
        sVar4 = sVar4 + 1;
      }
      psVar13[2] = sVar4;
      psVar14 = psVar13 + 4;
      psVar13[3] = 0x700;
      iVar6 = iVar6 + 1;
      psVar13 = psVar14;
    } while (iVar6 < (int)(uStack00000004 - 1));
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar14;
  return 0;
}


