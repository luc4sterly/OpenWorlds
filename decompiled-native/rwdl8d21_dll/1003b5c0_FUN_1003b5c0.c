// 1003b5c0 FUN_1003b5c0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1003b5c0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  undefined8 uVar25;
  int iStack_54;
  short sStack_3c;
  short sStack_2c;
  uint uStack_20;
  uint uStack_1c;
  short sStack_c;
  
  iVar1 = param_3;
  iVar15 = param_4;
  iVar21 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      iVar15 = param_3;
      iVar21 = param_4;
    }
LAB_1003b605:
    param_4 = iVar1;
    param_2 = iVar15;
    param_3 = iVar21;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1003b605;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar2 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar16 = *(int *)(param_2 + 0x68) >> 3;
  uVar20 = *(int *)(param_2 + 100) >> 3;
  iVar1 = *(int *)(param_2 + 0x20);
  uVar3 = *(int *)(param_2 + 0x58) >> 8;
  iVar17 = (int)*(short *)(param_3 + 0x1a);
  uVar23 = *(int *)(param_3 + 100) >> 3;
  uVar18 = *(int *)(param_3 + 0x68) >> 3;
  iVar21 = *(int *)(param_3 + 0x20);
  uStack_20 = *(int *)(param_3 + 0x58) >> 8;
  uVar22 = *(int *)(param_4 + 100) >> 3;
  iVar19 = (int)*(short *)(param_4 + 0x1a);
  uVar24 = *(int *)(param_4 + 0x68) >> 3;
  iVar15 = *(int *)(param_4 + 0x20);
  uVar4 = *(int *)(param_4 + 0x58) >> 8;
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2a0 = DAT_10077eb0;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar5 = DAT_10075214 + 0x1000;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  sStack_c = (short)((uint)*(int *)(param_4 + 0x58) >> 8);
  sStack_2c = (short)((uint)*(int *)(param_3 + 0x58) >> 8);
  sStack_3c = (short)((uint)*(int *)(param_2 + 0x58) >> 8);
  if (iVar2 < 1) {
    iVar2 = DAT_1007b280 - iVar17;
    if (iVar2 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iStack_54 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_54 == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar6 = iVar19 - iVar17;
    if (iStack_54 == 1) {
      DAT_1007b28c = iVar6 * 0x10000;
    }
    else if (iStack_54 == 2) {
      DAT_1007b28c = iVar6 * 0x8000;
    }
    else if (((iStack_54 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar5 + (iVar6 * 0x20 + iStack_54) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b28c = (iVar6 * 0x10000) / iStack_54;
    }
    else {
      DAT_1007b28c = (iVar6 * 0x10000) / iStack_54;
    }
    iVar19 = iVar19 - DAT_1007b280;
    if (iStack_54 == 1) {
      DAT_1007b288 = iVar19 * 0x10000;
    }
    else if (iStack_54 == 2) {
      DAT_1007b288 = iVar19 * 0x8000;
    }
    else if (((iStack_54 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar5 + (iVar19 * 0x20 + iStack_54) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1007b288 = (iVar19 * 0x10000) / iStack_54;
    }
    else {
      DAT_1007b288 = (iVar19 * 0x10000) / iStack_54;
    }
    if ((iVar21 == iVar1) || (iVar2 == 1)) {
      DAT_1007b2ec = iVar1 - iVar21;
    }
    else if (iVar2 == 2) {
      DAT_1007b2ec = iVar1 - iVar21 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar1 - iVar21) / iVar2;
    }
    if ((iVar15 == iVar21) || (iStack_54 == 1)) {
      DAT_1007b2e8 = iVar15 - iVar21;
    }
    else if (iStack_54 == 2) {
      DAT_1007b2e8 = iVar15 - iVar21 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar15 - iVar21) / iStack_54;
    }
    if ((uVar23 == uVar20) || (iVar2 == 1)) {
      uVar20 = uVar20 - uVar23;
    }
    else if (iVar2 == 2) {
      uVar20 = (int)(uVar20 - uVar23) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar23) / iVar2;
    }
    if ((uVar22 == uVar23) || (iStack_54 == 1)) {
      uVar22 = uVar22 - uVar23;
    }
    else if (iStack_54 == 2) {
      uVar22 = (int)(uVar22 - uVar23) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar23) / iStack_54;
    }
    if ((uVar18 == uVar16) || (iVar2 == 1)) {
      uVar16 = uVar16 - uVar18;
    }
    else if (iVar2 == 2) {
      uVar16 = (int)(uVar16 - uVar18) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar18) / iVar2;
    }
    if ((uVar24 == uVar18) || (iStack_54 == 1)) {
      uVar24 = uVar24 - uVar18;
    }
    else if (iStack_54 == 2) {
      uVar24 = (int)(uVar24 - uVar18) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar18) / iStack_54;
    }
    uVar3 = uVar3 & 0xffff;
    if ((sStack_2c == sStack_3c) || (iVar2 == 1)) {
      uVar3 = uVar3 - (uStack_20 & 0xffff);
    }
    else if (iVar2 == 2) {
      uVar3 = (int)(uVar3 - (uStack_20 & 0xffff)) >> 1;
    }
    else {
      uVar3 = (int)(uVar3 - (uStack_20 & 0xffff)) / iVar2;
    }
    uVar8 = uStack_20 & 0xffff;
    DAT_1007b2d4 = (uVar3 & 0xffff) + (uVar3 & 0x8000) * -2;
    uVar4 = uVar4 & 0xffff;
    if ((sStack_c == sStack_2c) || (iStack_54 == 1)) {
      uVar4 = uVar4 - uVar8;
    }
    else if (iStack_54 == 2) {
      uVar4 = (int)(uVar4 - uVar8) >> 1;
    }
    else {
      uVar4 = (int)(uVar4 - uVar8) / iStack_54;
    }
    DAT_1007b2d0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
    DAT_1007b2c0 = (uVar18 & 0xfffe) << 0xf | (uVar23 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar16 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar24 & 0xfffe) << 0xf | (uVar22 & 0xfffe) >> 1;
    DAT_1007b2cc = uStack_20;
  }
  else {
    iVar6 = iVar17 - DAT_1007b280;
    if (iVar2 == 1) {
      DAT_1007b28c = iVar6 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b28c = iVar6 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar5 + (iVar6 * 0x20 + iVar2) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b28c = (iVar6 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b28c = (iVar6 * 0x10000) / iVar2;
    }
    iVar6 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (0 < iVar6) {
      iVar7 = iVar19 - DAT_1007b280;
      iVar13 = iVar6;
      if (iVar6 == 1) {
        DAT_1007b288 = iVar7 * 0x10000;
      }
      else if (iVar6 == 2) {
        DAT_1007b288 = iVar7 * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar5 + (iVar7 * 0x20 + iVar6) * 4);
        iVar13 = iVar5;
      }
      else if (iVar7 < 0) {
        DAT_1007b288 = (iVar7 * 0x10000) / iVar6;
        iVar13 = (iVar7 * 0x10000) % iVar6;
      }
      else {
        DAT_1007b288 = (iVar7 * 0x10000) / iVar6;
        iVar13 = (iVar7 * 0x10000) % iVar6;
      }
      uVar8 = DAT_1007b288 - DAT_1007b28c;
      if ((int)uVar8 < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        return;
      }
      if ((uVar23 == uVar20) || (iVar2 == 1)) {
        uVar9 = uVar23 - uVar20;
      }
      else if (iVar2 == 2) {
        uVar9 = (int)(uVar23 - uVar20) >> 1;
      }
      else {
        uVar9 = (int)(uVar23 - uVar20) / iVar2;
        iVar13 = (int)(uVar23 - uVar20) % iVar2;
      }
      if ((uVar18 == uVar16) || (iVar2 == 1)) {
        uVar10 = uVar18 - uVar16;
      }
      else if (iVar2 == 2) {
        uVar10 = (int)(uVar18 - uVar16) >> 1;
      }
      else {
        uVar10 = (int)(uVar18 - uVar16) / iVar2;
        iVar13 = (int)(uVar18 - uVar16) % iVar2;
      }
      if ((uVar22 == uVar20) || (iVar6 == 1)) {
        iVar7 = uVar22 - uVar20;
      }
      else if (iVar6 == 2) {
        iVar7 = (int)(uVar22 - uVar20) >> 1;
      }
      else {
        iVar7 = (int)(uVar22 - uVar20) / iVar6;
        iVar13 = (int)(uVar22 - uVar20) % iVar6;
      }
      iVar7 = iVar7 - uVar9;
      uVar25 = CONCAT44(iVar13,iVar7);
      if (iVar7 != 0) {
        uVar25 = FUN_10063324(iVar7,iVar13,iVar7,uVar8);
      }
      iVar13 = (int)((ulonglong)uVar25 >> 0x20);
      uStack_1c = (uint)uVar25;
      if ((uVar24 == uVar16) || (iVar6 == 1)) {
        iVar7 = uVar24 - uVar16;
      }
      else if (iVar6 == 2) {
        iVar7 = (int)(uVar24 - uVar16) >> 1;
      }
      else {
        iVar7 = (int)(uVar24 - uVar16) / iVar6;
        iVar13 = (int)(uVar24 - uVar16) % iVar6;
      }
      iVar7 = iVar7 - uVar10;
      uVar11 = 0;
      if (iVar7 != 0) {
        uVar25 = FUN_10063324(iVar7,iVar13,iVar7,uVar8);
        uVar11 = (uint)uVar25;
      }
      uVar14 = uVar3 & 0xffff;
      if ((sStack_2c == sStack_3c) || (iVar2 == 1)) {
        uVar12 = (uStack_20 & 0xffff) - uVar14;
      }
      else if (iVar2 == 2) {
        uVar12 = (int)((uStack_20 & 0xffff) - uVar14) >> 1;
      }
      else {
        uVar12 = (int)((uStack_20 & 0xffff) - uVar14) / iVar2;
      }
      uStack_20 = uStack_20 & 0xffff;
      DAT_1007b2d4 = 0;
      DAT_1007b2d0 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
      if ((sStack_c == sStack_3c) || (iVar6 == 1)) {
        iVar13 = (uVar4 & 0xffff) - uVar14;
      }
      else if (iVar6 == 2) {
        iVar13 = (int)((uVar4 & 0xffff) - uVar14) >> 1;
      }
      else {
        iVar13 = (int)((uVar4 & 0xffff) - uVar14) / iVar6;
      }
      uVar4 = uVar4 & 0xffff;
      if (iVar13 - (short)DAT_1007b2d0 != 0) {
        uVar14 = ((iVar13 - (short)DAT_1007b2d0) * 0x10000) / (int)uVar8;
        DAT_1007b2d4 = (uVar14 & 0xffff) + (uVar14 & 0x8000) * -2;
      }
      if ((iVar21 == iVar1) || (iVar2 == 1)) {
        DAT_1007b2e8 = iVar21 - iVar1;
      }
      else if (iVar2 == 2) {
        DAT_1007b2e8 = iVar21 - iVar1 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar21 - iVar1) / iVar2;
      }
      if ((iVar15 == iVar1) || (iVar6 == 1)) {
        iVar13 = iVar15 - iVar1;
      }
      else if (iVar6 == 2) {
        iVar13 = iVar15 - iVar1 >> 1;
      }
      else {
        iVar13 = (iVar15 - iVar1) / iVar6;
      }
      DAT_1007b2ec = iVar13 - DAT_1007b2e8;
      if ((DAT_1007b2ec != 0) && ((int)uVar8 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / ((int)uVar8 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar2 < iVar6) {
        DAT_1007b2c0 = (uVar16 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
        uVar20 = (uVar11 & 0xfffe) << 0xf | (uStack_1c & 0xfffe) >> 1;
        iStack_54 = iVar6 - iVar2;
        DAT_1007b2c4 = (uVar10 & 0xfffe) << 0xf | (uVar9 & 0xfffe) >> 1;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar2;
        DAT_1007b2c8 = uVar20;
        DAT_1007b2cc = uVar3;
        FUN_1003c670((uint *)&DAT_1007b280);
        DAT_1007b280 = iVar17 << 0x10;
        iVar19 = iVar19 - iVar17;
        if (iStack_54 == 1) {
          DAT_1007b28c = iVar19 * 0x10000;
        }
        else if (iStack_54 == 2) {
          DAT_1007b28c = iVar19 * 0x8000;
        }
        else if (((iStack_54 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar5 + (iVar19 * 0x20 + iStack_54) * 4);
        }
        else if (iVar19 < 0) {
          DAT_1007b28c = (iVar19 * 0x10000) / iStack_54;
        }
        else {
          DAT_1007b28c = (iVar19 * 0x10000) / iStack_54;
        }
        if ((uVar22 == uVar23) || (iStack_54 == 1)) {
          uVar22 = uVar22 - uVar23;
        }
        else if (iStack_54 == 2) {
          uVar22 = (int)(uVar22 - uVar23) >> 1;
        }
        else {
          uVar22 = (int)(uVar22 - uVar23) / iStack_54;
        }
        if ((uVar24 == uVar18) || (iStack_54 == 1)) {
          uVar24 = uVar24 - uVar18;
        }
        else if (iStack_54 == 2) {
          uVar24 = (int)(uVar24 - uVar18) >> 1;
        }
        else {
          uVar24 = (int)(uVar24 - uVar18) / iStack_54;
        }
        DAT_1007b2d0 = 0;
        if ((sStack_c == sStack_2c) || (iStack_54 == 1)) {
          uVar4 = uVar4 - uStack_20;
        }
        else if (iStack_54 == 2) {
          uVar4 = (int)(uVar4 - uStack_20) >> 1;
        }
        else {
          uVar4 = (int)(uVar4 - uStack_20) / iStack_54;
        }
        if (uVar4 != 0) {
          DAT_1007b2d0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
        }
        if ((iVar15 == iVar21) || (iStack_54 == 1)) {
          DAT_1007b2e8 = iVar15 - iVar21;
        }
        else if (iStack_54 == 2) {
          DAT_1007b2e8 = iVar15 - iVar21 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar15 - iVar21) / iStack_54;
        }
        DAT_1007b2c4 = (uVar24 & 0xfffe) << 0xf | (uVar22 & 0xfffe) >> 1;
        DAT_1007b2c8 = uVar20;
      }
      else {
        DAT_1007b2c0 = (uVar16 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
        DAT_1007b2c8 = (uVar11 & 0xfffe) << 0xf | (uStack_1c & 0xfffe) >> 1;
        DAT_1007b2c4 = (uVar10 & 0xfffe) << 0xf | (uVar9 & 0xfffe) >> 1;
        iStack_54 = iVar2 - iVar6;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar6;
        DAT_1007b2cc = uVar3;
        FUN_1003c670((uint *)&DAT_1007b280);
        if (iStack_54 == 0) {
          return;
        }
        DAT_1007b284 = iVar19 << 0x10;
        iVar17 = iVar17 - iVar19;
        if (iStack_54 == 1) {
          DAT_1007b288 = iVar17 * 0x10000;
        }
        else if (iStack_54 == 2) {
          DAT_1007b288 = iVar17 * 0x8000;
        }
        else if (((iStack_54 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar5 + (iVar17 * 0x20 + iStack_54) * 4);
        }
        else if (iVar17 < 0) {
          DAT_1007b288 = (iVar17 * 0x10000) / iStack_54;
        }
        else {
          DAT_1007b288 = (iVar17 * 0x10000) / iStack_54;
        }
      }
      goto LAB_1003c64a;
    }
    iVar6 = iVar19 - DAT_1007b280;
    if (iVar6 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar17 = iVar17 - iVar19;
    if (iVar2 == 1) {
      DAT_1007b288 = iVar17 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b288 = iVar17 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar5 + (iVar17 * 0x20 + iVar2) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1007b288 = (iVar17 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b288 = (iVar17 * 0x10000) / iVar2;
    }
    if ((iVar15 == iVar1) || (iVar6 == 1)) {
      DAT_1007b2ec = iVar15 - iVar1;
    }
    else if (iVar6 == 2) {
      DAT_1007b2ec = iVar15 - iVar1 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar15 - iVar1) / iVar6;
    }
    if ((iVar21 == iVar1) || (iVar2 == 1)) {
      DAT_1007b2e8 = iVar21 - iVar1;
    }
    else if (iVar2 == 2) {
      DAT_1007b2e8 = iVar21 - iVar1 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar21 - iVar1) / iVar2;
    }
    if ((uVar22 == uVar20) || (iVar6 == 1)) {
      uVar22 = uVar22 - uVar20;
    }
    else if (iVar6 == 2) {
      uVar22 = (int)(uVar22 - uVar20) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar20) / iVar6;
    }
    if ((uVar24 == uVar16) || (iVar6 == 1)) {
      uVar24 = uVar24 - uVar16;
    }
    else if (iVar6 == 2) {
      uVar24 = (int)(uVar24 - uVar16) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar16) / iVar6;
    }
    if ((uVar23 == uVar20) || (iVar2 == 1)) {
      uVar23 = uVar23 - uVar20;
    }
    else if (iVar2 == 2) {
      uVar23 = (int)(uVar23 - uVar20) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - uVar20) / iVar2;
    }
    if ((uVar18 == uVar16) || (iVar2 == 1)) {
      uVar18 = uVar18 - uVar16;
    }
    else if (iVar2 == 2) {
      uVar18 = (int)(uVar18 - uVar16) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar16) / iVar2;
    }
    uVar4 = uVar4 & 0xffff;
    if ((sStack_c == sStack_3c) || (iVar6 == 1)) {
      uVar4 = uVar4 - (uVar3 & 0xffff);
    }
    else if (iVar6 == 2) {
      uVar4 = (int)(uVar4 - (uVar3 & 0xffff)) >> 1;
    }
    else {
      uVar4 = (int)(uVar4 - (uVar3 & 0xffff)) / iVar6;
    }
    uVar8 = uVar3 & 0xffff;
    DAT_1007b2d4 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
    uStack_20 = uStack_20 & 0xffff;
    if ((sStack_2c == sStack_3c) || (iVar2 == 1)) {
      uStack_20 = uStack_20 - uVar8;
    }
    else if (iVar2 == 2) {
      uStack_20 = (int)(uStack_20 - uVar8) >> 1;
    }
    else {
      uStack_20 = (int)(uStack_20 - uVar8) / iVar2;
    }
    DAT_1007b2d0 = (uStack_20 & 0xffff) + (uStack_20 & 0x8000) * -2;
    DAT_1007b2c0 = (uVar16 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar24 & 0xfffe) << 0xf | (uVar22 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar18 & 0xfffe) << 0xf | (uVar23 & 0xfffe) >> 1;
    DAT_1007b2cc = uVar3;
    iStack_54 = iVar2;
    iVar21 = iVar1;
    iVar17 = DAT_1007b280;
    DAT_1007b280 = iVar19;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar17 << 0x10;
  DAT_1007b2e4 = DAT_1007b2f0 + iVar21;
LAB_1003c64a:
  DAT_1007b290 = iStack_54;
  FUN_1003c670((uint *)&DAT_1007b280);
  return;
}


