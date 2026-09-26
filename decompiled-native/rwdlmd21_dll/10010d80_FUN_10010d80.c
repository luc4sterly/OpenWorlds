// 10010d80 FUN_10010d80 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10010d80(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  longlong lVar20;
  undefined8 uVar21;
  uint local_30;
  uint local_20;
  uint local_14;
  
  iVar4 = param_3;
  iVar8 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar4 = param_2;
      param_2 = param_4;
      iVar8 = param_3;
    }
LAB_10010dc6:
    param_4 = iVar4;
    param_3 = param_2;
    param_2 = iVar8;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10010dc6;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar2 = *(short *)(param_3 + 0x1e);
  sVar3 = *(short *)(param_4 + 0x1e);
  local_30 = (int)sVar2 - DAT_1008d284;
  DAT_1008d280 = (uint)*(short *)(param_2 + 0x1a);
  uVar16 = *(uint *)(param_2 + 100);
  uVar18 = *(uint *)(param_2 + 0x68);
  uVar10 = *(uint *)(param_3 + 0x68);
  uVar15 = (uint)*(short *)(param_3 + 0x1a);
  uVar12 = *(uint *)(param_3 + 100);
  uVar17 = *(uint *)(param_4 + 100);
  uVar13 = (uint)*(short *)(param_4 + 0x1a);
  uVar19 = *(uint *)(param_4 + 0x68);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248 + 0x800;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  if ((DAT_1008a100 == 0) || (*(float *)(param_1[0xf] + 0x14) <= _DAT_10089dd0)) {
    DAT_1008dbe0._4_4_ = 0;
  }
  else {
    lVar20 = __ftol();
    iVar4 = (int)lVar20;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    iVar4 = 0x10000 - iVar4;
    uVar14 = DAT_10089ef8 * iVar4;
    local_20 = DAT_10089ef0 * iVar4;
    uVar11 = iVar4 * DAT_10089de4;
    if (0x1e0000 < (int)(param_1[1] + uVar14)) {
      uVar14 = 0x1e0000 - param_1[1];
    }
    if (0x1e0000 < (int)(local_20 + param_1[2])) {
      local_20 = 0x1e0000 - param_1[2];
    }
    if (0x1e0000 < (int)(param_1[3] + uVar11)) {
      uVar11 = 0x1e0000 - param_1[3];
    }
    if ((int)uVar14 < 0) {
      uVar14 = 0;
    }
    if ((int)local_20 < 0) {
      local_20 = 0;
    }
    if ((int)uVar11 < 0) {
      uVar11 = 0;
    }
    uVar11 = (int)((local_20 & 0x1f8000) >> 5 | uVar14 & 0x1f0000) >> 5 |
             (uVar11 & 0x1f0000) >> 0x10;
    DAT_1008dbe0._4_4_ = uVar11 | uVar11 << 0x10;
  }
  uVar11 = DAT_1008723c + 0x1000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  DAT_1008dbe0._0_4_ = DAT_1008dbe0._4_4_;
  if ((int)local_30 < 1) {
    iVar4 = DAT_1008d280 - uVar15;
    if (iVar4 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return uVar15;
    }
    local_30 = -((int)sVar2 - (int)sVar3);
    if (local_30 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return 0;
    }
    iVar8 = uVar13 - uVar15;
    if (local_30 == 1) {
      DAT_1008d28c = iVar8 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d28c = iVar8 * 0x8000;
    }
    else if ((((int)local_30 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1008d28c = *(uint *)(uVar11 + (iVar8 * 0x20 + local_30) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1008d28c = (iVar8 * 0x10000) / (int)local_30;
    }
    else {
      DAT_1008d28c = (iVar8 * 0x10000) / (int)local_30;
    }
    iVar8 = uVar13 - DAT_1008d280;
    if (local_30 == 1) {
      DAT_1008d288 = iVar8 * 0x10000;
      uVar11 = DAT_1008d280;
    }
    else if (local_30 == 2) {
      DAT_1008d288 = iVar8 * 0x8000;
      uVar11 = DAT_1008d280;
    }
    else if ((((int)local_30 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1008d288 = *(uint *)(uVar11 + (iVar8 * 0x20 + local_30) * 4);
      uVar11 = DAT_1008d288;
    }
    else if (iVar8 < 0) {
      DAT_1008d288 = (iVar8 * 0x10000) / (int)local_30;
      uVar11 = (iVar8 * 0x10000) % (int)local_30;
    }
    else {
      DAT_1008d288 = (iVar8 * 0x10000) / (int)local_30;
      uVar11 = (iVar8 * 0x10000) % (int)local_30;
    }
    if ((uVar12 == uVar16) || (iVar4 == 1)) {
      uVar14 = uVar16 - uVar12;
    }
    else if (iVar4 == 2) {
      uVar14 = (int)(uVar16 - uVar12) >> 1;
    }
    else {
      uVar14 = (int)(uVar16 - uVar12) / iVar4;
      uVar11 = (int)(uVar16 - uVar12) % iVar4;
    }
    if ((uVar17 == uVar12) || (local_30 == 1)) {
      uVar16 = uVar17 - uVar12;
    }
    else if (local_30 == 2) {
      uVar16 = (int)(uVar17 - uVar12) >> 1;
    }
    else {
      uVar16 = (int)(uVar17 - uVar12) / (int)local_30;
      uVar11 = (int)(uVar17 - uVar12) % (int)local_30;
    }
    if ((uVar10 == uVar18) || (iVar4 == 1)) {
      uVar17 = uVar18 - uVar10;
    }
    else if (iVar4 == 2) {
      uVar17 = (int)(uVar18 - uVar10) >> 1;
    }
    else {
      uVar17 = (int)(uVar18 - uVar10) / iVar4;
      uVar11 = (int)(uVar18 - uVar10) % iVar4;
    }
    if ((uVar19 == uVar10) || (local_30 == 1)) {
      uVar18 = uVar19 - uVar10;
    }
    else if (local_30 == 2) {
      uVar18 = (int)(uVar19 - uVar10) >> 1;
    }
    else {
      uVar18 = (int)(uVar19 - uVar10) / (int)local_30;
      uVar11 = (int)(uVar19 - uVar10) % (int)local_30;
    }
    DAT_1008d284 = DAT_1008d280 << 0x10;
    uVar13 = (uVar12 & 0xfffe) >> 1;
    DAT_1008d2c0 = (uVar10 & 0xfffe) << 0xf | uVar13;
    DAT_1008d2c8 = (uVar17 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
  }
  else {
    iVar4 = uVar15 - DAT_1008d280;
    if (local_30 == 1) {
      DAT_1008d28c = iVar4 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d28c = iVar4 * 0x8000;
    }
    else if ((((int)local_30 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1008d28c = *(uint *)(uVar11 + (iVar4 * 0x20 + local_30) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1008d28c = (iVar4 * 0x10000) / (int)local_30;
    }
    else {
      DAT_1008d28c = (iVar4 * 0x10000) / (int)local_30;
    }
    uVar14 = (int)sVar3 - DAT_1008d284;
    if ((int)uVar14 < 1) {
      iVar4 = uVar13 - DAT_1008d280;
      if (iVar4 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return DAT_1008d280;
      }
      iVar8 = uVar15 - uVar13;
      if (local_30 == 1) {
        DAT_1008d288 = iVar8 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1008d288 = iVar8 * 0x8000;
      }
      else if ((((int)local_30 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
        DAT_1008d288 = *(uint *)(uVar11 + (iVar8 * 0x20 + local_30) * 4);
      }
      else if (iVar8 < 0) {
        DAT_1008d288 = (iVar8 * 0x10000) / (int)local_30;
      }
      else {
        DAT_1008d288 = (iVar8 * 0x10000) / (int)local_30;
      }
      if ((uVar17 == uVar16) || (iVar4 == 1)) {
        uVar17 = uVar17 - uVar16;
      }
      else if (iVar4 == 2) {
        uVar17 = (int)(uVar17 - uVar16) >> 1;
      }
      else {
        uVar17 = (int)(uVar17 - uVar16) / iVar4;
      }
      if ((uVar19 == uVar18) || (iVar4 == 1)) {
        uVar19 = uVar19 - uVar18;
      }
      else if (iVar4 == 2) {
        uVar19 = (int)(uVar19 - uVar18) >> 1;
      }
      else {
        uVar19 = (int)(uVar19 - uVar18) / iVar4;
      }
      if ((uVar12 == uVar16) || (local_30 == 1)) {
        uVar12 = uVar12 - uVar16;
      }
      else if (local_30 == 2) {
        uVar12 = (int)(uVar12 - uVar16) >> 1;
      }
      else {
        uVar12 = (int)(uVar12 - uVar16) / (int)local_30;
      }
      if ((uVar10 == uVar18) || (local_30 == 1)) {
        uVar10 = uVar10 - uVar18;
      }
      else if (local_30 == 2) {
        uVar10 = (int)(uVar10 - uVar18) >> 1;
      }
      else {
        uVar10 = (int)(uVar10 - uVar18) / (int)local_30;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      uVar11 = uVar13 << 0x10;
      DAT_1008d2c0 = (uVar18 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar19 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
      uVar13 = (uVar12 & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar10 & 0xfffe) << 0xf | uVar13;
      DAT_1008d284 = uVar11;
      goto LAB_10011928;
    }
    iVar4 = uVar13 - DAT_1008d280;
    uVar9 = uVar14;
    if (uVar14 == 1) {
      DAT_1008d288 = iVar4 * 0x10000;
    }
    else if (uVar14 == 2) {
      DAT_1008d288 = iVar4 * 0x8000;
    }
    else if ((((int)uVar14 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1008d288 = *(uint *)(uVar11 + (iVar4 * 0x20 + uVar14) * 4);
      uVar9 = uVar11;
    }
    else if (iVar4 < 0) {
      DAT_1008d288 = (iVar4 * 0x10000) / (int)uVar14;
      uVar9 = (iVar4 * 0x10000) % (int)uVar14;
    }
    else {
      DAT_1008d288 = (iVar4 * 0x10000) / (int)uVar14;
      uVar9 = (iVar4 * 0x10000) % (int)uVar14;
    }
    uVar5 = DAT_1008d288 - DAT_1008d28c;
    if ((int)uVar5 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return uVar5;
    }
    if ((uVar12 == uVar16) || (local_30 == 1)) {
      uVar6 = uVar12 - uVar16;
    }
    else if (local_30 == 2) {
      uVar6 = (int)(uVar12 - uVar16) >> 1;
    }
    else {
      uVar6 = (int)(uVar12 - uVar16) / (int)local_30;
      uVar9 = (int)(uVar12 - uVar16) % (int)local_30;
    }
    if ((uVar10 == uVar18) || (local_30 == 1)) {
      uVar7 = uVar10 - uVar18;
    }
    else if (local_30 == 2) {
      uVar7 = (int)(uVar10 - uVar18) >> 1;
    }
    else {
      uVar7 = (int)(uVar10 - uVar18) / (int)local_30;
      uVar9 = (int)(uVar10 - uVar18) % (int)local_30;
    }
    if ((uVar17 == uVar16) || (uVar14 == 1)) {
      iVar4 = uVar17 - uVar16;
    }
    else if (uVar14 == 2) {
      iVar4 = (int)(uVar17 - uVar16) >> 1;
    }
    else {
      iVar4 = (int)(uVar17 - uVar16) / (int)uVar14;
      uVar9 = (int)(uVar17 - uVar16) % (int)uVar14;
    }
    uVar1 = iVar4 - uVar6;
    uVar21 = CONCAT44(uVar9,uVar1);
    if (uVar1 != 0) {
      uVar21 = FUN_1006a324(uVar5,uVar9,uVar1,uVar5);
    }
    iVar4 = (int)((ulonglong)uVar21 >> 0x20);
    local_14 = (uint)uVar21;
    if ((uVar19 == uVar18) || (uVar14 == 1)) {
      iVar8 = uVar19 - uVar18;
    }
    else if (uVar14 == 2) {
      iVar8 = (int)(uVar19 - uVar18) >> 1;
    }
    else {
      iVar8 = (int)(uVar19 - uVar18) / (int)uVar14;
      iVar4 = (int)(uVar19 - uVar18) % (int)uVar14;
    }
    uVar9 = 0;
    if (iVar8 - uVar7 != 0) {
      uVar21 = FUN_1006a324(uVar5,iVar4,iVar8 - uVar7,uVar5);
      uVar9 = (uint)uVar21;
    }
    DAT_1008d280 = DAT_1008d280 << 0x10;
    DAT_1008d284 = DAT_1008d280;
    if ((int)uVar14 <= (int)local_30) {
      DAT_1008d2c0 = (uVar18 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
      DAT_1008d2c8 = (uVar9 & 0xfffe) << 0xf | (local_14 & 0xfffe) >> 1;
      DAT_1008d2c4 = (uVar7 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
      local_30 = local_30 - uVar14;
      DAT_1008d290 = uVar14;
      uVar21 = FUN_1007889c(DAT_1008d2c4,uVar14);
      if (local_30 == 0) {
        return (uint)uVar21;
      }
      DAT_1008d284 = uVar13 << 0x10;
      iVar4 = uVar15 - uVar13;
      if (local_30 == 1) {
        DAT_1008d288 = iVar4 * 0x10000;
        uVar11 = local_30;
      }
      else if (local_30 == 2) {
        uVar11 = local_30;
        DAT_1008d288 = iVar4 * 0x8000;
      }
      else if ((((int)local_30 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
        uVar13 = *(uint *)(uVar11 + (iVar4 * 0x20 + local_30) * 4);
        DAT_1008d288 = uVar13;
      }
      else if (iVar4 < 0) {
        DAT_1008d288 = (iVar4 * 0x10000) / (int)local_30;
        uVar11 = (iVar4 * 0x10000) % (int)local_30;
      }
      else {
        DAT_1008d288 = (iVar4 * 0x10000) / (int)local_30;
        uVar11 = (iVar4 * 0x10000) % (int)local_30;
      }
      goto LAB_10011928;
    }
    DAT_1008d2c0 = (uVar18 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
    uVar9 = (uVar9 & 0xfffe) << 0xf | (local_14 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar7 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
    uVar14 = uVar14 - local_30;
    DAT_1008d290 = local_30;
    DAT_1008d2c8 = uVar9;
    FUN_1007889c(DAT_1008d2c4,local_30);
    iVar4 = uVar13 - uVar15;
    uVar13 = uVar14;
    if (uVar14 == 1) {
      DAT_1008d28c = iVar4 * 0x10000;
      uVar11 = uVar15;
    }
    else if (uVar14 == 2) {
      DAT_1008d28c = iVar4 * 0x8000;
      uVar11 = uVar15;
    }
    else if ((((int)uVar14 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1008d28c = *(uint *)(uVar11 + (iVar4 * 0x20 + uVar14) * 4);
      uVar13 = DAT_1008d28c;
    }
    else if (iVar4 < 0) {
      DAT_1008d28c = (iVar4 * 0x10000) / (int)uVar14;
      uVar11 = (iVar4 * 0x10000) % (int)uVar14;
    }
    else {
      DAT_1008d28c = (iVar4 * 0x10000) / (int)uVar14;
      uVar11 = (iVar4 * 0x10000) % (int)uVar14;
    }
    if ((uVar17 == uVar12) || (uVar14 == 1)) {
      uVar16 = uVar17 - uVar12;
    }
    else if (uVar14 == 2) {
      uVar16 = (int)(uVar17 - uVar12) >> 1;
    }
    else {
      uVar16 = (int)(uVar17 - uVar12) / (int)uVar14;
      uVar11 = (int)(uVar17 - uVar12) % (int)uVar14;
    }
    local_30 = uVar14;
    if ((uVar19 == uVar10) || (uVar14 == 1)) {
      uVar18 = uVar19 - uVar10;
      DAT_1008d2c8 = uVar9;
    }
    else if (uVar14 == 2) {
      uVar18 = (int)(uVar19 - uVar10) >> 1;
      DAT_1008d2c8 = uVar9;
    }
    else {
      uVar18 = (int)(uVar19 - uVar10) / (int)uVar14;
      uVar11 = (int)(uVar19 - uVar10) % (int)uVar14;
      DAT_1008d2c8 = uVar9;
    }
  }
  DAT_1008d280 = uVar15 << 0x10;
  DAT_1008d2c4 = (uVar18 & 0xfffe) << 0xf | (uVar16 & 0xfffe) >> 1;
LAB_10011928:
  DAT_1008d290 = local_30;
  uVar21 = FUN_1007889c(uVar13,uVar11);
  return (uint)uVar21;
}


