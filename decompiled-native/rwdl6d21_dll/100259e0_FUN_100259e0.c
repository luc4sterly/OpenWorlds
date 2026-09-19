// 100259e0 FUN_100259e0 [Global]
// programa: RWDL6D21.DLL

void FUN_100259e0(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  short sVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  ushort uVar25;
  int iVar26;
  short sVar27;
  int local_3c;
  uint local_34;
  uint local_30;
  uint local_2c;
  short local_24;
  uint local_20;
  short local_14;
  uint local_10;
  ushort uVar4;
  
  iVar6 = param_3;
  iVar14 = param_4;
  iVar26 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar6 = param_2;
      iVar14 = param_3;
      iVar26 = param_4;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_10025a28;
  param_2 = iVar14;
  param_3 = iVar26;
  param_4 = iVar6;
LAB_10025a28:
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  local_3c = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar5 = *(uint *)(*param_1 + 8);
  uVar9 = (uVar5 & 0x7c0) >> 6;
  uVar10 = (uVar5 & 0xf800) >> 0xb;
  uVar22 = (uint)*(byte *)((*(int *)(param_2 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 + uVar9)
  ;
  uVar5 = uVar5 & 0x1f;
  local_34 = (uint)*(byte *)((*(int *)(param_2 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar10);
  uVar11 = local_34 << 0x10;
  iVar23 = (uVar22 | uVar11) << 8;
  uVar12 = (uint)*(byte *)((*(int *)(param_2 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar5)
  ;
  iVar14 = (int)*(short *)(param_3 + 0x1a);
  iVar13 = uVar12 * 0x100;
  local_2c = (uint)*(byte *)((*(int *)(param_3 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 +
                            uVar9);
  uVar2 = local_2c;
  local_34 = (uint)*(byte *)((*(int *)(param_3 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar10);
  uVar15 = local_34 << 0x10;
  iVar16 = (local_2c | uVar15) << 8;
  iVar26 = (int)*(short *)(param_4 + 0x1a);
  uVar17 = (uint)*(byte *)((*(int *)(param_3 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar5)
  ;
  iVar18 = uVar17 * 0x100;
  local_34 = (uint)*(byte *)((*(int *)(param_4 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 +
                            uVar9);
  bVar1 = *(byte *)((*(int *)(param_4 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar10);
  local_30 = (uint)bVar1;
  iVar19 = (local_34 | local_30 << 0x10) << 8;
  iVar20 = (uint)*(byte *)((*(int *)(param_4 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar5)
           * 0x100;
  iVar6 = DAT_10079214 + 0x1000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  sVar21 = (short)iVar23;
  sVar8 = (short)iVar13;
  uVar5 = iVar23 >> 0x10;
  uVar3 = (ushort)(uVar11 >> 8);
  local_24 = (short)iVar16;
  local_14 = (short)iVar19;
  local_2c._0_2_ = (short)iVar20;
  uVar9 = iVar19 >> 0x10;
  uVar10 = iVar16 >> 0x10;
  uVar25 = (ushort)(uVar15 >> 8);
  uVar4 = (ushort)((local_30 << 0x10) >> 8);
  sVar27 = (short)iVar18;
  if (local_3c < 1) {
    iVar13 = DAT_1007f280 - iVar14;
    if (iVar13 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    local_3c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_3c == 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    iVar19 = iVar26 - iVar14;
    if (local_3c == 1) {
      DAT_1007f28c = iVar19 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007f28c = iVar19 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar6 + (iVar19 * 0x20 + local_3c) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1007f28c = (iVar19 * 0x10000) / local_3c;
    }
    else {
      DAT_1007f28c = (iVar19 * 0x10000) / local_3c;
    }
    iVar26 = iVar26 - DAT_1007f280;
    if (local_3c == 1) {
      DAT_1007f288 = iVar26 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007f288 = iVar26 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar26)) && (iVar26 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar6 + (iVar26 * 0x20 + local_3c) * 4);
    }
    else if (iVar26 < 0) {
      DAT_1007f288 = (iVar26 * 0x10000) / local_3c;
    }
    else {
      DAT_1007f288 = (iVar26 * 0x10000) / local_3c;
    }
    if ((uVar25 == uVar3) || (iVar13 == 1)) {
      iVar6 = (uVar5 & 0xffff) - (uVar10 & 0xffff);
    }
    else if (iVar13 == 2) {
      iVar6 = (int)((uVar5 & 0xffff) - (uVar10 & 0xffff)) >> 1;
    }
    else {
      iVar6 = (int)((uVar5 & 0xffff) - (uVar10 & 0xffff)) / iVar13;
    }
    uVar10 = uVar10 & 0xffff;
    if ((uVar25 == uVar4) || (local_3c == 1)) {
      iVar26 = (uVar9 & 0xffff) - uVar10;
    }
    else if (local_3c == 2) {
      iVar26 = (int)((uVar9 & 0xffff) - uVar10) >> 1;
    }
    else {
      iVar26 = (int)((uVar9 & 0xffff) - uVar10) / local_3c;
    }
    DAT_1007f2c4 = iVar26 << 0x10;
    iVar26 = uVar22 * 0x100;
    if ((local_24 == sVar21) || (iVar13 == 1)) {
      uVar5 = iVar26 + uVar2 * -0x100;
    }
    else if (iVar13 == 2) {
      uVar5 = (int)(iVar26 + uVar2 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar26 + uVar2 * -0x100) / iVar13;
    }
    DAT_1007f2c8 = (iVar6 << 0x10 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    iVar6 = local_34 * 0x100;
    if ((local_14 == local_24) || (local_3c == 1)) {
      uVar5 = iVar6 + uVar2 * -0x100;
    }
    else if (local_3c == 2) {
      uVar5 = (int)(iVar6 + uVar2 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar6 + uVar2 * -0x100) / local_3c;
    }
    DAT_1007f2c4 = (DAT_1007f2c4 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    iVar6 = uVar12 * 0x100;
    if ((sVar27 == sVar8) || (iVar13 == 1)) {
      uVar5 = iVar6 + uVar17 * -0x100;
    }
    else if (iVar13 == 2) {
      uVar5 = (int)(iVar6 + uVar17 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar6 + uVar17 * -0x100) / iVar13;
    }
    DAT_1007f2d4 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    if (((short)local_2c == sVar27) || (local_3c == 1)) {
      uVar5 = iVar20 + uVar17 * -0x100;
    }
    else if (local_3c == 2) {
      uVar5 = (int)(iVar20 + uVar17 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar20 + uVar17 * -0x100) / local_3c;
    }
    DAT_1007f2d0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    DAT_1007f284 = DAT_1007f280 << 0x10;
    DAT_1007f280 = iVar14 << 0x10;
    DAT_1007f2c0 = iVar16;
    DAT_1007f2cc = iVar18;
  }
  else {
    iVar16 = iVar14 - DAT_1007f280;
    if (local_3c == 1) {
      DAT_1007f28c = iVar16 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1007f28c = iVar16 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar6 + (iVar16 * 0x20 + local_3c) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1007f28c = (iVar16 * 0x10000) / local_3c;
    }
    else {
      DAT_1007f28c = (iVar16 * 0x10000) / local_3c;
    }
    iVar16 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (iVar16 < 1) {
      iVar16 = iVar26 - DAT_1007f280;
      if (iVar16 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar14 = iVar14 - iVar26;
      if (local_3c == 1) {
        DAT_1007f288 = iVar14 * 0x10000;
      }
      else if (local_3c == 2) {
        DAT_1007f288 = iVar14 * 0x8000;
      }
      else if (((local_3c < 0x20) && (-0x20 < iVar14)) && (iVar14 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar6 + (iVar14 * 0x20 + local_3c) * 4);
      }
      else if (iVar14 < 0) {
        DAT_1007f288 = (iVar14 * 0x10000) / local_3c;
      }
      else {
        DAT_1007f288 = (iVar14 * 0x10000) / local_3c;
      }
      if ((uVar3 == uVar4) || (iVar16 == 1)) {
        iVar6 = (uVar9 & 0xffff) - (uint)uVar3;
      }
      else if (iVar16 == 2) {
        iVar6 = (int)((uVar9 & 0xffff) - (uint)uVar3) >> 1;
      }
      else {
        iVar6 = (int)((uVar9 & 0xffff) - (uint)uVar3) / iVar16;
      }
      uVar5 = (uint)uVar3;
      iVar14 = local_34 * 0x100;
      if ((local_14 == sVar21) || (iVar16 == 1)) {
        uVar9 = iVar14 + uVar22 * -0x100;
      }
      else if (iVar16 == 2) {
        uVar9 = (int)(iVar14 + uVar22 * -0x100) >> 1;
      }
      else {
        uVar9 = (int)(iVar14 + uVar22 * -0x100) / iVar16;
      }
      DAT_1007f2c8 = (iVar6 << 0x10 | uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      if ((uVar25 == uVar3) || (local_3c == 1)) {
        iVar6 = (uVar10 & 0xffff) - uVar5;
      }
      else if (local_3c == 2) {
        iVar6 = (int)((uVar10 & 0xffff) - uVar5) >> 1;
      }
      else {
        iVar6 = (int)((uVar10 & 0xffff) - uVar5) / local_3c;
      }
      iVar14 = uVar2 * 0x100;
      if ((local_24 == sVar21) || (local_3c == 1)) {
        uVar5 = iVar14 + uVar22 * -0x100;
      }
      else if (local_3c == 2) {
        uVar5 = (int)(iVar14 + uVar22 * -0x100) >> 1;
      }
      else {
        uVar5 = (int)(iVar14 + uVar22 * -0x100) / local_3c;
      }
      DAT_1007f2c4 = (iVar6 << 0x10 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      if (((short)local_2c == sVar8) || (iVar16 == 1)) {
        uVar5 = iVar20 + uVar12 * -0x100;
      }
      else if (iVar16 == 2) {
        uVar5 = (int)(iVar20 + uVar12 * -0x100) >> 1;
      }
      else {
        uVar5 = (int)(iVar20 + uVar12 * -0x100) / iVar16;
      }
      DAT_1007f2d4 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      if ((sVar27 == sVar8) || (local_3c == 1)) {
        uVar5 = iVar18 + uVar12 * -0x100;
      }
      else if (local_3c == 2) {
        uVar5 = (int)(iVar18 + uVar12 * -0x100) >> 1;
      }
      else {
        uVar5 = (int)(iVar18 + uVar12 * -0x100) / local_3c;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f2d0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      DAT_1007f284 = iVar26 << 0x10;
      DAT_1007f2c0 = iVar23;
      DAT_1007f2cc = iVar13;
    }
    else {
      iVar19 = iVar26 - DAT_1007f280;
      if (iVar16 == 1) {
        DAT_1007f288 = iVar19 * 0x10000;
      }
      else if (iVar16 == 2) {
        DAT_1007f288 = iVar19 * 0x8000;
      }
      else if (((iVar16 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar6 + (iVar19 * 0x20 + iVar16) * 4);
      }
      else if (iVar19 < 0) {
        DAT_1007f288 = (iVar19 * 0x10000) / iVar16;
      }
      else {
        DAT_1007f288 = (iVar19 * 0x10000) / iVar16;
      }
      iVar19 = DAT_1007f288 - DAT_1007f28c;
      if (iVar19 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      local_30 = (uint)CONCAT12(bVar1,uVar25);
      if ((uVar25 == uVar3) || (local_3c == 1)) {
        iVar7 = (local_30 & 0xffff) - (uVar5 & 0xffff);
      }
      else if (local_3c == 2) {
        iVar7 = (int)((local_30 & 0xffff) - (uVar5 & 0xffff)) >> 1;
      }
      else {
        iVar7 = (int)((local_30 & 0xffff) - (uVar5 & 0xffff)) / local_3c;
      }
      local_20 = local_30 & 0xffff;
      uVar5 = uVar5 & 0xffff;
      if ((local_24 == sVar21) || (local_3c == 1)) {
        uVar9 = uVar2 * 0x100 + uVar22 * -0x100;
      }
      else if (local_3c == 2) {
        uVar9 = (int)(uVar2 * 0x100 + uVar22 * -0x100) >> 1;
      }
      else {
        uVar9 = (int)(uVar2 * 0x100 + uVar22 * -0x100) / local_3c;
      }
      DAT_1007f2c4 = (iVar7 << 0x10 | uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      local_10 = (uint)uVar4;
      if ((uVar3 == uVar4) || (iVar16 == 1)) {
        iVar7 = local_10 - uVar5;
      }
      else if (iVar16 == 2) {
        iVar7 = (int)(local_10 - uVar5) >> 1;
      }
      else {
        iVar7 = (int)(local_10 - uVar5) / iVar16;
      }
      DAT_1007f2c8 = iVar7 - (DAT_1007f2c4 >> 0x10);
      if (DAT_1007f2c8 != 0) {
        DAT_1007f2c8 = (int)(DAT_1007f2c8 * 0x10000) / iVar19 << 0x10;
      }
      if ((local_14 == sVar21) || (iVar16 == 1)) {
        iVar7 = local_34 * 0x100 + uVar22 * -0x100;
      }
      else if (iVar16 == 2) {
        iVar7 = (int)(local_34 * 0x100 + uVar22 * -0x100) >> 1;
      }
      else {
        iVar7 = (int)(local_34 * 0x100 + uVar22 * -0x100) / iVar16;
      }
      iVar24 = local_34 * 0x100;
      if (iVar7 - (short)DAT_1007f2c4 != 0) {
        uVar5 = DAT_1007f2c8 | ((iVar7 - (short)DAT_1007f2c4) * 0x10000) / iVar19 & 0xffffU;
        DAT_1007f2c8 = uVar5 + (uVar5 & 0x8000) * -2;
      }
      if ((sVar27 == sVar8) || (local_3c == 1)) {
        uVar5 = iVar18 + uVar12 * -0x100;
      }
      else if (local_3c == 2) {
        uVar5 = (int)(iVar18 + uVar12 * -0x100) >> 1;
      }
      else {
        uVar5 = (int)(iVar18 + uVar12 * -0x100) / local_3c;
      }
      DAT_1007f2d4 = 0;
      DAT_1007f2d0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      if (((short)local_2c == sVar8) || (iVar16 == 1)) {
        iVar18 = iVar20 + uVar12 * -0x100;
      }
      else if (iVar16 == 2) {
        iVar18 = (int)(iVar20 + uVar12 * -0x100) >> 1;
      }
      else {
        iVar18 = (int)(iVar20 + uVar12 * -0x100) / iVar16;
      }
      if (iVar18 - (short)DAT_1007f2d0 != 0) {
        uVar5 = ((iVar18 - (short)DAT_1007f2d0) * 0x10000) / iVar19;
        DAT_1007f2d4 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (local_3c < iVar16) {
        iVar16 = iVar16 - local_3c;
        DAT_1007f290 = local_3c;
        DAT_1007f2c0 = iVar23;
        DAT_1007f2cc = iVar13;
        FUN_1006a340();
        DAT_1007f280 = iVar14 << 0x10;
        iVar26 = iVar26 - iVar14;
        if (iVar16 == 1) {
          DAT_1007f28c = iVar26 * 0x10000;
        }
        else if (iVar16 == 2) {
          DAT_1007f28c = iVar26 * 0x8000;
        }
        else if (((iVar16 < 0x20) && (-0x20 < iVar26)) && (iVar26 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar6 + (iVar26 * 0x20 + iVar16) * 4);
        }
        else if (iVar26 < 0) {
          DAT_1007f28c = (iVar26 * 0x10000) / iVar16;
        }
        else {
          DAT_1007f28c = (iVar26 * 0x10000) / iVar16;
        }
        if ((uVar25 == uVar4) || (iVar16 == 1)) {
          DAT_1007f2c4 = local_10 - local_20;
        }
        else if (iVar16 == 2) {
          DAT_1007f2c4 = (int)(local_10 - local_20) >> 1;
        }
        else {
          DAT_1007f2c4 = (int)(local_10 - local_20) / iVar16;
        }
        DAT_1007f2c4 = DAT_1007f2c4 << 0x10;
        if ((local_14 == local_24) || (iVar16 == 1)) {
          uVar5 = iVar24 + uVar2 * -0x100;
        }
        else if (iVar16 == 2) {
          uVar5 = (int)(iVar24 + uVar2 * -0x100) >> 1;
        }
        else {
          uVar5 = (int)(iVar24 + uVar2 * -0x100) / iVar16;
        }
        if (uVar5 != 0) {
          DAT_1007f2c4 = (DAT_1007f2c4 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
        }
        DAT_1007f2d0 = 0;
        if (((short)local_2c == sVar27) || (iVar16 == 1)) {
          uVar5 = iVar20 + uVar17 * -0x100;
        }
        else if (iVar16 == 2) {
          uVar5 = (int)(iVar20 + uVar17 * -0x100) >> 1;
        }
        else {
          uVar5 = (int)(iVar20 + uVar17 * -0x100) / iVar16;
        }
        local_3c = iVar16;
        if (uVar5 != 0) {
          DAT_1007f2d0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
        }
      }
      else {
        local_3c = local_3c - iVar16;
        DAT_1007f290 = iVar16;
        DAT_1007f2c0 = iVar23;
        DAT_1007f2cc = iVar13;
        FUN_1006a340();
        if (local_3c == 0) {
          return;
        }
        DAT_1007f284 = iVar26 << 0x10;
        iVar14 = iVar14 - iVar26;
        if (local_3c == 1) {
          DAT_1007f288 = iVar14 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1007f288 = iVar14 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar14)) && (iVar14 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar6 + (iVar14 * 0x20 + local_3c) * 4);
        }
        else if (iVar14 < 0) {
          DAT_1007f288 = (iVar14 * 0x10000) / local_3c;
        }
        else {
          DAT_1007f288 = (iVar14 * 0x10000) / local_3c;
        }
      }
    }
  }
  DAT_1007f290 = local_3c;
  FUN_1006a340();
  return;
}


