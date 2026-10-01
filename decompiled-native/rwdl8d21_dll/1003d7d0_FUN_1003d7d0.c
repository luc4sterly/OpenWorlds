// 1003d7d0 FUN_1003d7d0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1003d7d0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint extraout_ECX;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  short sVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  undefined8 uVar26;
  int iStack_50;
  short sStack_2c;
  uint uStack_20;
  uint uStack_14;
  short sStack_c;
  
  iVar1 = param_3;
  iVar14 = param_4;
  iVar22 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      iVar14 = param_3;
      iVar22 = param_4;
    }
LAB_1003d815:
    param_4 = iVar1;
    param_2 = iVar14;
    param_3 = iVar22;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1003d815;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar2 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar24 = *(int *)(param_2 + 100) >> 3;
  uVar21 = *(int *)(param_2 + 0x58) >> 8;
  iVar1 = *(int *)(param_2 + 0x20);
  uVar16 = *(int *)(param_2 + 0x68) >> 3;
  iVar15 = (int)*(short *)(param_3 + 0x1a);
  uVar25 = *(int *)(param_3 + 100) >> 3;
  uStack_20 = *(int *)(param_3 + 0x58) >> 8;
  iVar22 = *(int *)(param_3 + 0x20);
  uVar17 = *(int *)(param_3 + 0x68) >> 3;
  iVar18 = (int)*(short *)(param_4 + 0x1a);
  uVar3 = *(int *)(param_4 + 0x58) >> 8;
  uVar19 = *(int *)(param_4 + 100) >> 3;
  iVar14 = *(int *)(param_4 + 0x20);
  uVar23 = *(int *)(param_4 + 0x68) >> 3;
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2a0 = DAT_10077eb0;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar4 = DAT_10075214 + 0x1000;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  sVar20 = (short)((uint)*(int *)(param_2 + 0x58) >> 8);
  sStack_c = (short)((uint)*(int *)(param_4 + 0x58) >> 8);
  sStack_2c = (short)((uint)*(int *)(param_3 + 0x58) >> 8);
  if (iVar2 < 1) {
    iVar2 = DAT_1007b280 - iVar15;
    if (iVar2 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iStack_50 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_50 == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar5 = iVar18 - iVar15;
    if (iStack_50 == 1) {
      DAT_1007b28c = iVar5 * 0x10000;
    }
    else if (iStack_50 == 2) {
      DAT_1007b28c = iVar5 * 0x8000;
    }
    else if (((iStack_50 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar4 + (iVar5 * 0x20 + iStack_50) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007b28c = (iVar5 * 0x10000) / iStack_50;
    }
    else {
      DAT_1007b28c = (iVar5 * 0x10000) / iStack_50;
    }
    iVar18 = iVar18 - DAT_1007b280;
    if (iStack_50 == 1) {
      DAT_1007b288 = iVar18 * 0x10000;
    }
    else if (iStack_50 == 2) {
      DAT_1007b288 = iVar18 * 0x8000;
    }
    else if (((iStack_50 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar4 + (iVar18 * 0x20 + iStack_50) * 4);
    }
    else if (iVar18 < 0) {
      DAT_1007b288 = (iVar18 * 0x10000) / iStack_50;
    }
    else {
      DAT_1007b288 = (iVar18 * 0x10000) / iStack_50;
    }
    if ((iVar22 == iVar1) || (iVar2 == 1)) {
      DAT_1007b2ec = iVar1 - iVar22;
    }
    else if (iVar2 == 2) {
      DAT_1007b2ec = iVar1 - iVar22 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar1 - iVar22) / iVar2;
    }
    if ((iVar14 == iVar22) || (iStack_50 == 1)) {
      DAT_1007b2e8 = iVar14 - iVar22;
    }
    else if (iStack_50 == 2) {
      DAT_1007b2e8 = iVar14 - iVar22 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar14 - iVar22) / iStack_50;
    }
    if ((uVar25 == uVar24) || (iVar2 == 1)) {
      uVar24 = uVar24 - uVar25;
    }
    else if (iVar2 == 2) {
      uVar24 = (int)(uVar24 - uVar25) >> 1;
    }
    else {
      uVar24 = (int)(uVar24 - uVar25) / iVar2;
    }
    if ((uVar19 == uVar25) || (iStack_50 == 1)) {
      uVar19 = uVar19 - uVar25;
    }
    else if (iStack_50 == 2) {
      uVar19 = (int)(uVar19 - uVar25) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar25) / iStack_50;
    }
    if ((uVar17 == uVar16) || (iVar2 == 1)) {
      uVar16 = uVar16 - uVar17;
    }
    else if (iVar2 == 2) {
      uVar16 = (int)(uVar16 - uVar17) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar17) / iVar2;
    }
    if ((uVar23 == uVar17) || (iStack_50 == 1)) {
      uVar23 = uVar23 - uVar17;
    }
    else if (iStack_50 == 2) {
      uVar23 = (int)(uVar23 - uVar17) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - uVar17) / iStack_50;
    }
    uVar21 = uVar21 & 0xffff;
    if ((sVar20 == sStack_2c) || (iVar2 == 1)) {
      uVar21 = uVar21 - (uStack_20 & 0xffff);
    }
    else if (iVar2 == 2) {
      uVar21 = (int)(uVar21 - (uStack_20 & 0xffff)) >> 1;
    }
    else {
      uVar21 = (int)(uVar21 - (uStack_20 & 0xffff)) / iVar2;
    }
    uVar7 = uStack_20 & 0xffff;
    DAT_1007b2d4 = (uVar21 & 0xffff) + (uVar21 & 0x8000) * -2;
    uVar3 = uVar3 & 0xffff;
    if ((sStack_c == sStack_2c) || (iStack_50 == 1)) {
      uVar3 = uVar3 - uVar7;
    }
    else if (iStack_50 == 2) {
      uVar3 = (int)(uVar3 - uVar7) >> 1;
    }
    else {
      uVar3 = (int)(uVar3 - uVar7) / iStack_50;
    }
    DAT_1007b2d0 = (uVar3 & 0xffff) + (uVar3 & 0x8000) * -2;
    DAT_1007b2c0 = (uVar17 & 0xfffe) << 0xf | (uVar25 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar16 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar23 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    DAT_1007b2cc = uStack_20;
  }
  else {
    iVar5 = iVar15 - DAT_1007b280;
    if (iVar2 == 1) {
      DAT_1007b28c = iVar5 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b28c = iVar5 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar4 + (iVar5 * 0x20 + iVar2) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007b28c = (iVar5 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b28c = (iVar5 * 0x10000) / iVar2;
    }
    iVar5 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (0 < iVar5) {
      iVar6 = iVar18 - DAT_1007b280;
      iVar12 = iVar5;
      if (iVar5 == 1) {
        DAT_1007b288 = iVar6 * 0x10000;
      }
      else if (iVar5 == 2) {
        DAT_1007b288 = iVar6 * 0x8000;
      }
      else if (((iVar5 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar4 + (iVar6 * 0x20 + iVar5) * 4);
        iVar12 = iVar4;
      }
      else if (iVar6 < 0) {
        DAT_1007b288 = (iVar6 * 0x10000) / iVar5;
        iVar12 = (iVar6 * 0x10000) % iVar5;
      }
      else {
        DAT_1007b288 = (iVar6 * 0x10000) / iVar5;
        iVar12 = (iVar6 * 0x10000) % iVar5;
      }
      uVar7 = DAT_1007b288 - DAT_1007b28c;
      if ((int)uVar7 < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        return;
      }
      if ((uVar25 == uVar24) || (iVar2 == 1)) {
        uVar8 = uVar25 - uVar24;
      }
      else if (iVar2 == 2) {
        uVar8 = (int)(uVar25 - uVar24) >> 1;
      }
      else {
        uVar8 = (int)(uVar25 - uVar24) / iVar2;
        iVar12 = (int)(uVar25 - uVar24) % iVar2;
      }
      if ((uVar17 == uVar16) || (iVar2 == 1)) {
        uVar9 = uVar17 - uVar16;
      }
      else if (iVar2 == 2) {
        uVar9 = (int)(uVar17 - uVar16) >> 1;
      }
      else {
        uVar9 = (int)(uVar17 - uVar16) / iVar2;
        iVar12 = (int)(uVar17 - uVar16) % iVar2;
      }
      if ((uVar19 == uVar24) || (iVar5 == 1)) {
        iVar6 = uVar19 - uVar24;
      }
      else if (iVar5 == 2) {
        iVar6 = (int)(uVar19 - uVar24) >> 1;
      }
      else {
        iVar6 = (int)(uVar19 - uVar24) / iVar5;
        iVar12 = (int)(uVar19 - uVar24) % iVar5;
      }
      iVar6 = iVar6 - uVar8;
      uVar26 = CONCAT44(iVar12,iVar6);
      uVar11 = 0;
      if (iVar6 != 0) {
        uVar26 = FUN_10063324(iVar6,iVar12,iVar6,uVar7);
        uVar11 = extraout_ECX;
      }
      iVar12 = (int)((ulonglong)uVar26 >> 0x20);
      uStack_14 = (uint)uVar26;
      if ((uVar23 == uVar16) || (iVar5 == 1)) {
        iVar6 = uVar23 - uVar16;
      }
      else if (iVar5 == 2) {
        iVar6 = (int)(uVar23 - uVar16) >> 1;
      }
      else {
        iVar6 = (int)(uVar23 - uVar16) / iVar5;
        iVar12 = (int)(uVar23 - uVar16) % iVar5;
        uVar11 = uVar16;
      }
      uVar10 = 0;
      if (iVar6 - uVar9 != 0) {
        uVar26 = FUN_10063324(uVar11,iVar12,iVar6 - uVar9,uVar7);
        uVar10 = (uint)uVar26;
      }
      if ((sStack_2c == sVar20) || (iVar2 == 1)) {
        uVar11 = (uStack_20 & 0xffff) - (uVar21 & 0xffff);
      }
      else if (iVar2 == 2) {
        uVar11 = (int)((uStack_20 & 0xffff) - (uVar21 & 0xffff)) >> 1;
      }
      else {
        uVar11 = (int)((uStack_20 & 0xffff) - (uVar21 & 0xffff)) / iVar2;
      }
      uStack_20 = uStack_20 & 0xffff;
      uVar13 = uVar21 & 0xffff;
      DAT_1007b2d4 = 0;
      DAT_1007b2d0 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      if ((sStack_c == sVar20) || (iVar5 == 1)) {
        iVar12 = (uVar3 & 0xffff) - uVar13;
      }
      else if (iVar5 == 2) {
        iVar12 = (int)((uVar3 & 0xffff) - uVar13) >> 1;
      }
      else {
        iVar12 = (int)((uVar3 & 0xffff) - uVar13) / iVar5;
      }
      uVar3 = uVar3 & 0xffff;
      if (iVar12 - (short)DAT_1007b2d0 != 0) {
        uVar11 = ((iVar12 - (short)DAT_1007b2d0) * 0x10000) / (int)uVar7;
        DAT_1007b2d4 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      }
      if ((iVar22 == iVar1) || (iVar2 == 1)) {
        DAT_1007b2e8 = iVar22 - iVar1;
      }
      else if (iVar2 == 2) {
        DAT_1007b2e8 = iVar22 - iVar1 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar22 - iVar1) / iVar2;
      }
      if ((iVar14 == iVar1) || (iVar5 == 1)) {
        iVar12 = iVar14 - iVar1;
      }
      else if (iVar5 == 2) {
        iVar12 = iVar14 - iVar1 >> 1;
      }
      else {
        iVar12 = (iVar14 - iVar1) / iVar5;
      }
      DAT_1007b2ec = iVar12 - DAT_1007b2e8;
      if ((DAT_1007b2ec != 0) && ((int)uVar7 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / ((int)uVar7 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar2 < iVar5) {
        DAT_1007b2c0 = (uVar16 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
        uVar24 = (uVar10 & 0xfffe) << 0xf | (uStack_14 & 0xfffe) >> 1;
        DAT_1007b2c4 = (uVar9 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
        iStack_50 = iVar5 - iVar2;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar2;
        DAT_1007b2c8 = uVar24;
        DAT_1007b2cc = uVar21;
        FUN_1003e8a0((uint *)&DAT_1007b280);
        DAT_1007b280 = iVar15 << 0x10;
        iVar18 = iVar18 - iVar15;
        if (iStack_50 == 1) {
          DAT_1007b28c = iVar18 * 0x10000;
        }
        else if (iStack_50 == 2) {
          DAT_1007b28c = iVar18 * 0x8000;
        }
        else if (((iStack_50 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar4 + (iVar18 * 0x20 + iStack_50) * 4);
        }
        else if (iVar18 < 0) {
          DAT_1007b28c = (iVar18 * 0x10000) / iStack_50;
        }
        else {
          DAT_1007b28c = (iVar18 * 0x10000) / iStack_50;
        }
        if ((uVar19 == uVar25) || (iStack_50 == 1)) {
          uVar19 = uVar19 - uVar25;
        }
        else if (iStack_50 == 2) {
          uVar19 = (int)(uVar19 - uVar25) >> 1;
        }
        else {
          uVar19 = (int)(uVar19 - uVar25) / iStack_50;
        }
        if ((uVar23 == uVar17) || (iStack_50 == 1)) {
          uVar23 = uVar23 - uVar17;
        }
        else if (iStack_50 == 2) {
          uVar23 = (int)(uVar23 - uVar17) >> 1;
        }
        else {
          uVar23 = (int)(uVar23 - uVar17) / iStack_50;
        }
        DAT_1007b2d0 = 0;
        if ((sStack_c == sStack_2c) || (iStack_50 == 1)) {
          uVar3 = uVar3 - uStack_20;
        }
        else if (iStack_50 == 2) {
          uVar3 = (int)(uVar3 - uStack_20) >> 1;
        }
        else {
          uVar3 = (int)(uVar3 - uStack_20) / iStack_50;
        }
        if (uVar3 != 0) {
          DAT_1007b2d0 = (uVar3 & 0xffff) + (uVar3 & 0x8000) * -2;
        }
        if ((iVar14 == iVar22) || (iStack_50 == 1)) {
          DAT_1007b2e8 = iVar14 - iVar22;
        }
        else if (iStack_50 == 2) {
          DAT_1007b2e8 = iVar14 - iVar22 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar14 - iVar22) / iStack_50;
        }
        DAT_1007b2c4 = (uVar23 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
        DAT_1007b2c8 = uVar24;
      }
      else {
        DAT_1007b2c0 = (uVar16 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
        DAT_1007b2c8 = (uVar10 & 0xfffe) << 0xf | (uStack_14 & 0xfffe) >> 1;
        iStack_50 = iVar2 - iVar5;
        DAT_1007b2c4 = (uVar9 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar5;
        DAT_1007b2cc = uVar21;
        FUN_1003e8a0((uint *)&DAT_1007b280);
        if (iStack_50 == 0) {
          return;
        }
        DAT_1007b284 = iVar18 << 0x10;
        iVar15 = iVar15 - iVar18;
        if (iStack_50 == 1) {
          DAT_1007b288 = iVar15 * 0x10000;
        }
        else if (iStack_50 == 2) {
          DAT_1007b288 = iVar15 * 0x8000;
        }
        else if (((iStack_50 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar4 + (iVar15 * 0x20 + iStack_50) * 4);
        }
        else if (iVar15 < 0) {
          DAT_1007b288 = (iVar15 * 0x10000) / iStack_50;
        }
        else {
          DAT_1007b288 = (iVar15 * 0x10000) / iStack_50;
        }
      }
      goto LAB_1003e882;
    }
    iVar5 = iVar18 - DAT_1007b280;
    if (iVar5 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar15 = iVar15 - iVar18;
    if (iVar2 == 1) {
      DAT_1007b288 = iVar15 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b288 = iVar15 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar4 + (iVar15 * 0x20 + iVar2) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007b288 = (iVar15 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b288 = (iVar15 * 0x10000) / iVar2;
    }
    if ((iVar14 == iVar1) || (iVar5 == 1)) {
      DAT_1007b2ec = iVar14 - iVar1;
    }
    else if (iVar5 == 2) {
      DAT_1007b2ec = iVar14 - iVar1 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar14 - iVar1) / iVar5;
    }
    if ((iVar22 == iVar1) || (iVar2 == 1)) {
      DAT_1007b2e8 = iVar22 - iVar1;
    }
    else if (iVar2 == 2) {
      DAT_1007b2e8 = iVar22 - iVar1 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar22 - iVar1) / iVar2;
    }
    if ((uVar19 == uVar24) || (iVar5 == 1)) {
      uVar19 = uVar19 - uVar24;
    }
    else if (iVar5 == 2) {
      uVar19 = (int)(uVar19 - uVar24) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar24) / iVar5;
    }
    if ((uVar23 == uVar16) || (iVar5 == 1)) {
      uVar23 = uVar23 - uVar16;
    }
    else if (iVar5 == 2) {
      uVar23 = (int)(uVar23 - uVar16) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - uVar16) / iVar5;
    }
    if ((uVar25 == uVar24) || (iVar2 == 1)) {
      uVar25 = uVar25 - uVar24;
    }
    else if (iVar2 == 2) {
      uVar25 = (int)(uVar25 - uVar24) >> 1;
    }
    else {
      uVar25 = (int)(uVar25 - uVar24) / iVar2;
    }
    if ((uVar17 == uVar16) || (iVar2 == 1)) {
      uVar17 = uVar17 - uVar16;
    }
    else if (iVar2 == 2) {
      uVar17 = (int)(uVar17 - uVar16) >> 1;
    }
    else {
      uVar17 = (int)(uVar17 - uVar16) / iVar2;
    }
    uVar3 = uVar3 & 0xffff;
    if ((sStack_c == sVar20) || (iVar5 == 1)) {
      uVar3 = uVar3 - (uVar21 & 0xffff);
    }
    else if (iVar5 == 2) {
      uVar3 = (int)(uVar3 - (uVar21 & 0xffff)) >> 1;
    }
    else {
      uVar3 = (int)(uVar3 - (uVar21 & 0xffff)) / iVar5;
    }
    uVar7 = uVar21 & 0xffff;
    DAT_1007b2d4 = (uVar3 & 0xffff) + (uVar3 & 0x8000) * -2;
    uStack_20 = uStack_20 & 0xffff;
    if ((sStack_2c == sVar20) || (iVar2 == 1)) {
      uStack_20 = uStack_20 - uVar7;
    }
    else if (iVar2 == 2) {
      uStack_20 = (int)(uStack_20 - uVar7) >> 1;
    }
    else {
      uStack_20 = (int)(uStack_20 - uVar7) / iVar2;
    }
    DAT_1007b2d0 = (uStack_20 & 0xffff) + (uStack_20 & 0x8000) * -2;
    DAT_1007b2c0 = (uVar16 & 0xfffe) << 0xf | (uVar24 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar23 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar17 & 0xfffe) << 0xf | (uVar25 & 0xfffe) >> 1;
    DAT_1007b2cc = uVar21;
    iStack_50 = iVar2;
    iVar22 = iVar1;
    iVar15 = DAT_1007b280;
    DAT_1007b280 = iVar18;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar15 << 0x10;
  DAT_1007b2e4 = DAT_1007b2f0 + iVar22;
LAB_1003e882:
  DAT_1007b290 = iStack_50;
  FUN_1003e8a0((uint *)&DAT_1007b280);
  return;
}


