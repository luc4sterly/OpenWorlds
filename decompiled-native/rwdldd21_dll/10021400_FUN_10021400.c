// 10021400 FUN_10021400 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10021400(int *param_1,int param_2)

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
  undefined4 *puVar10;
  undefined4 *puVar11;
  short *psVar12;
  short *psVar13;
  undefined4 unaff_EDI;
  undefined4 *puVar14;
  longlong lVar15;
  byte bVar16;
  uint uStack_2c;
  uint uStack_28;
  int *piStack_24;
  float fStack_20;
  undefined4 uStack_14;
  undefined1 auStack_8 [4];
  int iStack_4;
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (*(int *)(DAT_1003a024 + 0x70) == 0)) &&
     (*(byte *)(*param_1 + 4) < 0x80)) {
    return 0;
  }
  bVar16 = *(byte *)(*param_1 + 0x30);
  if (((bVar16 & 0x80) == 0) && (param_2 != 0)) {
    return 0;
  }
  piVar5 = (int *)FUN_10001190(*(int *)(*param_1 + 0x34),(uint)bVar16,&iStack_4);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  iVar6 = (**(code **)(*piVar5 + 0x10))(piVar5,*(undefined4 *)(DAT_1003a024 + 8),auStack_8);
  if (iVar6 != 0) {
    return 0;
  }
  piStack_24 = param_1 + 0xf;
  uStack_28 = 0;
  uStack_2c = (uint)*(byte *)((int)param_1 + 0x3a);
  if ((((*(byte *)(*param_1 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    fStack_20 = 1.0;
  }
  else {
    fStack_20 = *(float *)(*piStack_24 + 0x14);
    if (1 < uStack_2c) {
      iVar6 = uStack_2c - 1;
      piVar5 = piStack_24;
      do {
        piVar5 = piVar5 + 1;
        if (*(float *)(*piVar5 + 0x14) < fStack_20) {
          fStack_20 = *(float *)(*piVar5 + 0x14);
        }
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  if (uStack_2c != 0) {
    fVar1 = (float)DAT_10042034;
    fVar2 = (float)DAT_10042038;
    puVar10 = &DAT_10038b8c;
    while( true ) {
      uStack_2c = uStack_2c - 1;
      iVar6 = *piStack_24;
      puVar10[-5] = (float)*(int *)(iVar6 + 0x18) * _DAT_10034610 + fVar1;
      puVar10[-4] = (float)*(int *)(iVar6 + 0x1c) * _DAT_10034610 + fVar2;
      puVar10[-3] = (float)(ushort)~*(ushort *)(iVar6 + 0x22) * _DAT_10034614;
      if ((((*(byte *)(*param_1 + 0x30) & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
        puVar10[-2] = 0x3f800000;
      }
      else {
        puVar10[-2] = fStack_20 / *(float *)(iVar6 + 0x14);
      }
      bVar16 = (byte)((uint)unaff_EDI >> 0x18);
      if ((*(byte *)(*param_1 + 0x30) & 1) == 0) {
        uVar7 = (uint)bVar16 << 0x18 | 0xffffff;
      }
      else {
        uVar7 = ((uint)*(byte *)(((*(uint *)(iVar6 + 0x58) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0
                                ) << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar6 + 0x5c) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0
                                ) << 8 |
                 (uint)*(byte *)(((*(uint *)(iVar6 + 0x60) & 0x1f0000) >> 0xb) + 0x1f + DAT_100362d0
                                ) | (uint)bVar16 << 0x15) * 8;
      }
      puVar10[-1] = uVar7;
      if (_DAT_1003607c <= *(float *)(iVar6 + 0x14)) {
        if (*(float *)(iVar6 + 0x14) <= _DAT_10036080) {
          lVar15 = __ftol();
          *puVar10 = *(undefined4 *)(DAT_1003a020 + (int)lVar15 * 4);
        }
        else {
          *puVar10 = 0;
        }
      }
      else {
        *puVar10 = 0xff000000;
      }
      uStack_28 = uStack_28 + 1;
      puVar10[1] = (float)*(int *)(iVar6 + 100) * _DAT_10034610;
      fVar3 = (float)*(int *)(iVar6 + 0x68) * _DAT_10034610;
      if ((int)uStack_2c < 1) break;
      puVar10[2] = fVar3;
      puVar10 = puVar10 + 8;
      piStack_24 = piStack_24 + 1;
    }
    puVar10[2] = fVar3;
  }
  iVar8 = (*(int *)(DAT_1003a024 + 0x34) + uStack_28 * -8) - *(int *)(DAT_1003a024 + 0x30);
  iVar6 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  if (((iVar6 == uStack_28 * 0x20 || (int)(iVar6 + uStack_28 * -0x20) < 0) ||
      (iVar8 == 0x16c || iVar8 + -0x16c < 0)) && (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
    return 0;
  }
  if ((int)uStack_28 < 1) {
    return 0;
  }
  puVar10 = *(undefined4 **)(DAT_1003a024 + 0x28);
  iVar6 = *(int *)(DAT_1003a024 + 0x24);
  if (puVar10 != &DAT_10038b78) {
    puVar11 = &DAT_10038b78;
    puVar14 = puVar10;
    for (iVar8 = (uStack_28 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar14 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar14 = puVar14 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar14 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    }
  }
  *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_28 * 0x20;
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
  iVar8 = *param_1;
  bVar16 = *(byte *)(iVar8 + 0x30);
  if (((bVar16 & 4) == 0) && (DAT_100362b0 == 0)) {
    if (*(int *)(*(int *)(iVar8 + 0x34) + 0x1c) == 0) {
      uVar7 = *(uint *)(DAT_1003a024 + 100);
    }
    else if ((bVar16 & 0x10) == 0) {
      uVar7 = *(uint *)(DAT_1003a024 + 0x5c);
    }
    else {
      uVar7 = *(uint *)(DAT_1003a024 + 0x54);
    }
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar7) goto LAB_10022348;
  }
  else {
    if (*(int *)(*(int *)(iVar8 + 0x34) + 0x1c) == 0) {
      uVar7 = *(uint *)(DAT_1003a024 + 0x60);
    }
    else if ((bVar16 & 0x10) == 0) {
      uVar7 = *(uint *)(DAT_1003a024 + 0x58);
    }
    else {
      uVar7 = *(uint *)(DAT_1003a024 + 0x50);
    }
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar7) goto LAB_10022348;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar7;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar7;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar7;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_10022348:
  **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
  *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uStack_14;
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
  sVar9 = (short)((uint)((int)puVar10 - iVar6) >> 5);
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar9;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar9;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_28;
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
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uStack_28 + -2;
  iVar6 = 1;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  psVar13 = *(short **)(DAT_1003a024 + 0x30);
  psVar12 = psVar13;
  if (1 < (int)(uStack_28 - 1)) {
    do {
      *psVar12 = sVar9;
      sVar4 = sVar9 + (short)iVar6;
      if (iStack_4 == 0) {
        psVar12[1] = sVar4 + 1;
      }
      else {
        psVar12[1] = sVar4;
        sVar4 = sVar4 + 1;
      }
      psVar12[2] = sVar4;
      psVar13 = psVar12 + 4;
      psVar12[3] = 0x700;
      iVar6 = iVar6 + 1;
      psVar12 = psVar13;
    } while (iVar6 < (int)(uStack_28 - 1));
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar13;
  return 0;
}


