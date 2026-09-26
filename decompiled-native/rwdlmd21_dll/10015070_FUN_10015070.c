// 10015070 FUN_10015070 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10015070(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  ushort uVar32;
  int iVar33;
  int iVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  longlong lVar38;
  undefined8 uVar39;
  int iStack_84;
  uint uStack_7c;
  short sStack_60;
  short sStack_58;
  short sStack_54;
  short sStack_50;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  short sStack_20;
  short sStack_1c;
  uint uStack_18;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  
  iVar10 = param_3;
  iVar21 = param_4;
  iVar33 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar10 = param_2;
      iVar21 = param_3;
      iVar33 = param_4;
    }
LAB_100150c2:
    param_2 = iVar21;
    param_4 = iVar10;
    param_3 = iVar33;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_100150c2;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar10 = (int)sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar31 = *(uint *)(param_2 + 100);
  uVar36 = *(uint *)(param_2 + 0x68);
  uVar11 = (*(uint *)(param_2 + 0x58) & 0xffff0001 | 0x10001) << 8 |
           (*(uint *)(param_2 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_2 + 0x14) <= _DAT_10089dd0)) {
    uVar12 = 0;
  }
  else {
    lVar38 = __ftol();
    if ((int)lVar38 == 0) {
      uVar12 = 0x1e00;
      DAT_1008dbe0._4_4_ = 0;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar38) * 0x1e;
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
  iVar33 = (int)*(short *)(param_3 + 0x1a);
  uVar22 = (*(uint *)(param_2 + 0x60) & 0xfffe00ff) >> 8;
  uVar23 = uVar22 | uVar12 << 0x10;
  iVar21 = *(int *)(param_2 + 0x20);
  uVar24 = uVar23 | 0x100;
  uVar12 = *(uint *)(param_3 + 0x68);
  uVar20 = *(uint *)(param_3 + 100);
  uStack_2c = (*(uint *)(param_3 + 0x58) & 0xffff0001 | 0x10001) << 8 |
              (*(uint *)(param_3 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_3 + 0x14) <= _DAT_10089dd0)) {
    uVar13 = 0;
  }
  else {
    lVar38 = __ftol();
    if ((int)lVar38 == 0) {
      uVar13 = 0x1e00;
      DAT_1008dbe0._4_4_ = 0;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar38) * 0x1e;
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
  iVar34 = (int)*(short *)(param_4 + 0x1a);
  uVar25 = (*(uint *)(param_3 + 0x60) & 0xfffe00ff) >> 8;
  uVar26 = uVar25 | uVar13 << 0x10;
  iVar3 = *(int *)(param_3 + 0x20);
  uVar27 = uVar26 | 0x100;
  uVar13 = *(uint *)(param_4 + 0x68);
  uVar37 = *(uint *)(param_4 + 100);
  uVar14 = (*(uint *)(param_4 + 0x58) & 0xffff0001 | 0x10001) << 8 |
           (*(uint *)(param_4 + 0x5c) & 0xfffe00ff) >> 8;
  if ((DAT_1008a100 == 0) || (*(float *)(param_4 + 0x14) <= _DAT_10089dd0)) {
    uVar15 = 0;
  }
  else {
    lVar38 = __ftol();
    if ((int)lVar38 == 0) {
      uVar15 = 0x1e00;
    }
    else {
      DAT_1008dbe0._4_4_ = (0x10000 - (int)lVar38) * 0x1e;
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
        uVar15 = 0;
      }
      else {
        uVar15 = DAT_1008dbe0._4_4_ >> 8;
      }
    }
  }
  uVar28 = (*(uint *)(param_4 + 0x60) & 0xfffe00ff) >> 8;
  uVar29 = uVar28 | uVar15 << 0x10;
  iVar4 = *(int *)(param_4 + 0x20);
  uVar30 = uVar29 | 0x100;
  uVar15 = (DAT_10089ef8 << 5 | DAT_10089ef0) << 6 | DAT_10089de4;
  DAT_1008dbe0._0_4_ = uVar15 | uVar15 << 0x10;
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  iVar16 = DAT_1008723c + 0x1000;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  sStack_60 = (short)uVar11;
  sStack_20 = (short)uVar14;
  sStack_58 = (short)uVar24;
  sStack_1c = (short)uVar30;
  sStack_54 = (short)uStack_2c;
  sStack_50 = (short)uVar27;
  uVar32 = (ushort)(uVar11 >> 0x10);
  uVar5 = (ushort)(uVar26 >> 0x10);
  uVar26 = (int)uVar14 >> 0x10;
  uVar15 = (int)uVar24 >> 0x10;
  uVar30 = (int)uVar30 >> 0x10;
  uVar6 = (ushort)(uStack_2c >> 0x10);
  uVar7 = (ushort)(uVar14 >> 0x10);
  uVar8 = (ushort)(uVar29 >> 0x10);
  uVar9 = (ushort)(uVar23 >> 0x10);
  DAT_1008dbe0._4_4_ = (uint)DAT_1008dbe0;
  if (iVar10 < 1) {
    iVar10 = DAT_1008d280 - iVar33;
    if (iVar10 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iStack_84 = -((int)sVar1 - (int)sVar2);
    if (iStack_84 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar17 = iVar34 - iVar33;
    if (iStack_84 == 1) {
      DAT_1008d28c = iVar17 * 0x10000;
    }
    else if (iStack_84 == 2) {
      DAT_1008d28c = iVar17 * 0x8000;
    }
    else if (((iStack_84 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar16 + (iVar17 * 0x20 + iStack_84) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1008d28c = (iVar17 * 0x10000) / iStack_84;
    }
    else {
      DAT_1008d28c = (iVar17 * 0x10000) / iStack_84;
    }
    iVar34 = iVar34 - DAT_1008d280;
    if (iStack_84 == 1) {
      DAT_1008d288 = iVar34 * 0x10000;
    }
    else if (iStack_84 == 2) {
      DAT_1008d288 = iVar34 * 0x8000;
    }
    else if (((iStack_84 < 0x20) && (-0x20 < iVar34)) && (iVar34 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar16 + (iVar34 * 0x20 + iStack_84) * 4);
    }
    else if (iVar34 < 0) {
      DAT_1008d288 = (iVar34 * 0x10000) / iStack_84;
    }
    else {
      DAT_1008d288 = (iVar34 * 0x10000) / iStack_84;
    }
    if ((iVar3 == iVar21) || (iVar10 == 1)) {
      DAT_1008d2ec = iVar21 - iVar3;
    }
    else if (iVar10 == 2) {
      DAT_1008d2ec = iVar21 - iVar3 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar21 - iVar3) / iVar10;
    }
    if ((iVar4 == iVar3) || (iStack_84 == 1)) {
      DAT_1008d2e8 = iVar4 - iVar3;
    }
    else if (iStack_84 == 2) {
      DAT_1008d2e8 = iVar4 - iVar3 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar4 - iVar3) / iStack_84;
    }
    if ((uVar20 == uVar31) || (iVar10 == 1)) {
      uVar31 = uVar31 - uVar20;
    }
    else if (iVar10 == 2) {
      uVar31 = (int)(uVar31 - uVar20) >> 1;
    }
    else {
      uVar31 = (int)(uVar31 - uVar20) / iVar10;
    }
    if ((uVar20 == uVar37) || (iStack_84 == 1)) {
      uVar37 = uVar37 - uVar20;
    }
    else if (iStack_84 == 2) {
      uVar37 = (int)(uVar37 - uVar20) >> 1;
    }
    else {
      uVar37 = (int)(uVar37 - uVar20) / iStack_84;
    }
    if ((uVar12 == uVar36) || (iVar10 == 1)) {
      uVar36 = uVar36 - uVar12;
    }
    else if (iVar10 == 2) {
      uVar36 = (int)(uVar36 - uVar12) >> 1;
    }
    else {
      uVar36 = (int)(uVar36 - uVar12) / iVar10;
    }
    if ((uVar12 == uVar13) || (iStack_84 == 1)) {
      uVar13 = uVar13 - uVar12;
    }
    else if (iStack_84 == 2) {
      uVar13 = (int)(uVar13 - uVar12) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - uVar12) / iStack_84;
    }
    uVar23 = (int)uVar11 >> 0x10;
    if ((uVar6 == uVar32) || (iVar10 == 1)) {
      iVar21 = (uVar23 & 0xffff) - (uint)uVar6;
    }
    else if (iVar10 == 2) {
      iVar21 = (int)((uVar23 & 0xffff) - (uint)uVar6) >> 1;
    }
    else {
      iVar21 = (int)((uVar23 & 0xffff) - (uint)uVar6) / iVar10;
    }
    uVar23 = (uint)uVar6;
    if ((uVar7 == uVar6) || (iStack_84 == 1)) {
      iVar34 = (uVar26 & 0xffff) - uVar23;
    }
    else if (iStack_84 == 2) {
      iVar34 = (int)((uVar26 & 0xffff) - uVar23) >> 1;
    }
    else {
      iVar34 = (int)((uVar26 & 0xffff) - uVar23) / iStack_84;
    }
    uVar11 = uVar11 & 0xffff;
    if ((sStack_54 == sStack_60) || (iVar10 == 1)) {
      uVar11 = uVar11 - (uStack_2c & 0xffff);
    }
    else if (iVar10 == 2) {
      uVar11 = (int)(uVar11 - (uStack_2c & 0xffff)) >> 1;
    }
    else {
      uVar11 = (int)(uVar11 - (uStack_2c & 0xffff)) / iVar10;
    }
    uVar23 = uStack_2c & 0xffff;
    DAT_1008d2d4 = (iVar21 << 0x10 | uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
    uVar14 = uVar14 & 0xffff;
    if ((sStack_20 == sStack_54) || (iStack_84 == 1)) {
      uVar14 = uVar14 - uVar23;
    }
    else if (iStack_84 == 2) {
      uVar14 = (int)(uVar14 - uVar23) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar23) / iStack_84;
    }
    DAT_1008d2d0 = (iVar34 << 0x10 | uVar14 & 0xffff) + (uVar14 & 0x8000) * -2;
    if ((uVar8 == uVar5) || (iStack_84 == 1)) {
      iVar21 = (uVar30 & 0xffff) - (uint)uVar5;
    }
    else if (iStack_84 == 2) {
      iVar21 = (int)((uVar30 & 0xffff) - (uint)uVar5) >> 1;
    }
    else {
      iVar21 = (int)((uVar30 & 0xffff) - (uint)uVar5) / iStack_84;
    }
    uVar11 = (uint)uVar5;
    if ((uVar9 == uVar5) || (iVar10 == 1)) {
      iVar34 = (uVar15 & 0xffff) - uVar11;
    }
    else if (iVar10 == 2) {
      iVar34 = (int)((uVar15 & 0xffff) - uVar11) >> 1;
    }
    else {
      iVar34 = (int)((uVar15 & 0xffff) - uVar11) / iVar10;
    }
    uVar11 = uVar22 & 0xffff | 0x100;
    if ((sStack_58 == sStack_50) || (iVar10 == 1)) {
      uVar11 = uVar11 - (uVar25 & 0xffff | 0x100);
    }
    else if (iVar10 == 2) {
      uVar11 = (int)(uVar11 - (uVar25 & 0xffff | 0x100)) >> 1;
    }
    else {
      uVar11 = (int)(uVar11 - (uVar25 & 0xffff | 0x100)) / iVar10;
    }
    uVar22 = uVar25 & 0xffff | 0x100;
    DAT_1008d2e0 = (iVar34 << 0x10 | uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
    uVar11 = uVar28 & 0xffff | 0x100;
    if ((sStack_1c == sStack_50) || (iStack_84 == 1)) {
      uVar11 = uVar11 - uVar22;
    }
    else if (iStack_84 == 2) {
      uVar11 = (int)(uVar11 - uVar22) >> 1;
    }
    else {
      uVar11 = (int)(uVar11 - uVar22) / iStack_84;
    }
    DAT_1008d2dc = (iVar21 << 0x10 | uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
    DAT_1008d2c0 = (uVar12 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1008d2c8 = (uVar36 & 0xfffe) << 0xf | (uVar31 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar13 & 0xfffe) << 0xf | (uVar37 & 0xfffe) >> 1;
    DAT_1008d2cc = uStack_2c;
    DAT_1008d2d8 = uVar27;
  }
  else {
    iVar17 = iVar33 - DAT_1008d280;
    if (iVar10 == 1) {
      DAT_1008d28c = iVar17 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1008d28c = iVar17 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar16 + (iVar17 * 0x20 + iVar10) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1008d28c = (iVar17 * 0x10000) / iVar10;
    }
    else {
      DAT_1008d28c = (iVar17 * 0x10000) / iVar10;
    }
    iVar17 = (int)sVar2 - DAT_1008d284;
    if (0 < iVar17) {
      iVar18 = iVar34 - DAT_1008d280;
      iVar19 = iVar17;
      if (iVar17 == 1) {
        DAT_1008d288 = iVar18 * 0x10000;
      }
      else if (iVar17 == 2) {
        DAT_1008d288 = iVar18 * 0x8000;
      }
      else if (((iVar17 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar16 + (iVar18 * 0x20 + iVar17) * 4);
        iVar19 = iVar16;
      }
      else if (iVar18 < 0) {
        DAT_1008d288 = (iVar18 * 0x10000) / iVar17;
        iVar19 = (iVar18 * 0x10000) % iVar17;
      }
      else {
        DAT_1008d288 = (iVar18 * 0x10000) / iVar17;
        iVar19 = (iVar18 * 0x10000) % iVar17;
      }
      uVar23 = DAT_1008d288 - DAT_1008d28c;
      if ((int)uVar23 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d2a0 = DAT_10089ef4;
        return;
      }
      if ((uVar20 == uVar31) || (iVar10 == 1)) {
        uVar26 = uVar20 - uVar31;
      }
      else if (iVar10 == 2) {
        uVar26 = (int)(uVar20 - uVar31) >> 1;
      }
      else {
        uVar26 = (int)(uVar20 - uVar31) / iVar10;
        iVar19 = (int)(uVar20 - uVar31) % iVar10;
      }
      if ((uVar12 == uVar36) || (iVar10 == 1)) {
        uVar27 = uVar12 - uVar36;
      }
      else if (iVar10 == 2) {
        uVar27 = (int)(uVar12 - uVar36) >> 1;
      }
      else {
        uVar27 = (int)(uVar12 - uVar36) / iVar10;
        iVar19 = (int)(uVar12 - uVar36) % iVar10;
      }
      if ((uVar31 == uVar37) || (iVar17 == 1)) {
        iVar18 = uVar37 - uVar31;
      }
      else if (iVar17 == 2) {
        iVar18 = (int)(uVar37 - uVar31) >> 1;
      }
      else {
        iVar18 = (int)(uVar37 - uVar31) / iVar17;
        iVar19 = (int)(uVar37 - uVar31) % iVar17;
      }
      iVar18 = iVar18 - uVar26;
      uVar39 = CONCAT44(iVar19,iVar18);
      if (iVar18 != 0) {
        uVar39 = FUN_1006a324(iVar18,iVar19,iVar18,uVar23);
      }
      iVar19 = (int)((ulonglong)uVar39 >> 0x20);
      uStack_18 = (uint)uVar39;
      if ((uVar36 == uVar13) || (iVar17 == 1)) {
        iVar18 = uVar13 - uVar36;
      }
      else if (iVar17 == 2) {
        iVar18 = (int)(uVar13 - uVar36) >> 1;
      }
      else {
        iVar18 = (int)(uVar13 - uVar36) / iVar17;
        iVar19 = (int)(uVar13 - uVar36) % iVar17;
      }
      iVar18 = iVar18 - uVar27;
      uVar15 = 0;
      if (iVar18 != 0) {
        uVar39 = FUN_1006a324(iVar18,iVar19,iVar18,uVar23);
        uVar15 = (uint)uVar39;
      }
      if ((uVar6 == uVar32) || (iVar10 == 1)) {
        iVar19 = (uint)uVar6 - (uint)uVar32;
      }
      else if (iVar10 == 2) {
        iVar19 = (int)((uint)uVar6 - (uint)uVar32) >> 1;
      }
      else {
        iVar19 = (int)((uint)uVar6 - (uint)uVar32) / iVar10;
      }
      uStack_30 = (uint)uVar6;
      uVar30 = (uint)uVar32;
      if ((sStack_54 == sStack_60) || (iVar10 == 1)) {
        uVar29 = (uStack_2c & 0xffff) - (uVar11 & 0xffff);
      }
      else if (iVar10 == 2) {
        uVar29 = (int)((uStack_2c & 0xffff) - (uVar11 & 0xffff)) >> 1;
      }
      else {
        uVar29 = (int)((uStack_2c & 0xffff) - (uVar11 & 0xffff)) / iVar10;
      }
      uStack_2c = uStack_2c & 0xffff;
      uVar35 = uVar11 & 0xffff;
      DAT_1008d2d0 = (iVar19 << 0x10 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
      if ((uVar7 == uVar32) || (iVar17 == 1)) {
        iVar19 = uVar7 - uVar30;
      }
      else if (iVar17 == 2) {
        iVar19 = (int)(uVar7 - uVar30) >> 1;
      }
      else {
        iVar19 = (int)(uVar7 - uVar30) / iVar17;
      }
      uStack_34 = (uint)uVar7;
      DAT_1008d2d4 = iVar19 - (DAT_1008d2d0 >> 0x10);
      if (DAT_1008d2d4 != 0) {
        DAT_1008d2d4 = (int)(DAT_1008d2d4 * 0x10000) / (int)uVar23 << 0x10;
      }
      if ((sStack_20 == sStack_60) || (iVar17 == 1)) {
        iVar19 = (uVar14 & 0xffff) - uVar35;
      }
      else if (iVar17 == 2) {
        iVar19 = (int)((uVar14 & 0xffff) - uVar35) >> 1;
      }
      else {
        iVar19 = (int)((uVar14 & 0xffff) - uVar35) / iVar17;
      }
      uVar14 = uVar14 & 0xffff;
      if (iVar19 - (short)DAT_1008d2d0 != 0) {
        uVar30 = DAT_1008d2d4 | ((iVar19 - (short)DAT_1008d2d0) * 0x10000) / (int)uVar23 & 0xffffU;
        DAT_1008d2d4 = uVar30 + (uVar30 & 0x8000) * -2;
      }
      if ((uVar5 == uVar9) || (iVar10 == 1)) {
        iVar19 = (uint)uVar5 - (uint)uVar9;
      }
      else if (iVar10 == 2) {
        iVar19 = (int)((uint)uVar5 - (uint)uVar9) >> 1;
      }
      else {
        iVar19 = (int)((uint)uVar5 - (uint)uVar9) / iVar10;
      }
      uStack_28 = (uint)uVar5;
      uVar30 = (uint)uVar9;
      if ((sStack_50 == sStack_58) || (iVar10 == 1)) {
        uStack_24 = uVar25 & 0xffff | 0x100;
        uStack_38 = uVar22 & 0xffff | 0x100;
        uVar22 = uStack_24 - uStack_38;
      }
      else if (iVar10 == 2) {
        uStack_24 = uVar25 & 0xffff | 0x100;
        uStack_38 = uVar22 & 0xffff | 0x100;
        uVar22 = (int)(uStack_24 - uStack_38) >> 1;
      }
      else {
        uStack_24 = uVar25 & 0xffff | 0x100;
        uStack_38 = uVar22 & 0xffff | 0x100;
        uVar22 = (int)(uStack_24 - uStack_38) / iVar10;
      }
      DAT_1008d2dc = (iVar19 << 0x10 | uVar22 & 0xffff) + (uVar22 & 0x8000) * -2;
      if ((uVar8 == uVar9) || (iVar17 == 1)) {
        iVar19 = uVar8 - uVar30;
      }
      else if (iVar17 == 2) {
        iVar19 = (int)(uVar8 - uVar30) >> 1;
      }
      else {
        iVar19 = (int)(uVar8 - uVar30) / iVar17;
      }
      uStack_7c = (uint)uVar8;
      DAT_1008d2e0 = iVar19 - (DAT_1008d2dc >> 0x10);
      if (DAT_1008d2e0 != 0) {
        DAT_1008d2e0 = (int)(DAT_1008d2e0 * 0x10000) / (int)uVar23 << 0x10;
      }
      if ((sStack_1c == sStack_58) || (iVar17 == 1)) {
        iVar19 = (uVar28 & 0xffff | 0x100) - uStack_38;
      }
      else if (iVar17 == 2) {
        iVar19 = (int)((uVar28 & 0xffff | 0x100) - uStack_38) >> 1;
      }
      else {
        iVar19 = (int)((uVar28 & 0xffff | 0x100) - uStack_38) / iVar17;
      }
      uVar22 = uVar28 & 0xffff | 0x100;
      if (iVar19 - (short)DAT_1008d2dc != 0) {
        uVar25 = DAT_1008d2e0 | ((iVar19 - (short)DAT_1008d2dc) * 0x10000) / (int)uVar23 & 0xffffU;
        DAT_1008d2e0 = uVar25 + (uVar25 & 0x8000) * -2;
      }
      if ((iVar3 == iVar21) || (iVar10 == 1)) {
        DAT_1008d2e8 = iVar3 - iVar21;
      }
      else if (iVar10 == 2) {
        DAT_1008d2e8 = iVar3 - iVar21 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar3 - iVar21) / iVar10;
      }
      if ((iVar4 == iVar21) || (iVar17 == 1)) {
        iVar19 = iVar4 - iVar21;
      }
      else if (iVar17 == 2) {
        iVar19 = iVar4 - iVar21 >> 1;
      }
      else {
        iVar19 = (iVar4 - iVar21) / iVar17;
      }
      DAT_1008d2ec = iVar19 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && ((int)uVar23 >> 6 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / ((int)uVar23 >> 6) << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar10 < iVar17) {
        DAT_1008d2c0 = (uVar36 & 0xfffe) << 0xf | (uVar31 & 0xfffe) >> 1;
        uVar31 = (uVar15 & 0xfffe) << 0xf | (uStack_18 & 0xfffe) >> 1;
        DAT_1008d2c4 = (uVar27 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
        iStack_84 = iVar17 - iVar10;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar21;
        DAT_1008d290 = iVar10;
        DAT_1008d2c8 = uVar31;
        DAT_1008d2cc = uVar11;
        DAT_1008d2d8 = uVar24;
        FUN_1007953c();
        DAT_1008d280 = iVar33 << 0x10;
        iVar34 = iVar34 - iVar33;
        if (iStack_84 == 1) {
          DAT_1008d28c = iVar34 * 0x10000;
        }
        else if (iStack_84 == 2) {
          DAT_1008d28c = iVar34 * 0x8000;
        }
        else if (((iStack_84 < 0x20) && (-0x20 < iVar34)) && (iVar34 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar16 + (iVar34 * 0x20 + iStack_84) * 4);
        }
        else if (iVar34 < 0) {
          DAT_1008d28c = (iVar34 * 0x10000) / iStack_84;
        }
        else {
          DAT_1008d28c = (iVar34 * 0x10000) / iStack_84;
        }
        if ((uVar20 == uVar37) || (iStack_84 == 1)) {
          uVar37 = uVar37 - uVar20;
        }
        else if (iStack_84 == 2) {
          uVar37 = (int)(uVar37 - uVar20) >> 1;
        }
        else {
          uVar37 = (int)(uVar37 - uVar20) / iStack_84;
        }
        if ((uVar12 == uVar13) || (iStack_84 == 1)) {
          uVar13 = uVar13 - uVar12;
        }
        else if (iStack_84 == 2) {
          uVar13 = (int)(uVar13 - uVar12) >> 1;
        }
        else {
          uVar13 = (int)(uVar13 - uVar12) / iStack_84;
        }
        if ((uVar7 == uVar6) || (iStack_84 == 1)) {
          iVar10 = uStack_34 - uStack_30;
        }
        else if (iStack_84 == 2) {
          iVar10 = (int)(uStack_34 - uStack_30) >> 1;
        }
        else {
          iVar10 = (int)(uStack_34 - uStack_30) / iStack_84;
        }
        DAT_1008d2d0 = iVar10 << 0x10;
        if ((sStack_20 == sStack_54) || (iStack_84 == 1)) {
          uVar14 = uVar14 - uStack_2c;
        }
        else if (iStack_84 == 2) {
          uVar14 = (int)(uVar14 - uStack_2c) >> 1;
        }
        else {
          uVar14 = (int)(uVar14 - uStack_2c) / iStack_84;
        }
        if (uVar14 != 0) {
          DAT_1008d2d0 = (DAT_1008d2d0 | uVar14 & 0xffff) + (uVar14 & 0x8000) * -2;
        }
        if ((uVar8 == uVar5) || (iStack_84 == 1)) {
          iVar10 = uStack_7c - uStack_28;
        }
        else if (iStack_84 == 2) {
          iVar10 = (int)(uStack_7c - uStack_28) >> 1;
        }
        else {
          iVar10 = (int)(uStack_7c - uStack_28) / iStack_84;
        }
        DAT_1008d2dc = iVar10 << 0x10;
        if ((sStack_1c == sStack_50) || (iStack_84 == 1)) {
          uVar22 = uVar22 - uStack_24;
        }
        else if (iStack_84 == 2) {
          uVar22 = (int)(uVar22 - uStack_24) >> 1;
        }
        else {
          uVar22 = (int)(uVar22 - uStack_24) / iStack_84;
        }
        if (uVar22 != 0) {
          DAT_1008d2dc = (DAT_1008d2dc | uVar22 & 0xffff) + (uVar22 & 0x8000) * -2;
        }
        if ((iVar4 == iVar3) || (iStack_84 == 1)) {
          DAT_1008d2e8 = iVar4 - iVar3;
        }
        else if (iStack_84 == 2) {
          DAT_1008d2e8 = iVar4 - iVar3 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar4 - iVar3) / iStack_84;
        }
        DAT_1008d2c4 = (uVar13 & 0xfffe) << 0xf | (uVar37 & 0xfffe) >> 1;
        DAT_1008d2c8 = uVar31;
      }
      else {
        DAT_1008d2c0 = (uVar36 & 0xfffe) << 0xf | (uVar31 & 0xfffe) >> 1;
        DAT_1008d2c8 = (uVar15 & 0xfffe) << 0xf | (uStack_18 & 0xfffe) >> 1;
        DAT_1008d2c4 = (uVar27 & 0xfffe) << 0xf | (uVar26 & 0xfffe) >> 1;
        iStack_84 = iVar10 - iVar17;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar21;
        DAT_1008d290 = iVar17;
        DAT_1008d2cc = uVar11;
        DAT_1008d2d8 = uVar24;
        FUN_1007953c();
        if (iStack_84 == 0) {
          return;
        }
        DAT_1008d284 = iVar34 << 0x10;
        iVar33 = iVar33 - iVar34;
        if (iStack_84 == 1) {
          DAT_1008d288 = iVar33 * 0x10000;
        }
        else if (iStack_84 == 2) {
          DAT_1008d288 = iVar33 * 0x8000;
        }
        else if (((iStack_84 < 0x20) && (-0x20 < iVar33)) && (iVar33 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar16 + (iVar33 * 0x20 + iStack_84) * 4);
        }
        else if (iVar33 < 0) {
          DAT_1008d288 = (iVar33 * 0x10000) / iStack_84;
        }
        else {
          DAT_1008d288 = (iVar33 * 0x10000) / iStack_84;
        }
      }
      goto LAB_10016dc6;
    }
    iVar17 = iVar34 - DAT_1008d280;
    if (iVar17 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar33 = iVar33 - iVar34;
    if (iVar10 == 1) {
      DAT_1008d288 = iVar33 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1008d288 = iVar33 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar33)) && (iVar33 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar16 + (iVar33 * 0x20 + iVar10) * 4);
    }
    else if (iVar33 < 0) {
      DAT_1008d288 = (iVar33 * 0x10000) / iVar10;
    }
    else {
      DAT_1008d288 = (iVar33 * 0x10000) / iVar10;
    }
    if ((iVar4 == iVar21) || (iVar17 == 1)) {
      DAT_1008d2ec = iVar4 - iVar21;
    }
    else if (iVar17 == 2) {
      DAT_1008d2ec = iVar4 - iVar21 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar4 - iVar21) / iVar17;
    }
    if ((iVar3 == iVar21) || (iVar10 == 1)) {
      DAT_1008d2e8 = iVar3 - iVar21;
    }
    else if (iVar10 == 2) {
      DAT_1008d2e8 = iVar3 - iVar21 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar3 - iVar21) / iVar10;
    }
    if ((uVar31 == uVar37) || (iVar17 == 1)) {
      uVar37 = uVar37 - uVar31;
    }
    else if (iVar17 == 2) {
      uVar37 = (int)(uVar37 - uVar31) >> 1;
    }
    else {
      uVar37 = (int)(uVar37 - uVar31) / iVar17;
    }
    if ((uVar36 == uVar13) || (iVar17 == 1)) {
      uVar13 = uVar13 - uVar36;
    }
    else if (iVar17 == 2) {
      uVar13 = (int)(uVar13 - uVar36) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - uVar36) / iVar17;
    }
    if ((uVar20 == uVar31) || (iVar10 == 1)) {
      uVar20 = uVar20 - uVar31;
    }
    else if (iVar10 == 2) {
      uVar20 = (int)(uVar20 - uVar31) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar31) / iVar10;
    }
    if ((uVar12 == uVar36) || (iVar10 == 1)) {
      uVar12 = uVar12 - uVar36;
    }
    else if (iVar10 == 2) {
      uVar12 = (int)(uVar12 - uVar36) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar36) / iVar10;
    }
    if ((uVar7 == uVar32) || (iVar17 == 1)) {
      iVar33 = (uVar26 & 0xffff) - (uint)uVar32;
    }
    else if (iVar17 == 2) {
      iVar33 = (int)((uVar26 & 0xffff) - (uint)uVar32) >> 1;
    }
    else {
      iVar33 = (int)((uVar26 & 0xffff) - (uint)uVar32) / iVar17;
    }
    uVar23 = (uint)uVar32;
    uVar14 = uVar14 & 0xffff;
    if ((sStack_20 == sStack_60) || (iVar17 == 1)) {
      uVar14 = uVar14 - (uVar11 & 0xffff);
    }
    else if (iVar17 == 2) {
      uVar14 = (int)(uVar14 - (uVar11 & 0xffff)) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - (uVar11 & 0xffff)) / iVar17;
    }
    uVar26 = uVar11 & 0xffff;
    DAT_1008d2d4 = (iVar33 << 0x10 | uVar14 & 0xffff) + (uVar14 & 0x8000) * -2;
    uVar14 = (int)uStack_2c >> 0x10;
    if ((uVar6 == uVar32) || (iVar10 == 1)) {
      iVar33 = (uVar14 & 0xffff) - uVar23;
    }
    else if (iVar10 == 2) {
      iVar33 = (int)((uVar14 & 0xffff) - uVar23) >> 1;
    }
    else {
      iVar33 = (int)((uVar14 & 0xffff) - uVar23) / iVar10;
    }
    uStack_2c = uStack_2c & 0xffff;
    if ((sStack_54 == sStack_60) || (iVar10 == 1)) {
      uStack_2c = uStack_2c - uVar26;
    }
    else if (iVar10 == 2) {
      uStack_2c = (int)(uStack_2c - uVar26) >> 1;
    }
    else {
      uStack_2c = (int)(uStack_2c - uVar26) / iVar10;
    }
    DAT_1008d2d0 = (iVar33 << 0x10 | uStack_2c & 0xffff) + (uStack_2c & 0x8000) * -2;
    if ((uVar8 == uVar9) || (iVar17 == 1)) {
      iVar33 = (uVar30 & 0xffff) - (uVar15 & 0xffff);
    }
    else if (iVar17 == 2) {
      iVar33 = (int)((uVar30 & 0xffff) - (uVar15 & 0xffff)) >> 1;
    }
    else {
      iVar33 = (int)((uVar30 & 0xffff) - (uVar15 & 0xffff)) / iVar17;
    }
    uVar23 = uVar28 & 0xffff | 0x100;
    if ((sStack_1c == sStack_58) || (iVar17 == 1)) {
      uVar23 = uVar23 - (uVar22 & 0xffff | 0x100);
    }
    else if (iVar17 == 2) {
      uVar23 = (int)(uVar23 - (uVar22 & 0xffff | 0x100)) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - (uVar22 & 0xffff | 0x100)) / iVar17;
    }
    uVar14 = uVar22 & 0xffff | 0x100;
    DAT_1008d2e0 = (iVar33 << 0x10 | uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
    uVar22 = uVar25 & 0xffff | 0x100;
    if ((sStack_50 == sStack_58) || (iVar10 == 1)) {
      uVar22 = uVar22 - uVar14;
    }
    else if (iVar10 == 2) {
      uVar22 = (int)(uVar22 - uVar14) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar14) / iVar10;
    }
    DAT_1008d2dc = (uVar22 & 0xffff) + (uVar22 & 0x8000) * -2;
    DAT_1008d2c0 = (uVar36 & 0xfffe) << 0xf | (uVar31 & 0xfffe) >> 1;
    DAT_1008d2c8 = (uVar13 & 0xfffe) << 0xf | (uVar37 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar12 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1008d2cc = uVar11;
    DAT_1008d2d8 = uVar24;
    iStack_84 = iVar10;
    iVar3 = iVar21;
    iVar33 = DAT_1008d280;
    DAT_1008d280 = iVar34;
  }
  DAT_1008d284 = DAT_1008d280 << 0x10;
  DAT_1008d280 = iVar33 << 0x10;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar3;
LAB_10016dc6:
  DAT_1008d290 = iStack_84;
  FUN_1007953c();
  return;
}


