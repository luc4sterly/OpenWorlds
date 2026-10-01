// 100180a0 FUN_100180a0 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_100180a0(int *param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  int *piVar9;
  undefined4 uVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  short sVar14;
  uint uVar15;
  int *piVar16;
  uint *puVar17;
  undefined4 *puVar18;
  short *psVar19;
  short *psVar20;
  undefined4 *puVar21;
  undefined4 *puVar22;
  longlong lVar23;
  uint local_20;
  uint local_18;
  
  piVar9 = (int *)(DAT_1003a024 + 0x70);
  iVar12 = *piVar9;
  if (iVar12 == 0) {
    local_20 = 0xff;
  }
  else {
    local_20 = (uint)*(byte *)(*param_1 + 4);
  }
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar10 = FUN_100170a0(param_1,param_2);
    return uVar10;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (iVar12 == 0)) && (*(byte *)(*param_1 + 4) < 0x80)) {
    return 0;
  }
  uVar15 = *(uint *)(*param_1 + 8);
  bVar1 = *(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar15 & 0x7c0) >> 6) + DAT_100362d0);
  bVar2 = *(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar15 & 0xf800) >> 0xb) + DAT_100362d0);
  bVar3 = *(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar15 & 0x1f) + DAT_100362d0);
  bVar4 = *(byte *)(*param_1 + 0x30);
  if (((bVar4 & 0x80) != 0) || (param_2 == 0)) {
    fVar5 = _DAT_1003461c;
    if ((bVar4 & 0x40) != 0) {
      fVar5 = _DAT_10034620;
    }
    piVar16 = param_1 + 0xf;
    local_18 = (uint)*(byte *)((int)param_1 + 0x3a);
    uVar15 = 0;
    if (local_18 != 0) {
      fVar6 = (float)DAT_10042034;
      fVar7 = (float)DAT_10042038;
      puVar21 = &DAT_10038b8c;
      do {
        local_18 = local_18 - 1;
        iVar12 = *piVar16;
        piVar16 = piVar16 + 1;
        puVar21[-5] = (float)*(int *)(iVar12 + 0x18) * _DAT_10034610 + fVar6;
        puVar21[-4] = (float)*(int *)(iVar12 + 0x1c) * _DAT_10034610 + fVar7;
        puVar21[-3] = (float)(ushort)~*(ushort *)(iVar12 + 0x22) * _DAT_10034614 - fVar5;
        puVar21[-2] = 0x3f800000;
        puVar21[-1] = ((uint)bVar1 << 8 | (uint)bVar2 << 0x10 | (uint)bVar3 | local_20 << 0x15) << 3
        ;
        if (_DAT_1003607c <= *(float *)(iVar12 + 0x14)) {
          if (*(float *)(iVar12 + 0x14) <= _DAT_10036080) {
            lVar23 = __ftol();
            *puVar21 = *(undefined4 *)(DAT_1003a020 + (int)lVar23 * 4);
          }
          else {
            *puVar21 = 0;
          }
        }
        else {
          *puVar21 = 0xff000000;
        }
        uVar15 = uVar15 + 1;
        puVar21[1] = 0;
        puVar21[2] = 0;
        puVar21 = puVar21 + 8;
      } while (0 < (int)local_18);
    }
    if ((*piVar9 != 0) &&
       (puVar11 = FUN_10029990(uVar15 * 0x20 + 0xc,FUN_10019010), puVar11 != (uint *)0x0)) {
      *puVar11 = uVar15;
      puVar11[1] = param_2;
      puVar11[2] = 1;
      puVar17 = &DAT_10038b78;
      puVar11 = puVar11 + 3;
      for (iVar12 = (uVar15 & 0x7ffffff) << 3; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar11 = *puVar17;
        puVar17 = puVar17 + 1;
        puVar11 = puVar11 + 1;
      }
      DAT_1003606c = 1;
      return 0;
    }
    iVar12 = (*(int *)(DAT_1003a024 + 0x34) + uVar15 * -8) - *(int *)(DAT_1003a024 + 0x30);
    if ((((int)((*(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28)) + uVar15 * -0x20) <
          1) || (iVar12 == 0x16c || iVar12 + -0x16c < 0)) &&
       (iVar12 = FUN_10001080(DAT_1003a024), iVar12 == 0)) {
      return 0;
    }
    if (0 < (int)uVar15) {
      puVar21 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar12 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar21 != &DAT_10038b78) {
        puVar18 = &DAT_10038b78;
        puVar22 = puVar21;
        for (iVar13 = (uVar15 & 0x7ffffff) << 3; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar22 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar22 = puVar22 + 1;
        }
        for (iVar13 = 0; iVar13 != 0; iVar13 = iVar13 + -1) {
          *(undefined1 *)puVar22 = *(undefined1 *)puVar18;
          puVar18 = (undefined4 *)((int)puVar18 + 1);
          puVar22 = (undefined4 *)((int)puVar22 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar15 * 0x20;
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
      if (*(int *)(DAT_1003a024 + 0x88) != 0) {
        *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
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
      iVar13 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar13) {
        *(int *)(DAT_1003a024 + 0x98) = iVar13;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar13;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar13;
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
      sVar14 = (short)((uint)((int)puVar21 - iVar12) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar14;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar14;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar15;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar15 + -2;
      iVar12 = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar20 = *(short **)(DAT_1003a024 + 0x30);
      psVar19 = psVar20;
      if (1 < (int)(uVar15 - 1)) {
        do {
          *psVar19 = sVar14;
          sVar8 = sVar14 + (short)iVar12;
          if (param_2 == 0) {
            psVar19[1] = sVar8 + 1;
          }
          else {
            psVar19[1] = sVar8;
            sVar8 = sVar8 + 1;
          }
          psVar19[2] = sVar8;
          psVar20 = psVar19 + 4;
          psVar19[3] = 0x700;
          iVar12 = iVar12 + 1;
          psVar19 = psVar20;
        } while (iVar12 < (int)(uVar15 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar20;
    }
  }
  return 0;
}


