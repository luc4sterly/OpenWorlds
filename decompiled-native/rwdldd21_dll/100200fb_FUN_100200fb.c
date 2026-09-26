// 100200fb FUN_100200fb [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_100200fb(void)

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
  undefined4 *puVar12;
  short *psVar13;
  short *psVar14;
  undefined4 *puVar15;
  bool in_ZF;
  longlong lVar16;
  float fStack00000004;
  int in_stack_00000010;
  undefined4 in_stack_00000014;
  int *in_stack_0000001c;
  int in_stack_00000020;
  int *in_stack_00000028;
  int in_stack_0000002c;
  uint uVar17;
  uint uVar18;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  bVar1 = *(byte *)(*in_stack_00000028 + 0x30);
  if (((bVar1 & 0x80) == 0) && (in_stack_0000002c != 0)) {
    return 0;
  }
  piVar6 = (int *)FUN_10001190(*(int *)(*in_stack_00000028 + 0x34),(uint)bVar1,&stack0x0000001c);
  if (piVar6 == (int *)0x0) {
    return 0;
  }
  iVar7 = (**(code **)(*piVar6 + 0x10))(piVar6,*(undefined4 *)(DAT_1003a024 + 8),&stack0x00000020);
  if (iVar7 != 0) {
    return 0;
  }
  piVar6 = in_stack_0000001c + 0xf;
  uVar18 = 0;
  uVar17 = (uint)*(byte *)((int)in_stack_0000001c + 0x3a);
  if ((((*(byte *)(*in_stack_0000001c + 0x30) & 2) == 0) && (DAT_100362ac == 0)) ||
     (DAT_10036068 == 0)) {
    fStack00000004 = 1.0;
  }
  else {
    fStack00000004 = *(float *)(*piVar6 + 0x14);
    if (1 < uVar17) {
      piVar10 = in_stack_0000001c + 0x10;
      iVar7 = uVar17 - 1;
      do {
        if (*(float *)(*piVar10 + 0x14) < fStack00000004) {
          fStack00000004 = *(float *)(*piVar10 + 0x14);
        }
        piVar10 = piVar10 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  if (uVar17 != 0) {
    fVar2 = (float)DAT_10042034;
    fVar3 = (float)DAT_10042038;
    puVar11 = &DAT_10038b8c;
    while( true ) {
      uVar17 = uVar17 - 1;
      iVar7 = *piVar6;
      piVar6 = piVar6 + 1;
      puVar11[-5] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar2;
      puVar11[-4] = (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar3;
      puVar11[-3] = (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614;
      if ((((*(byte *)(*in_stack_0000001c + 0x30) & 2) == 0) && (DAT_100362ac == 0)) ||
         (DAT_10036068 == 0)) {
        puVar11[-2] = 0x3f800000;
      }
      else {
        puVar11[-2] = fStack00000004 / *(float *)(iVar7 + 0x14);
      }
      iVar8 = -1;
      if ((*(byte *)(*in_stack_0000001c + 0x30) & 1) != 0) {
        iVar8 = ((*(byte *)(((*(uint *)(iVar7 + 0x5c) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0) |
                 0xffffe000) << 8 |
                 (uint)*(byte *)(((*(uint *)(iVar7 + 0x58) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0
                                ) << 0x10 |
                (uint)*(byte *)(((*(uint *)(iVar7 + 0x60) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0)
                ) << 3;
      }
      puVar11[-1] = iVar8;
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
      uVar18 = uVar18 + 1;
      puVar11[1] = (float)*(int *)(iVar7 + 100) * _DAT_10034610;
      fVar4 = (float)*(int *)(iVar7 + 0x68) * _DAT_10034610;
      if ((int)uVar17 < 1) break;
      puVar11[2] = fVar4;
      puVar11 = puVar11 + 8;
    }
    puVar11[2] = fVar4;
  }
  iVar8 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + uVar18 * -8;
  iVar7 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  if (((iVar7 == uVar18 * 0x20 || (int)(iVar7 + uVar18 * -0x20) < 0) ||
      (iVar8 == 0x6c || iVar8 + -0x6c < 0)) && (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
    return 0;
  }
  if ((int)uVar18 < 1) {
    return 0;
  }
  puVar11 = *(undefined4 **)(DAT_1003a024 + 0x28);
  iVar7 = *(int *)(DAT_1003a024 + 0x24);
  if (puVar11 != &DAT_10038b78) {
    puVar12 = &DAT_10038b78;
    puVar15 = puVar11;
    for (iVar8 = (uVar18 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
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
  *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar18 * 0x20;
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
  if ((((*(byte *)(*in_stack_0000001c + 0x30) & 2) == 0) && (DAT_100362ac == 0)) ||
     (DAT_10036068 == 0)) {
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      goto LAB_1002053f;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x88) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x88) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
LAB_1002053f:
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
  if ((in_stack_00000010 == 0) && (*(int *)(DAT_1003a024 + 0x80) == 0)) {
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
  }
  else if (*(int *)(DAT_1003a024 + 0x8c) == 0) {
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
  if (*(int *)(DAT_1003a024 + 0x94) != 0xff) {
    *(undefined4 *)(DAT_1003a024 + 0x94) = 0xff;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    DAT_10038b70 = DAT_10038b70 + 1;
  }
  iVar8 = *in_stack_0000001c;
  bVar1 = *(byte *)(iVar8 + 0x30);
  if (((bVar1 & 4) == 0) && (DAT_100362b0 == 0)) {
    if (*(int *)(*(int *)(iVar8 + 0x34) + 0x1c) == 0) {
      uVar17 = *(uint *)(DAT_1003a024 + 100);
    }
    else if ((bVar1 & 0x10) == 0) {
      uVar17 = *(uint *)(DAT_1003a024 + 0x5c);
    }
    else {
      uVar17 = *(uint *)(DAT_1003a024 + 0x54);
    }
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar17) goto LAB_10020856;
  }
  else {
    if (*(int *)(*(int *)(iVar8 + 0x34) + 0x1c) == 0) {
      uVar17 = *(uint *)(DAT_1003a024 + 0x60);
    }
    else if ((bVar1 & 0x10) == 0) {
      uVar17 = *(uint *)(DAT_1003a024 + 0x58);
    }
    else {
      uVar17 = *(uint *)(DAT_1003a024 + 0x50);
    }
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar17) goto LAB_10020856;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar17;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar17;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar17;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_10020856:
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
  sVar9 = (short)((uint)((int)puVar11 - iVar7) >> 5);
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar9;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar9;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar18;
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
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar18 + -2;
  iVar7 = 1;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  psVar14 = *(short **)(DAT_1003a024 + 0x30);
  psVar13 = psVar14;
  if (1 < (int)(uVar18 - 1)) {
    do {
      *psVar13 = sVar9;
      sVar5 = sVar9 + (short)iVar7;
      if (in_stack_00000020 == 0) {
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
    } while (iVar7 < (int)(uVar18 - 1));
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar14;
  return 0;
}


