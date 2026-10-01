// 1000e690 FUN_1000e690 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000e690(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  undefined8 uVar21;
  int local_3c;
  uint local_c;
  
  iVar2 = param_3;
  iVar18 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar2 = param_2;
      param_2 = param_4;
      iVar18 = param_3;
    }
LAB_1000e6d6:
    param_4 = iVar2;
    param_3 = param_2;
    param_2 = iVar18;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1000e6d6;
  DAT_1007f284 = (int)*(short *)(param_2 + 0x1e);
  iVar3 = *(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar13 = *(uint *)(param_2 + 100);
  uVar16 = *(uint *)(param_2 + 0x68);
  iVar2 = *(int *)(param_2 + 0x20);
  iVar17 = (int)*(short *)(param_3 + 0x1a);
  uVar14 = *(uint *)(param_3 + 100);
  uVar12 = *(uint *)(param_3 + 0x68);
  iVar1 = *(int *)(param_3 + 0x20);
  iVar15 = (int)*(short *)(param_4 + 0x1a);
  uVar19 = *(uint *)(param_4 + 100);
  uVar20 = *(uint *)(param_4 + 0x68);
  iVar18 = *(int *)(param_4 + 0x20);
  DAT_1007f2a0 = DAT_1007beb0;
  DAT_1007f29c = DAT_1007f284 * DAT_1007beb0 + DAT_10079210;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007f2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10079220;
  _DAT_1007f2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10079220 + 0x400;
  _DAT_1007f2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10079220 + 0x800;
  iVar4 = DAT_10079214 + 0x1000;
  DAT_1007f2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  if (iVar3 < 1) {
    iVar3 = DAT_1007f280 - iVar17;
    if (iVar3 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    local_3c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_3c == 0) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar5 = iVar15 - iVar17;
    if (local_3c == 1) {
      DAT_1007f28c = iVar5 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007f28c = iVar5 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar4 + (iVar5 * 0x20 + local_3c) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007f28c = (iVar5 * 0x10000) / local_3c;
    }
    else {
      DAT_1007f28c = (iVar5 * 0x10000) / local_3c;
    }
    iVar15 = iVar15 - DAT_1007f280;
    if (local_3c == 1) {
      DAT_1007f288 = iVar15 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007f288 = iVar15 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar4 + (iVar15 * 0x20 + local_3c) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007f288 = (iVar15 * 0x10000) / local_3c;
    }
    else {
      DAT_1007f288 = (iVar15 * 0x10000) / local_3c;
    }
    if ((iVar1 == iVar2) || (iVar3 == 1)) {
      DAT_1007f2ec = iVar2 - iVar1;
    }
    else if (iVar3 == 2) {
      DAT_1007f2ec = iVar2 - iVar1 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar2 - iVar1) / iVar3;
    }
    if ((iVar18 == iVar1) || (local_3c == 1)) {
      DAT_1007f2e8 = iVar18 - iVar1;
    }
    else if (local_3c == 2) {
      DAT_1007f2e8 = iVar18 - iVar1 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar18 - iVar1) / local_3c;
    }
    if ((uVar13 == uVar14) || (iVar3 == 1)) {
      uVar13 = uVar13 - uVar14;
    }
    else if (iVar3 == 2) {
      uVar13 = (int)(uVar13 - uVar14) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - uVar14) / iVar3;
    }
    if ((uVar19 == uVar14) || (local_3c == 1)) {
      uVar19 = uVar19 - uVar14;
    }
    else if (local_3c == 2) {
      uVar19 = (int)(uVar19 - uVar14) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar14) / local_3c;
    }
    if ((uVar16 == uVar12) || (iVar3 == 1)) {
      uVar16 = uVar16 - uVar12;
    }
    else if (iVar3 == 2) {
      uVar16 = (int)(uVar16 - uVar12) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar12) / iVar3;
    }
    if ((uVar20 == uVar12) || (local_3c == 1)) {
      uVar20 = uVar20 - uVar12;
    }
    else if (local_3c == 2) {
      uVar20 = (int)(uVar20 - uVar12) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar12) / local_3c;
    }
    DAT_1007f2c0 = (uVar12 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    DAT_1007f2c8 = (uVar16 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar20 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
  }
  else {
    iVar5 = iVar17 - DAT_1007f280;
    if (iVar3 == 1) {
      DAT_1007f28c = iVar5 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1007f28c = iVar5 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar4 + (iVar5 * 0x20 + iVar3) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007f28c = (iVar5 * 0x10000) / iVar3;
    }
    else {
      DAT_1007f28c = (iVar5 * 0x10000) / iVar3;
    }
    iVar5 = *(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (0 < iVar5) {
      iVar6 = iVar15 - DAT_1007f280;
      iVar11 = iVar5;
      if (iVar5 == 1) {
        DAT_1007f288 = iVar6 * 0x10000;
      }
      else if (iVar5 == 2) {
        DAT_1007f288 = iVar6 * 0x8000;
      }
      else if (((iVar5 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar4 + (iVar6 * 0x20 + iVar5) * 4);
        iVar11 = iVar4;
      }
      else if (iVar6 < 0) {
        DAT_1007f288 = (iVar6 * 0x10000) / iVar5;
        iVar11 = (iVar6 * 0x10000) % iVar5;
      }
      else {
        DAT_1007f288 = (iVar6 * 0x10000) / iVar5;
        iVar11 = (iVar6 * 0x10000) % iVar5;
      }
      uVar7 = DAT_1007f288 - DAT_1007f28c;
      if ((int)uVar7 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f2a0 = DAT_1007beb0;
        return;
      }
      if ((uVar13 == uVar14) || (iVar3 == 1)) {
        uVar8 = uVar14 - uVar13;
      }
      else if (iVar3 == 2) {
        uVar8 = (int)(uVar14 - uVar13) >> 1;
      }
      else {
        uVar8 = (int)(uVar14 - uVar13) / iVar3;
        iVar11 = (int)(uVar14 - uVar13) % iVar3;
      }
      if ((uVar16 == uVar12) || (iVar3 == 1)) {
        uVar9 = uVar12 - uVar16;
      }
      else if (iVar3 == 2) {
        uVar9 = (int)(uVar12 - uVar16) >> 1;
      }
      else {
        uVar9 = (int)(uVar12 - uVar16) / iVar3;
        iVar11 = (int)(uVar12 - uVar16) % iVar3;
      }
      if ((uVar13 == uVar19) || (iVar5 == 1)) {
        iVar6 = uVar19 - uVar13;
      }
      else if (iVar5 == 2) {
        iVar6 = (int)(uVar19 - uVar13) >> 1;
      }
      else {
        iVar6 = (int)(uVar19 - uVar13) / iVar5;
        iVar11 = (int)(uVar19 - uVar13) % iVar5;
      }
      iVar6 = iVar6 - uVar8;
      uVar21 = CONCAT44(iVar11,iVar6);
      if (iVar6 != 0) {
        uVar21 = FUN_10069324(iVar6,iVar11,iVar6,uVar7);
      }
      iVar11 = (int)((ulonglong)uVar21 >> 0x20);
      local_c = (uint)uVar21;
      if ((uVar16 == uVar20) || (iVar5 == 1)) {
        iVar6 = uVar20 - uVar16;
      }
      else if (iVar5 == 2) {
        iVar6 = (int)(uVar20 - uVar16) >> 1;
      }
      else {
        iVar6 = (int)(uVar20 - uVar16) / iVar5;
        iVar11 = (int)(uVar20 - uVar16) % iVar5;
      }
      iVar6 = iVar6 - uVar9;
      uVar10 = 0;
      if (iVar6 != 0) {
        uVar21 = FUN_10069324(iVar6,iVar11,iVar6,uVar7);
        uVar10 = (uint)uVar21;
      }
      if ((iVar1 == iVar2) || (iVar3 == 1)) {
        DAT_1007f2e8 = iVar1 - iVar2;
      }
      else if (iVar3 == 2) {
        DAT_1007f2e8 = iVar1 - iVar2 >> 1;
      }
      else {
        DAT_1007f2e8 = (iVar1 - iVar2) / iVar3;
      }
      if ((iVar18 == iVar2) || (iVar5 == 1)) {
        iVar11 = iVar18 - iVar2;
      }
      else if (iVar5 == 2) {
        iVar11 = iVar18 - iVar2 >> 1;
      }
      else {
        iVar11 = (iVar18 - iVar2) / iVar5;
      }
      DAT_1007f2ec = iVar11 - DAT_1007f2e8;
      if ((DAT_1007f2ec != 0) && ((int)uVar7 >> 6 != 0)) {
        DAT_1007f2ec = DAT_1007f2ec / ((int)uVar7 >> 6) << 10;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iVar3 < iVar5) {
        DAT_1007f2c0 = (uVar16 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
        uVar13 = (uVar10 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
        local_3c = iVar5 - iVar3;
        DAT_1007f2c4 = (uVar9 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar2;
        DAT_1007f290 = iVar3;
        DAT_1007f2c8 = uVar13;
        FUN_1000f3c0(&DAT_1007f280);
        DAT_1007f280 = iVar17 << 0x10;
        iVar15 = iVar15 - iVar17;
        if (local_3c == 1) {
          DAT_1007f28c = iVar15 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1007f28c = iVar15 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar4 + (iVar15 * 0x20 + local_3c) * 4);
        }
        else if (iVar15 < 0) {
          DAT_1007f28c = (iVar15 * 0x10000) / local_3c;
        }
        else {
          DAT_1007f28c = (iVar15 * 0x10000) / local_3c;
        }
        if ((uVar19 == uVar14) || (local_3c == 1)) {
          uVar19 = uVar19 - uVar14;
        }
        else if (local_3c == 2) {
          uVar19 = (int)(uVar19 - uVar14) >> 1;
        }
        else {
          uVar19 = (int)(uVar19 - uVar14) / local_3c;
        }
        if ((uVar20 == uVar12) || (local_3c == 1)) {
          uVar20 = uVar20 - uVar12;
        }
        else if (local_3c == 2) {
          uVar20 = (int)(uVar20 - uVar12) >> 1;
        }
        else {
          uVar20 = (int)(uVar20 - uVar12) / local_3c;
        }
        if ((iVar18 == iVar1) || (local_3c == 1)) {
          DAT_1007f2e8 = iVar18 - iVar1;
        }
        else if (local_3c == 2) {
          DAT_1007f2e8 = iVar18 - iVar1 >> 1;
        }
        else {
          DAT_1007f2e8 = (iVar18 - iVar1) / local_3c;
        }
        DAT_1007f2c4 = (uVar20 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
        DAT_1007f2c8 = uVar13;
      }
      else {
        DAT_1007f2c0 = (uVar16 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
        DAT_1007f2c8 = (uVar10 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
        DAT_1007f2c4 = (uVar9 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
        local_3c = iVar3 - iVar5;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar2;
        DAT_1007f290 = iVar5;
        FUN_1000f3c0(&DAT_1007f280);
        if (local_3c == 0) {
          return;
        }
        DAT_1007f284 = iVar15 << 0x10;
        iVar17 = iVar17 - iVar15;
        if (local_3c == 1) {
          DAT_1007f288 = iVar17 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1007f288 = iVar17 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar4 + (iVar17 * 0x20 + local_3c) * 4);
        }
        else if (iVar17 < 0) {
          DAT_1007f288 = (iVar17 * 0x10000) / local_3c;
        }
        else {
          DAT_1007f288 = (iVar17 * 0x10000) / local_3c;
        }
      }
      goto LAB_1000f394;
    }
    iVar5 = iVar15 - DAT_1007f280;
    if (iVar5 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar17 = iVar17 - iVar15;
    if (iVar3 == 1) {
      DAT_1007f288 = iVar17 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1007f288 = iVar17 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar4 + (iVar17 * 0x20 + iVar3) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1007f288 = (iVar17 * 0x10000) / iVar3;
    }
    else {
      DAT_1007f288 = (iVar17 * 0x10000) / iVar3;
    }
    if ((iVar18 == iVar2) || (iVar5 == 1)) {
      DAT_1007f2ec = iVar18 - iVar2;
    }
    else if (iVar5 == 2) {
      DAT_1007f2ec = iVar18 - iVar2 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar18 - iVar2) / iVar5;
    }
    if ((iVar1 == iVar2) || (iVar3 == 1)) {
      DAT_1007f2e8 = iVar1 - iVar2;
    }
    else if (iVar3 == 2) {
      DAT_1007f2e8 = iVar1 - iVar2 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar1 - iVar2) / iVar3;
    }
    if ((uVar13 == uVar19) || (iVar5 == 1)) {
      uVar19 = uVar19 - uVar13;
    }
    else if (iVar5 == 2) {
      uVar19 = (int)(uVar19 - uVar13) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar13) / iVar5;
    }
    if ((uVar16 == uVar20) || (iVar5 == 1)) {
      uVar20 = uVar20 - uVar16;
    }
    else if (iVar5 == 2) {
      uVar20 = (int)(uVar20 - uVar16) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar16) / iVar5;
    }
    if ((uVar13 == uVar14) || (iVar3 == 1)) {
      uVar14 = uVar14 - uVar13;
    }
    else if (iVar3 == 2) {
      uVar14 = (int)(uVar14 - uVar13) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar13) / iVar3;
    }
    if ((uVar16 == uVar12) || (iVar3 == 1)) {
      uVar12 = uVar12 - uVar16;
    }
    else if (iVar3 == 2) {
      uVar12 = (int)(uVar12 - uVar16) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar16) / iVar3;
    }
    DAT_1007f2c0 = (uVar16 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
    DAT_1007f2c8 = (uVar20 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar12 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    local_3c = iVar3;
    iVar1 = iVar2;
    iVar17 = DAT_1007f280;
    DAT_1007f280 = iVar15;
  }
  DAT_1007f284 = DAT_1007f280 << 0x10;
  DAT_1007f280 = iVar17 << 0x10;
  DAT_1007f2e4 = DAT_1007f2f0 + iVar1;
LAB_1000f394:
  DAT_1007f290 = local_3c;
  FUN_1000f3c0(&DAT_1007f280);
  return;
}


