// 1005aa00 FUN_1005aa00 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1005aa00(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  ushort uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  short sVar15;
  uint uVar16;
  short sVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  ushort uVar23;
  int local_40;
  short local_34;
  uint local_30;
  uint local_2c;
  short local_28;
  short local_1c;
  short local_8;
  ushort uVar3;
  uint uVar10;
  
  iVar9 = param_3;
  iVar19 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar9 = param_2;
      param_2 = param_4;
      iVar19 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1005aa49;
  param_3 = param_2;
  param_4 = iVar9;
  param_2 = iVar19;
LAB_1005aa49:
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  local_40 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  iVar19 = (int)*(short *)(param_3 + 0x1a);
  uVar4 = *(int *)(param_2 + 0x5c) >> 8;
  uVar16 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | uVar4;
  uVar5 = *(int *)(param_2 + 0x60) >> 8;
  local_2c = *(int *)(param_3 + 0x5c) >> 8;
  uVar20 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | local_2c;
  uVar6 = *(int *)(param_3 + 0x60) >> 8;
  iVar21 = (int)*(short *)(param_4 + 0x1a);
  uVar22 = *(int *)(param_4 + 0x5c) >> 8;
  DAT_1007f330 = *(float *)(param_3 + 0x14) * *(float *)(param_4 + 0x14);
  uVar7 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar22;
  DAT_1007f334 = *(float *)(param_2 + 0x14) * *(float *)(param_4 + 0x14);
  uVar8 = *(int *)(param_4 + 0x60) >> 8;
  DAT_1007f338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007f470 = (float)*(int *)(param_2 + 100) * _DAT_10078118 * DAT_1007f330;
  DAT_1007f474 = (float)*(int *)(param_2 + 0x68) * _DAT_10078118 * DAT_1007f330;
  DAT_1007f478 = (float)*(int *)(param_3 + 100) * _DAT_10078118 * DAT_1007f334;
  DAT_1007f47c = (float)*(int *)(param_3 + 0x68) * _DAT_10078118 * DAT_1007f334;
  DAT_1007f480 = (float)*(int *)(param_4 + 100) * _DAT_10078118 * DAT_1007f338;
  DAT_1007f484 = (float)*(int *)(param_4 + 0x68) * _DAT_10078118 * DAT_1007f338;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  iVar9 = DAT_10079214 + 0x1000;
  _DAT_1007f2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  sVar15 = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  uVar18 = (int)uVar16 >> 0x10;
  uVar2 = (ushort)(uVar16 >> 0x10);
  local_34 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  local_28 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  local_1c = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  local_8 = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  uVar10 = (int)uVar7 >> 0x10;
  uVar14 = (int)uVar20 >> 0x10;
  uVar23 = (ushort)(uVar20 >> 0x10);
  uVar3 = (ushort)(uVar7 >> 0x10);
  sVar17 = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  if (local_40 < 1) {
    iVar11 = DAT_1007f280 - iVar19;
    if (iVar11 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    local_40 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_40 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    _DAT_1007f46c = _DAT_1007811c / (float)local_40;
    _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f46c;
    _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f46c;
    _DAT_1007f454 = (DAT_1007f484 - DAT_1007f47c) * _DAT_1007f46c;
    _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
    _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
    _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f484 - DAT_1007f474);
    iVar12 = iVar21 - iVar19;
    if (local_40 == 1) {
      DAT_1007f28c = iVar12 * 0x10000;
    }
    else if (local_40 == 2) {
      DAT_1007f28c = iVar12 * 0x8000;
    }
    else if (((local_40 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar9 + (iVar12 * 0x20 + local_40) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1007f28c = (iVar12 * 0x10000) / local_40;
    }
    else {
      DAT_1007f28c = (iVar12 * 0x10000) / local_40;
    }
    iVar21 = iVar21 - DAT_1007f280;
    if (local_40 == 1) {
      DAT_1007f288 = iVar21 * 0x10000;
    }
    else if (local_40 == 2) {
      DAT_1007f288 = iVar21 * 0x8000;
    }
    else if (((local_40 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar9 + (iVar21 * 0x20 + local_40) * 4);
    }
    else if (iVar21 < 0) {
      DAT_1007f288 = (iVar21 * 0x10000) / local_40;
    }
    else {
      DAT_1007f288 = (iVar21 * 0x10000) / local_40;
    }
    if ((uVar2 == uVar23) || (iVar11 == 1)) {
      iVar9 = (uVar18 & 0xffff) - (uVar14 & 0xffff);
    }
    else if (iVar11 == 2) {
      iVar9 = (int)((uVar18 & 0xffff) - (uVar14 & 0xffff)) >> 1;
    }
    else {
      iVar9 = (int)((uVar18 & 0xffff) - (uVar14 & 0xffff)) / iVar11;
    }
    uVar14 = uVar14 & 0xffff;
    if ((uVar3 == uVar23) || (local_40 == 1)) {
      iVar21 = (uVar10 & 0xffff) - uVar14;
    }
    else if (local_40 == 2) {
      iVar21 = (int)((uVar10 & 0xffff) - uVar14) >> 1;
    }
    else {
      iVar21 = (int)((uVar10 & 0xffff) - uVar14) / local_40;
    }
    uVar4 = uVar4 & 0xffff;
    if ((sVar15 == local_34) || (iVar11 == 1)) {
      uVar4 = uVar4 - (local_2c & 0xffff);
    }
    else if (iVar11 == 2) {
      uVar4 = (int)(uVar4 - (local_2c & 0xffff)) >> 1;
    }
    else {
      uVar4 = (int)(uVar4 - (local_2c & 0xffff)) / iVar11;
    }
    local_2c = local_2c & 0xffff;
    DAT_1007f2d4 = (iVar9 << 0x10 | uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
    uVar22 = uVar22 & 0xffff;
    if ((local_28 == local_34) || (local_40 == 1)) {
      uVar22 = uVar22 - local_2c;
    }
    else if (local_40 == 2) {
      uVar22 = (int)(uVar22 - local_2c) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - local_2c) / local_40;
    }
    DAT_1007f2d0 = (iVar21 << 0x10 | uVar22 & 0xffff) + (uVar22 & 0x8000) * -2;
    uVar5 = uVar5 & 0xffff;
    uVar4 = uVar6 & 0xffff;
    if ((sVar17 == local_8) || (iVar11 == 1)) {
      uVar5 = uVar5 - uVar4;
    }
    else if (iVar11 == 2) {
      uVar5 = (int)(uVar5 - uVar4) >> 1;
    }
    else {
      uVar5 = (int)(uVar5 - uVar4) / iVar11;
    }
    DAT_1007f2e0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    uVar8 = uVar8 & 0xffff;
    if ((local_1c == sVar17) || (local_40 == 1)) {
      uVar8 = uVar8 - uVar4;
    }
    else if (local_40 == 2) {
      uVar8 = (int)(uVar8 - uVar4) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - uVar4) / local_40;
    }
    DAT_1007f2dc = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    DAT_1007f284 = DAT_1007f280 << 0x10;
    DAT_1007f280 = iVar19 << 0x10;
    DAT_1007f2cc = uVar20;
    _DAT_1007f2d8 = uVar6;
    _DAT_1007f440 = DAT_1007f334;
    _DAT_1007f448 = DAT_1007f478;
    _DAT_1007f450 = DAT_1007f47c;
    _DAT_1007f458 = DAT_1007f330;
    _DAT_1007f460 = DAT_1007f470;
    _DAT_1007f468 = DAT_1007f474;
  }
  else {
    iVar11 = iVar19 - DAT_1007f280;
    if (local_40 == 1) {
      DAT_1007f28c = iVar11 * 0x10000;
    }
    else if (local_40 == 2) {
      DAT_1007f28c = iVar11 * 0x8000;
    }
    else if (((local_40 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar9 + (iVar11 * 0x20 + local_40) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1007f28c = (iVar11 * 0x10000) / local_40;
    }
    else {
      DAT_1007f28c = (iVar11 * 0x10000) / local_40;
    }
    fVar1 = _DAT_1007811c / (float)local_40;
    _DAT_1007f444 = (DAT_1007f334 - DAT_1007f330) * fVar1;
    _DAT_1007f44c = (DAT_1007f478 - DAT_1007f470) * fVar1;
    _DAT_1007f454 = (DAT_1007f47c - DAT_1007f474) * fVar1;
    iVar11 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    _DAT_1007f440 = DAT_1007f330;
    _DAT_1007f448 = DAT_1007f470;
    _DAT_1007f450 = DAT_1007f474;
    if (iVar11 < 1) {
      iVar11 = iVar21 - DAT_1007f280;
      if (iVar11 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar19 = iVar19 - iVar21;
      if (local_40 == 1) {
        DAT_1007f288 = iVar19 * 0x10000;
      }
      else if (local_40 == 2) {
        DAT_1007f288 = iVar19 * 0x8000;
      }
      else if (((local_40 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar9 + (iVar19 * 0x20 + local_40) * 4);
      }
      else if (iVar19 < 0) {
        DAT_1007f288 = (iVar19 * 0x10000) / local_40;
      }
      else {
        DAT_1007f288 = (iVar19 * 0x10000) / local_40;
      }
      _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * fVar1;
      _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * fVar1;
      _DAT_1007f46c = (DAT_1007f47c - DAT_1007f484) * fVar1;
      if ((uVar3 == uVar2) || (iVar11 == 1)) {
        iVar9 = (uVar10 & 0xffff) - (uVar18 & 0xffff);
      }
      else if (iVar11 == 2) {
        iVar9 = (int)((uVar10 & 0xffff) - (uVar18 & 0xffff)) >> 1;
      }
      else {
        iVar9 = (int)((uVar10 & 0xffff) - (uVar18 & 0xffff)) / iVar11;
      }
      uVar18 = uVar18 & 0xffff;
      uVar22 = uVar22 & 0xffff;
      if ((local_28 == sVar15) || (iVar11 == 1)) {
        uVar22 = uVar22 - (uVar4 & 0xffff);
      }
      else if (iVar11 == 2) {
        uVar22 = (int)(uVar22 - (uVar4 & 0xffff)) >> 1;
      }
      else {
        uVar22 = (int)(uVar22 - (uVar4 & 0xffff)) / iVar11;
      }
      uVar4 = uVar4 & 0xffff;
      DAT_1007f2d4 = (iVar9 << 0x10 | uVar22 & 0xffff) + (uVar22 & 0x8000) * -2;
      if ((uVar23 == uVar2) || (local_40 == 1)) {
        iVar9 = (uVar14 & 0xffff) - uVar18;
      }
      else if (local_40 == 2) {
        iVar9 = (int)((uVar14 & 0xffff) - uVar18) >> 1;
      }
      else {
        iVar9 = (int)((uVar14 & 0xffff) - uVar18) / local_40;
      }
      local_2c = local_2c & 0xffff;
      if ((local_34 == sVar15) || (local_40 == 1)) {
        local_2c = local_2c - uVar4;
      }
      else if (local_40 == 2) {
        local_2c = (int)(local_2c - uVar4) >> 1;
      }
      else {
        local_2c = (int)(local_2c - uVar4) / local_40;
      }
      DAT_1007f2d0 = (iVar9 << 0x10 | local_2c & 0xffff) + (local_2c & 0x8000) * -2;
      uVar8 = uVar8 & 0xffff;
      if ((local_1c == local_8) || (iVar11 == 1)) {
        uVar8 = uVar8 - (uVar5 & 0xffff);
      }
      else if (iVar11 == 2) {
        uVar8 = (int)(uVar8 - (uVar5 & 0xffff)) >> 1;
      }
      else {
        uVar8 = (int)(uVar8 - (uVar5 & 0xffff)) / iVar11;
      }
      uVar4 = uVar5 & 0xffff;
      DAT_1007f2e0 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      uVar6 = uVar6 & 0xffff;
      if ((sVar17 == local_8) || (local_40 == 1)) {
        uVar6 = uVar6 - uVar4;
      }
      else if (local_40 == 2) {
        uVar6 = (int)(uVar6 - uVar4) >> 1;
      }
      else {
        uVar6 = (int)(uVar6 - uVar4) / local_40;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f2dc = (uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
      DAT_1007f284 = iVar21 << 0x10;
      DAT_1007f2cc = uVar16;
      _DAT_1007f2d8 = uVar5;
      _DAT_1007f458 = DAT_1007f338;
      _DAT_1007f460 = DAT_1007f480;
      _DAT_1007f468 = DAT_1007f484;
    }
    else {
      iVar12 = iVar21 - DAT_1007f280;
      if (iVar11 == 1) {
        DAT_1007f288 = iVar12 * 0x10000;
      }
      else if (iVar11 == 2) {
        DAT_1007f288 = iVar12 * 0x8000;
      }
      else if (((iVar11 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar9 + (iVar12 * 0x20 + iVar11) * 4);
      }
      else if (iVar12 < 0) {
        DAT_1007f288 = (iVar12 * 0x10000) / iVar11;
      }
      else {
        DAT_1007f288 = (iVar12 * 0x10000) / iVar11;
      }
      iVar12 = DAT_1007f288 - DAT_1007f28c;
      if (iVar12 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      _DAT_1007f46c = _DAT_1007811c / (float)iVar11;
      _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
      _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
      _DAT_1007f46c = (DAT_1007f484 - DAT_1007f474) * _DAT_1007f46c;
      if ((uVar23 == uVar2) || (local_40 == 1)) {
        iVar13 = (uint)uVar23 - (uVar18 & 0xffff);
      }
      else if (local_40 == 2) {
        iVar13 = (int)((uint)uVar23 - (uVar18 & 0xffff)) >> 1;
      }
      else {
        iVar13 = (int)((uint)uVar23 - (uVar18 & 0xffff)) / local_40;
      }
      local_30 = (uint)uVar23;
      uVar18 = uVar18 & 0xffff;
      if ((local_34 == sVar15) || (local_40 == 1)) {
        uVar7 = (local_2c & 0xffff) - (uVar4 & 0xffff);
      }
      else if (local_40 == 2) {
        uVar7 = (int)((local_2c & 0xffff) - (uVar4 & 0xffff)) >> 1;
      }
      else {
        uVar7 = (int)((local_2c & 0xffff) - (uVar4 & 0xffff)) / local_40;
      }
      local_2c = local_2c & 0xffff;
      uVar4 = uVar4 & 0xffff;
      DAT_1007f2d0 = (iVar13 << 0x10 | uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      if ((uVar3 == uVar2) || (iVar11 == 1)) {
        iVar13 = uVar3 - uVar18;
      }
      else if (iVar11 == 2) {
        iVar13 = (int)(uVar3 - uVar18) >> 1;
      }
      else {
        iVar13 = (int)(uVar3 - uVar18) / iVar11;
      }
      uVar7 = (uint)uVar3;
      DAT_1007f2d4 = iVar13 - (DAT_1007f2d0 >> 0x10);
      if (DAT_1007f2d4 != 0) {
        DAT_1007f2d4 = (int)(DAT_1007f2d4 * 0x10000) / iVar12 << 0x10;
      }
      if ((local_28 == sVar15) || (iVar11 == 1)) {
        iVar13 = (uVar22 & 0xffff) - uVar4;
      }
      else if (iVar11 == 2) {
        iVar13 = (int)((uVar22 & 0xffff) - uVar4) >> 1;
      }
      else {
        iVar13 = (int)((uVar22 & 0xffff) - uVar4) / iVar11;
      }
      uVar22 = uVar22 & 0xffff;
      if (iVar13 - (short)DAT_1007f2d0 != 0) {
        uVar4 = DAT_1007f2d4 | ((iVar13 - (short)DAT_1007f2d0) * 0x10000) / iVar12 & 0xffffU;
        DAT_1007f2d4 = uVar4 + (uVar4 & 0x8000) * -2;
      }
      uVar4 = uVar5 & 0xffff;
      if ((sVar17 == local_8) || (local_40 == 1)) {
        uVar14 = (uVar6 & 0xffff) - uVar4;
      }
      else if (local_40 == 2) {
        uVar14 = (int)((uVar6 & 0xffff) - uVar4) >> 1;
      }
      else {
        uVar14 = (int)((uVar6 & 0xffff) - uVar4) / local_40;
      }
      uVar6 = uVar6 & 0xffff;
      DAT_1007f2e0 = 0;
      DAT_1007f2dc = (uVar14 & 0xffff) + (uVar14 & 0x8000) * -2;
      if ((local_1c == local_8) || (iVar11 == 1)) {
        iVar13 = (uVar8 & 0xffff) - uVar4;
      }
      else if (iVar11 == 2) {
        iVar13 = (int)((uVar8 & 0xffff) - uVar4) >> 1;
      }
      else {
        iVar13 = (int)((uVar8 & 0xffff) - uVar4) / iVar11;
      }
      uVar8 = uVar8 & 0xffff;
      if (iVar13 - (short)DAT_1007f2dc != 0) {
        uVar4 = ((iVar13 - (short)DAT_1007f2dc) * 0x10000) / iVar12;
        DAT_1007f2e0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (local_40 < iVar11) {
        iVar11 = iVar11 - local_40;
        DAT_1007f290 = local_40;
        DAT_1007f2cc = uVar16;
        _DAT_1007f2d8 = uVar5;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_1005a2e0((uint *)&DAT_1007f280);
        _DAT_1007f454 = _DAT_1007811c / (float)iVar11;
        _DAT_1007f448 = DAT_1007f478;
        _DAT_1007f440 = DAT_1007f334;
        _DAT_1007f450 = DAT_1007f47c;
        _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f454;
        _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f454;
        _DAT_1007f454 = _DAT_1007f454 * (DAT_1007f484 - DAT_1007f47c);
        DAT_1007f280 = iVar19 << 0x10;
        iVar21 = iVar21 - iVar19;
        if (iVar11 == 1) {
          DAT_1007f28c = iVar21 * 0x10000;
        }
        else if (iVar11 == 2) {
          DAT_1007f28c = iVar21 * 0x8000;
        }
        else if (((iVar11 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar9 + (iVar21 * 0x20 + iVar11) * 4);
        }
        else if (iVar21 < 0) {
          DAT_1007f28c = (iVar21 * 0x10000) / iVar11;
        }
        else {
          DAT_1007f28c = (iVar21 * 0x10000) / iVar11;
        }
        if ((uVar3 == uVar23) || (iVar11 == 1)) {
          DAT_1007f2d0 = uVar7 - local_30;
        }
        else if (iVar11 == 2) {
          DAT_1007f2d0 = (int)(uVar7 - local_30) >> 1;
        }
        else {
          DAT_1007f2d0 = (int)(uVar7 - local_30) / iVar11;
        }
        DAT_1007f2d0 = DAT_1007f2d0 << 0x10;
        if ((local_28 == local_34) || (iVar11 == 1)) {
          uVar22 = uVar22 - local_2c;
        }
        else if (iVar11 == 2) {
          uVar22 = (int)(uVar22 - local_2c) >> 1;
        }
        else {
          uVar22 = (int)(uVar22 - local_2c) / iVar11;
        }
        if (uVar22 != 0) {
          DAT_1007f2d0 = (DAT_1007f2d0 | uVar22 & 0xffff) + (uVar22 & 0x8000) * -2;
        }
        DAT_1007f2dc = 0;
        if ((local_1c == sVar17) || (iVar11 == 1)) {
          uVar8 = uVar8 - uVar6;
        }
        else if (iVar11 == 2) {
          uVar8 = (int)(uVar8 - uVar6) >> 1;
        }
        else {
          uVar8 = (int)(uVar8 - uVar6) / iVar11;
        }
        local_40 = iVar11;
        if (uVar8 != 0) {
          DAT_1007f2dc = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
        }
      }
      else {
        local_40 = local_40 - iVar11;
        DAT_1007f290 = iVar11;
        DAT_1007f2cc = uVar16;
        _DAT_1007f2d8 = uVar5;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_1005a2e0((uint *)&DAT_1007f280);
        if (local_40 == 0) {
          return;
        }
        _DAT_1007f46c = _DAT_1007811c / (float)local_40;
        _DAT_1007f458 = DAT_1007f338;
        _DAT_1007f460 = DAT_1007f480;
        _DAT_1007f468 = DAT_1007f484;
        _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * _DAT_1007f46c;
        _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * _DAT_1007f46c;
        _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f47c - DAT_1007f484);
        DAT_1007f284 = iVar21 << 0x10;
        iVar19 = iVar19 - iVar21;
        if (local_40 == 1) {
          DAT_1007f288 = iVar19 * 0x10000;
        }
        else if (local_40 == 2) {
          DAT_1007f288 = iVar19 * 0x8000;
        }
        else if (((local_40 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar9 + (iVar19 * 0x20 + local_40) * 4);
        }
        else if (iVar19 < 0) {
          DAT_1007f288 = (iVar19 * 0x10000) / local_40;
        }
        else {
          DAT_1007f288 = (iVar19 * 0x10000) / local_40;
        }
      }
    }
  }
  DAT_1007f290 = local_40;
  FUN_1005a2e0((uint *)&DAT_1007f280);
  return;
}


