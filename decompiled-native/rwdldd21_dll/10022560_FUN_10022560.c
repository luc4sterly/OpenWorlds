// 10022560 FUN_10022560 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10022560(int *param_1,uint param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  short sVar10;
  int *piVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  undefined4 *puVar16;
  short *psVar17;
  short *psVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  longlong lVar21;
  byte local_31;
  uint local_30;
  uint local_28;
  int *local_24;
  float local_20;
  uint local_1c;
  float local_14;
  undefined1 local_8 [4];
  int local_4;
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar6 = FUN_10021400(param_1,param_2);
    return uVar6;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (*(int *)(DAT_1003a024 + 0x70) == 0)) &&
     (*(byte *)(*param_1 + 4) < 0x80)) {
    return 0;
  }
  bVar1 = *(byte *)(*param_1 + 0x30);
  if (((bVar1 & 0x80) == 0) && (param_2 != 0)) {
    return 0;
  }
  piVar11 = (int *)(DAT_1003a024 + 0x70);
  if (*piVar11 == 0) {
    local_31 = 0xff;
  }
  else {
    local_31 = *(byte *)(*param_1 + 4);
  }
  fVar2 = _DAT_1003461c;
  if ((bVar1 & 0x40) != 0) {
    fVar2 = _DAT_10034620;
  }
  local_24 = param_1 + 0xf;
  uVar13 = 0;
  local_28 = (uint)*(byte *)((int)param_1 + 0x3a);
  if ((((bVar1 & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
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
    fVar3 = (float)DAT_10042038;
    puVar19 = &DAT_10038b8c;
    while( true ) {
      local_28 = local_28 - 1;
      iVar14 = *local_24;
      puVar19[-5] = (float)*(int *)(iVar14 + 0x18) * _DAT_10034610 + local_14;
      puVar19[-4] = (float)*(int *)(iVar14 + 0x1c) * _DAT_10034610 + fVar3;
      puVar19[-3] = (float)(ushort)~*(ushort *)(iVar14 + 0x22) * _DAT_10034614 - fVar2;
      if ((((*(byte *)(*param_1 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
        puVar19[-2] = 0x3f800000;
      }
      else {
        puVar19[-2] = local_20 / *(float *)(iVar14 + 0x14);
      }
      if ((*(byte *)(*param_1 + 0x30) & 1) == 0) {
        uVar7 = (uint)local_31 << 0x18 | 0xffffff;
      }
      else {
        local_1c = (uint)*(byte *)(((*(uint *)(iVar14 + 0x58) & 0x1f0000) >> 0xb) + 0x1f +
                                  DAT_100362d0);
        local_30 = (uint)*(byte *)(((*(uint *)(iVar14 + 0x60) & 0x1f0000) >> 0xb) + 0x1f +
                                  DAT_100362d0);
        uVar7 = ((uint)*(byte *)(((*(uint *)(iVar14 + 0x5c) & 0x1f0000) >> 0xb) + 0x1f +
                                DAT_100362d0) << 8 | local_1c << 0x10 | local_30 |
                (uint)local_31 << 0x15) * 8;
      }
      puVar19[-1] = uVar7;
      if (_DAT_1003607c <= *(float *)(iVar14 + 0x14)) {
        if (*(float *)(iVar14 + 0x14) <= _DAT_10036080) {
          lVar21 = __ftol();
          *puVar19 = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
        }
        else {
          *puVar19 = 0;
        }
      }
      else {
        *puVar19 = 0xff000000;
      }
      uVar13 = uVar13 + 1;
      puVar19[1] = (float)*(int *)(iVar14 + 100) * _DAT_10034610;
      fVar4 = (float)*(int *)(iVar14 + 0x68) * _DAT_10034610;
      if ((int)local_28 < 1) break;
      puVar19[2] = fVar4;
      puVar19 = puVar19 + 8;
      local_24 = local_24 + 1;
    }
    puVar19[2] = fVar4;
  }
  if ((*piVar11 != 0) &&
     (puVar8 = FUN_10029990(uVar13 * 0x20 + 0x14,FUN_1001f9e0), puVar8 != (uint *)0x0)) {
    *puVar8 = uVar13;
    puVar8[1] = param_2;
    puVar8[2] = 0;
    puVar8[3] = (uint)*(byte *)(*param_1 + 0x30);
    puVar8[4] = *(uint *)(*param_1 + 0x34);
    puVar15 = &DAT_10038b78;
    puVar8 = puVar8 + 5;
    for (iVar14 = (uVar13 & 0x7ffffff) << 3; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar8 = *puVar15;
      puVar15 = puVar15 + 1;
      puVar8 = puVar8 + 1;
    }
    DAT_1003606c = 1;
    return 0;
  }
  piVar11 = (int *)FUN_10001190(*(int *)(*param_1 + 0x34),(uint)*(byte *)(*param_1 + 0x30),&local_4)
  ;
  if (piVar11 == (int *)0x0) {
    return 0;
  }
  iVar14 = (**(code **)(*piVar11 + 0x10))(piVar11,*(undefined4 *)(DAT_1003a024 + 8),local_8);
  if (iVar14 != 0) {
    return 0;
  }
  iVar14 = (*(int *)(DAT_1003a024 + 0x34) + uVar13 * -8) - *(int *)(DAT_1003a024 + 0x30);
  if ((((int)((*(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28)) + uVar13 * -0x20) < 1)
      || (iVar14 == 0x16c || iVar14 + -0x16c < 0)) &&
     (iVar14 = FUN_10001080(DAT_1003a024), iVar14 == 0)) {
    return 0;
  }
  if ((int)uVar13 < 1) {
    return 0;
  }
  puVar19 = *(undefined4 **)(DAT_1003a024 + 0x28);
  iVar14 = *(int *)(DAT_1003a024 + 0x24);
  if (puVar19 != &DAT_10038b78) {
    puVar16 = &DAT_10038b78;
    puVar20 = puVar19;
    for (iVar9 = (uVar13 & 0x7ffffff) << 3; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar20 = *puVar16;
      puVar16 = puVar16 + 1;
      puVar20 = puVar20 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar20 = *(undefined1 *)puVar16;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
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
  if (*(int *)(DAT_1003a024 + 0x84) != 0) {
    *(undefined4 *)(DAT_1003a024 + 0x84) = 0;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    DAT_10038b70 = DAT_10038b70 + 1;
  }
  if ((((*(byte *)(*param_1 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      goto LAB_10022ad1;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x88) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x88) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
LAB_10022ad1:
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
  bVar1 = *(byte *)(iVar9 + 0x30);
  if (((bVar1 & 4) == 0) && (DAT_100362b0 == 0)) {
    if (*(int *)(*(int *)(iVar9 + 0x34) + 0x1c) == 0) {
      uVar7 = *(uint *)(DAT_1003a024 + 100);
    }
    else if ((bVar1 & 0x10) == 0) {
      uVar7 = *(uint *)(DAT_1003a024 + 0x5c);
    }
    else {
      uVar7 = *(uint *)(DAT_1003a024 + 0x54);
    }
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar7) goto LAB_100235d1;
  }
  else {
    if (*(int *)(*(int *)(iVar9 + 0x34) + 0x1c) == 0) {
      uVar7 = *(uint *)(DAT_1003a024 + 0x60);
    }
    else if ((bVar1 & 0x10) == 0) {
      uVar7 = *(uint *)(DAT_1003a024 + 0x58);
    }
    else {
      uVar7 = *(uint *)(DAT_1003a024 + 0x50);
    }
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar7) goto LAB_100235d1;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar7;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar7;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar7;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_100235d1:
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
  sVar10 = (short)((uint)((int)puVar19 - iVar14) >> 5);
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar10;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar10;
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
  psVar18 = *(short **)(DAT_1003a024 + 0x30);
  psVar17 = psVar18;
  if (1 < (int)(uVar13 - 1)) {
    do {
      *psVar17 = sVar10;
      sVar5 = sVar10 + (short)iVar14;
      if (local_4 == 0) {
        psVar17[1] = sVar5 + 1;
      }
      else {
        psVar17[1] = sVar5;
        sVar5 = sVar5 + 1;
      }
      psVar17[2] = sVar5;
      psVar18 = psVar17 + 4;
      psVar17[3] = 0x700;
      iVar14 = iVar14 + 1;
      psVar17 = psVar18;
    } while (iVar14 < (int)(uVar13 - 1));
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar18;
  return 0;
}


