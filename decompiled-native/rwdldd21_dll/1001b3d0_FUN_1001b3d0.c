// 1001b3d0 FUN_1001b3d0 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001b3d0(int *param_1,uint param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  undefined4 uVar6;
  int *piVar7;
  uint *puVar8;
  byte bVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  undefined4 *puVar13;
  uint *puVar14;
  undefined4 *puVar15;
  short *psVar16;
  short *psVar17;
  undefined4 *puVar18;
  longlong lVar19;
  uint local_28;
  uint local_24;
  int *local_18;
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar6 = FUN_1001a410(param_1,param_2);
    return uVar6;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (*(int *)(DAT_1003a024 + 0x70) == 0)) &&
     (*(byte *)(*param_1 + 4) < 0x80)) {
    return 0;
  }
  bVar9 = *(byte *)(*param_1 + 0x30);
  if (((bVar9 & 0x80) != 0) || (param_2 == 0)) {
    fVar2 = _DAT_1003461c;
    if ((bVar9 & 0x40) != 0) {
      fVar2 = _DAT_10034620;
    }
    piVar7 = (int *)(DAT_1003a024 + 0x70);
    if (*piVar7 == 0) {
      bVar9 = 0xff;
    }
    else {
      bVar9 = *(byte *)(*param_1 + 4);
    }
    local_28 = 0;
    local_24 = (uint)*(byte *)((int)param_1 + 0x3a);
    if (local_24 != 0) {
      fVar3 = (float)DAT_10042034;
      fVar4 = (float)DAT_10042038;
      puVar13 = &DAT_10038b8c;
      local_18 = param_1 + 0xf;
      do {
        iVar12 = DAT_100362d0;
        local_24 = local_24 - 1;
        iVar10 = *local_18;
        puVar13[-5] = (float)*(int *)(iVar10 + 0x18) * _DAT_10034610 + fVar3;
        puVar13[-4] = (float)*(int *)(iVar10 + 0x1c) * _DAT_10034610 + fVar4;
        puVar13[-3] = (float)(ushort)~*(ushort *)(iVar10 + 0x22) * _DAT_10034614 - fVar2;
        puVar13[-2] = 0x3f800000;
        uVar1 = *(uint *)(*param_1 + 8);
        puVar13[-1] = ((uint)*(byte *)(((*(uint *)(iVar10 + 0x5c) & 0x1f0000) >> 0xb) +
                                       ((uVar1 & 0x7c0) >> 6) + iVar12) << 8 |
                       (uint)*(byte *)(((*(uint *)(iVar10 + 0x58) & 0x1f0000) >> 0xb) +
                                       ((uVar1 & 0xf800) >> 0xb) + iVar12) << 0x10 |
                       (uint)*(byte *)(((*(uint *)(iVar10 + 0x60) & 0x1f0000) >> 0xb) +
                                       (uVar1 & 0x1f) + iVar12) | (uint)bVar9 << 0x15) << 3;
        if (_DAT_1003607c <= *(float *)(iVar10 + 0x14)) {
          if (*(float *)(iVar10 + 0x14) <= _DAT_10036080) {
            lVar19 = __ftol();
            *puVar13 = *(undefined4 *)(DAT_1003a020 + (int)lVar19 * 4);
          }
          else {
            *puVar13 = 0;
          }
        }
        else {
          *puVar13 = 0xff000000;
        }
        local_28 = local_28 + 1;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar13 = puVar13 + 8;
        local_18 = local_18 + 1;
      } while (0 < (int)local_24);
    }
    if ((*piVar7 != 0) &&
       (puVar8 = FUN_10029990(local_28 * 0x20 + 0xc,FUN_10019010), puVar8 != (uint *)0x0)) {
      *puVar8 = local_28;
      puVar8[1] = param_2;
      puVar8[2] = 0;
      puVar14 = &DAT_10038b78;
      puVar8 = puVar8 + 3;
      for (iVar10 = (local_28 & 0x7ffffff) << 3; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar8 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar8 = puVar8 + 1;
      }
      DAT_1003606c = 1;
      return 0;
    }
    iVar12 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + local_28 * -8;
    iVar10 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    if (((iVar10 == local_28 * 0x20 || (int)(iVar10 + local_28 * -0x20) < 0) ||
        (iVar12 == 0x16c || iVar12 + -0x16c < 0)) &&
       (iVar10 = FUN_10001080(DAT_1003a024), iVar10 == 0)) {
      return 0;
    }
    if (0 < (int)local_28) {
      puVar13 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar10 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar13 != &DAT_10038b78) {
        puVar15 = &DAT_10038b78;
        puVar18 = puVar13;
        for (iVar12 = (local_28 & 0x7ffffff) << 3; iVar12 != 0; iVar12 = iVar12 + -1) {
          *puVar18 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar18 = puVar18 + 1;
        }
        for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
          *(undefined1 *)puVar18 = *(undefined1 *)puVar15;
          puVar15 = (undefined4 *)((int)puVar15 + 1);
          puVar18 = (undefined4 *)((int)puVar18 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + local_28 * 0x20;
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
      iVar12 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar12) {
        *(int *)(DAT_1003a024 + 0x98) = iVar12;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar12;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar12;
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
      sVar11 = (short)((uint)((int)puVar13 - iVar10) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar11;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar11;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = local_28;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)local_28 + -2;
      iVar10 = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar17 = *(short **)(DAT_1003a024 + 0x30);
      psVar16 = psVar17;
      if (1 < (int)(local_28 - 1)) {
        do {
          *psVar16 = sVar11;
          sVar5 = (short)iVar10 + sVar11;
          if (param_2 == 0) {
            psVar16[1] = sVar5 + 1;
          }
          else {
            psVar16[1] = sVar5;
            sVar5 = sVar5 + 1;
          }
          psVar16[2] = sVar5;
          psVar17 = psVar16 + 4;
          psVar16[3] = 0x700;
          iVar10 = iVar10 + 1;
          psVar16 = psVar17;
        } while (iVar10 < (int)(local_28 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar17;
    }
  }
  return 0;
}


