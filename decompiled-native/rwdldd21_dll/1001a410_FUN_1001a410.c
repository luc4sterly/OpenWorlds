// 1001a410 FUN_1001a410 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001a410(int *param_1,int param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  short sVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  short *psVar11;
  short *psVar12;
  undefined4 *puVar13;
  longlong lVar14;
  uint uStack_24;
  uint uStack_20;
  uint uStack_18;
  uint uStack_14;
  int *piStack_10;
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(int *)(DAT_1003a024 + 0x6c) == 0) && (*(int *)(DAT_1003a024 + 0x70) == 0)) &&
     (*(byte *)(*param_1 + 4) < 0x80)) {
    return 0;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    bVar6 = 0xff;
    if (*(int *)(DAT_1003a024 + 0x70) != 0) {
      bVar6 = *(byte *)(*param_1 + 4);
    }
    uStack_24 = 0;
    uStack_18 = (uint)*(byte *)((int)param_1 + 0x3a);
    if (uStack_18 != 0) {
      fVar2 = (float)DAT_10042034;
      fVar3 = (float)DAT_10042038;
      puVar9 = &DAT_10038b8c;
      piStack_10 = param_1 + 0xf;
      do {
        uStack_18 = uStack_18 - 1;
        iVar5 = *piStack_10;
        puVar9[-5] = (float)*(int *)(iVar5 + 0x18) * _DAT_10034610 + fVar2;
        puVar9[-4] = (float)*(int *)(iVar5 + 0x1c) * _DAT_10034610 + fVar3;
        puVar9[-3] = (float)(ushort)~*(ushort *)(iVar5 + 0x22) * _DAT_10034614;
        puVar9[-2] = 0x3f800000;
        uVar1 = *(uint *)(*param_1 + 8);
        uStack_14 = (uint)*(byte *)(((*(uint *)(iVar5 + 0x58) & 0x1f0000) >> 0xb) +
                                    ((uVar1 & 0xf800) >> 0xb) + DAT_100362d0);
        uStack_20 = (uint)*(byte *)(((*(uint *)(iVar5 + 0x60) & 0x1f0000) >> 0xb) + (uVar1 & 0x1f) +
                                   DAT_100362d0);
        puVar9[-1] = ((uint)*(byte *)(((*(uint *)(iVar5 + 0x5c) & 0x1f0000) >> 0xb) +
                                      ((uVar1 & 0x7c0) >> 6) + DAT_100362d0) << 8 |
                      uStack_14 << 0x10 | uStack_20 | (uint)bVar6 << 0x15) << 3;
        if (_DAT_1003607c <= *(float *)(iVar5 + 0x14)) {
          if (*(float *)(iVar5 + 0x14) <= _DAT_10036080) {
            lVar14 = __ftol();
            *puVar9 = *(undefined4 *)(DAT_1003a020 + (int)lVar14 * 4);
          }
          else {
            *puVar9 = 0;
          }
        }
        else {
          *puVar9 = 0xff000000;
        }
        uStack_24 = uStack_24 + 1;
        puVar9[1] = 0;
        puVar9[2] = 0;
        puVar9 = puVar9 + 8;
        piStack_10 = piStack_10 + 1;
      } while (0 < (int)uStack_18);
    }
    iVar7 = (*(int *)(DAT_1003a024 + 0x34) + uStack_24 * -8) - *(int *)(DAT_1003a024 + 0x30);
    iVar5 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    if (((iVar5 == uStack_24 * 0x20 || (int)(iVar5 + uStack_24 * -0x20) < 0) ||
        (iVar7 == 0x16c || iVar7 + -0x16c < 0)) && (iVar5 = FUN_10001080(DAT_1003a024), iVar5 == 0))
    {
      return 0;
    }
    if (0 < (int)uStack_24) {
      puVar9 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar5 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar9 != &DAT_10038b78) {
        puVar10 = &DAT_10038b78;
        puVar13 = puVar9;
        for (iVar7 = (uStack_24 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar13 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar13 = puVar13 + 1;
        }
        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined1 *)puVar13 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar13 = (undefined4 *)((int)puVar13 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_24 * 0x20;
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
      iVar7 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar7) {
        *(int *)(DAT_1003a024 + 0x98) = iVar7;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar7;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar7;
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
      sVar8 = (short)((uint)((int)puVar9 - iVar5) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar8;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar8;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_24;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uStack_24 + -2;
      iVar5 = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar12 = *(short **)(DAT_1003a024 + 0x30);
      psVar11 = psVar12;
      if (1 < (int)(uStack_24 - 1)) {
        do {
          *psVar11 = sVar8;
          sVar4 = sVar8 + (short)iVar5;
          if (param_2 == 0) {
            psVar11[1] = sVar4 + 1;
          }
          else {
            psVar11[1] = sVar4;
            sVar4 = sVar4 + 1;
          }
          psVar11[2] = sVar4;
          psVar12 = psVar11 + 4;
          psVar11[3] = 0x700;
          iVar5 = iVar5 + 1;
          psVar11 = psVar12;
        } while (iVar5 < (int)(uStack_24 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar12;
    }
  }
  return 0;
}


