// 1002a1e0 FUN_1002a1e0 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002a1e0(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  short sVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  uint uVar29;
  ushort uVar30;
  int local_44;
  short local_3c;
  uint local_34;
  short local_30;
  short local_2c;
  short local_28;
  uint local_20;
  short local_18;
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
LAB_1002a227:
    param_4 = iVar8;
    param_2 = iVar9;
    param_3 = iVar7;
  }
  else {
    iVar8 = param_3;
    if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1002a227;
  }
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  iVar10 = (int)*(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar29 = *(uint *)(*param_1 + 8);
  uVar11 = (uVar29 & 0xf800) >> 0xb;
  uVar12 = (uVar29 & 0x7c0) >> 6;
  uVar25 = (uint)*(byte *)((*(int *)(param_2 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 + uVar12
                          );
  local_34 = (uint)*(byte *)((*(int *)(param_2 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar11);
  uVar13 = local_34 << 0x10;
  uVar29 = uVar29 & 0x1f;
  iVar26 = (uVar25 | uVar13) << 8;
  uVar14 = (uint)*(byte *)((*(int *)(param_2 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar29
                          );
  iVar15 = uVar14 * 0x100;
  iVar9 = *(int *)(param_2 + 0x20);
  iVar17 = (int)*(short *)(param_3 + 0x1a);
  uVar18 = (uint)*(byte *)((*(int *)(param_3 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar11) <<
           0x10;
  local_34 = (uint)*(byte *)((*(int *)(param_3 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 +
                            uVar12);
  uVar2 = local_34;
  iVar19 = (uVar18 | local_34) << 8;
  iVar8 = *(int *)(param_3 + 0x20);
  uVar20 = (uint)*(byte *)((*(int *)(param_3 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar29
                          );
  iVar27 = (int)*(short *)(param_4 + 0x1a);
  iVar21 = uVar20 * 0x100;
  uVar22 = (uint)*(byte *)((*(int *)(param_4 + 0x5c) >> 0x10) * 0x20 + DAT_10087248 + 0x400 + uVar12
                          );
  bVar1 = *(byte *)((*(int *)(param_4 + 0x58) >> 0x10) * 0x20 + DAT_10087248 + uVar11);
  local_34 = (uint)bVar1;
  iVar23 = (uVar22 | local_34 << 0x10) << 8;
  iVar7 = *(int *)(param_4 + 0x20);
  iVar24 = (uint)*(byte *)((*(int *)(param_4 + 0x60) >> 0x10) * 0x20 + DAT_10087248 + 0x800 + uVar29
                          ) * 0x100;
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  iVar5 = DAT_1008723c + 0x1000;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  local_3c = (short)iVar26;
  local_28 = (short)iVar19;
  local_18 = (short)iVar23;
  local_2c = (short)iVar24;
  local_30 = (short)iVar15;
  uVar29 = iVar23 >> 0x10;
  uVar11 = iVar19 >> 0x10;
  uVar12 = iVar26 >> 0x10;
  uVar3 = (ushort)(uVar13 >> 8);
  uVar30 = (ushort)(uVar18 >> 8);
  uVar4 = (ushort)((local_34 << 0x10) >> 8);
  sVar16 = (short)iVar21;
  if (iVar10 < 1) {
    iVar10 = DAT_1008d280 - iVar17;
    if (iVar10 < 1) {
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
    iVar23 = iVar27 - iVar17;
    if (local_44 == 1) {
      DAT_1008d28c = iVar23 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1008d28c = iVar23 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar23)) && (iVar23 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar5 + (iVar23 * 0x20 + local_44) * 4);
    }
    else if (iVar23 < 0) {
      DAT_1008d28c = (iVar23 * 0x10000) / local_44;
    }
    else {
      DAT_1008d28c = (iVar23 * 0x10000) / local_44;
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
    if ((iVar8 == iVar9) || (iVar10 == 1)) {
      DAT_1008d2ec = iVar9 - iVar8;
    }
    else if (iVar10 == 2) {
      DAT_1008d2ec = iVar9 - iVar8 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar9 - iVar8) / iVar10;
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
    if ((uVar3 == uVar30) || (iVar10 == 1)) {
      iVar9 = (uVar12 & 0xffff) - (uVar11 & 0xffff);
    }
    else if (iVar10 == 2) {
      iVar9 = (int)((uVar12 & 0xffff) - (uVar11 & 0xffff)) >> 1;
    }
    else {
      iVar9 = (int)((uVar12 & 0xffff) - (uVar11 & 0xffff)) / iVar10;
    }
    uVar11 = uVar11 & 0xffff;
    if ((uVar4 == uVar30) || (local_44 == 1)) {
      iVar7 = (uVar29 & 0xffff) - uVar11;
    }
    else if (local_44 == 2) {
      iVar7 = (int)((uVar29 & 0xffff) - uVar11) >> 1;
    }
    else {
      iVar7 = (int)((uVar29 & 0xffff) - uVar11) / local_44;
    }
    DAT_1008d2c4 = iVar7 << 0x10;
    iVar7 = uVar25 * 0x100;
    if ((local_28 == local_3c) || (iVar10 == 1)) {
      uVar29 = iVar7 + uVar2 * -0x100;
    }
    else if (iVar10 == 2) {
      uVar29 = (int)(iVar7 + uVar2 * -0x100) >> 1;
    }
    else {
      uVar29 = (int)(iVar7 + uVar2 * -0x100) / iVar10;
    }
    DAT_1008d2c8 = (iVar9 << 0x10 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    iVar9 = uVar22 * 0x100;
    if ((local_18 == local_28) || (local_44 == 1)) {
      uVar29 = iVar9 + uVar2 * -0x100;
    }
    else if (local_44 == 2) {
      uVar29 = (int)(iVar9 + uVar2 * -0x100) >> 1;
    }
    else {
      uVar29 = (int)(iVar9 + uVar2 * -0x100) / local_44;
    }
    DAT_1008d2c4 = (DAT_1008d2c4 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    if ((sVar16 == local_30) || (iVar10 == 1)) {
      uVar29 = iVar15 + uVar20 * -0x100;
    }
    else if (iVar10 == 2) {
      uVar29 = (int)(iVar15 + uVar20 * -0x100) >> 1;
    }
    else {
      uVar29 = (int)(iVar15 + uVar20 * -0x100) / iVar10;
    }
    DAT_1008d2d4 = (uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    if ((local_2c == sVar16) || (local_44 == 1)) {
      uVar29 = iVar24 + uVar20 * -0x100;
    }
    else if (local_44 == 2) {
      uVar29 = (int)(iVar24 + uVar20 * -0x100) >> 1;
    }
    else {
      uVar29 = (int)(iVar24 + uVar20 * -0x100) / local_44;
    }
    DAT_1008d2d0 = (uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    DAT_1008d2c0 = iVar19;
    DAT_1008d2cc = iVar21;
  }
  else {
    iVar19 = iVar17 - DAT_1008d280;
    if (iVar10 == 1) {
      DAT_1008d28c = iVar19 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1008d28c = iVar19 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar5 + (iVar19 * 0x20 + iVar10) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1008d28c = (iVar19 * 0x10000) / iVar10;
    }
    else {
      DAT_1008d28c = (iVar19 * 0x10000) / iVar10;
    }
    iVar19 = (int)*(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (0 < iVar19) {
      iVar23 = iVar27 - DAT_1008d280;
      if (iVar19 == 1) {
        DAT_1008d288 = iVar23 * 0x10000;
      }
      else if (iVar19 == 2) {
        DAT_1008d288 = iVar23 * 0x8000;
      }
      else if (((iVar19 < 0x20) && (-0x20 < iVar23)) && (iVar23 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar5 + (iVar23 * 0x20 + iVar19) * 4);
      }
      else if (iVar23 < 0) {
        DAT_1008d288 = (iVar23 * 0x10000) / iVar19;
      }
      else {
        DAT_1008d288 = (iVar23 * 0x10000) / iVar19;
      }
      iVar23 = DAT_1008d288 - DAT_1008d28c;
      if (iVar23 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d2a0 = DAT_10089ef4;
        return;
      }
      if ((uVar3 == uVar30) || (iVar10 == 1)) {
        iVar6 = (uint)uVar30 - (uVar12 & 0xffff);
      }
      else if (iVar10 == 2) {
        iVar6 = (int)((uint)uVar30 - (uVar12 & 0xffff)) >> 1;
      }
      else {
        iVar6 = (int)((uint)uVar30 - (uVar12 & 0xffff)) / iVar10;
      }
      local_20 = (uint)uVar30;
      uVar12 = uVar12 & 0xffff;
      if ((local_28 == local_3c) || (iVar10 == 1)) {
        uVar29 = uVar2 * 0x100 + uVar25 * -0x100;
      }
      else if (iVar10 == 2) {
        uVar29 = (int)(uVar2 * 0x100 + uVar25 * -0x100) >> 1;
      }
      else {
        uVar29 = (int)(uVar2 * 0x100 + uVar25 * -0x100) / iVar10;
      }
      DAT_1008d2c4 = (iVar6 << 0x10 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
      local_34 = (uint)CONCAT12(bVar1,uVar4);
      if ((uVar3 == uVar4) || (iVar19 == 1)) {
        iVar6 = (local_34 & 0xffff) - uVar12;
      }
      else if (iVar19 == 2) {
        iVar6 = (int)((local_34 & 0xffff) - uVar12) >> 1;
      }
      else {
        iVar6 = (int)((local_34 & 0xffff) - uVar12) / iVar19;
      }
      uVar29 = (uint)uVar4;
      DAT_1008d2c8 = iVar6 - (DAT_1008d2c4 >> 0x10);
      if (DAT_1008d2c8 != 0) {
        DAT_1008d2c8 = (int)(DAT_1008d2c8 * 0x10000) / iVar23 << 0x10;
      }
      if ((local_18 == local_3c) || (iVar19 == 1)) {
        iVar6 = uVar22 * 0x100 + uVar25 * -0x100;
      }
      else if (iVar19 == 2) {
        iVar6 = (int)(uVar22 * 0x100 + uVar25 * -0x100) >> 1;
      }
      else {
        iVar6 = (int)(uVar22 * 0x100 + uVar25 * -0x100) / iVar19;
      }
      iVar28 = uVar22 * 0x100;
      if (iVar6 - (short)DAT_1008d2c4 != 0) {
        uVar11 = DAT_1008d2c8 | ((iVar6 - (short)DAT_1008d2c4) * 0x10000) / iVar23 & 0xffffU;
        DAT_1008d2c8 = uVar11 + (uVar11 & 0x8000) * -2;
      }
      if ((sVar16 == local_30) || (iVar10 == 1)) {
        uVar11 = iVar21 + uVar14 * -0x100;
      }
      else if (iVar10 == 2) {
        uVar11 = (int)(iVar21 + uVar14 * -0x100) >> 1;
      }
      else {
        uVar11 = (int)(iVar21 + uVar14 * -0x100) / iVar10;
      }
      DAT_1008d2d4 = 0;
      DAT_1008d2d0 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      if ((local_2c == local_30) || (iVar19 == 1)) {
        iVar21 = iVar24 + uVar14 * -0x100;
      }
      else if (iVar19 == 2) {
        iVar21 = (int)(iVar24 + uVar14 * -0x100) >> 1;
      }
      else {
        iVar21 = (int)(iVar24 + uVar14 * -0x100) / iVar19;
      }
      if (iVar21 - (short)DAT_1008d2d0 != 0) {
        uVar11 = ((iVar21 - (short)DAT_1008d2d0) * 0x10000) / iVar23;
        DAT_1008d2d4 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      }
      if ((iVar8 == iVar9) || (iVar10 == 1)) {
        DAT_1008d2e8 = iVar8 - iVar9;
      }
      else if (iVar10 == 2) {
        DAT_1008d2e8 = iVar8 - iVar9 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar8 - iVar9) / iVar10;
      }
      if ((iVar9 == iVar7) || (iVar19 == 1)) {
        iVar21 = iVar7 - iVar9;
      }
      else if (iVar19 == 2) {
        iVar21 = iVar7 - iVar9 >> 1;
      }
      else {
        iVar21 = (iVar7 - iVar9) / iVar19;
      }
      DAT_1008d2ec = iVar21 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && (iVar23 >> 6 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / (iVar23 >> 6) << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar10 < iVar19) {
        local_44 = iVar19 - iVar10;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar9;
        DAT_1008d290 = iVar10;
        DAT_1008d2c0 = iVar26;
        DAT_1008d2cc = iVar15;
        FUN_1007a8c8();
        DAT_1008d280 = iVar17 << 0x10;
        iVar27 = iVar27 - iVar17;
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
        if ((uVar4 == uVar30) || (local_44 == 1)) {
          DAT_1008d2c4 = uVar29 - local_20;
        }
        else if (local_44 == 2) {
          DAT_1008d2c4 = (int)(uVar29 - local_20) >> 1;
        }
        else {
          DAT_1008d2c4 = (int)(uVar29 - local_20) / local_44;
        }
        DAT_1008d2c4 = DAT_1008d2c4 << 0x10;
        if ((local_18 == local_28) || (local_44 == 1)) {
          uVar29 = iVar28 + uVar2 * -0x100;
        }
        else if (local_44 == 2) {
          uVar29 = (int)(iVar28 + uVar2 * -0x100) >> 1;
        }
        else {
          uVar29 = (int)(iVar28 + uVar2 * -0x100) / local_44;
        }
        if (uVar29 != 0) {
          DAT_1008d2c4 = (DAT_1008d2c4 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
        }
        DAT_1008d2d0 = 0;
        if ((local_2c == sVar16) || (local_44 == 1)) {
          uVar29 = iVar24 + uVar20 * -0x100;
        }
        else if (local_44 == 2) {
          uVar29 = (int)(iVar24 + uVar20 * -0x100) >> 1;
        }
        else {
          uVar29 = (int)(iVar24 + uVar20 * -0x100) / local_44;
        }
        if (uVar29 != 0) {
          DAT_1008d2d0 = (uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
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
        local_44 = iVar10 - iVar19;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar9;
        DAT_1008d290 = iVar19;
        DAT_1008d2c0 = iVar26;
        DAT_1008d2cc = iVar15;
        FUN_1007a8c8();
        if (local_44 == 0) {
          return;
        }
        DAT_1008d284 = iVar27 << 0x10;
        iVar17 = iVar17 - iVar27;
        if (local_44 == 1) {
          DAT_1008d288 = iVar17 * 0x10000;
        }
        else if (local_44 == 2) {
          DAT_1008d288 = iVar17 * 0x8000;
        }
        else if (((local_44 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar5 + (iVar17 * 0x20 + local_44) * 4);
        }
        else if (iVar17 < 0) {
          DAT_1008d288 = (iVar17 * 0x10000) / local_44;
        }
        else {
          DAT_1008d288 = (iVar17 * 0x10000) / local_44;
        }
      }
      goto LAB_1002b4a0;
    }
    iVar19 = iVar27 - DAT_1008d280;
    if (iVar19 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar17 = iVar17 - iVar27;
    if (iVar10 == 1) {
      DAT_1008d288 = iVar17 * 0x10000;
    }
    else if (iVar10 == 2) {
      DAT_1008d288 = iVar17 * 0x8000;
    }
    else if (((iVar10 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar5 + (iVar17 * 0x20 + iVar10) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1008d288 = (iVar17 * 0x10000) / iVar10;
    }
    else {
      DAT_1008d288 = (iVar17 * 0x10000) / iVar10;
    }
    if ((iVar9 == iVar7) || (iVar19 == 1)) {
      DAT_1008d2ec = iVar7 - iVar9;
    }
    else if (iVar19 == 2) {
      DAT_1008d2ec = iVar7 - iVar9 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar7 - iVar9) / iVar19;
    }
    if ((iVar8 == iVar9) || (iVar10 == 1)) {
      DAT_1008d2e8 = iVar8 - iVar9;
    }
    else if (iVar10 == 2) {
      DAT_1008d2e8 = iVar8 - iVar9 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar8 - iVar9) / iVar10;
    }
    if ((uVar3 == uVar4) || (iVar19 == 1)) {
      iVar7 = (uVar29 & 0xffff) - (uVar12 & 0xffff);
    }
    else if (iVar19 == 2) {
      iVar7 = (int)((uVar29 & 0xffff) - (uVar12 & 0xffff)) >> 1;
    }
    else {
      iVar7 = (int)((uVar29 & 0xffff) - (uVar12 & 0xffff)) / iVar19;
    }
    uVar12 = uVar12 & 0xffff;
    iVar8 = uVar22 * 0x100;
    if ((local_18 == local_3c) || (iVar19 == 1)) {
      uVar29 = iVar8 + uVar25 * -0x100;
    }
    else if (iVar19 == 2) {
      uVar29 = (int)(iVar8 + uVar25 * -0x100) >> 1;
    }
    else {
      uVar29 = (int)(iVar8 + uVar25 * -0x100) / iVar19;
    }
    DAT_1008d2c8 = (iVar7 << 0x10 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    if ((uVar3 == uVar30) || (iVar10 == 1)) {
      iVar7 = (uVar11 & 0xffff) - uVar12;
    }
    else if (iVar10 == 2) {
      iVar7 = (int)((uVar11 & 0xffff) - uVar12) >> 1;
    }
    else {
      iVar7 = (int)((uVar11 & 0xffff) - uVar12) / iVar10;
    }
    iVar8 = uVar2 * 0x100;
    if ((local_28 == local_3c) || (iVar10 == 1)) {
      uVar29 = iVar8 + uVar25 * -0x100;
    }
    else if (iVar10 == 2) {
      uVar29 = (int)(iVar8 + uVar25 * -0x100) >> 1;
    }
    else {
      uVar29 = (int)(iVar8 + uVar25 * -0x100) / iVar10;
    }
    DAT_1008d2c4 = (iVar7 << 0x10 | uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    if ((local_2c == local_30) || (iVar19 == 1)) {
      uVar29 = iVar24 + uVar14 * -0x100;
    }
    else if (iVar19 == 2) {
      uVar29 = (int)(iVar24 + uVar14 * -0x100) >> 1;
    }
    else {
      uVar29 = (int)(iVar24 + uVar14 * -0x100) / iVar19;
    }
    DAT_1008d2d4 = (uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    if ((sVar16 == local_30) || (iVar10 == 1)) {
      uVar29 = iVar21 + uVar14 * -0x100;
    }
    else if (iVar10 == 2) {
      uVar29 = (int)(iVar21 + uVar14 * -0x100) >> 1;
    }
    else {
      uVar29 = (int)(iVar21 + uVar14 * -0x100) / iVar10;
    }
    DAT_1008d2d0 = (uVar29 & 0xffff) + (uVar29 & 0x8000) * -2;
    DAT_1008d2c0 = iVar26;
    DAT_1008d2cc = iVar15;
    local_44 = iVar10;
    iVar8 = iVar9;
    iVar17 = DAT_1008d280;
    DAT_1008d280 = iVar27;
  }
  DAT_1008d284 = DAT_1008d280 << 0x10;
  DAT_1008d280 = iVar17 << 0x10;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar8;
LAB_1002b4a0:
  DAT_1008d290 = local_44;
  FUN_1007a8c8();
  return;
}


