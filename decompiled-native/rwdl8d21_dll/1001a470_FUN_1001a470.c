// 1001a470 FUN_1001a470 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001a470(int *param_1,int param_2,int param_3,int param_4)

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
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  undefined8 uVar25;
  int local_54;
  short local_3c;
  short local_2c;
  uint local_20;
  uint local_1c;
  short local_c;
  
  iVar2 = param_3;
  iVar24 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar2 = param_2;
      param_2 = param_4;
      iVar24 = param_3;
    }
LAB_1001a4b6:
    param_4 = iVar2;
    param_3 = param_2;
    param_2 = iVar24;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001a4b6;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar18 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar17 = *(uint *)(param_2 + 100);
  uVar22 = *(uint *)(param_2 + 0x68);
  uVar3 = *(int *)(param_2 + 0x58) >> 8;
  iVar2 = *(int *)(param_2 + 0x20);
  iVar20 = (int)*(short *)(param_3 + 0x1a);
  uVar16 = *(uint *)(param_3 + 0x68);
  uVar15 = *(uint *)(param_3 + 100);
  local_20 = *(int *)(param_3 + 0x58) >> 8;
  iVar1 = *(int *)(param_3 + 0x20);
  iVar21 = (int)*(short *)(param_4 + 0x1a);
  uVar19 = *(uint *)(param_4 + 100);
  uVar23 = *(uint *)(param_4 + 0x68);
  uVar4 = *(int *)(param_4 + 0x58) >> 8;
  iVar24 = *(int *)(param_4 + 0x20);
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2a0 = DAT_10077eb0;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar5 = DAT_10075214 + 0x1000;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  local_c = (short)((uint)*(int *)(param_4 + 0x58) >> 8);
  local_2c = (short)((uint)*(int *)(param_3 + 0x58) >> 8);
  local_3c = (short)((uint)*(int *)(param_2 + 0x58) >> 8);
  if (iVar18 < 1) {
    iVar18 = DAT_1007b280 - iVar20;
    if (iVar18 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    local_54 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_54 == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar6 = iVar21 - iVar20;
    if (local_54 == 1) {
      DAT_1007b28c = iVar6 * 0x10000;
    }
    else if (local_54 == 2) {
      DAT_1007b28c = iVar6 * 0x8000;
    }
    else if (((local_54 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar5 + (iVar6 * 0x20 + local_54) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b28c = (iVar6 * 0x10000) / local_54;
    }
    else {
      DAT_1007b28c = (iVar6 * 0x10000) / local_54;
    }
    iVar21 = iVar21 - DAT_1007b280;
    if (local_54 == 1) {
      DAT_1007b288 = iVar21 * 0x10000;
    }
    else if (local_54 == 2) {
      DAT_1007b288 = iVar21 * 0x8000;
    }
    else if (((local_54 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar5 + (iVar21 * 0x20 + local_54) * 4);
    }
    else if (iVar21 < 0) {
      DAT_1007b288 = (iVar21 * 0x10000) / local_54;
    }
    else {
      DAT_1007b288 = (iVar21 * 0x10000) / local_54;
    }
    if ((iVar1 == iVar2) || (iVar18 == 1)) {
      DAT_1007b2ec = iVar2 - iVar1;
    }
    else if (iVar18 == 2) {
      DAT_1007b2ec = iVar2 - iVar1 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar2 - iVar1) / iVar18;
    }
    if ((iVar24 == iVar1) || (local_54 == 1)) {
      DAT_1007b2e8 = iVar24 - iVar1;
    }
    else if (local_54 == 2) {
      DAT_1007b2e8 = iVar24 - iVar1 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar24 - iVar1) / local_54;
    }
    if ((uVar15 == uVar17) || (iVar18 == 1)) {
      uVar17 = uVar17 - uVar15;
    }
    else if (iVar18 == 2) {
      uVar17 = (int)(uVar17 - uVar15) >> 1;
    }
    else {
      uVar17 = (int)(uVar17 - uVar15) / iVar18;
    }
    if ((uVar19 == uVar15) || (local_54 == 1)) {
      uVar19 = uVar19 - uVar15;
    }
    else if (local_54 == 2) {
      uVar19 = (int)(uVar19 - uVar15) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar15) / local_54;
    }
    if ((uVar16 == uVar22) || (iVar18 == 1)) {
      uVar22 = uVar22 - uVar16;
    }
    else if (iVar18 == 2) {
      uVar22 = (int)(uVar22 - uVar16) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar16) / iVar18;
    }
    if ((uVar23 == uVar16) || (local_54 == 1)) {
      uVar23 = uVar23 - uVar16;
    }
    else if (local_54 == 2) {
      uVar23 = (int)(uVar23 - uVar16) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - uVar16) / local_54;
    }
    uVar3 = uVar3 & 0xffff;
    if ((local_2c == local_3c) || (iVar18 == 1)) {
      uVar3 = uVar3 - (local_20 & 0xffff);
    }
    else if (iVar18 == 2) {
      uVar3 = (int)(uVar3 - (local_20 & 0xffff)) >> 1;
    }
    else {
      uVar3 = (int)(uVar3 - (local_20 & 0xffff)) / iVar18;
    }
    uVar8 = local_20 & 0xffff;
    DAT_1007b2d4 = (uVar3 & 0xffff) + (uVar3 & 0x8000) * -2;
    uVar4 = uVar4 & 0xffff;
    if ((local_2c == local_c) || (local_54 == 1)) {
      uVar4 = uVar4 - uVar8;
    }
    else if (local_54 == 2) {
      uVar4 = (int)(uVar4 - uVar8) >> 1;
    }
    else {
      uVar4 = (int)(uVar4 - uVar8) / local_54;
    }
    DAT_1007b2d0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
    DAT_1007b2c0 = (uVar16 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar22 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar23 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    DAT_1007b2cc = local_20;
  }
  else {
    iVar6 = iVar20 - DAT_1007b280;
    if (iVar18 == 1) {
      DAT_1007b28c = iVar6 * 0x10000;
    }
    else if (iVar18 == 2) {
      DAT_1007b28c = iVar6 * 0x8000;
    }
    else if (((iVar18 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar5 + (iVar6 * 0x20 + iVar18) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b28c = (iVar6 * 0x10000) / iVar18;
    }
    else {
      DAT_1007b28c = (iVar6 * 0x10000) / iVar18;
    }
    iVar6 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (0 < iVar6) {
      iVar7 = iVar21 - DAT_1007b280;
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
      if ((uVar15 == uVar17) || (iVar18 == 1)) {
        uVar9 = uVar15 - uVar17;
      }
      else if (iVar18 == 2) {
        uVar9 = (int)(uVar15 - uVar17) >> 1;
      }
      else {
        uVar9 = (int)(uVar15 - uVar17) / iVar18;
        iVar13 = (int)(uVar15 - uVar17) % iVar18;
      }
      if ((uVar16 == uVar22) || (iVar18 == 1)) {
        uVar10 = uVar16 - uVar22;
      }
      else if (iVar18 == 2) {
        uVar10 = (int)(uVar16 - uVar22) >> 1;
      }
      else {
        uVar10 = (int)(uVar16 - uVar22) / iVar18;
        iVar13 = (int)(uVar16 - uVar22) % iVar18;
      }
      if ((uVar19 == uVar17) || (iVar6 == 1)) {
        iVar7 = uVar19 - uVar17;
      }
      else if (iVar6 == 2) {
        iVar7 = (int)(uVar19 - uVar17) >> 1;
      }
      else {
        iVar7 = (int)(uVar19 - uVar17) / iVar6;
        iVar13 = (int)(uVar19 - uVar17) % iVar6;
      }
      iVar7 = iVar7 - uVar9;
      uVar25 = CONCAT44(iVar13,iVar7);
      if (iVar7 != 0) {
        uVar25 = FUN_10063324(iVar7,iVar13,iVar7,uVar8);
      }
      iVar13 = (int)((ulonglong)uVar25 >> 0x20);
      local_1c = (uint)uVar25;
      if ((uVar23 == uVar22) || (iVar6 == 1)) {
        iVar7 = uVar23 - uVar22;
      }
      else if (iVar6 == 2) {
        iVar7 = (int)(uVar23 - uVar22) >> 1;
      }
      else {
        iVar7 = (int)(uVar23 - uVar22) / iVar6;
        iVar13 = (int)(uVar23 - uVar22) % iVar6;
      }
      iVar7 = iVar7 - uVar10;
      uVar11 = 0;
      if (iVar7 != 0) {
        uVar25 = FUN_10063324(iVar7,iVar13,iVar7,uVar8);
        uVar11 = (uint)uVar25;
      }
      uVar14 = uVar3 & 0xffff;
      if ((local_2c == local_3c) || (iVar18 == 1)) {
        uVar12 = (local_20 & 0xffff) - uVar14;
      }
      else if (iVar18 == 2) {
        uVar12 = (int)((local_20 & 0xffff) - uVar14) >> 1;
      }
      else {
        uVar12 = (int)((local_20 & 0xffff) - uVar14) / iVar18;
      }
      local_20 = local_20 & 0xffff;
      DAT_1007b2d4 = 0;
      DAT_1007b2d0 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
      if ((local_3c == local_c) || (iVar6 == 1)) {
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
      if ((iVar1 == iVar2) || (iVar18 == 1)) {
        DAT_1007b2e8 = iVar1 - iVar2;
      }
      else if (iVar18 == 2) {
        DAT_1007b2e8 = iVar1 - iVar2 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar1 - iVar2) / iVar18;
      }
      if ((iVar24 == iVar2) || (iVar6 == 1)) {
        iVar13 = iVar24 - iVar2;
      }
      else if (iVar6 == 2) {
        iVar13 = iVar24 - iVar2 >> 1;
      }
      else {
        iVar13 = (iVar24 - iVar2) / iVar6;
      }
      DAT_1007b2ec = iVar13 - DAT_1007b2e8;
      if ((DAT_1007b2ec != 0) && ((int)uVar8 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / ((int)uVar8 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar18 < iVar6) {
        DAT_1007b2c0 = (uVar22 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
        uVar17 = (uVar11 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
        DAT_1007b2c4 = (uVar10 & 0xfffe) << 0xf | (uVar9 & 0xfffe) >> 1;
        local_54 = iVar6 - iVar18;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar2;
        DAT_1007b290 = iVar18;
        DAT_1007b2c8 = uVar17;
        DAT_1007b2cc = uVar3;
        FUN_1001b510((uint *)&DAT_1007b280);
        DAT_1007b280 = iVar20 << 0x10;
        iVar21 = iVar21 - iVar20;
        if (local_54 == 1) {
          DAT_1007b28c = iVar21 * 0x10000;
        }
        else if (local_54 == 2) {
          DAT_1007b28c = iVar21 * 0x8000;
        }
        else if (((local_54 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar5 + (iVar21 * 0x20 + local_54) * 4);
        }
        else if (iVar21 < 0) {
          DAT_1007b28c = (iVar21 * 0x10000) / local_54;
        }
        else {
          DAT_1007b28c = (iVar21 * 0x10000) / local_54;
        }
        if ((uVar19 == uVar15) || (local_54 == 1)) {
          uVar19 = uVar19 - uVar15;
        }
        else if (local_54 == 2) {
          uVar19 = (int)(uVar19 - uVar15) >> 1;
        }
        else {
          uVar19 = (int)(uVar19 - uVar15) / local_54;
        }
        if ((uVar23 == uVar16) || (local_54 == 1)) {
          uVar23 = uVar23 - uVar16;
        }
        else if (local_54 == 2) {
          uVar23 = (int)(uVar23 - uVar16) >> 1;
        }
        else {
          uVar23 = (int)(uVar23 - uVar16) / local_54;
        }
        DAT_1007b2d0 = 0;
        if ((local_2c == local_c) || (local_54 == 1)) {
          uVar4 = uVar4 - local_20;
        }
        else if (local_54 == 2) {
          uVar4 = (int)(uVar4 - local_20) >> 1;
        }
        else {
          uVar4 = (int)(uVar4 - local_20) / local_54;
        }
        if (uVar4 != 0) {
          DAT_1007b2d0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
        }
        if ((iVar24 == iVar1) || (local_54 == 1)) {
          DAT_1007b2e8 = iVar24 - iVar1;
        }
        else if (local_54 == 2) {
          DAT_1007b2e8 = iVar24 - iVar1 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar24 - iVar1) / local_54;
        }
        DAT_1007b2c4 = (uVar23 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
        DAT_1007b2c8 = uVar17;
      }
      else {
        DAT_1007b2c0 = (uVar22 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
        DAT_1007b2c8 = (uVar11 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
        DAT_1007b2c4 = (uVar10 & 0xfffe) << 0xf | (uVar9 & 0xfffe) >> 1;
        local_54 = iVar18 - iVar6;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar2;
        DAT_1007b290 = iVar6;
        DAT_1007b2cc = uVar3;
        FUN_1001b510((uint *)&DAT_1007b280);
        if (local_54 == 0) {
          return;
        }
        DAT_1007b284 = iVar21 << 0x10;
        iVar20 = iVar20 - iVar21;
        if (local_54 == 1) {
          DAT_1007b288 = iVar20 * 0x10000;
        }
        else if (local_54 == 2) {
          DAT_1007b288 = iVar20 * 0x8000;
        }
        else if (((local_54 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar5 + (iVar20 * 0x20 + local_54) * 4);
        }
        else if (iVar20 < 0) {
          DAT_1007b288 = (iVar20 * 0x10000) / local_54;
        }
        else {
          DAT_1007b288 = (iVar20 * 0x10000) / local_54;
        }
      }
      goto LAB_1001b4ed;
    }
    iVar6 = iVar21 - DAT_1007b280;
    if (iVar6 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar20 = iVar20 - iVar21;
    if (iVar18 == 1) {
      DAT_1007b288 = iVar20 * 0x10000;
    }
    else if (iVar18 == 2) {
      DAT_1007b288 = iVar20 * 0x8000;
    }
    else if (((iVar18 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar5 + (iVar20 * 0x20 + iVar18) * 4);
    }
    else if (iVar20 < 0) {
      DAT_1007b288 = (iVar20 * 0x10000) / iVar18;
    }
    else {
      DAT_1007b288 = (iVar20 * 0x10000) / iVar18;
    }
    if ((iVar24 == iVar2) || (iVar6 == 1)) {
      DAT_1007b2ec = iVar24 - iVar2;
    }
    else if (iVar6 == 2) {
      DAT_1007b2ec = iVar24 - iVar2 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar24 - iVar2) / iVar6;
    }
    if ((iVar1 == iVar2) || (iVar18 == 1)) {
      DAT_1007b2e8 = iVar1 - iVar2;
    }
    else if (iVar18 == 2) {
      DAT_1007b2e8 = iVar1 - iVar2 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar1 - iVar2) / iVar18;
    }
    if ((uVar19 == uVar17) || (iVar6 == 1)) {
      uVar19 = uVar19 - uVar17;
    }
    else if (iVar6 == 2) {
      uVar19 = (int)(uVar19 - uVar17) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar17) / iVar6;
    }
    if ((uVar23 == uVar22) || (iVar6 == 1)) {
      uVar23 = uVar23 - uVar22;
    }
    else if (iVar6 == 2) {
      uVar23 = (int)(uVar23 - uVar22) >> 1;
    }
    else {
      uVar23 = (int)(uVar23 - uVar22) / iVar6;
    }
    if ((uVar15 == uVar17) || (iVar18 == 1)) {
      uVar15 = uVar15 - uVar17;
    }
    else if (iVar18 == 2) {
      uVar15 = (int)(uVar15 - uVar17) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar17) / iVar18;
    }
    if ((uVar16 == uVar22) || (iVar18 == 1)) {
      uVar16 = uVar16 - uVar22;
    }
    else if (iVar18 == 2) {
      uVar16 = (int)(uVar16 - uVar22) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar22) / iVar18;
    }
    uVar4 = uVar4 & 0xffff;
    if ((local_3c == local_c) || (iVar6 == 1)) {
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
    local_20 = local_20 & 0xffff;
    if ((local_2c == local_3c) || (iVar18 == 1)) {
      local_20 = local_20 - uVar8;
    }
    else if (iVar18 == 2) {
      local_20 = (int)(local_20 - uVar8) >> 1;
    }
    else {
      local_20 = (int)(local_20 - uVar8) / iVar18;
    }
    DAT_1007b2d0 = (local_20 & 0xffff) + (local_20 & 0x8000) * -2;
    DAT_1007b2c0 = (uVar22 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar23 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar16 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
    DAT_1007b2cc = uVar3;
    local_54 = iVar18;
    iVar1 = iVar2;
    iVar20 = DAT_1007b280;
    DAT_1007b280 = iVar21;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar20 << 0x10;
  DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
LAB_1001b4ed:
  DAT_1007b290 = local_54;
  FUN_1001b510((uint *)&DAT_1007b280);
  return;
}


