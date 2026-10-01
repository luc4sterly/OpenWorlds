// 10012d70 FUN_10012d70 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10012d70(int *param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
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
  int iVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
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
  ushort uVar3;
  
  iVar21 = param_3;
  iVar22 = param_4;
  iVar23 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar21 = param_2;
      iVar22 = param_3;
      iVar23 = param_4;
    }
LAB_10012db9:
    param_4 = iVar21;
    param_2 = iVar22;
    param_3 = iVar23;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10012db9;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  local_64 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar19 = *(uint *)(param_2 + 100);
  uVar26 = *(uint *)(param_2 + 0x68);
  uVar20 = *(int *)(param_2 + 0x5c) >> 8;
  uVar4 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | uVar20;
  iVar21 = (int)*(short *)(param_3 + 0x1a);
  uVar5 = *(int *)(param_2 + 0x60) >> 8;
  uVar17 = *(uint *)(param_3 + 100);
  uVar18 = *(uint *)(param_3 + 0x68);
  local_28 = *(int *)(param_3 + 0x5c) >> 8;
  uVar6 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | local_28;
  iVar22 = (int)*(short *)(param_4 + 0x1a);
  uVar7 = *(int *)(param_3 + 0x60) >> 8;
  uVar27 = *(uint *)(param_4 + 100);
  uVar24 = *(uint *)(param_4 + 0x68);
  uVar8 = *(int *)(param_4 + 0x5c) >> 8;
  uVar25 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar8;
  uVar9 = *(int *)(param_4 + 0x60) >> 8;
  iVar23 = DAT_10079214 + 0x1000;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  local_5c._0_2_ = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  local_24 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  local_3c = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  local_14 = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  local_40 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  local_44 = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  uVar12 = (int)uVar25 >> 0x10;
  uVar1 = (ushort)(uVar6 >> 0x10);
  uVar2 = (ushort)(uVar4 >> 0x10);
  uVar3 = (ushort)(uVar25 >> 0x10);
  if (local_64 < 1) {
    iVar10 = DAT_1007f280 - iVar21;
    if (iVar10 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    local_64 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_64 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    iVar14 = iVar22 - iVar21;
    if (local_64 == 1) {
      DAT_1007f28c = iVar14 * 0x10000;
    }
    else if (local_64 == 2) {
      DAT_1007f28c = iVar14 * 0x8000;
    }
    else if (((local_64 < 0x20) && (-0x20 < iVar14)) && (iVar14 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar23 + (iVar14 * 0x20 + local_64) * 4);
    }
    else if (iVar14 < 0) {
      DAT_1007f28c = (iVar14 * 0x10000) / local_64;
    }
    else {
      DAT_1007f28c = (iVar14 * 0x10000) / local_64;
    }
    iVar22 = iVar22 - DAT_1007f280;
    if (local_64 == 1) {
      DAT_1007f288 = iVar22 * 0x10000;
    }
    else if (local_64 == 2) {
      DAT_1007f288 = iVar22 * 0x8000;
    }
    else if (((local_64 < 0x20) && (-0x20 < iVar22)) && (iVar22 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar23 + (iVar22 * 0x20 + local_64) * 4);
    }
    else if (iVar22 < 0) {
      DAT_1007f288 = (iVar22 * 0x10000) / local_64;
    }
    else {
      DAT_1007f288 = (iVar22 * 0x10000) / local_64;
    }
    if ((uVar17 == uVar19) || (iVar10 == 1)) {
      uVar19 = uVar19 - uVar17;
    }
    else if (iVar10 == 2) {
      uVar19 = (int)(uVar19 - uVar17) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar17) / iVar10;
    }
    if ((uVar27 == uVar17) || (local_64 == 1)) {
      uVar27 = uVar27 - uVar17;
    }
    else if (local_64 == 2) {
      uVar27 = (int)(uVar27 - uVar17) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar17) / local_64;
    }
    if ((uVar18 == uVar26) || (iVar10 == 1)) {
      uVar26 = uVar26 - uVar18;
    }
    else if (iVar10 == 2) {
      uVar26 = (int)(uVar26 - uVar18) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar18) / iVar10;
    }
    if ((uVar24 == uVar18) || (local_64 == 1)) {
      uVar24 = uVar24 - uVar18;
    }
    else if (local_64 == 2) {
      uVar24 = (int)(uVar24 - uVar18) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar18) / local_64;
    }
    uVar4 = (int)uVar4 >> 0x10;
    if ((uVar1 == uVar2) || (iVar10 == 1)) {
      iVar22 = (uVar4 & 0xffff) - (uint)uVar1;
    }
    else if (iVar10 == 2) {
      iVar22 = (int)((uVar4 & 0xffff) - (uint)uVar1) >> 1;
    }
    else {
      iVar22 = (int)((uVar4 & 0xffff) - (uint)uVar1) / iVar10;
    }
    uVar4 = (uint)uVar1;
    if ((uVar3 == uVar1) || (local_64 == 1)) {
      iVar23 = (uVar12 & 0xffff) - uVar4;
    }
    else if (local_64 == 2) {
      iVar23 = (int)((uVar12 & 0xffff) - uVar4) >> 1;
    }
    else {
      iVar23 = (int)((uVar12 & 0xffff) - uVar4) / local_64;
    }
    uVar20 = uVar20 & 0xffff;
    if ((local_40 == (short)local_5c) || (iVar10 == 1)) {
      uVar20 = uVar20 - (local_28 & 0xffff);
    }
    else if (iVar10 == 2) {
      uVar20 = (int)(uVar20 - (local_28 & 0xffff)) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - (local_28 & 0xffff)) / iVar10;
    }
    local_28 = local_28 & 0xffff;
    DAT_1007f2d4 = (iVar22 << 0x10 | uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
    uVar8 = uVar8 & 0xffff;
    if ((local_24 == local_40) || (local_64 == 1)) {
      uVar8 = uVar8 - local_28;
    }
    else if (local_64 == 2) {
      uVar8 = (int)(uVar8 - local_28) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - local_28) / local_64;
    }
    DAT_1007f2d0 = (iVar23 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    uVar5 = uVar5 & 0xffff;
    if ((local_3c == local_44) || (iVar10 == 1)) {
      uVar5 = uVar5 - (uVar7 & 0xffff);
    }
    else if (iVar10 == 2) {
      uVar5 = (int)(uVar5 - (uVar7 & 0xffff)) >> 1;
    }
    else {
      uVar5 = (int)(uVar5 - (uVar7 & 0xffff)) / iVar10;
    }
    uVar20 = uVar7 & 0xffff;
    DAT_1007f2e0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    uVar9 = uVar9 & 0xffff;
    if ((local_14 == local_3c) || (local_64 == 1)) {
      uVar9 = uVar9 - uVar20;
    }
    else if (local_64 == 2) {
      uVar9 = (int)(uVar9 - uVar20) >> 1;
    }
    else {
      uVar9 = (int)(uVar9 - uVar20) / local_64;
    }
    DAT_1007f2dc = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    DAT_1007f284 = DAT_1007f280 << 0x10;
    DAT_1007f2c0 = (uVar18 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
    DAT_1007f2c8 = (uVar26 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    DAT_1007f2cc = uVar6;
    _DAT_1007f2d8 = uVar7;
  }
  else {
    iVar10 = iVar21 - DAT_1007f280;
    if (local_64 == 1) {
      DAT_1007f28c = iVar10 * 0x10000;
    }
    else if (local_64 == 2) {
      DAT_1007f28c = iVar10 * 0x8000;
    }
    else if (((local_64 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar23 + (iVar10 * 0x20 + local_64) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f28c = (iVar10 * 0x10000) / local_64;
    }
    else {
      DAT_1007f28c = (iVar10 * 0x10000) / local_64;
    }
    iVar10 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (iVar10 < 1) {
      iVar10 = iVar22 - DAT_1007f280;
      if (iVar10 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar21 = iVar21 - iVar22;
      if (local_64 == 1) {
        DAT_1007f288 = iVar21 * 0x10000;
      }
      else if (local_64 == 2) {
        DAT_1007f288 = iVar21 * 0x8000;
      }
      else if (((local_64 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar23 + (iVar21 * 0x20 + local_64) * 4);
      }
      else if (iVar21 < 0) {
        DAT_1007f288 = (iVar21 * 0x10000) / local_64;
      }
      else {
        DAT_1007f288 = (iVar21 * 0x10000) / local_64;
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
      if ((uVar24 == uVar26) || (iVar10 == 1)) {
        uVar24 = uVar24 - uVar26;
      }
      else if (iVar10 == 2) {
        uVar24 = (int)(uVar24 - uVar26) >> 1;
      }
      else {
        uVar24 = (int)(uVar24 - uVar26) / iVar10;
      }
      if ((uVar17 == uVar19) || (local_64 == 1)) {
        uVar17 = uVar17 - uVar19;
      }
      else if (local_64 == 2) {
        uVar17 = (int)(uVar17 - uVar19) >> 1;
      }
      else {
        uVar17 = (int)(uVar17 - uVar19) / local_64;
      }
      if ((uVar18 == uVar26) || (local_64 == 1)) {
        uVar18 = uVar18 - uVar26;
      }
      else if (local_64 == 2) {
        uVar18 = (int)(uVar18 - uVar26) >> 1;
      }
      else {
        uVar18 = (int)(uVar18 - uVar26) / local_64;
      }
      if ((uVar3 == uVar2) || (iVar10 == 1)) {
        iVar21 = (uVar12 & 0xffff) - (uint)uVar2;
      }
      else if (iVar10 == 2) {
        iVar21 = (int)((uVar12 & 0xffff) - (uint)uVar2) >> 1;
      }
      else {
        iVar21 = (int)((uVar12 & 0xffff) - (uint)uVar2) / iVar10;
      }
      uVar12 = (uint)uVar2;
      uVar8 = uVar8 & 0xffff;
      if ((local_24 == (short)local_5c) || (iVar10 == 1)) {
        uVar8 = uVar8 - (uVar20 & 0xffff);
      }
      else if (iVar10 == 2) {
        uVar8 = (int)(uVar8 - (uVar20 & 0xffff)) >> 1;
      }
      else {
        uVar8 = (int)(uVar8 - (uVar20 & 0xffff)) / iVar10;
      }
      uVar20 = uVar20 & 0xffff;
      DAT_1007f2d4 = (iVar21 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      uVar6 = (int)uVar6 >> 0x10;
      if ((uVar1 == uVar2) || (local_64 == 1)) {
        iVar21 = (uVar6 & 0xffff) - uVar12;
      }
      else if (local_64 == 2) {
        iVar21 = (int)((uVar6 & 0xffff) - uVar12) >> 1;
      }
      else {
        iVar21 = (int)((uVar6 & 0xffff) - uVar12) / local_64;
      }
      local_28 = local_28 & 0xffff;
      if ((local_40 == (short)local_5c) || (local_64 == 1)) {
        local_28 = local_28 - uVar20;
      }
      else if (local_64 == 2) {
        local_28 = (int)(local_28 - uVar20) >> 1;
      }
      else {
        local_28 = (int)(local_28 - uVar20) / local_64;
      }
      DAT_1007f2d0 = (iVar21 << 0x10 | local_28 & 0xffff) + (local_28 & 0x8000) * -2;
      uVar9 = uVar9 & 0xffff;
      if ((local_14 == local_44) || (iVar10 == 1)) {
        uVar9 = uVar9 - (uVar5 & 0xffff);
      }
      else if (iVar10 == 2) {
        uVar9 = (int)(uVar9 - (uVar5 & 0xffff)) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - (uVar5 & 0xffff)) / iVar10;
      }
      uVar20 = uVar5 & 0xffff;
      DAT_1007f2e0 = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      uVar7 = uVar7 & 0xffff;
      if ((local_3c == local_44) || (local_64 == 1)) {
        uVar7 = uVar7 - uVar20;
      }
      else if (local_64 == 2) {
        uVar7 = (int)(uVar7 - uVar20) >> 1;
      }
      else {
        uVar7 = (int)(uVar7 - uVar20) / local_64;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f2dc = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      DAT_1007f284 = iVar22 << 0x10;
      DAT_1007f2c0 = (uVar26 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
      DAT_1007f2c8 = (uVar24 & 0xfffe) << 0xf | (uVar27 & 0xfffe) >> 1;
      DAT_1007f2c4 = (uVar18 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
      DAT_1007f2cc = uVar4;
      _DAT_1007f2d8 = uVar5;
      goto LAB_100141af;
    }
    iVar11 = iVar22 - DAT_1007f280;
    iVar14 = iVar10;
    if (iVar10 == 1) {
      DAT_1007f288 = iVar11 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1007f288 = iVar11 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar23 + (iVar11 * 0x20 + iVar10) * 4);
      iVar14 = iVar23;
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
    if ((uVar17 == uVar19) || (local_64 == 1)) {
      uVar6 = uVar17 - uVar19;
    }
    else if (local_64 == 2) {
      uVar6 = (int)(uVar17 - uVar19) >> 1;
    }
    else {
      uVar6 = (int)(uVar17 - uVar19) / local_64;
      iVar14 = (int)(uVar17 - uVar19) % local_64;
    }
    if ((uVar18 == uVar26) || (local_64 == 1)) {
      uVar25 = uVar18 - uVar26;
    }
    else if (local_64 == 2) {
      uVar25 = (int)(uVar18 - uVar26) >> 1;
    }
    else {
      uVar25 = (int)(uVar18 - uVar26) / local_64;
      iVar14 = (int)(uVar18 - uVar26) % local_64;
    }
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
    iVar11 = iVar11 - uVar6;
    uVar28 = CONCAT44(iVar14,iVar11);
    if (iVar11 != 0) {
      uVar28 = FUN_10069324(iVar11,iVar14,iVar11,uVar12);
    }
    iVar14 = (int)((ulonglong)uVar28 >> 0x20);
    local_20 = (uint)uVar28;
    if ((uVar24 == uVar26) || (iVar10 == 1)) {
      iVar11 = uVar24 - uVar26;
    }
    else if (iVar10 == 2) {
      iVar11 = (int)(uVar24 - uVar26) >> 1;
    }
    else {
      iVar11 = (int)(uVar24 - uVar26) / iVar10;
      iVar14 = (int)(uVar24 - uVar26) % iVar10;
    }
    iVar11 = iVar11 - uVar25;
    uVar13 = 0;
    if (iVar11 != 0) {
      uVar28 = FUN_10069324(iVar11,iVar14,iVar11,uVar12);
      uVar13 = (uint)uVar28;
    }
    if ((uVar1 == uVar2) || (local_64 == 1)) {
      iVar14 = (uint)uVar1 - (uint)uVar2;
    }
    else if (local_64 == 2) {
      iVar14 = (int)((uint)uVar1 - (uint)uVar2) >> 1;
    }
    else {
      iVar14 = (int)((uint)uVar1 - (uint)uVar2) / local_64;
    }
    local_2c = (uint)uVar1;
    uVar16 = (uint)uVar2;
    if ((local_40 == (short)local_5c) || (local_64 == 1)) {
      uVar15 = (local_28 & 0xffff) - (uVar20 & 0xffff);
    }
    else if (local_64 == 2) {
      uVar15 = (int)((local_28 & 0xffff) - (uVar20 & 0xffff)) >> 1;
    }
    else {
      uVar15 = (int)((local_28 & 0xffff) - (uVar20 & 0xffff)) / local_64;
    }
    local_28 = local_28 & 0xffff;
    uVar20 = uVar20 & 0xffff;
    DAT_1007f2d0 = (iVar14 << 0x10 | uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    if ((uVar3 == uVar2) || (iVar10 == 1)) {
      iVar14 = uVar3 - uVar16;
    }
    else if (iVar10 == 2) {
      iVar14 = (int)(uVar3 - uVar16) >> 1;
    }
    else {
      iVar14 = (int)(uVar3 - uVar16) / iVar10;
    }
    local_48 = (uint)uVar3;
    DAT_1007f2d4 = iVar14 - (DAT_1007f2d0 >> 0x10);
    if (DAT_1007f2d4 != 0) {
      DAT_1007f2d4 = (int)(DAT_1007f2d4 * 0x10000) / (int)uVar12 << 0x10;
    }
    if ((local_24 == (short)local_5c) || (iVar10 == 1)) {
      iVar14 = (uVar8 & 0xffff) - uVar20;
    }
    else if (iVar10 == 2) {
      iVar14 = (int)((uVar8 & 0xffff) - uVar20) >> 1;
    }
    else {
      iVar14 = (int)((uVar8 & 0xffff) - uVar20) / iVar10;
    }
    uVar8 = uVar8 & 0xffff;
    if (iVar14 - (short)DAT_1007f2d0 != 0) {
      uVar20 = DAT_1007f2d4 | ((iVar14 - (short)DAT_1007f2d0) * 0x10000) / (int)uVar12 & 0xffffU;
      DAT_1007f2d4 = uVar20 + (uVar20 & 0x8000) * -2;
    }
    uVar20 = uVar5 & 0xffff;
    if ((local_3c == local_44) || (local_64 == 1)) {
      uVar16 = (uVar7 & 0xffff) - uVar20;
    }
    else if (local_64 == 2) {
      uVar16 = (int)((uVar7 & 0xffff) - uVar20) >> 1;
    }
    else {
      uVar16 = (int)((uVar7 & 0xffff) - uVar20) / local_64;
    }
    local_5c = uVar7 & 0xffff;
    DAT_1007f2e0 = 0;
    DAT_1007f2dc = (uVar16 & 0xffff) + (uVar16 & 0x8000) * -2;
    if ((local_14 == local_44) || (iVar10 == 1)) {
      iVar14 = (uVar9 & 0xffff) - uVar20;
    }
    else if (iVar10 == 2) {
      iVar14 = (int)((uVar9 & 0xffff) - uVar20) >> 1;
    }
    else {
      iVar14 = (int)((uVar9 & 0xffff) - uVar20) / iVar10;
    }
    uVar9 = uVar9 & 0xffff;
    if (iVar14 - (short)DAT_1007f2dc != 0) {
      uVar12 = ((iVar14 - (short)DAT_1007f2dc) * 0x10000) / (int)uVar12;
      DAT_1007f2e0 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
    }
    DAT_1007f280 = DAT_1007f280 << 0x10;
    DAT_1007f284 = DAT_1007f280;
    if (iVar10 <= local_64) {
      DAT_1007f2c0 = (uVar26 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
      DAT_1007f2c8 = (uVar13 & 0xfffe) << 0xf | (local_20 & 0xfffe) >> 1;
      DAT_1007f2c4 = (uVar25 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
      local_64 = local_64 - iVar10;
      DAT_1007f290 = iVar10;
      DAT_1007f2cc = uVar4;
      _DAT_1007f2d8 = uVar5;
      FUN_100141d0((uint *)&DAT_1007f280);
      if (local_64 == 0) {
        return;
      }
      DAT_1007f284 = iVar22 << 0x10;
      iVar21 = iVar21 - iVar22;
      if (local_64 == 1) {
        DAT_1007f288 = iVar21 * 0x10000;
      }
      else if (local_64 == 2) {
        DAT_1007f288 = iVar21 * 0x8000;
      }
      else if (((local_64 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar23 + (iVar21 * 0x20 + local_64) * 4);
      }
      else if (iVar21 < 0) {
        DAT_1007f288 = (iVar21 * 0x10000) / local_64;
      }
      else {
        DAT_1007f288 = (iVar21 * 0x10000) / local_64;
      }
      goto LAB_100141af;
    }
    DAT_1007f2c0 = (uVar26 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    uVar19 = (uVar13 & 0xfffe) << 0xf | (local_20 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar25 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
    iVar10 = iVar10 - local_64;
    DAT_1007f290 = local_64;
    DAT_1007f2c8 = uVar19;
    DAT_1007f2cc = uVar4;
    _DAT_1007f2d8 = uVar5;
    FUN_100141d0((uint *)&DAT_1007f280);
    iVar22 = iVar22 - iVar21;
    if (iVar10 == 1) {
      DAT_1007f28c = iVar22 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1007f28c = iVar22 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar22)) && (iVar22 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar23 + (iVar22 * 0x20 + iVar10) * 4);
    }
    else if (iVar22 < 0) {
      DAT_1007f28c = (iVar22 * 0x10000) / iVar10;
    }
    else {
      DAT_1007f28c = (iVar22 * 0x10000) / iVar10;
    }
    if ((uVar27 == uVar17) || (iVar10 == 1)) {
      uVar27 = uVar27 - uVar17;
    }
    else if (iVar10 == 2) {
      uVar27 = (int)(uVar27 - uVar17) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar17) / iVar10;
    }
    if ((uVar24 == uVar18) || (iVar10 == 1)) {
      uVar24 = uVar24 - uVar18;
    }
    else if (iVar10 == 2) {
      uVar24 = (int)(uVar24 - uVar18) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar18) / iVar10;
    }
    if ((uVar3 == uVar1) || (iVar10 == 1)) {
      iVar22 = local_48 - local_2c;
    }
    else if (iVar10 == 2) {
      iVar22 = (int)(local_48 - local_2c) >> 1;
    }
    else {
      iVar22 = (int)(local_48 - local_2c) / iVar10;
    }
    DAT_1007f2d0 = iVar22 << 0x10;
    if ((local_24 == local_40) || (iVar10 == 1)) {
      uVar8 = uVar8 - local_28;
    }
    else if (iVar10 == 2) {
      uVar8 = (int)(uVar8 - local_28) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - local_28) / iVar10;
    }
    if (uVar8 != 0) {
      DAT_1007f2d0 = (DAT_1007f2d0 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    }
    DAT_1007f2dc = 0;
    if ((local_14 == local_3c) || (iVar10 == 1)) {
      uVar9 = uVar9 - local_5c;
    }
    else if (iVar10 == 2) {
      uVar9 = (int)(uVar9 - local_5c) >> 1;
    }
    else {
      uVar9 = (int)(uVar9 - local_5c) / iVar10;
    }
    DAT_1007f2c8 = uVar19;
    local_64 = iVar10;
    if (uVar9 != 0) {
      DAT_1007f2dc = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    }
  }
  DAT_1007f280 = iVar21 << 0x10;
  DAT_1007f2c4 = (uVar24 & 0xfffe) << 0xf | (uVar27 & 0xfffe) >> 1;
LAB_100141af:
  DAT_1007f290 = local_64;
  FUN_100141d0((uint *)&DAT_1007f280);
  return;
}


