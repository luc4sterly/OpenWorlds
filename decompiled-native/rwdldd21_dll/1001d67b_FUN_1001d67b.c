// 1001d67b FUN_1001d67b [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001d67b(float param_1)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  int *piVar10;
  undefined4 *puVar11;
  short *psVar12;
  short *psVar13;
  uint unaff_EDI;
  undefined4 *puVar14;
  undefined4 *puVar15;
  bool in_ZF;
  longlong lVar16;
  uint uVar17;
  uint uStack00000008;
  undefined4 in_stack_00000014;
  int in_stack_00000024;
  int *in_stack_0000002c;
  int in_stack_00000030;
  uint uVar18;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (*(int *)(DAT_1003a024 + 0x70) == 0)) &&
     (*(byte *)(*in_stack_0000002c + 4) < 0x80)) {
    return 0;
  }
  bVar1 = *(byte *)(*in_stack_0000002c + 0x30);
  if (((bVar1 & 0x80) == 0) && (in_stack_00000030 != 0)) {
    return 0;
  }
  piVar6 = (int *)FUN_10001190(*(int *)(*in_stack_0000002c + 0x34),(uint)bVar1,&stack0x00000024);
  if (piVar6 == (int *)0x0) {
    return 0;
  }
  iVar7 = (**(code **)(*piVar6 + 0x10))(piVar6,*(undefined4 *)(DAT_1003a024 + 8),&stack0x00000020);
  if (iVar7 != 0) {
    return 0;
  }
  if ((*(byte *)(*in_stack_0000002c + 0x30) & 1) == 0) {
    uStack00000008 = unaff_EDI << 0x18 | 0xffffff;
  }
  else {
    uStack00000008 =
         ((uint)*(byte *)(((in_stack_0000002c[2] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0) << 8 |
          (uint)*(byte *)(((in_stack_0000002c[1] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0) << 0x10
          | (uint)*(byte *)(((in_stack_0000002c[3] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0) |
         (unaff_EDI & 0xff) << 0x15) << 3;
  }
  piVar6 = in_stack_0000002c + 0xf;
  uVar17 = 0;
  uVar18 = (uint)*(byte *)((int)in_stack_0000002c + 0x3a);
  if ((((*(byte *)(*in_stack_0000002c + 0x30) & 2) != 0) || (DAT_100362ac != 0)) &&
     ((DAT_10036068 != 0 && (param_1 = *(float *)(*piVar6 + 0x14), 1 < uVar18)))) {
    piVar10 = in_stack_0000002c + 0x10;
    iVar7 = uVar18 - 1;
    do {
      if (*(float *)(*piVar10 + 0x14) < param_1) {
        param_1 = *(float *)(*piVar10 + 0x14);
      }
      piVar10 = piVar10 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (uVar18 != 0) {
    fVar2 = (float)DAT_10042034;
    fVar3 = (float)DAT_10042038;
    puVar14 = &DAT_10038b8c;
    while( true ) {
      uVar18 = uVar18 - 1;
      iVar7 = *piVar6;
      piVar6 = piVar6 + 1;
      puVar14[-5] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar2;
      puVar14[-4] = (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar3;
      puVar14[-3] = (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614;
      if ((((*(byte *)(*in_stack_0000002c + 0x30) & 2) == 0) && (DAT_100362ac == 0)) ||
         (DAT_10036068 == 0)) {
        puVar14[-2] = 0x3f800000;
      }
      else {
        puVar14[-2] = param_1 / *(float *)(iVar7 + 0x14);
      }
      puVar14[-1] = uStack00000008;
      if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
        if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
          lVar16 = __ftol();
          *puVar14 = *(undefined4 *)(DAT_1003a020 + (int)lVar16 * 4);
        }
        else {
          *puVar14 = 0;
        }
      }
      else {
        *puVar14 = 0xff000000;
      }
      uVar17 = uVar17 + 1;
      puVar14[1] = (float)*(int *)(iVar7 + 100) * _DAT_10034610;
      fVar4 = (float)*(int *)(iVar7 + 0x68) * _DAT_10034610;
      if ((int)uVar18 < 1) break;
      puVar14[2] = fVar4;
      puVar14 = puVar14 + 8;
    }
    puVar14[2] = fVar4;
  }
  iVar8 = (*(int *)(DAT_1003a024 + 0x34) + uVar17 * -8) - *(int *)(DAT_1003a024 + 0x30);
  iVar7 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  if (((iVar7 == uVar17 * 0x20 || (int)(iVar7 + uVar17 * -0x20) < 0) ||
      (iVar8 == 0x16c || iVar8 + -0x16c < 0)) && (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
    return 0;
  }
  if ((int)uVar17 < 1) {
    return 0;
  }
  puVar14 = *(undefined4 **)(DAT_1003a024 + 0x28);
  iVar7 = *(int *)(DAT_1003a024 + 0x24);
  if (puVar14 != &DAT_10038b78) {
    puVar11 = &DAT_10038b78;
    puVar15 = puVar14;
    for (iVar8 = (uVar17 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar15 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar15 = puVar15 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar15 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
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
  if (*(int *)(DAT_1003a024 + 0x84) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x84) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    DAT_10038b70 = DAT_10038b70 + 1;
  }
  if ((((*(byte *)(*in_stack_0000002c + 0x30) & 2) == 0) && (DAT_100362ac == 0)) ||
     (DAT_10036068 == 0)) {
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      goto LAB_1001daf6;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x88) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x88) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
LAB_1001daf6:
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
    else if (*(uint *)(DAT_1003a024 + 0x94) != (uint)*(byte *)(*in_stack_0000002c + 4)) {
      *(uint *)(DAT_1003a024 + 0x94) = (uint)*(byte *)(*in_stack_0000002c + 4);
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x40;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           (&DAT_1003a030)[(uint)*(byte *)(*in_stack_0000002c + 4) * 0x20];
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x41;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a034 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x42;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a038 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x43;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a03c + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x44;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a040 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x45;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a044 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x46;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a048 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x47;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a04c + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x48;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a050 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x49;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a054 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4a;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a058 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4b;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a05c + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4c;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a060 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4d;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a064 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4e;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a068 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4f;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a06c + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x50;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           (&DAT_1003a070)[(uint)*(byte *)(*in_stack_0000002c + 4) * 0x20];
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x51;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a074 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x52;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a078 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x53;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a07c + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x54;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a080 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x55;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a084 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x56;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a088 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x57;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a08c + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x58;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a090 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x59;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a094 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5a;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a098 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5b;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a09c + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5c;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a0 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5d;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a4 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5e;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a8 + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5f;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0ac + (uint)*(byte *)(*in_stack_0000002c + 4) * 0x80);
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
  iVar8 = *in_stack_0000002c;
  bVar1 = *(byte *)(iVar8 + 0x30);
  if (((bVar1 & 4) == 0) && (DAT_100362b0 == 0)) {
    if (*(int *)(*(int *)(iVar8 + 0x34) + 0x1c) == 0) {
      uVar18 = *(uint *)(DAT_1003a024 + 100);
    }
    else if ((bVar1 & 0x10) == 0) {
      uVar18 = *(uint *)(DAT_1003a024 + 0x5c);
    }
    else {
      uVar18 = *(uint *)(DAT_1003a024 + 0x54);
    }
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar18) goto LAB_1001e592;
  }
  else {
    if (*(int *)(*(int *)(iVar8 + 0x34) + 0x1c) == 0) {
      uVar18 = *(uint *)(DAT_1003a024 + 0x60);
    }
    else if ((bVar1 & 0x10) == 0) {
      uVar18 = *(uint *)(DAT_1003a024 + 0x58);
    }
    else {
      uVar18 = *(uint *)(DAT_1003a024 + 0x50);
    }
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar18) goto LAB_1001e592;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar18;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar18;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar18;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_1001e592:
  **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
  *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = in_stack_00000014;
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
  sVar9 = (short)((uint)((int)puVar14 - iVar7) >> 5);
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar9;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar9;
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
  psVar13 = *(short **)(DAT_1003a024 + 0x30);
  psVar12 = psVar13;
  if (1 < (int)(uVar17 - 1)) {
    do {
      *psVar12 = sVar9;
      sVar5 = sVar9 + (short)iVar7;
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
    } while (iVar7 < (int)(uVar17 - 1));
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar13;
  return 0;
}


