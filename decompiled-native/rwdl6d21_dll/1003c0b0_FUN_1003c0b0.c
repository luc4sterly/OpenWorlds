// 1003c0b0 FUN_1003c0b0 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1003c0b0(int *param_1,int param_2,int param_3,int param_4)

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
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  int local_30;
  uint local_20;
  
  iVar3 = param_3;
  iVar1 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar3 = param_2;
      param_2 = param_4;
      iVar1 = param_3;
    }
LAB_1003c0f6:
    param_3 = param_2;
    param_4 = iVar3;
    param_2 = iVar1;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1003c0f6;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  local_30 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  iVar1 = (int)*(short *)(param_3 + 0x1a);
  uVar16 = *(int *)(param_2 + 0x68) >> 3;
  uVar12 = *(int *)(param_2 + 100) >> 3;
  iVar10 = (int)*(short *)(param_4 + 0x1a);
  uVar13 = *(int *)(param_3 + 100) >> 3;
  uVar2 = *(int *)(param_3 + 0x68) >> 3;
  uVar14 = *(int *)(param_4 + 100) >> 3;
  uVar15 = *(int *)(param_4 + 0x68) >> 3;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007f2a8 = (uint)*(byte *)(*param_1 + 4);
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
    iVar11 = iVar10 - iVar1;
    if (local_30 == 1) {
      DAT_1007f28c = iVar11 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007f28c = iVar11 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar3 + (iVar11 * 0x20 + local_30) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1007f28c = (iVar11 * 0x10000) / local_30;
    }
    else {
      DAT_1007f28c = (iVar11 * 0x10000) / local_30;
    }
    iVar10 = iVar10 - DAT_1007f280;
    if (local_30 == 1) {
      DAT_1007f288 = iVar10 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007f288 = iVar10 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar3 + (iVar10 * 0x20 + local_30) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f288 = (iVar10 * 0x10000) / local_30;
    }
    else {
      DAT_1007f288 = (iVar10 * 0x10000) / local_30;
    }
    if ((uVar13 == uVar12) || (iVar4 == 1)) {
      uVar12 = uVar12 - uVar13;
    }
    else if (iVar4 == 2) {
      uVar12 = (int)(uVar12 - uVar13) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar13) / iVar4;
    }
    if ((uVar14 == uVar13) || (local_30 == 1)) {
      uVar14 = uVar14 - uVar13;
    }
    else if (local_30 == 2) {
      uVar14 = (int)(uVar14 - uVar13) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar13) / local_30;
    }
    if ((uVar2 == uVar16) || (iVar4 == 1)) {
      uVar16 = uVar16 - uVar2;
    }
    else if (iVar4 == 2) {
      uVar16 = (int)(uVar16 - uVar2) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar2) / iVar4;
    }
    if ((uVar15 == uVar2) || (local_30 == 1)) {
      uVar15 = uVar15 - uVar2;
    }
    else if (local_30 == 2) {
      uVar15 = (int)(uVar15 - uVar2) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar2) / local_30;
    }
    DAT_1007f284 = DAT_1007f280 << 0x10;
    DAT_1007f2c0 = (uVar2 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
    DAT_1007f2c8 = (uVar12 & 0xfffe) >> 1 | (uVar16 & 0xfffe) << 0xf;
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
      iVar4 = iVar10 - DAT_1007f280;
      if (iVar4 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar1 = iVar1 - iVar10;
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
      if ((uVar14 == uVar12) || (iVar4 == 1)) {
        uVar14 = uVar14 - uVar12;
      }
      else if (iVar4 == 2) {
        uVar14 = (int)(uVar14 - uVar12) >> 1;
      }
      else {
        uVar14 = (int)(uVar14 - uVar12) / iVar4;
      }
      if ((uVar15 == uVar16) || (iVar4 == 1)) {
        uVar15 = uVar15 - uVar16;
      }
      else if (iVar4 == 2) {
        uVar15 = (int)(uVar15 - uVar16) >> 1;
      }
      else {
        uVar15 = (int)(uVar15 - uVar16) / iVar4;
      }
      if ((uVar13 == uVar12) || (local_30 == 1)) {
        uVar13 = uVar13 - uVar12;
      }
      else if (local_30 == 2) {
        uVar13 = (int)(uVar13 - uVar12) >> 1;
      }
      else {
        uVar13 = (int)(uVar13 - uVar12) / local_30;
      }
      if ((uVar2 == uVar16) || (local_30 == 1)) {
        uVar2 = uVar2 - uVar16;
      }
      else if (local_30 == 2) {
        uVar2 = (int)(uVar2 - uVar16) >> 1;
      }
      else {
        uVar2 = (int)(uVar2 - uVar16) / local_30;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = iVar10 << 0x10;
      DAT_1007f2c0 = (uVar12 & 0xfffe) >> 1 | (uVar16 & 0xfffe) << 0xf;
      DAT_1007f2c8 = (uVar14 & 0xfffe) >> 1 | (uVar15 & 0xfffe) << 0xf;
      DAT_1007f2c4 = (uVar13 & 0xfffe) >> 1 | (uVar2 & 0xfffe) << 0xf;
      goto LAB_1003cae3;
    }
    iVar5 = iVar10 - DAT_1007f280;
    iVar11 = iVar4;
    if (iVar4 == 1) {
      DAT_1007f288 = iVar5 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007f288 = iVar5 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar3 + (iVar5 * 0x20 + iVar4) * 4);
      iVar11 = iVar3;
    }
    else if (iVar5 < 0) {
      DAT_1007f288 = (iVar5 * 0x10000) / iVar4;
      iVar11 = (iVar5 * 0x10000) % iVar4;
    }
    else {
      DAT_1007f288 = (iVar5 * 0x10000) / iVar4;
      iVar11 = (iVar5 * 0x10000) % iVar4;
    }
    iVar5 = DAT_1007f288 - DAT_1007f28c;
    if (iVar5 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    if ((uVar13 == uVar12) || (local_30 == 1)) {
      uVar6 = uVar13 - uVar12;
    }
    else if (local_30 == 2) {
      uVar6 = (int)(uVar13 - uVar12) >> 1;
    }
    else {
      uVar6 = (int)(uVar13 - uVar12) / local_30;
      iVar11 = (int)(uVar13 - uVar12) % local_30;
    }
    if ((uVar2 == uVar16) || (local_30 == 1)) {
      uVar7 = uVar2 - uVar16;
    }
    else if (local_30 == 2) {
      uVar7 = (int)(uVar2 - uVar16) >> 1;
    }
    else {
      uVar7 = (int)(uVar2 - uVar16) / local_30;
      iVar11 = (int)(uVar2 - uVar16) % local_30;
    }
    if ((uVar14 == uVar12) || (iVar4 == 1)) {
      iVar8 = uVar14 - uVar12;
    }
    else if (iVar4 == 2) {
      iVar8 = (int)(uVar14 - uVar12) >> 1;
    }
    else {
      iVar8 = (int)(uVar14 - uVar12) / iVar4;
      iVar11 = (int)(uVar14 - uVar12) % iVar4;
    }
    uVar9 = iVar8 - uVar6;
    uVar17 = CONCAT44(iVar11,uVar9);
    if (uVar9 != 0) {
      uVar17 = FUN_10069324(iVar5,iVar11,uVar9,iVar5);
    }
    iVar11 = (int)((ulonglong)uVar17 >> 0x20);
    local_20 = (uint)uVar17;
    if ((uVar15 == uVar16) || (iVar4 == 1)) {
      iVar8 = uVar15 - uVar16;
    }
    else if (iVar4 == 2) {
      iVar8 = (int)(uVar15 - uVar16) >> 1;
    }
    else {
      iVar8 = (int)(uVar15 - uVar16) / iVar4;
      iVar11 = (int)(uVar15 - uVar16) % iVar4;
    }
    uVar9 = 0;
    if (iVar8 - uVar7 != 0) {
      uVar17 = FUN_10069324(iVar5,iVar11,iVar8 - uVar7,iVar5);
      uVar9 = (uint)uVar17;
    }
    DAT_1007f280 = DAT_1007f280 << 0x10;
    DAT_1007f284 = DAT_1007f280;
    if (iVar4 <= local_30) {
      DAT_1007f2c0 = (uVar12 & 0xfffe) >> 1 | (uVar16 & 0xfffe) << 0xf;
      DAT_1007f2c8 = (local_20 & 0xfffe) >> 1 | (uVar9 & 0xfffe) << 0xf;
      DAT_1007f2c4 = (uVar6 & 0xfffe) >> 1 | (uVar7 & 0xfffe) << 0xf;
      local_30 = local_30 - iVar4;
      DAT_1007f290 = iVar4;
      FUN_1003cb00((uint *)&DAT_1007f280);
      if (local_30 == 0) {
        return;
      }
      DAT_1007f284 = iVar10 << 0x10;
      iVar1 = iVar1 - iVar10;
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
      goto LAB_1003cae3;
    }
    DAT_1007f2c0 = (uVar12 & 0xfffe) >> 1 | (uVar16 & 0xfffe) << 0xf;
    uVar12 = (local_20 & 0xfffe) >> 1 | (uVar9 & 0xfffe) << 0xf;
    iVar4 = iVar4 - local_30;
    DAT_1007f2c4 = (uVar6 & 0xfffe) >> 1 | (uVar7 & 0xfffe) << 0xf;
    DAT_1007f290 = local_30;
    DAT_1007f2c8 = uVar12;
    FUN_1003cb00((uint *)&DAT_1007f280);
    iVar10 = iVar10 - iVar1;
    if (iVar4 == 1) {
      DAT_1007f28c = iVar10 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007f28c = iVar10 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar3 + (iVar10 * 0x20 + iVar4) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007f28c = (iVar10 * 0x10000) / iVar4;
    }
    else {
      DAT_1007f28c = (iVar10 * 0x10000) / iVar4;
    }
    if ((uVar14 == uVar13) || (iVar4 == 1)) {
      uVar14 = uVar14 - uVar13;
    }
    else if (iVar4 == 2) {
      uVar14 = (int)(uVar14 - uVar13) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar13) / iVar4;
    }
    local_30 = iVar4;
    if ((uVar15 == uVar2) || (iVar4 == 1)) {
      uVar15 = uVar15 - uVar2;
      DAT_1007f2c8 = uVar12;
    }
    else if (iVar4 == 2) {
      uVar15 = (int)(uVar15 - uVar2) >> 1;
      DAT_1007f2c8 = uVar12;
    }
    else {
      uVar15 = (int)(uVar15 - uVar2) / iVar4;
      DAT_1007f2c8 = uVar12;
    }
  }
  DAT_1007f280 = iVar1 << 0x10;
  DAT_1007f2c4 = (uVar14 & 0xfffe) >> 1 | (uVar15 & 0xfffe) << 0xf;
LAB_1003cae3:
  DAT_1007f290 = local_30;
  FUN_1003cb00((uint *)&DAT_1007f280);
  return;
}


