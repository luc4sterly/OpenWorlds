// 100143f0 FUN_100143f0 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100143f0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  ushort uVar2;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  int iVar29;
  uint uVar30;
  uint uVar31;
  undefined8 uVar32;
  int local_70;
  uint local_68;
  uint local_4c;
  short local_44;
  short local_40;
  short local_3c;
  uint local_28;
  uint local_24;
  short local_20;
  uint local_1c;
  short local_10;
  ushort uVar3;
  ushort uVar4;
  
  iVar19 = param_3;
  iVar22 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar19 = param_2;
      param_2 = param_4;
      iVar22 = param_3;
    }
LAB_10014440:
    param_4 = iVar19;
    param_3 = param_2;
    param_2 = iVar22;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10014440;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  iVar25 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar24 = *(uint *)(param_2 + 100);
  uVar23 = *(uint *)(param_2 + 0x68);
  uVar26 = *(int *)(param_2 + 0x5c) >> 8;
  uVar5 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | uVar26;
  iVar19 = *(int *)(param_2 + 0x20);
  iVar28 = (int)*(short *)(param_3 + 0x1a);
  uVar6 = *(int *)(param_2 + 0x60) >> 8;
  uVar20 = *(uint *)(param_3 + 100);
  uVar21 = *(uint *)(param_3 + 0x68);
  local_24 = *(int *)(param_3 + 0x5c) >> 8;
  uVar7 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | local_24;
  iVar1 = *(int *)(param_3 + 0x20);
  iVar29 = (int)*(short *)(param_4 + 0x1a);
  uVar8 = *(int *)(param_3 + 0x60) >> 8;
  uVar27 = *(uint *)(param_4 + 100);
  uVar31 = *(uint *)(param_4 + 0x68);
  uVar30 = *(int *)(param_4 + 0x5c) >> 8;
  uVar9 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar30;
  uVar10 = *(int *)(param_4 + 0x60) >> 8;
  iVar22 = *(int *)(param_4 + 0x20);
  DAT_1007f29c = DAT_1007f284 * DAT_1007beb0 + DAT_10079210;
  DAT_1007f2a0 = DAT_1007beb0;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  iVar11 = DAT_10079214 + 0x1000;
  DAT_1007f2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  local_68._0_2_ = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  local_20 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  local_3c = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  local_10 = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  local_40 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  local_44 = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  uVar14 = (int)uVar9 >> 0x10;
  uVar2 = (ushort)(uVar7 >> 0x10);
  uVar3 = (ushort)(uVar5 >> 0x10);
  uVar4 = (ushort)(uVar9 >> 0x10);
  if (iVar25 < 1) {
    iVar25 = DAT_1007f280 - iVar28;
    if (iVar25 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    local_70 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_70 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar12 = iVar29 - iVar28;
    if (local_70 == 1) {
      DAT_1007f28c = iVar12 * 0x10000;
    }
    else if (local_70 == 2) {
      DAT_1007f28c = iVar12 * 0x8000;
    }
    else if (((local_70 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar11 + (iVar12 * 0x20 + local_70) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1007f28c = (iVar12 * 0x10000) / local_70;
    }
    else {
      DAT_1007f28c = (iVar12 * 0x10000) / local_70;
    }
    iVar29 = iVar29 - DAT_1007f280;
    if (local_70 == 1) {
      DAT_1007f288 = iVar29 * 0x10000;
    }
    else if (local_70 == 2) {
      DAT_1007f288 = iVar29 * 0x8000;
    }
    else if (((local_70 < 0x20) && (-0x20 < iVar29)) && (iVar29 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar11 + (iVar29 * 0x20 + local_70) * 4);
    }
    else if (iVar29 < 0) {
      DAT_1007f288 = (iVar29 * 0x10000) / local_70;
    }
    else {
      DAT_1007f288 = (iVar29 * 0x10000) / local_70;
    }
    if ((iVar1 == iVar19) || (iVar25 == 1)) {
      DAT_1007f2ec = iVar19 - iVar1;
    }
    else if (iVar25 == 2) {
      DAT_1007f2ec = iVar19 - iVar1 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar19 - iVar1) / iVar25;
    }
    if ((iVar22 == iVar1) || (local_70 == 1)) {
      DAT_1007f2e8 = iVar22 - iVar1;
    }
    else if (local_70 == 2) {
      DAT_1007f2e8 = iVar22 - iVar1 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar22 - iVar1) / local_70;
    }
    if ((uVar20 == uVar24) || (iVar25 == 1)) {
      uVar24 = uVar24 - uVar20;
    }
    else if (iVar25 == 2) {
      uVar24 = (int)(uVar24 - uVar20) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar20) / iVar25;
    }
    if ((uVar27 == uVar20) || (local_70 == 1)) {
      uVar27 = uVar27 - uVar20;
    }
    else if (local_70 == 2) {
      uVar27 = (int)(uVar27 - uVar20) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar20) / local_70;
    }
    if ((uVar21 == uVar23) || (iVar25 == 1)) {
      uVar23 = uVar23 - uVar21;
    }
    else if (iVar25 == 2) {
      uVar23 = (int)(uVar23 - uVar21) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - uVar21) / iVar25;
    }
    if ((uVar31 == uVar21) || (local_70 == 1)) {
      uVar31 = uVar31 - uVar21;
    }
    else if (local_70 == 2) {
      uVar31 = (int)(uVar31 - uVar21) >> 1;
    }
    else {
      uVar31 = (int)(uVar31 - uVar21) / local_70;
    }
    uVar5 = (int)uVar5 >> 0x10;
    if ((uVar2 == uVar3) || (iVar25 == 1)) {
      iVar19 = (uVar5 & 0xffff) - (uint)uVar2;
    }
    else if (iVar25 == 2) {
      iVar19 = (int)((uVar5 & 0xffff) - (uint)uVar2) >> 1;
    }
    else {
      iVar19 = (int)((uVar5 & 0xffff) - (uint)uVar2) / iVar25;
    }
    uVar9 = (uint)uVar2;
    if ((uVar4 == uVar2) || (local_70 == 1)) {
      iVar22 = (uVar14 & 0xffff) - uVar9;
    }
    else if (local_70 == 2) {
      iVar22 = (int)((uVar14 & 0xffff) - uVar9) >> 1;
    }
    else {
      iVar22 = (int)((uVar14 & 0xffff) - uVar9) / local_70;
    }
    uVar26 = uVar26 & 0xffff;
    if ((local_40 == (short)local_68) || (iVar25 == 1)) {
      uVar26 = uVar26 - (local_24 & 0xffff);
    }
    else if (iVar25 == 2) {
      uVar26 = (int)(uVar26 - (local_24 & 0xffff)) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - (local_24 & 0xffff)) / iVar25;
    }
    local_24 = local_24 & 0xffff;
    DAT_1007f2d4 = (iVar19 << 0x10 | uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
    uVar30 = uVar30 & 0xffff;
    if ((local_20 == local_40) || (local_70 == 1)) {
      uVar30 = uVar30 - local_24;
    }
    else if (local_70 == 2) {
      uVar30 = (int)(uVar30 - local_24) >> 1;
    }
    else {
      uVar30 = (int)(uVar30 - local_24) / local_70;
    }
    DAT_1007f2d0 = (iVar22 << 0x10 | uVar30 & 0xffff) + (uVar30 & 0x8000) * -2;
    uVar6 = uVar6 & 0xffff;
    if ((local_44 == local_3c) || (iVar25 == 1)) {
      uVar6 = uVar6 - (uVar8 & 0xffff);
    }
    else if (iVar25 == 2) {
      uVar6 = (int)(uVar6 - (uVar8 & 0xffff)) >> 1;
    }
    else {
      uVar6 = (int)(uVar6 - (uVar8 & 0xffff)) / iVar25;
    }
    uVar26 = uVar8 & 0xffff;
    DAT_1007f2e0 = (uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
    uVar10 = uVar10 & 0xffff;
    if ((local_10 == local_3c) || (local_70 == 1)) {
      uVar10 = uVar10 - uVar26;
    }
    else if (local_70 == 2) {
      uVar10 = (int)(uVar10 - uVar26) >> 1;
    }
    else {
      uVar10 = (int)(uVar10 - uVar26) / local_70;
    }
    DAT_1007f2dc = (uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
    DAT_1007f2c0 = (uVar20 & 0xfffe) >> 1 | (uVar21 & 0xfffe) << 0xf;
    DAT_1007f2c8 = (uVar23 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar31 & 0xfffe) << 0xf | (uVar27 & 0xfffe) >> 1;
    DAT_1007f2cc = uVar7;
    _DAT_1007f2d8 = uVar8;
  }
  else {
    iVar12 = iVar28 - DAT_1007f280;
    if (iVar25 == 1) {
      DAT_1007f28c = iVar12 * 0x10000;
    }
    else if (iVar25 == 2) {
      DAT_1007f28c = iVar12 * 0x8000;
    }
    else if (((iVar25 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar11 + (iVar12 * 0x20 + iVar25) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1007f28c = (iVar12 * 0x10000) / iVar25;
    }
    else {
      DAT_1007f28c = (iVar12 * 0x10000) / iVar25;
    }
    iVar12 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (0 < iVar12) {
      iVar13 = iVar29 - DAT_1007f280;
      iVar16 = iVar12;
      if (iVar12 == 1) {
        DAT_1007f288 = iVar13 * 0x10000;
      }
      else if (iVar12 == 2) {
        DAT_1007f288 = iVar13 * 0x8000;
      }
      else if (((iVar12 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar11 + (iVar13 * 0x20 + iVar12) * 4);
        iVar16 = iVar11;
      }
      else if (iVar13 < 0) {
        DAT_1007f288 = (iVar13 * 0x10000) / iVar12;
        iVar16 = (iVar13 * 0x10000) % iVar12;
      }
      else {
        DAT_1007f288 = (iVar13 * 0x10000) / iVar12;
        iVar16 = (iVar13 * 0x10000) % iVar12;
      }
      uVar9 = DAT_1007f288 - DAT_1007f28c;
      if ((int)uVar9 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f2a0 = DAT_1007beb0;
        return;
      }
      if ((uVar20 == uVar24) || (iVar25 == 1)) {
        uVar14 = uVar20 - uVar24;
      }
      else if (iVar25 == 2) {
        uVar14 = (int)(uVar20 - uVar24) >> 1;
      }
      else {
        uVar14 = (int)(uVar20 - uVar24) / iVar25;
        iVar16 = (int)(uVar20 - uVar24) % iVar25;
      }
      if ((uVar21 == uVar23) || (iVar25 == 1)) {
        uVar7 = uVar21 - uVar23;
      }
      else if (iVar25 == 2) {
        uVar7 = (int)(uVar21 - uVar23) >> 1;
      }
      else {
        uVar7 = (int)(uVar21 - uVar23) / iVar25;
        iVar16 = (int)(uVar21 - uVar23) % iVar25;
      }
      if ((uVar27 == uVar24) || (iVar12 == 1)) {
        iVar13 = uVar27 - uVar24;
      }
      else if (iVar12 == 2) {
        iVar13 = (int)(uVar27 - uVar24) >> 1;
      }
      else {
        iVar13 = (int)(uVar27 - uVar24) / iVar12;
        iVar16 = (int)(uVar27 - uVar24) % iVar12;
      }
      iVar13 = iVar13 - uVar14;
      uVar32 = CONCAT44(iVar16,iVar13);
      if (iVar13 != 0) {
        uVar32 = FUN_10069324(iVar13,iVar16,iVar13,uVar9);
      }
      iVar16 = (int)((ulonglong)uVar32 >> 0x20);
      local_1c = (uint)uVar32;
      if ((uVar31 == uVar23) || (iVar12 == 1)) {
        iVar13 = uVar31 - uVar23;
      }
      else if (iVar12 == 2) {
        iVar13 = (int)(uVar31 - uVar23) >> 1;
      }
      else {
        iVar13 = (int)(uVar31 - uVar23) / iVar12;
        iVar16 = (int)(uVar31 - uVar23) % iVar12;
      }
      iVar13 = iVar13 - uVar7;
      uVar15 = 0;
      if (iVar13 != 0) {
        uVar32 = FUN_10069324(iVar13,iVar16,iVar13,uVar9);
        uVar15 = (uint)uVar32;
      }
      if ((uVar2 == uVar3) || (iVar25 == 1)) {
        iVar16 = (uint)uVar2 - (uint)uVar3;
      }
      else if (iVar25 == 2) {
        iVar16 = (int)((uint)uVar2 - (uint)uVar3) >> 1;
      }
      else {
        iVar16 = (int)((uint)uVar2 - (uint)uVar3) / iVar25;
      }
      local_28 = (uint)uVar2;
      uVar18 = (uint)uVar3;
      if ((local_40 == (short)local_68) || (iVar25 == 1)) {
        uVar17 = (local_24 & 0xffff) - (uVar26 & 0xffff);
      }
      else if (iVar25 == 2) {
        uVar17 = (int)((local_24 & 0xffff) - (uVar26 & 0xffff)) >> 1;
      }
      else {
        uVar17 = (int)((local_24 & 0xffff) - (uVar26 & 0xffff)) / iVar25;
      }
      local_24 = local_24 & 0xffff;
      uVar26 = uVar26 & 0xffff;
      DAT_1007f2d0 = (iVar16 << 0x10 | uVar17 & 0xffff) + (uVar17 & 0x8000) * -2;
      if ((uVar4 == uVar3) || (iVar12 == 1)) {
        iVar16 = uVar4 - uVar18;
      }
      else if (iVar12 == 2) {
        iVar16 = (int)(uVar4 - uVar18) >> 1;
      }
      else {
        iVar16 = (int)(uVar4 - uVar18) / iVar12;
      }
      local_4c = (uint)uVar4;
      DAT_1007f2d4 = iVar16 - (DAT_1007f2d0 >> 0x10);
      if (DAT_1007f2d4 != 0) {
        DAT_1007f2d4 = (int)(DAT_1007f2d4 * 0x10000) / (int)uVar9 << 0x10;
      }
      if ((local_20 == (short)local_68) || (iVar12 == 1)) {
        iVar16 = (uVar30 & 0xffff) - uVar26;
      }
      else if (iVar12 == 2) {
        iVar16 = (int)((uVar30 & 0xffff) - uVar26) >> 1;
      }
      else {
        iVar16 = (int)((uVar30 & 0xffff) - uVar26) / iVar12;
      }
      uVar30 = uVar30 & 0xffff;
      if (iVar16 - (short)DAT_1007f2d0 != 0) {
        uVar26 = DAT_1007f2d4 | ((iVar16 - (short)DAT_1007f2d0) * 0x10000) / (int)uVar9 & 0xffffU;
        DAT_1007f2d4 = uVar26 + (uVar26 & 0x8000) * -2;
      }
      uVar26 = uVar6 & 0xffff;
      if ((local_3c == local_44) || (iVar25 == 1)) {
        uVar18 = (uVar8 & 0xffff) - uVar26;
      }
      else if (iVar25 == 2) {
        uVar18 = (int)((uVar8 & 0xffff) - uVar26) >> 1;
      }
      else {
        uVar18 = (int)((uVar8 & 0xffff) - uVar26) / iVar25;
      }
      local_68 = uVar8 & 0xffff;
      DAT_1007f2e0 = 0;
      DAT_1007f2dc = (uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
      if ((local_10 == local_44) || (iVar12 == 1)) {
        iVar16 = (uVar10 & 0xffff) - uVar26;
      }
      else if (iVar12 == 2) {
        iVar16 = (int)((uVar10 & 0xffff) - uVar26) >> 1;
      }
      else {
        iVar16 = (int)((uVar10 & 0xffff) - uVar26) / iVar12;
      }
      uVar10 = uVar10 & 0xffff;
      if (iVar16 - (short)DAT_1007f2dc != 0) {
        uVar26 = ((iVar16 - (short)DAT_1007f2dc) * 0x10000) / (int)uVar9;
        DAT_1007f2e0 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
      }
      if ((iVar1 == iVar19) || (iVar25 == 1)) {
        DAT_1007f2e8 = iVar1 - iVar19;
      }
      else if (iVar25 == 2) {
        DAT_1007f2e8 = iVar1 - iVar19 >> 1;
      }
      else {
        DAT_1007f2e8 = (iVar1 - iVar19) / iVar25;
      }
      if ((iVar22 == iVar19) || (iVar12 == 1)) {
        iVar16 = iVar22 - iVar19;
      }
      else if (iVar12 == 2) {
        iVar16 = iVar22 - iVar19 >> 1;
      }
      else {
        iVar16 = (iVar22 - iVar19) / iVar12;
      }
      DAT_1007f2ec = iVar16 - DAT_1007f2e8;
      if ((DAT_1007f2ec != 0) && ((int)uVar9 >> 6 != 0)) {
        DAT_1007f2ec = DAT_1007f2ec / ((int)uVar9 >> 6) << 10;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iVar25 < iVar12) {
        DAT_1007f2c0 = (uVar24 & 0xfffe) >> 1 | (uVar23 & 0xfffe) << 0xf;
        uVar24 = (uVar15 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
        DAT_1007f2c4 = (uVar7 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
        local_70 = iVar12 - iVar25;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar19;
        DAT_1007f290 = iVar25;
        DAT_1007f2c8 = uVar24;
        DAT_1007f2cc = uVar5;
        _DAT_1007f2d8 = uVar6;
        FUN_10015b30((uint *)&DAT_1007f280);
        DAT_1007f280 = iVar28 << 0x10;
        iVar29 = iVar29 - iVar28;
        if (local_70 == 1) {
          DAT_1007f28c = iVar29 * 0x10000;
        }
        else if (local_70 == 2) {
          DAT_1007f28c = iVar29 * 0x8000;
        }
        else if (((local_70 < 0x20) && (-0x20 < iVar29)) && (iVar29 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar11 + (iVar29 * 0x20 + local_70) * 4);
        }
        else if (iVar29 < 0) {
          DAT_1007f28c = (iVar29 * 0x10000) / local_70;
        }
        else {
          DAT_1007f28c = (iVar29 * 0x10000) / local_70;
        }
        if ((uVar27 == uVar20) || (local_70 == 1)) {
          uVar27 = uVar27 - uVar20;
        }
        else if (local_70 == 2) {
          uVar27 = (int)(uVar27 - uVar20) >> 1;
        }
        else {
          uVar27 = (int)(uVar27 - uVar20) / local_70;
        }
        if ((uVar31 == uVar21) || (local_70 == 1)) {
          uVar31 = uVar31 - uVar21;
        }
        else if (local_70 == 2) {
          uVar31 = (int)(uVar31 - uVar21) >> 1;
        }
        else {
          uVar31 = (int)(uVar31 - uVar21) / local_70;
        }
        if ((uVar4 == uVar2) || (local_70 == 1)) {
          iVar19 = local_4c - local_28;
        }
        else if (local_70 == 2) {
          iVar19 = (int)(local_4c - local_28) >> 1;
        }
        else {
          iVar19 = (int)(local_4c - local_28) / local_70;
        }
        DAT_1007f2d0 = iVar19 << 0x10;
        if ((local_20 == local_40) || (local_70 == 1)) {
          uVar30 = uVar30 - local_24;
        }
        else if (local_70 == 2) {
          uVar30 = (int)(uVar30 - local_24) >> 1;
        }
        else {
          uVar30 = (int)(uVar30 - local_24) / local_70;
        }
        if (uVar30 != 0) {
          DAT_1007f2d0 = (DAT_1007f2d0 | uVar30 & 0xffff) + (uVar30 & 0x8000) * -2;
        }
        DAT_1007f2dc = 0;
        if ((local_10 == local_3c) || (local_70 == 1)) {
          uVar10 = uVar10 - local_68;
        }
        else if (local_70 == 2) {
          uVar10 = (int)(uVar10 - local_68) >> 1;
        }
        else {
          uVar10 = (int)(uVar10 - local_68) / local_70;
        }
        if (uVar10 != 0) {
          DAT_1007f2dc = (uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
        }
        if ((iVar22 == iVar1) || (local_70 == 1)) {
          DAT_1007f2e8 = iVar22 - iVar1;
        }
        else if (local_70 == 2) {
          DAT_1007f2e8 = iVar22 - iVar1 >> 1;
        }
        else {
          DAT_1007f2e8 = (iVar22 - iVar1) / local_70;
        }
        DAT_1007f2c4 = (uVar31 & 0xfffe) << 0xf | (uVar27 & 0xfffe) >> 1;
        DAT_1007f2c8 = uVar24;
      }
      else {
        DAT_1007f2c0 = (uVar24 & 0xfffe) >> 1 | (uVar23 & 0xfffe) << 0xf;
        DAT_1007f2c8 = (uVar15 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
        DAT_1007f2c4 = (uVar7 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
        local_70 = iVar25 - iVar12;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar19;
        DAT_1007f290 = iVar12;
        DAT_1007f2cc = uVar5;
        _DAT_1007f2d8 = uVar6;
        FUN_10015b30((uint *)&DAT_1007f280);
        if (local_70 == 0) {
          return;
        }
        DAT_1007f284 = iVar29 << 0x10;
        iVar28 = iVar28 - iVar29;
        if (local_70 == 1) {
          DAT_1007f288 = iVar28 * 0x10000;
        }
        else if (local_70 == 2) {
          DAT_1007f288 = iVar28 * 0x8000;
        }
        else if (((local_70 < 0x20) && (-0x20 < iVar28)) && (iVar28 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar11 + (iVar28 * 0x20 + local_70) * 4);
        }
        else if (iVar28 < 0) {
          DAT_1007f288 = (iVar28 * 0x10000) / local_70;
        }
        else {
          DAT_1007f288 = (iVar28 * 0x10000) / local_70;
        }
      }
      goto LAB_10015b0d;
    }
    iVar12 = iVar29 - DAT_1007f280;
    if (iVar12 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar28 = iVar28 - iVar29;
    if (iVar25 == 1) {
      DAT_1007f288 = iVar28 * 0x10000;
    }
    else if (iVar25 == 2) {
      DAT_1007f288 = iVar28 * 0x8000;
    }
    else if (((iVar25 < 0x20) && (-0x20 < iVar28)) && (iVar28 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar11 + (iVar28 * 0x20 + iVar25) * 4);
    }
    else if (iVar28 < 0) {
      DAT_1007f288 = (iVar28 * 0x10000) / iVar25;
    }
    else {
      DAT_1007f288 = (iVar28 * 0x10000) / iVar25;
    }
    if ((iVar22 == iVar19) || (iVar12 == 1)) {
      DAT_1007f2ec = iVar22 - iVar19;
    }
    else if (iVar12 == 2) {
      DAT_1007f2ec = iVar22 - iVar19 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar22 - iVar19) / iVar12;
    }
    if ((iVar1 == iVar19) || (iVar25 == 1)) {
      DAT_1007f2e8 = iVar1 - iVar19;
    }
    else if (iVar25 == 2) {
      DAT_1007f2e8 = iVar1 - iVar19 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar1 - iVar19) / iVar25;
    }
    if ((uVar27 == uVar24) || (iVar12 == 1)) {
      uVar27 = uVar27 - uVar24;
    }
    else if (iVar12 == 2) {
      uVar27 = (int)(uVar27 - uVar24) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar24) / iVar12;
    }
    if ((uVar31 == uVar23) || (iVar12 == 1)) {
      uVar31 = uVar31 - uVar23;
    }
    else if (iVar12 == 2) {
      uVar31 = (int)(uVar31 - uVar23) >> 1;
    }
    else {
      uVar31 = (int)(uVar31 - uVar23) / iVar12;
    }
    if ((uVar20 == uVar24) || (iVar25 == 1)) {
      uVar20 = uVar20 - uVar24;
    }
    else if (iVar25 == 2) {
      uVar20 = (int)(uVar20 - uVar24) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar24) / iVar25;
    }
    if ((uVar21 == uVar23) || (iVar25 == 1)) {
      uVar21 = uVar21 - uVar23;
    }
    else if (iVar25 == 2) {
      uVar21 = (int)(uVar21 - uVar23) >> 1;
    }
    else {
      uVar21 = (int)(uVar21 - uVar23) / iVar25;
    }
    if ((uVar4 == uVar3) || (iVar12 == 1)) {
      iVar22 = (uVar14 & 0xffff) - (uint)uVar3;
    }
    else if (iVar12 == 2) {
      iVar22 = (int)((uVar14 & 0xffff) - (uint)uVar3) >> 1;
    }
    else {
      iVar22 = (int)((uVar14 & 0xffff) - (uint)uVar3) / iVar12;
    }
    uVar9 = (uint)uVar3;
    uVar30 = uVar30 & 0xffff;
    if ((local_20 == (short)local_68) || (iVar12 == 1)) {
      uVar30 = uVar30 - (uVar26 & 0xffff);
    }
    else if (iVar12 == 2) {
      uVar30 = (int)(uVar30 - (uVar26 & 0xffff)) >> 1;
    }
    else {
      uVar30 = (int)(uVar30 - (uVar26 & 0xffff)) / iVar12;
    }
    uVar26 = uVar26 & 0xffff;
    DAT_1007f2d4 = (iVar22 << 0x10 | uVar30 & 0xffff) + (uVar30 & 0x8000) * -2;
    uVar7 = (int)uVar7 >> 0x10;
    if ((uVar2 == uVar3) || (iVar25 == 1)) {
      iVar22 = (uVar7 & 0xffff) - uVar9;
    }
    else if (iVar25 == 2) {
      iVar22 = (int)((uVar7 & 0xffff) - uVar9) >> 1;
    }
    else {
      iVar22 = (int)((uVar7 & 0xffff) - uVar9) / iVar25;
    }
    local_24 = local_24 & 0xffff;
    if ((local_40 == (short)local_68) || (iVar25 == 1)) {
      local_24 = local_24 - uVar26;
    }
    else if (iVar25 == 2) {
      local_24 = (int)(local_24 - uVar26) >> 1;
    }
    else {
      local_24 = (int)(local_24 - uVar26) / iVar25;
    }
    DAT_1007f2d0 = (iVar22 << 0x10 | local_24 & 0xffff) + (local_24 & 0x8000) * -2;
    uVar10 = uVar10 & 0xffff;
    if ((local_10 == local_44) || (iVar12 == 1)) {
      uVar10 = uVar10 - (uVar6 & 0xffff);
    }
    else if (iVar12 == 2) {
      uVar10 = (int)(uVar10 - (uVar6 & 0xffff)) >> 1;
    }
    else {
      uVar10 = (int)(uVar10 - (uVar6 & 0xffff)) / iVar12;
    }
    uVar26 = uVar6 & 0xffff;
    DAT_1007f2e0 = (uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
    uVar8 = uVar8 & 0xffff;
    if ((local_3c == local_44) || (iVar25 == 1)) {
      uVar8 = uVar8 - uVar26;
    }
    else if (iVar25 == 2) {
      uVar8 = (int)(uVar8 - uVar26) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - uVar26) / iVar25;
    }
    DAT_1007f2dc = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    DAT_1007f2c0 = (uVar24 & 0xfffe) >> 1 | (uVar23 & 0xfffe) << 0xf;
    DAT_1007f2c8 = (uVar31 & 0xfffe) << 0xf | (uVar27 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar21 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1007f2cc = uVar5;
    _DAT_1007f2d8 = uVar6;
    local_70 = iVar25;
    iVar1 = iVar19;
    iVar28 = DAT_1007f280;
    DAT_1007f280 = iVar29;
  }
  DAT_1007f284 = DAT_1007f280 << 0x10;
  DAT_1007f280 = iVar28 << 0x10;
  DAT_1007f2e4 = DAT_1007f2f0 + iVar1;
LAB_10015b0d:
  DAT_1007f290 = local_70;
  FUN_10015b30((uint *)&DAT_1007f280);
  return;
}


