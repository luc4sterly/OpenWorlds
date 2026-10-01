// 10042690 FUN_10042690 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10042690(int *param_1,int param_2,int param_3,int param_4)

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
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  undefined8 uVar28;
  int iStack_64;
  uint uStack_54;
  uint uStack_48;
  short sStack_44;
  short sStack_40;
  short sStack_3c;
  uint uStack_2c;
  uint uStack_28;
  short sStack_24;
  uint uStack_20;
  short sStack_14;
  ushort uVar2;
  ushort uVar3;
  
  iVar17 = param_3;
  iVar19 = param_4;
  iVar21 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar17 = param_2;
      iVar19 = param_3;
      iVar21 = param_4;
    }
LAB_100426d4:
    param_4 = iVar17;
    param_2 = iVar19;
    param_3 = iVar21;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_100426d4;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  iStack_64 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar24 = *(int *)(param_2 + 100) >> 3;
  uVar22 = *(int *)(param_2 + 0x68) >> 3;
  uVar23 = *(int *)(param_2 + 0x5c) >> 8;
  uVar4 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | uVar23;
  iVar17 = (int)*(short *)(param_3 + 0x1a);
  uVar5 = *(int *)(param_2 + 0x60) >> 8;
  uVar25 = *(int *)(param_3 + 100) >> 3;
  uVar18 = *(int *)(param_3 + 0x68) >> 3;
  uStack_28 = *(int *)(param_3 + 0x5c) >> 8;
  uVar6 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | uStack_28;
  iVar19 = (int)*(short *)(param_4 + 0x1a);
  uVar7 = *(int *)(param_3 + 0x60) >> 8;
  uVar26 = *(int *)(param_4 + 100) >> 3;
  uVar27 = *(int *)(param_4 + 0x68) >> 3;
  uVar20 = *(int *)(param_4 + 0x5c) >> 8;
  uVar8 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar20;
  uVar9 = *(int *)(param_4 + 0x60) >> 8;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007f2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar21 = DAT_10079214 + 0x1000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  uStack_54._0_2_ = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  sStack_24 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  sStack_3c = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  sStack_14 = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  sStack_40 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  sStack_44 = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  uVar12 = (int)uVar8 >> 0x10;
  uVar1 = (ushort)(uVar6 >> 0x10);
  uVar2 = (ushort)(uVar4 >> 0x10);
  uVar3 = (ushort)(uVar8 >> 0x10);
  if (iStack_64 < 1) {
    iVar14 = DAT_1007f280 - iVar17;
    if (iVar14 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    iStack_64 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_64 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    iVar10 = iVar19 - iVar17;
    if (iStack_64 == 1) {
      DAT_1007f28c = iVar10 * 0x10000;
    }
    else if (iStack_64 == 2) {
      DAT_1007f28c = iVar10 * 0x8000;
    }
    else if (((iStack_64 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar21 + (iVar10 * 0x20 + iStack_64) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f28c = (iVar10 * 0x10000) / iStack_64;
    }
    else {
      DAT_1007f28c = (iVar10 * 0x10000) / iStack_64;
    }
    iVar19 = iVar19 - DAT_1007f280;
    if (iStack_64 == 1) {
      DAT_1007f288 = iVar19 * 0x10000;
    }
    else if (iStack_64 == 2) {
      DAT_1007f288 = iVar19 * 0x8000;
    }
    else if (((iStack_64 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar21 + (iVar19 * 0x20 + iStack_64) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1007f288 = (iVar19 * 0x10000) / iStack_64;
    }
    else {
      DAT_1007f288 = (iVar19 * 0x10000) / iStack_64;
    }
    if ((uVar25 == uVar24) || (iVar14 == 1)) {
      uVar24 = uVar24 - uVar25;
    }
    else if (iVar14 == 2) {
      uVar24 = (int)(uVar24 - uVar25) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar25) / iVar14;
    }
    if ((uVar26 == uVar25) || (iStack_64 == 1)) {
      uVar26 = uVar26 - uVar25;
    }
    else if (iStack_64 == 2) {
      uVar26 = (int)(uVar26 - uVar25) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar25) / iStack_64;
    }
    if ((uVar18 == uVar22) || (iVar14 == 1)) {
      uVar22 = uVar22 - uVar18;
    }
    else if (iVar14 == 2) {
      uVar22 = (int)(uVar22 - uVar18) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar18) / iVar14;
    }
    if ((uVar27 == uVar18) || (iStack_64 == 1)) {
      uVar27 = uVar27 - uVar18;
    }
    else if (iStack_64 == 2) {
      uVar27 = (int)(uVar27 - uVar18) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar18) / iStack_64;
    }
    uVar4 = (int)uVar4 >> 0x10;
    if ((uVar1 == uVar2) || (iVar14 == 1)) {
      iVar19 = (uVar4 & 0xffff) - (uint)uVar1;
    }
    else if (iVar14 == 2) {
      iVar19 = (int)((uVar4 & 0xffff) - (uint)uVar1) >> 1;
    }
    else {
      iVar19 = (int)((uVar4 & 0xffff) - (uint)uVar1) / iVar14;
    }
    uVar8 = (uint)uVar1;
    if ((uVar3 == uVar1) || (iStack_64 == 1)) {
      iVar21 = (uVar12 & 0xffff) - uVar8;
    }
    else if (iStack_64 == 2) {
      iVar21 = (int)((uVar12 & 0xffff) - uVar8) >> 1;
    }
    else {
      iVar21 = (int)((uVar12 & 0xffff) - uVar8) / iStack_64;
    }
    uVar23 = uVar23 & 0xffff;
    if ((sStack_40 == (short)uStack_54) || (iVar14 == 1)) {
      uVar23 = uVar23 - (uStack_28 & 0xffff);
    }
    else if (iVar14 == 2) {
      uVar23 = (int)(uVar23 - (uStack_28 & 0xffff)) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - (uStack_28 & 0xffff)) / iVar14;
    }
    uStack_28 = uStack_28 & 0xffff;
    DAT_1007f2d4 = (iVar19 << 0x10 | uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
    uVar20 = uVar20 & 0xffff;
    if ((sStack_24 == sStack_40) || (iStack_64 == 1)) {
      uVar20 = uVar20 - uStack_28;
    }
    else if (iStack_64 == 2) {
      uVar20 = (int)(uVar20 - uStack_28) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uStack_28) / iStack_64;
    }
    DAT_1007f2d0 = (iVar21 << 0x10 | uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
    uVar5 = uVar5 & 0xffff;
    if ((sStack_44 == sStack_3c) || (iVar14 == 1)) {
      uVar5 = uVar5 - (uVar7 & 0xffff);
    }
    else if (iVar14 == 2) {
      uVar5 = (int)(uVar5 - (uVar7 & 0xffff)) >> 1;
    }
    else {
      uVar5 = (int)(uVar5 - (uVar7 & 0xffff)) / iVar14;
    }
    uVar23 = uVar7 & 0xffff;
    DAT_1007f2e0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    uVar9 = uVar9 & 0xffff;
    if ((sStack_14 == sStack_3c) || (iStack_64 == 1)) {
      uVar9 = uVar9 - uVar23;
    }
    else if (iStack_64 == 2) {
      uVar9 = (int)(uVar9 - uVar23) >> 1;
    }
    else {
      uVar9 = (int)(uVar9 - uVar23) / iStack_64;
    }
    DAT_1007f2dc = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    DAT_1007f284 = DAT_1007f280 << 0x10;
    DAT_1007f2c0 = (uVar18 & 0xfffe) << 0xf | (uVar25 & 0xfffe) >> 1;
    uVar23 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
    DAT_1007f2cc = uVar6;
    _DAT_1007f2d8 = uVar7;
  }
  else {
    iVar10 = iVar17 - DAT_1007f280;
    iVar14 = iStack_64;
    if (iStack_64 == 1) {
      DAT_1007f28c = iVar10 * 0x10000;
    }
    else if (iStack_64 == 2) {
      DAT_1007f28c = iVar10 * 0x8000;
    }
    else if (((iStack_64 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar21 + (iVar10 * 0x20 + iStack_64) * 4);
      iVar14 = iVar21;
    }
    else if (iVar10 < 0) {
      DAT_1007f28c = (iVar10 * 0x10000) / iStack_64;
      iVar14 = (iVar10 * 0x10000) % iStack_64;
    }
    else {
      DAT_1007f28c = (iVar10 * 0x10000) / iStack_64;
      iVar14 = (iVar10 * 0x10000) % iStack_64;
    }
    iVar10 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (iVar10 < 1) {
      iVar14 = iVar19 - DAT_1007f280;
      if (iVar14 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar17 = iVar17 - iVar19;
      if (iStack_64 == 1) {
        DAT_1007f288 = iVar17 * 0x10000;
      }
      else if (iStack_64 == 2) {
        DAT_1007f288 = iVar17 * 0x8000;
      }
      else if (((iStack_64 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar21 + (iVar17 * 0x20 + iStack_64) * 4);
      }
      else if (iVar17 < 0) {
        DAT_1007f288 = (iVar17 * 0x10000) / iStack_64;
      }
      else {
        DAT_1007f288 = (iVar17 * 0x10000) / iStack_64;
      }
      if ((uVar26 == uVar24) || (iVar14 == 1)) {
        uVar26 = uVar26 - uVar24;
      }
      else if (iVar14 == 2) {
        uVar26 = (int)(uVar26 - uVar24) >> 1;
      }
      else {
        uVar26 = (int)(uVar26 - uVar24) / iVar14;
      }
      if ((uVar27 == uVar22) || (iVar14 == 1)) {
        uVar27 = uVar27 - uVar22;
      }
      else if (iVar14 == 2) {
        uVar27 = (int)(uVar27 - uVar22) >> 1;
      }
      else {
        uVar27 = (int)(uVar27 - uVar22) / iVar14;
      }
      if ((uVar25 == uVar24) || (iStack_64 == 1)) {
        uVar25 = uVar25 - uVar24;
      }
      else if (iStack_64 == 2) {
        uVar25 = (int)(uVar25 - uVar24) >> 1;
      }
      else {
        uVar25 = (int)(uVar25 - uVar24) / iStack_64;
      }
      if ((uVar18 == uVar22) || (iStack_64 == 1)) {
        uVar18 = uVar18 - uVar22;
      }
      else if (iStack_64 == 2) {
        uVar18 = (int)(uVar18 - uVar22) >> 1;
      }
      else {
        uVar18 = (int)(uVar18 - uVar22) / iStack_64;
      }
      if ((uVar3 == uVar2) || (iVar14 == 1)) {
        iVar17 = (uVar12 & 0xffff) - (uint)uVar2;
      }
      else if (iVar14 == 2) {
        iVar17 = (int)((uVar12 & 0xffff) - (uint)uVar2) >> 1;
      }
      else {
        iVar17 = (int)((uVar12 & 0xffff) - (uint)uVar2) / iVar14;
      }
      uVar8 = (uint)uVar2;
      uVar20 = uVar20 & 0xffff;
      if ((sStack_24 == (short)uStack_54) || (iVar14 == 1)) {
        uVar20 = uVar20 - (uVar23 & 0xffff);
      }
      else if (iVar14 == 2) {
        uVar20 = (int)(uVar20 - (uVar23 & 0xffff)) >> 1;
      }
      else {
        uVar20 = (int)(uVar20 - (uVar23 & 0xffff)) / iVar14;
      }
      uVar23 = uVar23 & 0xffff;
      DAT_1007f2d4 = (iVar17 << 0x10 | uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
      uVar6 = (int)uVar6 >> 0x10;
      if ((uVar1 == uVar2) || (iStack_64 == 1)) {
        iVar17 = (uVar6 & 0xffff) - uVar8;
      }
      else if (iStack_64 == 2) {
        iVar17 = (int)((uVar6 & 0xffff) - uVar8) >> 1;
      }
      else {
        iVar17 = (int)((uVar6 & 0xffff) - uVar8) / iStack_64;
      }
      uStack_28 = uStack_28 & 0xffff;
      if ((sStack_40 == (short)uStack_54) || (iStack_64 == 1)) {
        uStack_28 = uStack_28 - uVar23;
      }
      else if (iStack_64 == 2) {
        uStack_28 = (int)(uStack_28 - uVar23) >> 1;
      }
      else {
        uStack_28 = (int)(uStack_28 - uVar23) / iStack_64;
      }
      DAT_1007f2d0 = (iVar17 << 0x10 | uStack_28 & 0xffff) + (uStack_28 & 0x8000) * -2;
      uVar9 = uVar9 & 0xffff;
      if ((sStack_14 == sStack_44) || (iVar14 == 1)) {
        uVar9 = uVar9 - (uVar5 & 0xffff);
      }
      else if (iVar14 == 2) {
        uVar9 = (int)(uVar9 - (uVar5 & 0xffff)) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - (uVar5 & 0xffff)) / iVar14;
      }
      uVar23 = uVar5 & 0xffff;
      DAT_1007f2e0 = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      uVar7 = uVar7 & 0xffff;
      if ((sStack_3c == sStack_44) || (iStack_64 == 1)) {
        uVar7 = uVar7 - uVar23;
      }
      else if (iStack_64 == 2) {
        uVar7 = (int)(uVar7 - uVar23) >> 1;
      }
      else {
        uVar7 = (int)(uVar7 - uVar23) / iStack_64;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f2dc = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      DAT_1007f284 = iVar19 << 0x10;
      DAT_1007f2c0 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
      DAT_1007f2c8 = (uVar27 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
      DAT_1007f2c4 = (uVar18 & 0xfffe) << 0xf | (uVar25 & 0xfffe) >> 1;
      DAT_1007f2cc = uVar4;
      _DAT_1007f2d8 = uVar5;
      goto LAB_10043adb;
    }
    iVar11 = iVar19 - DAT_1007f280;
    if (iVar10 == 1) {
      DAT_1007f288 = iVar11 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1007f288 = iVar11 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar21 + (iVar11 * 0x20 + iVar10) * 4);
      iVar14 = iVar21;
    }
    else if (iVar11 < 0) {
      DAT_1007f288 = (iVar11 * 0x10000) / iVar10;
      iVar14 = (iVar11 * 0x10000) % iVar10;
    }
    else {
      DAT_1007f288 = (iVar11 * 0x10000) / iVar10;
      iVar14 = (iVar11 * 0x10000) % iVar10;
    }
    uVar8 = DAT_1007f288 - DAT_1007f28c;
    if ((int)uVar8 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    if ((uVar25 == uVar24) || (iStack_64 == 1)) {
      uVar12 = uVar25 - uVar24;
    }
    else if (iStack_64 == 2) {
      uVar12 = (int)(uVar25 - uVar24) >> 1;
    }
    else {
      uVar12 = (int)(uVar25 - uVar24) / iStack_64;
      iVar14 = (int)(uVar25 - uVar24) % iStack_64;
    }
    if ((uVar18 == uVar22) || (iStack_64 == 1)) {
      uVar6 = uVar18 - uVar22;
    }
    else if (iStack_64 == 2) {
      uVar6 = (int)(uVar18 - uVar22) >> 1;
    }
    else {
      uVar6 = (int)(uVar18 - uVar22) / iStack_64;
      iVar14 = (int)(uVar18 - uVar22) % iStack_64;
    }
    if ((uVar26 == uVar24) || (iVar10 == 1)) {
      iVar11 = uVar26 - uVar24;
    }
    else if (iVar10 == 2) {
      iVar11 = (int)(uVar26 - uVar24) >> 1;
    }
    else {
      iVar11 = (int)(uVar26 - uVar24) / iVar10;
      iVar14 = (int)(uVar26 - uVar24) % iVar10;
    }
    iVar11 = iVar11 - uVar12;
    uVar28 = CONCAT44(iVar14,iVar11);
    if (iVar11 != 0) {
      uVar28 = FUN_10069324(iVar11,iVar14,iVar11,uVar8);
    }
    iVar14 = (int)((ulonglong)uVar28 >> 0x20);
    uStack_20 = (uint)uVar28;
    if ((uVar27 == uVar22) || (iVar10 == 1)) {
      iVar11 = uVar27 - uVar22;
    }
    else if (iVar10 == 2) {
      iVar11 = (int)(uVar27 - uVar22) >> 1;
    }
    else {
      iVar11 = (int)(uVar27 - uVar22) / iVar10;
      iVar14 = (int)(uVar27 - uVar22) % iVar10;
    }
    iVar11 = iVar11 - uVar6;
    uVar13 = 0;
    if (iVar11 != 0) {
      uVar28 = FUN_10069324(iVar11,iVar14,iVar11,uVar8);
      uVar13 = (uint)uVar28;
    }
    if ((uVar1 == uVar2) || (iStack_64 == 1)) {
      iVar14 = (uint)uVar1 - (uint)uVar2;
    }
    else if (iStack_64 == 2) {
      iVar14 = (int)((uint)uVar1 - (uint)uVar2) >> 1;
    }
    else {
      iVar14 = (int)((uint)uVar1 - (uint)uVar2) / iStack_64;
    }
    uStack_2c = (uint)uVar1;
    uVar16 = (uint)uVar2;
    if ((sStack_40 == (short)uStack_54) || (iStack_64 == 1)) {
      uVar15 = (uStack_28 & 0xffff) - (uVar23 & 0xffff);
    }
    else if (iStack_64 == 2) {
      uVar15 = (int)((uStack_28 & 0xffff) - (uVar23 & 0xffff)) >> 1;
    }
    else {
      uVar15 = (int)((uStack_28 & 0xffff) - (uVar23 & 0xffff)) / iStack_64;
    }
    uStack_28 = uStack_28 & 0xffff;
    uVar23 = uVar23 & 0xffff;
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
    uStack_48 = (uint)uVar3;
    DAT_1007f2d4 = iVar14 - (DAT_1007f2d0 >> 0x10);
    if (DAT_1007f2d4 != 0) {
      DAT_1007f2d4 = (int)(DAT_1007f2d4 * 0x10000) / (int)uVar8 << 0x10;
    }
    if ((sStack_24 == (short)uStack_54) || (iVar10 == 1)) {
      iVar14 = (uVar20 & 0xffff) - uVar23;
    }
    else if (iVar10 == 2) {
      iVar14 = (int)((uVar20 & 0xffff) - uVar23) >> 1;
    }
    else {
      iVar14 = (int)((uVar20 & 0xffff) - uVar23) / iVar10;
    }
    uVar20 = uVar20 & 0xffff;
    if (iVar14 - (short)DAT_1007f2d0 != 0) {
      uVar23 = DAT_1007f2d4 | ((iVar14 - (short)DAT_1007f2d0) * 0x10000) / (int)uVar8 & 0xffffU;
      DAT_1007f2d4 = uVar23 + (uVar23 & 0x8000) * -2;
    }
    uVar23 = uVar5 & 0xffff;
    if ((sStack_3c == sStack_44) || (iStack_64 == 1)) {
      uVar16 = (uVar7 & 0xffff) - uVar23;
    }
    else if (iStack_64 == 2) {
      uVar16 = (int)((uVar7 & 0xffff) - uVar23) >> 1;
    }
    else {
      uVar16 = (int)((uVar7 & 0xffff) - uVar23) / iStack_64;
    }
    uStack_54 = uVar7 & 0xffff;
    DAT_1007f2e0 = 0;
    DAT_1007f2dc = (uVar16 & 0xffff) + (uVar16 & 0x8000) * -2;
    if ((sStack_14 == sStack_44) || (iVar10 == 1)) {
      iVar14 = (uVar9 & 0xffff) - uVar23;
    }
    else if (iVar10 == 2) {
      iVar14 = (int)((uVar9 & 0xffff) - uVar23) >> 1;
    }
    else {
      iVar14 = (int)((uVar9 & 0xffff) - uVar23) / iVar10;
    }
    uVar9 = uVar9 & 0xffff;
    if (iVar14 - (short)DAT_1007f2dc != 0) {
      uVar8 = ((iVar14 - (short)DAT_1007f2dc) * 0x10000) / (int)uVar8;
      DAT_1007f2e0 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    }
    DAT_1007f280 = DAT_1007f280 << 0x10;
    DAT_1007f284 = DAT_1007f280;
    if (iVar10 <= iStack_64) {
      DAT_1007f2c0 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
      DAT_1007f2c8 = (uVar13 & 0xfffe) << 0xf | (uStack_20 & 0xfffe) >> 1;
      DAT_1007f2c4 = (uVar6 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
      iStack_64 = iStack_64 - iVar10;
      DAT_1007f290 = iVar10;
      DAT_1007f2cc = uVar4;
      _DAT_1007f2d8 = uVar5;
      FUN_10043b00((uint *)&DAT_1007f280);
      if (iStack_64 == 0) {
        return;
      }
      DAT_1007f284 = iVar19 << 0x10;
      iVar17 = iVar17 - iVar19;
      if (iStack_64 == 1) {
        DAT_1007f288 = iVar17 * 0x10000;
      }
      else if (iStack_64 == 2) {
        DAT_1007f288 = iVar17 * 0x8000;
      }
      else if (((iStack_64 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar21 + (iVar17 * 0x20 + iStack_64) * 4);
      }
      else if (iVar17 < 0) {
        DAT_1007f288 = (iVar17 * 0x10000) / iStack_64;
      }
      else {
        DAT_1007f288 = (iVar17 * 0x10000) / iStack_64;
      }
      goto LAB_10043adb;
    }
    DAT_1007f2c0 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
    uVar23 = (uVar13 & 0xfffe) << 0xf | (uStack_20 & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar6 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
    iVar10 = iVar10 - iStack_64;
    DAT_1007f290 = iStack_64;
    DAT_1007f2c8 = uVar23;
    DAT_1007f2cc = uVar4;
    _DAT_1007f2d8 = uVar5;
    FUN_10043b00((uint *)&DAT_1007f280);
    iVar19 = iVar19 - iVar17;
    if (iVar10 == 1) {
      DAT_1007f28c = iVar19 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1007f28c = iVar19 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar21 + (iVar19 * 0x20 + iVar10) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1007f28c = (iVar19 * 0x10000) / iVar10;
    }
    else {
      DAT_1007f28c = (iVar19 * 0x10000) / iVar10;
    }
    if ((uVar26 == uVar25) || (iVar10 == 1)) {
      uVar26 = uVar26 - uVar25;
    }
    else if (iVar10 == 2) {
      uVar26 = (int)(uVar26 - uVar25) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar25) / iVar10;
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
    if ((uVar3 == uVar1) || (iVar10 == 1)) {
      iVar19 = uStack_48 - uStack_2c;
    }
    else if (iVar10 == 2) {
      iVar19 = (int)(uStack_48 - uStack_2c) >> 1;
    }
    else {
      iVar19 = (int)(uStack_48 - uStack_2c) / iVar10;
    }
    DAT_1007f2d0 = iVar19 << 0x10;
    if ((sStack_24 == sStack_40) || (iVar10 == 1)) {
      uVar20 = uVar20 - uStack_28;
    }
    else if (iVar10 == 2) {
      uVar20 = (int)(uVar20 - uStack_28) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uStack_28) / iVar10;
    }
    if (uVar20 != 0) {
      DAT_1007f2d0 = (DAT_1007f2d0 | uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
    }
    DAT_1007f2dc = 0;
    if ((sStack_14 == sStack_3c) || (iVar10 == 1)) {
      uVar9 = uVar9 - uStack_54;
    }
    else if (iVar10 == 2) {
      uVar9 = (int)(uVar9 - uStack_54) >> 1;
    }
    else {
      uVar9 = (int)(uVar9 - uStack_54) / iVar10;
    }
    iStack_64 = iVar10;
    if (uVar9 != 0) {
      DAT_1007f2dc = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    }
  }
  DAT_1007f280 = iVar17 << 0x10;
  DAT_1007f2c4 = (uVar27 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
  DAT_1007f2c8 = uVar23;
LAB_10043adb:
  DAT_1007f290 = iStack_64;
  FUN_10043b00((uint *)&DAT_1007f280);
  return;
}


