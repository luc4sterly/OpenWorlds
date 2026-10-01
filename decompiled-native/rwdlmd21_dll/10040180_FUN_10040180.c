// 10040180 FUN_10040180 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10040180(int *param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  ushort uVar16;
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
  
  iVar17 = param_3;
  iVar19 = param_4;
  iVar21 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar17 = param_2;
      iVar19 = param_3;
      iVar21 = param_4;
    }
LAB_100401c6:
    param_4 = iVar17;
    param_2 = iVar19;
    param_3 = iVar21;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_100401c6;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  iStack_64 = (int)*(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar24 = *(int *)(param_2 + 100) >> 3;
  uVar22 = *(int *)(param_2 + 0x68) >> 3;
  uVar23 = *(int *)(param_2 + 0x5c) >> 8;
  uVar3 = (*(uint *)(param_2 + 0x58) & 0xffffff00) << 8 | uVar23;
  iVar17 = (int)*(short *)(param_3 + 0x1a);
  uVar4 = *(int *)(param_2 + 0x60) >> 8;
  uVar25 = *(int *)(param_3 + 100) >> 3;
  uVar18 = *(int *)(param_3 + 0x68) >> 3;
  uStack_28 = *(int *)(param_3 + 0x5c) >> 8;
  uVar5 = (*(uint *)(param_3 + 0x58) & 0xffffff00) << 8 | uStack_28;
  iVar19 = (int)*(short *)(param_4 + 0x1a);
  uVar6 = *(int *)(param_3 + 0x60) >> 8;
  uVar27 = *(int *)(param_4 + 100) >> 3;
  uVar26 = *(int *)(param_4 + 0x68) >> 3;
  uVar20 = *(int *)(param_4 + 0x5c) >> 8;
  uVar7 = (*(uint *)(param_4 + 0x58) & 0xffffff00) << 8 | uVar20;
  uVar8 = *(int *)(param_4 + 0x60) >> 8;
  iVar21 = DAT_1008723c + 0x1000;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  uStack_54._0_2_ = (short)((uint)*(int *)(param_2 + 0x5c) >> 8);
  sStack_24 = (short)((uint)*(int *)(param_4 + 0x5c) >> 8);
  sStack_3c = (short)((uint)*(int *)(param_3 + 0x60) >> 8);
  sStack_14 = (short)((uint)*(int *)(param_4 + 0x60) >> 8);
  sStack_40 = (short)((uint)*(int *)(param_3 + 0x5c) >> 8);
  sStack_44 = (short)((uint)*(int *)(param_2 + 0x60) >> 8);
  uVar1 = (ushort)(uVar3 >> 0x10);
  uVar11 = (int)uVar7 >> 0x10;
  uVar16 = (ushort)(uVar5 >> 0x10);
  uVar2 = (ushort)(uVar7 >> 0x10);
  if (iStack_64 < 1) {
    iVar13 = DAT_1008d280 - iVar17;
    if (iVar13 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iStack_64 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_64 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar9 = iVar19 - iVar17;
    if (iStack_64 == 1) {
      DAT_1008d28c = iVar9 * 0x10000;
    }
    else if (iStack_64 == 2) {
      DAT_1008d28c = iVar9 * 0x8000;
    }
    else if (((iStack_64 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar21 + (iVar9 * 0x20 + iStack_64) * 4);
    }
    else if (iVar9 < 0) {
      DAT_1008d28c = (iVar9 * 0x10000) / iStack_64;
    }
    else {
      DAT_1008d28c = (iVar9 * 0x10000) / iStack_64;
    }
    iVar19 = iVar19 - DAT_1008d280;
    if (iStack_64 == 1) {
      DAT_1008d288 = iVar19 * 0x10000;
    }
    else if (iStack_64 == 2) {
      DAT_1008d288 = iVar19 * 0x8000;
    }
    else if (((iStack_64 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar21 + (iVar19 * 0x20 + iStack_64) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1008d288 = (iVar19 * 0x10000) / iStack_64;
    }
    else {
      DAT_1008d288 = (iVar19 * 0x10000) / iStack_64;
    }
    if ((uVar25 == uVar24) || (iVar13 == 1)) {
      uVar24 = uVar24 - uVar25;
    }
    else if (iVar13 == 2) {
      uVar24 = (int)(uVar24 - uVar25) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar25) / iVar13;
    }
    if ((uVar27 == uVar25) || (iStack_64 == 1)) {
      uVar27 = uVar27 - uVar25;
    }
    else if (iStack_64 == 2) {
      uVar27 = (int)(uVar27 - uVar25) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar25) / iStack_64;
    }
    if ((uVar18 == uVar22) || (iVar13 == 1)) {
      uVar22 = uVar22 - uVar18;
    }
    else if (iVar13 == 2) {
      uVar22 = (int)(uVar22 - uVar18) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar18) / iVar13;
    }
    if ((uVar26 == uVar18) || (iStack_64 == 1)) {
      uVar26 = uVar26 - uVar18;
    }
    else if (iStack_64 == 2) {
      uVar26 = (int)(uVar26 - uVar18) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar18) / iStack_64;
    }
    uVar3 = (int)uVar3 >> 0x10;
    if ((uVar1 == uVar16) || (iVar13 == 1)) {
      iVar19 = (uVar3 & 0xffff) - (uint)uVar16;
    }
    else if (iVar13 == 2) {
      iVar19 = (int)((uVar3 & 0xffff) - (uint)uVar16) >> 1;
    }
    else {
      iVar19 = (int)((uVar3 & 0xffff) - (uint)uVar16) / iVar13;
    }
    uVar7 = (uint)uVar16;
    if ((uVar2 == uVar16) || (iStack_64 == 1)) {
      iVar21 = (uVar11 & 0xffff) - uVar7;
    }
    else if (iStack_64 == 2) {
      iVar21 = (int)((uVar11 & 0xffff) - uVar7) >> 1;
    }
    else {
      iVar21 = (int)((uVar11 & 0xffff) - uVar7) / iStack_64;
    }
    uVar23 = uVar23 & 0xffff;
    if ((sStack_40 == (short)uStack_54) || (iVar13 == 1)) {
      uVar23 = uVar23 - (uStack_28 & 0xffff);
    }
    else if (iVar13 == 2) {
      uVar23 = (int)(uVar23 - (uStack_28 & 0xffff)) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - (uStack_28 & 0xffff)) / iVar13;
    }
    uStack_28 = uStack_28 & 0xffff;
    DAT_1008d2d4 = (iVar19 << 0x10 | uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
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
    DAT_1008d2d0 = (iVar21 << 0x10 | uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
    uVar4 = uVar4 & 0xffff;
    if ((sStack_3c == sStack_44) || (iVar13 == 1)) {
      uVar4 = uVar4 - (uVar6 & 0xffff);
    }
    else if (iVar13 == 2) {
      uVar4 = (int)(uVar4 - (uVar6 & 0xffff)) >> 1;
    }
    else {
      uVar4 = (int)(uVar4 - (uVar6 & 0xffff)) / iVar13;
    }
    uVar23 = uVar6 & 0xffff;
    DAT_1008d2e0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
    uVar8 = uVar8 & 0xffff;
    if ((sStack_14 == sStack_3c) || (iStack_64 == 1)) {
      uVar8 = uVar8 - uVar23;
    }
    else if (iStack_64 == 2) {
      uVar8 = (int)(uVar8 - uVar23) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - uVar23) / iStack_64;
    }
    DAT_1008d2dc = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d2c0 = (uVar18 & 0xfffe) << 0xf | (uVar25 & 0xfffe) >> 1;
    DAT_1008d2c8 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
    DAT_1008d2cc = uVar5;
    DAT_1008d2d8 = uVar6;
  }
  else {
    iVar9 = iVar17 - DAT_1008d280;
    iVar13 = iStack_64;
    if (iStack_64 == 1) {
      DAT_1008d28c = iVar9 * 0x10000;
    }
    else if (iStack_64 == 2) {
      DAT_1008d28c = iVar9 * 0x8000;
    }
    else if (((iStack_64 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar21 + (iVar9 * 0x20 + iStack_64) * 4);
      iVar13 = iVar21;
    }
    else if (iVar9 < 0) {
      DAT_1008d28c = (iVar9 * 0x10000) / iStack_64;
      iVar13 = (iVar9 * 0x10000) % iStack_64;
    }
    else {
      DAT_1008d28c = (iVar9 * 0x10000) / iStack_64;
      iVar13 = (iVar9 * 0x10000) % iStack_64;
    }
    iVar9 = (int)*(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (iVar9 < 1) {
      iVar13 = iVar19 - DAT_1008d280;
      if (iVar13 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar17 = iVar17 - iVar19;
      if (iStack_64 == 1) {
        DAT_1008d288 = iVar17 * 0x10000;
      }
      else if (iStack_64 == 2) {
        DAT_1008d288 = iVar17 * 0x8000;
      }
      else if (((iStack_64 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar21 + (iVar17 * 0x20 + iStack_64) * 4);
      }
      else if (iVar17 < 0) {
        DAT_1008d288 = (iVar17 * 0x10000) / iStack_64;
      }
      else {
        DAT_1008d288 = (iVar17 * 0x10000) / iStack_64;
      }
      if ((uVar27 == uVar24) || (iVar13 == 1)) {
        uVar27 = uVar27 - uVar24;
      }
      else if (iVar13 == 2) {
        uVar27 = (int)(uVar27 - uVar24) >> 1;
      }
      else {
        uVar27 = (int)(uVar27 - uVar24) / iVar13;
      }
      if ((uVar26 == uVar22) || (iVar13 == 1)) {
        uVar26 = uVar26 - uVar22;
      }
      else if (iVar13 == 2) {
        uVar26 = (int)(uVar26 - uVar22) >> 1;
      }
      else {
        uVar26 = (int)(uVar26 - uVar22) / iVar13;
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
      if ((uVar1 == uVar2) || (iVar13 == 1)) {
        iVar17 = (uVar11 & 0xffff) - (uint)uVar1;
      }
      else if (iVar13 == 2) {
        iVar17 = (int)((uVar11 & 0xffff) - (uint)uVar1) >> 1;
      }
      else {
        iVar17 = (int)((uVar11 & 0xffff) - (uint)uVar1) / iVar13;
      }
      uVar7 = (uint)uVar1;
      uVar20 = uVar20 & 0xffff;
      if ((sStack_24 == (short)uStack_54) || (iVar13 == 1)) {
        uVar20 = uVar20 - (uVar23 & 0xffff);
      }
      else if (iVar13 == 2) {
        uVar20 = (int)(uVar20 - (uVar23 & 0xffff)) >> 1;
      }
      else {
        uVar20 = (int)(uVar20 - (uVar23 & 0xffff)) / iVar13;
      }
      uVar23 = uVar23 & 0xffff;
      DAT_1008d2d4 = (iVar17 << 0x10 | uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
      uVar5 = (int)uVar5 >> 0x10;
      if ((uVar1 == uVar16) || (iStack_64 == 1)) {
        iVar17 = (uVar5 & 0xffff) - uVar7;
      }
      else if (iStack_64 == 2) {
        iVar17 = (int)((uVar5 & 0xffff) - uVar7) >> 1;
      }
      else {
        iVar17 = (int)((uVar5 & 0xffff) - uVar7) / iStack_64;
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
      DAT_1008d2d0 = (iVar17 << 0x10 | uStack_28 & 0xffff) + (uStack_28 & 0x8000) * -2;
      uVar8 = uVar8 & 0xffff;
      if ((sStack_14 == sStack_44) || (iVar13 == 1)) {
        uVar8 = uVar8 - (uVar4 & 0xffff);
      }
      else if (iVar13 == 2) {
        uVar8 = (int)(uVar8 - (uVar4 & 0xffff)) >> 1;
      }
      else {
        uVar8 = (int)(uVar8 - (uVar4 & 0xffff)) / iVar13;
      }
      uVar23 = uVar4 & 0xffff;
      DAT_1008d2e0 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      uVar6 = uVar6 & 0xffff;
      if ((sStack_3c == sStack_44) || (iStack_64 == 1)) {
        uVar6 = uVar6 - uVar23;
      }
      else if (iStack_64 == 2) {
        uVar6 = (int)(uVar6 - uVar23) >> 1;
      }
      else {
        uVar6 = (int)(uVar6 - uVar23) / iStack_64;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d2dc = (uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
      DAT_1008d284 = iVar19 << 0x10;
      DAT_1008d2c0 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar26 & 0xfffe) << 0xf | (uVar27 & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar25 & 0xfffe) >> 1 | (uVar18 & 0xfffe) << 0xf;
      DAT_1008d2cc = uVar3;
      DAT_1008d2d8 = uVar4;
      goto LAB_100415cf;
    }
    iVar10 = iVar19 - DAT_1008d280;
    if (iVar9 == 1) {
      DAT_1008d288 = iVar10 * 0x10000;
    }
    else if (iVar9 == 2) {
      DAT_1008d288 = iVar10 * 0x8000;
    }
    else if (((iVar9 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar21 + (iVar10 * 0x20 + iVar9) * 4);
      iVar13 = iVar21;
    }
    else if (iVar10 < 0) {
      DAT_1008d288 = (iVar10 * 0x10000) / iVar9;
      iVar13 = (iVar10 * 0x10000) % iVar9;
    }
    else {
      DAT_1008d288 = (iVar10 * 0x10000) / iVar9;
      iVar13 = (iVar10 * 0x10000) % iVar9;
    }
    uVar7 = DAT_1008d288 - DAT_1008d28c;
    if ((int)uVar7 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    if ((uVar25 == uVar24) || (iStack_64 == 1)) {
      uVar11 = uVar25 - uVar24;
    }
    else if (iStack_64 == 2) {
      uVar11 = (int)(uVar25 - uVar24) >> 1;
    }
    else {
      uVar11 = (int)(uVar25 - uVar24) / iStack_64;
      iVar13 = (int)(uVar25 - uVar24) % iStack_64;
    }
    if ((uVar18 == uVar22) || (iStack_64 == 1)) {
      uVar5 = uVar18 - uVar22;
    }
    else if (iStack_64 == 2) {
      uVar5 = (int)(uVar18 - uVar22) >> 1;
    }
    else {
      uVar5 = (int)(uVar18 - uVar22) / iStack_64;
      iVar13 = (int)(uVar18 - uVar22) % iStack_64;
    }
    if ((uVar27 == uVar24) || (iVar9 == 1)) {
      iVar10 = uVar27 - uVar24;
    }
    else if (iVar9 == 2) {
      iVar10 = (int)(uVar27 - uVar24) >> 1;
    }
    else {
      iVar10 = (int)(uVar27 - uVar24) / iVar9;
      iVar13 = (int)(uVar27 - uVar24) % iVar9;
    }
    iVar10 = iVar10 - uVar11;
    uVar28 = CONCAT44(iVar13,iVar10);
    if (iVar10 != 0) {
      uVar28 = FUN_1006a324(iVar10,iVar13,iVar10,uVar7);
    }
    iVar13 = (int)((ulonglong)uVar28 >> 0x20);
    uStack_20 = (uint)uVar28;
    if ((uVar26 == uVar22) || (iVar9 == 1)) {
      iVar10 = uVar26 - uVar22;
    }
    else if (iVar9 == 2) {
      iVar10 = (int)(uVar26 - uVar22) >> 1;
    }
    else {
      iVar10 = (int)(uVar26 - uVar22) / iVar9;
      iVar13 = (int)(uVar26 - uVar22) % iVar9;
    }
    iVar10 = iVar10 - uVar5;
    uVar12 = 0;
    if (iVar10 != 0) {
      uVar28 = FUN_1006a324(iVar10,iVar13,iVar10,uVar7);
      uVar12 = (uint)uVar28;
    }
    if ((uVar1 == uVar16) || (iStack_64 == 1)) {
      iVar13 = (uint)uVar16 - (uint)uVar1;
    }
    else if (iStack_64 == 2) {
      iVar13 = (int)((uint)uVar16 - (uint)uVar1) >> 1;
    }
    else {
      iVar13 = (int)((uint)uVar16 - (uint)uVar1) / iStack_64;
    }
    uStack_2c = (uint)uVar16;
    uVar15 = (uint)uVar1;
    if ((sStack_40 == (short)uStack_54) || (iStack_64 == 1)) {
      uVar14 = (uStack_28 & 0xffff) - (uVar23 & 0xffff);
    }
    else if (iStack_64 == 2) {
      uVar14 = (int)((uStack_28 & 0xffff) - (uVar23 & 0xffff)) >> 1;
    }
    else {
      uVar14 = (int)((uStack_28 & 0xffff) - (uVar23 & 0xffff)) / iStack_64;
    }
    uStack_28 = uStack_28 & 0xffff;
    uVar23 = uVar23 & 0xffff;
    DAT_1008d2d0 = (iVar13 << 0x10 | uVar14 & 0xffff) + (uVar14 & 0x8000) * -2;
    if ((uVar1 == uVar2) || (iVar9 == 1)) {
      iVar13 = uVar2 - uVar15;
    }
    else if (iVar9 == 2) {
      iVar13 = (int)(uVar2 - uVar15) >> 1;
    }
    else {
      iVar13 = (int)(uVar2 - uVar15) / iVar9;
    }
    uStack_48 = (uint)uVar2;
    DAT_1008d2d4 = iVar13 - (DAT_1008d2d0 >> 0x10);
    if (DAT_1008d2d4 != 0) {
      DAT_1008d2d4 = (int)(DAT_1008d2d4 * 0x10000) / (int)uVar7 << 0x10;
    }
    if ((sStack_24 == (short)uStack_54) || (iVar9 == 1)) {
      iVar13 = (uVar20 & 0xffff) - uVar23;
    }
    else if (iVar9 == 2) {
      iVar13 = (int)((uVar20 & 0xffff) - uVar23) >> 1;
    }
    else {
      iVar13 = (int)((uVar20 & 0xffff) - uVar23) / iVar9;
    }
    uVar20 = uVar20 & 0xffff;
    if (iVar13 - (short)DAT_1008d2d0 != 0) {
      uVar23 = DAT_1008d2d4 | ((iVar13 - (short)DAT_1008d2d0) * 0x10000) / (int)uVar7 & 0xffffU;
      DAT_1008d2d4 = uVar23 + (uVar23 & 0x8000) * -2;
    }
    uVar23 = uVar4 & 0xffff;
    if ((sStack_3c == sStack_44) || (iStack_64 == 1)) {
      uVar15 = (uVar6 & 0xffff) - uVar23;
    }
    else if (iStack_64 == 2) {
      uVar15 = (int)((uVar6 & 0xffff) - uVar23) >> 1;
    }
    else {
      uVar15 = (int)((uVar6 & 0xffff) - uVar23) / iStack_64;
    }
    uStack_54 = uVar6 & 0xffff;
    DAT_1008d2e0 = 0;
    DAT_1008d2dc = (uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    if ((sStack_14 == sStack_44) || (iVar9 == 1)) {
      iVar13 = (uVar8 & 0xffff) - uVar23;
    }
    else if (iVar9 == 2) {
      iVar13 = (int)((uVar8 & 0xffff) - uVar23) >> 1;
    }
    else {
      iVar13 = (int)((uVar8 & 0xffff) - uVar23) / iVar9;
    }
    uVar8 = uVar8 & 0xffff;
    if (iVar13 - (short)DAT_1008d2dc != 0) {
      uVar7 = ((iVar13 - (short)DAT_1008d2dc) * 0x10000) / (int)uVar7;
      DAT_1008d2e0 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
    }
    DAT_1008d280 = DAT_1008d280 << 0x10;
    DAT_1008d284 = DAT_1008d280;
    if (iVar9 <= iStack_64) {
      DAT_1008d2c0 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar12 & 0xfffe) << 0xf | (uStack_20 & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar11 & 0xfffe) >> 1 | (uVar5 & 0xfffe) << 0xf;
      iStack_64 = iStack_64 - iVar9;
      DAT_1008d290 = iVar9;
      DAT_1008d2cc = uVar3;
      DAT_1008d2d8 = uVar4;
      FUN_100415f0((uint *)&DAT_1008d280);
      if (iStack_64 == 0) {
        return;
      }
      DAT_1008d284 = iVar19 << 0x10;
      iVar17 = iVar17 - iVar19;
      if (iStack_64 == 1) {
        DAT_1008d288 = iVar17 * 0x10000;
      }
      else if (iStack_64 == 2) {
        DAT_1008d288 = iVar17 * 0x8000;
      }
      else if (((iStack_64 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar21 + (iVar17 * 0x20 + iStack_64) * 4);
      }
      else if (iVar17 < 0) {
        DAT_1008d288 = (iVar17 * 0x10000) / iStack_64;
      }
      else {
        DAT_1008d288 = (iVar17 * 0x10000) / iStack_64;
      }
      goto LAB_100415cf;
    }
    DAT_1008d2c0 = (uVar22 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
    uVar23 = (uVar12 & 0xfffe) << 0xf | (uStack_20 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar11 & 0xfffe) >> 1 | (uVar5 & 0xfffe) << 0xf;
    iVar9 = iVar9 - iStack_64;
    DAT_1008d290 = iStack_64;
    DAT_1008d2c8 = uVar23;
    DAT_1008d2cc = uVar3;
    DAT_1008d2d8 = uVar4;
    FUN_100415f0((uint *)&DAT_1008d280);
    iVar19 = iVar19 - iVar17;
    if (iVar9 == 1) {
      DAT_1008d28c = iVar19 * 0x10000;
    }
    else if (iVar9 == 2) {
      DAT_1008d28c = iVar19 * 0x8000;
    }
    else if (((iVar9 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar21 + (iVar19 * 0x20 + iVar9) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1008d28c = (iVar19 * 0x10000) / iVar9;
    }
    else {
      DAT_1008d28c = (iVar19 * 0x10000) / iVar9;
    }
    if ((uVar27 == uVar25) || (iVar9 == 1)) {
      uVar27 = uVar27 - uVar25;
    }
    else if (iVar9 == 2) {
      uVar27 = (int)(uVar27 - uVar25) >> 1;
    }
    else {
      uVar27 = (int)(uVar27 - uVar25) / iVar9;
    }
    if ((uVar26 == uVar18) || (iVar9 == 1)) {
      uVar26 = uVar26 - uVar18;
    }
    else if (iVar9 == 2) {
      uVar26 = (int)(uVar26 - uVar18) >> 1;
    }
    else {
      uVar26 = (int)(uVar26 - uVar18) / iVar9;
    }
    if ((uVar2 == uVar16) || (iVar9 == 1)) {
      iVar19 = uStack_48 - uStack_2c;
    }
    else if (iVar9 == 2) {
      iVar19 = (int)(uStack_48 - uStack_2c) >> 1;
    }
    else {
      iVar19 = (int)(uStack_48 - uStack_2c) / iVar9;
    }
    DAT_1008d2d0 = iVar19 << 0x10;
    if ((sStack_24 == sStack_40) || (iVar9 == 1)) {
      uVar20 = uVar20 - uStack_28;
    }
    else if (iVar9 == 2) {
      uVar20 = (int)(uVar20 - uStack_28) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uStack_28) / iVar9;
    }
    if (uVar20 != 0) {
      DAT_1008d2d0 = (DAT_1008d2d0 | uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
    }
    DAT_1008d2dc = 0;
    if ((sStack_14 == sStack_3c) || (iVar9 == 1)) {
      uVar8 = uVar8 - uStack_54;
    }
    else if (iVar9 == 2) {
      uVar8 = (int)(uVar8 - uStack_54) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - uStack_54) / iVar9;
    }
    DAT_1008d2c8 = uVar23;
    iStack_64 = iVar9;
    if (uVar8 != 0) {
      DAT_1008d2dc = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    }
  }
  DAT_1008d280 = iVar17 << 0x10;
  DAT_1008d2c4 = (uVar27 & 0xfffe) >> 1 | (uVar26 & 0xfffe) << 0xf;
LAB_100415cf:
  DAT_1008d290 = iStack_64;
  FUN_100415f0((uint *)&DAT_1008d280);
  return;
}


