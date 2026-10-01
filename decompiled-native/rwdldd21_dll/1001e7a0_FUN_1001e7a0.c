// 1001e7a0 FUN_1001e7a0 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001e7a0(int *param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  short sVar5;
  undefined4 uVar6;
  int *piVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  short sVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  uint *puVar16;
  undefined4 *puVar17;
  short *psVar18;
  short *psVar19;
  undefined4 *puVar20;
  longlong lVar21;
  uint local_28;
  int *local_24;
  float local_20;
  uint local_1c;
  float local_14;
  undefined1 local_8 [4];
  int local_4;
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar6 = FUN_1001d670(param_1,param_2);
    return uVar6;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (*(int *)(DAT_1003a024 + 0x70) == 0)) &&
     (*(byte *)(*param_1 + 4) < 0x80)) {
    return 0;
  }
  iVar14 = *param_1;
  if (((*(byte *)(iVar14 + 0x30) & 0x80) == 0) && (param_2 != 0)) {
    return 0;
  }
  piVar7 = (int *)(DAT_1003a024 + 0x70);
  bVar4 = 0xff;
  if (*piVar7 != 0) {
    bVar4 = *(byte *)(iVar14 + 4);
  }
  fVar1 = _DAT_1003461c;
  if ((*(byte *)(iVar14 + 0x30) & 0x40) != 0) {
    fVar1 = _DAT_10034620;
  }
  if ((*(byte *)(iVar14 + 0x30) & 1) == 0) {
    local_1c = (uint)bVar4 << 0x18 | 0xffffff;
  }
  else {
    local_1c = ((uint)*(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0) << 0x10 |
                (uint)*(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0) << 8 |
                (uint)*(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + 0x1f + DAT_100362d0) |
               (uint)bVar4 << 0x15) << 3;
  }
  local_24 = param_1 + 0xf;
  uVar13 = 0;
  local_28 = (uint)*(byte *)((int)param_1 + 0x3a);
  if ((((*(byte *)(iVar14 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    local_20 = 1.0;
  }
  else {
    local_20 = *(float *)(*local_24 + 0x14);
    if (1 < local_28) {
      iVar14 = local_28 - 1;
      piVar12 = local_24;
      do {
        piVar12 = piVar12 + 1;
        if (*(float *)(*piVar12 + 0x14) < local_20) {
          local_20 = *(float *)(*piVar12 + 0x14);
        }
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
    }
  }
  if (local_28 != 0) {
    local_14 = (float)DAT_10042034;
    fVar2 = (float)DAT_10042038;
    puVar15 = &DAT_10038b8c;
    while( true ) {
      local_28 = local_28 - 1;
      iVar14 = *local_24;
      puVar15[-5] = (float)*(int *)(iVar14 + 0x18) * _DAT_10034610 + local_14;
      puVar15[-4] = (float)*(int *)(iVar14 + 0x1c) * _DAT_10034610 + fVar2;
      puVar15[-3] = (float)(ushort)~*(ushort *)(iVar14 + 0x22) * _DAT_10034614 - fVar1;
      if ((((*(byte *)(*param_1 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
        puVar15[-2] = 0x3f800000;
      }
      else {
        puVar15[-2] = local_20 / *(float *)(iVar14 + 0x14);
      }
      puVar15[-1] = local_1c;
      if (_DAT_1003607c <= *(float *)(iVar14 + 0x14)) {
        if (*(float *)(iVar14 + 0x14) <= _DAT_10036080) {
          lVar21 = __ftol();
          *puVar15 = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
        }
        else {
          *puVar15 = 0;
        }
      }
      else {
        *puVar15 = 0xff000000;
      }
      uVar13 = uVar13 + 1;
      puVar15[1] = (float)*(int *)(iVar14 + 100) * _DAT_10034610;
      fVar3 = (float)*(int *)(iVar14 + 0x68) * _DAT_10034610;
      if ((int)local_28 < 1) break;
      puVar15[2] = fVar3;
      puVar15 = puVar15 + 8;
      local_24 = local_24 + 1;
    }
    puVar15[2] = fVar3;
  }
  if ((*piVar7 != 0) &&
     (puVar8 = FUN_10029990(uVar13 * 0x20 + 0x14,FUN_1001f9e0), puVar8 != (uint *)0x0)) {
    *puVar8 = uVar13;
    puVar8[1] = param_2;
    puVar8[2] = 1;
    puVar8[3] = (uint)*(byte *)(*param_1 + 0x30);
    puVar8[4] = *(uint *)(*param_1 + 0x34);
    puVar16 = &DAT_10038b78;
    puVar8 = puVar8 + 5;
    for (iVar14 = (uVar13 & 0x7ffffff) << 3; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar8 = *puVar16;
      puVar16 = puVar16 + 1;
      puVar8 = puVar8 + 1;
    }
    DAT_1003606c = 1;
    return 0;
  }
  piVar7 = (int *)FUN_10001190(*(int *)(*param_1 + 0x34),(uint)*(byte *)(*param_1 + 0x30),&local_4);
  if (piVar7 == (int *)0x0) {
    return 0;
  }
  iVar14 = (**(code **)(*piVar7 + 0x10))(piVar7,*(undefined4 *)(DAT_1003a024 + 8),local_8);
  if (iVar14 != 0) {
    return 0;
  }
  iVar14 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + uVar13 * -8;
  if ((((int)((*(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28)) + uVar13 * -0x20) < 1)
      || (iVar14 == 0x16c || iVar14 + -0x16c < 0)) &&
     (iVar14 = FUN_10001080(DAT_1003a024), iVar14 == 0)) {
    return 0;
  }
  if ((int)uVar13 < 1) {
    return 0;
  }
  puVar15 = *(undefined4 **)(DAT_1003a024 + 0x28);
  iVar14 = *(int *)(DAT_1003a024 + 0x24);
  if (puVar15 != &DAT_10038b78) {
    puVar17 = &DAT_10038b78;
    puVar20 = puVar15;
    for (iVar9 = (uVar13 & 0x7ffffff) << 3; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar20 = *puVar17;
      puVar17 = puVar17 + 1;
      puVar20 = puVar20 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar20 = *(undefined1 *)puVar17;
      puVar17 = (undefined4 *)((int)puVar17 + 1);
      puVar20 = (undefined4 *)((int)puVar20 + 1);
    }
  }
  *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar13 * 0x20;
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
  if ((((*(byte *)(*param_1 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      goto LAB_1001ecda;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x88) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x88) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
LAB_1001ecda:
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
    else if (*(uint *)(DAT_1003a024 + 0x94) != (uint)*(byte *)(*param_1 + 4)) {
      *(uint *)(DAT_1003a024 + 0x94) = (uint)*(byte *)(*param_1 + 4);
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x40;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           (&DAT_1003a030)[(uint)*(byte *)(*param_1 + 4) * 0x20];
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x41;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a034 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x42;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a038 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x43;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a03c + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x44;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a040 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x45;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a044 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x46;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a048 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x47;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a04c + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x48;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a050 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x49;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a054 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4a;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a058 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4b;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a05c + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4c;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a060 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4d;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a064 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4e;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a068 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x4f;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a06c + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x50;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           (&DAT_1003a070)[(uint)*(byte *)(*param_1 + 4) * 0x20];
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x51;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a074 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x52;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a078 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x53;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a07c + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x54;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a080 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x55;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a084 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x56;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a088 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x57;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a08c + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x58;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a090 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x59;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a094 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5a;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a098 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5b;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a09c + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5c;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a0 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5d;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a4 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5e;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0a8 + (uint)*(byte *)(*param_1 + 4) * 0x80);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x5f;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) =
           *(undefined4 *)(&DAT_1003a0ac + (uint)*(byte *)(*param_1 + 4) * 0x80);
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
  iVar9 = *param_1;
  bVar4 = *(byte *)(iVar9 + 0x30);
  if (((bVar4 & 4) == 0) && (DAT_100362b0 == 0)) {
    if (*(int *)(*(int *)(iVar9 + 0x34) + 0x1c) == 0) {
      uVar10 = *(uint *)(DAT_1003a024 + 100);
    }
    else if ((bVar4 & 0x10) == 0) {
      uVar10 = *(uint *)(DAT_1003a024 + 0x5c);
    }
    else {
      uVar10 = *(uint *)(DAT_1003a024 + 0x54);
    }
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar10) goto LAB_1001f7da;
  }
  else {
    if (*(int *)(*(int *)(iVar9 + 0x34) + 0x1c) == 0) {
      uVar10 = *(uint *)(DAT_1003a024 + 0x60);
    }
    else if ((bVar4 & 0x10) == 0) {
      uVar10 = *(uint *)(DAT_1003a024 + 0x58);
    }
    else {
      uVar10 = *(uint *)(DAT_1003a024 + 0x50);
    }
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar10) goto LAB_1001f7da;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar10;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar10;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar10;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_1001f7da:
  **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
  *(float *)(*(int *)(DAT_1003a024 + 0x30) + 4) = local_14;
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
  sVar11 = (short)((uint)((int)puVar15 - iVar14) >> 5);
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar11;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar13;
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
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar13 + -2;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  iVar14 = 1;
  psVar19 = *(short **)(DAT_1003a024 + 0x30);
  psVar18 = psVar19;
  if (1 < (int)(uVar13 - 1)) {
    do {
      *psVar18 = sVar11;
      sVar5 = (short)iVar14 + sVar11;
      if (local_4 == 0) {
        psVar18[1] = sVar5 + 1;
      }
      else {
        psVar18[1] = sVar5;
        sVar5 = sVar5 + 1;
      }
      psVar18[2] = sVar5;
      psVar19 = psVar18 + 4;
      psVar18[3] = 0x700;
      iVar14 = iVar14 + 1;
      psVar18 = psVar19;
    } while (iVar14 < (int)(uVar13 - 1));
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar19;
  return 0;
}


