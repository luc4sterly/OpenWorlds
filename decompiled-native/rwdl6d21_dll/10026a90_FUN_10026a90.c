// 10026a90 FUN_10026a90 [Global]
// program: RWDL6D21.DLL

void FUN_10026a90(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  ushort uVar2;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  short sVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  int iVar29;
  int iVar30;
  int local_44;
  short local_3c;
  uint local_34;
  short local_30;
  uint local_2c;
  short local_28;
  uint local_20;
  short local_18;
  ushort uVar3;
  
  iVar10 = param_3;
  iVar8 = param_4;
  iVar9 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar10 = param_2;
      iVar8 = param_3;
      iVar9 = param_4;
    }
LAB_10026ad6:
    param_2 = iVar8;
    param_3 = iVar9;
    param_4 = iVar10;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10026ad6;
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  iVar4 = (int)*(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  uVar5 = *(uint *)(*param_1 + 8);
  uVar12 = (uVar5 & 0x7c0) >> 6;
  uVar13 = (uVar5 & 0xf800) >> 0xb;
  uVar26 = (uint)*(byte *)((*(int *)(param_2 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 + uVar12
                          );
  local_34 = (uint)*(byte *)((*(int *)(param_2 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar13);
  uVar14 = local_34 << 0x10;
  uVar5 = uVar5 & 0x1f;
  iVar27 = (uVar26 | uVar14) << 8;
  uVar15 = (uint)*(byte *)((*(int *)(param_2 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar5)
  ;
  iVar16 = uVar15 * 0x100;
  iVar10 = *(int *)(param_2 + 0x20);
  iVar18 = (int)*(short *)(param_3 + 0x1a);
  uVar19 = (uint)*(byte *)((*(int *)(param_3 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 + uVar12
                          );
  local_34 = (uint)*(byte *)((*(int *)(param_3 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar13);
  uVar28 = local_34 << 0x10;
  iVar20 = (uVar19 | uVar28) << 8;
  iVar9 = *(int *)(param_3 + 0x20);
  uVar21 = (uint)*(byte *)((*(int *)(param_3 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar5)
  ;
  iVar29 = (int)*(short *)(param_4 + 0x1a);
  iVar22 = uVar21 * 0x100;
  uVar23 = (uint)*(byte *)((*(int *)(param_4 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 + uVar12
                          );
  bVar1 = *(byte *)((*(int *)(param_4 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar13);
  local_2c = (uint)bVar1;
  iVar24 = (uVar23 | local_2c << 0x10) << 8;
  iVar8 = *(int *)(param_4 + 0x20);
  iVar25 = (uint)*(byte *)((*(int *)(param_4 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar5)
           * 0x100;
  DAT_1007f2a0 = DAT_1007beb0;
  DAT_1007f29c = DAT_1007f284 * DAT_1007beb0 + DAT_10079210;
  iVar6 = DAT_10079214 + 0x1000;
  DAT_1007f2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  DAT_1007f2a4 = *(undefined4 *)(DAT_10079228 + (DAT_1007f284 & 7) * 4);
  local_3c = (short)iVar27;
  local_28 = (short)iVar20;
  local_18 = (short)iVar24;
  local_34._0_2_ = (short)iVar25;
  local_30 = (short)iVar16;
  uVar5 = iVar24 >> 0x10;
  uVar12 = iVar20 >> 0x10;
  uVar13 = iVar27 >> 0x10;
  uVar2 = (ushort)(uVar14 >> 8);
  uVar11 = (ushort)(uVar28 >> 8);
  uVar3 = (ushort)((local_2c << 0x10) >> 8);
  sVar17 = (short)iVar22;
  if (iVar4 < 1) {
    iVar4 = DAT_1007f280 - iVar18;
    if (iVar4 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    local_44 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_44 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar24 = iVar29 - iVar18;
    if (local_44 == 1) {
      DAT_1007f28c = iVar24 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1007f28c = iVar24 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar6 + (iVar24 * 0x20 + local_44) * 4);
    }
    else if (iVar24 < 0) {
      DAT_1007f28c = (iVar24 * 0x10000) / local_44;
    }
    else {
      DAT_1007f28c = (iVar24 * 0x10000) / local_44;
    }
    iVar29 = iVar29 - DAT_1007f280;
    if (local_44 == 1) {
      DAT_1007f288 = iVar29 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1007f288 = iVar29 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar29)) && (iVar29 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar6 + (iVar29 * 0x20 + local_44) * 4);
    }
    else if (iVar29 < 0) {
      DAT_1007f288 = (iVar29 * 0x10000) / local_44;
    }
    else {
      DAT_1007f288 = (iVar29 * 0x10000) / local_44;
    }
    if ((iVar9 == iVar10) || (iVar4 == 1)) {
      DAT_1007f2ec = iVar10 - iVar9;
    }
    else if (iVar4 == 2) {
      DAT_1007f2ec = iVar10 - iVar9 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar10 - iVar9) / iVar4;
    }
    if ((iVar8 == iVar9) || (local_44 == 1)) {
      DAT_1007f2e8 = iVar8 - iVar9;
    }
    else if (local_44 == 2) {
      DAT_1007f2e8 = iVar8 - iVar9 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar8 - iVar9) / local_44;
    }
    if ((uVar2 == uVar11) || (iVar4 == 1)) {
      iVar10 = (uVar13 & 0xffff) - (uVar12 & 0xffff);
    }
    else if (iVar4 == 2) {
      iVar10 = (int)((uVar13 & 0xffff) - (uVar12 & 0xffff)) >> 1;
    }
    else {
      iVar10 = (int)((uVar13 & 0xffff) - (uVar12 & 0xffff)) / iVar4;
    }
    uVar12 = uVar12 & 0xffff;
    if ((uVar3 == uVar11) || (local_44 == 1)) {
      iVar8 = (uVar5 & 0xffff) - uVar12;
    }
    else if (local_44 == 2) {
      iVar8 = (int)((uVar5 & 0xffff) - uVar12) >> 1;
    }
    else {
      iVar8 = (int)((uVar5 & 0xffff) - uVar12) / local_44;
    }
    DAT_1007f2c4 = iVar8 << 0x10;
    iVar8 = uVar26 * 0x100;
    if ((local_3c == local_28) || (iVar4 == 1)) {
      uVar5 = iVar8 + uVar19 * -0x100;
    }
    else if (iVar4 == 2) {
      uVar5 = (int)(iVar8 + uVar19 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar8 + uVar19 * -0x100) / iVar4;
    }
    DAT_1007f2c8 = (iVar10 << 0x10 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    iVar10 = uVar23 * 0x100;
    if ((local_18 == local_28) || (local_44 == 1)) {
      uVar5 = iVar10 + uVar19 * -0x100;
    }
    else if (local_44 == 2) {
      uVar5 = (int)(iVar10 + uVar19 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar10 + uVar19 * -0x100) / local_44;
    }
    DAT_1007f2c4 = (DAT_1007f2c4 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    if ((sVar17 == local_30) || (iVar4 == 1)) {
      uVar5 = iVar16 + uVar21 * -0x100;
    }
    else if (iVar4 == 2) {
      uVar5 = (int)(iVar16 + uVar21 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar16 + uVar21 * -0x100) / iVar4;
    }
    DAT_1007f2d4 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    if (((short)local_34 == sVar17) || (local_44 == 1)) {
      uVar5 = iVar25 + uVar21 * -0x100;
    }
    else if (local_44 == 2) {
      uVar5 = (int)(iVar25 + uVar21 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar25 + uVar21 * -0x100) / local_44;
    }
    DAT_1007f2d0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    DAT_1007f2c0 = iVar20;
    DAT_1007f2cc = iVar22;
  }
  else {
    iVar20 = iVar18 - DAT_1007f280;
    if (iVar4 == 1) {
      DAT_1007f28c = iVar20 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007f28c = iVar20 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar6 + (iVar20 * 0x20 + iVar4) * 4);
    }
    else if (iVar20 < 0) {
      DAT_1007f28c = (iVar20 * 0x10000) / iVar4;
    }
    else {
      DAT_1007f28c = (iVar20 * 0x10000) / iVar4;
    }
    iVar20 = (int)*(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (0 < iVar20) {
      iVar24 = iVar29 - DAT_1007f280;
      if (iVar20 == 1) {
        DAT_1007f288 = iVar24 * 0x10000;
      }
      else if (iVar20 == 2) {
        DAT_1007f288 = iVar24 * 0x8000;
      }
      else if (((iVar20 < 0x20) && (-0x20 < iVar24)) && (iVar24 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar6 + (iVar24 * 0x20 + iVar20) * 4);
      }
      else if (iVar24 < 0) {
        DAT_1007f288 = (iVar24 * 0x10000) / iVar20;
      }
      else {
        DAT_1007f288 = (iVar24 * 0x10000) / iVar20;
      }
      iVar24 = DAT_1007f288 - DAT_1007f28c;
      if (iVar24 < 1) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f2a0 = DAT_1007beb0;
        return;
      }
      if ((uVar11 == uVar2) || (iVar4 == 1)) {
        iVar7 = (uint)uVar11 - (uVar13 & 0xffff);
      }
      else if (iVar4 == 2) {
        iVar7 = (int)((uint)uVar11 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        iVar7 = (int)((uint)uVar11 - (uVar13 & 0xffff)) / iVar4;
      }
      local_20 = (uint)uVar11;
      uVar13 = uVar13 & 0xffff;
      if ((local_28 == local_3c) || (iVar4 == 1)) {
        uVar5 = uVar19 * 0x100 + uVar26 * -0x100;
      }
      else if (iVar4 == 2) {
        uVar5 = (int)(uVar19 * 0x100 + uVar26 * -0x100) >> 1;
      }
      else {
        uVar5 = (int)(uVar19 * 0x100 + uVar26 * -0x100) / iVar4;
      }
      DAT_1007f2c4 = (iVar7 << 0x10 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      local_2c = (uint)CONCAT12(bVar1,uVar3);
      if ((uVar3 == uVar2) || (iVar20 == 1)) {
        iVar7 = (local_2c & 0xffff) - uVar13;
      }
      else if (iVar20 == 2) {
        iVar7 = (int)((local_2c & 0xffff) - uVar13) >> 1;
      }
      else {
        iVar7 = (int)((local_2c & 0xffff) - uVar13) / iVar20;
      }
      uVar5 = (uint)uVar3;
      DAT_1007f2c8 = iVar7 - (DAT_1007f2c4 >> 0x10);
      if (DAT_1007f2c8 != 0) {
        DAT_1007f2c8 = (int)(DAT_1007f2c8 * 0x10000) / iVar24 << 0x10;
      }
      if ((local_18 == local_3c) || (iVar20 == 1)) {
        iVar7 = uVar23 * 0x100 + uVar26 * -0x100;
      }
      else if (iVar20 == 2) {
        iVar7 = (int)(uVar23 * 0x100 + uVar26 * -0x100) >> 1;
      }
      else {
        iVar7 = (int)(uVar23 * 0x100 + uVar26 * -0x100) / iVar20;
      }
      iVar30 = uVar23 * 0x100;
      if (iVar7 - (short)DAT_1007f2c4 != 0) {
        uVar12 = DAT_1007f2c8 | ((iVar7 - (short)DAT_1007f2c4) * 0x10000) / iVar24 & 0xffffU;
        DAT_1007f2c8 = uVar12 + (uVar12 & 0x8000) * -2;
      }
      if ((sVar17 == local_30) || (iVar4 == 1)) {
        uVar12 = iVar22 + uVar15 * -0x100;
      }
      else if (iVar4 == 2) {
        uVar12 = (int)(iVar22 + uVar15 * -0x100) >> 1;
      }
      else {
        uVar12 = (int)(iVar22 + uVar15 * -0x100) / iVar4;
      }
      DAT_1007f2d4 = 0;
      DAT_1007f2d0 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
      if (((short)local_34 == local_30) || (iVar20 == 1)) {
        iVar22 = iVar25 + uVar15 * -0x100;
      }
      else if (iVar20 == 2) {
        iVar22 = (int)(iVar25 + uVar15 * -0x100) >> 1;
      }
      else {
        iVar22 = (int)(iVar25 + uVar15 * -0x100) / iVar20;
      }
      if (iVar22 - (short)DAT_1007f2d0 != 0) {
        uVar12 = ((iVar22 - (short)DAT_1007f2d0) * 0x10000) / iVar24;
        DAT_1007f2d4 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
      }
      if ((iVar9 == iVar10) || (iVar4 == 1)) {
        DAT_1007f2e8 = iVar9 - iVar10;
      }
      else if (iVar4 == 2) {
        DAT_1007f2e8 = iVar9 - iVar10 >> 1;
      }
      else {
        DAT_1007f2e8 = (iVar9 - iVar10) / iVar4;
      }
      if ((iVar8 == iVar10) || (iVar20 == 1)) {
        iVar22 = iVar8 - iVar10;
      }
      else if (iVar20 == 2) {
        iVar22 = iVar8 - iVar10 >> 1;
      }
      else {
        iVar22 = (iVar8 - iVar10) / iVar20;
      }
      DAT_1007f2ec = iVar22 - DAT_1007f2e8;
      if ((DAT_1007f2ec != 0) && (iVar24 >> 6 != 0)) {
        DAT_1007f2ec = DAT_1007f2ec / (iVar24 >> 6) << 10;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iVar4 < iVar20) {
        local_44 = iVar20 - iVar4;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar10;
        DAT_1007f290 = iVar4;
        DAT_1007f2c0 = iVar27;
        DAT_1007f2cc = iVar16;
        FUN_1006a440();
        DAT_1007f280 = iVar18 << 0x10;
        iVar29 = iVar29 - iVar18;
        if (local_44 == 1) {
          DAT_1007f28c = iVar29 * 0x10000;
        }
        else if (local_44 == 2) {
          DAT_1007f28c = iVar29 * 0x8000;
        }
        else if (((local_44 < 0x20) && (-0x20 < iVar29)) && (iVar29 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar6 + (iVar29 * 0x20 + local_44) * 4);
        }
        else if (iVar29 < 0) {
          DAT_1007f28c = (iVar29 * 0x10000) / local_44;
        }
        else {
          DAT_1007f28c = (iVar29 * 0x10000) / local_44;
        }
        if ((uVar3 == uVar11) || (local_44 == 1)) {
          DAT_1007f2c4 = uVar5 - local_20;
        }
        else if (local_44 == 2) {
          DAT_1007f2c4 = (int)(uVar5 - local_20) >> 1;
        }
        else {
          DAT_1007f2c4 = (int)(uVar5 - local_20) / local_44;
        }
        DAT_1007f2c4 = DAT_1007f2c4 << 0x10;
        if ((local_18 == local_28) || (local_44 == 1)) {
          uVar5 = iVar30 + uVar19 * -0x100;
        }
        else if (local_44 == 2) {
          uVar5 = (int)(iVar30 + uVar19 * -0x100) >> 1;
        }
        else {
          uVar5 = (int)(iVar30 + uVar19 * -0x100) / local_44;
        }
        if (uVar5 != 0) {
          DAT_1007f2c4 = (DAT_1007f2c4 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
        }
        DAT_1007f2d0 = 0;
        if (((short)local_34 == sVar17) || (local_44 == 1)) {
          uVar5 = iVar25 + uVar21 * -0x100;
        }
        else if (local_44 == 2) {
          uVar5 = (int)(iVar25 + uVar21 * -0x100) >> 1;
        }
        else {
          uVar5 = (int)(iVar25 + uVar21 * -0x100) / local_44;
        }
        if (uVar5 != 0) {
          DAT_1007f2d0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
        }
        if (iVar8 == iVar9) {
          DAT_1007f2e8 = iVar8 - iVar9;
        }
        else if (local_44 == 1) {
          DAT_1007f2e8 = iVar8 - iVar9;
        }
        else if (local_44 == 2) {
          DAT_1007f2e8 = iVar8 - iVar9 >> 1;
        }
        else {
          DAT_1007f2e8 = (iVar8 - iVar9) / local_44;
        }
      }
      else {
        local_44 = iVar4 - iVar20;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar10;
        DAT_1007f290 = iVar20;
        DAT_1007f2c0 = iVar27;
        DAT_1007f2cc = iVar16;
        FUN_1006a440();
        if (local_44 == 0) {
          return;
        }
        DAT_1007f284 = iVar29 << 0x10;
        iVar18 = iVar18 - iVar29;
        if (local_44 == 1) {
          DAT_1007f288 = iVar18 * 0x10000;
        }
        else if (local_44 == 2) {
          DAT_1007f288 = iVar18 * 0x8000;
        }
        else if (((local_44 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar6 + (iVar18 * 0x20 + local_44) * 4);
        }
        else if (iVar18 < 0) {
          DAT_1007f288 = (iVar18 * 0x10000) / local_44;
        }
        else {
          DAT_1007f288 = (iVar18 * 0x10000) / local_44;
        }
      }
      goto LAB_10027d50;
    }
    iVar20 = iVar29 - DAT_1007f280;
    if (iVar20 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar18 = iVar18 - iVar29;
    if (iVar4 == 1) {
      DAT_1007f288 = iVar18 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007f288 = iVar18 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar6 + (iVar18 * 0x20 + iVar4) * 4);
    }
    else if (iVar18 < 0) {
      DAT_1007f288 = (iVar18 * 0x10000) / iVar4;
    }
    else {
      DAT_1007f288 = (iVar18 * 0x10000) / iVar4;
    }
    if ((iVar8 == iVar10) || (iVar20 == 1)) {
      DAT_1007f2ec = iVar8 - iVar10;
    }
    else if (iVar20 == 2) {
      DAT_1007f2ec = iVar8 - iVar10 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar8 - iVar10) / iVar20;
    }
    if ((iVar9 == iVar10) || (iVar4 == 1)) {
      DAT_1007f2e8 = iVar9 - iVar10;
    }
    else if (iVar4 == 2) {
      DAT_1007f2e8 = iVar9 - iVar10 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar9 - iVar10) / iVar4;
    }
    if ((uVar3 == uVar2) || (iVar20 == 1)) {
      iVar8 = (uVar5 & 0xffff) - (uVar13 & 0xffff);
    }
    else if (iVar20 == 2) {
      iVar8 = (int)((uVar5 & 0xffff) - (uVar13 & 0xffff)) >> 1;
    }
    else {
      iVar8 = (int)((uVar5 & 0xffff) - (uVar13 & 0xffff)) / iVar20;
    }
    uVar13 = uVar13 & 0xffff;
    iVar9 = uVar23 * 0x100;
    if ((local_18 == local_3c) || (iVar20 == 1)) {
      uVar5 = iVar9 + uVar26 * -0x100;
    }
    else if (iVar20 == 2) {
      uVar5 = (int)(iVar9 + uVar26 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar9 + uVar26 * -0x100) / iVar20;
    }
    DAT_1007f2c8 = (iVar8 << 0x10 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    if ((uVar11 == uVar2) || (iVar4 == 1)) {
      iVar8 = (uVar12 & 0xffff) - uVar13;
    }
    else if (iVar4 == 2) {
      iVar8 = (int)((uVar12 & 0xffff) - uVar13) >> 1;
    }
    else {
      iVar8 = (int)((uVar12 & 0xffff) - uVar13) / iVar4;
    }
    iVar9 = uVar19 * 0x100;
    if ((local_28 == local_3c) || (iVar4 == 1)) {
      uVar5 = iVar9 + uVar26 * -0x100;
    }
    else if (iVar4 == 2) {
      uVar5 = (int)(iVar9 + uVar26 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar9 + uVar26 * -0x100) / iVar4;
    }
    DAT_1007f2c4 = (iVar8 << 0x10 | uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    if (((short)local_34 == local_30) || (iVar20 == 1)) {
      uVar5 = iVar25 + uVar15 * -0x100;
    }
    else if (iVar20 == 2) {
      uVar5 = (int)(iVar25 + uVar15 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar25 + uVar15 * -0x100) / iVar20;
    }
    DAT_1007f2d4 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    if ((sVar17 == local_30) || (iVar4 == 1)) {
      uVar5 = iVar22 + uVar15 * -0x100;
    }
    else if (iVar4 == 2) {
      uVar5 = (int)(iVar22 + uVar15 * -0x100) >> 1;
    }
    else {
      uVar5 = (int)(iVar22 + uVar15 * -0x100) / iVar4;
    }
    DAT_1007f2d0 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    DAT_1007f2c0 = iVar27;
    DAT_1007f2cc = iVar16;
    local_44 = iVar4;
    iVar9 = iVar10;
    iVar18 = DAT_1007f280;
    DAT_1007f280 = iVar29;
  }
  DAT_1007f284 = DAT_1007f280 << 0x10;
  DAT_1007f280 = iVar18 << 0x10;
  DAT_1007f2e4 = DAT_1007f2f0 + iVar9;
LAB_10027d50:
  DAT_1007f290 = local_44;
  FUN_1006a440();
  return;
}


