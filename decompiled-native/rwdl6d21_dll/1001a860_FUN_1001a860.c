// 1001a860 FUN_1001a860 [Global]
// program: RWDL6D21.DLL

void FUN_1001a860(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  ushort *puVar15;
  int iVar16;
  int iVar17;
  
  iVar1 = DAT_1007bda4;
  iVar6 = param_3;
  iVar12 = param_4;
  iVar2 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar6 = param_2;
      iVar12 = param_3;
      iVar2 = param_4;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1001a898;
  param_2 = iVar12;
  param_4 = iVar6;
  param_3 = iVar2;
LAB_1001a898:
  uVar7 = (uint)*(short *)(param_2 + 0x1e);
  iVar9 = (int)*(short *)(param_2 + 0x1a);
  iVar12 = (int)*(short *)(param_3 + 0x1e) - uVar7;
  iVar13 = (int)*(short *)(param_3 + 0x1a);
  iVar2 = (int)*(short *)(param_4 + 0x1a);
  uVar3 = (uint)*(byte *)(*param_1 + 4);
  uVar14 = *(uint *)(*param_1 + 8);
  uVar11 = (ushort)*(byte *)((param_1[2] >> 0x10) * 0x20 + ((uVar14 & 0x7c0) >> 6) + 0x400 +
                            DAT_10079220) << 6 |
           (ushort)*(byte *)((param_1[1] >> 0x10) * 0x20 + ((uVar14 & 0xf800) >> 0xb) + DAT_10079220
                            ) << 0xb |
           (ushort)*(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar14 & 0x1f) + 0x800 + DAT_10079220);
  iVar4 = DAT_10079214 + 0x1000;
  iVar6 = *(int *)(DAT_10079218 + uVar7 * 4);
  uVar14 = *(uint *)(DAT_10079228 + (uVar7 & 7) * 4);
  if (iVar12 < 1) {
    if (iVar9 == iVar13 || iVar9 - iVar13 < 0) {
      return;
    }
    iVar12 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iVar12 == 0) {
      return;
    }
    iVar16 = iVar2 - iVar13;
    if (iVar12 == 1) {
      iVar16 = iVar16 * 0x10000;
    }
    else if (iVar12 == 2) {
      iVar16 = iVar16 * 0x8000;
    }
    else if (((iVar12 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      iVar16 = *(int *)(iVar4 + (iVar16 * 0x20 + iVar12) * 4);
    }
    else if (iVar16 < 0) {
      iVar16 = (iVar16 * 0x10000) / iVar12;
    }
    else {
      iVar16 = (iVar16 * 0x10000) / iVar12;
    }
    iVar2 = iVar2 - iVar9;
    if (iVar12 == 1) {
      iVar8 = iVar2 * 0x10000;
    }
    else if (iVar12 == 2) {
      iVar8 = iVar2 * 0x8000;
    }
    else if (((iVar12 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      iVar8 = *(int *)(iVar4 + (iVar2 * 0x20 + iVar12) * 4);
    }
    else if (iVar2 < 0) {
      iVar8 = (iVar2 * 0x10000) / iVar12;
    }
    else {
      iVar8 = (iVar2 * 0x10000) / iVar12;
    }
    uVar10 = iVar9 << 0x10;
    uVar7 = iVar13 << 0x10;
  }
  else {
    iVar16 = iVar13 - iVar9;
    if (iVar12 == 1) {
      iVar16 = iVar16 * 0x10000;
    }
    else if (iVar12 == 2) {
      iVar16 = iVar16 * 0x8000;
    }
    else if (((iVar12 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      iVar16 = *(int *)(iVar4 + (iVar16 * 0x20 + iVar12) * 4);
    }
    else if (iVar16 < 0) {
      iVar16 = (iVar16 * 0x10000) / iVar12;
    }
    else {
      iVar16 = (iVar16 * 0x10000) / iVar12;
    }
    iVar17 = (int)*(short *)(param_4 + 0x1e) - uVar7;
    if (iVar17 < 1) {
      if (iVar2 == iVar9 || iVar2 - iVar9 < 0) {
        return;
      }
      iVar13 = iVar13 - iVar2;
      if (iVar12 == 1) {
        iVar8 = iVar13 * 0x10000;
      }
      else if (iVar12 == 2) {
        iVar8 = iVar13 * 0x8000;
      }
      else if (((iVar12 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
        iVar8 = *(int *)(iVar4 + (iVar13 * 0x20 + iVar12) * 4);
      }
      else if (iVar13 < 0) {
        iVar8 = (iVar13 * 0x10000) / iVar12;
      }
      else {
        iVar8 = (iVar13 * 0x10000) / iVar12;
      }
      uVar7 = iVar9 << 0x10;
      uVar10 = iVar2 << 0x10;
    }
    else {
      iVar8 = iVar2 - iVar9;
      if (iVar17 == 1) {
        iVar8 = iVar8 * 0x10000;
      }
      else if (iVar17 == 2) {
        iVar8 = iVar8 * 0x8000;
      }
      else if (((iVar17 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
        iVar8 = *(int *)(iVar4 + (iVar8 * 0x20 + iVar17) * 4);
      }
      else if (iVar8 < 0) {
        iVar8 = (iVar8 * 0x10000) / iVar17;
      }
      else {
        iVar8 = (iVar8 * 0x10000) / iVar17;
      }
      if (iVar8 == iVar16 || iVar8 - iVar16 < 0) {
        return;
      }
      uVar7 = iVar9 << 0x10;
      if (iVar12 < iVar17) {
        iVar17 = iVar17 - iVar12;
        uVar10 = uVar7;
        while (iVar12 = iVar12 + -1, -1 < iVar12) {
          uVar7 = uVar7 + iVar16;
          uVar10 = uVar10 + iVar8;
          uVar5 = *(uint *)(DAT_10079224 + ((uVar7 & 0x70000) >> 0x10) * 4) ^ uVar14 & 0xff;
          iVar9 = ((int)uVar7 >> 0x10) - ((int)uVar10 >> 0x10);
          if (iVar9 < 0) {
            puVar15 = (ushort *)(iVar6 + ((int)uVar10 >> 0x10) * 2 + iVar9 * 2);
            do {
              if ((uVar5 & 0xff) < uVar3) {
                *puVar15 = uVar11;
              }
              puVar15 = puVar15 + 1;
              uVar5 = uVar5 ^ uVar5 >> 6;
              iVar9 = iVar9 + 1;
            } while (iVar9 < 0);
          }
          iVar6 = iVar6 + iVar1;
          uVar14 = uVar14 ^ uVar14 >> 6;
        }
        uVar7 = iVar13 << 0x10;
        iVar2 = iVar2 - iVar13;
        iVar12 = iVar17;
        if (iVar17 == 1) {
          iVar16 = iVar2 * 0x10000;
        }
        else if (iVar17 == 2) {
          iVar16 = iVar2 * 0x8000;
        }
        else if (((iVar17 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
          iVar16 = *(int *)(iVar4 + (iVar2 * 0x20 + iVar17) * 4);
        }
        else if (iVar2 < 0) {
          iVar16 = (iVar2 * 0x10000) / iVar17;
        }
        else {
          iVar16 = (iVar2 * 0x10000) / iVar17;
        }
      }
      else {
        iVar12 = iVar12 - iVar17;
        uVar10 = uVar7;
        while (iVar17 = iVar17 + -1, -1 < iVar17) {
          uVar7 = uVar7 + iVar16;
          uVar10 = uVar10 + iVar8;
          uVar5 = *(uint *)(DAT_10079224 + ((uVar7 & 0x70000) >> 0x10) * 4) ^ uVar14 & 0xff;
          iVar9 = ((int)uVar7 >> 0x10) - ((int)uVar10 >> 0x10);
          if (iVar9 < 0) {
            puVar15 = (ushort *)(iVar6 + ((int)uVar10 >> 0x10) * 2 + iVar9 * 2);
            do {
              if ((uVar5 & 0xff) < uVar3) {
                *puVar15 = uVar11;
              }
              puVar15 = puVar15 + 1;
              uVar5 = uVar5 ^ uVar5 >> 6;
              iVar9 = iVar9 + 1;
            } while (iVar9 < 0);
          }
          iVar6 = iVar6 + iVar1;
          uVar14 = uVar14 ^ uVar14 >> 6;
        }
        if (iVar12 == 0) {
          return;
        }
        uVar10 = iVar2 << 0x10;
        iVar13 = iVar13 - iVar2;
        if (iVar12 == 1) {
          iVar8 = iVar13 * 0x10000;
        }
        else if (iVar12 == 2) {
          iVar8 = iVar13 * 0x8000;
        }
        else if (((iVar12 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
          iVar8 = *(int *)(iVar4 + (iVar13 * 0x20 + iVar12) * 4);
        }
        else if (iVar13 < 0) {
          iVar8 = (iVar13 * 0x10000) / iVar12;
        }
        else {
          iVar8 = (iVar13 * 0x10000) / iVar12;
        }
      }
    }
  }
  while (-1 < iVar12 + -1) {
    uVar7 = uVar7 + iVar16;
    uVar10 = uVar10 + iVar8;
    uVar5 = *(uint *)(DAT_10079224 + ((uVar7 & 0x70000) >> 0x10) * 4) ^ uVar14 & 0xff;
    iVar2 = ((int)uVar7 >> 0x10) - ((int)uVar10 >> 0x10);
    if (iVar2 < 0) {
      puVar15 = (ushort *)(iVar6 + ((int)uVar10 >> 0x10) * 2 + iVar2 * 2);
      do {
        if ((uVar5 & 0xff) < uVar3) {
          *puVar15 = uVar11;
        }
        puVar15 = puVar15 + 1;
        uVar5 = uVar5 ^ uVar5 >> 6;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0);
    }
    iVar6 = iVar6 + iVar1;
    uVar14 = uVar14 ^ uVar14 >> 6;
    iVar12 = iVar12 + -1;
  }
  return;
}


