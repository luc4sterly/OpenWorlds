// 1001c370 FUN_1001c370 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001c370(int *param_1,int param_2)

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
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  short *psVar14;
  short *psVar15;
  undefined4 *puVar16;
  longlong lVar17;
  uint uVar18;
  float fStack_24;
  int iStack_20;
  int iStack_14;
  undefined4 uStack_10;
  int *piStack_8;
  int iStack_4;
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  bVar1 = *(byte *)(*param_1 + 0x30);
  if (((bVar1 & 0x80) == 0) && (param_2 != 0)) {
    return 0;
  }
  piVar6 = (int *)FUN_10001190(*(int *)(*param_1 + 0x34),(uint)bVar1,&piStack_8);
  if (piVar6 == (int *)0x0) {
    return 0;
  }
  iVar7 = (**(code **)(*piVar6 + 0x10))(piVar6,*(undefined4 *)(DAT_1003a024 + 8),&iStack_4);
  if (iVar7 != 0) {
    return 0;
  }
  if ((*(byte *)(*piStack_8 + 0x30) & 1) == 0) {
    iStack_20 = -1;
  }
  else {
    iStack_20 = ((*(byte *)(((piStack_8[2] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0) | 0xffffe000)
                 << 8 | (uint)*(byte *)(((piStack_8[1] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0)
                        << 0x10 |
                (uint)*(byte *)(((piStack_8[3] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0)) << 3;
  }
  piVar6 = piStack_8 + 0xf;
  uVar11 = 0;
  uVar18 = (uint)*(byte *)((int)piStack_8 + 0x3a);
  if ((((*(byte *)(*piStack_8 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    fStack_24 = 1.0;
  }
  else {
    fStack_24 = *(float *)(*piVar6 + 0x14);
    if (1 < uVar18) {
      piVar10 = piStack_8 + 0x10;
      iVar7 = uVar18 - 1;
      do {
        if (*(float *)(*piVar10 + 0x14) < fStack_24) {
          fStack_24 = *(float *)(*piVar10 + 0x14);
        }
        piVar10 = piVar10 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  if (uVar18 != 0) {
    fVar2 = (float)DAT_10042034;
    fVar3 = (float)DAT_10042038;
    puVar12 = &DAT_10038b8c;
    while( true ) {
      uVar18 = uVar18 - 1;
      iVar7 = *piVar6;
      piVar6 = piVar6 + 1;
      puVar12[-5] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar2;
      puVar12[-4] = (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar3;
      puVar12[-3] = (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614;
      if ((((*(byte *)(*piStack_8 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0))
      {
        puVar12[-2] = 0x3f800000;
      }
      else {
        puVar12[-2] = fStack_24 / *(float *)(iVar7 + 0x14);
      }
      puVar12[-1] = iStack_20;
      if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
        if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
          lVar17 = __ftol();
          *puVar12 = *(undefined4 *)(DAT_1003a020 + (int)lVar17 * 4);
        }
        else {
          *puVar12 = 0;
        }
      }
      else {
        *puVar12 = 0xff000000;
      }
      uVar11 = uVar11 + 1;
      puVar12[1] = (float)*(int *)(iVar7 + 100) * _DAT_10034610;
      fVar4 = (float)*(int *)(iVar7 + 0x68) * _DAT_10034610;
      if ((int)uVar18 < 1) break;
      puVar12[2] = fVar4;
      puVar12 = puVar12 + 8;
    }
    puVar12[2] = fVar4;
  }
  iVar7 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + uVar11 * -8;
  if ((((int)((*(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28)) + uVar11 * -0x20) < 1)
      || (iVar7 == 0x6c || iVar7 + -0x6c < 0)) && (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0))
  {
    return 0;
  }
  if ((int)uVar11 < 1) {
    return 0;
  }
  puVar12 = *(undefined4 **)(DAT_1003a024 + 0x28);
  iVar7 = *(int *)(DAT_1003a024 + 0x24);
  if (puVar12 != &DAT_10038b78) {
    puVar13 = &DAT_10038b78;
    puVar16 = puVar12;
    for (iVar8 = (uVar11 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar16 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar16 = puVar16 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar16 = *(undefined1 *)puVar13;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      puVar16 = (undefined4 *)((int)puVar16 + 1);
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
  if ((((*(byte *)(*piStack_8 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      goto LAB_1001c7c0;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x88) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x88) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
LAB_1001c7c0:
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
  if ((iStack_14 == 0) && (*(int *)(DAT_1003a024 + 0x80) == 0)) {
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
  iVar8 = *piStack_8;
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
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar18) goto LAB_1001cae0;
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
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar18) goto LAB_1001cae0;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar18;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar18;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar18;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_1001cae0:
  **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
  *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uStack_10;
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
  sVar9 = (short)((uint)((int)puVar12 - iVar7) >> 5);
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
      sVar5 = sVar9 + (short)iVar7;
      if (iStack_4 == 0) {
        psVar14[1] = sVar5 + 1;
      }
      else {
        psVar14[1] = sVar5;
        sVar5 = sVar5 + 1;
      }
      psVar14[2] = sVar5;
      psVar15 = psVar14 + 4;
      psVar14[3] = 0x700;
      iVar7 = iVar7 + 1;
      psVar14 = psVar15;
    } while (iVar7 < (int)(uVar11 - 1));
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar15;
  return 0;
}


