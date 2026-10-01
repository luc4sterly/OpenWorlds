// 10029120 FUN_10029120 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10029120(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  ushort uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  short sVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  short sVar19;
  uint uVar20;
  int iVar21;
  ushort uVar22;
  uint uVar23;
  int iVar24;
  short sVar25;
  uint uVar26;
  int local_38;
  uint local_30;
  uint local_2c;
  uint local_28;
  short local_24;
  uint local_20;
  short local_18;
  uint local_14;
  ushort uVar3;
  
  iVar8 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar8 = param_2;
      param_2 = param_4;
      param_4 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1002916d;
  param_3 = param_2;
  param_2 = param_4;
  param_4 = iVar8;
LAB_1002916d:
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  local_38 = (int)*(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar23 = *(uint *)(*param_1 + 8);
  uVar4 = (uVar23 & 0x7c0) >> 6;
  uVar5 = (uVar23 & 0xf800) >> 0xb;
  uVar16 = (uint)*(byte *)((*(int *)(param_2 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 + uVar4)
  ;
  uVar23 = uVar23 & 0x1f;
  local_2c = (uint)*(byte *)((*(int *)(param_2 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar5);
  uVar6 = local_2c << 0x10;
  iVar17 = (uVar16 | uVar6) << 8;
  uVar20 = (uint)*(byte *)((*(int *)(param_2 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar23
                          );
  iVar7 = (int)*(short *)(param_3 + 0x1a);
  iVar21 = uVar20 * 0x100;
  local_28 = (uint)*(byte *)((*(int *)(param_3 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 +
                            uVar4);
  uVar1 = local_28;
  local_2c = (uint)*(byte *)((*(int *)(param_3 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar5);
  iVar8 = (local_28 | local_2c << 0x10) << 8;
  uVar9 = (uint)*(byte *)((*(int *)(param_3 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar23)
  ;
  iVar18 = (int)*(short *)(param_4 + 0x1a);
  iVar10 = uVar9 * 0x100;
  uVar5 = (uint)*(byte *)((*(int *)(param_4 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar5) << 0x10;
  local_30 = (uint)*(byte *)((*(int *)(param_4 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 +
                            uVar4);
  uVar4 = local_30;
  iVar11 = (uVar5 | local_30) << 8;
  iVar12 = (uint)*(byte *)((*(int *)(param_4 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar23
                          ) * 0x100;
  DAT_1008d298 = DAT_10089ddc;
  iVar13 = DAT_1008723c + 0x1000;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  sVar15 = (short)iVar17;
  sVar19 = (short)iVar21;
  uVar23 = iVar17 >> 0x10;
  uVar2 = (ushort)(uVar6 >> 8);
  local_24 = (short)iVar8;
  local_18 = (short)iVar11;
  local_28._0_2_ = (short)iVar12;
  uVar6 = iVar11 >> 0x10;
  uVar26 = iVar8 >> 0x10;
  uVar22 = (ushort)((local_2c << 0x10) >> 8);
  uVar3 = (ushort)(uVar5 >> 8);
  sVar25 = (short)iVar10;
  if (local_38 < 1) {
    iVar11 = DAT_1008d280 - iVar7;
    if (iVar11 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    local_38 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_38 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar17 = iVar18 - iVar7;
    if (local_38 == 1) {
      DAT_1008d28c = iVar17 * 0x10000;
    }
    else if (local_38 == 2) {
      DAT_1008d28c = iVar17 * 0x8000;
    }
    else if (((local_38 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar13 + (iVar17 * 0x20 + local_38) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1008d28c = (iVar17 * 0x10000) / local_38;
    }
    else {
      DAT_1008d28c = (iVar17 * 0x10000) / local_38;
    }
    iVar18 = iVar18 - DAT_1008d280;
    if (local_38 == 1) {
      DAT_1008d288 = iVar18 * 0x10000;
    }
    else if (local_38 == 2) {
      DAT_1008d288 = iVar18 * 0x8000;
    }
    else if (((local_38 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar13 + (iVar18 * 0x20 + local_38) * 4);
    }
    else if (iVar18 < 0) {
      DAT_1008d288 = (iVar18 * 0x10000) / local_38;
    }
    else {
      DAT_1008d288 = (iVar18 * 0x10000) / local_38;
    }
    if ((uVar22 == uVar2) || (iVar11 == 1)) {
      iVar13 = (uVar23 & 0xffff) - (uVar26 & 0xffff);
    }
    else if (iVar11 == 2) {
      iVar13 = (int)((uVar23 & 0xffff) - (uVar26 & 0xffff)) >> 1;
    }
    else {
      iVar13 = (int)((uVar23 & 0xffff) - (uVar26 & 0xffff)) / iVar11;
    }
    uVar26 = uVar26 & 0xffff;
    if ((uVar3 == uVar22) || (local_38 == 1)) {
      iVar18 = (uVar6 & 0xffff) - uVar26;
    }
    else if (local_38 == 2) {
      iVar18 = (int)((uVar6 & 0xffff) - uVar26) >> 1;
    }
    else {
      iVar18 = (int)((uVar6 & 0xffff) - uVar26) / local_38;
    }
    DAT_1008d2c4 = iVar18 << 0x10;
    iVar18 = uVar16 * 0x100;
    if ((local_24 == sVar15) || (iVar11 == 1)) {
      uVar23 = iVar18 + uVar1 * -0x100;
    }
    else if (iVar11 == 2) {
      uVar23 = (int)(iVar18 + uVar1 * -0x100) >> 1;
    }
    else {
      uVar23 = (int)(iVar18 + uVar1 * -0x100) / iVar11;
    }
    DAT_1008d2c8 = (iVar13 << 0x10 | uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
    iVar13 = local_30 * 0x100;
    if ((local_18 == local_24) || (local_38 == 1)) {
      uVar23 = iVar13 + uVar1 * -0x100;
    }
    else if (local_38 == 2) {
      uVar23 = (int)(iVar13 + uVar1 * -0x100) >> 1;
    }
    else {
      uVar23 = (int)(iVar13 + uVar1 * -0x100) / local_38;
    }
    DAT_1008d2c4 = (DAT_1008d2c4 | uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
    iVar13 = uVar20 * 0x100;
    if ((sVar25 == sVar19) || (iVar11 == 1)) {
      uVar23 = iVar13 + uVar9 * -0x100;
    }
    else if (iVar11 == 2) {
      uVar23 = (int)(iVar13 + uVar9 * -0x100) >> 1;
    }
    else {
      uVar23 = (int)(iVar13 + uVar9 * -0x100) / iVar11;
    }
    DAT_1008d2d4 = (uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
    if (((short)local_28 == sVar25) || (local_38 == 1)) {
      uVar23 = iVar12 + uVar9 * -0x100;
    }
    else if (local_38 == 2) {
      uVar23 = (int)(iVar12 + uVar9 * -0x100) >> 1;
    }
    else {
      uVar23 = (int)(iVar12 + uVar9 * -0x100) / local_38;
    }
    DAT_1008d2d0 = (uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d280 = iVar7 << 0x10;
    DAT_1008d2c0 = iVar8;
    DAT_1008d2cc = iVar10;
  }
  else {
    iVar8 = iVar7 - DAT_1008d280;
    if (local_38 == 1) {
      DAT_1008d28c = iVar8 * 0x10000;
    }
    else if (local_38 == 2) {
      DAT_1008d28c = iVar8 * 0x8000;
    }
    else if (((local_38 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar13 + (iVar8 * 0x20 + local_38) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1008d28c = (iVar8 * 0x10000) / local_38;
    }
    else {
      DAT_1008d28c = (iVar8 * 0x10000) / local_38;
    }
    iVar8 = (int)*(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (iVar8 < 1) {
      iVar8 = iVar18 - DAT_1008d280;
      if (iVar8 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar7 = iVar7 - iVar18;
      if (local_38 == 1) {
        DAT_1008d288 = iVar7 * 0x10000;
      }
      else if (local_38 == 2) {
        DAT_1008d288 = iVar7 * 0x8000;
      }
      else if (((local_38 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar13 + (iVar7 * 0x20 + local_38) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1008d288 = (iVar7 * 0x10000) / local_38;
      }
      else {
        DAT_1008d288 = (iVar7 * 0x10000) / local_38;
      }
      local_30 = (uint)uVar2;
      if ((uVar3 == uVar2) || (iVar8 == 1)) {
        iVar11 = (uVar6 & 0xffff) - local_30;
      }
      else if (iVar8 == 2) {
        iVar11 = (int)((uVar6 & 0xffff) - local_30) >> 1;
      }
      else {
        iVar11 = (int)((uVar6 & 0xffff) - local_30) / iVar8;
      }
      iVar13 = uVar4 * 0x100;
      if ((local_18 == sVar15) || (iVar8 == 1)) {
        uVar23 = iVar13 + uVar16 * -0x100;
      }
      else if (iVar8 == 2) {
        uVar23 = (int)(iVar13 + uVar16 * -0x100) >> 1;
      }
      else {
        uVar23 = (int)(iVar13 + uVar16 * -0x100) / iVar8;
      }
      DAT_1008d2c8 = (iVar11 << 0x10 | uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
      if ((uVar22 == uVar2) || (local_38 == 1)) {
        iVar11 = (uVar26 & 0xffff) - local_30;
      }
      else if (local_38 == 2) {
        iVar11 = (int)((uVar26 & 0xffff) - local_30) >> 1;
      }
      else {
        iVar11 = (int)((uVar26 & 0xffff) - local_30) / local_38;
      }
      iVar13 = uVar1 * 0x100;
      if ((local_24 == sVar15) || (local_38 == 1)) {
        uVar23 = iVar13 + uVar16 * -0x100;
      }
      else if (local_38 == 2) {
        uVar23 = (int)(iVar13 + uVar16 * -0x100) >> 1;
      }
      else {
        uVar23 = (int)(iVar13 + uVar16 * -0x100) / local_38;
      }
      DAT_1008d2c4 = (iVar11 << 0x10 | uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
      if (((short)local_28 == sVar19) || (iVar8 == 1)) {
        uVar23 = iVar12 + uVar20 * -0x100;
      }
      else if (iVar8 == 2) {
        uVar23 = (int)(iVar12 + uVar20 * -0x100) >> 1;
      }
      else {
        uVar23 = (int)(iVar12 + uVar20 * -0x100) / iVar8;
      }
      DAT_1008d2d4 = (uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
      if ((sVar25 == sVar19) || (local_38 == 1)) {
        uVar23 = iVar10 + uVar20 * -0x100;
      }
      else if (local_38 == 2) {
        uVar23 = (int)(iVar10 + uVar20 * -0x100) >> 1;
      }
      else {
        uVar23 = (int)(iVar10 + uVar20 * -0x100) / local_38;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d2d0 = (uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
      DAT_1008d284 = iVar18 << 0x10;
      DAT_1008d2c0 = iVar17;
      DAT_1008d2cc = iVar21;
    }
    else {
      iVar11 = iVar18 - DAT_1008d280;
      if (iVar8 == 1) {
        DAT_1008d288 = iVar11 * 0x10000;
      }
      else if (iVar8 == 2) {
        DAT_1008d288 = iVar11 * 0x8000;
      }
      else if (((iVar8 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar13 + (iVar11 * 0x20 + iVar8) * 4);
      }
      else if (iVar11 < 0) {
        DAT_1008d288 = (iVar11 * 0x10000) / iVar8;
      }
      else {
        DAT_1008d288 = (iVar11 * 0x10000) / iVar8;
      }
      iVar11 = DAT_1008d288 - DAT_1008d28c;
      if (iVar11 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      if ((uVar22 == uVar2) || (local_38 == 1)) {
        iVar14 = (uint)uVar22 - (uVar23 & 0xffff);
      }
      else if (local_38 == 2) {
        iVar14 = (int)((uint)uVar22 - (uVar23 & 0xffff)) >> 1;
      }
      else {
        iVar14 = (int)((uint)uVar22 - (uVar23 & 0xffff)) / local_38;
      }
      local_20 = (uint)uVar22;
      uVar23 = uVar23 & 0xffff;
      if ((local_24 == sVar15) || (local_38 == 1)) {
        uVar4 = uVar1 * 0x100 + uVar16 * -0x100;
      }
      else if (local_38 == 2) {
        uVar4 = (int)(uVar1 * 0x100 + uVar16 * -0x100) >> 1;
      }
      else {
        uVar4 = (int)(uVar1 * 0x100 + uVar16 * -0x100) / local_38;
      }
      DAT_1008d2c4 = (iVar14 << 0x10 | uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
      local_14 = (uint)uVar3;
      if ((uVar3 == uVar2) || (iVar8 == 1)) {
        iVar14 = local_14 - uVar23;
      }
      else if (iVar8 == 2) {
        iVar14 = (int)(local_14 - uVar23) >> 1;
      }
      else {
        iVar14 = (int)(local_14 - uVar23) / iVar8;
      }
      DAT_1008d2c8 = iVar14 - (DAT_1008d2c4 >> 0x10);
      if (DAT_1008d2c8 != 0) {
        DAT_1008d2c8 = (int)(DAT_1008d2c8 * 0x10000) / iVar11 << 0x10;
      }
      if ((local_18 == sVar15) || (iVar8 == 1)) {
        iVar14 = local_30 * 0x100 + uVar16 * -0x100;
      }
      else if (iVar8 == 2) {
        iVar14 = (int)(local_30 * 0x100 + uVar16 * -0x100) >> 1;
      }
      else {
        iVar14 = (int)(local_30 * 0x100 + uVar16 * -0x100) / iVar8;
      }
      iVar24 = local_30 * 0x100;
      if (iVar14 - (short)DAT_1008d2c4 != 0) {
        uVar23 = DAT_1008d2c8 | ((iVar14 - (short)DAT_1008d2c4) * 0x10000) / iVar11 & 0xffffU;
        DAT_1008d2c8 = uVar23 + (uVar23 & 0x8000) * -2;
      }
      if ((sVar25 == sVar19) || (local_38 == 1)) {
        uVar23 = iVar10 + uVar20 * -0x100;
      }
      else if (local_38 == 2) {
        uVar23 = (int)(iVar10 + uVar20 * -0x100) >> 1;
      }
      else {
        uVar23 = (int)(iVar10 + uVar20 * -0x100) / local_38;
      }
      DAT_1008d2d4 = 0;
      DAT_1008d2d0 = (uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
      if (((short)local_28 == sVar19) || (iVar8 == 1)) {
        iVar10 = iVar12 + uVar20 * -0x100;
      }
      else if (iVar8 == 2) {
        iVar10 = (int)(iVar12 + uVar20 * -0x100) >> 1;
      }
      else {
        iVar10 = (int)(iVar12 + uVar20 * -0x100) / iVar8;
      }
      if (iVar10 - (short)DAT_1008d2d0 != 0) {
        uVar23 = ((iVar10 - (short)DAT_1008d2d0) * 0x10000) / iVar11;
        DAT_1008d2d4 = (uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (local_38 < iVar8) {
        iVar8 = iVar8 - local_38;
        DAT_1008d290 = local_38;
        DAT_1008d2c0 = iVar17;
        DAT_1008d2cc = iVar21;
        FUN_1007ad88();
        DAT_1008d280 = iVar7 << 0x10;
        iVar18 = iVar18 - iVar7;
        if (iVar8 == 1) {
          DAT_1008d28c = iVar18 * 0x10000;
        }
        else if (iVar8 == 2) {
          DAT_1008d28c = iVar18 * 0x8000;
        }
        else if (((iVar8 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar13 + (iVar18 * 0x20 + iVar8) * 4);
        }
        else if (iVar18 < 0) {
          DAT_1008d28c = (iVar18 * 0x10000) / iVar8;
        }
        else {
          DAT_1008d28c = (iVar18 * 0x10000) / iVar8;
        }
        if ((uVar3 == uVar22) || (iVar8 == 1)) {
          DAT_1008d2c4 = local_14 - local_20;
        }
        else if (iVar8 == 2) {
          DAT_1008d2c4 = (int)(local_14 - local_20) >> 1;
        }
        else {
          DAT_1008d2c4 = (int)(local_14 - local_20) / iVar8;
        }
        DAT_1008d2c4 = DAT_1008d2c4 << 0x10;
        if ((local_18 == local_24) || (iVar8 == 1)) {
          uVar23 = iVar24 + uVar1 * -0x100;
        }
        else if (iVar8 == 2) {
          uVar23 = (int)(iVar24 + uVar1 * -0x100) >> 1;
        }
        else {
          uVar23 = (int)(iVar24 + uVar1 * -0x100) / iVar8;
        }
        if (uVar23 != 0) {
          DAT_1008d2c4 = (DAT_1008d2c4 | uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
        }
        DAT_1008d2d0 = 0;
        if (((short)local_28 == sVar25) || (iVar8 == 1)) {
          uVar23 = iVar12 + uVar9 * -0x100;
        }
        else if (iVar8 == 2) {
          uVar23 = (int)(iVar12 + uVar9 * -0x100) >> 1;
        }
        else {
          uVar23 = (int)(iVar12 + uVar9 * -0x100) / iVar8;
        }
        local_38 = iVar8;
        if (uVar23 != 0) {
          DAT_1008d2d0 = (uVar23 & 0xffff) + (uVar23 & 0x8000) * -2;
        }
      }
      else {
        local_38 = local_38 - iVar8;
        DAT_1008d290 = iVar8;
        DAT_1008d2c0 = iVar17;
        DAT_1008d2cc = iVar21;
        FUN_1007ad88();
        if (local_38 == 0) {
          return;
        }
        DAT_1008d284 = iVar18 << 0x10;
        iVar7 = iVar7 - iVar18;
        if (local_38 == 1) {
          DAT_1008d288 = iVar7 * 0x10000;
        }
        else if (local_38 == 2) {
          DAT_1008d288 = iVar7 * 0x8000;
        }
        else if (((local_38 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar13 + (iVar7 * 0x20 + local_38) * 4);
        }
        else if (iVar7 < 0) {
          DAT_1008d288 = (iVar7 * 0x10000) / local_38;
        }
        else {
          DAT_1008d288 = (iVar7 * 0x10000) / local_38;
        }
      }
    }
  }
  DAT_1008d290 = local_38;
  FUN_1007ad88();
  return;
}


