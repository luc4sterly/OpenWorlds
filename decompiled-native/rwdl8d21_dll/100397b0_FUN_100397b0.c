// 100397b0 FUN_100397b0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100397b0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  undefined8 uVar21;
  int iStack_3c;
  uint uStack_20;
  
  iVar1 = param_3;
  iVar11 = param_4;
  iVar19 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      iVar11 = param_3;
      iVar19 = param_4;
    }
LAB_100397f6:
    param_4 = iVar1;
    param_2 = iVar11;
    param_3 = iVar19;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_100397f6;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar2 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar17 = *(int *)(param_2 + 100) >> 3;
  iVar1 = *(int *)(param_2 + 0x20);
  uVar18 = *(int *)(param_2 + 0x68) >> 3;
  iVar12 = (int)*(short *)(param_3 + 0x1a);
  uVar14 = *(int *)(param_3 + 100) >> 3;
  iVar19 = *(int *)(param_3 + 0x20);
  uVar13 = *(int *)(param_3 + 0x68) >> 3;
  iVar15 = (int)*(short *)(param_4 + 0x1a);
  uVar20 = *(int *)(param_4 + 0x68) >> 3;
  iVar11 = *(int *)(param_4 + 0x20);
  uVar16 = *(int *)(param_4 + 100) >> 3;
  DAT_1007b2a0 = DAT_10077eb0;
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007b2b4 = ((int)(param_1[1] & 0xffff00ffU) >> 8) + DAT_10075220;
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar3 = DAT_10075214 + 0x1000;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  if (iVar2 < 1) {
    iVar2 = DAT_1007b280 - iVar12;
    if (iVar2 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iStack_3c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_3c == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar4 = iVar15 - iVar12;
    if (iStack_3c == 1) {
      DAT_1007b28c = iVar4 * 0x10000;
    }
    else if (iStack_3c == 2) {
      DAT_1007b28c = iVar4 * 0x8000;
    }
    else if (((iStack_3c < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar3 + (iVar4 * 0x20 + iStack_3c) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1007b28c = (iVar4 * 0x10000) / iStack_3c;
    }
    else {
      DAT_1007b28c = (iVar4 * 0x10000) / iStack_3c;
    }
    iVar15 = iVar15 - DAT_1007b280;
    if (iStack_3c == 1) {
      DAT_1007b288 = iVar15 * 0x10000;
    }
    else if (iStack_3c == 2) {
      DAT_1007b288 = iVar15 * 0x8000;
    }
    else if (((iStack_3c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar3 + (iVar15 * 0x20 + iStack_3c) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007b288 = (iVar15 * 0x10000) / iStack_3c;
    }
    else {
      DAT_1007b288 = (iVar15 * 0x10000) / iStack_3c;
    }
    if ((iVar1 == iVar19) || (iVar2 == 1)) {
      DAT_1007b2ec = iVar1 - iVar19;
    }
    else if (iVar2 == 2) {
      DAT_1007b2ec = iVar1 - iVar19 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar1 - iVar19) / iVar2;
    }
    if ((iVar11 == iVar19) || (iStack_3c == 1)) {
      DAT_1007b2e8 = iVar11 - iVar19;
    }
    else if (iStack_3c == 2) {
      DAT_1007b2e8 = iVar11 - iVar19 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar11 - iVar19) / iStack_3c;
    }
    if ((uVar14 == uVar17) || (iVar2 == 1)) {
      uVar17 = uVar17 - uVar14;
    }
    else if (iVar2 == 2) {
      uVar17 = (int)(uVar17 - uVar14) >> 1;
    }
    else {
      uVar17 = (int)(uVar17 - uVar14) / iVar2;
    }
    if ((uVar16 == uVar14) || (iStack_3c == 1)) {
      uVar16 = uVar16 - uVar14;
    }
    else if (iStack_3c == 2) {
      uVar16 = (int)(uVar16 - uVar14) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar14) / iStack_3c;
    }
    if ((uVar13 == uVar18) || (iVar2 == 1)) {
      uVar18 = uVar18 - uVar13;
    }
    else if (iVar2 == 2) {
      uVar18 = (int)(uVar18 - uVar13) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar13) / iVar2;
    }
    if ((uVar20 == uVar13) || (iStack_3c == 1)) {
      uVar20 = uVar20 - uVar13;
    }
    else if (iStack_3c == 2) {
      uVar20 = (int)(uVar20 - uVar13) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar13) / iStack_3c;
    }
    DAT_1007b2c8 = (uVar18 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
    DAT_1007b2c0 = (uVar13 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar20 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
  }
  else {
    iVar4 = iVar12 - DAT_1007b280;
    if (iVar2 == 1) {
      DAT_1007b28c = iVar4 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b28c = iVar4 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar3 + (iVar4 * 0x20 + iVar2) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1007b28c = (iVar4 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b28c = (iVar4 * 0x10000) / iVar2;
    }
    iVar4 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (0 < iVar4) {
      iVar5 = iVar15 - DAT_1007b280;
      iVar10 = iVar4;
      if (iVar4 == 1) {
        DAT_1007b288 = iVar5 * 0x10000;
      }
      else if (iVar4 == 2) {
        DAT_1007b288 = iVar5 * 0x8000;
      }
      else if (((iVar4 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar3 + (iVar5 * 0x20 + iVar4) * 4);
        iVar10 = iVar3;
      }
      else if (iVar5 < 0) {
        DAT_1007b288 = (iVar5 * 0x10000) / iVar4;
        iVar10 = (iVar5 * 0x10000) % iVar4;
      }
      else {
        DAT_1007b288 = (iVar5 * 0x10000) / iVar4;
        iVar10 = (iVar5 * 0x10000) % iVar4;
      }
      uVar6 = DAT_1007b288 - DAT_1007b28c;
      if ((int)uVar6 < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        return;
      }
      if ((uVar14 == uVar17) || (iVar2 == 1)) {
        uVar7 = uVar14 - uVar17;
      }
      else if (iVar2 == 2) {
        uVar7 = (int)(uVar14 - uVar17) >> 1;
      }
      else {
        uVar7 = (int)(uVar14 - uVar17) / iVar2;
        iVar10 = (int)(uVar14 - uVar17) % iVar2;
      }
      if ((uVar13 == uVar18) || (iVar2 == 1)) {
        uVar8 = uVar13 - uVar18;
      }
      else if (iVar2 == 2) {
        uVar8 = (int)(uVar13 - uVar18) >> 1;
      }
      else {
        uVar8 = (int)(uVar13 - uVar18) / iVar2;
        iVar10 = (int)(uVar13 - uVar18) % iVar2;
      }
      if ((uVar16 == uVar17) || (iVar4 == 1)) {
        iVar5 = uVar16 - uVar17;
      }
      else if (iVar4 == 2) {
        iVar5 = (int)(uVar16 - uVar17) >> 1;
      }
      else {
        iVar5 = (int)(uVar16 - uVar17) / iVar4;
        iVar10 = (int)(uVar16 - uVar17) % iVar4;
      }
      iVar5 = iVar5 - uVar7;
      uVar21 = CONCAT44(iVar10,iVar5);
      if (iVar5 != 0) {
        uVar21 = FUN_10063324(iVar5,iVar10,iVar5,uVar6);
      }
      iVar10 = (int)((ulonglong)uVar21 >> 0x20);
      uStack_20 = (uint)uVar21;
      if ((uVar20 == uVar18) || (iVar4 == 1)) {
        iVar5 = uVar20 - uVar18;
      }
      else if (iVar4 == 2) {
        iVar5 = (int)(uVar20 - uVar18) >> 1;
      }
      else {
        iVar5 = (int)(uVar20 - uVar18) / iVar4;
        iVar10 = (int)(uVar20 - uVar18) % iVar4;
      }
      iVar5 = iVar5 - uVar8;
      uVar9 = 0;
      if (iVar5 != 0) {
        uVar21 = FUN_10063324(iVar5,iVar10,iVar5,uVar6);
        uVar9 = (uint)uVar21;
      }
      if ((iVar1 == iVar19) || (iVar2 == 1)) {
        DAT_1007b2e8 = iVar19 - iVar1;
      }
      else if (iVar2 == 2) {
        DAT_1007b2e8 = iVar19 - iVar1 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar19 - iVar1) / iVar2;
      }
      if ((iVar1 == iVar11) || (iVar4 == 1)) {
        iVar10 = iVar11 - iVar1;
      }
      else if (iVar4 == 2) {
        iVar10 = iVar11 - iVar1 >> 1;
      }
      else {
        iVar10 = (iVar11 - iVar1) / iVar4;
      }
      DAT_1007b2ec = iVar10 - DAT_1007b2e8;
      if ((DAT_1007b2ec != 0) && ((int)uVar6 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / ((int)uVar6 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar2 < iVar4) {
        DAT_1007b2c0 = (uVar18 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
        uVar17 = (uVar9 & 0xfffe) << 0xf | (uStack_20 & 0xfffe) >> 1;
        iStack_3c = iVar4 - iVar2;
        DAT_1007b2c4 = (uVar8 & 0xfffe) << 0xf | (uVar7 & 0xfffe) >> 1;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar2;
        DAT_1007b2c8 = uVar17;
        FUN_1003a4d0((uint *)&DAT_1007b280);
        DAT_1007b280 = iVar12 << 0x10;
        iVar15 = iVar15 - iVar12;
        if (iStack_3c == 1) {
          DAT_1007b28c = iVar15 * 0x10000;
        }
        else if (iStack_3c == 2) {
          DAT_1007b28c = iVar15 * 0x8000;
        }
        else if (((iStack_3c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar3 + (iVar15 * 0x20 + iStack_3c) * 4);
        }
        else if (iVar15 < 0) {
          DAT_1007b28c = (iVar15 * 0x10000) / iStack_3c;
        }
        else {
          DAT_1007b28c = (iVar15 * 0x10000) / iStack_3c;
        }
        if ((uVar16 == uVar14) || (iStack_3c == 1)) {
          uVar16 = uVar16 - uVar14;
        }
        else if (iStack_3c == 2) {
          uVar16 = (int)(uVar16 - uVar14) >> 1;
        }
        else {
          uVar16 = (int)(uVar16 - uVar14) / iStack_3c;
        }
        if ((uVar20 == uVar13) || (iStack_3c == 1)) {
          uVar20 = uVar20 - uVar13;
        }
        else if (iStack_3c == 2) {
          uVar20 = (int)(uVar20 - uVar13) >> 1;
        }
        else {
          uVar20 = (int)(uVar20 - uVar13) / iStack_3c;
        }
        if ((iVar11 == iVar19) || (iStack_3c == 1)) {
          DAT_1007b2e8 = iVar11 - iVar19;
        }
        else if (iStack_3c == 2) {
          DAT_1007b2e8 = iVar11 - iVar19 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar11 - iVar19) / iStack_3c;
        }
        DAT_1007b2c4 = (uVar20 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
        DAT_1007b2c8 = uVar17;
      }
      else {
        DAT_1007b2c0 = (uVar18 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
        DAT_1007b2c8 = (uVar9 & 0xfffe) << 0xf | (uStack_20 & 0xfffe) >> 1;
        DAT_1007b2c4 = (uVar8 & 0xfffe) << 0xf | (uVar7 & 0xfffe) >> 1;
        iStack_3c = iVar2 - iVar4;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar4;
        FUN_1003a4d0((uint *)&DAT_1007b280);
        if (iStack_3c == 0) {
          return;
        }
        DAT_1007b284 = iVar15 << 0x10;
        iVar12 = iVar12 - iVar15;
        if (iStack_3c == 1) {
          DAT_1007b288 = iVar12 * 0x10000;
        }
        else if (iStack_3c == 2) {
          DAT_1007b288 = iVar12 * 0x8000;
        }
        else if (((iStack_3c < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar3 + (iVar12 * 0x20 + iStack_3c) * 4);
        }
        else if (iVar12 < 0) {
          DAT_1007b288 = (iVar12 * 0x10000) / iStack_3c;
        }
        else {
          DAT_1007b288 = (iVar12 * 0x10000) / iStack_3c;
        }
      }
      goto LAB_1003a4a9;
    }
    iVar4 = iVar15 - DAT_1007b280;
    if (iVar4 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar12 = iVar12 - iVar15;
    if (iVar2 == 1) {
      DAT_1007b288 = iVar12 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b288 = iVar12 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar3 + (iVar12 * 0x20 + iVar2) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1007b288 = (iVar12 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b288 = (iVar12 * 0x10000) / iVar2;
    }
    if ((iVar1 == iVar11) || (iVar4 == 1)) {
      DAT_1007b2ec = iVar11 - iVar1;
    }
    else if (iVar4 == 2) {
      DAT_1007b2ec = iVar11 - iVar1 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar11 - iVar1) / iVar4;
    }
    if ((iVar1 == iVar19) || (iVar2 == 1)) {
      DAT_1007b2e8 = iVar19 - iVar1;
    }
    else if (iVar2 == 2) {
      DAT_1007b2e8 = iVar19 - iVar1 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar19 - iVar1) / iVar2;
    }
    if ((uVar16 == uVar17) || (iVar4 == 1)) {
      uVar16 = uVar16 - uVar17;
    }
    else if (iVar4 == 2) {
      uVar16 = (int)(uVar16 - uVar17) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar17) / iVar4;
    }
    if ((uVar20 == uVar18) || (iVar4 == 1)) {
      uVar20 = uVar20 - uVar18;
    }
    else if (iVar4 == 2) {
      uVar20 = (int)(uVar20 - uVar18) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar18) / iVar4;
    }
    if ((uVar14 == uVar17) || (iVar2 == 1)) {
      uVar14 = uVar14 - uVar17;
    }
    else if (iVar2 == 2) {
      uVar14 = (int)(uVar14 - uVar17) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar17) / iVar2;
    }
    if ((uVar13 == uVar18) || (iVar2 == 1)) {
      uVar13 = uVar13 - uVar18;
    }
    else if (iVar2 == 2) {
      uVar13 = (int)(uVar13 - uVar18) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - uVar18) / iVar2;
    }
    DAT_1007b2c0 = (uVar18 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar20 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar13 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    iStack_3c = iVar2;
    iVar19 = iVar1;
    iVar12 = DAT_1007b280;
    DAT_1007b280 = iVar15;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar12 << 0x10;
  DAT_1007b2e4 = DAT_1007b2f0 + iVar19;
LAB_1003a4a9:
  DAT_1007b290 = iStack_3c;
  FUN_1003a4d0((uint *)&DAT_1007b280);
  return;
}


