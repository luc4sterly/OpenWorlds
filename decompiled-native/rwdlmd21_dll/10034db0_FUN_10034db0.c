// 10034db0 FUN_10034db0 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10034db0(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  float fVar3;
  ushort uVar4;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  ushort uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  short sVar28;
  uint uVar29;
  longlong lVar30;
  int local_50;
  short local_44;
  short local_40;
  short local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  short local_28;
  short local_24;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  iVar10 = param_3;
  iVar12 = param_4;
  iVar14 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar10 = param_2;
      iVar12 = param_3;
      iVar14 = param_4;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_10034df6;
  param_2 = iVar12;
  param_3 = iVar14;
  param_4 = iVar10;
LAB_10034df6:
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  local_50 = (int)sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar29 = (*(uint *)(param_2 + 0x58) & 0xffff0001 | 0x10001) << 8 |
           (*(uint *)(param_2 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_2 + 0x14) <= _DAT_10089dd0)) {
    uVar9 = 0;
  }
  else {
    lVar30 = __ftol();
    if ((int)lVar30 == 0) {
      uVar9 = 0x1e00;
      DAT_1008dbe0._4_4_ = 0;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar30) * 0x1e;
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
        uVar9 = 0;
        DAT_1008dbe0._4_4_ = 0;
      }
      else {
        uVar9 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  uVar19 = (*(uint *)(param_2 + 0x60) & 0xfffe00ff) >> 8;
  uVar9 = uVar19 | uVar9 << 0x10;
  iVar10 = (int)*(short *)(param_3 + 0x1a);
  uVar20 = uVar9 | 0x100;
  local_34 = (*(uint *)(param_3 + 0x58) & 0xffff0001 | 0x10001) << 8 |
             (*(uint *)(param_3 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_3 + 0x14) <= _DAT_10089dd0)) {
    uVar11 = 0;
  }
  else {
    lVar30 = __ftol();
    if ((int)lVar30 == 0) {
      uVar11 = 0x1e00;
      DAT_1008dbe0._4_4_ = 0;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar30) * 0x1e;
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
        uVar11 = 0;
        DAT_1008dbe0._4_4_ = 0;
      }
      else {
        uVar11 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  uVar21 = (*(uint *)(param_3 + 0x60) & 0xfffe00ff) >> 8;
  uVar22 = uVar21 | uVar11 << 0x10;
  iVar12 = (int)*(short *)(param_4 + 0x1a);
  uVar23 = uVar22 | 0x100;
  uVar11 = (*(uint *)(param_4 + 0x58) & 0xffff0001 | 0x10001) << 8 |
           (*(uint *)(param_4 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_4 + 0x14) <= _DAT_10089dd0)) {
    uVar13 = 0;
  }
  else {
    lVar30 = __ftol();
    if ((int)lVar30 == 0) {
      uVar13 = 0x1e00;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar30) * 0x1e;
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
        uVar13 = 0;
      }
      else {
        uVar13 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  DAT_1008d330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  uVar24 = (*(uint *)(param_4 + 0x60) & 0xfffe00ff) >> 8;
  uVar25 = uVar24 | uVar13 << 0x10;
  DAT_1008d334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  uVar26 = uVar25 | 0x100;
  DAT_1008d338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d470 = (float)*(int *)(param_2 + 100) * _DAT_10086110 * DAT_1008d330;
  DAT_1008d474 = (float)*(int *)(param_2 + 0x68) * _DAT_10086110 * DAT_1008d330;
  DAT_1008d478 = (float)*(int *)(param_3 + 100) * _DAT_10086110 * DAT_1008d334;
  DAT_1008d47c = (float)*(int *)(param_3 + 0x68) * _DAT_10086110 * DAT_1008d334;
  DAT_1008d480 = (float)*(int *)(param_4 + 100) * _DAT_10086110 * DAT_1008d338;
  uVar13 = (DAT_10089ef8 << 5 | DAT_10089ef0) << 6 | DAT_10089de4;
  DAT_1008dbe0._0_4_ = uVar13 | uVar13 << 0x10;
  DAT_1008d484 = (float)*(int *)(param_4 + 0x68) * _DAT_10086110 * DAT_1008d338;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar14 = DAT_1008723c + 0x1000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  sVar28 = (short)uVar29;
  uVar13 = (int)uVar29 >> 0x10;
  uVar4 = (ushort)(uVar29 >> 0x10);
  local_40 = (short)local_34;
  local_28 = (short)uVar11;
  local_44 = (short)uVar20;
  local_3c = (short)uVar23;
  local_24 = (short)uVar26;
  uVar5 = (ushort)(uVar22 >> 0x10);
  uVar22 = (int)uVar11 >> 0x10;
  uVar27 = (int)local_34 >> 0x10;
  uVar26 = (int)uVar26 >> 0x10;
  uVar18 = (ushort)(local_34 >> 0x10);
  uVar6 = (ushort)(uVar11 >> 0x10);
  uVar7 = (ushort)(uVar25 >> 0x10);
  uVar25 = (int)uVar20 >> 0x10;
  uVar8 = (ushort)(uVar9 >> 0x10);
  DAT_1008dbe0._4_4_ = (uint)DAT_1008dbe0;
  if (local_50 < 1) {
    iVar15 = DAT_1008d280 - iVar10;
    if (iVar15 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    local_50 = -((int)sVar1 - (int)sVar2);
    if (local_50 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    _DAT_1008d46c = _DAT_10086114 / (float)local_50;
    _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d46c;
    _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d46c;
    _DAT_1008d454 = (DAT_1008d484 - DAT_1008d47c) * _DAT_1008d46c;
    _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
    _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
    _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d484 - DAT_1008d474);
    iVar16 = iVar12 - iVar10;
    if (local_50 == 1) {
      DAT_1008d28c = iVar16 * 0x10000;
    }
    else if (local_50 == 2) {
      DAT_1008d28c = iVar16 * 0x8000;
    }
    else if (((local_50 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar14 + (iVar16 * 0x20 + local_50) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1008d28c = (iVar16 * 0x10000) / local_50;
    }
    else {
      DAT_1008d28c = (iVar16 * 0x10000) / local_50;
    }
    iVar12 = iVar12 - DAT_1008d280;
    if (local_50 == 1) {
      DAT_1008d288 = iVar12 * 0x10000;
    }
    else if (local_50 == 2) {
      DAT_1008d288 = iVar12 * 0x8000;
    }
    else if (((local_50 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar14 + (iVar12 * 0x20 + local_50) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1008d288 = (iVar12 * 0x10000) / local_50;
    }
    else {
      DAT_1008d288 = (iVar12 * 0x10000) / local_50;
    }
    if ((uVar18 == uVar4) || (iVar15 == 1)) {
      iVar12 = (uVar13 & 0xffff) - (uVar27 & 0xffff);
    }
    else if (iVar15 == 2) {
      iVar12 = (int)((uVar13 & 0xffff) - (uVar27 & 0xffff)) >> 1;
    }
    else {
      iVar12 = (int)((uVar13 & 0xffff) - (uVar27 & 0xffff)) / iVar15;
    }
    uVar27 = uVar27 & 0xffff;
    if ((uVar6 == uVar18) || (local_50 == 1)) {
      iVar14 = (uVar22 & 0xffff) - uVar27;
    }
    else if (local_50 == 2) {
      iVar14 = (int)((uVar22 & 0xffff) - uVar27) >> 1;
    }
    else {
      iVar14 = (int)((uVar22 & 0xffff) - uVar27) / local_50;
    }
    DAT_1008d2d0 = iVar14 << 0x10;
    uVar29 = uVar29 & 0xffff;
    if ((local_40 == sVar28) || (iVar15 == 1)) {
      uVar29 = uVar29 - (local_34 & 0xffff);
    }
    else if (iVar15 == 2) {
      uVar29 = (int)(uVar29 - (local_34 & 0xffff)) >> 1;
    }
    else {
      uVar29 = (int)(uVar29 - (local_34 & 0xffff)) / iVar15;
    }
    uVar9 = local_34 & 0xffff;
    DAT_1008d2d4 = (iVar12 << 0x10 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    uVar11 = uVar11 & 0xffff;
    if ((local_28 == local_40) || (local_50 == 1)) {
      uVar11 = uVar11 - uVar9;
    }
    else if (local_50 == 2) {
      uVar11 = (int)(uVar11 - uVar9) >> 1;
    }
    else {
      uVar11 = (int)(uVar11 - uVar9) / local_50;
    }
    DAT_1008d2d0 = (DAT_1008d2d0 | uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
    uVar29 = (int)uVar23 >> 0x10;
    if ((uVar7 == uVar5) || (local_50 == 1)) {
      iVar12 = (uVar26 & 0xffff) - (uVar29 & 0xffff);
    }
    else if (local_50 == 2) {
      iVar12 = (int)((uVar26 & 0xffff) - (uVar29 & 0xffff)) >> 1;
    }
    else {
      iVar12 = (int)((uVar26 & 0xffff) - (uVar29 & 0xffff)) / local_50;
    }
    uVar29 = uVar29 & 0xffff;
    if ((uVar5 == uVar8) || (iVar15 == 1)) {
      iVar14 = (uVar25 & 0xffff) - uVar29;
    }
    else if (iVar15 == 2) {
      iVar14 = (int)((uVar25 & 0xffff) - uVar29) >> 1;
    }
    else {
      iVar14 = (int)((uVar25 & 0xffff) - uVar29) / iVar15;
    }
    DAT_1008d2e0 = iVar14 << 0x10;
    uVar29 = uVar19 & 0xffff | 0x100;
    if ((local_3c == local_44) || (iVar15 == 1)) {
      uVar29 = uVar29 - (uVar21 & 0xffff | 0x100);
    }
    else if (iVar15 == 2) {
      uVar29 = (int)(uVar29 - (uVar21 & 0xffff | 0x100)) >> 1;
    }
    else {
      uVar29 = (int)(uVar29 - (uVar21 & 0xffff | 0x100)) / iVar15;
    }
    uVar9 = uVar21 & 0xffff | 0x100;
    DAT_1008d2e0 = (DAT_1008d2e0 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    uVar29 = uVar24 & 0xffff | 0x100;
    if ((local_24 == local_3c) || (local_50 == 1)) {
      uVar29 = uVar29 - uVar9;
    }
    else if (local_50 == 2) {
      uVar29 = (int)(uVar29 - uVar9) >> 1;
    }
    else {
      uVar29 = (int)(uVar29 - uVar9) / local_50;
    }
    DAT_1008d2dc = (iVar12 << 0x10 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d280 = iVar10 << 0x10;
    DAT_1008d2cc = local_34;
    DAT_1008d2d8 = uVar23;
    _DAT_1008d440 = DAT_1008d334;
    _DAT_1008d448 = DAT_1008d478;
    _DAT_1008d450 = DAT_1008d47c;
    _DAT_1008d458 = DAT_1008d330;
    _DAT_1008d460 = DAT_1008d470;
    _DAT_1008d468 = DAT_1008d474;
  }
  else {
    iVar15 = iVar10 - DAT_1008d280;
    if (local_50 == 1) {
      DAT_1008d28c = iVar15 * 0x10000;
    }
    else if (local_50 == 2) {
      DAT_1008d28c = iVar15 * 0x8000;
    }
    else if (((local_50 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar14 + (iVar15 * 0x20 + local_50) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1008d28c = (iVar15 * 0x10000) / local_50;
    }
    else {
      DAT_1008d28c = (iVar15 * 0x10000) / local_50;
    }
    fVar3 = _DAT_10086114 / (float)local_50;
    _DAT_1008d444 = (DAT_1008d334 - DAT_1008d330) * fVar3;
    _DAT_1008d44c = (DAT_1008d478 - DAT_1008d470) * fVar3;
    _DAT_1008d454 = (DAT_1008d47c - DAT_1008d474) * fVar3;
    iVar15 = (int)sVar2 - DAT_1008d284;
    _DAT_1008d440 = DAT_1008d330;
    _DAT_1008d448 = DAT_1008d470;
    _DAT_1008d450 = DAT_1008d474;
    if (iVar15 < 1) {
      iVar15 = iVar12 - DAT_1008d280;
      if (iVar15 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar10 = iVar10 - iVar12;
      if (local_50 == 1) {
        DAT_1008d288 = iVar10 * 0x10000;
      }
      else if (local_50 == 2) {
        DAT_1008d288 = iVar10 * 0x8000;
      }
      else if (((local_50 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar14 + (iVar10 * 0x20 + local_50) * 4);
      }
      else if (iVar10 < 0) {
        DAT_1008d288 = (iVar10 * 0x10000) / local_50;
      }
      else {
        DAT_1008d288 = (iVar10 * 0x10000) / local_50;
      }
      _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * fVar3;
      _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * fVar3;
      _DAT_1008d46c = (DAT_1008d47c - DAT_1008d484) * fVar3;
      if ((uVar6 == uVar4) || (iVar15 == 1)) {
        iVar10 = (uVar22 & 0xffff) - (uVar13 & 0xffff);
      }
      else if (iVar15 == 2) {
        iVar10 = (int)((uVar22 & 0xffff) - (uVar13 & 0xffff)) >> 1;
      }
      else {
        iVar10 = (int)((uVar22 & 0xffff) - (uVar13 & 0xffff)) / iVar15;
      }
      uVar13 = uVar13 & 0xffff;
      uVar11 = uVar11 & 0xffff;
      if ((local_28 == sVar28) || (iVar15 == 1)) {
        uVar11 = uVar11 - (uVar29 & 0xffff);
      }
      else if (iVar15 == 2) {
        uVar11 = (int)(uVar11 - (uVar29 & 0xffff)) >> 1;
      }
      else {
        uVar11 = (int)(uVar11 - (uVar29 & 0xffff)) / iVar15;
      }
      uVar9 = uVar29 & 0xffff;
      DAT_1008d2d4 = (iVar10 << 0x10 | uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      if ((uVar18 == uVar4) || (local_50 == 1)) {
        iVar10 = (uVar27 & 0xffff) - uVar13;
      }
      else if (local_50 == 2) {
        iVar10 = (int)((uVar27 & 0xffff) - uVar13) >> 1;
      }
      else {
        iVar10 = (int)((uVar27 & 0xffff) - uVar13) / local_50;
      }
      local_34 = local_34 & 0xffff;
      if ((local_40 == sVar28) || (local_50 == 1)) {
        local_34 = local_34 - uVar9;
      }
      else if (local_50 == 2) {
        local_34 = (int)(local_34 - uVar9) >> 1;
      }
      else {
        local_34 = (int)(local_34 - uVar9) / local_50;
      }
      DAT_1008d2d0 = (iVar10 << 0x10 | local_34 & 0xffff) + (local_34 & 0x8000) * -2;
      if ((uVar7 == uVar8) || (iVar15 == 1)) {
        iVar10 = (uVar26 & 0xffff) - (uVar25 & 0xffff);
      }
      else if (iVar15 == 2) {
        iVar10 = (int)((uVar26 & 0xffff) - (uVar25 & 0xffff)) >> 1;
      }
      else {
        iVar10 = (int)((uVar26 & 0xffff) - (uVar25 & 0xffff)) / iVar15;
      }
      DAT_1008d2e0 = iVar10 << 0x10;
      uVar9 = uVar24 & 0xffff | 0x100;
      if ((local_24 == local_44) || (iVar15 == 1)) {
        uVar9 = uVar9 - (uVar19 & 0xffff | 0x100);
      }
      else if (iVar15 == 2) {
        uVar9 = (int)(uVar9 - (uVar19 & 0xffff | 0x100)) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - (uVar19 & 0xffff | 0x100)) / iVar15;
      }
      uVar19 = uVar19 & 0xffff | 0x100;
      DAT_1008d2e0 = (DAT_1008d2e0 | uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      uVar9 = uVar21 & 0xffff | 0x100;
      if ((local_3c == local_44) || (local_50 == 1)) {
        uVar9 = uVar9 - uVar19;
      }
      else if (local_50 == 2) {
        uVar9 = (int)(uVar9 - uVar19) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - uVar19) / local_50;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d2dc = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      DAT_1008d284 = iVar12 << 0x10;
      DAT_1008d2cc = uVar29;
      DAT_1008d2d8 = uVar20;
      _DAT_1008d458 = DAT_1008d338;
      _DAT_1008d460 = DAT_1008d480;
      _DAT_1008d468 = DAT_1008d484;
    }
    else {
      iVar16 = iVar12 - DAT_1008d280;
      if (iVar15 == 1) {
        DAT_1008d288 = iVar16 * 0x10000;
      }
      else if (iVar15 == 2) {
        DAT_1008d288 = iVar16 * 0x8000;
      }
      else if (((iVar15 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar14 + (iVar16 * 0x20 + iVar15) * 4);
      }
      else if (iVar16 < 0) {
        DAT_1008d288 = (iVar16 * 0x10000) / iVar15;
      }
      else {
        DAT_1008d288 = (iVar16 * 0x10000) / iVar15;
      }
      iVar16 = DAT_1008d288 - DAT_1008d28c;
      if (iVar16 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      _DAT_1008d46c = _DAT_10086114 / (float)iVar15;
      _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
      _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
      _DAT_1008d46c = (DAT_1008d484 - DAT_1008d474) * _DAT_1008d46c;
      if ((uVar18 == uVar4) || (local_50 == 1)) {
        iVar17 = (uint)uVar18 - (uVar13 & 0xffff);
      }
      else if (local_50 == 2) {
        iVar17 = (int)((uint)uVar18 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        iVar17 = (int)((uint)uVar18 - (uVar13 & 0xffff)) / local_50;
      }
      local_38 = (uint)uVar18;
      uVar13 = uVar13 & 0xffff;
      if ((local_40 == sVar28) || (local_50 == 1)) {
        uVar9 = (local_34 & 0xffff) - (uVar29 & 0xffff);
      }
      else if (local_50 == 2) {
        uVar9 = (int)((local_34 & 0xffff) - (uVar29 & 0xffff)) >> 1;
      }
      else {
        uVar9 = (int)((local_34 & 0xffff) - (uVar29 & 0xffff)) / local_50;
      }
      local_34 = local_34 & 0xffff;
      uVar22 = uVar29 & 0xffff;
      DAT_1008d2d0 = (iVar17 << 0x10 | uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      if ((uVar6 == uVar4) || (iVar15 == 1)) {
        iVar17 = uVar6 - uVar13;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)(uVar6 - uVar13) >> 1;
      }
      else {
        iVar17 = (int)(uVar6 - uVar13) / iVar15;
      }
      uVar9 = (uint)uVar6;
      DAT_1008d2d4 = iVar17 - (DAT_1008d2d0 >> 0x10);
      if (DAT_1008d2d4 != 0) {
        DAT_1008d2d4 = (int)(DAT_1008d2d4 * 0x10000) / iVar16 << 0x10;
      }
      if ((local_28 == sVar28) || (iVar15 == 1)) {
        iVar17 = (uVar11 & 0xffff) - uVar22;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)((uVar11 & 0xffff) - uVar22) >> 1;
      }
      else {
        iVar17 = (int)((uVar11 & 0xffff) - uVar22) / iVar15;
      }
      uVar11 = uVar11 & 0xffff;
      if (iVar17 - (short)DAT_1008d2d0 != 0) {
        uVar22 = DAT_1008d2d4 | ((iVar17 - (short)DAT_1008d2d0) * 0x10000) / iVar16 & 0xffffU;
        DAT_1008d2d4 = uVar22 + (uVar22 & 0x8000) * -2;
      }
      if ((uVar5 == uVar8) || (local_50 == 1)) {
        iVar17 = (uint)uVar5 - (uVar25 & 0xffff);
      }
      else if (local_50 == 2) {
        iVar17 = (int)((uint)uVar5 - (uVar25 & 0xffff)) >> 1;
      }
      else {
        iVar17 = (int)((uint)uVar5 - (uVar25 & 0xffff)) / local_50;
      }
      local_30 = (uint)uVar5;
      uVar25 = uVar25 & 0xffff;
      if ((local_3c == local_44) || (local_50 == 1)) {
        local_2c = uVar21 & 0xffff | 0x100;
        uVar21 = local_2c - (uVar19 & 0xffff | 0x100);
      }
      else if (local_50 == 2) {
        local_2c = uVar21 & 0xffff | 0x100;
        uVar21 = (int)(local_2c - (uVar19 & 0xffff | 0x100)) >> 1;
      }
      else {
        local_2c = uVar21 & 0xffff | 0x100;
        uVar21 = (int)(local_2c - (uVar19 & 0xffff | 0x100)) / local_50;
      }
      uVar19 = uVar19 & 0xffff | 0x100;
      DAT_1008d2dc = (iVar17 << 0x10 | uVar21 & 0xffff) + (uVar21 & 0x8000) * -2;
      if ((uVar7 == uVar8) || (iVar15 == 1)) {
        iVar17 = uVar7 - uVar25;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)(uVar7 - uVar25) >> 1;
      }
      else {
        iVar17 = (int)(uVar7 - uVar25) / iVar15;
      }
      uVar21 = (uint)uVar7;
      DAT_1008d2e0 = iVar17 - (DAT_1008d2dc >> 0x10);
      if (DAT_1008d2e0 != 0) {
        DAT_1008d2e0 = (int)(DAT_1008d2e0 * 0x10000) / iVar16 << 0x10;
      }
      if ((local_24 == local_44) || (iVar15 == 1)) {
        iVar17 = (uVar24 & 0xffff | 0x100) - uVar19;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)((uVar24 & 0xffff | 0x100) - uVar19) >> 1;
      }
      else {
        iVar17 = (int)((uVar24 & 0xffff | 0x100) - uVar19) / iVar15;
      }
      uVar19 = uVar24 & 0xffff | 0x100;
      if (iVar17 - (short)DAT_1008d2dc != 0) {
        uVar22 = DAT_1008d2e0 | ((iVar17 - (short)DAT_1008d2dc) * 0x10000) / iVar16 & 0xffffU;
        DAT_1008d2e0 = uVar22 + (uVar22 & 0x8000) * -2;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (local_50 < iVar15) {
        iVar15 = iVar15 - local_50;
        DAT_1008d290 = local_50;
        DAT_1008d2cc = uVar29;
        DAT_1008d2d8 = uVar20;
        _DAT_1008d458 = DAT_1008d330;
        _DAT_1008d460 = DAT_1008d470;
        _DAT_1008d468 = DAT_1008d474;
        FUN_1007f404();
        _DAT_1008d454 = _DAT_10086114 / (float)iVar15;
        _DAT_1008d448 = DAT_1008d478;
        _DAT_1008d440 = DAT_1008d334;
        _DAT_1008d450 = DAT_1008d47c;
        _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d454;
        _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d454;
        _DAT_1008d454 = _DAT_1008d454 * (DAT_1008d484 - DAT_1008d47c);
        DAT_1008d280 = iVar10 << 0x10;
        iVar12 = iVar12 - iVar10;
        if (iVar15 == 1) {
          DAT_1008d28c = iVar12 * 0x10000;
        }
        else if (iVar15 == 2) {
          DAT_1008d28c = iVar12 * 0x8000;
        }
        else if (((iVar15 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar14 + (iVar12 * 0x20 + iVar15) * 4);
        }
        else if (iVar12 < 0) {
          DAT_1008d28c = (iVar12 * 0x10000) / iVar15;
        }
        else {
          DAT_1008d28c = (iVar12 * 0x10000) / iVar15;
        }
        if ((uVar6 == uVar18) || (iVar15 == 1)) {
          DAT_1008d2d0 = uVar9 - local_38;
        }
        else if (iVar15 == 2) {
          DAT_1008d2d0 = (int)(uVar9 - local_38) >> 1;
        }
        else {
          DAT_1008d2d0 = (int)(uVar9 - local_38) / iVar15;
        }
        DAT_1008d2d0 = DAT_1008d2d0 << 0x10;
        if ((local_28 == local_40) || (iVar15 == 1)) {
          uVar11 = uVar11 - local_34;
        }
        else if (iVar15 == 2) {
          uVar11 = (int)(uVar11 - local_34) >> 1;
        }
        else {
          uVar11 = (int)(uVar11 - local_34) / iVar15;
        }
        if (uVar11 != 0) {
          DAT_1008d2d0 = (DAT_1008d2d0 | uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
        }
        if ((uVar7 == uVar5) || (iVar15 == 1)) {
          DAT_1008d2dc = uVar21 - local_30;
        }
        else if (iVar15 == 2) {
          DAT_1008d2dc = (int)(uVar21 - local_30) >> 1;
        }
        else {
          DAT_1008d2dc = (int)(uVar21 - local_30) / iVar15;
        }
        DAT_1008d2dc = DAT_1008d2dc << 0x10;
        if ((local_24 == local_3c) || (iVar15 == 1)) {
          uVar19 = uVar19 - local_2c;
        }
        else if (iVar15 == 2) {
          uVar19 = (int)(uVar19 - local_2c) >> 1;
        }
        else {
          uVar19 = (int)(uVar19 - local_2c) / iVar15;
        }
        local_50 = iVar15;
        if (uVar19 != 0) {
          DAT_1008d2dc = (DAT_1008d2dc | uVar19 & 0xffff) + (uVar19 & 0x8000) * -2;
        }
      }
      else {
        local_50 = local_50 - iVar15;
        DAT_1008d290 = iVar15;
        DAT_1008d2cc = uVar29;
        DAT_1008d2d8 = uVar20;
        _DAT_1008d458 = DAT_1008d330;
        _DAT_1008d460 = DAT_1008d470;
        _DAT_1008d468 = DAT_1008d474;
        FUN_1007f404();
        if (local_50 == 0) {
          return;
        }
        _DAT_1008d46c = _DAT_10086114 / (float)local_50;
        _DAT_1008d458 = DAT_1008d338;
        _DAT_1008d460 = DAT_1008d480;
        _DAT_1008d468 = DAT_1008d484;
        _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * _DAT_1008d46c;
        _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * _DAT_1008d46c;
        _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d47c - DAT_1008d484);
        DAT_1008d284 = iVar12 << 0x10;
        iVar10 = iVar10 - iVar12;
        if (local_50 == 1) {
          DAT_1008d288 = iVar10 * 0x10000;
        }
        else if (local_50 == 2) {
          DAT_1008d288 = iVar10 * 0x8000;
        }
        else if (((local_50 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar14 + (iVar10 * 0x20 + local_50) * 4);
        }
        else if (iVar10 < 0) {
          DAT_1008d288 = (iVar10 * 0x10000) / local_50;
        }
        else {
          DAT_1008d288 = (iVar10 * 0x10000) / local_50;
        }
      }
    }
  }
  DAT_1008d290 = local_50;
  FUN_1007f404();
  return;
}


