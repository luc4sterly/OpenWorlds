// 10056fa0 FUN_10056fa0 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10056fa0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float fVar2;
  ushort uVar3;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  short sVar20;
  int iVar21;
  uint uVar22;
  ushort uVar23;
  uint uVar24;
  uint uVar25;
  short sVar26;
  uint uVar27;
  int local_4c;
  short local_34;
  uint local_30;
  uint local_2c;
  short local_28;
  short local_18;
  short local_4;
  ushort uVar4;
  uint uVar14;
  
  iVar19 = param_3;
  iVar18 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar19 = param_2;
      param_2 = param_4;
      iVar18 = param_3;
    }
LAB_10056fe6:
    param_4 = iVar19;
    param_3 = param_2;
    param_2 = iVar18;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10056fe6;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  iVar21 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  iVar19 = *(int *)(param_2 + 0x20);
  uVar5 = *(int *)(param_2 + 0x5c) >> 8;
  uVar22 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | uVar5;
  uVar6 = *(int *)(param_2 + 0x60) >> 8;
  local_2c = *(int *)(param_3 + 0x5c) >> 8;
  iVar7 = (int)*(short *)(param_3 + 0x1a);
  uVar8 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | local_2c;
  iVar1 = *(int *)(param_3 + 0x20);
  uVar9 = *(int *)(param_3 + 0x60) >> 8;
  uVar25 = *(int *)(param_4 + 0x5c) >> 8;
  iVar10 = (int)*(short *)(param_4 + 0x1a);
  uVar11 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar25;
  iVar18 = *(int *)(param_4 + 0x20);
  DAT_1007f330 = *(float *)(param_3 + 0x14) * *(float *)(param_4 + 0x14);
  uVar12 = *(int *)(param_4 + 0x60) >> 8;
  DAT_1007f334 = *(float *)(param_2 + 0x14) * *(float *)(param_4 + 0x14);
  DAT_1007f338 = *(float *)(param_2 + 0x14) * *(float *)(param_3 + 0x14);
  DAT_1007f470 = (float)*(int *)(param_2 + 100) * _DAT_10078118 * DAT_1007f330;
  DAT_1007f474 = (float)*(int *)(param_2 + 0x68) * _DAT_10078118 * DAT_1007f330;
  DAT_1007f478 = (float)*(int *)(param_3 + 100) * _DAT_10078118 * DAT_1007f334;
  DAT_1007f47c = (float)*(int *)(param_3 + 0x68) * _DAT_10078118 * DAT_1007f334;
  DAT_1007f480 = (float)*(int *)(param_4 + 100) * _DAT_10078118 * DAT_1007f338;
  DAT_1007f29c = DAT_1007f284 * DAT_1007beb0 + DAT_10079210;
  DAT_1007f2a0 = DAT_1007beb0;
  DAT_1007f484 = (float)*(int *)(param_4 + 0x68) * _DAT_10078118 * DAT_1007f338;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  iVar13 = DAT_10079214 + 0x1000;
  DAT_1007f2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  sVar20 = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  uVar24 = (int)uVar22 >> 0x10;
  uVar3 = (ushort)(uVar22 >> 0x10);
  local_34 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  local_28 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  local_18 = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  local_4 = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  uVar14 = (int)uVar11 >> 0x10;
  uVar27 = (int)uVar8 >> 0x10;
  uVar23 = (ushort)(uVar8 >> 0x10);
  uVar4 = (ushort)(uVar11 >> 0x10);
  sVar26 = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  if (iVar21 < 1) {
    iVar21 = DAT_1007f280 - iVar7;
    if (iVar21 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    local_4c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_4c == 0) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    _DAT_1007f46c = _DAT_1007811c / (float)local_4c;
    _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f46c;
    _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f46c;
    _DAT_1007f454 = (DAT_1007f484 - DAT_1007f47c) * _DAT_1007f46c;
    _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
    _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
    _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f484 - DAT_1007f474);
    iVar15 = iVar10 - iVar7;
    if (local_4c == 1) {
      DAT_1007f28c = iVar15 * 0x10000;
    }
    else if (local_4c == 2) {
      DAT_1007f28c = iVar15 * 0x8000;
    }
    else if (((local_4c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar13 + (iVar15 * 0x20 + local_4c) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007f28c = (iVar15 * 0x10000) / local_4c;
    }
    else {
      DAT_1007f28c = (iVar15 * 0x10000) / local_4c;
    }
    iVar10 = iVar10 - DAT_1007f280;
    if (local_4c == 1) {
      DAT_1007f288 = iVar10 * 0x10000;
    }
    else if (local_4c == 2) {
      DAT_1007f288 = iVar10 * 0x8000;
    }
    else if (((local_4c < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar13 + (iVar10 * 0x20 + local_4c) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f288 = (iVar10 * 0x10000) / local_4c;
    }
    else {
      DAT_1007f288 = (iVar10 * 0x10000) / local_4c;
    }
    if ((iVar1 == iVar19) || (iVar21 == 1)) {
      DAT_1007f2ec = iVar19 - iVar1;
    }
    else if (iVar21 == 2) {
      DAT_1007f2ec = iVar19 - iVar1 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar19 - iVar1) / iVar21;
    }
    if ((iVar18 == iVar1) || (local_4c == 1)) {
      DAT_1007f2e8 = iVar18 - iVar1;
    }
    else if (local_4c == 2) {
      DAT_1007f2e8 = iVar18 - iVar1 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar18 - iVar1) / local_4c;
    }
    if ((uVar23 == uVar3) || (iVar21 == 1)) {
      iVar19 = (uVar24 & 0xffff) - (uVar27 & 0xffff);
    }
    else if (iVar21 == 2) {
      iVar19 = (int)((uVar24 & 0xffff) - (uVar27 & 0xffff)) >> 1;
    }
    else {
      iVar19 = (int)((uVar24 & 0xffff) - (uVar27 & 0xffff)) / iVar21;
    }
    uVar27 = uVar27 & 0xffff;
    if ((uVar4 == uVar23) || (local_4c == 1)) {
      iVar18 = (uVar14 & 0xffff) - uVar27;
    }
    else if (local_4c == 2) {
      iVar18 = (int)((uVar14 & 0xffff) - uVar27) >> 1;
    }
    else {
      iVar18 = (int)((uVar14 & 0xffff) - uVar27) / local_4c;
    }
    DAT_1007f2d0 = iVar18 << 0x10;
    uVar5 = uVar5 & 0xffff;
    if ((local_34 == sVar20) || (iVar21 == 1)) {
      uVar5 = uVar5 - (local_2c & 0xffff);
    }
    else if (iVar21 == 2) {
      uVar5 = (int)(uVar5 - (local_2c & 0xffff)) >> 1;
    }
    else {
      uVar5 = (int)(uVar5 - (local_2c & 0xffff)) / iVar21;
    }
    local_2c = local_2c & 0xffff;
    DAT_1007f2d4 = (iVar19 << 0x10 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    uVar25 = uVar25 & 0xffff;
    if ((local_28 == local_34) || (local_4c == 1)) {
      uVar25 = uVar25 - local_2c;
    }
    else if (local_4c == 2) {
      uVar25 = (int)(uVar25 - local_2c) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - local_2c) / local_4c;
    }
    uVar5 = uVar9 & 0xffff;
    DAT_1007f2d0 = (DAT_1007f2d0 | uVar25 & 0xffff) + (uVar25 & 0x8000) * -2;
    uVar6 = uVar6 & 0xffff;
    if ((local_4 == sVar26) || (iVar21 == 1)) {
      uVar6 = uVar6 - uVar5;
    }
    else if (iVar21 == 2) {
      uVar6 = (int)(uVar6 - uVar5) >> 1;
    }
    else {
      uVar6 = (int)(uVar6 - uVar5) / iVar21;
    }
    DAT_1007f2e0 = (uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
    uVar12 = uVar12 & 0xffff;
    if ((local_18 == sVar26) || (local_4c == 1)) {
      uVar12 = uVar12 - uVar5;
    }
    else if (local_4c == 2) {
      uVar12 = (int)(uVar12 - uVar5) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar5) / local_4c;
    }
    DAT_1007f2dc = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
    DAT_1007f2cc = uVar8;
    _DAT_1007f2d8 = uVar9;
    _DAT_1007f440 = DAT_1007f334;
    _DAT_1007f448 = DAT_1007f478;
    _DAT_1007f450 = DAT_1007f47c;
    _DAT_1007f458 = DAT_1007f330;
    _DAT_1007f460 = DAT_1007f470;
    _DAT_1007f468 = DAT_1007f474;
  }
  else {
    iVar15 = iVar7 - DAT_1007f280;
    if (iVar21 == 1) {
      DAT_1007f28c = iVar15 * 0x10000;
    }
    else if (iVar21 == 2) {
      DAT_1007f28c = iVar15 * 0x8000;
    }
    else if (((iVar21 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar13 + (iVar15 * 0x20 + iVar21) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007f28c = (iVar15 * 0x10000) / iVar21;
    }
    else {
      DAT_1007f28c = (iVar15 * 0x10000) / iVar21;
    }
    fVar2 = _DAT_1007811c / (float)iVar21;
    _DAT_1007f444 = (DAT_1007f334 - DAT_1007f330) * fVar2;
    _DAT_1007f44c = (DAT_1007f478 - DAT_1007f470) * fVar2;
    _DAT_1007f454 = (DAT_1007f47c - DAT_1007f474) * fVar2;
    iVar15 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    _DAT_1007f440 = DAT_1007f330;
    _DAT_1007f448 = DAT_1007f470;
    _DAT_1007f450 = DAT_1007f474;
    if (0 < iVar15) {
      iVar16 = iVar10 - DAT_1007f280;
      if (iVar15 == 1) {
        DAT_1007f288 = iVar16 * 0x10000;
      }
      else if (iVar15 == 2) {
        DAT_1007f288 = iVar16 * 0x8000;
      }
      else if (((iVar15 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar13 + (iVar16 * 0x20 + iVar15) * 4);
      }
      else if (iVar16 < 0) {
        DAT_1007f288 = (iVar16 * 0x10000) / iVar15;
      }
      else {
        DAT_1007f288 = (iVar16 * 0x10000) / iVar15;
      }
      iVar16 = DAT_1007f288 - DAT_1007f28c;
      if (iVar16 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f2a0 = DAT_1007beb0;
        return;
      }
      _DAT_1007f46c = _DAT_1007811c / (float)iVar15;
      _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
      _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
      _DAT_1007f46c = (DAT_1007f484 - DAT_1007f474) * _DAT_1007f46c;
      DAT_1007f2c0 = 0;
      DAT_1007f2c4 = 0;
      DAT_1007f2c8 = 0;
      if ((uVar23 == uVar3) || (iVar21 == 1)) {
        iVar17 = (uint)uVar23 - (uVar24 & 0xffff);
      }
      else if (iVar21 == 2) {
        iVar17 = (int)((uint)uVar23 - (uVar24 & 0xffff)) >> 1;
      }
      else {
        iVar17 = (int)((uint)uVar23 - (uVar24 & 0xffff)) / iVar21;
      }
      local_30 = (uint)uVar23;
      uVar24 = uVar24 & 0xffff;
      if ((local_34 == sVar20) || (iVar21 == 1)) {
        uVar8 = (local_2c & 0xffff) - (uVar5 & 0xffff);
      }
      else if (iVar21 == 2) {
        uVar8 = (int)((local_2c & 0xffff) - (uVar5 & 0xffff)) >> 1;
      }
      else {
        uVar8 = (int)((local_2c & 0xffff) - (uVar5 & 0xffff)) / iVar21;
      }
      local_2c = local_2c & 0xffff;
      uVar5 = uVar5 & 0xffff;
      DAT_1007f2d0 = (iVar17 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      if ((uVar4 == uVar3) || (iVar15 == 1)) {
        iVar17 = uVar4 - uVar24;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)(uVar4 - uVar24) >> 1;
      }
      else {
        iVar17 = (int)(uVar4 - uVar24) / iVar15;
      }
      uVar8 = (uint)uVar4;
      DAT_1007f2d4 = iVar17 - (DAT_1007f2d0 >> 0x10);
      if (DAT_1007f2d4 != 0) {
        DAT_1007f2d4 = (int)(DAT_1007f2d4 * 0x10000) / iVar16 << 0x10;
      }
      if ((local_28 == sVar20) || (iVar15 == 1)) {
        iVar17 = (uVar25 & 0xffff) - uVar5;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)((uVar25 & 0xffff) - uVar5) >> 1;
      }
      else {
        iVar17 = (int)((uVar25 & 0xffff) - uVar5) / iVar15;
      }
      uVar25 = uVar25 & 0xffff;
      if (iVar17 - (short)DAT_1007f2d0 != 0) {
        uVar5 = DAT_1007f2d4 | ((iVar17 - (short)DAT_1007f2d0) * 0x10000) / iVar16 & 0xffffU;
        DAT_1007f2d4 = uVar5 + (uVar5 & 0x8000) * -2;
      }
      uVar5 = uVar6 & 0xffff;
      if ((local_4 == sVar26) || (iVar21 == 1)) {
        uVar11 = (uVar9 & 0xffff) - uVar5;
      }
      else if (iVar21 == 2) {
        uVar11 = (int)((uVar9 & 0xffff) - uVar5) >> 1;
      }
      else {
        uVar11 = (int)((uVar9 & 0xffff) - uVar5) / iVar21;
      }
      uVar9 = uVar9 & 0xffff;
      DAT_1007f2e0 = 0;
      DAT_1007f2dc = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      if ((local_4 == local_18) || (iVar15 == 1)) {
        iVar17 = (uVar12 & 0xffff) - uVar5;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)((uVar12 & 0xffff) - uVar5) >> 1;
      }
      else {
        iVar17 = (int)((uVar12 & 0xffff) - uVar5) / iVar15;
      }
      uVar12 = uVar12 & 0xffff;
      if (iVar17 - (short)DAT_1007f2dc != 0) {
        uVar5 = ((iVar17 - (short)DAT_1007f2dc) * 0x10000) / iVar16;
        DAT_1007f2e0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      }
      if ((iVar1 == iVar19) || (iVar21 == 1)) {
        DAT_1007f2e8 = iVar1 - iVar19;
      }
      else if (iVar21 == 2) {
        DAT_1007f2e8 = iVar1 - iVar19 >> 1;
      }
      else {
        DAT_1007f2e8 = (iVar1 - iVar19) / iVar21;
      }
      if ((iVar18 == iVar19) || (iVar15 == 1)) {
        iVar17 = iVar18 - iVar19;
      }
      else if (iVar15 == 2) {
        iVar17 = iVar18 - iVar19 >> 1;
      }
      else {
        iVar17 = (iVar18 - iVar19) / iVar15;
      }
      DAT_1007f2ec = iVar17 - DAT_1007f2e8;
      if ((DAT_1007f2ec != 0) && (iVar16 >> 6 != 0)) {
        DAT_1007f2ec = DAT_1007f2ec / (iVar16 >> 6) << 10;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iVar21 < iVar15) {
        local_4c = iVar15 - iVar21;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar19;
        DAT_1007f290 = iVar21;
        DAT_1007f2cc = uVar22;
        _DAT_1007f2d8 = uVar6;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_100567a0((uint *)&DAT_1007f280);
        _DAT_1007f454 = _DAT_1007811c / (float)local_4c;
        _DAT_1007f448 = DAT_1007f478;
        _DAT_1007f440 = DAT_1007f334;
        _DAT_1007f450 = DAT_1007f47c;
        _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f454;
        _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f454;
        _DAT_1007f454 = _DAT_1007f454 * (DAT_1007f484 - DAT_1007f47c);
        DAT_1007f280 = iVar7 << 0x10;
        iVar10 = iVar10 - iVar7;
        if (local_4c == 1) {
          DAT_1007f28c = iVar10 * 0x10000;
        }
        else if (local_4c == 2) {
          DAT_1007f28c = iVar10 * 0x8000;
        }
        else if (((local_4c < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar13 + (iVar10 * 0x20 + local_4c) * 4);
        }
        else if (iVar10 < 0) {
          DAT_1007f28c = (iVar10 * 0x10000) / local_4c;
        }
        else {
          DAT_1007f28c = (iVar10 * 0x10000) / local_4c;
        }
        DAT_1007f2c4 = 0;
        if ((uVar4 == uVar23) || (local_4c == 1)) {
          DAT_1007f2d0 = uVar8 - local_30;
        }
        else if (local_4c == 2) {
          DAT_1007f2d0 = (int)(uVar8 - local_30) >> 1;
        }
        else {
          DAT_1007f2d0 = (int)(uVar8 - local_30) / local_4c;
        }
        DAT_1007f2d0 = DAT_1007f2d0 << 0x10;
        if ((local_28 == local_34) || (local_4c == 1)) {
          uVar25 = uVar25 - local_2c;
        }
        else if (local_4c == 2) {
          uVar25 = (int)(uVar25 - local_2c) >> 1;
        }
        else {
          uVar25 = (int)(uVar25 - local_2c) / local_4c;
        }
        if (uVar25 != 0) {
          DAT_1007f2d0 = (DAT_1007f2d0 | uVar25 & 0xffff) + (uVar25 & 0x8000) * -2;
        }
        DAT_1007f2dc = 0;
        if ((local_18 == sVar26) || (local_4c == 1)) {
          uVar12 = uVar12 - uVar9;
        }
        else if (local_4c == 2) {
          uVar12 = (int)(uVar12 - uVar9) >> 1;
        }
        else {
          uVar12 = (int)(uVar12 - uVar9) / local_4c;
        }
        if (uVar12 != 0) {
          DAT_1007f2dc = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
        }
        if (iVar18 == iVar1) {
          DAT_1007f2e8 = iVar18 - iVar1;
        }
        else if (local_4c == 1) {
          DAT_1007f2e8 = iVar18 - iVar1;
        }
        else if (local_4c == 2) {
          DAT_1007f2e8 = iVar18 - iVar1 >> 1;
        }
        else {
          DAT_1007f2e8 = (iVar18 - iVar1) / local_4c;
        }
      }
      else {
        local_4c = iVar21 - iVar15;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar19;
        DAT_1007f290 = iVar15;
        DAT_1007f2cc = uVar22;
        _DAT_1007f2d8 = uVar6;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_100567a0((uint *)&DAT_1007f280);
        if (local_4c == 0) {
          return;
        }
        _DAT_1007f46c = _DAT_1007811c / (float)local_4c;
        _DAT_1007f458 = DAT_1007f338;
        _DAT_1007f460 = DAT_1007f480;
        _DAT_1007f468 = DAT_1007f484;
        _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * _DAT_1007f46c;
        _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * _DAT_1007f46c;
        _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f47c - DAT_1007f484);
        DAT_1007f284 = iVar10 << 0x10;
        iVar7 = iVar7 - iVar10;
        if (local_4c == 1) {
          DAT_1007f288 = iVar7 * 0x10000;
        }
        else if (local_4c == 2) {
          DAT_1007f288 = iVar7 * 0x8000;
        }
        else if (((local_4c < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar13 + (iVar7 * 0x20 + local_4c) * 4);
        }
        else if (iVar7 < 0) {
          DAT_1007f288 = (iVar7 * 0x10000) / local_4c;
        }
        else {
          DAT_1007f288 = (iVar7 * 0x10000) / local_4c;
        }
      }
      goto LAB_10058522;
    }
    iVar15 = iVar10 - DAT_1007f280;
    if (iVar15 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar7 = iVar7 - iVar10;
    if (iVar21 == 1) {
      DAT_1007f288 = iVar7 * 0x10000;
    }
    else if (iVar21 == 2) {
      DAT_1007f288 = iVar7 * 0x8000;
    }
    else if (((iVar21 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar13 + (iVar7 * 0x20 + iVar21) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1007f288 = (iVar7 * 0x10000) / iVar21;
    }
    else {
      DAT_1007f288 = (iVar7 * 0x10000) / iVar21;
    }
    _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * fVar2;
    _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * fVar2;
    _DAT_1007f46c = (DAT_1007f47c - DAT_1007f484) * fVar2;
    if ((iVar18 == iVar19) || (iVar15 == 1)) {
      DAT_1007f2ec = iVar18 - iVar19;
    }
    else if (iVar15 == 2) {
      DAT_1007f2ec = iVar18 - iVar19 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar18 - iVar19) / iVar15;
    }
    if ((iVar1 == iVar19) || (iVar21 == 1)) {
      DAT_1007f2e8 = iVar1 - iVar19;
    }
    else if (iVar21 == 2) {
      DAT_1007f2e8 = iVar1 - iVar19 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar1 - iVar19) / iVar21;
    }
    if ((uVar4 == uVar3) || (iVar15 == 1)) {
      iVar18 = (uVar14 & 0xffff) - (uVar24 & 0xffff);
    }
    else if (iVar15 == 2) {
      iVar18 = (int)((uVar14 & 0xffff) - (uVar24 & 0xffff)) >> 1;
    }
    else {
      iVar18 = (int)((uVar14 & 0xffff) - (uVar24 & 0xffff)) / iVar15;
    }
    uVar24 = uVar24 & 0xffff;
    uVar25 = uVar25 & 0xffff;
    if ((local_28 == sVar20) || (iVar15 == 1)) {
      uVar25 = uVar25 - (uVar5 & 0xffff);
    }
    else if (iVar15 == 2) {
      uVar25 = (int)(uVar25 - (uVar5 & 0xffff)) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - (uVar5 & 0xffff)) / iVar15;
    }
    uVar5 = uVar5 & 0xffff;
    DAT_1007f2d4 = (iVar18 << 0x10 | uVar25 & 0xffff) + (uVar25 & 0x8000) * -2;
    if ((uVar23 == uVar3) || (iVar21 == 1)) {
      iVar18 = (uVar27 & 0xffff) - uVar24;
    }
    else if (iVar21 == 2) {
      iVar18 = (int)((uVar27 & 0xffff) - uVar24) >> 1;
    }
    else {
      iVar18 = (int)((uVar27 & 0xffff) - uVar24) / iVar21;
    }
    local_2c = local_2c & 0xffff;
    if ((local_34 == sVar20) || (iVar21 == 1)) {
      local_2c = local_2c - uVar5;
    }
    else if (iVar21 == 2) {
      local_2c = (int)(local_2c - uVar5) >> 1;
    }
    else {
      local_2c = (int)(local_2c - uVar5) / iVar21;
    }
    DAT_1007f2d0 = (iVar18 << 0x10 | local_2c & 0xffff) + (local_2c & 0x8000) * -2;
    uVar12 = uVar12 & 0xffff;
    if ((local_4 == local_18) || (iVar15 == 1)) {
      uVar12 = uVar12 - (uVar6 & 0xffff);
    }
    else if (iVar15 == 2) {
      uVar12 = (int)(uVar12 - (uVar6 & 0xffff)) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - (uVar6 & 0xffff)) / iVar15;
    }
    uVar5 = uVar6 & 0xffff;
    DAT_1007f2e0 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
    uVar9 = uVar9 & 0xffff;
    if ((local_4 == sVar26) || (iVar21 == 1)) {
      uVar9 = uVar9 - uVar5;
    }
    else if (iVar21 == 2) {
      uVar9 = (int)(uVar9 - uVar5) >> 1;
    }
    else {
      uVar9 = (int)(uVar9 - uVar5) / iVar21;
    }
    DAT_1007f2dc = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    DAT_1007f2cc = uVar22;
    _DAT_1007f2d8 = uVar6;
    _DAT_1007f458 = DAT_1007f338;
    _DAT_1007f460 = DAT_1007f480;
    _DAT_1007f468 = DAT_1007f484;
    local_4c = iVar21;
    iVar1 = iVar19;
    iVar7 = DAT_1007f280;
    DAT_1007f280 = iVar10;
  }
  DAT_1007f284 = DAT_1007f280 << 0x10;
  DAT_1007f280 = iVar7 << 0x10;
  DAT_1007f2c8 = 0;
  DAT_1007f2c4 = 0;
  DAT_1007f2c0 = 0;
  DAT_1007f2e4 = DAT_1007f2f0 + iVar1;
LAB_10058522:
  DAT_1007f290 = local_4c;
  FUN_100567a0((uint *)&DAT_1007f280);
  return;
}


