// 1002e4d0 FUN_1002e4d0 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002e4d0(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  ushort uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  short sVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  ushort uVar22;
  int local_40;
  short local_34;
  uint local_30;
  uint local_2c;
  short local_28;
  short local_1c;
  short local_8;
  ushort uVar3;
  uint uVar9;
  short sVar23;
  
  iVar18 = param_3;
  iVar20 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar18 = param_2;
      param_2 = param_4;
      iVar20 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1002e518;
  param_3 = param_2;
  param_4 = iVar18;
  param_2 = iVar20;
LAB_1002e518:
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  local_40 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  iVar18 = (int)*(short *)(param_3 + 0x1a);
  uVar4 = *(int *)(param_2 + 0x5c) >> 8;
  uVar15 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | uVar4;
  uVar5 = *(int *)(param_2 + 0x60) >> 8;
  local_2c = *(int *)(param_3 + 0x5c) >> 8;
  uVar19 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | local_2c;
  uVar6 = *(int *)(param_3 + 0x60) >> 8;
  iVar20 = (int)*(short *)(param_4 + 0x1a);
  uVar21 = *(int *)(param_4 + 0x5c) >> 8;
  DAT_1007f330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  uVar7 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar21;
  DAT_1007f334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  uVar8 = *(int *)(param_4 + 0x60) >> 8;
  DAT_1007f338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007f470 = (float)*(int *)(param_2 + 100) * _DAT_100780f8 * DAT_1007f330;
  DAT_1007f474 = (float)*(int *)(param_2 + 0x68) * _DAT_100780f8 * DAT_1007f330;
  DAT_1007f478 = (float)*(int *)(param_3 + 100) * _DAT_100780f8 * DAT_1007f334;
  DAT_1007f47c = (float)*(int *)(param_3 + 0x68) * _DAT_100780f8 * DAT_1007f334;
  DAT_1007f480 = (float)*(int *)(param_4 + 100) * _DAT_100780f8 * DAT_1007f338;
  DAT_1007f484 = (float)*(int *)(param_4 + 0x68) * _DAT_100780f8 * DAT_1007f338;
  iVar16 = DAT_10079214 + 0x1000;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  sVar14 = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  uVar13 = (int)uVar15 >> 0x10;
  uVar2 = (ushort)(uVar15 >> 0x10);
  local_34 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  local_28 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  local_1c = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  local_8 = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  uVar9 = (int)uVar7 >> 0x10;
  uVar17 = (int)uVar19 >> 0x10;
  uVar22 = (ushort)(uVar19 >> 0x10);
  uVar3 = (ushort)(uVar7 >> 0x10);
  sVar23 = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  if (local_40 < 1) {
    iVar10 = DAT_1007f280 - iVar18;
    if (iVar10 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    local_40 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_40 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    _DAT_1007f46c = _DAT_100780fc / (float)local_40;
    _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f46c;
    _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f46c;
    _DAT_1007f454 = (DAT_1007f484 - DAT_1007f47c) * _DAT_1007f46c;
    _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
    _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
    _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f484 - DAT_1007f474);
    iVar11 = iVar20 - iVar18;
    if (local_40 == 1) {
      DAT_1007f28c = iVar11 * 0x10000;
    }
    else if (local_40 == 2) {
      DAT_1007f28c = iVar11 * 0x8000;
    }
    else if (((local_40 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar16 + (iVar11 * 0x20 + local_40) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1007f28c = (iVar11 * 0x10000) / local_40;
    }
    else {
      DAT_1007f28c = (iVar11 * 0x10000) / local_40;
    }
    iVar20 = iVar20 - DAT_1007f280;
    if (local_40 == 1) {
      DAT_1007f288 = iVar20 * 0x10000;
    }
    else if (local_40 == 2) {
      DAT_1007f288 = iVar20 * 0x8000;
    }
    else if (((local_40 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar16 + (iVar20 * 0x20 + local_40) * 4);
    }
    else if (iVar20 < 0) {
      DAT_1007f288 = (iVar20 * 0x10000) / local_40;
    }
    else {
      DAT_1007f288 = (iVar20 * 0x10000) / local_40;
    }
    DAT_1007f2c0 = 0;
    DAT_1007f2c8 = 0;
    DAT_1007f2c4 = 0;
    if ((uVar2 == uVar22) || (iVar10 == 1)) {
      iVar20 = (uVar13 & 0xffff) - (uVar17 & 0xffff);
    }
    else if (iVar10 == 2) {
      iVar20 = (int)((uVar13 & 0xffff) - (uVar17 & 0xffff)) >> 1;
    }
    else {
      iVar20 = (int)((uVar13 & 0xffff) - (uVar17 & 0xffff)) / iVar10;
    }
    uVar17 = uVar17 & 0xffff;
    if ((uVar3 == uVar22) || (local_40 == 1)) {
      iVar16 = (uVar9 & 0xffff) - uVar17;
    }
    else if (local_40 == 2) {
      iVar16 = (int)((uVar9 & 0xffff) - uVar17) >> 1;
    }
    else {
      iVar16 = (int)((uVar9 & 0xffff) - uVar17) / local_40;
    }
    DAT_1007f2d0 = iVar16 << 0x10;
    uVar4 = uVar4 & 0xffff;
    if ((local_34 == sVar14) || (iVar10 == 1)) {
      uVar4 = uVar4 - (local_2c & 0xffff);
    }
    else if (iVar10 == 2) {
      uVar4 = (int)(uVar4 - (local_2c & 0xffff)) >> 1;
    }
    else {
      uVar4 = (int)(uVar4 - (local_2c & 0xffff)) / iVar10;
    }
    local_2c = local_2c & 0xffff;
    DAT_1007f2d4 = (iVar20 << 0x10 | uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
    uVar21 = uVar21 & 0xffff;
    if ((local_28 == local_34) || (local_40 == 1)) {
      uVar21 = uVar21 - local_2c;
    }
    else if (local_40 == 2) {
      uVar21 = (int)(uVar21 - local_2c) >> 1;
    }
    else {
      uVar21 = (int)(uVar21 - local_2c) / local_40;
    }
    uVar4 = uVar6 & 0xffff;
    DAT_1007f2d0 = (DAT_1007f2d0 | uVar21 & 0xffff) + (uVar21 & 0x8000) * -2;
    uVar5 = uVar5 & 0xffff;
    if ((sVar23 == local_8) || (iVar10 == 1)) {
      uVar5 = uVar5 - uVar4;
    }
    else if (iVar10 == 2) {
      uVar5 = (int)(uVar5 - uVar4) >> 1;
    }
    else {
      uVar5 = (int)(uVar5 - uVar4) / iVar10;
    }
    DAT_1007f2e0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    uVar8 = uVar8 & 0xffff;
    if ((local_1c == sVar23) || (local_40 == 1)) {
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
    DAT_1007f280 = iVar18 << 0x10;
    DAT_1007f2cc = uVar19;
    _DAT_1007f2d8 = uVar6;
    _DAT_1007f440 = DAT_1007f334;
    _DAT_1007f448 = DAT_1007f478;
    _DAT_1007f450 = DAT_1007f47c;
    _DAT_1007f458 = DAT_1007f330;
    _DAT_1007f460 = DAT_1007f470;
    _DAT_1007f468 = DAT_1007f474;
  }
  else {
    iVar10 = iVar18 - DAT_1007f280;
    if (local_40 == 1) {
      DAT_1007f28c = iVar10 * 0x10000;
    }
    else if (local_40 == 2) {
      DAT_1007f28c = iVar10 * 0x8000;
    }
    else if (((local_40 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar16 + (iVar10 * 0x20 + local_40) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f28c = (iVar10 * 0x10000) / local_40;
    }
    else {
      DAT_1007f28c = (iVar10 * 0x10000) / local_40;
    }
    fVar1 = _DAT_100780fc / (float)local_40;
    _DAT_1007f444 = (DAT_1007f334 - DAT_1007f330) * fVar1;
    _DAT_1007f44c = (DAT_1007f478 - DAT_1007f470) * fVar1;
    _DAT_1007f454 = (DAT_1007f47c - DAT_1007f474) * fVar1;
    iVar10 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    _DAT_1007f440 = DAT_1007f330;
    _DAT_1007f448 = DAT_1007f470;
    _DAT_1007f450 = DAT_1007f474;
    if (iVar10 < 1) {
      iVar10 = iVar20 - DAT_1007f280;
      if (iVar10 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar18 = iVar18 - iVar20;
      if (local_40 == 1) {
        DAT_1007f288 = iVar18 * 0x10000;
      }
      else if (local_40 == 2) {
        DAT_1007f288 = iVar18 * 0x8000;
      }
      else if (((local_40 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar16 + (iVar18 * 0x20 + local_40) * 4);
      }
      else if (iVar18 < 0) {
        DAT_1007f288 = (iVar18 * 0x10000) / local_40;
      }
      else {
        DAT_1007f288 = (iVar18 * 0x10000) / local_40;
      }
      _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * fVar1;
      _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * fVar1;
      _DAT_1007f46c = (DAT_1007f47c - DAT_1007f484) * fVar1;
      DAT_1007f2c8 = 0;
      DAT_1007f2c0 = 0;
      DAT_1007f2c4 = 0;
      if ((uVar2 == uVar3) || (iVar10 == 1)) {
        iVar18 = (uVar9 & 0xffff) - (uVar13 & 0xffff);
      }
      else if (iVar10 == 2) {
        iVar18 = (int)((uVar9 & 0xffff) - (uVar13 & 0xffff)) >> 1;
      }
      else {
        iVar18 = (int)((uVar9 & 0xffff) - (uVar13 & 0xffff)) / iVar10;
      }
      uVar13 = uVar13 & 0xffff;
      uVar21 = uVar21 & 0xffff;
      if ((local_28 == sVar14) || (iVar10 == 1)) {
        uVar21 = uVar21 - (uVar4 & 0xffff);
      }
      else if (iVar10 == 2) {
        uVar21 = (int)(uVar21 - (uVar4 & 0xffff)) >> 1;
      }
      else {
        uVar21 = (int)(uVar21 - (uVar4 & 0xffff)) / iVar10;
      }
      uVar4 = uVar4 & 0xffff;
      DAT_1007f2d4 = (iVar18 << 0x10 | uVar21 & 0xffff) + (uVar21 & 0x8000) * -2;
      if ((uVar2 == uVar22) || (local_40 == 1)) {
        iVar18 = (uVar17 & 0xffff) - uVar13;
      }
      else if (local_40 == 2) {
        iVar18 = (int)((uVar17 & 0xffff) - uVar13) >> 1;
      }
      else {
        iVar18 = (int)((uVar17 & 0xffff) - uVar13) / local_40;
      }
      local_2c = local_2c & 0xffff;
      if ((local_34 == sVar14) || (local_40 == 1)) {
        local_2c = local_2c - uVar4;
      }
      else if (local_40 == 2) {
        local_2c = (int)(local_2c - uVar4) >> 1;
      }
      else {
        local_2c = (int)(local_2c - uVar4) / local_40;
      }
      DAT_1007f2d0 = (iVar18 << 0x10 | local_2c & 0xffff) + (local_2c & 0x8000) * -2;
      uVar8 = uVar8 & 0xffff;
      if ((local_1c == local_8) || (iVar10 == 1)) {
        uVar8 = uVar8 - (uVar5 & 0xffff);
      }
      else if (iVar10 == 2) {
        uVar8 = (int)(uVar8 - (uVar5 & 0xffff)) >> 1;
      }
      else {
        uVar8 = (int)(uVar8 - (uVar5 & 0xffff)) / iVar10;
      }
      uVar4 = uVar5 & 0xffff;
      DAT_1007f2e0 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      uVar6 = uVar6 & 0xffff;
      if ((sVar23 == local_8) || (local_40 == 1)) {
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
      DAT_1007f284 = iVar20 << 0x10;
      DAT_1007f2cc = uVar15;
      _DAT_1007f2d8 = uVar5;
      _DAT_1007f458 = DAT_1007f338;
      _DAT_1007f460 = DAT_1007f480;
      _DAT_1007f468 = DAT_1007f484;
    }
    else {
      iVar11 = iVar20 - DAT_1007f280;
      if (iVar10 == 1) {
        DAT_1007f288 = iVar11 * 0x10000;
      }
      else if (iVar10 == 2) {
        DAT_1007f288 = iVar11 * 0x8000;
      }
      else if (((iVar10 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar16 + (iVar11 * 0x20 + iVar10) * 4);
      }
      else if (iVar11 < 0) {
        DAT_1007f288 = (iVar11 * 0x10000) / iVar10;
      }
      else {
        DAT_1007f288 = (iVar11 * 0x10000) / iVar10;
      }
      iVar11 = DAT_1007f288 - DAT_1007f28c;
      if (iVar11 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      _DAT_1007f46c = _DAT_100780fc / (float)iVar10;
      _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
      _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
      _DAT_1007f46c = (DAT_1007f484 - DAT_1007f474) * _DAT_1007f46c;
      DAT_1007f2c0 = 0;
      DAT_1007f2c4 = 0;
      DAT_1007f2c8 = 0;
      if ((uVar2 == uVar22) || (local_40 == 1)) {
        iVar12 = (uint)uVar22 - (uVar13 & 0xffff);
      }
      else if (local_40 == 2) {
        iVar12 = (int)((uint)uVar22 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        iVar12 = (int)((uint)uVar22 - (uVar13 & 0xffff)) / local_40;
      }
      local_30 = (uint)uVar22;
      uVar13 = uVar13 & 0xffff;
      if ((local_34 == sVar14) || (local_40 == 1)) {
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
      DAT_1007f2d0 = (iVar12 << 0x10 | uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      if ((uVar2 == uVar3) || (iVar10 == 1)) {
        iVar12 = uVar3 - uVar13;
      }
      else if (iVar10 == 2) {
        iVar12 = (int)(uVar3 - uVar13) >> 1;
      }
      else {
        iVar12 = (int)(uVar3 - uVar13) / iVar10;
      }
      uVar7 = (uint)uVar3;
      DAT_1007f2d4 = iVar12 - (DAT_1007f2d0 >> 0x10);
      if (DAT_1007f2d4 != 0) {
        DAT_1007f2d4 = (int)(DAT_1007f2d4 * 0x10000) / iVar11 << 0x10;
      }
      if ((local_28 == sVar14) || (iVar10 == 1)) {
        iVar12 = (uVar21 & 0xffff) - uVar4;
      }
      else if (iVar10 == 2) {
        iVar12 = (int)((uVar21 & 0xffff) - uVar4) >> 1;
      }
      else {
        iVar12 = (int)((uVar21 & 0xffff) - uVar4) / iVar10;
      }
      uVar21 = uVar21 & 0xffff;
      if (iVar12 - (short)DAT_1007f2d0 != 0) {
        uVar4 = DAT_1007f2d4 | ((iVar12 - (short)DAT_1007f2d0) * 0x10000) / iVar11 & 0xffffU;
        DAT_1007f2d4 = uVar4 + (uVar4 & 0x8000) * -2;
      }
      uVar4 = uVar5 & 0xffff;
      if ((sVar23 == local_8) || (local_40 == 1)) {
        uVar13 = (uVar6 & 0xffff) - uVar4;
      }
      else if (local_40 == 2) {
        uVar13 = (int)((uVar6 & 0xffff) - uVar4) >> 1;
      }
      else {
        uVar13 = (int)((uVar6 & 0xffff) - uVar4) / local_40;
      }
      uVar6 = uVar6 & 0xffff;
      DAT_1007f2e0 = 0;
      DAT_1007f2dc = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
      if ((local_1c == local_8) || (iVar10 == 1)) {
        iVar12 = (uVar8 & 0xffff) - uVar4;
      }
      else if (iVar10 == 2) {
        iVar12 = (int)((uVar8 & 0xffff) - uVar4) >> 1;
      }
      else {
        iVar12 = (int)((uVar8 & 0xffff) - uVar4) / iVar10;
      }
      uVar8 = uVar8 & 0xffff;
      if (iVar12 - (short)DAT_1007f2dc != 0) {
        uVar4 = ((iVar12 - (short)DAT_1007f2dc) * 0x10000) / iVar11;
        DAT_1007f2e0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (local_40 < iVar10) {
        iVar10 = iVar10 - local_40;
        DAT_1007f290 = local_40;
        DAT_1007f2cc = uVar15;
        _DAT_1007f2d8 = uVar5;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_1002ddd0((uint *)&DAT_1007f280);
        _DAT_1007f454 = _DAT_100780fc / (float)iVar10;
        _DAT_1007f448 = DAT_1007f478;
        _DAT_1007f440 = DAT_1007f334;
        _DAT_1007f450 = DAT_1007f47c;
        _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f454;
        _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f454;
        _DAT_1007f454 = _DAT_1007f454 * (DAT_1007f484 - DAT_1007f47c);
        DAT_1007f280 = iVar18 << 0x10;
        iVar20 = iVar20 - iVar18;
        if (iVar10 == 1) {
          DAT_1007f28c = iVar20 * 0x10000;
        }
        else if (iVar10 == 2) {
          DAT_1007f28c = iVar20 * 0x8000;
        }
        else if (((iVar10 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar16 + (iVar20 * 0x20 + iVar10) * 4);
        }
        else if (iVar20 < 0) {
          DAT_1007f28c = (iVar20 * 0x10000) / iVar10;
        }
        else {
          DAT_1007f28c = (iVar20 * 0x10000) / iVar10;
        }
        DAT_1007f2c4 = 0;
        if ((uVar3 == uVar22) || (iVar10 == 1)) {
          DAT_1007f2d0 = uVar7 - local_30;
        }
        else if (iVar10 == 2) {
          DAT_1007f2d0 = (int)(uVar7 - local_30) >> 1;
        }
        else {
          DAT_1007f2d0 = (int)(uVar7 - local_30) / iVar10;
        }
        DAT_1007f2d0 = DAT_1007f2d0 << 0x10;
        if ((local_28 == local_34) || (iVar10 == 1)) {
          uVar21 = uVar21 - local_2c;
        }
        else if (iVar10 == 2) {
          uVar21 = (int)(uVar21 - local_2c) >> 1;
        }
        else {
          uVar21 = (int)(uVar21 - local_2c) / iVar10;
        }
        if (uVar21 != 0) {
          DAT_1007f2d0 = (DAT_1007f2d0 | uVar21 & 0xffff) + (uVar21 & 0x8000) * -2;
        }
        DAT_1007f2dc = 0;
        if ((local_1c == sVar23) || (iVar10 == 1)) {
          uVar8 = uVar8 - uVar6;
        }
        else if (iVar10 == 2) {
          uVar8 = (int)(uVar8 - uVar6) >> 1;
        }
        else {
          uVar8 = (int)(uVar8 - uVar6) / iVar10;
        }
        local_40 = iVar10;
        if (uVar8 != 0) {
          DAT_1007f2dc = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
        }
      }
      else {
        local_40 = local_40 - iVar10;
        DAT_1007f290 = iVar10;
        DAT_1007f2cc = uVar15;
        _DAT_1007f2d8 = uVar5;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_1002ddd0((uint *)&DAT_1007f280);
        if (local_40 == 0) {
          return;
        }
        _DAT_1007f46c = _DAT_100780fc / (float)local_40;
        _DAT_1007f458 = DAT_1007f338;
        _DAT_1007f460 = DAT_1007f480;
        _DAT_1007f468 = DAT_1007f484;
        _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * _DAT_1007f46c;
        _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * _DAT_1007f46c;
        _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f47c - DAT_1007f484);
        DAT_1007f284 = iVar20 << 0x10;
        iVar18 = iVar18 - iVar20;
        if (local_40 == 1) {
          DAT_1007f288 = iVar18 * 0x10000;
        }
        else if (local_40 == 2) {
          DAT_1007f288 = iVar18 * 0x8000;
        }
        else if (((local_40 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar16 + (iVar18 * 0x20 + local_40) * 4);
        }
        else if (iVar18 < 0) {
          DAT_1007f288 = (iVar18 * 0x10000) / local_40;
        }
        else {
          DAT_1007f288 = (iVar18 * 0x10000) / local_40;
        }
      }
    }
  }
  DAT_1007f290 = local_40;
  FUN_1002ddd0((uint *)&DAT_1007f280);
  return;
}


