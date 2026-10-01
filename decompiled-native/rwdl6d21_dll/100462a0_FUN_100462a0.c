// 100462a0 FUN_100462a0 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100462a0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  undefined8 uVar17;
  int local_30;
  uint local_1c;
  
  iVar3 = param_3;
  iVar1 = param_4;
  iVar15 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar3 = param_2;
      iVar1 = param_3;
      iVar15 = param_4;
    }
LAB_100462e6:
    param_4 = iVar3;
    param_2 = iVar1;
    param_3 = iVar15;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_100462e6;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  local_30 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar11 = *(int *)(param_2 + 0x68) >> 3;
  uVar14 = *(int *)(param_2 + 100) >> 3;
  iVar1 = (int)*(short *)(param_3 + 0x1a);
  uVar12 = *(int *)(param_3 + 100) >> 3;
  iVar15 = (int)*(short *)(param_4 + 0x1a);
  uVar2 = *(int *)(param_3 + 0x68) >> 3;
  uVar16 = *(int *)(param_4 + 100) >> 3;
  uVar13 = *(int *)(param_4 + 0x68) >> 3;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007f2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10079220;
  _DAT_1007f2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10079220 + 0x400;
  _DAT_1007f2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10079220 + 0x800;
  DAT_1007f298 = DAT_1007bda4;
  iVar3 = DAT_10079214 + 0x1000;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  if (local_30 < 1) {
    iVar4 = DAT_1007f280 - iVar1;
    if (iVar4 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    local_30 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_30 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    iVar10 = iVar15 - iVar1;
    if (local_30 == 1) {
      DAT_1007f28c = iVar10 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007f28c = iVar10 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar3 + (iVar10 * 0x20 + local_30) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f28c = (iVar10 * 0x10000) / local_30;
    }
    else {
      DAT_1007f28c = (iVar10 * 0x10000) / local_30;
    }
    iVar15 = iVar15 - DAT_1007f280;
    if (local_30 == 1) {
      DAT_1007f288 = iVar15 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007f288 = iVar15 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar3 + (iVar15 * 0x20 + local_30) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007f288 = (iVar15 * 0x10000) / local_30;
    }
    else {
      DAT_1007f288 = (iVar15 * 0x10000) / local_30;
    }
    if ((uVar12 == uVar14) || (iVar4 == 1)) {
      uVar14 = uVar14 - uVar12;
    }
    else if (iVar4 == 2) {
      uVar14 = (int)(uVar14 - uVar12) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar12) / iVar4;
    }
    if ((uVar16 == uVar12) || (local_30 == 1)) {
      uVar16 = uVar16 - uVar12;
    }
    else if (local_30 == 2) {
      uVar16 = (int)(uVar16 - uVar12) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar12) / local_30;
    }
    if ((uVar2 == uVar11) || (iVar4 == 1)) {
      uVar11 = uVar11 - uVar2;
    }
    else if (iVar4 == 2) {
      uVar11 = (int)(uVar11 - uVar2) >> 1;
    }
    else {
      uVar11 = (int)(uVar11 - uVar2) / iVar4;
    }
    if ((uVar13 == uVar2) || (local_30 == 1)) {
      uVar13 = uVar13 - uVar2;
    }
    else if (local_30 == 2) {
      uVar13 = (int)(uVar13 - uVar2) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - uVar2) / local_30;
    }
    DAT_1007f284 = DAT_1007f280 << 0x10;
    DAT_1007f2c0 = (uVar2 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
    DAT_1007f2c8 = (uVar11 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
  }
  else {
    iVar4 = iVar1 - DAT_1007f280;
    if (local_30 == 1) {
      DAT_1007f28c = iVar4 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007f28c = iVar4 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar3 + (iVar4 * 0x20 + local_30) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1007f28c = (iVar4 * 0x10000) / local_30;
    }
    else {
      DAT_1007f28c = (iVar4 * 0x10000) / local_30;
    }
    iVar4 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (iVar4 < 1) {
      iVar4 = iVar15 - DAT_1007f280;
      if (iVar4 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar1 = iVar1 - iVar15;
      if (local_30 == 1) {
        DAT_1007f288 = iVar1 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1007f288 = iVar1 * 0x8000;
      }
      else if (((local_30 < 0x20) && (-0x20 < iVar1)) && (iVar1 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar3 + (iVar1 * 0x20 + local_30) * 4);
      }
      else if (iVar1 < 0) {
        DAT_1007f288 = (iVar1 * 0x10000) / local_30;
      }
      else {
        DAT_1007f288 = (iVar1 * 0x10000) / local_30;
      }
      if ((uVar16 == uVar14) || (iVar4 == 1)) {
        uVar16 = uVar16 - uVar14;
      }
      else if (iVar4 == 2) {
        uVar16 = (int)(uVar16 - uVar14) >> 1;
      }
      else {
        uVar16 = (int)(uVar16 - uVar14) / iVar4;
      }
      if ((uVar13 == uVar11) || (iVar4 == 1)) {
        uVar13 = uVar13 - uVar11;
      }
      else if (iVar4 == 2) {
        uVar13 = (int)(uVar13 - uVar11) >> 1;
      }
      else {
        uVar13 = (int)(uVar13 - uVar11) / iVar4;
      }
      if ((uVar12 == uVar14) || (local_30 == 1)) {
        uVar12 = uVar12 - uVar14;
      }
      else if (local_30 == 2) {
        uVar12 = (int)(uVar12 - uVar14) >> 1;
      }
      else {
        uVar12 = (int)(uVar12 - uVar14) / local_30;
      }
      if ((uVar2 == uVar11) || (local_30 == 1)) {
        uVar2 = uVar2 - uVar11;
      }
      else if (local_30 == 2) {
        uVar2 = (int)(uVar2 - uVar11) >> 1;
      }
      else {
        uVar2 = (int)(uVar2 - uVar11) / local_30;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = iVar15 << 0x10;
      DAT_1007f2c0 = (uVar11 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
      DAT_1007f2c8 = (uVar13 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
      DAT_1007f2c4 = (uVar2 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
      goto LAB_10046d15;
    }
    iVar5 = iVar15 - DAT_1007f280;
    iVar10 = iVar4;
    if (iVar4 == 1) {
      DAT_1007f288 = iVar5 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007f288 = iVar5 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar3 + (iVar5 * 0x20 + iVar4) * 4);
      iVar10 = iVar3;
    }
    else if (iVar5 < 0) {
      DAT_1007f288 = (iVar5 * 0x10000) / iVar4;
      iVar10 = (iVar5 * 0x10000) % iVar4;
    }
    else {
      DAT_1007f288 = (iVar5 * 0x10000) / iVar4;
      iVar10 = (iVar5 * 0x10000) % iVar4;
    }
    iVar5 = DAT_1007f288 - DAT_1007f28c;
    if (iVar5 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    if ((uVar12 == uVar14) || (local_30 == 1)) {
      uVar6 = uVar12 - uVar14;
    }
    else if (local_30 == 2) {
      uVar6 = (int)(uVar12 - uVar14) >> 1;
    }
    else {
      uVar6 = (int)(uVar12 - uVar14) / local_30;
      iVar10 = (int)(uVar12 - uVar14) % local_30;
    }
    if ((uVar2 == uVar11) || (local_30 == 1)) {
      uVar7 = uVar2 - uVar11;
    }
    else if (local_30 == 2) {
      uVar7 = (int)(uVar2 - uVar11) >> 1;
    }
    else {
      uVar7 = (int)(uVar2 - uVar11) / local_30;
      iVar10 = (int)(uVar2 - uVar11) % local_30;
    }
    if ((uVar16 == uVar14) || (iVar4 == 1)) {
      iVar8 = uVar16 - uVar14;
    }
    else if (iVar4 == 2) {
      iVar8 = (int)(uVar16 - uVar14) >> 1;
    }
    else {
      iVar8 = (int)(uVar16 - uVar14) / iVar4;
      iVar10 = (int)(uVar16 - uVar14) % iVar4;
    }
    uVar9 = iVar8 - uVar6;
    uVar17 = CONCAT44(iVar10,uVar9);
    if (uVar9 != 0) {
      uVar17 = FUN_10069324(iVar5,iVar10,uVar9,iVar5);
    }
    iVar10 = (int)((ulonglong)uVar17 >> 0x20);
    local_1c = (uint)uVar17;
    if ((uVar13 == uVar11) || (iVar4 == 1)) {
      iVar8 = uVar13 - uVar11;
    }
    else if (iVar4 == 2) {
      iVar8 = (int)(uVar13 - uVar11) >> 1;
    }
    else {
      iVar8 = (int)(uVar13 - uVar11) / iVar4;
      iVar10 = (int)(uVar13 - uVar11) % iVar4;
    }
    uVar9 = 0;
    if (iVar8 - uVar7 != 0) {
      uVar17 = FUN_10069324(iVar5,iVar10,iVar8 - uVar7,iVar5);
      uVar9 = (uint)uVar17;
    }
    DAT_1007f280 = DAT_1007f280 << 0x10;
    DAT_1007f284 = DAT_1007f280;
    if (iVar4 <= local_30) {
      DAT_1007f2c0 = (uVar11 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
      DAT_1007f2c8 = (uVar9 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
      DAT_1007f2c4 = (uVar7 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
      local_30 = local_30 - iVar4;
      DAT_1007f290 = iVar4;
      FUN_10046d40((uint *)&DAT_1007f280);
      if (local_30 == 0) {
        return;
      }
      DAT_1007f284 = iVar15 << 0x10;
      iVar1 = iVar1 - iVar15;
      if (local_30 == 1) {
        DAT_1007f288 = iVar1 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1007f288 = iVar1 * 0x8000;
      }
      else if (((local_30 < 0x20) && (-0x20 < iVar1)) && (iVar1 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar3 + (iVar1 * 0x20 + local_30) * 4);
      }
      else if (iVar1 < 0) {
        DAT_1007f288 = (iVar1 * 0x10000) / local_30;
      }
      else {
        DAT_1007f288 = (iVar1 * 0x10000) / local_30;
      }
      goto LAB_10046d15;
    }
    DAT_1007f2c0 = (uVar11 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    uVar14 = (uVar9 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
    DAT_1007f2c4 = (uVar7 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
    iVar4 = iVar4 - local_30;
    DAT_1007f290 = local_30;
    DAT_1007f2c8 = uVar14;
    FUN_10046d40((uint *)&DAT_1007f280);
    iVar15 = iVar15 - iVar1;
    if (iVar4 == 1) {
      DAT_1007f28c = iVar15 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007f28c = iVar15 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar3 + (iVar15 * 0x20 + iVar4) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007f28c = (iVar15 * 0x10000) / iVar4;
    }
    else {
      DAT_1007f28c = (iVar15 * 0x10000) / iVar4;
    }
    if ((uVar16 == uVar12) || (iVar4 == 1)) {
      uVar16 = uVar16 - uVar12;
    }
    else if (iVar4 == 2) {
      uVar16 = (int)(uVar16 - uVar12) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar12) / iVar4;
    }
    local_30 = iVar4;
    if ((uVar13 == uVar2) || (iVar4 == 1)) {
      uVar13 = uVar13 - uVar2;
      DAT_1007f2c8 = uVar14;
    }
    else if (iVar4 == 2) {
      uVar13 = (int)(uVar13 - uVar2) >> 1;
      DAT_1007f2c8 = uVar14;
    }
    else {
      uVar13 = (int)(uVar13 - uVar2) / iVar4;
      DAT_1007f2c8 = uVar14;
    }
  }
  DAT_1007f280 = iVar1 << 0x10;
  DAT_1007f2c4 = (uVar13 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
LAB_10046d15:
  DAT_1007f290 = local_30;
  FUN_10046d40((uint *)&DAT_1007f280);
  return;
}


