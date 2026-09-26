// 1000d9b0 FUN_1000d9b0 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_1000d9b0(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
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
  iVar9 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar4 = param_2;
      param_2 = param_4;
      iVar9 = param_3;
    }
LAB_1000d9f6:
    param_4 = iVar4;
    param_3 = param_2;
    param_2 = iVar9;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1000d9f6;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar2 = *(short *)(param_3 + 0x1e);
  sVar3 = *(short *)(param_4 + 0x1e);
  local_30 = (int)sVar2 - DAT_1008d284;
  DAT_1008d280 = (uint)*(short *)(param_2 + 0x1a);
  uVar12 = *(uint *)(param_2 + 0x68);
  uVar18 = *(uint *)(param_2 + 100);
  uVar16 = (uint)*(short *)(param_3 + 0x1a);
  uVar13 = *(uint *)(param_3 + 100);
  uVar19 = *(uint *)(param_4 + 100);
  uVar10 = *(uint *)(param_3 + 0x68);
  uVar14 = (uint)*(short *)(param_4 + 0x1a);
  uVar17 = *(uint *)(param_4 + 0x68);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248 + 0x800;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
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
    uVar15 = DAT_10089ef8 * iVar4;
    local_20 = DAT_10089ef0 * iVar4;
    uVar11 = iVar4 * DAT_10089de4;
    if (0x1e0000 < (int)(param_1[1] + uVar15)) {
      uVar15 = 0x1e0000 - param_1[1];
    }
    if (0x1e0000 < (int)(local_20 + param_1[2])) {
      local_20 = 0x1e0000 - param_1[2];
    }
    if (0x1e0000 < (int)(param_1[3] + uVar11)) {
      uVar11 = 0x1e0000 - param_1[3];
    }
    if ((int)uVar15 < 0) {
      uVar15 = 0;
    }
    if ((int)local_20 < 0) {
      local_20 = 0;
    }
    if ((int)uVar11 < 0) {
      uVar11 = 0;
    }
    uVar11 = (int)((local_20 & 0x1f8000) >> 5 | uVar15 & 0x1f0000) >> 5 |
             (uVar11 & 0x1f0000) >> 0x10;
    DAT_1008dbe0._4_4_ = uVar11 | uVar11 << 0x10;
  }
  uVar11 = DAT_1008723c + 0x1000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  DAT_1008dbe0._0_4_ = DAT_1008dbe0._4_4_;
  if ((int)local_30 < 1) {
    iVar4 = DAT_1008d280 - uVar16;
    if (iVar4 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return uVar16;
    }
    local_30 = -((int)sVar2 - (int)sVar3);
    if (local_30 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return 0;
    }
    iVar9 = uVar14 - uVar16;
    if (local_30 == 1) {
      DAT_1008d28c = iVar9 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d28c = iVar9 * 0x8000;
    }
    else if ((((int)local_30 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1008d28c = *(uint *)(uVar11 + (iVar9 * 0x20 + local_30) * 4);
    }
    else if (iVar9 < 0) {
      DAT_1008d28c = (iVar9 * 0x10000) / (int)local_30;
    }
    else {
      DAT_1008d28c = (iVar9 * 0x10000) / (int)local_30;
    }
    iVar9 = uVar14 - DAT_1008d280;
    uVar15 = DAT_1008d280;
    if (local_30 == 1) {
      DAT_1008d288 = iVar9 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1008d288 = iVar9 * 0x8000;
    }
    else if ((((int)local_30 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1008d288 = *(uint *)(uVar11 + (iVar9 * 0x20 + local_30) * 4);
      uVar15 = DAT_1008d288;
    }
    else if (iVar9 < 0) {
      DAT_1008d288 = (iVar9 * 0x10000) / (int)local_30;
      uVar15 = (iVar9 * 0x10000) % (int)local_30;
    }
    else {
      DAT_1008d288 = (iVar9 * 0x10000) / (int)local_30;
      uVar15 = (iVar9 * 0x10000) % (int)local_30;
    }
    if ((uVar13 == uVar18) || (iVar4 == 1)) {
      uVar11 = uVar18 - uVar13;
    }
    else if (iVar4 == 2) {
      uVar11 = (int)(uVar18 - uVar13) >> 1;
    }
    else {
      uVar11 = (int)(uVar18 - uVar13) / iVar4;
      uVar15 = (int)(uVar18 - uVar13) % iVar4;
    }
    if ((uVar19 == uVar13) || (local_30 == 1)) {
      uVar18 = uVar19 - uVar13;
    }
    else if (local_30 == 2) {
      uVar18 = (int)(uVar19 - uVar13) >> 1;
    }
    else {
      uVar18 = (int)(uVar19 - uVar13) / (int)local_30;
      uVar15 = (int)(uVar19 - uVar13) % (int)local_30;
    }
    if ((uVar10 == uVar12) || (iVar4 == 1)) {
      uVar19 = uVar12 - uVar10;
    }
    else if (iVar4 == 2) {
      uVar19 = (int)(uVar12 - uVar10) >> 1;
    }
    else {
      uVar19 = (int)(uVar12 - uVar10) / iVar4;
      uVar15 = (int)(uVar12 - uVar10) % iVar4;
    }
    if ((uVar17 == uVar10) || (local_30 == 1)) {
      uVar12 = uVar17 - uVar10;
    }
    else if (local_30 == 2) {
      uVar12 = (int)(uVar17 - uVar10) >> 1;
    }
    else {
      uVar12 = (int)(uVar17 - uVar10) / (int)local_30;
      uVar15 = (int)(uVar17 - uVar10) % (int)local_30;
    }
    DAT_1008d284 = DAT_1008d280 << 0x10;
    uVar14 = (uVar10 & 0xfffe) << 0xf;
    DAT_1008d2c0 = (uVar13 & 0xfffe) >> 1 | uVar14;
    DAT_1008d2c8 = (uVar11 & 0xfffe) >> 1 | (uVar19 & 0xfffe) << 0xf;
  }
  else {
    iVar4 = uVar16 - DAT_1008d280;
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
    uVar5 = (int)sVar3 - DAT_1008d284;
    if ((int)uVar5 < 1) {
      iVar4 = uVar14 - DAT_1008d280;
      if (iVar4 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return DAT_1008d280;
      }
      iVar9 = uVar16 - uVar14;
      if (local_30 == 1) {
        DAT_1008d288 = iVar9 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1008d288 = iVar9 * 0x8000;
      }
      else if ((((int)local_30 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
        DAT_1008d288 = *(uint *)(uVar11 + (iVar9 * 0x20 + local_30) * 4);
      }
      else if (iVar9 < 0) {
        DAT_1008d288 = (iVar9 * 0x10000) / (int)local_30;
      }
      else {
        DAT_1008d288 = (iVar9 * 0x10000) / (int)local_30;
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
      if ((uVar17 == uVar12) || (iVar4 == 1)) {
        uVar17 = uVar17 - uVar12;
      }
      else if (iVar4 == 2) {
        uVar17 = (int)(uVar17 - uVar12) >> 1;
      }
      else {
        uVar17 = (int)(uVar17 - uVar12) / iVar4;
      }
      if ((uVar13 == uVar18) || (local_30 == 1)) {
        uVar13 = uVar13 - uVar18;
      }
      else if (local_30 == 2) {
        uVar13 = (int)(uVar13 - uVar18) >> 1;
      }
      else {
        uVar13 = (int)(uVar13 - uVar18) / (int)local_30;
      }
      if ((uVar10 == uVar12) || (local_30 == 1)) {
        uVar10 = uVar10 - uVar12;
      }
      else if (local_30 == 2) {
        uVar10 = (int)(uVar10 - uVar12) >> 1;
      }
      else {
        uVar10 = (int)(uVar10 - uVar12) / (int)local_30;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      uVar15 = uVar14 << 0x10;
      DAT_1008d2c0 = (uVar18 & 0xfffe) >> 1 | (uVar12 & 0xfffe) << 0xf;
      DAT_1008d2c8 = (uVar19 & 0xfffe) >> 1 | (uVar17 & 0xfffe) << 0xf;
      uVar14 = (uVar13 & 0xfffe) >> 1 | (uVar10 & 0xfffe) << 0xf;
      DAT_1008d284 = uVar15;
      DAT_1008d2c4 = uVar14;
      goto LAB_1000e549;
    }
    iVar4 = uVar14 - DAT_1008d280;
    uVar15 = uVar5;
    if (uVar5 == 1) {
      DAT_1008d288 = iVar4 * 0x10000;
    }
    else if (uVar5 == 2) {
      DAT_1008d288 = iVar4 * 0x8000;
    }
    else if ((((int)uVar5 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1008d288 = *(uint *)(uVar11 + (iVar4 * 0x20 + uVar5) * 4);
      uVar15 = uVar11;
    }
    else if (iVar4 < 0) {
      DAT_1008d288 = (iVar4 * 0x10000) / (int)uVar5;
      uVar15 = (iVar4 * 0x10000) % (int)uVar5;
    }
    else {
      DAT_1008d288 = (iVar4 * 0x10000) / (int)uVar5;
      uVar15 = (iVar4 * 0x10000) % (int)uVar5;
    }
    uVar6 = DAT_1008d288 - DAT_1008d28c;
    if ((int)uVar6 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return uVar6;
    }
    if ((uVar13 == uVar18) || (local_30 == 1)) {
      uVar7 = uVar13 - uVar18;
    }
    else if (local_30 == 2) {
      uVar7 = (int)(uVar13 - uVar18) >> 1;
    }
    else {
      uVar7 = (int)(uVar13 - uVar18) / (int)local_30;
      uVar15 = (int)(uVar13 - uVar18) % (int)local_30;
    }
    if ((uVar10 == uVar12) || (local_30 == 1)) {
      uVar8 = uVar10 - uVar12;
    }
    else if (local_30 == 2) {
      uVar8 = (int)(uVar10 - uVar12) >> 1;
    }
    else {
      uVar8 = (int)(uVar10 - uVar12) / (int)local_30;
      uVar15 = (int)(uVar10 - uVar12) % (int)local_30;
    }
    if ((uVar19 == uVar18) || (uVar5 == 1)) {
      iVar4 = uVar19 - uVar18;
    }
    else if (uVar5 == 2) {
      iVar4 = (int)(uVar19 - uVar18) >> 1;
    }
    else {
      iVar4 = (int)(uVar19 - uVar18) / (int)uVar5;
      uVar15 = (int)(uVar19 - uVar18) % (int)uVar5;
    }
    uVar1 = iVar4 - uVar7;
    uVar21 = CONCAT44(uVar15,uVar1);
    if (uVar1 != 0) {
      uVar21 = FUN_1006a324(uVar6,uVar15,uVar1,uVar6);
    }
    iVar4 = (int)((ulonglong)uVar21 >> 0x20);
    local_14 = (uint)uVar21;
    if ((uVar17 == uVar12) || (uVar5 == 1)) {
      iVar9 = uVar17 - uVar12;
    }
    else if (uVar5 == 2) {
      iVar9 = (int)(uVar17 - uVar12) >> 1;
    }
    else {
      iVar9 = (int)(uVar17 - uVar12) / (int)uVar5;
      iVar4 = (int)(uVar17 - uVar12) % (int)uVar5;
    }
    uVar15 = 0;
    if (iVar9 - uVar8 != 0) {
      uVar21 = FUN_1006a324(uVar6,iVar4,iVar9 - uVar8,uVar6);
      uVar15 = (uint)uVar21;
    }
    DAT_1008d280 = DAT_1008d280 << 0x10;
    DAT_1008d284 = DAT_1008d280;
    if ((int)uVar5 <= (int)local_30) {
      DAT_1008d2c0 = (uVar18 & 0xfffe) >> 1 | (uVar12 & 0xfffe) << 0xf;
      DAT_1008d2c8 = (local_14 & 0xfffe) >> 1 | (uVar15 & 0xfffe) << 0xf;
      uVar12 = (uVar8 & 0xfffe) << 0xf;
      DAT_1008d2c4 = (uVar7 & 0xfffe) >> 1 | uVar12;
      local_30 = local_30 - uVar5;
      DAT_1008d290 = uVar5;
      uVar21 = FUN_10078a84(uVar12,uVar5);
      if (local_30 == 0) {
        return (uint)uVar21;
      }
      DAT_1008d284 = uVar14 << 0x10;
      iVar4 = uVar16 - uVar14;
      uVar15 = local_30;
      if (local_30 == 1) {
        DAT_1008d288 = iVar4 * 0x10000;
      }
      else if (local_30 == 2) {
        DAT_1008d288 = iVar4 * 0x8000;
      }
      else if ((((int)local_30 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
        uVar14 = *(uint *)(uVar11 + (iVar4 * 0x20 + local_30) * 4);
        uVar15 = uVar11;
        DAT_1008d288 = uVar14;
      }
      else if (iVar4 < 0) {
        DAT_1008d288 = (iVar4 * 0x10000) / (int)local_30;
        uVar15 = (iVar4 * 0x10000) % (int)local_30;
      }
      else {
        DAT_1008d288 = (iVar4 * 0x10000) / (int)local_30;
        uVar15 = (iVar4 * 0x10000) % (int)local_30;
      }
      goto LAB_1000e549;
    }
    DAT_1008d2c0 = (uVar18 & 0xfffe) >> 1 | (uVar12 & 0xfffe) << 0xf;
    uVar6 = (local_14 & 0xfffe) >> 1 | (uVar15 & 0xfffe) << 0xf;
    uVar5 = uVar5 - local_30;
    uVar12 = (uVar8 & 0xfffe) << 0xf;
    DAT_1008d2c4 = (uVar7 & 0xfffe) >> 1 | uVar12;
    DAT_1008d290 = local_30;
    DAT_1008d2c8 = uVar6;
    uVar21 = FUN_10078a84(uVar12,local_30);
    uVar15 = (uint)((ulonglong)uVar21 >> 0x20);
    iVar4 = uVar14 - uVar16;
    uVar14 = uVar16;
    if (uVar5 == 1) {
      DAT_1008d28c = iVar4 * 0x10000;
    }
    else if (uVar5 == 2) {
      DAT_1008d28c = iVar4 * 0x8000;
    }
    else if ((((int)uVar5 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1008d28c = *(uint *)(uVar11 + (iVar4 * 0x20 + uVar5) * 4);
      uVar14 = DAT_1008d28c;
      uVar15 = uVar11;
    }
    else if (iVar4 < 0) {
      DAT_1008d28c = (iVar4 * 0x10000) / (int)uVar5;
      uVar15 = (iVar4 * 0x10000) % (int)uVar5;
    }
    else {
      DAT_1008d28c = (iVar4 * 0x10000) / (int)uVar5;
      uVar15 = (iVar4 * 0x10000) % (int)uVar5;
    }
    if ((uVar19 == uVar13) || (uVar5 == 1)) {
      uVar18 = uVar19 - uVar13;
    }
    else if (uVar5 == 2) {
      uVar18 = (int)(uVar19 - uVar13) >> 1;
    }
    else {
      uVar18 = (int)(uVar19 - uVar13) / (int)uVar5;
      uVar15 = (int)(uVar19 - uVar13) % (int)uVar5;
    }
    local_30 = uVar5;
    if ((uVar17 == uVar10) || (uVar5 == 1)) {
      uVar12 = uVar17 - uVar10;
      DAT_1008d2c8 = uVar6;
    }
    else if (uVar5 == 2) {
      uVar12 = (int)(uVar17 - uVar10) >> 1;
      DAT_1008d2c8 = uVar6;
    }
    else {
      uVar12 = (int)(uVar17 - uVar10) / (int)uVar5;
      uVar15 = (int)(uVar17 - uVar10) % (int)uVar5;
      DAT_1008d2c8 = uVar6;
    }
  }
  DAT_1008d280 = uVar16 << 0x10;
  DAT_1008d2c4 = (uVar18 & 0xfffe) >> 1 | (uVar12 & 0xfffe) << 0xf;
LAB_1000e549:
  DAT_1008d290 = local_30;
  uVar21 = FUN_10078a84(uVar14,uVar15);
  return (uint)uVar21;
}


