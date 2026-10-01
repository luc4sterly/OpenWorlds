// 10010330 FUN_10010330 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10010330(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  undefined8 uVar19;
  uint local_30;
  uint local_c;
  
  iVar3 = param_3;
  iVar7 = param_4;
  iVar16 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar3 = param_2;
      iVar7 = param_3;
      iVar16 = param_4;
    }
LAB_10010376:
    param_4 = iVar3;
    param_2 = iVar7;
    param_3 = iVar16;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10010376;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  local_30 = (int)*(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (uint)*(short *)(param_2 + 0x1a);
  uVar10 = *(uint *)(param_2 + 100);
  uVar17 = *(uint *)(param_2 + 0x68);
  uVar11 = *(uint *)(param_3 + 100);
  uVar13 = (uint)*(short *)(param_3 + 0x1a);
  uVar8 = *(uint *)(param_3 + 0x68);
  uVar15 = *(uint *)(param_4 + 100);
  uVar18 = *(uint *)(param_4 + 0x68);
  uVar14 = (uint)*(short *)(param_4 + 0x1a);
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  uVar2 = DAT_1008723c + 0x1000;
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  if ((int)local_30 < 1) {
    iVar3 = DAT_1008d280 - uVar13;
    if (iVar3 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return uVar13;
    }
    local_30 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_30 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return 0;
    }
    iVar7 = uVar14 - uVar13;
    if (local_30 == 1) {
      DAT_1008d28c = iVar7 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d28c = iVar7 * 0x8000;
    }
    else if ((((int)local_30 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1008d28c = *(uint *)(uVar2 + (iVar7 * 0x20 + local_30) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1008d28c = (iVar7 * 0x10000) / (int)local_30;
    }
    else {
      DAT_1008d28c = (iVar7 * 0x10000) / (int)local_30;
    }
    iVar7 = uVar14 - DAT_1008d280;
    uVar12 = DAT_1008d280;
    if (local_30 == 1) {
      DAT_1008d288 = iVar7 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d288 = iVar7 * 0x8000;
    }
    else if ((((int)local_30 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1008d288 = *(uint *)(uVar2 + (iVar7 * 0x20 + local_30) * 4);
      uVar12 = DAT_1008d288;
    }
    else if (iVar7 < 0) {
      DAT_1008d288 = (iVar7 * 0x10000) / (int)local_30;
      uVar12 = (iVar7 * 0x10000) % (int)local_30;
    }
    else {
      DAT_1008d288 = (iVar7 * 0x10000) / (int)local_30;
      uVar12 = (iVar7 * 0x10000) % (int)local_30;
    }
    if ((uVar10 == uVar11) || (iVar3 == 1)) {
      uVar2 = uVar10 - uVar11;
    }
    else if (iVar3 == 2) {
      uVar2 = (int)(uVar10 - uVar11) >> 1;
    }
    else {
      uVar2 = (int)(uVar10 - uVar11) / iVar3;
      uVar12 = (int)(uVar10 - uVar11) % iVar3;
    }
    if ((uVar15 == uVar11) || (local_30 == 1)) {
      uVar10 = uVar15 - uVar11;
    }
    else if (local_30 == 2) {
      uVar10 = (int)(uVar15 - uVar11) >> 1;
    }
    else {
      uVar10 = (int)(uVar15 - uVar11) / (int)local_30;
      uVar12 = (int)(uVar15 - uVar11) % (int)local_30;
    }
    if ((uVar17 == uVar8) || (iVar3 == 1)) {
      uVar15 = uVar17 - uVar8;
    }
    else if (iVar3 == 2) {
      uVar15 = (int)(uVar17 - uVar8) >> 1;
    }
    else {
      uVar15 = (int)(uVar17 - uVar8) / iVar3;
      uVar12 = (int)(uVar17 - uVar8) % iVar3;
    }
    if ((uVar18 == uVar8) || (local_30 == 1)) {
      uVar17 = uVar18 - uVar8;
    }
    else if (local_30 == 2) {
      uVar17 = (int)(uVar18 - uVar8) >> 1;
    }
    else {
      uVar17 = (int)(uVar18 - uVar8) / (int)local_30;
      uVar12 = (int)(uVar18 - uVar8) % (int)local_30;
    }
    DAT_1008d284 = DAT_1008d280 << 0x10;
    uVar14 = (uVar11 & 0xfffe) >> 1;
    DAT_1008d2c0 = (uVar8 & 0xfffe) << 0xf | uVar14;
    uVar4 = (uVar15 & 0xfffe) << 0xf | (uVar2 & 0xfffe) >> 1;
  }
  else {
    iVar3 = uVar13 - DAT_1008d280;
    if (local_30 == 1) {
      DAT_1008d28c = iVar3 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d28c = iVar3 * 0x8000;
    }
    else if ((((int)local_30 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1008d28c = *(uint *)(uVar2 + (iVar3 * 0x20 + local_30) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1008d28c = (iVar3 * 0x10000) / (int)local_30;
    }
    else {
      DAT_1008d28c = (iVar3 * 0x10000) / (int)local_30;
    }
    uVar9 = (int)*(short *)(param_4 + 0x1e) - DAT_1008d284;
    if ((int)uVar9 < 1) {
      iVar3 = uVar14 - DAT_1008d280;
      if (iVar3 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return DAT_1008d280;
      }
      iVar7 = uVar13 - uVar14;
      if (local_30 == 1) {
        DAT_1008d288 = iVar7 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1008d288 = iVar7 * 0x8000;
      }
      else if ((((int)local_30 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1008d288 = *(uint *)(uVar2 + (iVar7 * 0x20 + local_30) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1008d288 = (iVar7 * 0x10000) / (int)local_30;
      }
      else {
        DAT_1008d288 = (iVar7 * 0x10000) / (int)local_30;
      }
      if ((uVar15 == uVar10) || (iVar3 == 1)) {
        uVar15 = uVar15 - uVar10;
      }
      else if (iVar3 == 2) {
        uVar15 = (int)(uVar15 - uVar10) >> 1;
      }
      else {
        uVar15 = (int)(uVar15 - uVar10) / iVar3;
      }
      if ((uVar18 == uVar17) || (iVar3 == 1)) {
        uVar18 = uVar18 - uVar17;
      }
      else if (iVar3 == 2) {
        uVar18 = (int)(uVar18 - uVar17) >> 1;
      }
      else {
        uVar18 = (int)(uVar18 - uVar17) / iVar3;
      }
      if ((uVar11 == uVar10) || (local_30 == 1)) {
        uVar11 = uVar11 - uVar10;
      }
      else if (local_30 == 2) {
        uVar11 = (int)(uVar11 - uVar10) >> 1;
      }
      else {
        uVar11 = (int)(uVar11 - uVar10) / (int)local_30;
      }
      if ((uVar8 == uVar17) || (local_30 == 1)) {
        uVar8 = uVar8 - uVar17;
      }
      else if (local_30 == 2) {
        uVar8 = (int)(uVar8 - uVar17) >> 1;
      }
      else {
        uVar8 = (int)(uVar8 - uVar17) / (int)local_30;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      uVar12 = uVar14 << 0x10;
      DAT_1008d2c0 = (uVar17 & 0xfffe) << 0xf | (uVar10 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar18 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
      uVar14 = (uVar11 & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar8 & 0xfffe) << 0xf | uVar14;
      DAT_1008d284 = uVar12;
      goto LAB_10010d5d;
    }
    iVar3 = uVar14 - DAT_1008d280;
    uVar12 = uVar9;
    if (uVar9 == 1) {
      DAT_1008d288 = iVar3 * 0x10000;
    }
    else if (uVar9 == 2) {
      DAT_1008d288 = iVar3 * 0x8000;
    }
    else if ((((int)uVar9 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1008d288 = *(uint *)(uVar2 + (iVar3 * 0x20 + uVar9) * 4);
      uVar12 = uVar2;
    }
    else if (iVar3 < 0) {
      DAT_1008d288 = (iVar3 * 0x10000) / (int)uVar9;
      uVar12 = (iVar3 * 0x10000) % (int)uVar9;
    }
    else {
      DAT_1008d288 = (iVar3 * 0x10000) / (int)uVar9;
      uVar12 = (iVar3 * 0x10000) % (int)uVar9;
    }
    uVar4 = DAT_1008d288 - DAT_1008d28c;
    if ((int)uVar4 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return uVar4;
    }
    if ((uVar11 == uVar10) || (local_30 == 1)) {
      uVar5 = uVar11 - uVar10;
    }
    else if (local_30 == 2) {
      uVar5 = (int)(uVar11 - uVar10) >> 1;
    }
    else {
      uVar5 = (int)(uVar11 - uVar10) / (int)local_30;
      uVar12 = (int)(uVar11 - uVar10) % (int)local_30;
    }
    if ((uVar8 == uVar17) || (local_30 == 1)) {
      uVar6 = uVar8 - uVar17;
    }
    else if (local_30 == 2) {
      uVar6 = (int)(uVar8 - uVar17) >> 1;
    }
    else {
      uVar6 = (int)(uVar8 - uVar17) / (int)local_30;
      uVar12 = (int)(uVar8 - uVar17) % (int)local_30;
    }
    if ((uVar15 == uVar10) || (uVar9 == 1)) {
      iVar3 = uVar15 - uVar10;
    }
    else if (uVar9 == 2) {
      iVar3 = (int)(uVar15 - uVar10) >> 1;
    }
    else {
      iVar3 = (int)(uVar15 - uVar10) / (int)uVar9;
      uVar12 = (int)(uVar15 - uVar10) % (int)uVar9;
    }
    uVar1 = iVar3 - uVar5;
    uVar19 = CONCAT44(uVar12,uVar1);
    if (uVar1 != 0) {
      uVar19 = FUN_1006a324(uVar4,uVar12,uVar1,uVar4);
    }
    iVar3 = (int)((ulonglong)uVar19 >> 0x20);
    local_c = (uint)uVar19;
    if ((uVar18 == uVar17) || (uVar9 == 1)) {
      iVar7 = uVar18 - uVar17;
    }
    else if (uVar9 == 2) {
      iVar7 = (int)(uVar18 - uVar17) >> 1;
    }
    else {
      iVar7 = (int)(uVar18 - uVar17) / (int)uVar9;
      iVar3 = (int)(uVar18 - uVar17) % (int)uVar9;
    }
    uVar12 = 0;
    if (iVar7 - uVar6 != 0) {
      uVar19 = FUN_1006a324(uVar4,iVar3,iVar7 - uVar6,uVar4);
      uVar12 = (uint)uVar19;
    }
    DAT_1008d280 = DAT_1008d280 << 0x10;
    DAT_1008d284 = DAT_1008d280;
    if ((int)uVar9 <= (int)local_30) {
      DAT_1008d2c0 = (uVar17 & 0xfffe) << 0xf | (uVar10 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar12 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
      uVar10 = (uVar5 & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar6 & 0xfffe) << 0xf | uVar10;
      local_30 = local_30 - uVar9;
      DAT_1008d290 = uVar9;
      uVar19 = FUN_100785b4(uVar10,uVar9);
      if (local_30 == 0) {
        return (uint)uVar19;
      }
      DAT_1008d284 = uVar14 << 0x10;
      iVar3 = uVar13 - uVar14;
      uVar12 = local_30;
      if (local_30 == 1) {
        DAT_1008d288 = iVar3 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1008d288 = iVar3 * 0x8000;
      }
      else if ((((int)local_30 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
        uVar14 = *(uint *)(uVar2 + (iVar3 * 0x20 + local_30) * 4);
        uVar12 = uVar2;
        DAT_1008d288 = uVar14;
      }
      else if (iVar3 < 0) {
        DAT_1008d288 = (iVar3 * 0x10000) / (int)local_30;
        uVar12 = (iVar3 * 0x10000) % (int)local_30;
      }
      else {
        DAT_1008d288 = (iVar3 * 0x10000) / (int)local_30;
        uVar12 = (iVar3 * 0x10000) % (int)local_30;
      }
      goto LAB_10010d5d;
    }
    DAT_1008d2c0 = (uVar17 & 0xfffe) << 0xf | (uVar10 & 0xfffe) >> 1;
    uVar4 = (uVar12 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
    uVar10 = (uVar5 & 0xfffe) >> 1;
    uVar9 = uVar9 - local_30;
    DAT_1008d2c4 = (uVar6 & 0xfffe) << 0xf | uVar10;
    DAT_1008d290 = local_30;
    DAT_1008d2c8 = uVar4;
    uVar19 = FUN_100785b4(uVar10,local_30);
    uVar12 = (uint)((ulonglong)uVar19 >> 0x20);
    iVar3 = uVar14 - uVar13;
    uVar14 = uVar13;
    if (uVar9 == 1) {
      DAT_1008d28c = iVar3 * 0x10000;
    }
    else if (uVar9 == 2) {
      DAT_1008d28c = iVar3 * 0x8000;
    }
    else if ((((int)uVar9 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1008d28c = *(uint *)(uVar2 + (iVar3 * 0x20 + uVar9) * 4);
      uVar14 = DAT_1008d28c;
      uVar12 = uVar2;
    }
    else if (iVar3 < 0) {
      DAT_1008d28c = (iVar3 * 0x10000) / (int)uVar9;
      uVar12 = (iVar3 * 0x10000) % (int)uVar9;
    }
    else {
      DAT_1008d28c = (iVar3 * 0x10000) / (int)uVar9;
      uVar12 = (iVar3 * 0x10000) % (int)uVar9;
    }
    if ((uVar15 == uVar11) || (uVar9 == 1)) {
      uVar10 = uVar15 - uVar11;
    }
    else if (uVar9 == 2) {
      uVar10 = (int)(uVar15 - uVar11) >> 1;
    }
    else {
      uVar10 = (int)(uVar15 - uVar11) / (int)uVar9;
      uVar12 = (int)(uVar15 - uVar11) % (int)uVar9;
    }
    local_30 = uVar9;
    if ((uVar18 == uVar8) || (uVar9 == 1)) {
      uVar17 = uVar18 - uVar8;
    }
    else if (uVar9 == 2) {
      uVar17 = (int)(uVar18 - uVar8) >> 1;
    }
    else {
      uVar17 = (int)(uVar18 - uVar8) / (int)uVar9;
      uVar12 = (int)(uVar18 - uVar8) % (int)uVar9;
    }
  }
  DAT_1008d280 = uVar13 << 0x10;
  DAT_1008d2c4 = (uVar17 & 0xfffe) << 0xf | (uVar10 & 0xfffe) >> 1;
  DAT_1008d2c8 = uVar4;
LAB_10010d5d:
  DAT_1008d290 = local_30;
  uVar19 = FUN_100785b4(uVar14,uVar12);
  return (uint)uVar19;
}


