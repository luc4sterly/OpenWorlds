// 10010e60 FUN_10010e60 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010e60(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  undefined8 uVar21;
  int local_3c;
  uint local_c;
  
  iVar2 = param_3;
  iVar20 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar2 = param_2;
      param_2 = param_4;
      iVar20 = param_3;
    }
LAB_10010ea6:
    param_4 = iVar2;
    param_3 = param_2;
    param_2 = iVar20;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10010ea6;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  iVar14 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar12 = *(uint *)(param_2 + 100);
  uVar18 = *(uint *)(param_2 + 0x68);
  iVar2 = *(int *)(param_2 + 0x20);
  uVar11 = *(uint *)(param_3 + 0x68);
  iVar16 = (int)*(short *)(param_3 + 0x1a);
  uVar13 = *(uint *)(param_3 + 100);
  iVar1 = *(int *)(param_3 + 0x20);
  uVar19 = *(uint *)(param_4 + 0x68);
  iVar17 = (int)*(short *)(param_4 + 0x1a);
  uVar15 = *(uint *)(param_4 + 100);
  iVar20 = *(int *)(param_4 + 0x20);
  DAT_1007f2a0 = DAT_1007beb0;
  DAT_1007f29c = DAT_1007f284 * DAT_1007beb0 + DAT_10079210;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007f2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007f2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar3 = DAT_10079214 + 0x1000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  if (iVar14 < 1) {
    iVar14 = DAT_1007f280 - iVar16;
    if (iVar14 < 1) {
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
    iVar4 = iVar17 - iVar16;
    if (local_3c == 1) {
      DAT_1007f28c = iVar4 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007f28c = iVar4 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar3 + (iVar4 * 0x20 + local_3c) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1007f28c = (iVar4 * 0x10000) / local_3c;
    }
    else {
      DAT_1007f28c = (iVar4 * 0x10000) / local_3c;
    }
    iVar17 = iVar17 - DAT_1007f280;
    if (local_3c == 1) {
      DAT_1007f288 = iVar17 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007f288 = iVar17 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar3 + (iVar17 * 0x20 + local_3c) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1007f288 = (iVar17 * 0x10000) / local_3c;
    }
    else {
      DAT_1007f288 = (iVar17 * 0x10000) / local_3c;
    }
    if ((iVar1 == iVar2) || (iVar14 == 1)) {
      DAT_1007f2ec = iVar2 - iVar1;
    }
    else if (iVar14 == 2) {
      DAT_1007f2ec = iVar2 - iVar1 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar2 - iVar1) / iVar14;
    }
    if ((iVar20 == iVar1) || (local_3c == 1)) {
      DAT_1007f2e8 = iVar20 - iVar1;
    }
    else if (local_3c == 2) {
      DAT_1007f2e8 = iVar20 - iVar1 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar20 - iVar1) / local_3c;
    }
    if ((uVar13 == uVar12) || (iVar14 == 1)) {
      uVar12 = uVar12 - uVar13;
    }
    else if (iVar14 == 2) {
      uVar12 = (int)(uVar12 - uVar13) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar13) / iVar14;
    }
    if ((uVar13 == uVar15) || (local_3c == 1)) {
      uVar15 = uVar15 - uVar13;
    }
    else if (local_3c == 2) {
      uVar15 = (int)(uVar15 - uVar13) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar13) / local_3c;
    }
    if ((uVar11 == uVar18) || (iVar14 == 1)) {
      uVar18 = uVar18 - uVar11;
    }
    else if (iVar14 == 2) {
      uVar18 = (int)(uVar18 - uVar11) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar11) / iVar14;
    }
    if ((uVar11 == uVar19) || (local_3c == 1)) {
      uVar19 = uVar19 - uVar11;
    }
    else if (local_3c == 2) {
      uVar19 = (int)(uVar19 - uVar11) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar11) / local_3c;
    }
    DAT_1007f2c0 = (uVar11 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
    DAT_1007f2c8 = (uVar18 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar19 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
  }
  else {
    iVar4 = iVar16 - DAT_1007f280;
    if (iVar14 == 1) {
      DAT_1007f28c = iVar4 * 0x10000;
    }
    else if (iVar14 == 2) {
      DAT_1007f28c = iVar4 * 0x8000;
    }
    else if (((iVar14 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar3 + (iVar4 * 0x20 + iVar14) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1007f28c = (iVar4 * 0x10000) / iVar14;
    }
    else {
      DAT_1007f28c = (iVar4 * 0x10000) / iVar14;
    }
    iVar4 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (0 < iVar4) {
      iVar5 = iVar17 - DAT_1007f280;
      iVar10 = iVar4;
      if (iVar4 == 1) {
        DAT_1007f288 = iVar5 * 0x10000;
      }
      else if (iVar4 == 2) {
        DAT_1007f288 = iVar5 * 0x8000;
      }
      else if (((iVar4 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar3 + (iVar5 * 0x20 + iVar4) * 4);
        iVar10 = iVar3;
      }
      else if (iVar5 < 0) {
        DAT_1007f288 = (iVar5 * 0x10000) / iVar4;
        iVar10 = (iVar5 * 0x10000) % iVar4;
      }
      else {
        DAT_1007f288 = (iVar5 * 0x10000) / iVar4;
        iVar10 = (iVar5 * 0x10000) % iVar4;
      }
      uVar6 = DAT_1007f288 - DAT_1007f28c;
      if ((int)uVar6 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f2a0 = DAT_1007beb0;
        return;
      }
      if ((uVar13 == uVar12) || (iVar14 == 1)) {
        uVar7 = uVar13 - uVar12;
      }
      else if (iVar14 == 2) {
        uVar7 = (int)(uVar13 - uVar12) >> 1;
      }
      else {
        uVar7 = (int)(uVar13 - uVar12) / iVar14;
        iVar10 = (int)(uVar13 - uVar12) % iVar14;
      }
      if ((uVar11 == uVar18) || (iVar14 == 1)) {
        uVar8 = uVar11 - uVar18;
      }
      else if (iVar14 == 2) {
        uVar8 = (int)(uVar11 - uVar18) >> 1;
      }
      else {
        uVar8 = (int)(uVar11 - uVar18) / iVar14;
        iVar10 = (int)(uVar11 - uVar18) % iVar14;
      }
      if ((uVar12 == uVar15) || (iVar4 == 1)) {
        iVar5 = uVar15 - uVar12;
      }
      else if (iVar4 == 2) {
        iVar5 = (int)(uVar15 - uVar12) >> 1;
      }
      else {
        iVar5 = (int)(uVar15 - uVar12) / iVar4;
        iVar10 = (int)(uVar15 - uVar12) % iVar4;
      }
      iVar5 = iVar5 - uVar7;
      uVar21 = CONCAT44(iVar10,iVar5);
      if (iVar5 != 0) {
        uVar21 = FUN_10069324(iVar5,iVar10,iVar5,uVar6);
      }
      iVar10 = (int)((ulonglong)uVar21 >> 0x20);
      local_c = (uint)uVar21;
      if ((uVar18 == uVar19) || (iVar4 == 1)) {
        iVar5 = uVar19 - uVar18;
      }
      else if (iVar4 == 2) {
        iVar5 = (int)(uVar19 - uVar18) >> 1;
      }
      else {
        iVar5 = (int)(uVar19 - uVar18) / iVar4;
        iVar10 = (int)(uVar19 - uVar18) % iVar4;
      }
      iVar5 = iVar5 - uVar8;
      uVar9 = 0;
      if (iVar5 != 0) {
        uVar21 = FUN_10069324(iVar5,iVar10,iVar5,uVar6);
        uVar9 = (uint)uVar21;
      }
      if ((iVar1 == iVar2) || (iVar14 == 1)) {
        DAT_1007f2e8 = iVar1 - iVar2;
      }
      else if (iVar14 == 2) {
        DAT_1007f2e8 = iVar1 - iVar2 >> 1;
      }
      else {
        DAT_1007f2e8 = (iVar1 - iVar2) / iVar14;
      }
      if ((iVar20 == iVar2) || (iVar4 == 1)) {
        iVar10 = iVar20 - iVar2;
      }
      else if (iVar4 == 2) {
        iVar10 = iVar20 - iVar2 >> 1;
      }
      else {
        iVar10 = (iVar20 - iVar2) / iVar4;
      }
      DAT_1007f2ec = iVar10 - DAT_1007f2e8;
      if ((DAT_1007f2ec != 0) && ((int)uVar6 >> 6 != 0)) {
        DAT_1007f2ec = DAT_1007f2ec / ((int)uVar6 >> 6) << 10;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iVar14 < iVar4) {
        DAT_1007f2c0 = (uVar18 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
        uVar12 = (uVar9 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
        local_3c = iVar4 - iVar14;
        DAT_1007f2c4 = (uVar8 & 0xfffe) << 0xf | (uVar7 & 0xfffe) >> 1;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar2;
        DAT_1007f290 = iVar14;
        DAT_1007f2c8 = uVar12;
        FUN_10011b60((uint *)&DAT_1007f280);
        DAT_1007f280 = iVar16 << 0x10;
        iVar17 = iVar17 - iVar16;
        if (local_3c == 1) {
          DAT_1007f28c = iVar17 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1007f28c = iVar17 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar3 + (iVar17 * 0x20 + local_3c) * 4);
        }
        else if (iVar17 < 0) {
          DAT_1007f28c = (iVar17 * 0x10000) / local_3c;
        }
        else {
          DAT_1007f28c = (iVar17 * 0x10000) / local_3c;
        }
        if ((uVar13 == uVar15) || (local_3c == 1)) {
          uVar15 = uVar15 - uVar13;
        }
        else if (local_3c == 2) {
          uVar15 = (int)(uVar15 - uVar13) >> 1;
        }
        else {
          uVar15 = (int)(uVar15 - uVar13) / local_3c;
        }
        if ((uVar11 == uVar19) || (local_3c == 1)) {
          uVar19 = uVar19 - uVar11;
        }
        else if (local_3c == 2) {
          uVar19 = (int)(uVar19 - uVar11) >> 1;
        }
        else {
          uVar19 = (int)(uVar19 - uVar11) / local_3c;
        }
        if ((iVar20 == iVar1) || (local_3c == 1)) {
          DAT_1007f2e8 = iVar20 - iVar1;
        }
        else if (local_3c == 2) {
          DAT_1007f2e8 = iVar20 - iVar1 >> 1;
        }
        else {
          DAT_1007f2e8 = (iVar20 - iVar1) / local_3c;
        }
        DAT_1007f2c4 = (uVar19 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
        DAT_1007f2c8 = uVar12;
      }
      else {
        DAT_1007f2c0 = (uVar18 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
        DAT_1007f2c8 = (uVar9 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
        DAT_1007f2c4 = (uVar8 & 0xfffe) << 0xf | (uVar7 & 0xfffe) >> 1;
        local_3c = iVar14 - iVar4;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar2;
        DAT_1007f290 = iVar4;
        FUN_10011b60((uint *)&DAT_1007f280);
        if (local_3c == 0) {
          return;
        }
        DAT_1007f284 = iVar17 << 0x10;
        iVar16 = iVar16 - iVar17;
        if (local_3c == 1) {
          DAT_1007f288 = iVar16 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1007f288 = iVar16 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar3 + (iVar16 * 0x20 + local_3c) * 4);
        }
        else if (iVar16 < 0) {
          DAT_1007f288 = (iVar16 * 0x10000) / local_3c;
        }
        else {
          DAT_1007f288 = (iVar16 * 0x10000) / local_3c;
        }
      }
      goto LAB_10011b38;
    }
    iVar4 = iVar17 - DAT_1007f280;
    if (iVar4 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar16 = iVar16 - iVar17;
    if (iVar14 == 1) {
      DAT_1007f288 = iVar16 * 0x10000;
    }
    else if (iVar14 == 2) {
      DAT_1007f288 = iVar16 * 0x8000;
    }
    else if (((iVar14 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar3 + (iVar16 * 0x20 + iVar14) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1007f288 = (iVar16 * 0x10000) / iVar14;
    }
    else {
      DAT_1007f288 = (iVar16 * 0x10000) / iVar14;
    }
    if ((iVar20 == iVar2) || (iVar4 == 1)) {
      DAT_1007f2ec = iVar20 - iVar2;
    }
    else if (iVar4 == 2) {
      DAT_1007f2ec = iVar20 - iVar2 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar20 - iVar2) / iVar4;
    }
    if ((iVar1 == iVar2) || (iVar14 == 1)) {
      DAT_1007f2e8 = iVar1 - iVar2;
    }
    else if (iVar14 == 2) {
      DAT_1007f2e8 = iVar1 - iVar2 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar1 - iVar2) / iVar14;
    }
    if ((uVar12 == uVar15) || (iVar4 == 1)) {
      uVar15 = uVar15 - uVar12;
    }
    else if (iVar4 == 2) {
      uVar15 = (int)(uVar15 - uVar12) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar12) / iVar4;
    }
    if ((uVar18 == uVar19) || (iVar4 == 1)) {
      uVar19 = uVar19 - uVar18;
    }
    else if (iVar4 == 2) {
      uVar19 = (int)(uVar19 - uVar18) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar18) / iVar4;
    }
    if ((uVar13 == uVar12) || (iVar14 == 1)) {
      uVar13 = uVar13 - uVar12;
    }
    else if (iVar14 == 2) {
      uVar13 = (int)(uVar13 - uVar12) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - uVar12) / iVar14;
    }
    if ((uVar11 == uVar18) || (iVar14 == 1)) {
      uVar11 = uVar11 - uVar18;
    }
    else if (iVar14 == 2) {
      uVar11 = (int)(uVar11 - uVar18) >> 1;
    }
    else {
      uVar11 = (int)(uVar11 - uVar18) / iVar14;
    }
    DAT_1007f2c0 = (uVar18 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
    DAT_1007f2c8 = (uVar19 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar11 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
    local_3c = iVar14;
    iVar1 = iVar2;
    iVar16 = DAT_1007f280;
    DAT_1007f280 = iVar17;
  }
  DAT_1007f284 = DAT_1007f280 << 0x10;
  DAT_1007f280 = iVar16 << 0x10;
  DAT_1007f2e4 = DAT_1007f2f0 + iVar1;
LAB_10011b38:
  DAT_1007f290 = local_3c;
  FUN_10011b60((uint *)&DAT_1007f280);
  return;
}


