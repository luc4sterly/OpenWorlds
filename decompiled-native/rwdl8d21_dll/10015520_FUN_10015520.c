// 10015520 FUN_10015520 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10015520(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  undefined8 uVar21;
  int local_3c;
  uint local_c;
  
  iVar1 = param_3;
  iVar18 = param_4;
  iVar19 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      iVar18 = param_3;
      iVar19 = param_4;
    }
LAB_10015565:
    param_4 = iVar1;
    param_2 = iVar18;
    param_3 = iVar19;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10015565;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar13 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar11 = *(uint *)(param_2 + 100);
  uVar14 = *(uint *)(param_2 + 0x68);
  iVar15 = (int)*(short *)(param_3 + 0x1a);
  iVar1 = *(int *)(param_2 + 0x20);
  uVar12 = *(uint *)(param_3 + 100);
  uVar10 = *(uint *)(param_3 + 0x68);
  iVar19 = *(int *)(param_3 + 0x20);
  uVar17 = *(uint *)(param_4 + 0x68);
  iVar16 = (int)*(short *)(param_4 + 0x1a);
  uVar20 = *(uint *)(param_4 + 100);
  iVar18 = *(int *)(param_4 + 0x20);
  DAT_1007b2a0 = DAT_10077eb0;
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar2 = DAT_10075214 + 0x1000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  if (iVar13 < 1) {
    iVar13 = DAT_1007b280 - iVar15;
    if (iVar13 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    local_3c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_3c == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar3 = iVar16 - iVar15;
    if (local_3c == 1) {
      DAT_1007b28c = iVar3 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007b28c = iVar3 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar2 + (iVar3 * 0x20 + local_3c) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1007b28c = (iVar3 * 0x10000) / local_3c;
    }
    else {
      DAT_1007b28c = (iVar3 * 0x10000) / local_3c;
    }
    iVar16 = iVar16 - DAT_1007b280;
    if (local_3c == 1) {
      DAT_1007b288 = iVar16 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007b288 = iVar16 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar2 + (iVar16 * 0x20 + local_3c) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1007b288 = (iVar16 * 0x10000) / local_3c;
    }
    else {
      DAT_1007b288 = (iVar16 * 0x10000) / local_3c;
    }
    if ((iVar19 == iVar1) || (iVar13 == 1)) {
      DAT_1007b2ec = iVar1 - iVar19;
    }
    else if (iVar13 == 2) {
      DAT_1007b2ec = iVar1 - iVar19 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar1 - iVar19) / iVar13;
    }
    if ((iVar18 == iVar19) || (local_3c == 1)) {
      DAT_1007b2e8 = iVar18 - iVar19;
    }
    else if (local_3c == 2) {
      DAT_1007b2e8 = iVar18 - iVar19 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar18 - iVar19) / local_3c;
    }
    if ((uVar12 == uVar11) || (iVar13 == 1)) {
      uVar11 = uVar11 - uVar12;
    }
    else if (iVar13 == 2) {
      uVar11 = (int)(uVar11 - uVar12) >> 1;
    }
    else {
      uVar11 = (int)(uVar11 - uVar12) / iVar13;
    }
    if ((uVar20 == uVar12) || (local_3c == 1)) {
      uVar20 = uVar20 - uVar12;
    }
    else if (local_3c == 2) {
      uVar20 = (int)(uVar20 - uVar12) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar12) / local_3c;
    }
    if ((uVar10 == uVar14) || (iVar13 == 1)) {
      uVar14 = uVar14 - uVar10;
    }
    else if (iVar13 == 2) {
      uVar14 = (int)(uVar14 - uVar10) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar10) / iVar13;
    }
    if ((uVar17 == uVar10) || (local_3c == 1)) {
      uVar17 = uVar17 - uVar10;
    }
    else if (local_3c == 2) {
      uVar17 = (int)(uVar17 - uVar10) >> 1;
    }
    else {
      uVar17 = (int)(uVar17 - uVar10) / local_3c;
    }
    DAT_1007b2c0 = (uVar10 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar14 & 0xfffe) << 0xf | (uVar11 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar17 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
  }
  else {
    iVar3 = iVar15 - DAT_1007b280;
    if (iVar13 == 1) {
      DAT_1007b28c = iVar3 * 0x10000;
    }
    else if (iVar13 == 2) {
      DAT_1007b28c = iVar3 * 0x8000;
    }
    else if (((iVar13 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar2 + (iVar3 * 0x20 + iVar13) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1007b28c = (iVar3 * 0x10000) / iVar13;
    }
    else {
      DAT_1007b28c = (iVar3 * 0x10000) / iVar13;
    }
    iVar3 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (0 < iVar3) {
      iVar4 = iVar16 - DAT_1007b280;
      iVar9 = iVar3;
      if (iVar3 == 1) {
        DAT_1007b288 = iVar4 * 0x10000;
      }
      else if (iVar3 == 2) {
        DAT_1007b288 = iVar4 * 0x8000;
      }
      else if (((iVar3 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar2 + (iVar4 * 0x20 + iVar3) * 4);
        iVar9 = iVar2;
      }
      else if (iVar4 < 0) {
        DAT_1007b288 = (iVar4 * 0x10000) / iVar3;
        iVar9 = (iVar4 * 0x10000) % iVar3;
      }
      else {
        DAT_1007b288 = (iVar4 * 0x10000) / iVar3;
        iVar9 = (iVar4 * 0x10000) % iVar3;
      }
      uVar5 = DAT_1007b288 - DAT_1007b28c;
      if ((int)uVar5 < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        return;
      }
      if ((uVar12 == uVar11) || (iVar13 == 1)) {
        uVar6 = uVar12 - uVar11;
      }
      else if (iVar13 == 2) {
        uVar6 = (int)(uVar12 - uVar11) >> 1;
      }
      else {
        uVar6 = (int)(uVar12 - uVar11) / iVar13;
        iVar9 = (int)(uVar12 - uVar11) % iVar13;
      }
      if ((uVar10 == uVar14) || (iVar13 == 1)) {
        uVar7 = uVar10 - uVar14;
      }
      else if (iVar13 == 2) {
        uVar7 = (int)(uVar10 - uVar14) >> 1;
      }
      else {
        uVar7 = (int)(uVar10 - uVar14) / iVar13;
        iVar9 = (int)(uVar10 - uVar14) % iVar13;
      }
      if ((uVar20 == uVar11) || (iVar3 == 1)) {
        iVar4 = uVar20 - uVar11;
      }
      else if (iVar3 == 2) {
        iVar4 = (int)(uVar20 - uVar11) >> 1;
      }
      else {
        iVar4 = (int)(uVar20 - uVar11) / iVar3;
        iVar9 = (int)(uVar20 - uVar11) % iVar3;
      }
      iVar4 = iVar4 - uVar6;
      uVar21 = CONCAT44(iVar9,iVar4);
      if (iVar4 != 0) {
        uVar21 = FUN_10063324(iVar4,iVar9,iVar4,uVar5);
      }
      iVar9 = (int)((ulonglong)uVar21 >> 0x20);
      local_c = (uint)uVar21;
      if ((uVar17 == uVar14) || (iVar3 == 1)) {
        iVar4 = uVar17 - uVar14;
      }
      else if (iVar3 == 2) {
        iVar4 = (int)(uVar17 - uVar14) >> 1;
      }
      else {
        iVar4 = (int)(uVar17 - uVar14) / iVar3;
        iVar9 = (int)(uVar17 - uVar14) % iVar3;
      }
      iVar4 = iVar4 - uVar7;
      uVar8 = 0;
      if (iVar4 != 0) {
        uVar21 = FUN_10063324(iVar4,iVar9,iVar4,uVar5);
        uVar8 = (uint)uVar21;
      }
      if ((iVar19 == iVar1) || (iVar13 == 1)) {
        DAT_1007b2e8 = iVar19 - iVar1;
      }
      else if (iVar13 == 2) {
        DAT_1007b2e8 = iVar19 - iVar1 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar19 - iVar1) / iVar13;
      }
      if ((iVar18 == iVar1) || (iVar3 == 1)) {
        iVar9 = iVar18 - iVar1;
      }
      else if (iVar3 == 2) {
        iVar9 = iVar18 - iVar1 >> 1;
      }
      else {
        iVar9 = (iVar18 - iVar1) / iVar3;
      }
      DAT_1007b2ec = iVar9 - DAT_1007b2e8;
      if ((DAT_1007b2ec != 0) && ((int)uVar5 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / ((int)uVar5 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar13 < iVar3) {
        DAT_1007b2c0 = (uVar14 & 0xfffe) << 0xf | (uVar11 & 0xfffe) >> 1;
        uVar11 = (uVar8 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
        local_3c = iVar3 - iVar13;
        DAT_1007b2c4 = (uVar7 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar13;
        DAT_1007b2c8 = uVar11;
        FUN_10016220((uint *)&DAT_1007b280);
        DAT_1007b280 = iVar15 << 0x10;
        iVar16 = iVar16 - iVar15;
        if (local_3c == 1) {
          DAT_1007b28c = iVar16 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1007b28c = iVar16 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar2 + (iVar16 * 0x20 + local_3c) * 4);
        }
        else if (iVar16 < 0) {
          DAT_1007b28c = (iVar16 * 0x10000) / local_3c;
        }
        else {
          DAT_1007b28c = (iVar16 * 0x10000) / local_3c;
        }
        if ((uVar20 == uVar12) || (local_3c == 1)) {
          uVar20 = uVar20 - uVar12;
        }
        else if (local_3c == 2) {
          uVar20 = (int)(uVar20 - uVar12) >> 1;
        }
        else {
          uVar20 = (int)(uVar20 - uVar12) / local_3c;
        }
        if ((uVar17 == uVar10) || (local_3c == 1)) {
          uVar17 = uVar17 - uVar10;
        }
        else if (local_3c == 2) {
          uVar17 = (int)(uVar17 - uVar10) >> 1;
        }
        else {
          uVar17 = (int)(uVar17 - uVar10) / local_3c;
        }
        if ((iVar18 == iVar19) || (local_3c == 1)) {
          DAT_1007b2e8 = iVar18 - iVar19;
        }
        else if (local_3c == 2) {
          DAT_1007b2e8 = iVar18 - iVar19 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar18 - iVar19) / local_3c;
        }
        DAT_1007b2c4 = (uVar17 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
        DAT_1007b2c8 = uVar11;
      }
      else {
        DAT_1007b2c0 = (uVar14 & 0xfffe) << 0xf | (uVar11 & 0xfffe) >> 1;
        DAT_1007b2c8 = (uVar8 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
        DAT_1007b2c4 = (uVar7 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
        local_3c = iVar13 - iVar3;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar3;
        FUN_10016220((uint *)&DAT_1007b280);
        if (local_3c == 0) {
          return;
        }
        DAT_1007b284 = iVar16 << 0x10;
        iVar15 = iVar15 - iVar16;
        if (local_3c == 1) {
          DAT_1007b288 = iVar15 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1007b288 = iVar15 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar2 + (iVar15 * 0x20 + local_3c) * 4);
        }
        else if (iVar15 < 0) {
          DAT_1007b288 = (iVar15 * 0x10000) / local_3c;
        }
        else {
          DAT_1007b288 = (iVar15 * 0x10000) / local_3c;
        }
      }
      goto LAB_100161f8;
    }
    iVar3 = iVar16 - DAT_1007b280;
    if (iVar3 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar15 = iVar15 - iVar16;
    if (iVar13 == 1) {
      DAT_1007b288 = iVar15 * 0x10000;
    }
    else if (iVar13 == 2) {
      DAT_1007b288 = iVar15 * 0x8000;
    }
    else if (((iVar13 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar2 + (iVar15 * 0x20 + iVar13) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007b288 = (iVar15 * 0x10000) / iVar13;
    }
    else {
      DAT_1007b288 = (iVar15 * 0x10000) / iVar13;
    }
    if ((iVar18 == iVar1) || (iVar3 == 1)) {
      DAT_1007b2ec = iVar18 - iVar1;
    }
    else if (iVar3 == 2) {
      DAT_1007b2ec = iVar18 - iVar1 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar18 - iVar1) / iVar3;
    }
    if ((iVar19 == iVar1) || (iVar13 == 1)) {
      DAT_1007b2e8 = iVar19 - iVar1;
    }
    else if (iVar13 == 2) {
      DAT_1007b2e8 = iVar19 - iVar1 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar19 - iVar1) / iVar13;
    }
    if ((uVar20 == uVar11) || (iVar3 == 1)) {
      uVar20 = uVar20 - uVar11;
    }
    else if (iVar3 == 2) {
      uVar20 = (int)(uVar20 - uVar11) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar11) / iVar3;
    }
    if ((uVar17 == uVar14) || (iVar3 == 1)) {
      uVar17 = uVar17 - uVar14;
    }
    else if (iVar3 == 2) {
      uVar17 = (int)(uVar17 - uVar14) >> 1;
    }
    else {
      uVar17 = (int)(uVar17 - uVar14) / iVar3;
    }
    if ((uVar12 == uVar11) || (iVar13 == 1)) {
      uVar12 = uVar12 - uVar11;
    }
    else if (iVar13 == 2) {
      uVar12 = (int)(uVar12 - uVar11) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar11) / iVar13;
    }
    if ((uVar10 == uVar14) || (iVar13 == 1)) {
      uVar10 = uVar10 - uVar14;
    }
    else if (iVar13 == 2) {
      uVar10 = (int)(uVar10 - uVar14) >> 1;
    }
    else {
      uVar10 = (int)(uVar10 - uVar14) / iVar13;
    }
    DAT_1007b2c0 = (uVar14 & 0xfffe) << 0xf | (uVar11 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar17 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar10 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
    local_3c = iVar13;
    iVar19 = iVar1;
    iVar15 = DAT_1007b280;
    DAT_1007b280 = iVar16;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar15 << 0x10;
  DAT_1007b2e4 = DAT_1007b2f0 + iVar19;
LAB_100161f8:
  DAT_1007b290 = local_3c;
  FUN_10016220((uint *)&DAT_1007b280);
  return;
}


