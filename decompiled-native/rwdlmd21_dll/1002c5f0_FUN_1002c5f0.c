// 1002c5f0 FUN_1002c5f0 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002c5f0(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  short sVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  int iVar29;
  int local_44;
  short local_3c;
  uint local_34;
  uint local_30;
  uint local_2c;
  short local_28;
  short local_24;
  uint local_1c;
  short local_14;
  ushort uVar4;
  
  iVar9 = param_4;
  iVar7 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    iVar8 = param_3;
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar8 = param_2;
      iVar9 = param_3;
      iVar7 = param_4;
    }
LAB_1002c637:
    param_4 = iVar8;
    param_2 = iVar9;
    param_3 = iVar7;
  }
  else {
    iVar8 = param_3;
    if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1002c637;
  }
  DAT_1008d284 = (int)*(short *)(param_2 + 0x1e);
  iVar11 = *(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar28 = *(uint *)(*param_1 + 8);
  uVar12 = (uVar28 & 0x7c0) >> 6;
  uVar13 = (uVar28 & 0xf800) >> 0xb;
  local_34 = (uint)*(byte *)((*(int *)(param_2 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 +
                            uVar12);
  uVar26 = local_34;
  local_30 = (uint)*(byte *)((*(int *)(param_2 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar13);
  uVar14 = local_30 << 0x10;
  uVar28 = uVar28 & 0x1f;
  iVar15 = (local_34 | uVar14) << 8;
  uVar16 = (uint)*(byte *)((*(int *)(param_2 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar28
                          );
  iVar17 = uVar16 * 0x100;
  iVar9 = *(int *)(param_2 + 0x20);
  iVar19 = (int)*(short *)(param_3 + 0x1a);
  uVar20 = (uint)*(byte *)((*(int *)(param_3 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar13) <<
           0x10;
  local_30 = (uint)*(byte *)((*(int *)(param_3 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 +
                            uVar12);
  uVar2 = local_30;
  iVar21 = (uVar20 | local_30) << 8;
  iVar27 = (int)*(short *)(param_4 + 0x1a);
  uVar22 = (uint)*(byte *)((*(int *)(param_3 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar28
                          );
  iVar23 = uVar22 * 0x100;
  iVar8 = *(int *)(param_3 + 0x20);
  local_2c = (uint)*(byte *)((*(int *)(param_4 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 +
                            uVar12);
  bVar1 = *(byte *)((*(int *)(param_4 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar13);
  local_30 = (uint)bVar1;
  iVar24 = (local_2c | local_30 << 0x10) << 8;
  iVar7 = *(int *)(param_4 + 0x20);
  iVar25 = (uint)*(byte *)((*(int *)(param_4 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar28
                          ) * 0x100;
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar5 = DAT_1008723c + 0x1000;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  local_3c = (short)iVar15;
  local_24 = (short)iVar21;
  local_14 = (short)iVar24;
  local_28 = (short)iVar25;
  local_34._0_2_ = (short)iVar17;
  uVar28 = iVar24 >> 0x10;
  uVar12 = iVar21 >> 0x10;
  uVar13 = iVar15 >> 0x10;
  uVar3 = (ushort)(uVar14 >> 8);
  uVar10 = (ushort)(uVar20 >> 8);
  uVar4 = (ushort)((local_30 << 0x10) >> 8);
  sVar18 = (short)iVar23;
  if (iVar11 < 1) {
    iVar11 = DAT_1008d280 - iVar19;
    if (iVar11 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    local_44 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_44 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar15 = iVar27 - iVar19;
    if (local_44 == 1) {
      DAT_1008d28c = iVar15 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1008d28c = iVar15 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar5 + (iVar15 * 0x20 + local_44) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1008d28c = (iVar15 * 0x10000) / local_44;
    }
    else {
      DAT_1008d28c = (iVar15 * 0x10000) / local_44;
    }
    iVar27 = iVar27 - DAT_1008d280;
    if (local_44 == 1) {
      DAT_1008d288 = iVar27 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1008d288 = iVar27 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar27)) && (iVar27 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar5 + (iVar27 * 0x20 + local_44) * 4);
    }
    else if (iVar27 < 0) {
      DAT_1008d288 = (iVar27 * 0x10000) / local_44;
    }
    else {
      DAT_1008d288 = (iVar27 * 0x10000) / local_44;
    }
    if ((iVar8 == iVar9) || (iVar11 == 1)) {
      DAT_1008d2ec = iVar9 - iVar8;
    }
    else if (iVar11 == 2) {
      DAT_1008d2ec = iVar9 - iVar8 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar9 - iVar8) / iVar11;
    }
    if ((iVar8 == iVar7) || (local_44 == 1)) {
      DAT_1008d2e8 = iVar7 - iVar8;
    }
    else if (local_44 == 2) {
      DAT_1008d2e8 = iVar7 - iVar8 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar7 - iVar8) / local_44;
    }
    if ((uVar3 == uVar10) || (iVar11 == 1)) {
      iVar9 = (uVar13 & 0xffff) - (uVar12 & 0xffff);
    }
    else if (iVar11 == 2) {
      iVar9 = (int)((uVar13 & 0xffff) - (uVar12 & 0xffff)) >> 1;
    }
    else {
      iVar9 = (int)((uVar13 & 0xffff) - (uVar12 & 0xffff)) / iVar11;
    }
    uVar12 = uVar12 & 0xffff;
    if ((uVar4 == uVar10) || (local_44 == 1)) {
      iVar7 = (uVar28 & 0xffff) - uVar12;
    }
    else if (local_44 == 2) {
      iVar7 = (int)((uVar28 & 0xffff) - uVar12) >> 1;
    }
    else {
      iVar7 = (int)((uVar28 & 0xffff) - uVar12) / local_44;
    }
    DAT_1008d2c4 = iVar7 << 0x10;
    iVar7 = uVar26 * 0x100;
    if ((local_24 == local_3c) || (iVar11 == 1)) {
      uVar28 = iVar7 + uVar2 * -0x100;
    }
    else if (iVar11 == 2) {
      uVar28 = (int)(iVar7 + uVar2 * -0x100) >> 1;
    }
    else {
      uVar28 = (int)(iVar7 + uVar2 * -0x100) / iVar11;
    }
    DAT_1008d2c8 = (iVar9 << 0x10 | uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
    iVar9 = local_2c * 0x100;
    if ((local_14 == local_24) || (local_44 == 1)) {
      uVar28 = iVar9 + uVar2 * -0x100;
    }
    else if (local_44 == 2) {
      uVar28 = (int)(iVar9 + uVar2 * -0x100) >> 1;
    }
    else {
      uVar28 = (int)(iVar9 + uVar2 * -0x100) / local_44;
    }
    DAT_1008d2c4 = (DAT_1008d2c4 | uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
    if ((sVar18 == (short)local_34) || (iVar11 == 1)) {
      uVar28 = iVar17 + uVar22 * -0x100;
    }
    else if (iVar11 == 2) {
      uVar28 = (int)(iVar17 + uVar22 * -0x100) >> 1;
    }
    else {
      uVar28 = (int)(iVar17 + uVar22 * -0x100) / iVar11;
    }
    DAT_1008d2d4 = (uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
    if ((local_28 == sVar18) || (local_44 == 1)) {
      uVar28 = iVar25 + uVar22 * -0x100;
    }
    else if (local_44 == 2) {
      uVar28 = (int)(iVar25 + uVar22 * -0x100) >> 1;
    }
    else {
      uVar28 = (int)(iVar25 + uVar22 * -0x100) / local_44;
    }
    DAT_1008d2d0 = (uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
    DAT_1008d2c0 = iVar21;
    DAT_1008d2cc = iVar23;
  }
  else {
    iVar21 = iVar19 - DAT_1008d280;
    if (iVar11 == 1) {
      DAT_1008d28c = iVar21 * 0x10000;
    }
    else if (iVar11 == 2) {
      DAT_1008d28c = iVar21 * 0x8000;
    }
    else if (((iVar11 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar5 + (iVar21 * 0x20 + iVar11) * 4);
    }
    else if (iVar21 < 0) {
      DAT_1008d28c = (iVar21 * 0x10000) / iVar11;
    }
    else {
      DAT_1008d28c = (iVar21 * 0x10000) / iVar11;
    }
    iVar21 = *(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (0 < iVar21) {
      iVar24 = iVar27 - DAT_1008d280;
      if (iVar21 == 1) {
        DAT_1008d288 = iVar24 * 0x10000;
      }
      else if (iVar21 == 2) {
        DAT_1008d288 = iVar24 * 0x8000;
      }
      else if (((iVar21 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar5 + (iVar24 * 0x20 + iVar21) * 4);
      }
      else if (iVar24 < 0) {
        DAT_1008d288 = (iVar24 * 0x10000) / iVar21;
      }
      else {
        DAT_1008d288 = (iVar24 * 0x10000) / iVar21;
      }
      iVar24 = DAT_1008d288 - DAT_1008d28c;
      if (iVar24 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d2a0 = DAT_10089ef4;
        return;
      }
      if ((uVar3 == uVar10) || (iVar11 == 1)) {
        iVar6 = (uint)uVar10 - (uVar13 & 0xffff);
      }
      else if (iVar11 == 2) {
        iVar6 = (int)((uint)uVar10 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        iVar6 = (int)((uint)uVar10 - (uVar13 & 0xffff)) / iVar11;
      }
      local_1c = (uint)uVar10;
      uVar13 = uVar13 & 0xffff;
      if ((local_24 == local_3c) || (iVar11 == 1)) {
        uVar28 = uVar2 * 0x100 + uVar26 * -0x100;
      }
      else if (iVar11 == 2) {
        uVar28 = (int)(uVar2 * 0x100 + uVar26 * -0x100) >> 1;
      }
      else {
        uVar28 = (int)(uVar2 * 0x100 + uVar26 * -0x100) / iVar11;
      }
      DAT_1008d2c4 = (iVar6 << 0x10 | uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
      local_30 = (uint)CONCAT12(bVar1,uVar4);
      if ((uVar3 == uVar4) || (iVar21 == 1)) {
        iVar6 = (local_30 & 0xffff) - uVar13;
      }
      else if (iVar21 == 2) {
        iVar6 = (int)((local_30 & 0xffff) - uVar13) >> 1;
      }
      else {
        iVar6 = (int)((local_30 & 0xffff) - uVar13) / iVar21;
      }
      uVar28 = (uint)uVar4;
      DAT_1008d2c8 = iVar6 - (DAT_1008d2c4 >> 0x10);
      if (DAT_1008d2c8 != 0) {
        DAT_1008d2c8 = (int)(DAT_1008d2c8 * 0x10000) / iVar24 << 0x10;
      }
      if ((local_14 == local_3c) || (iVar21 == 1)) {
        iVar6 = local_2c * 0x100 + uVar26 * -0x100;
      }
      else if (iVar21 == 2) {
        iVar6 = (int)(local_2c * 0x100 + uVar26 * -0x100) >> 1;
      }
      else {
        iVar6 = (int)(local_2c * 0x100 + uVar26 * -0x100) / iVar21;
      }
      iVar29 = local_2c * 0x100;
      if (iVar6 - (short)DAT_1008d2c4 != 0) {
        uVar26 = DAT_1008d2c8 | ((iVar6 - (short)DAT_1008d2c4) * 0x10000) / iVar24 & 0xffffU;
        DAT_1008d2c8 = uVar26 + (uVar26 & 0x8000) * -2;
      }
      if ((sVar18 == (short)local_34) || (iVar11 == 1)) {
        uVar26 = iVar23 + uVar16 * -0x100;
      }
      else if (iVar11 == 2) {
        uVar26 = (int)(iVar23 + uVar16 * -0x100) >> 1;
      }
      else {
        uVar26 = (int)(iVar23 + uVar16 * -0x100) / iVar11;
      }
      DAT_1008d2d4 = 0;
      DAT_1008d2d0 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
      if ((local_28 == (short)local_34) || (iVar21 == 1)) {
        iVar23 = iVar25 + uVar16 * -0x100;
      }
      else if (iVar21 == 2) {
        iVar23 = (int)(iVar25 + uVar16 * -0x100) >> 1;
      }
      else {
        iVar23 = (int)(iVar25 + uVar16 * -0x100) / iVar21;
      }
      if (iVar23 - (short)DAT_1008d2d0 != 0) {
        uVar26 = ((iVar23 - (short)DAT_1008d2d0) * 0x10000) / iVar24;
        DAT_1008d2d4 = (uVar26 & 0xffff) + (uVar26 & 0x8000) * -2;
      }
      if ((iVar8 == iVar9) || (iVar11 == 1)) {
        DAT_1008d2e8 = iVar8 - iVar9;
      }
      else if (iVar11 == 2) {
        DAT_1008d2e8 = iVar8 - iVar9 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar8 - iVar9) / iVar11;
      }
      if ((iVar9 == iVar7) || (iVar21 == 1)) {
        iVar23 = iVar7 - iVar9;
      }
      else if (iVar21 == 2) {
        iVar23 = iVar7 - iVar9 >> 1;
      }
      else {
        iVar23 = (iVar7 - iVar9) / iVar21;
      }
      DAT_1008d2ec = iVar23 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && (iVar24 >> 6 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / (iVar24 >> 6) << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar11 < iVar21) {
        local_44 = iVar21 - iVar11;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar9;
        DAT_1008d290 = iVar11;
        DAT_1008d2c0 = iVar15;
        DAT_1008d2cc = iVar17;
        FUN_1007aad8();
        DAT_1008d280 = iVar19 << 0x10;
        iVar27 = iVar27 - iVar19;
        if (local_44 == 1) {
          DAT_1008d28c = iVar27 * 0x10000;
        }
        else if (local_44 == 2) {
          DAT_1008d28c = iVar27 * 0x8000;
        }
        else if (((local_44 < 0x20) && (-0x20 < iVar27)) && (iVar27 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar5 + (iVar27 * 0x20 + local_44) * 4);
        }
        else if (iVar27 < 0) {
          DAT_1008d28c = (iVar27 * 0x10000) / local_44;
        }
        else {
          DAT_1008d28c = (iVar27 * 0x10000) / local_44;
        }
        if ((uVar4 == uVar10) || (local_44 == 1)) {
          DAT_1008d2c4 = uVar28 - local_1c;
        }
        else if (local_44 == 2) {
          DAT_1008d2c4 = (int)(uVar28 - local_1c) >> 1;
        }
        else {
          DAT_1008d2c4 = (int)(uVar28 - local_1c) / local_44;
        }
        DAT_1008d2c4 = DAT_1008d2c4 << 0x10;
        if ((local_14 == local_24) || (local_44 == 1)) {
          uVar28 = iVar29 + uVar2 * -0x100;
        }
        else if (local_44 == 2) {
          uVar28 = (int)(iVar29 + uVar2 * -0x100) >> 1;
        }
        else {
          uVar28 = (int)(iVar29 + uVar2 * -0x100) / local_44;
        }
        if (uVar28 != 0) {
          DAT_1008d2c4 = (DAT_1008d2c4 | uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
        }
        DAT_1008d2d0 = 0;
        if ((local_28 == sVar18) || (local_44 == 1)) {
          uVar28 = iVar25 + uVar22 * -0x100;
        }
        else if (local_44 == 2) {
          uVar28 = (int)(iVar25 + uVar22 * -0x100) >> 1;
        }
        else {
          uVar28 = (int)(iVar25 + uVar22 * -0x100) / local_44;
        }
        if (uVar28 != 0) {
          DAT_1008d2d0 = (uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
        }
        if (iVar8 == iVar7) {
          DAT_1008d2e8 = iVar7 - iVar8;
        }
        else if (local_44 == 1) {
          DAT_1008d2e8 = iVar7 - iVar8;
        }
        else if (local_44 == 2) {
          DAT_1008d2e8 = iVar7 - iVar8 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar7 - iVar8) / local_44;
        }
      }
      else {
        local_44 = iVar11 - iVar21;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar9;
        DAT_1008d290 = iVar21;
        DAT_1008d2c0 = iVar15;
        DAT_1008d2cc = iVar17;
        FUN_1007aad8();
        if (local_44 == 0) {
          return;
        }
        DAT_1008d284 = iVar27 << 0x10;
        iVar19 = iVar19 - iVar27;
        if (local_44 == 1) {
          DAT_1008d288 = iVar19 * 0x10000;
        }
        else if (local_44 == 2) {
          DAT_1008d288 = iVar19 * 0x8000;
        }
        else if (((local_44 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar5 + (iVar19 * 0x20 + local_44) * 4);
        }
        else if (iVar19 < 0) {
          DAT_1008d288 = (iVar19 * 0x10000) / local_44;
        }
        else {
          DAT_1008d288 = (iVar19 * 0x10000) / local_44;
        }
      }
      goto LAB_1002d8cf;
    }
    iVar21 = iVar27 - DAT_1008d280;
    if (iVar21 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar19 = iVar19 - iVar27;
    if (iVar11 == 1) {
      DAT_1008d288 = iVar19 * 0x10000;
    }
    else if (iVar11 == 2) {
      DAT_1008d288 = iVar19 * 0x8000;
    }
    else if (((iVar11 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar5 + (iVar19 * 0x20 + iVar11) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1008d288 = (iVar19 * 0x10000) / iVar11;
    }
    else {
      DAT_1008d288 = (iVar19 * 0x10000) / iVar11;
    }
    if ((iVar9 == iVar7) || (iVar21 == 1)) {
      DAT_1008d2ec = iVar7 - iVar9;
    }
    else if (iVar21 == 2) {
      DAT_1008d2ec = iVar7 - iVar9 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar7 - iVar9) / iVar21;
    }
    if ((iVar8 == iVar9) || (iVar11 == 1)) {
      DAT_1008d2e8 = iVar8 - iVar9;
    }
    else if (iVar11 == 2) {
      DAT_1008d2e8 = iVar8 - iVar9 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar8 - iVar9) / iVar11;
    }
    if ((uVar3 == uVar4) || (iVar21 == 1)) {
      iVar7 = (uVar28 & 0xffff) - (uVar13 & 0xffff);
    }
    else if (iVar21 == 2) {
      iVar7 = (int)((uVar28 & 0xffff) - (uVar13 & 0xffff)) >> 1;
    }
    else {
      iVar7 = (int)((uVar28 & 0xffff) - (uVar13 & 0xffff)) / iVar21;
    }
    uVar13 = uVar13 & 0xffff;
    iVar8 = local_2c * 0x100;
    if ((local_14 == local_3c) || (iVar21 == 1)) {
      uVar28 = iVar8 + uVar26 * -0x100;
    }
    else if (iVar21 == 2) {
      uVar28 = (int)(iVar8 + uVar26 * -0x100) >> 1;
    }
    else {
      uVar28 = (int)(iVar8 + uVar26 * -0x100) / iVar21;
    }
    DAT_1008d2c8 = (iVar7 << 0x10 | uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
    if ((uVar3 == uVar10) || (iVar11 == 1)) {
      iVar7 = (uVar12 & 0xffff) - uVar13;
    }
    else if (iVar11 == 2) {
      iVar7 = (int)((uVar12 & 0xffff) - uVar13) >> 1;
    }
    else {
      iVar7 = (int)((uVar12 & 0xffff) - uVar13) / iVar11;
    }
    iVar8 = uVar2 * 0x100;
    if ((local_24 == local_3c) || (iVar11 == 1)) {
      uVar28 = iVar8 + uVar26 * -0x100;
    }
    else if (iVar11 == 2) {
      uVar28 = (int)(iVar8 + uVar26 * -0x100) >> 1;
    }
    else {
      uVar28 = (int)(iVar8 + uVar26 * -0x100) / iVar11;
    }
    DAT_1008d2c4 = (iVar7 << 0x10 | uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
    if ((local_28 == (short)local_34) || (iVar21 == 1)) {
      uVar28 = iVar25 + uVar16 * -0x100;
    }
    else if (iVar21 == 2) {
      uVar28 = (int)(iVar25 + uVar16 * -0x100) >> 1;
    }
    else {
      uVar28 = (int)(iVar25 + uVar16 * -0x100) / iVar21;
    }
    DAT_1008d2d4 = (uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
    if ((sVar18 == (short)local_34) || (iVar11 == 1)) {
      uVar28 = iVar23 + uVar16 * -0x100;
    }
    else if (iVar11 == 2) {
      uVar28 = (int)(iVar23 + uVar16 * -0x100) >> 1;
    }
    else {
      uVar28 = (int)(iVar23 + uVar16 * -0x100) / iVar11;
    }
    DAT_1008d2d0 = (uVar28 & 0xffff) + (uVar28 & 0x8000) * -2;
    DAT_1008d2c0 = iVar15;
    DAT_1008d2cc = iVar17;
    local_44 = iVar11;
    iVar8 = iVar9;
    iVar19 = DAT_1008d280;
    DAT_1008d280 = iVar27;
  }
  DAT_1008d284 = DAT_1008d280 << 0x10;
  DAT_1008d280 = iVar19 << 0x10;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar8;
LAB_1002d8cf:
  DAT_1008d290 = local_44;
  FUN_1007aad8();
  return;
}


