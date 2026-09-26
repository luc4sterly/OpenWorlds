// 1001cce0 FUN_1001cce0 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001cce0(int *param_1,int param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  int *piVar11;
  uint uVar12;
  undefined4 *puVar13;
  short *psVar14;
  short *psVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  longlong lVar18;
  uint uVar19;
  float fStack_28;
  int iStack_24;
  float fStack_18;
  int iStack_14;
  undefined4 uStack_10;
  int *local_8;
  int local_4;
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar6 = FUN_1001c370(param_1,param_2);
    return uVar6;
  }
  bVar1 = *(byte *)(*param_1 + 0x30);
  if (((bVar1 & 0x80) == 0) && (param_2 != 0)) {
    return 0;
  }
  piVar7 = (int *)FUN_10001190(*(int *)(*param_1 + 0x34),(uint)bVar1,&local_8);
  if (piVar7 == (int *)0x0) {
    return 0;
  }
  iVar8 = (**(code **)(*piVar7 + 0x10))(piVar7,*(undefined4 *)(DAT_1003a024 + 8),&local_4);
  if (iVar8 != 0) {
    return 0;
  }
  if ((*(byte *)(*local_8 + 0x30) & 1) == 0) {
    iStack_24 = -1;
  }
  else {
    iStack_24 = ((*(byte *)(((local_8[1] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0) | 0xffffffe0)
                 << 0x10 | (uint)*(byte *)(((local_8[2] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0)
                           << 8 |
                (uint)*(byte *)(((local_8[3] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0)) << 3;
  }
  piVar7 = local_8 + 0xf;
  uVar12 = 0;
  uVar19 = (uint)*(byte *)((int)local_8 + 0x3a);
  if ((((*(byte *)(*local_8 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    fStack_28 = 1.0;
  }
  else {
    fStack_28 = *(float *)(*piVar7 + 0x14);
    if (1 < uVar19) {
      piVar11 = local_8 + 0x10;
      iVar8 = uVar19 - 1;
      do {
        if (*(float *)(*piVar11 + 0x14) < fStack_28) {
          fStack_28 = *(float *)(*piVar11 + 0x14);
        }
        piVar11 = piVar11 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  if (uVar19 != 0) {
    fVar2 = (float)DAT_10042034;
    fVar3 = (float)DAT_10042038;
    puVar16 = &DAT_10038b8c;
    while( true ) {
      uVar19 = uVar19 - 1;
      iVar8 = *piVar7;
      piVar7 = piVar7 + 1;
      puVar16[-5] = (float)*(int *)(iVar8 + 0x18) * _DAT_10034610 + fVar2;
      puVar16[-4] = (float)*(int *)(iVar8 + 0x1c) * _DAT_10034610 + fVar3;
      puVar16[-3] = (float)(ushort)~*(ushort *)(iVar8 + 0x22) * _DAT_10034614 - fStack_18;
      if ((((*(byte *)(*local_8 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
        puVar16[-2] = 0x3f800000;
      }
      else {
        puVar16[-2] = fStack_28 / *(float *)(iVar8 + 0x14);
      }
      puVar16[-1] = iStack_24;
      if (_DAT_1003607c <= *(float *)(iVar8 + 0x14)) {
        if (*(float *)(iVar8 + 0x14) <= _DAT_10036080) {
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
      uVar12 = uVar12 + 1;
      puVar16[1] = (float)*(int *)(iVar8 + 100) * _DAT_10034610;
      fVar4 = (float)*(int *)(iVar8 + 0x68) * _DAT_10034610;
      if ((int)uVar19 < 1) break;
      puVar16[2] = fVar4;
      puVar16 = puVar16 + 8;
    }
    puVar16[2] = fVar4;
  }
  iVar8 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + uVar12 * -8;
  if ((((int)((*(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28)) + uVar12 * -0x20) < 1)
      || (iVar8 == 0x6c || iVar8 + -0x6c < 0)) && (iVar8 = FUN_10001080(DAT_1003a024), iVar8 == 0))
  {
    return 0;
  }
  if ((int)uVar12 < 1) {
    return 0;
  }
  puVar16 = *(undefined4 **)(DAT_1003a024 + 0x28);
  iVar8 = *(int *)(DAT_1003a024 + 0x24);
  if (puVar16 != &DAT_10038b78) {
    puVar13 = &DAT_10038b78;
    puVar17 = puVar16;
    for (iVar9 = (uVar12 & 0x7ffffff) << 3; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar17 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar17 = puVar17 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar17 = *(undefined1 *)puVar13;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      puVar17 = (undefined4 *)((int)puVar17 + 1);
    }
  }
  *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar12 * 0x20;
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
  if ((((*(byte *)(*local_8 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      goto LAB_1001d14b;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x88) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x88) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
LAB_1001d14b:
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
  iVar9 = *local_8;
  bVar1 = *(byte *)(iVar9 + 0x30);
  if (((bVar1 & 4) == 0) && (DAT_100362b0 == 0)) {
    if (*(int *)(*(int *)(iVar9 + 0x34) + 0x1c) == 0) {
      uVar19 = *(uint *)(DAT_1003a024 + 100);
    }
    else if ((bVar1 & 0x10) == 0) {
      uVar19 = *(uint *)(DAT_1003a024 + 0x5c);
    }
    else {
      uVar19 = *(uint *)(DAT_1003a024 + 0x54);
    }
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar19) goto LAB_1001d46e;
  }
  else {
    if (*(int *)(*(int *)(iVar9 + 0x34) + 0x1c) == 0) {
      uVar19 = *(uint *)(DAT_1003a024 + 0x60);
    }
    else if ((bVar1 & 0x10) == 0) {
      uVar19 = *(uint *)(DAT_1003a024 + 0x58);
    }
    else {
      uVar19 = *(uint *)(DAT_1003a024 + 0x50);
    }
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar19) goto LAB_1001d46e;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar19;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar19;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar19;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_1001d46e:
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
  sVar10 = (short)((uint)((int)puVar16 - iVar8) >> 5);
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar10;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar10;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar12;
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
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar12 + -2;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  iVar8 = 1;
  psVar15 = *(short **)(DAT_1003a024 + 0x30);
  psVar14 = psVar15;
  if (1 < (int)(uVar12 - 1)) {
    do {
      *psVar14 = sVar10;
      sVar5 = (short)iVar8 + sVar10;
      if (local_4 == 0) {
        psVar14[1] = sVar5 + 1;
      }
      else {
        psVar14[1] = sVar5;
        sVar5 = sVar5 + 1;
      }
      psVar14[2] = sVar5;
      psVar15 = psVar14 + 4;
      psVar14[3] = 0x700;
      iVar8 = iVar8 + 1;
      psVar14 = psVar15;
    } while (iVar8 < (int)(uVar12 - 1));
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar15;
  return 0;
}


