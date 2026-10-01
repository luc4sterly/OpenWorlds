// 10013e10 FUN_10013e10 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013e10(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  int local_30;
  uint local_c;
  
  iVar1 = param_3;
  iVar12 = param_4;
  iVar13 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      iVar12 = param_3;
      iVar13 = param_4;
    }
LAB_10013e56:
    param_4 = iVar1;
    param_2 = iVar12;
    param_3 = iVar13;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10013e56;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  local_30 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar8 = *(uint *)(param_2 + 100);
  uVar14 = *(uint *)(param_2 + 0x68);
  uVar10 = *(uint *)(param_3 + 100);
  iVar12 = (int)*(short *)(param_3 + 0x1a);
  uVar9 = *(uint *)(param_3 + 0x68);
  uVar16 = *(uint *)(param_4 + 100);
  iVar13 = (int)*(short *)(param_4 + 0x1a);
  uVar15 = *(uint *)(param_4 + 0x68);
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  iVar1 = DAT_10075214 + 0x1000;
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  if (local_30 < 1) {
    iVar2 = DAT_1007b280 - iVar12;
    if (iVar2 < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    local_30 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_30 == 0) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    iVar11 = iVar13 - iVar12;
    if (local_30 == 1) {
      DAT_1007b28c = iVar11 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007b28c = iVar11 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar1 + (iVar11 * 0x20 + local_30) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1007b28c = (iVar11 * 0x10000) / local_30;
    }
    else {
      DAT_1007b28c = (iVar11 * 0x10000) / local_30;
    }
    iVar13 = iVar13 - DAT_1007b280;
    if (local_30 == 1) {
      DAT_1007b288 = iVar13 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007b288 = iVar13 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar1 + (iVar13 * 0x20 + local_30) * 4);
    }
    else if (iVar13 < 0) {
      DAT_1007b288 = (iVar13 * 0x10000) / local_30;
    }
    else {
      DAT_1007b288 = (iVar13 * 0x10000) / local_30;
    }
    if ((uVar10 == uVar8) || (iVar2 == 1)) {
      uVar8 = uVar8 - uVar10;
    }
    else if (iVar2 == 2) {
      uVar8 = (int)(uVar8 - uVar10) >> 1;
    }
    else {
      uVar8 = (int)(uVar8 - uVar10) / iVar2;
    }
    if ((uVar16 == uVar10) || (local_30 == 1)) {
      uVar16 = uVar16 - uVar10;
    }
    else if (local_30 == 2) {
      uVar16 = (int)(uVar16 - uVar10) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar10) / local_30;
    }
    if ((uVar9 == uVar14) || (iVar2 == 1)) {
      uVar14 = uVar14 - uVar9;
    }
    else if (iVar2 == 2) {
      uVar14 = (int)(uVar14 - uVar9) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar9) / iVar2;
    }
    if ((uVar15 == uVar9) || (local_30 == 1)) {
      uVar15 = uVar15 - uVar9;
    }
    else if (local_30 == 2) {
      uVar15 = (int)(uVar15 - uVar9) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar9) / local_30;
    }
    DAT_1007b284 = DAT_1007b280 << 0x10;
    DAT_1007b2c0 = (uVar9 & 0xfffe) << 0xf | (uVar10 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar14 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
  }
  else {
    iVar2 = iVar12 - DAT_1007b280;
    if (local_30 == 1) {
      DAT_1007b28c = iVar2 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007b28c = iVar2 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar1 + (iVar2 * 0x20 + local_30) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007b28c = (iVar2 * 0x10000) / local_30;
    }
    else {
      DAT_1007b28c = (iVar2 * 0x10000) / local_30;
    }
    iVar2 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (iVar2 < 1) {
      iVar2 = iVar13 - DAT_1007b280;
      if (iVar2 < 1) {
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      iVar12 = iVar12 - iVar13;
      if (local_30 == 1) {
        DAT_1007b288 = iVar12 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1007b288 = iVar12 * 0x8000;
      }
      else if (((local_30 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar1 + (iVar12 * 0x20 + local_30) * 4);
      }
      else if (iVar12 < 0) {
        DAT_1007b288 = (iVar12 * 0x10000) / local_30;
      }
      else {
        DAT_1007b288 = (iVar12 * 0x10000) / local_30;
      }
      if ((uVar16 == uVar8) || (iVar2 == 1)) {
        uVar16 = uVar16 - uVar8;
      }
      else if (iVar2 == 2) {
        uVar16 = (int)(uVar16 - uVar8) >> 1;
      }
      else {
        uVar16 = (int)(uVar16 - uVar8) / iVar2;
      }
      if ((uVar15 == uVar14) || (iVar2 == 1)) {
        uVar15 = uVar15 - uVar14;
      }
      else if (iVar2 == 2) {
        uVar15 = (int)(uVar15 - uVar14) >> 1;
      }
      else {
        uVar15 = (int)(uVar15 - uVar14) / iVar2;
      }
      if ((uVar10 == uVar8) || (local_30 == 1)) {
        uVar10 = uVar10 - uVar8;
      }
      else if (local_30 == 2) {
        uVar10 = (int)(uVar10 - uVar8) >> 1;
      }
      else {
        uVar10 = (int)(uVar10 - uVar8) / local_30;
      }
      if ((uVar9 == uVar14) || (local_30 == 1)) {
        uVar9 = uVar9 - uVar14;
      }
      else if (local_30 == 2) {
        uVar9 = (int)(uVar9 - uVar14) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - uVar14) / local_30;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = iVar13 << 0x10;
      DAT_1007b2c0 = (uVar14 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
      DAT_1007b2c8 = (uVar15 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
      DAT_1007b2c4 = (uVar9 & 0xfffe) << 0xf | (uVar10 & 0xfffe) >> 1;
      goto LAB_1001483b;
    }
    iVar3 = iVar13 - DAT_1007b280;
    iVar11 = iVar2;
    if (iVar2 == 1) {
      DAT_1007b288 = iVar3 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b288 = iVar3 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar1 + (iVar3 * 0x20 + iVar2) * 4);
      iVar11 = iVar1;
    }
    else if (iVar3 < 0) {
      DAT_1007b288 = (iVar3 * 0x10000) / iVar2;
      iVar11 = (iVar3 * 0x10000) % iVar2;
    }
    else {
      DAT_1007b288 = (iVar3 * 0x10000) / iVar2;
      iVar11 = (iVar3 * 0x10000) % iVar2;
    }
    iVar3 = DAT_1007b288 - DAT_1007b28c;
    if (iVar3 < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    if ((uVar10 == uVar8) || (local_30 == 1)) {
      uVar4 = uVar10 - uVar8;
    }
    else if (local_30 == 2) {
      uVar4 = (int)(uVar10 - uVar8) >> 1;
    }
    else {
      uVar4 = (int)(uVar10 - uVar8) / local_30;
      iVar11 = (int)(uVar10 - uVar8) % local_30;
    }
    if ((uVar9 == uVar14) || (local_30 == 1)) {
      uVar5 = uVar9 - uVar14;
    }
    else if (local_30 == 2) {
      uVar5 = (int)(uVar9 - uVar14) >> 1;
    }
    else {
      uVar5 = (int)(uVar9 - uVar14) / local_30;
      iVar11 = (int)(uVar9 - uVar14) % local_30;
    }
    if ((uVar16 == uVar8) || (iVar2 == 1)) {
      iVar6 = uVar16 - uVar8;
    }
    else if (iVar2 == 2) {
      iVar6 = (int)(uVar16 - uVar8) >> 1;
    }
    else {
      iVar6 = (int)(uVar16 - uVar8) / iVar2;
      iVar11 = (int)(uVar16 - uVar8) % iVar2;
    }
    uVar7 = iVar6 - uVar4;
    uVar17 = CONCAT44(iVar11,uVar7);
    if (uVar7 != 0) {
      uVar17 = FUN_10063324(iVar3,iVar11,uVar7,iVar3);
    }
    iVar11 = (int)((ulonglong)uVar17 >> 0x20);
    local_c = (uint)uVar17;
    if ((uVar15 == uVar14) || (iVar2 == 1)) {
      iVar6 = uVar15 - uVar14;
    }
    else if (iVar2 == 2) {
      iVar6 = (int)(uVar15 - uVar14) >> 1;
    }
    else {
      iVar6 = (int)(uVar15 - uVar14) / iVar2;
      iVar11 = (int)(uVar15 - uVar14) % iVar2;
    }
    uVar7 = 0;
    if (iVar6 - uVar5 != 0) {
      uVar17 = FUN_10063324(iVar3,iVar11,iVar6 - uVar5,iVar3);
      uVar7 = (uint)uVar17;
    }
    DAT_1007b280 = DAT_1007b280 << 0x10;
    DAT_1007b284 = DAT_1007b280;
    if (iVar2 <= local_30) {
      DAT_1007b2c0 = (uVar14 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
      DAT_1007b2c8 = (uVar7 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
      DAT_1007b2c4 = (uVar5 & 0xfffe) << 0xf | (uVar4 & 0xfffe) >> 1;
      local_30 = local_30 - iVar2;
      DAT_1007b290 = iVar2;
      FUN_10014860((uint *)&DAT_1007b280);
      if (local_30 == 0) {
        return;
      }
      DAT_1007b284 = iVar13 << 0x10;
      iVar12 = iVar12 - iVar13;
      if (local_30 == 1) {
        DAT_1007b288 = iVar12 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1007b288 = iVar12 * 0x8000;
      }
      else if (((local_30 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar1 + (iVar12 * 0x20 + local_30) * 4);
      }
      else if (iVar12 < 0) {
        DAT_1007b288 = (iVar12 * 0x10000) / local_30;
      }
      else {
        DAT_1007b288 = (iVar12 * 0x10000) / local_30;
      }
      goto LAB_1001483b;
    }
    DAT_1007b2c0 = (uVar14 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
    uVar8 = (uVar7 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar5 & 0xfffe) << 0xf | (uVar4 & 0xfffe) >> 1;
    iVar2 = iVar2 - local_30;
    DAT_1007b290 = local_30;
    DAT_1007b2c8 = uVar8;
    FUN_10014860((uint *)&DAT_1007b280);
    iVar13 = iVar13 - iVar12;
    if (iVar2 == 1) {
      DAT_1007b28c = iVar13 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b28c = iVar13 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar1 + (iVar13 * 0x20 + iVar2) * 4);
    }
    else if (iVar13 < 0) {
      DAT_1007b28c = (iVar13 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b28c = (iVar13 * 0x10000) / iVar2;
    }
    if ((uVar16 == uVar10) || (iVar2 == 1)) {
      uVar16 = uVar16 - uVar10;
    }
    else if (iVar2 == 2) {
      uVar16 = (int)(uVar16 - uVar10) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar10) / iVar2;
    }
    local_30 = iVar2;
    if ((uVar15 == uVar9) || (iVar2 == 1)) {
      uVar15 = uVar15 - uVar9;
      DAT_1007b2c8 = uVar8;
    }
    else if (iVar2 == 2) {
      uVar15 = (int)(uVar15 - uVar9) >> 1;
      DAT_1007b2c8 = uVar8;
    }
    else {
      uVar15 = (int)(uVar15 - uVar9) / iVar2;
      DAT_1007b2c8 = uVar8;
    }
  }
  DAT_1007b280 = iVar12 << 0x10;
  DAT_1007b2c4 = (uVar15 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
LAB_1001483b:
  DAT_1007b290 = local_30;
  FUN_10014860((uint *)&DAT_1007b280);
  return;
}


