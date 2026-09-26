// 10013610 FUN_10013610 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013610(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  ushort uVar30;
  int iVar31;
  uint uVar32;
  uint uVar33;
  longlong lVar34;
  undefined8 uVar35;
  int local_78;
  uint local_70;
  short local_5c;
  short local_58;
  short local_54;
  short local_50;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  short local_24;
  short local_20;
  uint local_1c;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  iVar25 = param_3;
  iVar27 = param_4;
  iVar31 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar25 = param_2;
      iVar27 = param_3;
      iVar31 = param_4;
    }
LAB_1001365e:
    param_2 = iVar27;
    param_4 = iVar25;
    param_3 = iVar31;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001365e;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  local_78 = (int)sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar29 = *(uint *)(param_2 + 100);
  uVar23 = *(uint *)(param_2 + 0x68);
  uVar8 = (*(uint *)(param_2 + 0x58) & 0xffff0001 | 0x10001) << 8 |
          (*(uint *)(param_2 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_2 + 0x14) <= _DAT_10089dd0)) {
    uVar24 = 0;
  }
  else {
    lVar34 = __ftol();
    if ((int)lVar34 == 0) {
      uVar24 = 0x1e00;
      DAT_1008dbe0._4_4_ = 0;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar34) * 0x1e;
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_2 + 0x58)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_2 + 0x58);
      }
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_2 + 0x5c)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_2 + 0x5c);
      }
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_2 + 0x60)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_2 + 0x60);
      }
      if ((int)DAT_1008dbe0._4_4_ < 0) {
        uVar24 = 0;
        DAT_1008dbe0._4_4_ = 0;
      }
      else {
        uVar24 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  uVar9 = (*(uint *)(param_2 + 0x60) & 0xfffe00ff) >> 8;
  uVar10 = uVar9 | uVar24 << 0x10;
  iVar25 = (int)*(short *)(param_3 + 0x1a);
  uVar11 = uVar10 | 0x100;
  uVar24 = *(uint *)(param_3 + 100);
  uVar22 = *(uint *)(param_3 + 0x68);
  local_30 = (*(uint *)(param_3 + 0x58) & 0xffff0001 | 0x10001) << 8 |
             (*(uint *)(param_3 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_3 + 0x14) <= _DAT_10089dd0)) {
    uVar26 = 0;
  }
  else {
    lVar34 = __ftol();
    if ((int)lVar34 == 0) {
      uVar26 = 0x1e00;
      DAT_1008dbe0._4_4_ = 0;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar34) * 0x1e;
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_3 + 0x58)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_3 + 0x58);
      }
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_3 + 0x5c)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_3 + 0x5c);
      }
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_3 + 0x60)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_3 + 0x60);
      }
      if ((int)DAT_1008dbe0._4_4_ < 0) {
        uVar26 = 0;
        DAT_1008dbe0._4_4_ = 0;
      }
      else {
        uVar26 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  uVar12 = (*(uint *)(param_3 + 0x60) & 0xfffe00ff) >> 8;
  uVar13 = uVar12 | uVar26 << 0x10;
  iVar27 = (int)*(short *)(param_4 + 0x1a);
  uVar14 = uVar13 | 0x100;
  uVar26 = *(uint *)(param_4 + 100);
  uVar33 = *(uint *)(param_4 + 0x68);
  uVar15 = (*(uint *)(param_4 + 0x58) & 0xffff0001 | 0x10001) << 8 |
           (*(uint *)(param_4 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_4 + 0x14) <= _DAT_10089dd0)) {
    uVar28 = 0;
  }
  else {
    lVar34 = __ftol();
    if ((int)lVar34 == 0) {
      uVar28 = 0x1e00;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar34) * 0x1e;
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_4 + 0x58)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_4 + 0x58);
      }
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_4 + 0x5c)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_4 + 0x5c);
      }
      if (0x1e0000 < DAT_1008dbe0._4_4_ + *(int *)(param_4 + 0x60)) {
        DAT_1008dbe0._4_4_ = 0x1e0000 - *(int *)(param_4 + 0x60);
      }
      if ((int)DAT_1008dbe0._4_4_ < 0) {
        uVar28 = 0;
      }
      else {
        uVar28 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  uVar16 = (*(uint *)(param_4 + 0x60) & 0xfffe00ff) >> 8;
  uVar28 = uVar16 | uVar28 << 0x10;
  uVar17 = uVar28 | 0x100;
  uVar18 = (DAT_10089ef8 << 5 | DAT_10089ef0) << 6 | DAT_10089de4;
  DAT_1008dbe0._0_4_ = uVar18 | uVar18 << 0x10;
  iVar31 = DAT_1008723c + 0x1000;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  local_5c = (short)uVar8;
  local_24 = (short)uVar15;
  local_58 = (short)uVar11;
  local_20 = (short)uVar17;
  local_54 = (short)local_30;
  local_50 = (short)uVar14;
  uVar3 = (ushort)(uVar13 >> 0x10);
  uVar4 = (ushort)(uVar8 >> 0x10);
  uVar13 = (int)uVar15 >> 0x10;
  uVar18 = (int)uVar11 >> 0x10;
  uVar17 = (int)uVar17 >> 0x10;
  uVar30 = (ushort)(local_30 >> 0x10);
  uVar5 = (ushort)(uVar15 >> 0x10);
  uVar6 = (ushort)(uVar28 >> 0x10);
  uVar7 = (ushort)(uVar10 >> 0x10);
  DAT_1008dbe0._4_4_ = (uint)DAT_1008dbe0;
  if (local_78 < 1) {
    iVar19 = DAT_1008d280 - iVar25;
    if (iVar19 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    local_78 = -((int)sVar1 - (int)sVar2);
    if (local_78 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar21 = iVar27 - iVar25;
    if (local_78 == 1) {
      DAT_1008d28c = iVar21 * 0x10000;
    }
    else if (local_78 == 2) {
      DAT_1008d28c = iVar21 * 0x8000;
    }
    else if (((local_78 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar31 + (iVar21 * 0x20 + local_78) * 4);
    }
    else if (iVar21 < 0) {
      DAT_1008d28c = (iVar21 * 0x10000) / local_78;
    }
    else {
      DAT_1008d28c = (iVar21 * 0x10000) / local_78;
    }
    iVar27 = iVar27 - DAT_1008d280;
    if (local_78 == 1) {
      DAT_1008d288 = iVar27 * 0x10000;
    }
    else if (local_78 == 2) {
      DAT_1008d288 = iVar27 * 0x8000;
    }
    else if (((local_78 < 0x20) && (-0x20 < iVar27)) && (iVar27 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar31 + (iVar27 * 0x20 + local_78) * 4);
    }
    else if (iVar27 < 0) {
      DAT_1008d288 = (iVar27 * 0x10000) / local_78;
    }
    else {
      DAT_1008d288 = (iVar27 * 0x10000) / local_78;
    }
    if ((uVar29 == uVar24) || (iVar19 == 1)) {
      uVar29 = uVar29 - uVar24;
    }
    else if (iVar19 == 2) {
      uVar29 = (int)(uVar29 - uVar24) >> 1;
    }
    else {
      uVar29 = (int)(uVar29 - uVar24) / iVar19;
    }
    if ((uVar26 == uVar24) || (local_78 == 1)) {
      uVar26 = uVar26 - uVar24;
    }
    else if (local_78 == 2) {
      uVar26 = (int)(uVar26 - uVar24) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar24) / local_78;
    }
    if ((uVar23 == uVar22) || (iVar19 == 1)) {
      uVar23 = uVar23 - uVar22;
    }
    else if (iVar19 == 2) {
      uVar23 = (int)(uVar23 - uVar22) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - uVar22) / iVar19;
    }
    if ((uVar33 == uVar22) || (local_78 == 1)) {
      uVar33 = uVar33 - uVar22;
    }
    else if (local_78 == 2) {
      uVar33 = (int)(uVar33 - uVar22) >> 1;
    }
    else {
      uVar33 = (int)(uVar33 - uVar22) / local_78;
    }
    uVar10 = (int)uVar8 >> 0x10;
    if ((uVar4 == uVar30) || (iVar19 == 1)) {
      iVar27 = (uVar10 & 0xffff) - (uint)uVar30;
    }
    else if (iVar19 == 2) {
      iVar27 = (int)((uVar10 & 0xffff) - (uint)uVar30) >> 1;
    }
    else {
      iVar27 = (int)((uVar10 & 0xffff) - (uint)uVar30) / iVar19;
    }
    uVar10 = (uint)uVar30;
    if ((uVar5 == uVar30) || (local_78 == 1)) {
      iVar31 = (uVar13 & 0xffff) - uVar10;
    }
    else if (local_78 == 2) {
      iVar31 = (int)((uVar13 & 0xffff) - uVar10) >> 1;
    }
    else {
      iVar31 = (int)((uVar13 & 0xffff) - uVar10) / local_78;
    }
    uVar8 = uVar8 & 0xffff;
    if ((local_5c == local_54) || (iVar19 == 1)) {
      uVar8 = uVar8 - (local_30 & 0xffff);
    }
    else if (iVar19 == 2) {
      uVar8 = (int)(uVar8 - (local_30 & 0xffff)) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - (local_30 & 0xffff)) / iVar19;
    }
    uVar10 = local_30 & 0xffff;
    DAT_1008d2d4 = (iVar27 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    uVar15 = uVar15 & 0xffff;
    if ((local_24 == local_54) || (local_78 == 1)) {
      uVar15 = uVar15 - uVar10;
    }
    else if (local_78 == 2) {
      uVar15 = (int)(uVar15 - uVar10) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar10) / local_78;
    }
    DAT_1008d2d0 = (iVar31 << 0x10 | uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    if ((uVar6 == uVar3) || (local_78 == 1)) {
      iVar27 = (uVar17 & 0xffff) - (uint)uVar3;
    }
    else if (local_78 == 2) {
      iVar27 = (int)((uVar17 & 0xffff) - (uint)uVar3) >> 1;
    }
    else {
      iVar27 = (int)((uVar17 & 0xffff) - (uint)uVar3) / local_78;
    }
    uVar8 = (uint)uVar3;
    if ((uVar3 == uVar7) || (iVar19 == 1)) {
      iVar31 = (uVar18 & 0xffff) - uVar8;
    }
    else if (iVar19 == 2) {
      iVar31 = (int)((uVar18 & 0xffff) - uVar8) >> 1;
    }
    else {
      iVar31 = (int)((uVar18 & 0xffff) - uVar8) / iVar19;
    }
    uVar8 = uVar9 & 0xffff | 0x100;
    if ((local_50 == local_58) || (iVar19 == 1)) {
      uVar8 = uVar8 - (uVar12 & 0xffff | 0x100);
    }
    else if (iVar19 == 2) {
      uVar8 = (int)(uVar8 - (uVar12 & 0xffff | 0x100)) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - (uVar12 & 0xffff | 0x100)) / iVar19;
    }
    uVar9 = uVar12 & 0xffff | 0x100;
    DAT_1008d2e0 = (iVar31 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    uVar8 = uVar16 & 0xffff | 0x100;
    if ((local_20 == local_50) || (local_78 == 1)) {
      uVar8 = uVar8 - uVar9;
    }
    else if (local_78 == 2) {
      uVar8 = (int)(uVar8 - uVar9) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - uVar9) / local_78;
    }
    DAT_1008d2dc = (iVar27 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d2c0 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
    uVar29 = (uVar23 & 0xfffe) << 0xf | (uVar29 & 0xfffe) >> 1;
    DAT_1008d2cc = local_30;
    DAT_1008d2d8 = uVar14;
  }
  else {
    iVar19 = iVar25 - DAT_1008d280;
    if (local_78 == 1) {
      DAT_1008d28c = iVar19 * 0x10000;
    }
    else if (local_78 == 2) {
      DAT_1008d28c = iVar19 * 0x8000;
    }
    else if (((local_78 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar31 + (iVar19 * 0x20 + local_78) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1008d28c = (iVar19 * 0x10000) / local_78;
    }
    else {
      DAT_1008d28c = (iVar19 * 0x10000) / local_78;
    }
    iVar19 = (int)sVar2 - DAT_1008d284;
    if (iVar19 < 1) {
      iVar19 = iVar27 - DAT_1008d280;
      if (iVar19 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar25 = iVar25 - iVar27;
      if (local_78 == 1) {
        DAT_1008d288 = iVar25 * 0x10000;
      }
      else if (local_78 == 2) {
        DAT_1008d288 = iVar25 * 0x8000;
      }
      else if (((local_78 < 0x20) && (-0x20 < iVar25)) && (iVar25 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar31 + (iVar25 * 0x20 + local_78) * 4);
      }
      else if (iVar25 < 0) {
        DAT_1008d288 = (iVar25 * 0x10000) / local_78;
      }
      else {
        DAT_1008d288 = (iVar25 * 0x10000) / local_78;
      }
      if ((uVar26 == uVar29) || (iVar19 == 1)) {
        uVar26 = uVar26 - uVar29;
      }
      else if (iVar19 == 2) {
        uVar26 = (int)(uVar26 - uVar29) >> 1;
      }
      else {
        uVar26 = (int)(uVar26 - uVar29) / iVar19;
      }
      if ((uVar33 == uVar23) || (iVar19 == 1)) {
        uVar33 = uVar33 - uVar23;
      }
      else if (iVar19 == 2) {
        uVar33 = (int)(uVar33 - uVar23) >> 1;
      }
      else {
        uVar33 = (int)(uVar33 - uVar23) / iVar19;
      }
      if ((uVar24 == uVar29) || (local_78 == 1)) {
        uVar24 = uVar24 - uVar29;
      }
      else if (local_78 == 2) {
        uVar24 = (int)(uVar24 - uVar29) >> 1;
      }
      else {
        uVar24 = (int)(uVar24 - uVar29) / local_78;
      }
      if ((uVar22 == uVar23) || (local_78 == 1)) {
        uVar22 = uVar22 - uVar23;
      }
      else if (local_78 == 2) {
        uVar22 = (int)(uVar22 - uVar23) >> 1;
      }
      else {
        uVar22 = (int)(uVar22 - uVar23) / local_78;
      }
      if ((uVar4 == uVar5) || (iVar19 == 1)) {
        iVar25 = (uVar13 & 0xffff) - (uint)uVar4;
      }
      else if (iVar19 == 2) {
        iVar25 = (int)((uVar13 & 0xffff) - (uint)uVar4) >> 1;
      }
      else {
        iVar25 = (int)((uVar13 & 0xffff) - (uint)uVar4) / iVar19;
      }
      uVar10 = (uint)uVar4;
      uVar15 = uVar15 & 0xffff;
      if ((local_5c == local_24) || (iVar19 == 1)) {
        uVar15 = uVar15 - (uVar8 & 0xffff);
      }
      else if (iVar19 == 2) {
        uVar15 = (int)(uVar15 - (uVar8 & 0xffff)) >> 1;
      }
      else {
        uVar15 = (int)(uVar15 - (uVar8 & 0xffff)) / iVar19;
      }
      uVar14 = uVar8 & 0xffff;
      DAT_1008d2d4 = (iVar25 << 0x10 | uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
      uVar13 = (int)local_30 >> 0x10;
      if ((uVar4 == uVar30) || (local_78 == 1)) {
        iVar25 = (uVar13 & 0xffff) - uVar10;
      }
      else if (local_78 == 2) {
        iVar25 = (int)((uVar13 & 0xffff) - uVar10) >> 1;
      }
      else {
        iVar25 = (int)((uVar13 & 0xffff) - uVar10) / local_78;
      }
      local_30 = local_30 & 0xffff;
      if ((local_5c == local_54) || (local_78 == 1)) {
        local_30 = local_30 - uVar14;
      }
      else if (local_78 == 2) {
        local_30 = (int)(local_30 - uVar14) >> 1;
      }
      else {
        local_30 = (int)(local_30 - uVar14) / local_78;
      }
      DAT_1008d2d0 = (iVar25 << 0x10 | local_30 & 0xffff) + (local_30 & 0x8000) * -2;
      if ((uVar6 == uVar7) || (iVar19 == 1)) {
        iVar25 = (uVar17 & 0xffff) - (uVar18 & 0xffff);
      }
      else if (iVar19 == 2) {
        iVar25 = (int)((uVar17 & 0xffff) - (uVar18 & 0xffff)) >> 1;
      }
      else {
        iVar25 = (int)((uVar17 & 0xffff) - (uVar18 & 0xffff)) / iVar19;
      }
      uVar10 = uVar16 & 0xffff | 0x100;
      if ((local_20 == local_58) || (iVar19 == 1)) {
        uVar10 = uVar10 - (uVar9 & 0xffff | 0x100);
      }
      else if (iVar19 == 2) {
        uVar10 = (int)(uVar10 - (uVar9 & 0xffff | 0x100)) >> 1;
      }
      else {
        uVar10 = (int)(uVar10 - (uVar9 & 0xffff | 0x100)) / iVar19;
      }
      uVar13 = uVar9 & 0xffff | 0x100;
      DAT_1008d2e0 = (iVar25 << 0x10 | uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
      uVar9 = uVar12 & 0xffff | 0x100;
      if ((local_50 == local_58) || (local_78 == 1)) {
        uVar9 = uVar9 - uVar13;
      }
      else if (local_78 == 2) {
        uVar9 = (int)(uVar9 - uVar13) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - uVar13) / local_78;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d2dc = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      DAT_1008d284 = iVar27 << 0x10;
      DAT_1008d2c0 = (uVar23 & 0xfffe) << 0xf | (uVar29 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar33 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
      DAT_1008d2cc = uVar8;
      DAT_1008d2d8 = uVar11;
      goto LAB_10015050;
    }
    iVar20 = iVar27 - DAT_1008d280;
    iVar21 = iVar19;
    if (iVar19 == 1) {
      DAT_1008d288 = iVar20 * 0x10000;
    }
    else if (iVar19 == 2) {
      DAT_1008d288 = iVar20 * 0x8000;
    }
    else if (((iVar19 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar31 + (iVar20 * 0x20 + iVar19) * 4);
      iVar21 = iVar31;
    }
    else if (iVar20 < 0) {
      DAT_1008d288 = (iVar20 * 0x10000) / iVar19;
      iVar21 = (iVar20 * 0x10000) % iVar19;
    }
    else {
      DAT_1008d288 = (iVar20 * 0x10000) / iVar19;
      iVar21 = (iVar20 * 0x10000) % iVar19;
    }
    uVar10 = DAT_1008d288 - DAT_1008d28c;
    if ((int)uVar10 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    if ((uVar24 == uVar29) || (local_78 == 1)) {
      uVar13 = uVar24 - uVar29;
    }
    else if (local_78 == 2) {
      uVar13 = (int)(uVar24 - uVar29) >> 1;
    }
    else {
      uVar13 = (int)(uVar24 - uVar29) / local_78;
      iVar21 = (int)(uVar24 - uVar29) % local_78;
    }
    if ((uVar22 == uVar23) || (local_78 == 1)) {
      uVar14 = uVar22 - uVar23;
    }
    else if (local_78 == 2) {
      uVar14 = (int)(uVar22 - uVar23) >> 1;
    }
    else {
      uVar14 = (int)(uVar22 - uVar23) / local_78;
      iVar21 = (int)(uVar22 - uVar23) % local_78;
    }
    if ((uVar26 == uVar29) || (iVar19 == 1)) {
      iVar20 = uVar26 - uVar29;
    }
    else if (iVar19 == 2) {
      iVar20 = (int)(uVar26 - uVar29) >> 1;
    }
    else {
      iVar20 = (int)(uVar26 - uVar29) / iVar19;
      iVar21 = (int)(uVar26 - uVar29) % iVar19;
    }
    iVar20 = iVar20 - uVar13;
    uVar35 = CONCAT44(iVar21,iVar20);
    if (iVar20 != 0) {
      uVar35 = FUN_1006a324(iVar20,iVar21,iVar20,uVar10);
    }
    iVar21 = (int)((ulonglong)uVar35 >> 0x20);
    local_1c = (uint)uVar35;
    if ((uVar33 == uVar23) || (iVar19 == 1)) {
      iVar20 = uVar33 - uVar23;
    }
    else if (iVar19 == 2) {
      iVar20 = (int)(uVar33 - uVar23) >> 1;
    }
    else {
      iVar20 = (int)(uVar33 - uVar23) / iVar19;
      iVar21 = (int)(uVar33 - uVar23) % iVar19;
    }
    iVar20 = iVar20 - uVar14;
    uVar28 = 0;
    if (iVar20 != 0) {
      uVar35 = FUN_1006a324(iVar20,iVar21,iVar20,uVar10);
      uVar28 = (uint)uVar35;
    }
    if ((uVar4 == uVar30) || (local_78 == 1)) {
      iVar21 = (uint)uVar30 - (uint)uVar4;
    }
    else if (local_78 == 2) {
      iVar21 = (int)((uint)uVar30 - (uint)uVar4) >> 1;
    }
    else {
      iVar21 = (int)((uint)uVar30 - (uint)uVar4) / local_78;
    }
    local_34 = (uint)uVar30;
    uVar18 = (uint)uVar4;
    if ((local_5c == local_54) || (local_78 == 1)) {
      uVar17 = (local_30 & 0xffff) - (uVar8 & 0xffff);
    }
    else if (local_78 == 2) {
      uVar17 = (int)((local_30 & 0xffff) - (uVar8 & 0xffff)) >> 1;
    }
    else {
      uVar17 = (int)((local_30 & 0xffff) - (uVar8 & 0xffff)) / local_78;
    }
    local_30 = local_30 & 0xffff;
    uVar32 = uVar8 & 0xffff;
    DAT_1008d2d0 = (iVar21 << 0x10 | uVar17 & 0xffff) + (uVar17 & 0x8000) * -2;
    if ((uVar4 == uVar5) || (iVar19 == 1)) {
      iVar21 = uVar5 - uVar18;
    }
    else if (iVar19 == 2) {
      iVar21 = (int)(uVar5 - uVar18) >> 1;
    }
    else {
      iVar21 = (int)(uVar5 - uVar18) / iVar19;
    }
    local_38 = (uint)uVar5;
    DAT_1008d2d4 = iVar21 - (DAT_1008d2d0 >> 0x10);
    if (DAT_1008d2d4 != 0) {
      DAT_1008d2d4 = (int)(DAT_1008d2d4 * 0x10000) / (int)uVar10 << 0x10;
    }
    if ((local_5c == local_24) || (iVar19 == 1)) {
      iVar21 = (uVar15 & 0xffff) - uVar32;
    }
    else if (iVar19 == 2) {
      iVar21 = (int)((uVar15 & 0xffff) - uVar32) >> 1;
    }
    else {
      iVar21 = (int)((uVar15 & 0xffff) - uVar32) / iVar19;
    }
    uVar15 = uVar15 & 0xffff;
    if (iVar21 - (short)DAT_1008d2d0 != 0) {
      uVar18 = DAT_1008d2d4 | ((iVar21 - (short)DAT_1008d2d0) * 0x10000) / (int)uVar10 & 0xffffU;
      DAT_1008d2d4 = uVar18 + (uVar18 & 0x8000) * -2;
    }
    if ((uVar3 == uVar7) || (local_78 == 1)) {
      iVar21 = (uint)uVar3 - (uint)uVar7;
    }
    else if (local_78 == 2) {
      iVar21 = (int)((uint)uVar3 - (uint)uVar7) >> 1;
    }
    else {
      iVar21 = (int)((uint)uVar3 - (uint)uVar7) / local_78;
    }
    local_2c = (uint)uVar3;
    uVar18 = (uint)uVar7;
    if ((local_50 == local_58) || (local_78 == 1)) {
      local_28 = uVar12 & 0xffff | 0x100;
      local_3c = uVar9 & 0xffff | 0x100;
      uVar9 = local_28 - local_3c;
    }
    else if (local_78 == 2) {
      local_28 = uVar12 & 0xffff | 0x100;
      local_3c = uVar9 & 0xffff | 0x100;
      uVar9 = (int)(local_28 - local_3c) >> 1;
    }
    else {
      local_28 = uVar12 & 0xffff | 0x100;
      local_3c = uVar9 & 0xffff | 0x100;
      uVar9 = (int)(local_28 - local_3c) / local_78;
    }
    DAT_1008d2dc = (iVar21 << 0x10 | uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    if ((uVar6 == uVar7) || (iVar19 == 1)) {
      iVar21 = uVar6 - uVar18;
    }
    else if (iVar19 == 2) {
      iVar21 = (int)(uVar6 - uVar18) >> 1;
    }
    else {
      iVar21 = (int)(uVar6 - uVar18) / iVar19;
    }
    local_70 = (uint)uVar6;
    DAT_1008d2e0 = iVar21 - (DAT_1008d2dc >> 0x10);
    if (DAT_1008d2e0 != 0) {
      DAT_1008d2e0 = (int)(DAT_1008d2e0 * 0x10000) / (int)uVar10 << 0x10;
    }
    if ((local_20 == local_58) || (iVar19 == 1)) {
      iVar21 = (uVar16 & 0xffff | 0x100) - local_3c;
    }
    else if (iVar19 == 2) {
      iVar21 = (int)((uVar16 & 0xffff | 0x100) - local_3c) >> 1;
    }
    else {
      iVar21 = (int)((uVar16 & 0xffff | 0x100) - local_3c) / iVar19;
    }
    uVar9 = uVar16 & 0xffff | 0x100;
    if (iVar21 - (short)DAT_1008d2dc != 0) {
      uVar10 = DAT_1008d2e0 | ((iVar21 - (short)DAT_1008d2dc) * 0x10000) / (int)uVar10 & 0xffffU;
      DAT_1008d2e0 = uVar10 + (uVar10 & 0x8000) * -2;
    }
    DAT_1008d280 = DAT_1008d280 << 0x10;
    DAT_1008d284 = DAT_1008d280;
    if (iVar19 <= local_78) {
      DAT_1008d2c0 = (uVar23 & 0xfffe) << 0xf | (uVar29 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar28 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar14 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
      local_78 = local_78 - iVar19;
      DAT_1008d290 = iVar19;
      DAT_1008d2cc = uVar8;
      DAT_1008d2d8 = uVar11;
      FUN_10078fc4();
      if (local_78 == 0) {
        return;
      }
      DAT_1008d284 = iVar27 << 0x10;
      iVar25 = iVar25 - iVar27;
      if (local_78 == 1) {
        DAT_1008d288 = iVar25 * 0x10000;
      }
      else if (local_78 == 2) {
        DAT_1008d288 = iVar25 * 0x8000;
      }
      else if (((local_78 < 0x20) && (-0x20 < iVar25)) && (iVar25 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar31 + (iVar25 * 0x20 + local_78) * 4);
      }
      else if (iVar25 < 0) {
        DAT_1008d288 = (iVar25 * 0x10000) / local_78;
      }
      else {
        DAT_1008d288 = (iVar25 * 0x10000) / local_78;
      }
      goto LAB_10015050;
    }
    DAT_1008d2c0 = (uVar23 & 0xfffe) << 0xf | (uVar29 & 0xfffe) >> 1;
    uVar29 = (uVar28 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar14 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
    iVar19 = iVar19 - local_78;
    DAT_1008d290 = local_78;
    DAT_1008d2c8 = uVar29;
    DAT_1008d2cc = uVar8;
    DAT_1008d2d8 = uVar11;
    FUN_10078fc4();
    iVar27 = iVar27 - iVar25;
    if (iVar19 == 1) {
      DAT_1008d28c = iVar27 * 0x10000;
    }
    else if (iVar19 == 2) {
      DAT_1008d28c = iVar27 * 0x8000;
    }
    else if (((iVar19 < 0x20) && (-0x20 < iVar27)) && (iVar27 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar31 + (iVar27 * 0x20 + iVar19) * 4);
    }
    else if (iVar27 < 0) {
      DAT_1008d28c = (iVar27 * 0x10000) / iVar19;
    }
    else {
      DAT_1008d28c = (iVar27 * 0x10000) / iVar19;
    }
    if ((uVar26 == uVar24) || (iVar19 == 1)) {
      uVar26 = uVar26 - uVar24;
    }
    else if (iVar19 == 2) {
      uVar26 = (int)(uVar26 - uVar24) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar24) / iVar19;
    }
    if ((uVar33 == uVar22) || (iVar19 == 1)) {
      uVar33 = uVar33 - uVar22;
    }
    else if (iVar19 == 2) {
      uVar33 = (int)(uVar33 - uVar22) >> 1;
    }
    else {
      uVar33 = (int)(uVar33 - uVar22) / iVar19;
    }
    if ((uVar5 == uVar30) || (iVar19 == 1)) {
      iVar27 = local_38 - local_34;
    }
    else if (iVar19 == 2) {
      iVar27 = (int)(local_38 - local_34) >> 1;
    }
    else {
      iVar27 = (int)(local_38 - local_34) / iVar19;
    }
    DAT_1008d2d0 = iVar27 << 0x10;
    if ((local_24 == local_54) || (iVar19 == 1)) {
      uVar15 = uVar15 - local_30;
    }
    else if (iVar19 == 2) {
      uVar15 = (int)(uVar15 - local_30) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - local_30) / iVar19;
    }
    if (uVar15 != 0) {
      DAT_1008d2d0 = (DAT_1008d2d0 | uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    }
    if ((uVar6 == uVar3) || (iVar19 == 1)) {
      iVar27 = local_70 - local_2c;
    }
    else if (iVar19 == 2) {
      iVar27 = (int)(local_70 - local_2c) >> 1;
    }
    else {
      iVar27 = (int)(local_70 - local_2c) / iVar19;
    }
    DAT_1008d2dc = iVar27 << 0x10;
    if ((local_20 == local_50) || (iVar19 == 1)) {
      uVar9 = uVar9 - local_28;
    }
    else if (iVar19 == 2) {
      uVar9 = (int)(uVar9 - local_28) >> 1;
    }
    else {
      uVar9 = (int)(uVar9 - local_28) / iVar19;
    }
    local_78 = iVar19;
    if (uVar9 != 0) {
      DAT_1008d2dc = (DAT_1008d2dc | uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    }
  }
  DAT_1008d280 = iVar25 << 0x10;
  DAT_1008d2c4 = (uVar33 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
  DAT_1008d2c8 = uVar29;
LAB_10015050:
  DAT_1008d290 = local_78;
  FUN_10078fc4();
  return;
}


