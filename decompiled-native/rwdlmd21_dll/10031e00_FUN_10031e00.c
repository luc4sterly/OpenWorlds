// 10031e00 FUN_10031e00 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10031e00(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  ushort uVar6;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  int iVar29;
  uint uVar30;
  short sVar31;
  uint uVar32;
  ushort uVar33;
  longlong lVar34;
  int local_5c;
  short local_44;
  short local_40;
  short local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  short local_28;
  short local_24;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  
  iVar11 = param_3;
  iVar19 = param_4;
  iVar28 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar11 = param_2;
      iVar19 = param_3;
      iVar28 = param_4;
    }
LAB_10031e46:
    param_4 = iVar11;
    param_2 = iVar19;
    param_3 = iVar28;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10031e46;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar11 = (int)sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar32 = (*(uint *)(param_2 + 0x58) & 0xffff0001 | 0x10001) << 8 |
           (*(uint *)(param_2 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_2 + 0x14) <= _DAT_10089dd0)) {
    uVar12 = 0;
  }
  else {
    lVar34 = __ftol();
    if ((int)lVar34 == 0) {
      uVar12 = 0x1e00;
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
        uVar12 = 0;
        DAT_1008dbe0._4_4_ = 0;
      }
      else {
        uVar12 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  iVar28 = (int)*(short *)(param_3 + 0x1a);
  uVar20 = (*(uint *)(param_2 + 0x60) & 0xfffe00ff) >> 8;
  uVar12 = uVar20 | uVar12 << 0x10;
  iVar19 = *(int *)(param_2 + 0x20);
  uVar21 = uVar12 | 0x100;
  local_34 = (*(uint *)(param_3 + 0x58) & 0xffff0001 | 0x10001) << 8 |
             (*(uint *)(param_3 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_3 + 0x14) <= _DAT_10089dd0)) {
    uVar13 = 0;
  }
  else {
    lVar34 = __ftol();
    if ((int)lVar34 == 0) {
      uVar13 = 0x1e00;
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
        uVar13 = 0;
        DAT_1008dbe0._4_4_ = 0;
      }
      else {
        uVar13 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  iVar29 = (int)*(short *)(param_4 + 0x1a);
  uVar22 = (*(uint *)(param_3 + 0x60) & 0xfffe00ff) >> 8;
  uVar23 = uVar22 | uVar13 << 0x10;
  iVar3 = *(int *)(param_3 + 0x20);
  uVar24 = uVar23 | 0x100;
  uVar13 = (*(uint *)(param_4 + 0x58) & 0xffff0001 | 0x10001) << 8 |
           (*(uint *)(param_4 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_4 + 0x14) <= _DAT_10089dd0)) {
    uVar14 = 0;
  }
  else {
    lVar34 = __ftol();
    if ((int)lVar34 == 0) {
      uVar14 = 0x1e00;
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
        uVar14 = 0;
      }
      else {
        uVar14 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  DAT_1008d330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  uVar25 = (*(uint *)(param_4 + 0x60) & 0xfffe00ff) >> 8;
  uVar26 = uVar25 | uVar14 << 0x10;
  iVar4 = *(int *)(param_4 + 0x20);
  uVar27 = uVar26 | 0x100;
  DAT_1008d334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d470 = (float)*(int *)(param_2 + 100) * _DAT_10086110 * DAT_1008d330;
  DAT_1008d474 = (float)*(int *)(param_2 + 0x68) * _DAT_10086110 * DAT_1008d330;
  DAT_1008d478 = (float)*(int *)(param_3 + 100) * _DAT_10086110 * DAT_1008d334;
  DAT_1008d47c = (float)*(int *)(param_3 + 0x68) * _DAT_10086110 * DAT_1008d334;
  DAT_1008d480 = (float)*(int *)(param_4 + 100) * _DAT_10086110 * DAT_1008d338;
  uVar14 = (DAT_10089ef8 << 5 | DAT_10089ef0) << 6 | DAT_10089de4;
  DAT_1008d484 = (float)*(int *)(param_4 + 0x68) * _DAT_10086110 * DAT_1008d338;
  DAT_1008dbe0._0_4_ = uVar14 | uVar14 << 0x10;
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  iVar15 = DAT_1008723c + 0x1000;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  sVar31 = (short)uVar32;
  uVar30 = (int)uVar32 >> 0x10;
  uVar6 = (ushort)(uVar32 >> 0x10);
  local_40 = (short)local_34;
  local_28 = (short)uVar13;
  local_44 = (short)uVar21;
  local_3c = (short)uVar24;
  local_24 = (short)uVar27;
  uVar7 = (ushort)(uVar23 >> 0x10);
  uVar23 = (int)uVar13 >> 0x10;
  uVar14 = (int)local_34 >> 0x10;
  uVar27 = (int)uVar27 >> 0x10;
  uVar33 = (ushort)(local_34 >> 0x10);
  uVar8 = (ushort)(uVar13 >> 0x10);
  uVar9 = (ushort)(uVar26 >> 0x10);
  uVar26 = (int)uVar21 >> 0x10;
  uVar10 = (ushort)(uVar12 >> 0x10);
  DAT_1008dbe0._4_4_ = (uint)DAT_1008dbe0;
  if (iVar11 < 1) {
    iVar11 = DAT_1008d280 - iVar28;
    if (iVar11 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    local_5c = -((int)sVar1 - (int)sVar2);
    if (local_5c == 0) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    _DAT_1008d46c = _DAT_10086114 / (float)local_5c;
    _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d46c;
    _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d46c;
    _DAT_1008d454 = (DAT_1008d484 - DAT_1008d47c) * _DAT_1008d46c;
    _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
    _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
    _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d484 - DAT_1008d474);
    iVar16 = iVar29 - iVar28;
    if (local_5c == 1) {
      DAT_1008d28c = iVar16 * 0x10000;
    }
    else if (local_5c == 2) {
      DAT_1008d28c = iVar16 * 0x8000;
    }
    else if (((local_5c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar15 + (iVar16 * 0x20 + local_5c) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1008d28c = (iVar16 * 0x10000) / local_5c;
    }
    else {
      DAT_1008d28c = (iVar16 * 0x10000) / local_5c;
    }
    iVar29 = iVar29 - DAT_1008d280;
    if (local_5c == 1) {
      DAT_1008d288 = iVar29 * 0x10000;
    }
    else if (local_5c == 2) {
      DAT_1008d288 = iVar29 * 0x8000;
    }
    else if (((local_5c < 0x20) && (-0x20 < iVar29)) && (iVar29 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar15 + (iVar29 * 0x20 + local_5c) * 4);
    }
    else if (iVar29 < 0) {
      DAT_1008d288 = (iVar29 * 0x10000) / local_5c;
    }
    else {
      DAT_1008d288 = (iVar29 * 0x10000) / local_5c;
    }
    if ((iVar19 == iVar3) || (iVar11 == 1)) {
      DAT_1008d2ec = iVar19 - iVar3;
    }
    else if (iVar11 == 2) {
      DAT_1008d2ec = iVar19 - iVar3 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar19 - iVar3) / iVar11;
    }
    if ((iVar4 == iVar3) || (local_5c == 1)) {
      DAT_1008d2e8 = iVar4 - iVar3;
    }
    else if (local_5c == 2) {
      DAT_1008d2e8 = iVar4 - iVar3 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar4 - iVar3) / local_5c;
    }
    if ((uVar33 == uVar6) || (iVar11 == 1)) {
      iVar19 = (uVar30 & 0xffff) - (uVar14 & 0xffff);
    }
    else if (iVar11 == 2) {
      iVar19 = (int)((uVar30 & 0xffff) - (uVar14 & 0xffff)) >> 1;
    }
    else {
      iVar19 = (int)((uVar30 & 0xffff) - (uVar14 & 0xffff)) / iVar11;
    }
    uVar14 = uVar14 & 0xffff;
    if ((uVar8 == uVar33) || (local_5c == 1)) {
      iVar29 = (uVar23 & 0xffff) - uVar14;
    }
    else if (local_5c == 2) {
      iVar29 = (int)((uVar23 & 0xffff) - uVar14) >> 1;
    }
    else {
      iVar29 = (int)((uVar23 & 0xffff) - uVar14) / local_5c;
    }
    DAT_1008d2d0 = iVar29 << 0x10;
    uVar32 = uVar32 & 0xffff;
    if ((local_40 == sVar31) || (iVar11 == 1)) {
      uVar32 = uVar32 - (local_34 & 0xffff);
    }
    else if (iVar11 == 2) {
      uVar32 = (int)(uVar32 - (local_34 & 0xffff)) >> 1;
    }
    else {
      uVar32 = (int)(uVar32 - (local_34 & 0xffff)) / iVar11;
    }
    uVar12 = local_34 & 0xffff;
    DAT_1008d2d4 = (iVar19 << 0x10 | uVar32 & 0xffff) + (uVar32 & 0x8000) * -2;
    uVar13 = uVar13 & 0xffff;
    if ((local_28 == local_40) || (local_5c == 1)) {
      uVar13 = uVar13 - uVar12;
    }
    else if (local_5c == 2) {
      uVar13 = (int)(uVar13 - uVar12) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - uVar12) / local_5c;
    }
    uVar32 = (int)uVar24 >> 0x10;
    DAT_1008d2d0 = (DAT_1008d2d0 | uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
    if ((uVar9 == uVar7) || (local_5c == 1)) {
      iVar19 = (uVar27 & 0xffff) - (uVar32 & 0xffff);
    }
    else if (local_5c == 2) {
      iVar19 = (int)((uVar27 & 0xffff) - (uVar32 & 0xffff)) >> 1;
    }
    else {
      iVar19 = (int)((uVar27 & 0xffff) - (uVar32 & 0xffff)) / local_5c;
    }
    uVar32 = uVar32 & 0xffff;
    if ((uVar10 == uVar7) || (iVar11 == 1)) {
      iVar29 = (uVar26 & 0xffff) - uVar32;
    }
    else if (iVar11 == 2) {
      iVar29 = (int)((uVar26 & 0xffff) - uVar32) >> 1;
    }
    else {
      iVar29 = (int)((uVar26 & 0xffff) - uVar32) / iVar11;
    }
    DAT_1008d2e0 = iVar29 << 0x10;
    uVar32 = uVar20 & 0xffff | 0x100;
    if ((local_3c == local_44) || (iVar11 == 1)) {
      uVar32 = uVar32 - (uVar22 & 0xffff | 0x100);
    }
    else if (iVar11 == 2) {
      uVar32 = (int)(uVar32 - (uVar22 & 0xffff | 0x100)) >> 1;
    }
    else {
      uVar32 = (int)(uVar32 - (uVar22 & 0xffff | 0x100)) / iVar11;
    }
    uVar12 = uVar22 & 0xffff | 0x100;
    DAT_1008d2e0 = (DAT_1008d2e0 | uVar32 & 0xffff) + (uVar32 & 0x8000) * -2;
    uVar32 = uVar25 & 0xffff | 0x100;
    if ((local_24 == local_3c) || (local_5c == 1)) {
      uVar32 = uVar32 - uVar12;
    }
    else if (local_5c == 2) {
      uVar32 = (int)(uVar32 - uVar12) >> 1;
    }
    else {
      uVar32 = (int)(uVar32 - uVar12) / local_5c;
    }
    DAT_1008d2dc = (iVar19 << 0x10 | uVar32 & 0xffff) + (uVar32 & 0x8000) * -2;
    DAT_1008d2cc = local_34;
    DAT_1008d2d8 = uVar24;
    _DAT_1008d440 = DAT_1008d334;
    _DAT_1008d448 = DAT_1008d478;
    _DAT_1008d450 = DAT_1008d47c;
    _DAT_1008d458 = DAT_1008d330;
    _DAT_1008d460 = DAT_1008d470;
    _DAT_1008d468 = DAT_1008d474;
  }
  else {
    iVar16 = iVar28 - DAT_1008d280;
    if (iVar11 == 1) {
      DAT_1008d28c = iVar16 * 0x10000;
    }
    else if (iVar11 == 2) {
      DAT_1008d28c = iVar16 * 0x8000;
    }
    else if (((iVar11 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar15 + (iVar16 * 0x20 + iVar11) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1008d28c = (iVar16 * 0x10000) / iVar11;
    }
    else {
      DAT_1008d28c = (iVar16 * 0x10000) / iVar11;
    }
    fVar5 = _DAT_10086114 / (float)iVar11;
    _DAT_1008d444 = (DAT_1008d334 - DAT_1008d330) * fVar5;
    _DAT_1008d44c = (DAT_1008d478 - DAT_1008d470) * fVar5;
    _DAT_1008d454 = (DAT_1008d47c - DAT_1008d474) * fVar5;
    iVar16 = (int)sVar2 - DAT_1008d284;
    _DAT_1008d440 = DAT_1008d330;
    _DAT_1008d448 = DAT_1008d470;
    _DAT_1008d450 = DAT_1008d474;
    if (0 < iVar16) {
      iVar17 = iVar29 - DAT_1008d280;
      if (iVar16 == 1) {
        DAT_1008d288 = iVar17 * 0x10000;
      }
      else if (iVar16 == 2) {
        DAT_1008d288 = iVar17 * 0x8000;
      }
      else if (((iVar16 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar15 + (iVar17 * 0x20 + iVar16) * 4);
      }
      else if (iVar17 < 0) {
        DAT_1008d288 = (iVar17 * 0x10000) / iVar16;
      }
      else {
        DAT_1008d288 = (iVar17 * 0x10000) / iVar16;
      }
      iVar17 = DAT_1008d288 - DAT_1008d28c;
      if (iVar17 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d2a0 = DAT_10089ef4;
        return;
      }
      _DAT_1008d46c = _DAT_10086114 / (float)iVar16;
      _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
      _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
      _DAT_1008d46c = (DAT_1008d484 - DAT_1008d474) * _DAT_1008d46c;
      DAT_1008d2c0 = 0;
      DAT_1008d2c4 = 0;
      DAT_1008d2c8 = 0;
      if ((uVar33 == uVar6) || (iVar11 == 1)) {
        iVar18 = (uint)uVar33 - (uVar30 & 0xffff);
      }
      else if (iVar11 == 2) {
        iVar18 = (int)((uint)uVar33 - (uVar30 & 0xffff)) >> 1;
      }
      else {
        iVar18 = (int)((uint)uVar33 - (uVar30 & 0xffff)) / iVar11;
      }
      local_38 = (uint)uVar33;
      uVar30 = uVar30 & 0xffff;
      if ((local_40 == sVar31) || (iVar11 == 1)) {
        uVar12 = (local_34 & 0xffff) - (uVar32 & 0xffff);
      }
      else if (iVar11 == 2) {
        uVar12 = (int)((local_34 & 0xffff) - (uVar32 & 0xffff)) >> 1;
      }
      else {
        uVar12 = (int)((local_34 & 0xffff) - (uVar32 & 0xffff)) / iVar11;
      }
      local_34 = local_34 & 0xffff;
      uVar23 = uVar32 & 0xffff;
      DAT_1008d2d0 = (iVar18 << 0x10 | uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
      if ((uVar8 == uVar6) || (iVar16 == 1)) {
        iVar18 = uVar8 - uVar30;
      }
      else if (iVar16 == 2) {
        iVar18 = (int)(uVar8 - uVar30) >> 1;
      }
      else {
        iVar18 = (int)(uVar8 - uVar30) / iVar16;
      }
      uVar12 = (uint)uVar8;
      DAT_1008d2d4 = iVar18 - (DAT_1008d2d0 >> 0x10);
      if (DAT_1008d2d4 != 0) {
        DAT_1008d2d4 = (int)(DAT_1008d2d4 * 0x10000) / iVar17 << 0x10;
      }
      if ((local_28 == sVar31) || (iVar16 == 1)) {
        iVar18 = (uVar13 & 0xffff) - uVar23;
      }
      else if (iVar16 == 2) {
        iVar18 = (int)((uVar13 & 0xffff) - uVar23) >> 1;
      }
      else {
        iVar18 = (int)((uVar13 & 0xffff) - uVar23) / iVar16;
      }
      uVar13 = uVar13 & 0xffff;
      if (iVar18 - (short)DAT_1008d2d0 != 0) {
        uVar23 = DAT_1008d2d4 | ((iVar18 - (short)DAT_1008d2d0) * 0x10000) / iVar17 & 0xffffU;
        DAT_1008d2d4 = uVar23 + (uVar23 & 0x8000) * -2;
      }
      if ((uVar10 == uVar7) || (iVar11 == 1)) {
        iVar18 = (uint)uVar7 - (uVar26 & 0xffff);
      }
      else if (iVar11 == 2) {
        iVar18 = (int)((uint)uVar7 - (uVar26 & 0xffff)) >> 1;
      }
      else {
        iVar18 = (int)((uint)uVar7 - (uVar26 & 0xffff)) / iVar11;
      }
      local_30 = (uint)uVar7;
      uVar26 = uVar26 & 0xffff;
      if ((local_3c == local_44) || (iVar11 == 1)) {
        local_2c = uVar22 & 0xffff | 0x100;
        uVar22 = local_2c - (uVar20 & 0xffff | 0x100);
      }
      else if (iVar11 == 2) {
        local_2c = uVar22 & 0xffff | 0x100;
        uVar22 = (int)(local_2c - (uVar20 & 0xffff | 0x100)) >> 1;
      }
      else {
        local_2c = uVar22 & 0xffff | 0x100;
        uVar22 = (int)(local_2c - (uVar20 & 0xffff | 0x100)) / iVar11;
      }
      uVar20 = uVar20 & 0xffff | 0x100;
      DAT_1008d2dc = (iVar18 << 0x10 | uVar22 & 0xffff) + (uVar22 & 0x8000) * -2;
      if ((uVar10 == uVar9) || (iVar16 == 1)) {
        iVar18 = uVar9 - uVar26;
      }
      else if (iVar16 == 2) {
        iVar18 = (int)(uVar9 - uVar26) >> 1;
      }
      else {
        iVar18 = (int)(uVar9 - uVar26) / iVar16;
      }
      uVar22 = (uint)uVar9;
      DAT_1008d2e0 = iVar18 - (DAT_1008d2dc >> 0x10);
      if (DAT_1008d2e0 != 0) {
        DAT_1008d2e0 = (int)(DAT_1008d2e0 * 0x10000) / iVar17 << 0x10;
      }
      if ((local_24 == local_44) || (iVar16 == 1)) {
        iVar18 = (uVar25 & 0xffff | 0x100) - uVar20;
      }
      else if (iVar16 == 2) {
        iVar18 = (int)((uVar25 & 0xffff | 0x100) - uVar20) >> 1;
      }
      else {
        iVar18 = (int)((uVar25 & 0xffff | 0x100) - uVar20) / iVar16;
      }
      uVar20 = uVar25 & 0xffff | 0x100;
      if (iVar18 - (short)DAT_1008d2dc != 0) {
        uVar23 = DAT_1008d2e0 | ((iVar18 - (short)DAT_1008d2dc) * 0x10000) / iVar17 & 0xffffU;
        DAT_1008d2e0 = uVar23 + (uVar23 & 0x8000) * -2;
      }
      if ((iVar3 == iVar19) || (iVar11 == 1)) {
        DAT_1008d2e8 = iVar3 - iVar19;
      }
      else if (iVar11 == 2) {
        DAT_1008d2e8 = iVar3 - iVar19 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar3 - iVar19) / iVar11;
      }
      if ((iVar4 == iVar19) || (iVar16 == 1)) {
        iVar18 = iVar4 - iVar19;
      }
      else if (iVar16 == 2) {
        iVar18 = iVar4 - iVar19 >> 1;
      }
      else {
        iVar18 = (iVar4 - iVar19) / iVar16;
      }
      DAT_1008d2ec = iVar18 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && (iVar17 >> 6 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / (iVar17 >> 6) << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar11 < iVar16) {
        local_5c = iVar16 - iVar11;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar19;
        DAT_1008d290 = iVar11;
        DAT_1008d2cc = uVar32;
        DAT_1008d2d8 = uVar21;
        _DAT_1008d458 = DAT_1008d330;
        _DAT_1008d460 = DAT_1008d470;
        _DAT_1008d468 = DAT_1008d474;
        FUN_1007ed90();
        _DAT_1008d454 = _DAT_10086114 / (float)local_5c;
        _DAT_1008d448 = DAT_1008d478;
        _DAT_1008d440 = DAT_1008d334;
        _DAT_1008d450 = DAT_1008d47c;
        _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d454;
        _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d454;
        _DAT_1008d454 = _DAT_1008d454 * (DAT_1008d484 - DAT_1008d47c);
        DAT_1008d280 = iVar28 << 0x10;
        iVar29 = iVar29 - iVar28;
        if (local_5c == 1) {
          DAT_1008d28c = iVar29 * 0x10000;
        }
        else if (local_5c == 2) {
          DAT_1008d28c = iVar29 * 0x8000;
        }
        else if (((local_5c < 0x20) && (-0x20 < iVar29)) && (iVar29 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar15 + (iVar29 * 0x20 + local_5c) * 4);
        }
        else if (iVar29 < 0) {
          DAT_1008d28c = (iVar29 * 0x10000) / local_5c;
        }
        else {
          DAT_1008d28c = (iVar29 * 0x10000) / local_5c;
        }
        DAT_1008d2c4 = 0;
        if ((uVar8 == uVar33) || (local_5c == 1)) {
          DAT_1008d2d0 = uVar12 - local_38;
        }
        else if (local_5c == 2) {
          DAT_1008d2d0 = (int)(uVar12 - local_38) >> 1;
        }
        else {
          DAT_1008d2d0 = (int)(uVar12 - local_38) / local_5c;
        }
        DAT_1008d2d0 = DAT_1008d2d0 << 0x10;
        if ((local_28 == local_40) || (local_5c == 1)) {
          uVar13 = uVar13 - local_34;
        }
        else if (local_5c == 2) {
          uVar13 = (int)(uVar13 - local_34) >> 1;
        }
        else {
          uVar13 = (int)(uVar13 - local_34) / local_5c;
        }
        if (uVar13 != 0) {
          DAT_1008d2d0 = (DAT_1008d2d0 | uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
        }
        if ((uVar9 == uVar7) || (local_5c == 1)) {
          DAT_1008d2dc = uVar22 - local_30;
        }
        else if (local_5c == 2) {
          DAT_1008d2dc = (int)(uVar22 - local_30) >> 1;
        }
        else {
          DAT_1008d2dc = (int)(uVar22 - local_30) / local_5c;
        }
        DAT_1008d2dc = DAT_1008d2dc << 0x10;
        if ((local_24 == local_3c) || (local_5c == 1)) {
          uVar20 = uVar20 - local_2c;
        }
        else if (local_5c == 2) {
          uVar20 = (int)(uVar20 - local_2c) >> 1;
        }
        else {
          uVar20 = (int)(uVar20 - local_2c) / local_5c;
        }
        if (uVar20 != 0) {
          DAT_1008d2dc = (DAT_1008d2dc | uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
        }
        if (iVar4 == iVar3) {
          DAT_1008d2e8 = iVar4 - iVar3;
        }
        else if (local_5c == 1) {
          DAT_1008d2e8 = iVar4 - iVar3;
        }
        else if (local_5c == 2) {
          DAT_1008d2e8 = iVar4 - iVar3 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar4 - iVar3) / local_5c;
        }
      }
      else {
        local_5c = iVar11 - iVar16;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar19;
        DAT_1008d290 = iVar16;
        DAT_1008d2cc = uVar32;
        DAT_1008d2d8 = uVar21;
        _DAT_1008d458 = DAT_1008d330;
        _DAT_1008d460 = DAT_1008d470;
        _DAT_1008d468 = DAT_1008d474;
        FUN_1007ed90();
        if (local_5c == 0) {
          return;
        }
        _DAT_1008d46c = _DAT_10086114 / (float)local_5c;
        _DAT_1008d458 = DAT_1008d338;
        _DAT_1008d460 = DAT_1008d480;
        _DAT_1008d468 = DAT_1008d484;
        _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * _DAT_1008d46c;
        _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * _DAT_1008d46c;
        _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d47c - DAT_1008d484);
        DAT_1008d284 = iVar29 << 0x10;
        iVar28 = iVar28 - iVar29;
        if (local_5c == 1) {
          DAT_1008d288 = iVar28 * 0x10000;
        }
        else if (local_5c == 2) {
          DAT_1008d288 = iVar28 * 0x8000;
        }
        else if (((local_5c < 0x20) && (-0x20 < iVar28)) && (iVar28 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar15 + (iVar28 * 0x20 + local_5c) * 4);
        }
        else if (iVar28 < 0) {
          DAT_1008d288 = (iVar28 * 0x10000) / local_5c;
        }
        else {
          DAT_1008d288 = (iVar28 * 0x10000) / local_5c;
        }
      }
      goto LAB_1003395d;
    }
    iVar16 = iVar29 - DAT_1008d280;
    if (iVar16 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar28 = iVar28 - iVar29;
    if (iVar11 == 1) {
      DAT_1008d288 = iVar28 * 0x10000;
    }
    else if (iVar11 == 2) {
      DAT_1008d288 = iVar28 * 0x8000;
    }
    else if (((iVar11 < 0x20) && (-0x20 < iVar28)) && (iVar28 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar15 + (iVar28 * 0x20 + iVar11) * 4);
    }
    else if (iVar28 < 0) {
      DAT_1008d288 = (iVar28 * 0x10000) / iVar11;
    }
    else {
      DAT_1008d288 = (iVar28 * 0x10000) / iVar11;
    }
    _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * fVar5;
    _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * fVar5;
    _DAT_1008d46c = (DAT_1008d47c - DAT_1008d484) * fVar5;
    if ((iVar4 == iVar19) || (iVar16 == 1)) {
      DAT_1008d2ec = iVar4 - iVar19;
    }
    else if (iVar16 == 2) {
      DAT_1008d2ec = iVar4 - iVar19 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar4 - iVar19) / iVar16;
    }
    if ((iVar3 == iVar19) || (iVar11 == 1)) {
      DAT_1008d2e8 = iVar3 - iVar19;
    }
    else if (iVar11 == 2) {
      DAT_1008d2e8 = iVar3 - iVar19 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar3 - iVar19) / iVar11;
    }
    if ((uVar8 == uVar6) || (iVar16 == 1)) {
      iVar28 = (uVar23 & 0xffff) - (uVar30 & 0xffff);
    }
    else if (iVar16 == 2) {
      iVar28 = (int)((uVar23 & 0xffff) - (uVar30 & 0xffff)) >> 1;
    }
    else {
      iVar28 = (int)((uVar23 & 0xffff) - (uVar30 & 0xffff)) / iVar16;
    }
    uVar30 = uVar30 & 0xffff;
    uVar13 = uVar13 & 0xffff;
    if ((local_28 == sVar31) || (iVar16 == 1)) {
      uVar13 = uVar13 - (uVar32 & 0xffff);
    }
    else if (iVar16 == 2) {
      uVar13 = (int)(uVar13 - (uVar32 & 0xffff)) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - (uVar32 & 0xffff)) / iVar16;
    }
    uVar12 = uVar32 & 0xffff;
    DAT_1008d2d4 = (iVar28 << 0x10 | uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
    if ((uVar33 == uVar6) || (iVar11 == 1)) {
      iVar28 = (uVar14 & 0xffff) - uVar30;
    }
    else if (iVar11 == 2) {
      iVar28 = (int)((uVar14 & 0xffff) - uVar30) >> 1;
    }
    else {
      iVar28 = (int)((uVar14 & 0xffff) - uVar30) / iVar11;
    }
    local_34 = local_34 & 0xffff;
    if ((local_40 == sVar31) || (iVar11 == 1)) {
      local_34 = local_34 - uVar12;
    }
    else if (iVar11 == 2) {
      local_34 = (int)(local_34 - uVar12) >> 1;
    }
    else {
      local_34 = (int)(local_34 - uVar12) / iVar11;
    }
    DAT_1008d2d0 = (iVar28 << 0x10 | local_34 & 0xffff) + (local_34 & 0x8000) * -2;
    if ((uVar10 == uVar9) || (iVar16 == 1)) {
      iVar28 = (uVar27 & 0xffff) - (uVar26 & 0xffff);
    }
    else if (iVar16 == 2) {
      iVar28 = (int)((uVar27 & 0xffff) - (uVar26 & 0xffff)) >> 1;
    }
    else {
      iVar28 = (int)((uVar27 & 0xffff) - (uVar26 & 0xffff)) / iVar16;
    }
    DAT_1008d2e0 = iVar28 << 0x10;
    uVar12 = uVar25 & 0xffff | 0x100;
    if ((local_24 == local_44) || (iVar16 == 1)) {
      uVar12 = uVar12 - (uVar20 & 0xffff | 0x100);
    }
    else if (iVar16 == 2) {
      uVar12 = (int)(uVar12 - (uVar20 & 0xffff | 0x100)) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - (uVar20 & 0xffff | 0x100)) / iVar16;
    }
    uVar20 = uVar20 & 0xffff | 0x100;
    DAT_1008d2e0 = (DAT_1008d2e0 | uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
    uVar12 = uVar22 & 0xffff | 0x100;
    if ((local_3c == local_44) || (iVar11 == 1)) {
      uVar12 = uVar12 - uVar20;
    }
    else if (iVar11 == 2) {
      uVar12 = (int)(uVar12 - uVar20) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar20) / iVar11;
    }
    DAT_1008d2dc = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
    DAT_1008d2cc = uVar32;
    DAT_1008d2d8 = uVar21;
    _DAT_1008d458 = DAT_1008d338;
    _DAT_1008d460 = DAT_1008d480;
    _DAT_1008d468 = DAT_1008d484;
    local_5c = iVar11;
    iVar3 = iVar19;
    iVar28 = DAT_1008d280;
    DAT_1008d280 = iVar29;
  }
  DAT_1008d284 = DAT_1008d280 << 0x10;
  DAT_1008d280 = iVar28 << 0x10;
  DAT_1008d2c8 = 0;
  DAT_1008d2c4 = 0;
  DAT_1008d2c0 = 0;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar3;
LAB_1003395d:
  DAT_1008d290 = local_5c;
  FUN_1007ed90();
  return;
}


