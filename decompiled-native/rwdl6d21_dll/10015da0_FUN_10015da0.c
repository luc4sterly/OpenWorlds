// 10015da0 FUN_10015da0 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10015da0(int *param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  ushort uVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  undefined8 uVar28;
  int local_64;
  uint local_5c;
  uint local_48;
  short local_44;
  short local_40;
  short local_3c;
  uint local_2c;
  uint local_28;
  short local_24;
  uint local_20;
  short local_14;
  ushort uVar2;
  
  iVar9 = param_3;
  iVar23 = param_4;
  iVar24 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar9 = param_2;
      iVar23 = param_3;
      iVar24 = param_4;
    }
LAB_10015de9:
    param_4 = iVar9;
    param_2 = iVar23;
    param_3 = iVar24;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10015de9;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  local_64 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar20 = *(uint *)(param_2 + 100);
  uVar19 = *(uint *)(param_2 + 0x68);
  uVar22 = *(int *)(param_2 + 0x5c) >> 8;
  uVar3 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | uVar22;
  iVar23 = (int)*(short *)(param_3 + 0x1a);
  uVar4 = *(int *)(param_2 + 0x60) >> 8;
  uVar17 = *(uint *)(param_3 + 100);
  uVar18 = *(uint *)(param_3 + 0x68);
  local_28 = *(int *)(param_3 + 0x5c) >> 8;
  uVar5 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | local_28;
  iVar24 = (int)*(short *)(param_4 + 0x1a);
  uVar6 = *(int *)(param_3 + 0x60) >> 8;
  uVar25 = *(uint *)(param_4 + 100);
  uVar27 = *(uint *)(param_4 + 0x68);
  uVar7 = *(int *)(param_4 + 0x5c) >> 8;
  uVar26 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar7;
  uVar8 = *(int *)(param_4 + 0x60) >> 8;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007f2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007f298 = DAT_1007bda4;
  iVar9 = DAT_10079214 + 0x1000;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  local_5c._0_2_ = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  local_24 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  local_3c = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  local_14 = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  local_40 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  local_44 = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  uVar12 = (int)uVar26 >> 0x10;
  uVar21 = (ushort)(uVar5 >> 0x10);
  uVar1 = (ushort)(uVar3 >> 0x10);
  uVar2 = (ushort)(uVar26 >> 0x10);
  if (local_64 < 1) {
    iVar10 = DAT_1007f280 - iVar23;
    if (iVar10 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    local_64 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_64 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    iVar14 = iVar24 - iVar23;
    if (local_64 == 1) {
      DAT_1007f28c = iVar14 * 0x10000;
    }
    else if (local_64 == 2) {
      DAT_1007f28c = iVar14 * 0x8000;
    }
    else if (((local_64 < 0x20) && (-0x20 < iVar14)) && (iVar14 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar9 + (iVar14 * 0x20 + local_64) * 4);
    }
    else if (iVar14 < 0) {
      DAT_1007f28c = (iVar14 * 0x10000) / local_64;
    }
    else {
      DAT_1007f28c = (iVar14 * 0x10000) / local_64;
    }
    iVar24 = iVar24 - DAT_1007f280;
    if (local_64 == 1) {
      DAT_1007f288 = iVar24 * 0x10000;
    }
    else if (local_64 == 2) {
      DAT_1007f288 = iVar24 * 0x8000;
    }
    else if (((local_64 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar9 + (iVar24 * 0x20 + local_64) * 4);
    }
    else if (iVar24 < 0) {
      DAT_1007f288 = (iVar24 * 0x10000) / local_64;
    }
    else {
      DAT_1007f288 = (iVar24 * 0x10000) / local_64;
    }
    if ((uVar17 == uVar20) || (iVar10 == 1)) {
      uVar20 = uVar20 - uVar17;
    }
    else if (iVar10 == 2) {
      uVar20 = (int)(uVar20 - uVar17) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar17) / iVar10;
    }
    if ((uVar25 == uVar17) || (local_64 == 1)) {
      uVar25 = uVar25 - uVar17;
    }
    else if (local_64 == 2) {
      uVar25 = (int)(uVar25 - uVar17) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - uVar17) / local_64;
    }
    if ((uVar18 == uVar19) || (iVar10 == 1)) {
      uVar19 = uVar19 - uVar18;
    }
    else if (iVar10 == 2) {
      uVar19 = (int)(uVar19 - uVar18) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar18) / iVar10;
    }
    if ((uVar27 == uVar18) || (local_64 == 1)) {
      uVar27 = uVar27 - uVar18;
    }
    else if (local_64 == 2) {
      uVar27 = (int)(uVar27 - uVar18) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar18) / local_64;
    }
    uVar3 = (int)uVar3 >> 0x10;
    if ((uVar1 == uVar21) || (iVar10 == 1)) {
      iVar9 = (uVar3 & 0xffff) - (uint)uVar21;
    }
    else if (iVar10 == 2) {
      iVar9 = (int)((uVar3 & 0xffff) - (uint)uVar21) >> 1;
    }
    else {
      iVar9 = (int)((uVar3 & 0xffff) - (uint)uVar21) / iVar10;
    }
    uVar3 = (uint)uVar21;
    if ((uVar2 == uVar21) || (local_64 == 1)) {
      iVar24 = (uVar12 & 0xffff) - uVar3;
    }
    else if (local_64 == 2) {
      iVar24 = (int)((uVar12 & 0xffff) - uVar3) >> 1;
    }
    else {
      iVar24 = (int)((uVar12 & 0xffff) - uVar3) / local_64;
    }
    uVar22 = uVar22 & 0xffff;
    if (((short)local_5c == local_40) || (iVar10 == 1)) {
      uVar22 = uVar22 - (local_28 & 0xffff);
    }
    else if (iVar10 == 2) {
      uVar22 = (int)(uVar22 - (local_28 & 0xffff)) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - (local_28 & 0xffff)) / iVar10;
    }
    local_28 = local_28 & 0xffff;
    DAT_1007f2d4 = (iVar9 << 0x10 | uVar22 & 0xffff) + (uVar22 & 0x8000) * -2;
    uVar7 = uVar7 & 0xffff;
    if ((local_24 == local_40) || (local_64 == 1)) {
      uVar7 = uVar7 - local_28;
    }
    else if (local_64 == 2) {
      uVar7 = (int)(uVar7 - local_28) >> 1;
    }
    else {
      uVar7 = (int)(uVar7 - local_28) / local_64;
    }
    DAT_1007f2d0 = (iVar24 << 0x10 | uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
    uVar4 = uVar4 & 0xffff;
    if ((local_44 == local_3c) || (iVar10 == 1)) {
      uVar4 = uVar4 - (uVar6 & 0xffff);
    }
    else if (iVar10 == 2) {
      uVar4 = (int)(uVar4 - (uVar6 & 0xffff)) >> 1;
    }
    else {
      uVar4 = (int)(uVar4 - (uVar6 & 0xffff)) / iVar10;
    }
    uVar22 = uVar6 & 0xffff;
    DAT_1007f2e0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
    uVar8 = uVar8 & 0xffff;
    if ((local_14 == local_3c) || (local_64 == 1)) {
      uVar8 = uVar8 - uVar22;
    }
    else if (local_64 == 2) {
      uVar8 = (int)(uVar8 - uVar22) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - uVar22) / local_64;
    }
    DAT_1007f2dc = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    DAT_1007f284 = DAT_1007f280 << 0x10;
    DAT_1007f2c0 = (uVar18 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
    uVar20 = (uVar19 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1007f2cc = uVar5;
    _DAT_1007f2d8 = uVar6;
  }
  else {
    iVar10 = iVar23 - DAT_1007f280;
    if (local_64 == 1) {
      DAT_1007f28c = iVar10 * 0x10000;
    }
    else if (local_64 == 2) {
      DAT_1007f28c = iVar10 * 0x8000;
    }
    else if (((local_64 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar9 + (iVar10 * 0x20 + local_64) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f28c = (iVar10 * 0x10000) / local_64;
    }
    else {
      DAT_1007f28c = (iVar10 * 0x10000) / local_64;
    }
    iVar10 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (iVar10 < 1) {
      iVar10 = iVar24 - DAT_1007f280;
      if (iVar10 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar23 = iVar23 - iVar24;
      if (local_64 == 1) {
        DAT_1007f288 = iVar23 * 0x10000;
      }
      else if (local_64 == 2) {
        DAT_1007f288 = iVar23 * 0x8000;
      }
      else if (((local_64 < 0x20) && (-0x20 < iVar23)) && (iVar23 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar9 + (iVar23 * 0x20 + local_64) * 4);
      }
      else if (iVar23 < 0) {
        DAT_1007f288 = (iVar23 * 0x10000) / local_64;
      }
      else {
        DAT_1007f288 = (iVar23 * 0x10000) / local_64;
      }
      if ((uVar25 == uVar20) || (iVar10 == 1)) {
        uVar25 = uVar25 - uVar20;
      }
      else if (iVar10 == 2) {
        uVar25 = (int)(uVar25 - uVar20) >> 1;
      }
      else {
        uVar25 = (int)(uVar25 - uVar20) / iVar10;
      }
      if ((uVar27 == uVar19) || (iVar10 == 1)) {
        uVar27 = uVar27 - uVar19;
      }
      else if (iVar10 == 2) {
        uVar27 = (int)(uVar27 - uVar19) >> 1;
      }
      else {
        uVar27 = (int)(uVar27 - uVar19) / iVar10;
      }
      if ((uVar17 == uVar20) || (local_64 == 1)) {
        uVar17 = uVar17 - uVar20;
      }
      else if (local_64 == 2) {
        uVar17 = (int)(uVar17 - uVar20) >> 1;
      }
      else {
        uVar17 = (int)(uVar17 - uVar20) / local_64;
      }
      if ((uVar18 == uVar19) || (local_64 == 1)) {
        uVar18 = uVar18 - uVar19;
      }
      else if (local_64 == 2) {
        uVar18 = (int)(uVar18 - uVar19) >> 1;
      }
      else {
        uVar18 = (int)(uVar18 - uVar19) / local_64;
      }
      if ((uVar2 == uVar1) || (iVar10 == 1)) {
        iVar9 = (uVar12 & 0xffff) - (uint)uVar1;
      }
      else if (iVar10 == 2) {
        iVar9 = (int)((uVar12 & 0xffff) - (uint)uVar1) >> 1;
      }
      else {
        iVar9 = (int)((uVar12 & 0xffff) - (uint)uVar1) / iVar10;
      }
      uVar12 = (uint)uVar1;
      uVar7 = uVar7 & 0xffff;
      if ((local_24 == (short)local_5c) || (iVar10 == 1)) {
        uVar7 = uVar7 - (uVar22 & 0xffff);
      }
      else if (iVar10 == 2) {
        uVar7 = (int)(uVar7 - (uVar22 & 0xffff)) >> 1;
      }
      else {
        uVar7 = (int)(uVar7 - (uVar22 & 0xffff)) / iVar10;
      }
      uVar22 = uVar22 & 0xffff;
      DAT_1007f2d4 = (iVar9 << 0x10 | uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      uVar5 = (int)uVar5 >> 0x10;
      if ((uVar21 == uVar1) || (local_64 == 1)) {
        iVar9 = (uVar5 & 0xffff) - uVar12;
      }
      else if (local_64 == 2) {
        iVar9 = (int)((uVar5 & 0xffff) - uVar12) >> 1;
      }
      else {
        iVar9 = (int)((uVar5 & 0xffff) - uVar12) / local_64;
      }
      local_28 = local_28 & 0xffff;
      if ((local_40 == (short)local_5c) || (local_64 == 1)) {
        local_28 = local_28 - uVar22;
      }
      else if (local_64 == 2) {
        local_28 = (int)(local_28 - uVar22) >> 1;
      }
      else {
        local_28 = (int)(local_28 - uVar22) / local_64;
      }
      DAT_1007f2d0 = (iVar9 << 0x10 | local_28 & 0xffff) + (local_28 & 0x8000) * -2;
      uVar8 = uVar8 & 0xffff;
      if ((local_44 == local_14) || (iVar10 == 1)) {
        uVar8 = uVar8 - (uVar4 & 0xffff);
      }
      else if (iVar10 == 2) {
        uVar8 = (int)(uVar8 - (uVar4 & 0xffff)) >> 1;
      }
      else {
        uVar8 = (int)(uVar8 - (uVar4 & 0xffff)) / iVar10;
      }
      uVar22 = uVar4 & 0xffff;
      DAT_1007f2e0 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      uVar6 = uVar6 & 0xffff;
      if ((local_44 == local_3c) || (local_64 == 1)) {
        uVar6 = uVar6 - uVar22;
      }
      else if (local_64 == 2) {
        uVar6 = (int)(uVar6 - uVar22) >> 1;
      }
      else {
        uVar6 = (int)(uVar6 - uVar22) / local_64;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f2dc = (uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
      DAT_1007f284 = iVar24 << 0x10;
      DAT_1007f2c0 = (uVar19 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
      DAT_1007f2c8 = (uVar27 & 0xfffe) << 0xf | (uVar25 & 0xfffe) >> 1;
      DAT_1007f2c4 = (uVar18 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
      DAT_1007f2cc = uVar3;
      _DAT_1007f2d8 = uVar4;
      goto LAB_100171ea;
    }
    iVar11 = iVar24 - DAT_1007f280;
    iVar14 = iVar10;
    if (iVar10 == 1) {
      DAT_1007f288 = iVar11 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1007f288 = iVar11 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar9 + (iVar11 * 0x20 + iVar10) * 4);
      iVar14 = iVar9;
    }
    else if (iVar11 < 0) {
      DAT_1007f288 = (iVar11 * 0x10000) / iVar10;
      iVar14 = (iVar11 * 0x10000) % iVar10;
    }
    else {
      DAT_1007f288 = (iVar11 * 0x10000) / iVar10;
      iVar14 = (iVar11 * 0x10000) % iVar10;
    }
    uVar12 = DAT_1007f288 - DAT_1007f28c;
    if ((int)uVar12 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    if ((uVar17 == uVar20) || (local_64 == 1)) {
      uVar5 = uVar17 - uVar20;
    }
    else if (local_64 == 2) {
      uVar5 = (int)(uVar17 - uVar20) >> 1;
    }
    else {
      uVar5 = (int)(uVar17 - uVar20) / local_64;
      iVar14 = (int)(uVar17 - uVar20) % local_64;
    }
    if ((uVar18 == uVar19) || (local_64 == 1)) {
      uVar26 = uVar18 - uVar19;
    }
    else if (local_64 == 2) {
      uVar26 = (int)(uVar18 - uVar19) >> 1;
    }
    else {
      uVar26 = (int)(uVar18 - uVar19) / local_64;
      iVar14 = (int)(uVar18 - uVar19) % local_64;
    }
    if ((uVar25 == uVar20) || (iVar10 == 1)) {
      iVar11 = uVar25 - uVar20;
    }
    else if (iVar10 == 2) {
      iVar11 = (int)(uVar25 - uVar20) >> 1;
    }
    else {
      iVar11 = (int)(uVar25 - uVar20) / iVar10;
      iVar14 = (int)(uVar25 - uVar20) % iVar10;
    }
    iVar11 = iVar11 - uVar5;
    uVar28 = CONCAT44(iVar14,iVar11);
    if (iVar11 != 0) {
      uVar28 = FUN_10069324(iVar11,iVar14,iVar11,uVar12);
    }
    iVar14 = (int)((ulonglong)uVar28 >> 0x20);
    local_20 = (uint)uVar28;
    if ((uVar27 == uVar19) || (iVar10 == 1)) {
      iVar11 = uVar27 - uVar19;
    }
    else if (iVar10 == 2) {
      iVar11 = (int)(uVar27 - uVar19) >> 1;
    }
    else {
      iVar11 = (int)(uVar27 - uVar19) / iVar10;
      iVar14 = (int)(uVar27 - uVar19) % iVar10;
    }
    iVar11 = iVar11 - uVar26;
    uVar13 = 0;
    if (iVar11 != 0) {
      uVar28 = FUN_10069324(iVar11,iVar14,iVar11,uVar12);
      uVar13 = (uint)uVar28;
    }
    if ((uVar21 == uVar1) || (local_64 == 1)) {
      iVar14 = (uint)uVar21 - (uint)uVar1;
    }
    else if (local_64 == 2) {
      iVar14 = (int)((uint)uVar21 - (uint)uVar1) >> 1;
    }
    else {
      iVar14 = (int)((uint)uVar21 - (uint)uVar1) / local_64;
    }
    local_2c = (uint)uVar21;
    uVar16 = (uint)uVar1;
    if ((local_40 == (short)local_5c) || (local_64 == 1)) {
      uVar15 = (local_28 & 0xffff) - (uVar22 & 0xffff);
    }
    else if (local_64 == 2) {
      uVar15 = (int)((local_28 & 0xffff) - (uVar22 & 0xffff)) >> 1;
    }
    else {
      uVar15 = (int)((local_28 & 0xffff) - (uVar22 & 0xffff)) / local_64;
    }
    local_28 = local_28 & 0xffff;
    uVar22 = uVar22 & 0xffff;
    DAT_1007f2d0 = (iVar14 << 0x10 | uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    if ((uVar2 == uVar1) || (iVar10 == 1)) {
      iVar14 = uVar2 - uVar16;
    }
    else if (iVar10 == 2) {
      iVar14 = (int)(uVar2 - uVar16) >> 1;
    }
    else {
      iVar14 = (int)(uVar2 - uVar16) / iVar10;
    }
    local_48 = (uint)uVar2;
    DAT_1007f2d4 = iVar14 - (DAT_1007f2d0 >> 0x10);
    if (DAT_1007f2d4 != 0) {
      DAT_1007f2d4 = (int)(DAT_1007f2d4 * 0x10000) / (int)uVar12 << 0x10;
    }
    if ((local_24 == (short)local_5c) || (iVar10 == 1)) {
      iVar14 = (uVar7 & 0xffff) - uVar22;
    }
    else if (iVar10 == 2) {
      iVar14 = (int)((uVar7 & 0xffff) - uVar22) >> 1;
    }
    else {
      iVar14 = (int)((uVar7 & 0xffff) - uVar22) / iVar10;
    }
    uVar7 = uVar7 & 0xffff;
    if (iVar14 - (short)DAT_1007f2d0 != 0) {
      uVar22 = DAT_1007f2d4 | ((iVar14 - (short)DAT_1007f2d0) * 0x10000) / (int)uVar12 & 0xffffU;
      DAT_1007f2d4 = uVar22 + (uVar22 & 0x8000) * -2;
    }
    uVar22 = uVar4 & 0xffff;
    if ((local_44 == local_3c) || (local_64 == 1)) {
      uVar16 = (uVar6 & 0xffff) - uVar22;
    }
    else if (local_64 == 2) {
      uVar16 = (int)((uVar6 & 0xffff) - uVar22) >> 1;
    }
    else {
      uVar16 = (int)((uVar6 & 0xffff) - uVar22) / local_64;
    }
    local_5c = uVar6 & 0xffff;
    DAT_1007f2e0 = 0;
    DAT_1007f2dc = (uVar16 & 0xffff) + (uVar16 & 0x8000) * -2;
    if ((local_44 == local_14) || (iVar10 == 1)) {
      iVar14 = (uVar8 & 0xffff) - uVar22;
    }
    else if (iVar10 == 2) {
      iVar14 = (int)((uVar8 & 0xffff) - uVar22) >> 1;
    }
    else {
      iVar14 = (int)((uVar8 & 0xffff) - uVar22) / iVar10;
    }
    uVar8 = uVar8 & 0xffff;
    if (iVar14 - (short)DAT_1007f2dc != 0) {
      uVar12 = ((iVar14 - (short)DAT_1007f2dc) * 0x10000) / (int)uVar12;
      DAT_1007f2e0 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
    }
    DAT_1007f280 = DAT_1007f280 << 0x10;
    DAT_1007f284 = DAT_1007f280;
    if (iVar10 <= local_64) {
      DAT_1007f2c0 = (uVar19 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
      DAT_1007f2c8 = (uVar13 & 0xfffe) << 0xf | (local_20 & 0xfffe) >> 1;
      DAT_1007f2c4 = (uVar26 & 0xfffe) << 0xf | (uVar5 & 0xfffe) >> 1;
      local_64 = local_64 - iVar10;
      DAT_1007f290 = iVar10;
      DAT_1007f2cc = uVar3;
      _DAT_1007f2d8 = uVar4;
      FUN_10017210((uint *)&DAT_1007f280);
      if (local_64 == 0) {
        return;
      }
      DAT_1007f284 = iVar24 << 0x10;
      iVar23 = iVar23 - iVar24;
      if (local_64 == 1) {
        DAT_1007f288 = iVar23 * 0x10000;
      }
      else if (local_64 == 2) {
        DAT_1007f288 = iVar23 * 0x8000;
      }
      else if (((local_64 < 0x20) && (-0x20 < iVar23)) && (iVar23 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar9 + (iVar23 * 0x20 + local_64) * 4);
      }
      else if (iVar23 < 0) {
        DAT_1007f288 = (iVar23 * 0x10000) / local_64;
      }
      else {
        DAT_1007f288 = (iVar23 * 0x10000) / local_64;
      }
      goto LAB_100171ea;
    }
    DAT_1007f2c0 = (uVar19 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    uVar20 = (uVar13 & 0xfffe) << 0xf | (local_20 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar26 & 0xfffe) << 0xf | (uVar5 & 0xfffe) >> 1;
    iVar10 = iVar10 - local_64;
    DAT_1007f290 = local_64;
    DAT_1007f2c8 = uVar20;
    DAT_1007f2cc = uVar3;
    _DAT_1007f2d8 = uVar4;
    FUN_10017210((uint *)&DAT_1007f280);
    iVar24 = iVar24 - iVar23;
    if (iVar10 == 1) {
      DAT_1007f28c = iVar24 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1007f28c = iVar24 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar9 + (iVar24 * 0x20 + iVar10) * 4);
    }
    else if (iVar24 < 0) {
      DAT_1007f28c = (iVar24 * 0x10000) / iVar10;
    }
    else {
      DAT_1007f28c = (iVar24 * 0x10000) / iVar10;
    }
    if ((uVar25 == uVar17) || (iVar10 == 1)) {
      uVar25 = uVar25 - uVar17;
    }
    else if (iVar10 == 2) {
      uVar25 = (int)(uVar25 - uVar17) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - uVar17) / iVar10;
    }
    if ((uVar27 == uVar18) || (iVar10 == 1)) {
      uVar27 = uVar27 - uVar18;
    }
    else if (iVar10 == 2) {
      uVar27 = (int)(uVar27 - uVar18) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar18) / iVar10;
    }
    if ((uVar2 == uVar21) || (iVar10 == 1)) {
      iVar9 = local_48 - local_2c;
    }
    else if (iVar10 == 2) {
      iVar9 = (int)(local_48 - local_2c) >> 1;
    }
    else {
      iVar9 = (int)(local_48 - local_2c) / iVar10;
    }
    DAT_1007f2d0 = iVar9 << 0x10;
    if ((local_24 == local_40) || (iVar10 == 1)) {
      uVar7 = uVar7 - local_28;
    }
    else if (iVar10 == 2) {
      uVar7 = (int)(uVar7 - local_28) >> 1;
    }
    else {
      uVar7 = (int)(uVar7 - local_28) / iVar10;
    }
    if (uVar7 != 0) {
      DAT_1007f2d0 = (DAT_1007f2d0 | uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
    }
    DAT_1007f2dc = 0;
    if ((local_14 == local_3c) || (iVar10 == 1)) {
      uVar8 = uVar8 - local_5c;
    }
    else if (iVar10 == 2) {
      uVar8 = (int)(uVar8 - local_5c) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - local_5c) / iVar10;
    }
    local_64 = iVar10;
    if (uVar8 != 0) {
      DAT_1007f2dc = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    }
  }
  DAT_1007f280 = iVar23 << 0x10;
  DAT_1007f2c4 = (uVar27 & 0xfffe) << 0xf | (uVar25 & 0xfffe) >> 1;
  DAT_1007f2c8 = uVar20;
LAB_100171ea:
  DAT_1007f290 = local_64;
  FUN_10017210((uint *)&DAT_1007f280);
  return;
}


