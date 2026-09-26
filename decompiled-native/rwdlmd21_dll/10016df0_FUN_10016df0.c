// 10016df0 FUN_10016df0 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10016df0(int *param_1,int param_2,int param_3,int param_4)

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
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  int iVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  ushort uVar33;
  undefined2 uVar34;
  uint uVar35;
  uint uVar36;
  longlong lVar37;
  undefined8 uVar38;
  uint local_7c;
  short local_64;
  short local_60;
  short local_5c;
  short local_58;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  short local_2c;
  short local_28;
  uint local_1c;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  iVar19 = param_3;
  iVar20 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar19 = param_2;
      param_2 = param_4;
      iVar20 = param_3;
    }
LAB_10016e3d:
    param_4 = iVar19;
    param_3 = param_2;
    param_2 = iVar20;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10016e3d;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  uVar23 = (int)sVar1 - DAT_1008d284;
  DAT_1008d280 = (uint)*(short *)(param_2 + 0x1a);
  uVar30 = *(uint *)(param_2 + 100);
  uVar31 = *(uint *)(param_2 + 0x68);
  uVar8 = (*(uint *)(param_2 + 0x58) & 0xffff0001 | 0x10001) << 8 |
          (*(uint *)(param_2 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_2 + 0x14) <= _DAT_10089dd0)) {
    uVar24 = 0;
  }
  else {
    lVar37 = __ftol();
    if ((int)lVar37 == 0) {
      uVar24 = 0x1e00;
      DAT_1008dbe0._4_4_ = 0;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar37) * 0x1e;
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
  uVar25 = (uint)*(short *)(param_3 + 0x1a);
  uVar11 = uVar10 | 0x100;
  uVar24 = *(uint *)(param_3 + 100);
  uVar22 = *(uint *)(param_3 + 0x68);
  local_38 = (*(uint *)(param_3 + 0x58) & 0xffff0001 | 0x10001) << 8 |
             (*(uint *)(param_3 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_3 + 0x14) <= _DAT_10089dd0)) {
    uVar26 = 0;
  }
  else {
    lVar37 = __ftol();
    if ((int)lVar37 == 0) {
      uVar26 = 0x1e00;
      DAT_1008dbe0._4_4_ = 0;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar37) * 0x1e;
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
  uVar27 = (uint)*(short *)(param_4 + 0x1a);
  uVar14 = uVar13 | 0x100;
  uVar26 = *(uint *)(param_4 + 100);
  uVar32 = *(uint *)(param_4 + 0x68);
  uVar15 = (*(uint *)(param_4 + 0x58) & 0xffff0001 | 0x10001) << 8 |
           (*(uint *)(param_4 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_4 + 0x14) <= _DAT_10089dd0)) {
    uVar28 = 0;
  }
  else {
    lVar37 = __ftol();
    if ((int)lVar37 == 0) {
      uVar28 = 0x1e00;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar37) * 0x1e;
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
  uVar17 = uVar16 | uVar28 << 0x10;
  uVar18 = uVar17 | 0x100;
  uVar28 = (DAT_10089ef8 << 5 | DAT_10089ef0) << 6 | DAT_10089de4;
  DAT_1008dbe0._0_4_ = uVar28 | uVar28 << 0x10;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  uVar28 = DAT_1008723c + 0x1000;
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(uint *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  local_64 = (short)uVar8;
  local_2c = (short)uVar15;
  local_60 = (short)uVar11;
  local_28 = (short)uVar18;
  local_5c = (short)local_38;
  local_58 = (short)uVar14;
  uVar36 = (int)uVar8 >> 0x10;
  uVar33 = (ushort)(uVar8 >> 0x10);
  uVar3 = (ushort)(uVar13 >> 0x10);
  uVar21 = (int)uVar15 >> 0x10;
  uVar18 = (int)uVar18 >> 0x10;
  uVar4 = (ushort)(local_38 >> 0x10);
  uVar5 = (ushort)(uVar15 >> 0x10);
  uVar6 = (ushort)(uVar17 >> 0x10);
  uVar13 = (int)uVar11 >> 0x10;
  uVar7 = (ushort)(uVar10 >> 0x10);
  DAT_1008dbe0._4_4_ = (uint)DAT_1008dbe0;
  if ((int)uVar23 < 1) {
    iVar19 = DAT_1008d280 - uVar25;
    if (iVar19 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return uVar25;
    }
    local_7c = -((int)sVar1 - (int)sVar2);
    if (local_7c == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return 0;
    }
    iVar20 = uVar27 - uVar25;
    if (local_7c == 1) {
      DAT_1008d28c = iVar20 * 0x10000;
    }
    else if (local_7c == 2) {
      DAT_1008d28c = iVar20 * 0x8000;
    }
    else if ((((int)local_7c < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
      DAT_1008d28c = *(int *)(uVar28 + (iVar20 * 0x20 + local_7c) * 4);
    }
    else if (iVar20 < 0) {
      DAT_1008d28c = (iVar20 * 0x10000) / (int)local_7c;
    }
    else {
      DAT_1008d28c = (iVar20 * 0x10000) / (int)local_7c;
    }
    iVar20 = uVar27 - DAT_1008d280;
    if (local_7c == 1) {
      DAT_1008d288 = iVar20 * 0x10000;
    }
    else if (local_7c == 2) {
      DAT_1008d288 = iVar20 * 0x8000;
    }
    else if ((((int)local_7c < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
      DAT_1008d288 = *(int *)(uVar28 + (iVar20 * 0x20 + local_7c) * 4);
    }
    else if (iVar20 < 0) {
      DAT_1008d288 = (iVar20 * 0x10000) / (int)local_7c;
    }
    else {
      DAT_1008d288 = (iVar20 * 0x10000) / (int)local_7c;
    }
    if ((uVar30 == uVar24) || (iVar19 == 1)) {
      uVar30 = uVar30 - uVar24;
    }
    else if (iVar19 == 2) {
      uVar30 = (int)(uVar30 - uVar24) >> 1;
    }
    else {
      uVar30 = (int)(uVar30 - uVar24) / iVar19;
    }
    if ((uVar26 == uVar24) || (local_7c == 1)) {
      uVar26 = uVar26 - uVar24;
    }
    else if (local_7c == 2) {
      uVar26 = (int)(uVar26 - uVar24) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar24) / (int)local_7c;
    }
    if ((uVar31 == uVar22) || (iVar19 == 1)) {
      uVar31 = uVar31 - uVar22;
    }
    else if (iVar19 == 2) {
      uVar31 = (int)(uVar31 - uVar22) >> 1;
    }
    else {
      uVar31 = (int)(uVar31 - uVar22) / iVar19;
    }
    if ((uVar32 == uVar22) || (local_7c == 1)) {
      uVar32 = uVar32 - uVar22;
    }
    else if (local_7c == 2) {
      uVar32 = (int)(uVar32 - uVar22) >> 1;
    }
    else {
      uVar32 = (int)(uVar32 - uVar22) / (int)local_7c;
    }
    if ((uVar4 == uVar33) || (iVar19 == 1)) {
      iVar20 = (uVar36 & 0xffff) - (uint)uVar4;
    }
    else if (iVar19 == 2) {
      iVar20 = (int)((uVar36 & 0xffff) - (uint)uVar4) >> 1;
    }
    else {
      iVar20 = (int)((uVar36 & 0xffff) - (uint)uVar4) / iVar19;
    }
    uVar23 = (uint)uVar4;
    if ((uVar5 == uVar4) || (local_7c == 1)) {
      iVar29 = (uVar21 & 0xffff) - uVar23;
    }
    else if (local_7c == 2) {
      iVar29 = (int)((uVar21 & 0xffff) - uVar23) >> 1;
    }
    else {
      iVar29 = (int)((uVar21 & 0xffff) - uVar23) / (int)local_7c;
    }
    uVar8 = uVar8 & 0xffff;
    if ((local_5c == local_64) || (iVar19 == 1)) {
      uVar8 = uVar8 - (local_38 & 0xffff);
    }
    else if (iVar19 == 2) {
      uVar8 = (int)(uVar8 - (local_38 & 0xffff)) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - (local_38 & 0xffff)) / iVar19;
    }
    uVar23 = local_38 & 0xffff;
    DAT_1008d2d4 = (iVar20 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    uVar15 = uVar15 & 0xffff;
    if ((local_2c == local_5c) || (local_7c == 1)) {
      uVar15 = uVar15 - uVar23;
    }
    else if (local_7c == 2) {
      uVar15 = (int)(uVar15 - uVar23) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar23) / (int)local_7c;
    }
    DAT_1008d2d0 = (iVar29 << 0x10 | uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    if ((uVar6 == uVar3) || (local_7c == 1)) {
      iVar20 = (uVar18 & 0xffff) - (uint)uVar3;
    }
    else if (local_7c == 2) {
      iVar20 = (int)((uVar18 & 0xffff) - (uint)uVar3) >> 1;
    }
    else {
      iVar20 = (int)((uVar18 & 0xffff) - (uint)uVar3) / (int)local_7c;
    }
    uVar8 = (uint)uVar3;
    if ((uVar3 == uVar7) || (iVar19 == 1)) {
      iVar29 = (uVar13 & 0xffff) - uVar8;
    }
    else if (iVar19 == 2) {
      iVar29 = (int)((uVar13 & 0xffff) - uVar8) >> 1;
    }
    else {
      iVar29 = (int)((uVar13 & 0xffff) - uVar8) / iVar19;
    }
    uVar8 = uVar9 & 0xffff | 0x100;
    if ((local_58 == local_60) || (iVar19 == 1)) {
      uVar8 = uVar8 - (uVar12 & 0xffff | 0x100);
    }
    else if (iVar19 == 2) {
      uVar8 = (int)(uVar8 - (uVar12 & 0xffff | 0x100)) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - (uVar12 & 0xffff | 0x100)) / iVar19;
    }
    uVar23 = uVar12 & 0xffff | 0x100;
    DAT_1008d2e0 = (iVar29 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    uVar8 = uVar16 & 0xffff | 0x100;
    if ((local_28 == local_58) || (local_7c == 1)) {
      uVar8 = uVar8 - uVar23;
    }
    else if (local_7c == 2) {
      uVar8 = (int)(uVar8 - uVar23) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - uVar23) / (int)local_7c;
    }
    DAT_1008d2dc = (iVar20 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    uVar28 = (uVar24 & 0xfffe) >> 1;
    DAT_1008d2c0 = (uVar22 & 0xfffe) << 0xf | uVar28;
    DAT_1008d2c8 = (uVar31 & 0xfffe) << 0xf | (uVar30 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar32 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
    uVar30 = DAT_1008d2c8;
    DAT_1008d2cc = local_38;
    DAT_1008d2d8 = uVar14;
  }
  else {
    iVar19 = uVar25 - DAT_1008d280;
    uVar10 = _DAT_1008d2a4;
    if (uVar23 == 1) {
      DAT_1008d28c = iVar19 * 0x10000;
    }
    else if (uVar23 == 2) {
      DAT_1008d28c = iVar19 * 0x8000;
    }
    else if ((((int)uVar23 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1008d28c = *(int *)(uVar28 + (iVar19 * 0x20 + uVar23) * 4);
      uVar10 = uVar28;
    }
    else if (iVar19 < 0) {
      DAT_1008d28c = (iVar19 * 0x10000) / (int)uVar23;
      uVar10 = (iVar19 * 0x10000) % (int)uVar23;
    }
    else {
      DAT_1008d28c = (iVar19 * 0x10000) / (int)uVar23;
      uVar10 = (iVar19 * 0x10000) % (int)uVar23;
    }
    iVar19 = (int)sVar2 - DAT_1008d284;
    if (0 < iVar19) {
      iVar20 = uVar27 - DAT_1008d280;
      if (iVar19 == 1) {
        DAT_1008d288 = iVar20 * 0x10000;
      }
      else if (iVar19 == 2) {
        DAT_1008d288 = iVar20 * 0x8000;
      }
      else if (((iVar19 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
        DAT_1008d288 = *(int *)(uVar28 + (iVar20 * 0x20 + iVar19) * 4);
        uVar10 = uVar28;
      }
      else if (iVar20 < 0) {
        DAT_1008d288 = (iVar20 * 0x10000) / iVar19;
        uVar10 = (iVar20 * 0x10000) % iVar19;
      }
      else {
        DAT_1008d288 = (iVar20 * 0x10000) / iVar19;
        uVar10 = (iVar20 * 0x10000) % iVar19;
      }
      uVar14 = DAT_1008d288 - DAT_1008d28c;
      if ((int)uVar14 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return uVar14;
      }
      if ((uVar30 == uVar24) || (uVar23 == 1)) {
        uVar17 = uVar24 - uVar30;
      }
      else if (uVar23 == 2) {
        uVar17 = (int)(uVar24 - uVar30) >> 1;
      }
      else {
        uVar17 = (int)(uVar24 - uVar30) / (int)uVar23;
        uVar10 = (int)(uVar24 - uVar30) % (int)uVar23;
      }
      if ((uVar31 == uVar22) || (uVar23 == 1)) {
        uVar21 = uVar22 - uVar31;
      }
      else if (uVar23 == 2) {
        uVar21 = (int)(uVar22 - uVar31) >> 1;
      }
      else {
        uVar21 = (int)(uVar22 - uVar31) / (int)uVar23;
        uVar10 = (int)(uVar22 - uVar31) % (int)uVar23;
      }
      if ((uVar30 == uVar26) || (iVar19 == 1)) {
        iVar20 = uVar26 - uVar30;
      }
      else if (iVar19 == 2) {
        iVar20 = (int)(uVar26 - uVar30) >> 1;
      }
      else {
        iVar20 = (int)(uVar26 - uVar30) / iVar19;
        uVar10 = (int)(uVar26 - uVar30) % iVar19;
      }
      iVar20 = iVar20 - uVar17;
      uVar38 = CONCAT44(uVar10,iVar20);
      if (iVar20 != 0) {
        uVar38 = FUN_1006a324(iVar20,uVar10,iVar20,uVar14);
      }
      iVar20 = (int)((ulonglong)uVar38 >> 0x20);
      local_1c = (uint)uVar38;
      if ((uVar31 == uVar32) || (iVar19 == 1)) {
        iVar29 = uVar32 - uVar31;
      }
      else if (iVar19 == 2) {
        iVar29 = (int)(uVar32 - uVar31) >> 1;
      }
      else {
        iVar29 = (int)(uVar32 - uVar31) / iVar19;
        iVar20 = (int)(uVar32 - uVar31) % iVar19;
      }
      iVar29 = iVar29 - uVar21;
      uVar10 = 0;
      if (iVar29 != 0) {
        uVar38 = FUN_1006a324(iVar29,iVar20,iVar29,uVar14);
        uVar10 = (uint)uVar38;
      }
      if ((uVar4 == uVar33) || (uVar23 == 1)) {
        iVar20 = (uint)uVar4 - (uVar36 & 0xffff);
      }
      else if (uVar23 == 2) {
        iVar20 = (int)((uint)uVar4 - (uVar36 & 0xffff)) >> 1;
      }
      else {
        iVar20 = (int)((uint)uVar4 - (uVar36 & 0xffff)) / (int)uVar23;
      }
      local_3c = (uint)uVar4;
      uVar36 = uVar36 & 0xffff;
      if ((local_5c == local_64) || (uVar23 == 1)) {
        uVar18 = (local_38 & 0xffff) - (uVar8 & 0xffff);
      }
      else if (uVar23 == 2) {
        uVar18 = (int)((local_38 & 0xffff) - (uVar8 & 0xffff)) >> 1;
      }
      else {
        uVar18 = (int)((local_38 & 0xffff) - (uVar8 & 0xffff)) / (int)uVar23;
      }
      local_38 = local_38 & 0xffff;
      uVar35 = uVar8 & 0xffff;
      DAT_1008d2d0 = (iVar20 << 0x10 | uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
      if ((uVar5 == uVar33) || (iVar19 == 1)) {
        iVar20 = uVar5 - uVar36;
      }
      else if (iVar19 == 2) {
        iVar20 = (int)(uVar5 - uVar36) >> 1;
      }
      else {
        iVar20 = (int)(uVar5 - uVar36) / iVar19;
      }
      local_40 = (uint)uVar5;
      DAT_1008d2d4 = iVar20 - (DAT_1008d2d0 >> 0x10);
      if (DAT_1008d2d4 != 0) {
        DAT_1008d2d4 = (int)(DAT_1008d2d4 * 0x10000) / (int)uVar14 << 0x10;
      }
      if ((local_2c == local_64) || (iVar19 == 1)) {
        iVar20 = (uVar15 & 0xffff) - uVar35;
      }
      else if (iVar19 == 2) {
        iVar20 = (int)((uVar15 & 0xffff) - uVar35) >> 1;
      }
      else {
        iVar20 = (int)((uVar15 & 0xffff) - uVar35) / iVar19;
      }
      uVar15 = uVar15 & 0xffff;
      if (iVar20 - (short)DAT_1008d2d0 != 0) {
        uVar18 = DAT_1008d2d4 | ((iVar20 - (short)DAT_1008d2d0) * 0x10000) / (int)uVar14 & 0xffffU;
        DAT_1008d2d4 = uVar18 + (uVar18 & 0x8000) * -2;
      }
      if ((uVar3 == uVar7) || (uVar23 == 1)) {
        iVar20 = (uint)uVar3 - (uVar13 & 0xffff);
      }
      else if (uVar23 == 2) {
        iVar20 = (int)((uint)uVar3 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        iVar20 = (int)((uint)uVar3 - (uVar13 & 0xffff)) / (int)uVar23;
      }
      local_34 = (uint)uVar3;
      uVar13 = uVar13 & 0xffff;
      if ((local_58 == local_60) || (uVar23 == 1)) {
        local_30 = uVar12 & 0xffff | 0x100;
        local_44 = uVar9 & 0xffff | 0x100;
        uVar9 = local_30 - local_44;
      }
      else if (uVar23 == 2) {
        local_30 = uVar12 & 0xffff | 0x100;
        local_44 = uVar9 & 0xffff | 0x100;
        uVar9 = (int)(local_30 - local_44) >> 1;
      }
      else {
        local_30 = uVar12 & 0xffff | 0x100;
        local_44 = uVar9 & 0xffff | 0x100;
        uVar9 = (int)(local_30 - local_44) / (int)uVar23;
      }
      DAT_1008d2dc = (iVar20 << 0x10 | uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      if ((uVar6 == uVar7) || (iVar19 == 1)) {
        iVar20 = uVar6 - uVar13;
      }
      else if (iVar19 == 2) {
        iVar20 = (int)(uVar6 - uVar13) >> 1;
      }
      else {
        iVar20 = (int)(uVar6 - uVar13) / iVar19;
      }
      uVar9 = (uint)uVar6;
      DAT_1008d2e0 = iVar20 - (DAT_1008d2dc >> 0x10);
      if (DAT_1008d2e0 != 0) {
        DAT_1008d2e0 = (int)(DAT_1008d2e0 * 0x10000) / (int)uVar14 << 0x10;
      }
      if ((local_28 == local_60) || (iVar19 == 1)) {
        iVar20 = (uVar16 & 0xffff | 0x100) - local_44;
      }
      else if (iVar19 == 2) {
        iVar20 = (int)((uVar16 & 0xffff | 0x100) - local_44) >> 1;
      }
      else {
        iVar20 = (int)((uVar16 & 0xffff | 0x100) - local_44) / iVar19;
      }
      uVar12 = uVar16 & 0xffff | 0x100;
      if (iVar20 - (short)DAT_1008d2dc != 0) {
        uVar13 = DAT_1008d2e0 | ((iVar20 - (short)DAT_1008d2dc) * 0x10000) / (int)uVar14 & 0xffffU;
        DAT_1008d2e0 = uVar13 + (uVar13 & 0x8000) * -2;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if ((int)uVar23 < iVar19) {
        DAT_1008d2c0 = (uVar31 & 0xfffe) << 0xf | (uVar30 & 0xfffe) >> 1;
        uVar30 = (uVar10 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
        uVar31 = (uVar17 & 0xfffe) >> 1;
        DAT_1008d2c4 = (uVar21 & 0xfffe) << 0xf | uVar31;
        local_7c = iVar19 - uVar23;
        DAT_1008d290 = uVar23;
        DAT_1008d2c8 = uVar30;
        DAT_1008d2cc = uVar8;
        DAT_1008d2d8 = uVar11;
        FUN_10079ac0(uVar31,uVar23);
        DAT_1008d280 = uVar25 << 0x10;
        iVar19 = uVar27 - uVar25;
        if (local_7c == 1) {
          DAT_1008d28c = iVar19 * 0x10000;
        }
        else if (local_7c == 2) {
          DAT_1008d28c = iVar19 * 0x8000;
        }
        else if ((((int)local_7c < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
          DAT_1008d28c = *(int *)(uVar28 + (iVar19 * 0x20 + local_7c) * 4);
        }
        else if (iVar19 < 0) {
          DAT_1008d28c = (iVar19 * 0x10000) / (int)local_7c;
        }
        else {
          DAT_1008d28c = (iVar19 * 0x10000) / (int)local_7c;
        }
        if ((uVar26 == uVar24) || (local_7c == 1)) {
          uVar26 = uVar26 - uVar24;
        }
        else if (local_7c == 2) {
          uVar26 = (int)(uVar26 - uVar24) >> 1;
        }
        else {
          uVar26 = (int)(uVar26 - uVar24) / (int)local_7c;
        }
        if ((uVar32 == uVar22) || (local_7c == 1)) {
          uVar32 = uVar32 - uVar22;
        }
        else if (local_7c == 2) {
          uVar32 = (int)(uVar32 - uVar22) >> 1;
        }
        else {
          uVar32 = (int)(uVar32 - uVar22) / (int)local_7c;
        }
        if ((uVar5 == uVar4) || (local_7c == 1)) {
          iVar19 = local_40 - local_3c;
        }
        else if (local_7c == 2) {
          iVar19 = (int)(local_40 - local_3c) >> 1;
        }
        else {
          iVar19 = (int)(local_40 - local_3c) / (int)local_7c;
          local_3c = (int)(local_40 - local_3c) % (int)local_7c;
        }
        uVar31 = CONCAT22((short)(local_3c >> 0x10),local_5c);
        if ((local_2c == local_5c) || (local_7c == 1)) {
          uVar8 = uVar15 - local_38;
        }
        else if (local_7c == 2) {
          uVar8 = (int)(uVar15 - local_38) >> 1;
        }
        else {
          uVar8 = (int)(uVar15 - local_38) / (int)local_7c;
          uVar31 = (int)(uVar15 - local_38) % (int)local_7c;
        }
        DAT_1008d2d0 = iVar19 << 0x10;
        if (uVar8 != 0) {
          uVar31 = (iVar19 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
          DAT_1008d2d0 = uVar31;
        }
        uVar34 = (undefined2)(uVar31 >> 0x10);
        if ((uVar6 == uVar3) || (local_7c == 1)) {
          DAT_1008d2dc = uVar9 - local_34;
        }
        else if (local_7c == 2) {
          DAT_1008d2dc = (int)(uVar9 - local_34) >> 1;
        }
        else {
          DAT_1008d2dc = (int)(uVar9 - local_34) / (int)local_7c;
          uVar34 = (undefined2)((uint)((int)(uVar9 - local_34) % (int)local_7c) >> 0x10);
        }
        uVar28 = CONCAT22(uVar34,local_28);
        DAT_1008d2dc = DAT_1008d2dc << 0x10;
        if ((local_28 == local_58) || (local_7c == 1)) {
          uVar31 = uVar12 - local_30;
        }
        else if (local_7c == 2) {
          uVar31 = (int)(uVar12 - local_30) >> 1;
        }
        else {
          uVar31 = (int)(uVar12 - local_30) / (int)local_7c;
          uVar28 = (int)(uVar12 - local_30) % (int)local_7c;
        }
        if (uVar31 != 0) {
          uVar28 = (DAT_1008d2dc | uVar31 & 0xffff) + (uVar31 & 0x8000) * -2;
          DAT_1008d2dc = uVar28;
        }
        DAT_1008d2c4 = (uVar32 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
        uVar27 = DAT_1008d2c4;
        DAT_1008d2c8 = uVar30;
      }
      else {
        DAT_1008d2c0 = (uVar31 & 0xfffe) << 0xf | (uVar30 & 0xfffe) >> 1;
        DAT_1008d2c8 = (uVar10 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
        DAT_1008d2c4 = (uVar21 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
        local_7c = uVar23 - iVar19;
        DAT_1008d290 = iVar19;
        DAT_1008d2cc = uVar8;
        DAT_1008d2d8 = uVar11;
        uVar38 = FUN_10079ac0(DAT_1008d2c4,iVar19);
        if (local_7c == 0) {
          return (uint)uVar38;
        }
        DAT_1008d284 = uVar27 << 0x10;
        iVar19 = uVar25 - uVar27;
        if (local_7c == 1) {
          DAT_1008d288 = iVar19 * 0x10000;
          uVar28 = local_7c;
        }
        else if (local_7c == 2) {
          DAT_1008d288 = iVar19 * 0x8000;
          uVar28 = local_7c;
        }
        else if ((((int)local_7c < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
          DAT_1008d288 = *(int *)(uVar28 + (iVar19 * 0x20 + local_7c) * 4);
          uVar27 = local_7c;
        }
        else if (iVar19 < 0) {
          DAT_1008d288 = (iVar19 * 0x10000) / (int)local_7c;
          uVar28 = (iVar19 * 0x10000) % (int)local_7c;
        }
        else {
          DAT_1008d288 = (iVar19 * 0x10000) / (int)local_7c;
          uVar28 = (iVar19 * 0x10000) % (int)local_7c;
        }
      }
      goto LAB_10018879;
    }
    iVar19 = uVar27 - DAT_1008d280;
    if (iVar19 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return DAT_1008d280;
    }
    iVar20 = uVar25 - uVar27;
    if (uVar23 == 1) {
      DAT_1008d288 = iVar20 * 0x10000;
    }
    else if (uVar23 == 2) {
      DAT_1008d288 = iVar20 * 0x8000;
    }
    else if ((((int)uVar23 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
      DAT_1008d288 = *(int *)(uVar28 + (iVar20 * 0x20 + uVar23) * 4);
    }
    else if (iVar20 < 0) {
      DAT_1008d288 = (iVar20 * 0x10000) / (int)uVar23;
    }
    else {
      DAT_1008d288 = (iVar20 * 0x10000) / (int)uVar23;
    }
    if ((uVar30 == uVar26) || (iVar19 == 1)) {
      uVar26 = uVar26 - uVar30;
    }
    else if (iVar19 == 2) {
      uVar26 = (int)(uVar26 - uVar30) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar30) / iVar19;
    }
    if ((uVar31 == uVar32) || (iVar19 == 1)) {
      uVar32 = uVar32 - uVar31;
    }
    else if (iVar19 == 2) {
      uVar32 = (int)(uVar32 - uVar31) >> 1;
    }
    else {
      uVar32 = (int)(uVar32 - uVar31) / iVar19;
    }
    if ((uVar30 == uVar24) || (uVar23 == 1)) {
      uVar24 = uVar24 - uVar30;
    }
    else if (uVar23 == 2) {
      uVar24 = (int)(uVar24 - uVar30) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar30) / (int)uVar23;
    }
    if ((uVar31 == uVar22) || (uVar23 == 1)) {
      uVar22 = uVar22 - uVar31;
    }
    else if (uVar23 == 2) {
      uVar22 = (int)(uVar22 - uVar31) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar31) / (int)uVar23;
    }
    if ((uVar5 == uVar33) || (iVar19 == 1)) {
      iVar20 = (uVar21 & 0xffff) - (uint)uVar33;
    }
    else if (iVar19 == 2) {
      iVar20 = (int)((uVar21 & 0xffff) - (uint)uVar33) >> 1;
    }
    else {
      iVar20 = (int)((uVar21 & 0xffff) - (uint)uVar33) / iVar19;
    }
    uVar25 = (uint)uVar33;
    uVar15 = uVar15 & 0xffff;
    if ((local_2c == local_64) || (iVar19 == 1)) {
      uVar15 = uVar15 - (uVar8 & 0xffff);
    }
    else if (iVar19 == 2) {
      uVar15 = (int)(uVar15 - (uVar8 & 0xffff)) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - (uVar8 & 0xffff)) / iVar19;
    }
    uVar14 = uVar8 & 0xffff;
    DAT_1008d2d4 = (iVar20 << 0x10 | uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    uVar10 = (int)local_38 >> 0x10;
    if ((uVar4 == uVar33) || (uVar23 == 1)) {
      iVar20 = (uVar10 & 0xffff) - uVar25;
    }
    else if (uVar23 == 2) {
      iVar20 = (int)((uVar10 & 0xffff) - uVar25) >> 1;
    }
    else {
      iVar20 = (int)((uVar10 & 0xffff) - uVar25) / (int)uVar23;
    }
    local_38 = local_38 & 0xffff;
    if ((local_5c == local_64) || (uVar23 == 1)) {
      local_38 = local_38 - uVar14;
    }
    else if (uVar23 == 2) {
      local_38 = (int)(local_38 - uVar14) >> 1;
    }
    else {
      local_38 = (int)(local_38 - uVar14) / (int)uVar23;
    }
    DAT_1008d2d0 = (iVar20 << 0x10 | local_38 & 0xffff) + (local_38 & 0x8000) * -2;
    if ((uVar6 == uVar7) || (iVar19 == 1)) {
      iVar20 = (uVar18 & 0xffff) - (uVar13 & 0xffff);
    }
    else if (iVar19 == 2) {
      iVar20 = (int)((uVar18 & 0xffff) - (uVar13 & 0xffff)) >> 1;
    }
    else {
      iVar20 = (int)((uVar18 & 0xffff) - (uVar13 & 0xffff)) / iVar19;
    }
    uVar25 = uVar16 & 0xffff | 0x100;
    if ((local_28 == local_60) || (iVar19 == 1)) {
      uVar25 = uVar25 - (uVar9 & 0xffff | 0x100);
    }
    else if (iVar19 == 2) {
      uVar25 = (int)(uVar25 - (uVar9 & 0xffff | 0x100)) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - (uVar9 & 0xffff | 0x100)) / iVar19;
    }
    uVar9 = uVar9 & 0xffff | 0x100;
    DAT_1008d2e0 = (iVar20 << 0x10 | uVar25 & 0xffff) + (uVar25 & 0x8000) * -2;
    uVar25 = uVar12 & 0xffff | 0x100;
    if ((local_58 == local_60) || (uVar23 == 1)) {
      uVar25 = uVar25 - uVar9;
    }
    else if (uVar23 == 2) {
      uVar25 = (int)(uVar25 - uVar9) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - uVar9) / (int)uVar23;
    }
    DAT_1008d2dc = (uVar25 & 0xffff) + (uVar25 & 0x8000) * -2;
    uVar28 = (uVar31 & 0xfffe) << 0xf | (uVar30 & 0xfffe) >> 1;
    DAT_1008d2c8 = (uVar32 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
    uVar30 = (uVar24 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar22 & 0xfffe) << 0xf | uVar30;
    DAT_1008d2c0 = uVar28;
    DAT_1008d2cc = uVar8;
    DAT_1008d2d8 = uVar11;
    local_7c = uVar23;
    uVar25 = DAT_1008d280;
    DAT_1008d280 = uVar27;
  }
  uVar27 = uVar30;
  DAT_1008d284 = DAT_1008d280 << 0x10;
  DAT_1008d280 = uVar25 << 0x10;
LAB_10018879:
  DAT_1008d290 = local_7c;
  uVar38 = FUN_10079ac0(uVar27,uVar28);
  return (uint)uVar38;
}


