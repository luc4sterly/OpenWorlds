// 1002b530 FUN_1002b530 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002b530(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  short sVar17;
  uint uVar18;
  int iVar19;
  short sVar20;
  uint uVar21;
  int iVar22;
  ushort uVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  short sVar27;
  int local_38;
  uint local_30;
  uint local_2c;
  short local_28;
  uint local_20;
  short local_18;
  uint local_14;
  ushort uVar4;
  
  iVar10 = param_3;
  iVar12 = param_4;
  iVar13 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar10 = param_2;
      iVar12 = param_3;
      iVar13 = param_4;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1002b57f;
  param_2 = iVar12;
  param_3 = iVar13;
  param_4 = iVar10;
LAB_1002b57f:
  DAT_1008d284 = (int)*(short *)(param_2 + 0x1e);
  local_38 = *(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar26 = *(uint *)(*param_1 + 8);
  uVar5 = (uVar26 & 0x7c0) >> 6;
  uVar6 = (uVar26 & 0xf800) >> 0xb;
  uVar18 = (uint)*(byte *)((*(int *)(param_2 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 + uVar5)
  ;
  uVar26 = uVar26 & 0x1f;
  local_30 = (uint)*(byte *)((*(int *)(param_2 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar6);
  uVar7 = local_30 << 0x10;
  iVar19 = (uVar18 | uVar7) << 8;
  uVar21 = (uint)*(byte *)((*(int *)(param_2 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar26
                          );
  iVar8 = (int)*(short *)(param_3 + 0x1a);
  iVar22 = uVar21 * 0x100;
  uVar9 = (uint)*(byte *)((*(int *)(param_3 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar6) << 0x10;
  local_30 = (uint)*(byte *)((*(int *)(param_3 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 +
                            uVar5);
  uVar2 = local_30;
  iVar10 = (uVar9 | local_30) << 8;
  uVar11 = (uint)*(byte *)((*(int *)(param_3 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar26
                          );
  iVar24 = (int)*(short *)(param_4 + 0x1a);
  iVar12 = uVar11 * 0x100;
  local_2c = (uint)*(byte *)((*(int *)(param_4 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 +
                            uVar5);
  uVar5 = local_2c;
  bVar1 = *(byte *)((*(int *)(param_4 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar6);
  local_30 = (uint)bVar1;
  iVar13 = (local_2c | local_30 << 0x10) << 8;
  iVar14 = (uint)*(byte *)((*(int *)(param_4 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar26
                          ) * 0x100;
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar15 = DAT_1008723c + 0x1000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  sVar17 = (short)iVar19;
  sVar20 = (short)iVar22;
  uVar26 = iVar19 >> 0x10;
  uVar3 = (ushort)(uVar7 >> 8);
  local_28 = (short)iVar10;
  local_18 = (short)iVar13;
  local_2c._0_2_ = (short)iVar14;
  uVar6 = iVar13 >> 0x10;
  uVar7 = iVar10 >> 0x10;
  uVar23 = (ushort)(uVar9 >> 8);
  uVar4 = (ushort)((local_30 << 0x10) >> 8);
  sVar27 = (short)iVar12;
  if (local_38 < 1) {
    iVar13 = DAT_1008d280 - iVar8;
    if (iVar13 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    local_38 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_38 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar19 = iVar24 - iVar8;
    if (local_38 == 1) {
      DAT_1008d28c = iVar19 * 0x10000;
    }
    else if (local_38 == 2) {
      DAT_1008d28c = iVar19 * 0x8000;
    }
    else if (((local_38 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar15 + (iVar19 * 0x20 + local_38) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1008d28c = (iVar19 * 0x10000) / local_38;
    }
    else {
      DAT_1008d28c = (iVar19 * 0x10000) / local_38;
    }
    iVar24 = iVar24 - DAT_1008d280;
    if (local_38 == 1) {
      DAT_1008d288 = iVar24 * 0x10000;
    }
    else if (local_38 == 2) {
      DAT_1008d288 = iVar24 * 0x8000;
    }
    else if (((local_38 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar15 + (iVar24 * 0x20 + local_38) * 4);
    }
    else if (iVar24 < 0) {
      DAT_1008d288 = (iVar24 * 0x10000) / local_38;
    }
    else {
      DAT_1008d288 = (iVar24 * 0x10000) / local_38;
    }
    if ((uVar23 == uVar3) || (iVar13 == 1)) {
      iVar15 = (uVar26 & 0xffff) - (uVar7 & 0xffff);
    }
    else if (iVar13 == 2) {
      iVar15 = (int)((uVar26 & 0xffff) - (uVar7 & 0xffff)) >> 1;
    }
    else {
      iVar15 = (int)((uVar26 & 0xffff) - (uVar7 & 0xffff)) / iVar13;
    }
    uVar7 = uVar7 & 0xffff;
    if ((uVar4 == uVar23) || (local_38 == 1)) {
      iVar24 = (uVar6 & 0xffff) - uVar7;
    }
    else if (local_38 == 2) {
      iVar24 = (int)((uVar6 & 0xffff) - uVar7) >> 1;
    }
    else {
      iVar24 = (int)((uVar6 & 0xffff) - uVar7) / local_38;
    }
    DAT_1008d2c4 = iVar24 << 0x10;
    iVar24 = uVar18 * 0x100;
    if ((local_28 == sVar17) || (iVar13 == 1)) {
      uVar26 = iVar24 + uVar2 * -0x100;
    }
    else if (iVar13 == 2) {
      uVar26 = (int)(iVar24 + uVar2 * -0x100) >> 1;
    }
    else {
      uVar26 = (int)(iVar24 + uVar2 * -0x100) / iVar13;
    }
    DAT_1008d2c8 = (iVar15 << 0x10 | uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
    iVar15 = uVar5 * 0x100;
    if ((local_18 == local_28) || (local_38 == 1)) {
      uVar26 = iVar15 + uVar2 * -0x100;
    }
    else if (local_38 == 2) {
      uVar26 = (int)(iVar15 + uVar2 * -0x100) >> 1;
    }
    else {
      uVar26 = (int)(iVar15 + uVar2 * -0x100) / local_38;
    }
    DAT_1008d2c4 = (DAT_1008d2c4 | uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
    iVar15 = uVar21 * 0x100;
    if ((sVar27 == sVar20) || (iVar13 == 1)) {
      uVar26 = iVar15 + uVar11 * -0x100;
    }
    else if (iVar13 == 2) {
      uVar26 = (int)(iVar15 + uVar11 * -0x100) >> 1;
    }
    else {
      uVar26 = (int)(iVar15 + uVar11 * -0x100) / iVar13;
    }
    DAT_1008d2d4 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
    if (((short)local_2c == sVar27) || (local_38 == 1)) {
      uVar26 = iVar14 + uVar11 * -0x100;
    }
    else if (local_38 == 2) {
      uVar26 = (int)(iVar14 + uVar11 * -0x100) >> 1;
    }
    else {
      uVar26 = (int)(iVar14 + uVar11 * -0x100) / local_38;
    }
    DAT_1008d2d0 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d280 = iVar8 << 0x10;
    DAT_1008d2c0 = iVar10;
    DAT_1008d2cc = iVar12;
  }
  else {
    iVar10 = iVar8 - DAT_1008d280;
    if (local_38 == 1) {
      DAT_1008d28c = iVar10 * 0x10000;
    }
    else if (local_38 == 2) {
      DAT_1008d28c = iVar10 * 0x8000;
    }
    else if (((local_38 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar15 + (iVar10 * 0x20 + local_38) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1008d28c = (iVar10 * 0x10000) / local_38;
    }
    else {
      DAT_1008d28c = (iVar10 * 0x10000) / local_38;
    }
    iVar10 = *(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (iVar10 < 1) {
      iVar10 = iVar24 - DAT_1008d280;
      if (iVar10 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar8 = iVar8 - iVar24;
      if (local_38 == 1) {
        DAT_1008d288 = iVar8 * 0x10000;
      }
      else if (local_38 == 2) {
        DAT_1008d288 = iVar8 * 0x8000;
      }
      else if (((local_38 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar15 + (iVar8 * 0x20 + local_38) * 4);
      }
      else if (iVar8 < 0) {
        DAT_1008d288 = (iVar8 * 0x10000) / local_38;
      }
      else {
        DAT_1008d288 = (iVar8 * 0x10000) / local_38;
      }
      local_30 = (uint)CONCAT12(bVar1,uVar3);
      if ((uVar4 == uVar3) || (iVar10 == 1)) {
        iVar13 = (uVar6 & 0xffff) - (local_30 & 0xffff);
      }
      else if (iVar10 == 2) {
        iVar13 = (int)((uVar6 & 0xffff) - (local_30 & 0xffff)) >> 1;
      }
      else {
        iVar13 = (int)((uVar6 & 0xffff) - (local_30 & 0xffff)) / iVar10;
      }
      uVar26 = (uint)uVar3;
      iVar15 = uVar5 * 0x100;
      if ((local_18 == sVar17) || (iVar10 == 1)) {
        uVar5 = iVar15 + uVar18 * -0x100;
      }
      else if (iVar10 == 2) {
        uVar5 = (int)(iVar15 + uVar18 * -0x100) >> 1;
      }
      else {
        uVar5 = (int)(iVar15 + uVar18 * -0x100) / iVar10;
      }
      DAT_1008d2c8 = (iVar13 << 0x10 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      if ((uVar23 == uVar3) || (local_38 == 1)) {
        iVar13 = (uVar7 & 0xffff) - uVar26;
      }
      else if (local_38 == 2) {
        iVar13 = (int)((uVar7 & 0xffff) - uVar26) >> 1;
      }
      else {
        iVar13 = (int)((uVar7 & 0xffff) - uVar26) / local_38;
      }
      iVar15 = uVar2 * 0x100;
      if ((local_28 == sVar17) || (local_38 == 1)) {
        uVar26 = iVar15 + uVar18 * -0x100;
      }
      else if (local_38 == 2) {
        uVar26 = (int)(iVar15 + uVar18 * -0x100) >> 1;
      }
      else {
        uVar26 = (int)(iVar15 + uVar18 * -0x100) / local_38;
      }
      DAT_1008d2c4 = (iVar13 << 0x10 | uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
      if (((short)local_2c == sVar20) || (iVar10 == 1)) {
        uVar26 = iVar14 + uVar21 * -0x100;
      }
      else if (iVar10 == 2) {
        uVar26 = (int)(iVar14 + uVar21 * -0x100) >> 1;
      }
      else {
        uVar26 = (int)(iVar14 + uVar21 * -0x100) / iVar10;
      }
      DAT_1008d2d4 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
      if ((sVar27 == sVar20) || (local_38 == 1)) {
        uVar26 = iVar12 + uVar21 * -0x100;
      }
      else if (local_38 == 2) {
        uVar26 = (int)(iVar12 + uVar21 * -0x100) >> 1;
      }
      else {
        uVar26 = (int)(iVar12 + uVar21 * -0x100) / local_38;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d2d0 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
      DAT_1008d284 = iVar24 << 0x10;
      DAT_1008d2c0 = iVar19;
      DAT_1008d2cc = iVar22;
    }
    else {
      iVar13 = iVar24 - DAT_1008d280;
      if (iVar10 == 1) {
        DAT_1008d288 = iVar13 * 0x10000;
      }
      else if (iVar10 == 2) {
        DAT_1008d288 = iVar13 * 0x8000;
      }
      else if (((iVar10 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar15 + (iVar13 * 0x20 + iVar10) * 4);
      }
      else if (iVar13 < 0) {
        DAT_1008d288 = (iVar13 * 0x10000) / iVar10;
      }
      else {
        DAT_1008d288 = (iVar13 * 0x10000) / iVar10;
      }
      iVar13 = DAT_1008d288 - DAT_1008d28c;
      if (iVar13 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      if ((uVar23 == uVar3) || (local_38 == 1)) {
        iVar16 = (uint)uVar23 - (uVar26 & 0xffff);
      }
      else if (local_38 == 2) {
        iVar16 = (int)((uint)uVar23 - (uVar26 & 0xffff)) >> 1;
      }
      else {
        iVar16 = (int)((uint)uVar23 - (uVar26 & 0xffff)) / local_38;
      }
      local_20 = (uint)uVar23;
      uVar26 = uVar26 & 0xffff;
      if ((local_28 == sVar17) || (local_38 == 1)) {
        uVar6 = uVar2 * 0x100 + uVar18 * -0x100;
      }
      else if (local_38 == 2) {
        uVar6 = (int)(uVar2 * 0x100 + uVar18 * -0x100) >> 1;
      }
      else {
        uVar6 = (int)(uVar2 * 0x100 + uVar18 * -0x100) / local_38;
      }
      DAT_1008d2c4 = (iVar16 << 0x10 | uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
      local_14 = (uint)uVar4;
      if ((uVar4 == uVar3) || (iVar10 == 1)) {
        iVar16 = local_14 - uVar26;
      }
      else if (iVar10 == 2) {
        iVar16 = (int)(local_14 - uVar26) >> 1;
      }
      else {
        iVar16 = (int)(local_14 - uVar26) / iVar10;
      }
      DAT_1008d2c8 = iVar16 - (DAT_1008d2c4 >> 0x10);
      if (DAT_1008d2c8 != 0) {
        DAT_1008d2c8 = (int)(DAT_1008d2c8 * 0x10000) / iVar13 << 0x10;
      }
      if ((local_18 == sVar17) || (iVar10 == 1)) {
        iVar16 = uVar5 * 0x100 + uVar18 * -0x100;
      }
      else if (iVar10 == 2) {
        iVar16 = (int)(uVar5 * 0x100 + uVar18 * -0x100) >> 1;
      }
      else {
        iVar16 = (int)(uVar5 * 0x100 + uVar18 * -0x100) / iVar10;
      }
      iVar25 = uVar5 * 0x100;
      if (iVar16 - (short)DAT_1008d2c4 != 0) {
        uVar26 = DAT_1008d2c8 | ((iVar16 - (short)DAT_1008d2c4) * 0x10000) / iVar13 & 0xffffU;
        DAT_1008d2c8 = uVar26 + (uVar26 & 0x8000) * -2;
      }
      if ((sVar27 == sVar20) || (local_38 == 1)) {
        uVar26 = iVar12 + uVar21 * -0x100;
      }
      else if (local_38 == 2) {
        uVar26 = (int)(iVar12 + uVar21 * -0x100) >> 1;
      }
      else {
        uVar26 = (int)(iVar12 + uVar21 * -0x100) / local_38;
      }
      DAT_1008d2d4 = 0;
      DAT_1008d2d0 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
      if (((short)local_2c == sVar20) || (iVar10 == 1)) {
        iVar12 = iVar14 + uVar21 * -0x100;
      }
      else if (iVar10 == 2) {
        iVar12 = (int)(iVar14 + uVar21 * -0x100) >> 1;
      }
      else {
        iVar12 = (int)(iVar14 + uVar21 * -0x100) / iVar10;
      }
      if (iVar12 - (short)DAT_1008d2d0 != 0) {
        uVar26 = ((iVar12 - (short)DAT_1008d2d0) * 0x10000) / iVar13;
        DAT_1008d2d4 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (local_38 < iVar10) {
        iVar10 = iVar10 - local_38;
        DAT_1008d290 = local_38;
        DAT_1008d2c0 = iVar19;
        DAT_1008d2cc = iVar22;
        FUN_1007b07c();
        DAT_1008d280 = iVar8 << 0x10;
        iVar24 = iVar24 - iVar8;
        if (iVar10 == 1) {
          DAT_1008d28c = iVar24 * 0x10000;
        }
        else if (iVar10 == 2) {
          DAT_1008d28c = iVar24 * 0x8000;
        }
        else if (((iVar10 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar15 + (iVar24 * 0x20 + iVar10) * 4);
        }
        else if (iVar24 < 0) {
          DAT_1008d28c = (iVar24 * 0x10000) / iVar10;
        }
        else {
          DAT_1008d28c = (iVar24 * 0x10000) / iVar10;
        }
        if ((uVar4 == uVar23) || (iVar10 == 1)) {
          DAT_1008d2c4 = local_14 - local_20;
        }
        else if (iVar10 == 2) {
          DAT_1008d2c4 = (int)(local_14 - local_20) >> 1;
        }
        else {
          DAT_1008d2c4 = (int)(local_14 - local_20) / iVar10;
        }
        DAT_1008d2c4 = DAT_1008d2c4 << 0x10;
        if ((local_18 == local_28) || (iVar10 == 1)) {
          uVar26 = iVar25 + uVar2 * -0x100;
        }
        else if (iVar10 == 2) {
          uVar26 = (int)(iVar25 + uVar2 * -0x100) >> 1;
        }
        else {
          uVar26 = (int)(iVar25 + uVar2 * -0x100) / iVar10;
        }
        if (uVar26 != 0) {
          DAT_1008d2c4 = (DAT_1008d2c4 | uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
        }
        DAT_1008d2d0 = 0;
        if (((short)local_2c == sVar27) || (iVar10 == 1)) {
          uVar26 = iVar14 + uVar11 * -0x100;
        }
        else if (iVar10 == 2) {
          uVar26 = (int)(iVar14 + uVar11 * -0x100) >> 1;
        }
        else {
          uVar26 = (int)(iVar14 + uVar11 * -0x100) / iVar10;
        }
        local_38 = iVar10;
        if (uVar26 != 0) {
          DAT_1008d2d0 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
        }
      }
      else {
        local_38 = local_38 - iVar10;
        DAT_1008d290 = iVar10;
        DAT_1008d2c0 = iVar19;
        DAT_1008d2cc = iVar22;
        FUN_1007b07c();
        if (local_38 == 0) {
          return;
        }
        DAT_1008d284 = iVar24 << 0x10;
        iVar8 = iVar8 - iVar24;
        if (local_38 == 1) {
          DAT_1008d288 = iVar8 * 0x10000;
        }
        else if (local_38 == 2) {
          DAT_1008d288 = iVar8 * 0x8000;
        }
        else if (((local_38 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar15 + (iVar8 * 0x20 + local_38) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1008d288 = (iVar8 * 0x10000) / local_38;
        }
        else {
          DAT_1008d288 = (iVar8 * 0x10000) / local_38;
        }
      }
    }
  }
  DAT_1008d290 = local_38;
  FUN_1007b07c();
  return;
}


