// 1001dd70 FUN_1001dd70 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001dd70(int *param_1,int param_2,int param_3,int param_4)

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
LAB_1001ddb6:
    param_4 = iVar1;
    param_2 = iVar12;
    param_3 = iVar13;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001ddb6;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  local_30 = (int)*(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar8 = *(uint *)(param_2 + 100);
  uVar15 = *(uint *)(param_2 + 0x68);
  uVar10 = *(uint *)(param_3 + 100);
  iVar12 = (int)*(short *)(param_3 + 0x1a);
  uVar9 = *(uint *)(param_3 + 0x68);
  uVar14 = *(uint *)(param_4 + 100);
  uVar16 = *(uint *)(param_4 + 0x68);
  iVar13 = (int)*(short *)(param_4 + 0x1a);
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248 + 0x800;
  iVar1 = DAT_1008723c + 0x1000;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  if (local_30 < 1) {
    iVar2 = DAT_1008d280 - iVar12;
    if (iVar2 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    local_30 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_30 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar11 = iVar13 - iVar12;
    if (local_30 == 1) {
      DAT_1008d28c = iVar11 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d28c = iVar11 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar1 + (iVar11 * 0x20 + local_30) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1008d28c = (iVar11 * 0x10000) / local_30;
    }
    else {
      DAT_1008d28c = (iVar11 * 0x10000) / local_30;
    }
    iVar13 = iVar13 - DAT_1008d280;
    if (local_30 == 1) {
      DAT_1008d288 = iVar13 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d288 = iVar13 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar1 + (iVar13 * 0x20 + local_30) * 4);
    }
    else if (iVar13 < 0) {
      DAT_1008d288 = (iVar13 * 0x10000) / local_30;
    }
    else {
      DAT_1008d288 = (iVar13 * 0x10000) / local_30;
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
    if ((uVar14 == uVar10) || (local_30 == 1)) {
      uVar14 = uVar14 - uVar10;
    }
    else if (local_30 == 2) {
      uVar14 = (int)(uVar14 - uVar10) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar10) / local_30;
    }
    if ((uVar9 == uVar15) || (iVar2 == 1)) {
      uVar15 = uVar15 - uVar9;
    }
    else if (iVar2 == 2) {
      uVar15 = (int)(uVar15 - uVar9) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar9) / iVar2;
    }
    if ((uVar16 == uVar9) || (local_30 == 1)) {
      uVar16 = uVar16 - uVar9;
    }
    else if (local_30 == 2) {
      uVar16 = (int)(uVar16 - uVar9) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar9) / local_30;
    }
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d2c0 = (uVar9 & 0xfffe) << 0xf | (uVar10 & 0xfffe) >> 1;
    DAT_1008d2c8 = (uVar15 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
  }
  else {
    iVar2 = iVar12 - DAT_1008d280;
    if (local_30 == 1) {
      DAT_1008d28c = iVar2 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d28c = iVar2 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar1 + (iVar2 * 0x20 + local_30) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1008d28c = (iVar2 * 0x10000) / local_30;
    }
    else {
      DAT_1008d28c = (iVar2 * 0x10000) / local_30;
    }
    iVar2 = (int)*(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (iVar2 < 1) {
      iVar2 = iVar13 - DAT_1008d280;
      if (iVar2 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar12 = iVar12 - iVar13;
      if (local_30 == 1) {
        DAT_1008d288 = iVar12 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1008d288 = iVar12 * 0x8000;
      }
      else if (((local_30 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar1 + (iVar12 * 0x20 + local_30) * 4);
      }
      else if (iVar12 < 0) {
        DAT_1008d288 = (iVar12 * 0x10000) / local_30;
      }
      else {
        DAT_1008d288 = (iVar12 * 0x10000) / local_30;
      }
      if ((uVar14 == uVar8) || (iVar2 == 1)) {
        uVar14 = uVar14 - uVar8;
      }
      else if (iVar2 == 2) {
        uVar14 = (int)(uVar14 - uVar8) >> 1;
      }
      else {
        uVar14 = (int)(uVar14 - uVar8) / iVar2;
      }
      if ((uVar16 == uVar15) || (iVar2 == 1)) {
        uVar16 = uVar16 - uVar15;
      }
      else if (iVar2 == 2) {
        uVar16 = (int)(uVar16 - uVar15) >> 1;
      }
      else {
        uVar16 = (int)(uVar16 - uVar15) / iVar2;
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
      if ((uVar9 == uVar15) || (local_30 == 1)) {
        uVar9 = uVar9 - uVar15;
      }
      else if (local_30 == 2) {
        uVar9 = (int)(uVar9 - uVar15) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - uVar15) / local_30;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = iVar13 << 0x10;
      DAT_1008d2c0 = (uVar15 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar16 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar9 & 0xfffe) << 0xf | (uVar10 & 0xfffe) >> 1;
      goto LAB_1001e7cd;
    }
    iVar3 = iVar13 - DAT_1008d280;
    iVar11 = iVar2;
    if (iVar2 == 1) {
      DAT_1008d288 = iVar3 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1008d288 = iVar3 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar1 + (iVar3 * 0x20 + iVar2) * 4);
      iVar11 = iVar1;
    }
    else if (iVar3 < 0) {
      DAT_1008d288 = (iVar3 * 0x10000) / iVar2;
      iVar11 = (iVar3 * 0x10000) % iVar2;
    }
    else {
      DAT_1008d288 = (iVar3 * 0x10000) / iVar2;
      iVar11 = (iVar3 * 0x10000) % iVar2;
    }
    iVar3 = DAT_1008d288 - DAT_1008d28c;
    if (iVar3 < 1) {
      DAT_1008d298 = DAT_10089ddc;
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
    if ((uVar9 == uVar15) || (local_30 == 1)) {
      uVar5 = uVar9 - uVar15;
    }
    else if (local_30 == 2) {
      uVar5 = (int)(uVar9 - uVar15) >> 1;
    }
    else {
      uVar5 = (int)(uVar9 - uVar15) / local_30;
      iVar11 = (int)(uVar9 - uVar15) % local_30;
    }
    if ((uVar14 == uVar8) || (iVar2 == 1)) {
      iVar6 = uVar14 - uVar8;
    }
    else if (iVar2 == 2) {
      iVar6 = (int)(uVar14 - uVar8) >> 1;
    }
    else {
      iVar6 = (int)(uVar14 - uVar8) / iVar2;
      iVar11 = (int)(uVar14 - uVar8) % iVar2;
    }
    uVar7 = iVar6 - uVar4;
    uVar17 = CONCAT44(iVar11,uVar7);
    if (uVar7 != 0) {
      uVar17 = FUN_1006a324(iVar3,iVar11,uVar7,iVar3);
    }
    iVar11 = (int)((ulonglong)uVar17 >> 0x20);
    local_c = (uint)uVar17;
    if ((uVar16 == uVar15) || (iVar2 == 1)) {
      iVar6 = uVar16 - uVar15;
    }
    else if (iVar2 == 2) {
      iVar6 = (int)(uVar16 - uVar15) >> 1;
    }
    else {
      iVar6 = (int)(uVar16 - uVar15) / iVar2;
      iVar11 = (int)(uVar16 - uVar15) % iVar2;
    }
    uVar7 = 0;
    if (iVar6 - uVar5 != 0) {
      uVar17 = FUN_1006a324(iVar3,iVar11,iVar6 - uVar5,iVar3);
      uVar7 = (uint)uVar17;
    }
    DAT_1008d280 = DAT_1008d280 << 0x10;
    DAT_1008d284 = DAT_1008d280;
    if (iVar2 <= local_30) {
      DAT_1008d2c0 = (uVar15 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar7 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar5 & 0xfffe) << 0xf | (uVar4 & 0xfffe) >> 1;
      local_30 = local_30 - iVar2;
      DAT_1008d290 = iVar2;
      FUN_1001e7f0((uint *)&DAT_1008d280);
      if (local_30 == 0) {
        return;
      }
      DAT_1008d284 = iVar13 << 0x10;
      iVar12 = iVar12 - iVar13;
      if (local_30 == 1) {
        DAT_1008d288 = iVar12 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1008d288 = iVar12 * 0x8000;
      }
      else if (((local_30 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar1 + (iVar12 * 0x20 + local_30) * 4);
      }
      else if (iVar12 < 0) {
        DAT_1008d288 = (iVar12 * 0x10000) / local_30;
      }
      else {
        DAT_1008d288 = (iVar12 * 0x10000) / local_30;
      }
      goto LAB_1001e7cd;
    }
    DAT_1008d2c0 = (uVar15 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
    uVar8 = (uVar7 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar5 & 0xfffe) << 0xf | (uVar4 & 0xfffe) >> 1;
    iVar2 = iVar2 - local_30;
    DAT_1008d290 = local_30;
    DAT_1008d2c8 = uVar8;
    FUN_1001e7f0((uint *)&DAT_1008d280);
    iVar13 = iVar13 - iVar12;
    if (iVar2 == 1) {
      DAT_1008d28c = iVar13 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1008d28c = iVar13 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar1 + (iVar13 * 0x20 + iVar2) * 4);
    }
    else if (iVar13 < 0) {
      DAT_1008d28c = (iVar13 * 0x10000) / iVar2;
    }
    else {
      DAT_1008d28c = (iVar13 * 0x10000) / iVar2;
    }
    if ((uVar14 == uVar10) || (iVar2 == 1)) {
      uVar14 = uVar14 - uVar10;
    }
    else if (iVar2 == 2) {
      uVar14 = (int)(uVar14 - uVar10) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar10) / iVar2;
    }
    local_30 = iVar2;
    if ((uVar16 == uVar9) || (iVar2 == 1)) {
      uVar16 = uVar16 - uVar9;
      DAT_1008d2c8 = uVar8;
    }
    else if (iVar2 == 2) {
      uVar16 = (int)(uVar16 - uVar9) >> 1;
      DAT_1008d2c8 = uVar8;
    }
    else {
      uVar16 = (int)(uVar16 - uVar9) / iVar2;
      DAT_1008d2c8 = uVar8;
    }
  }
  DAT_1008d280 = iVar12 << 0x10;
  DAT_1008d2c4 = (uVar16 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
LAB_1001e7cd:
  DAT_1008d290 = local_30;
  FUN_1001e7f0((uint *)&DAT_1008d280);
  return;
}


