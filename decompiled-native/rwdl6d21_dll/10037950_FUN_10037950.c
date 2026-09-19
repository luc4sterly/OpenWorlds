// 10037950 FUN_10037950 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10037950(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float fVar2;
  short sVar3;
  ushort uVar4;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  ushort uVar21;
  short sVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  short sVar26;
  uint uVar27;
  int local_44;
  uint local_40;
  uint local_34;
  short local_30;
  uint local_2c;
  uint local_28;
  short local_24;
  short local_10;
  ushort uVar5;
  uint uVar14;
  
  iVar20 = param_3;
  iVar19 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar20 = param_2;
      param_2 = param_4;
      iVar19 = param_3;
    }
LAB_10037995:
    param_3 = param_2;
    param_4 = iVar20;
    param_2 = iVar19;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10037995;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  iVar6 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  local_40 = *(int *)(param_2 + 0x5c) >> 8;
  iVar20 = *(int *)(param_2 + 0x20);
  iVar24 = (int)*(short *)(param_3 + 0x1a);
  uVar27 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | local_40;
  uVar7 = *(int *)(param_2 + 0x60) >> 8;
  local_28 = *(int *)(param_3 + 0x5c) >> 8;
  uVar8 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | local_28;
  iVar1 = *(int *)(param_3 + 0x20);
  uVar9 = *(int *)(param_3 + 0x60) >> 8;
  uVar25 = *(int *)(param_4 + 0x5c) >> 8;
  iVar10 = (int)*(short *)(param_4 + 0x1a);
  DAT_1007f330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  uVar11 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar25;
  iVar19 = *(int *)(param_4 + 0x20);
  uVar12 = *(int *)(param_4 + 0x60) >> 8;
  DAT_1007f334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007f338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007f470 = (float)*(int *)(param_2 + 100) * _DAT_100780f8 * DAT_1007f330;
  DAT_1007f474 = (float)*(int *)(param_2 + 0x68) * _DAT_100780f8 * DAT_1007f330;
  DAT_1007f478 = (float)*(int *)(param_3 + 100) * _DAT_100780f8 * DAT_1007f334;
  DAT_1007f47c = (float)*(int *)(param_3 + 0x68) * _DAT_100780f8 * DAT_1007f334;
  DAT_1007f480 = (float)*(int *)(param_4 + 100) * _DAT_100780f8 * DAT_1007f338;
  DAT_1007f29c = DAT_1007f284 * DAT_1007beb0 + DAT_10079210;
  DAT_1007f2a0 = DAT_1007beb0;
  DAT_1007f484 = (float)*(int *)(param_4 + 0x68) * _DAT_100780f8 * DAT_1007f338;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007f2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar13 = DAT_10079214 + 0x1000;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  sVar26 = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  uVar18 = (int)uVar27 >> 0x10;
  uVar4 = (ushort)(uVar27 >> 0x10);
  local_30 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  local_24 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  local_10 = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  local_34._0_2_ = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  sVar3 = (short)local_34;
  uVar14 = (int)uVar11 >> 0x10;
  uVar23 = (int)uVar8 >> 0x10;
  uVar21 = (ushort)(uVar8 >> 0x10);
  uVar5 = (ushort)(uVar11 >> 0x10);
  sVar22 = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  if (iVar6 < 1) {
    iVar6 = DAT_1007f280 - iVar24;
    if (iVar6 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    local_44 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_44 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    _DAT_1007f46c = _DAT_100780fc / (float)local_44;
    _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f46c;
    _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f46c;
    _DAT_1007f454 = (DAT_1007f484 - DAT_1007f47c) * _DAT_1007f46c;
    _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
    _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
    _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f484 - DAT_1007f474);
    iVar15 = iVar10 - iVar24;
    if (local_44 == 1) {
      DAT_1007f28c = iVar15 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1007f28c = iVar15 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar13 + (iVar15 * 0x20 + local_44) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007f28c = (iVar15 * 0x10000) / local_44;
    }
    else {
      DAT_1007f28c = (iVar15 * 0x10000) / local_44;
    }
    iVar10 = iVar10 - DAT_1007f280;
    if (local_44 == 1) {
      DAT_1007f288 = iVar10 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1007f288 = iVar10 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar13 + (iVar10 * 0x20 + local_44) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f288 = (iVar10 * 0x10000) / local_44;
    }
    else {
      DAT_1007f288 = (iVar10 * 0x10000) / local_44;
    }
    if ((iVar1 == iVar20) || (iVar6 == 1)) {
      DAT_1007f2ec = iVar20 - iVar1;
    }
    else if (iVar6 == 2) {
      DAT_1007f2ec = iVar20 - iVar1 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar20 - iVar1) / iVar6;
    }
    if ((iVar1 == iVar19) || (local_44 == 1)) {
      DAT_1007f2e8 = iVar19 - iVar1;
    }
    else if (local_44 == 2) {
      DAT_1007f2e8 = iVar19 - iVar1 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar19 - iVar1) / local_44;
    }
    if ((uVar4 == uVar21) || (iVar6 == 1)) {
      iVar20 = (uVar18 & 0xffff) - (uVar23 & 0xffff);
    }
    else if (iVar6 == 2) {
      iVar20 = (int)((uVar18 & 0xffff) - (uVar23 & 0xffff)) >> 1;
    }
    else {
      iVar20 = (int)((uVar18 & 0xffff) - (uVar23 & 0xffff)) / iVar6;
    }
    uVar23 = uVar23 & 0xffff;
    if ((uVar5 == uVar21) || (local_44 == 1)) {
      iVar19 = (uVar14 & 0xffff) - uVar23;
    }
    else if (local_44 == 2) {
      iVar19 = (int)((uVar14 & 0xffff) - uVar23) >> 1;
    }
    else {
      iVar19 = (int)((uVar14 & 0xffff) - uVar23) / local_44;
    }
    DAT_1007f2d0 = iVar19 << 0x10;
    local_40 = local_40 & 0xffff;
    if ((local_30 == sVar26) || (iVar6 == 1)) {
      local_40 = local_40 - (local_28 & 0xffff);
    }
    else if (iVar6 == 2) {
      local_40 = (int)(local_40 - (local_28 & 0xffff)) >> 1;
    }
    else {
      local_40 = (int)(local_40 - (local_28 & 0xffff)) / iVar6;
    }
    local_28 = local_28 & 0xffff;
    DAT_1007f2d4 = (iVar20 << 0x10 | local_40 & 0xffff) + (local_40 & 0x8000) * -2;
    uVar25 = uVar25 & 0xffff;
    if ((local_24 == local_30) || (local_44 == 1)) {
      uVar25 = uVar25 - local_28;
    }
    else if (local_44 == 2) {
      uVar25 = (int)(uVar25 - local_28) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - local_28) / local_44;
    }
    DAT_1007f2d0 = (DAT_1007f2d0 | uVar25 & 0xffff) + (uVar25 & 0x8000) * -2;
    uVar7 = uVar7 & 0xffff;
    uVar25 = uVar9 & 0xffff;
    if ((sVar22 == (short)local_34) || (iVar6 == 1)) {
      uVar7 = uVar7 - uVar25;
    }
    else if (iVar6 == 2) {
      uVar7 = (int)(uVar7 - uVar25) >> 1;
    }
    else {
      uVar7 = (int)(uVar7 - uVar25) / iVar6;
    }
    DAT_1007f2e0 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
    uVar12 = uVar12 & 0xffff;
    if ((local_10 == sVar22) || (local_44 == 1)) {
      uVar12 = uVar12 - uVar25;
    }
    else if (local_44 == 2) {
      uVar12 = (int)(uVar12 - uVar25) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar25) / local_44;
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
    iVar15 = iVar24 - DAT_1007f280;
    if (iVar6 == 1) {
      DAT_1007f28c = iVar15 * 0x10000;
    }
    else if (iVar6 == 2) {
      DAT_1007f28c = iVar15 * 0x8000;
    }
    else if (((iVar6 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar13 + (iVar15 * 0x20 + iVar6) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007f28c = (iVar15 * 0x10000) / iVar6;
    }
    else {
      DAT_1007f28c = (iVar15 * 0x10000) / iVar6;
    }
    fVar2 = _DAT_100780fc / (float)iVar6;
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
      _DAT_1007f46c = _DAT_100780fc / (float)iVar15;
      _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
      _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
      _DAT_1007f46c = (DAT_1007f484 - DAT_1007f474) * _DAT_1007f46c;
      if ((uVar4 == uVar21) || (iVar6 == 1)) {
        iVar17 = (uint)uVar21 - (uVar18 & 0xffff);
      }
      else if (iVar6 == 2) {
        iVar17 = (int)((uint)uVar21 - (uVar18 & 0xffff)) >> 1;
      }
      else {
        iVar17 = (int)((uint)uVar21 - (uVar18 & 0xffff)) / iVar6;
      }
      local_2c = (uint)uVar21;
      uVar18 = uVar18 & 0xffff;
      if ((local_30 == sVar26) || (iVar6 == 1)) {
        uVar8 = (local_28 & 0xffff) - (local_40 & 0xffff);
      }
      else if (iVar6 == 2) {
        uVar8 = (int)((local_28 & 0xffff) - (local_40 & 0xffff)) >> 1;
      }
      else {
        uVar8 = (int)((local_28 & 0xffff) - (local_40 & 0xffff)) / iVar6;
      }
      local_28 = local_28 & 0xffff;
      local_40 = local_40 & 0xffff;
      DAT_1007f2d0 = (iVar17 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      if ((uVar4 == uVar5) || (iVar15 == 1)) {
        iVar17 = uVar5 - uVar18;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)(uVar5 - uVar18) >> 1;
      }
      else {
        iVar17 = (int)(uVar5 - uVar18) / iVar15;
      }
      uVar8 = (uint)uVar5;
      DAT_1007f2d4 = iVar17 - (DAT_1007f2d0 >> 0x10);
      if (DAT_1007f2d4 != 0) {
        DAT_1007f2d4 = (int)(DAT_1007f2d4 * 0x10000) / iVar16 << 0x10;
      }
      if ((local_24 == sVar26) || (iVar15 == 1)) {
        iVar17 = (uVar25 & 0xffff) - local_40;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)((uVar25 & 0xffff) - local_40) >> 1;
      }
      else {
        iVar17 = (int)((uVar25 & 0xffff) - local_40) / iVar15;
      }
      uVar25 = uVar25 & 0xffff;
      if (iVar17 - (short)DAT_1007f2d0 != 0) {
        uVar11 = DAT_1007f2d4 | ((iVar17 - (short)DAT_1007f2d0) * 0x10000) / iVar16 & 0xffffU;
        DAT_1007f2d4 = uVar11 + (uVar11 & 0x8000) * -2;
      }
      uVar11 = uVar7 & 0xffff;
      if ((sVar22 == (short)local_34) || (iVar6 == 1)) {
        uVar18 = (uVar9 & 0xffff) - uVar11;
      }
      else if (iVar6 == 2) {
        uVar18 = (int)((uVar9 & 0xffff) - uVar11) >> 1;
      }
      else {
        uVar18 = (int)((uVar9 & 0xffff) - uVar11) / iVar6;
      }
      local_34 = uVar9 & 0xffff;
      DAT_1007f2e0 = 0;
      DAT_1007f2dc = (uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
      if ((local_10 == sVar3) || (iVar15 == 1)) {
        iVar17 = (uVar12 & 0xffff) - uVar11;
      }
      else if (iVar15 == 2) {
        iVar17 = (int)((uVar12 & 0xffff) - uVar11) >> 1;
      }
      else {
        iVar17 = (int)((uVar12 & 0xffff) - uVar11) / iVar15;
      }
      uVar12 = uVar12 & 0xffff;
      if (iVar17 - (short)DAT_1007f2dc != 0) {
        uVar11 = ((iVar17 - (short)DAT_1007f2dc) * 0x10000) / iVar16;
        DAT_1007f2e0 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      }
      if ((iVar1 == iVar20) || (iVar6 == 1)) {
        DAT_1007f2e8 = iVar1 - iVar20;
      }
      else if (iVar6 == 2) {
        DAT_1007f2e8 = iVar1 - iVar20 >> 1;
      }
      else {
        DAT_1007f2e8 = (iVar1 - iVar20) / iVar6;
      }
      if ((iVar20 == iVar19) || (iVar15 == 1)) {
        iVar17 = iVar19 - iVar20;
      }
      else if (iVar15 == 2) {
        iVar17 = iVar19 - iVar20 >> 1;
      }
      else {
        iVar17 = (iVar19 - iVar20) / iVar15;
      }
      DAT_1007f2ec = iVar17 - DAT_1007f2e8;
      if ((DAT_1007f2ec != 0) && (iVar16 >> 6 != 0)) {
        DAT_1007f2ec = DAT_1007f2ec / (iVar16 >> 6) << 10;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iVar6 < iVar15) {
        local_44 = iVar15 - iVar6;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar20;
        DAT_1007f290 = iVar6;
        DAT_1007f2cc = uVar27;
        _DAT_1007f2d8 = uVar7;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_10037110((uint *)&DAT_1007f280);
        _DAT_1007f454 = _DAT_100780fc / (float)local_44;
        _DAT_1007f448 = DAT_1007f478;
        _DAT_1007f440 = DAT_1007f334;
        _DAT_1007f450 = DAT_1007f47c;
        _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f454;
        _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f454;
        _DAT_1007f454 = _DAT_1007f454 * (DAT_1007f484 - DAT_1007f47c);
        DAT_1007f280 = iVar24 << 0x10;
        iVar10 = iVar10 - iVar24;
        if (local_44 == 1) {
          DAT_1007f28c = iVar10 * 0x10000;
        }
        else if (local_44 == 2) {
          DAT_1007f28c = iVar10 * 0x8000;
        }
        else if (((local_44 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar13 + (iVar10 * 0x20 + local_44) * 4);
        }
        else if (iVar10 < 0) {
          DAT_1007f28c = (iVar10 * 0x10000) / local_44;
        }
        else {
          DAT_1007f28c = (iVar10 * 0x10000) / local_44;
        }
        if ((uVar5 == uVar21) || (local_44 == 1)) {
          DAT_1007f2d0 = uVar8 - local_2c;
        }
        else if (local_44 == 2) {
          DAT_1007f2d0 = (int)(uVar8 - local_2c) >> 1;
        }
        else {
          DAT_1007f2d0 = (int)(uVar8 - local_2c) / local_44;
        }
        DAT_1007f2d0 = DAT_1007f2d0 << 0x10;
        if ((local_24 == local_30) || (local_44 == 1)) {
          uVar25 = uVar25 - local_28;
        }
        else if (local_44 == 2) {
          uVar25 = (int)(uVar25 - local_28) >> 1;
        }
        else {
          uVar25 = (int)(uVar25 - local_28) / local_44;
        }
        if (uVar25 != 0) {
          DAT_1007f2d0 = (DAT_1007f2d0 | uVar25 & 0xffff) + (uVar25 & 0x8000) * -2;
        }
        DAT_1007f2dc = 0;
        if ((local_10 == sVar22) || (local_44 == 1)) {
          uVar12 = uVar12 - local_34;
        }
        else if (local_44 == 2) {
          uVar12 = (int)(uVar12 - local_34) >> 1;
        }
        else {
          uVar12 = (int)(uVar12 - local_34) / local_44;
        }
        if (uVar12 != 0) {
          DAT_1007f2dc = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
        }
        if (iVar1 == iVar19) {
          DAT_1007f2e8 = iVar19 - iVar1;
        }
        else if (local_44 == 1) {
          DAT_1007f2e8 = iVar19 - iVar1;
        }
        else if (local_44 == 2) {
          DAT_1007f2e8 = iVar19 - iVar1 >> 1;
        }
        else {
          DAT_1007f2e8 = (iVar19 - iVar1) / local_44;
        }
      }
      else {
        local_44 = iVar6 - iVar15;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar20;
        DAT_1007f290 = iVar15;
        DAT_1007f2cc = uVar27;
        _DAT_1007f2d8 = uVar7;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_10037110((uint *)&DAT_1007f280);
        if (local_44 == 0) {
          return;
        }
        _DAT_1007f46c = _DAT_100780fc / (float)local_44;
        _DAT_1007f458 = DAT_1007f338;
        _DAT_1007f460 = DAT_1007f480;
        _DAT_1007f468 = DAT_1007f484;
        _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * _DAT_1007f46c;
        _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * _DAT_1007f46c;
        _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f47c - DAT_1007f484);
        DAT_1007f284 = iVar10 << 0x10;
        iVar24 = iVar24 - iVar10;
        if (local_44 == 1) {
          DAT_1007f288 = iVar24 * 0x10000;
        }
        else if (local_44 == 2) {
          DAT_1007f288 = iVar24 * 0x8000;
        }
        else if (((local_44 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar13 + (iVar24 * 0x20 + local_44) * 4);
        }
        else if (iVar24 < 0) {
          DAT_1007f288 = (iVar24 * 0x10000) / local_44;
        }
        else {
          DAT_1007f288 = (iVar24 * 0x10000) / local_44;
        }
      }
      goto LAB_10038ed2;
    }
    iVar15 = iVar10 - DAT_1007f280;
    if (iVar15 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar24 = iVar24 - iVar10;
    if (iVar6 == 1) {
      DAT_1007f288 = iVar24 * 0x10000;
    }
    else if (iVar6 == 2) {
      DAT_1007f288 = iVar24 * 0x8000;
    }
    else if (((iVar6 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar13 + (iVar24 * 0x20 + iVar6) * 4);
    }
    else if (iVar24 < 0) {
      DAT_1007f288 = (iVar24 * 0x10000) / iVar6;
    }
    else {
      DAT_1007f288 = (iVar24 * 0x10000) / iVar6;
    }
    _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * fVar2;
    _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * fVar2;
    _DAT_1007f46c = (DAT_1007f47c - DAT_1007f484) * fVar2;
    if ((iVar20 == iVar19) || (iVar15 == 1)) {
      DAT_1007f2ec = iVar19 - iVar20;
    }
    else if (iVar15 == 2) {
      DAT_1007f2ec = iVar19 - iVar20 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar19 - iVar20) / iVar15;
    }
    if ((iVar1 == iVar20) || (iVar6 == 1)) {
      DAT_1007f2e8 = iVar1 - iVar20;
    }
    else if (iVar6 == 2) {
      DAT_1007f2e8 = iVar1 - iVar20 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar1 - iVar20) / iVar6;
    }
    if ((uVar4 == uVar5) || (iVar15 == 1)) {
      iVar19 = (uVar14 & 0xffff) - (uint)uVar4;
    }
    else if (iVar15 == 2) {
      iVar19 = (int)((uVar14 & 0xffff) - (uint)uVar4) >> 1;
    }
    else {
      iVar19 = (int)((uVar14 & 0xffff) - (uint)uVar4) / iVar15;
    }
    uVar8 = (uint)uVar4;
    uVar25 = uVar25 & 0xffff;
    if ((local_24 == sVar26) || (iVar15 == 1)) {
      uVar25 = uVar25 - (local_40 & 0xffff);
    }
    else if (iVar15 == 2) {
      uVar25 = (int)(uVar25 - (local_40 & 0xffff)) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - (local_40 & 0xffff)) / iVar15;
    }
    local_40 = local_40 & 0xffff;
    DAT_1007f2d4 = (iVar19 << 0x10 | uVar25 & 0xffff) + (uVar25 & 0x8000) * -2;
    if ((uVar4 == uVar21) || (iVar6 == 1)) {
      iVar19 = (uVar23 & 0xffff) - uVar8;
    }
    else if (iVar6 == 2) {
      iVar19 = (int)((uVar23 & 0xffff) - uVar8) >> 1;
    }
    else {
      iVar19 = (int)((uVar23 & 0xffff) - uVar8) / iVar6;
    }
    local_28 = local_28 & 0xffff;
    if ((local_30 == sVar26) || (iVar6 == 1)) {
      local_28 = local_28 - local_40;
    }
    else if (iVar6 == 2) {
      local_28 = (int)(local_28 - local_40) >> 1;
    }
    else {
      local_28 = (int)(local_28 - local_40) / iVar6;
    }
    DAT_1007f2d0 = (iVar19 << 0x10 | local_28 & 0xffff) + (local_28 & 0x8000) * -2;
    uVar12 = uVar12 & 0xffff;
    if ((local_10 == (short)local_34) || (iVar15 == 1)) {
      uVar12 = uVar12 - (uVar7 & 0xffff);
    }
    else if (iVar15 == 2) {
      uVar12 = (int)(uVar12 - (uVar7 & 0xffff)) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - (uVar7 & 0xffff)) / iVar15;
    }
    uVar25 = uVar7 & 0xffff;
    DAT_1007f2e0 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
    uVar9 = uVar9 & 0xffff;
    if ((sVar22 == (short)local_34) || (iVar6 == 1)) {
      uVar9 = uVar9 - uVar25;
    }
    else if (iVar6 == 2) {
      uVar9 = (int)(uVar9 - uVar25) >> 1;
    }
    else {
      uVar9 = (int)(uVar9 - uVar25) / iVar6;
    }
    DAT_1007f2dc = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    DAT_1007f2cc = uVar27;
    _DAT_1007f2d8 = uVar7;
    _DAT_1007f458 = DAT_1007f338;
    _DAT_1007f460 = DAT_1007f480;
    _DAT_1007f468 = DAT_1007f484;
    local_44 = iVar6;
    iVar1 = iVar20;
    iVar24 = DAT_1007f280;
    DAT_1007f280 = iVar10;
  }
  DAT_1007f284 = DAT_1007f280 << 0x10;
  DAT_1007f280 = iVar24 << 0x10;
  DAT_1007f2e4 = DAT_1007f2f0 + iVar1;
LAB_10038ed2:
  DAT_1007f290 = local_44;
  FUN_10037110((uint *)&DAT_1007f280);
  return;
}


