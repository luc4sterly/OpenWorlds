// 10027de0 FUN_10027de0 [Global]
// programa: RWDL6D21.DLL

void FUN_10027de0(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  short sVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  short sVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  short sVar28;
  int iVar29;
  uint uVar30;
  int iVar31;
  ushort *puVar32;
  uint uVar33;
  uint uVar34;
  int local_7c;
  uint local_78;
  int local_74;
  uint local_6c;
  ushort local_68;
  short local_60;
  uint local_5c;
  int local_54;
  short local_50;
  uint local_48;
  uint local_44;
  int local_40;
  int local_38;
  short local_30;
  short local_28;
  uint local_18;
  ushort uVar4;
  
  iVar2 = DAT_1007bda4;
  iVar10 = param_2;
  iVar21 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar10 = param_4;
      iVar21 = param_2;
      param_4 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_10027e2e;
  param_3 = iVar10;
  param_2 = param_4;
  param_4 = iVar21;
LAB_10027e2e:
  uVar14 = (uint)*(short *)(param_2 + 0x1e);
  iVar15 = (int)*(short *)(param_3 + 0x1e) - uVar14;
  iVar16 = (int)*(short *)(param_2 + 0x1a);
  uVar17 = *(uint *)(*param_1 + 8);
  uVar33 = (uVar17 & 0x7c0) >> 6;
  uVar34 = (uVar17 & 0xf800) >> 0xb;
  uVar20 = (uint)*(byte *)((*(int *)(param_2 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 + uVar33
                          );
  local_18 = (uint)*(byte *)((*(int *)(param_2 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar34);
  uVar17 = uVar17 & 0x1f;
  iVar21 = (uVar20 | local_18 << 0x10) << 8;
  uVar22 = (uint)*(byte *)((*(int *)(param_2 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar17
                          );
  iVar29 = (int)*(short *)(param_3 + 0x1a);
  iVar23 = uVar22 * 0x100;
  uVar24 = (uint)*(byte *)((*(int *)(param_3 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 + uVar33
                          );
  uVar30 = (uint)*(byte *)((*(int *)(param_3 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar34) <<
           0x10;
  iVar25 = (uVar24 | uVar30) << 8;
  uVar11 = (uint)*(byte *)((*(int *)(param_3 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar17
                          );
  iVar31 = (int)*(short *)(param_4 + 0x1a);
  iVar5 = uVar11 * 0x100;
  uVar33 = (uint)*(byte *)((*(int *)(param_4 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 + uVar33
                          );
  uVar26 = (uint)*(byte *)((*(int *)(param_4 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar34) <<
           0x10;
  iVar6 = (uVar33 | uVar26) << 8;
  bVar1 = *(byte *)((*(int *)(param_4 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar17);
  sVar19 = (ushort)bVar1 * 0x100;
  iVar18 = DAT_10079214 + 0x1000;
  uVar34 = (uint)*(byte *)(*param_1 + 4);
  iVar10 = *(int *)(DAT_10079218 + uVar14 * 4);
  uVar17 = *(uint *)(DAT_10079228 + (uVar14 & 7) * 4);
  local_60 = (short)iVar21;
  local_50 = (short)iVar25;
  local_30 = (short)iVar6;
  local_68 = (ushort)iVar23;
  uVar8 = iVar6 >> 0x10;
  uVar9 = iVar25 >> 0x10;
  uVar27 = iVar21 >> 0x10;
  uVar3 = (ushort)((local_18 << 0x10) >> 8);
  uVar12 = (ushort)(uVar30 >> 8);
  uVar4 = (ushort)(uVar26 >> 8);
  sVar28 = (short)iVar5;
  if (iVar15 < 1) {
    iVar21 = iVar16 - iVar29;
    if (iVar21 < 1) {
      return;
    }
    iVar15 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iVar15 == 0) {
      return;
    }
    local_74 = iVar31 - iVar29;
    if (iVar15 == 1) {
      local_74 = local_74 * 0x10000;
    }
    else if (iVar15 == 2) {
      local_74 = local_74 * 0x8000;
    }
    else if (((iVar15 < 0x20) && (-0x20 < local_74)) && (local_74 < 0x20)) {
      local_74 = *(int *)(iVar18 + (local_74 * 0x20 + iVar15) * 4);
    }
    else if (local_74 < 0) {
      local_74 = (local_74 * 0x10000) / iVar15;
    }
    else {
      local_74 = (local_74 * 0x10000) / iVar15;
    }
    iVar31 = iVar31 - iVar16;
    if (iVar15 == 1) {
      local_7c = iVar31 * 0x10000;
    }
    else if (iVar15 == 2) {
      local_7c = iVar31 * 0x8000;
    }
    else if (((iVar15 < 0x20) && (-0x20 < iVar31)) && (iVar31 < 0x20)) {
      local_7c = *(int *)(iVar18 + (iVar31 * 0x20 + iVar15) * 4);
    }
    else if (iVar31 < 0) {
      local_7c = (iVar31 * 0x10000) / iVar15;
    }
    else {
      local_7c = (iVar31 * 0x10000) / iVar15;
    }
    if ((uVar12 == uVar3) || (iVar21 == 1)) {
      iVar6 = (uVar27 & 0xffff) - (uVar9 & 0xffff);
    }
    else if (iVar21 == 2) {
      iVar6 = (int)((uVar27 & 0xffff) - (uVar9 & 0xffff)) >> 1;
    }
    else {
      iVar6 = (int)((uVar27 & 0xffff) - (uVar9 & 0xffff)) / iVar21;
    }
    uVar9 = uVar9 & 0xffff;
    if ((uVar4 == uVar12) || (iVar15 == 1)) {
      iVar31 = (uVar8 & 0xffff) - uVar9;
    }
    else if (iVar15 == 2) {
      iVar31 = (int)((uVar8 & 0xffff) - uVar9) >> 1;
    }
    else {
      iVar31 = (int)((uVar8 & 0xffff) - uVar9) / iVar15;
    }
    iVar18 = uVar20 * 0x100;
    if ((local_50 == local_60) || (iVar21 == 1)) {
      uVar8 = iVar18 + uVar24 * -0x100;
    }
    else if (iVar21 == 2) {
      uVar8 = (int)(iVar18 + uVar24 * -0x100) >> 1;
    }
    else {
      uVar8 = (int)(iVar18 + uVar24 * -0x100) / iVar21;
    }
    local_6c = (iVar6 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    iVar6 = uVar33 * 0x100;
    if ((local_30 == local_50) || (iVar15 == 1)) {
      uVar33 = iVar6 + uVar24 * -0x100;
    }
    else if (iVar15 == 2) {
      uVar33 = (int)(iVar6 + uVar24 * -0x100) >> 1;
    }
    else {
      uVar33 = (int)(iVar6 + uVar24 * -0x100) / iVar15;
    }
    local_78 = (iVar31 << 0x10 | uVar33 & 0xffff) + (uVar33 & 0x8000) * -2;
    if ((sVar28 == local_68) || (iVar21 == 1)) {
      sVar13 = local_68 - sVar28;
    }
    else if (iVar21 == 2) {
      sVar13 = (short)((int)(iVar23 + uVar11 * -0x100) >> 1);
    }
    else {
      sVar13 = (short)((int)(iVar23 + uVar11 * -0x100) / iVar21);
    }
    iVar21 = (uint)bVar1 * 0x100;
    if ((sVar19 == sVar28) || (iVar15 == 1)) {
      local_5c = iVar21 + uVar11 * -0x100;
    }
    else if (iVar15 == 2) {
      local_5c = (int)(iVar21 + uVar11 * -0x100) >> 1;
    }
    else {
      local_5c = (int)(iVar21 + uVar11 * -0x100) / iVar15;
    }
    local_5c = local_5c & 0xffff;
    uVar8 = iVar16 << 0x10;
    uVar33 = iVar29 << 0x10;
  }
  else {
    local_74 = iVar29 - iVar16;
    if (iVar15 == 1) {
      local_74 = local_74 * 0x10000;
    }
    else if (iVar15 == 2) {
      local_74 = local_74 * 0x8000;
    }
    else if (((iVar15 < 0x20) && (-0x20 < local_74)) && (local_74 < 0x20)) {
      local_74 = *(int *)(iVar18 + (local_74 * 0x20 + iVar15) * 4);
    }
    else if (local_74 < 0) {
      local_74 = (local_74 * 0x10000) / iVar15;
    }
    else {
      local_74 = (local_74 * 0x10000) / iVar15;
    }
    iVar6 = (int)*(short *)(param_4 + 0x1e) - uVar14;
    if (iVar6 < 1) {
      iVar25 = iVar31 - iVar16;
      if (iVar25 < 1) {
        return;
      }
      iVar29 = iVar29 - iVar31;
      if (iVar15 == 1) {
        local_7c = iVar29 * 0x10000;
      }
      else if (iVar15 == 2) {
        local_7c = iVar29 * 0x8000;
      }
      else if (((iVar15 < 0x20) && (-0x20 < iVar29)) && (iVar29 < 0x20)) {
        local_7c = *(int *)(iVar18 + (iVar29 * 0x20 + iVar15) * 4);
      }
      else if (iVar29 < 0) {
        local_7c = (iVar29 * 0x10000) / iVar15;
      }
      else {
        local_7c = (iVar29 * 0x10000) / iVar15;
      }
      if ((uVar4 == uVar3) || (iVar25 == 1)) {
        iVar6 = (uVar8 & 0xffff) - (uVar27 & 0xffff);
      }
      else if (iVar25 == 2) {
        iVar6 = (int)((uVar8 & 0xffff) - (uVar27 & 0xffff)) >> 1;
      }
      else {
        iVar6 = (int)((uVar8 & 0xffff) - (uVar27 & 0xffff)) / iVar25;
      }
      uVar27 = uVar27 & 0xffff;
      iVar29 = uVar33 * 0x100;
      if ((local_30 == local_60) || (iVar25 == 1)) {
        uVar11 = iVar29 + uVar20 * -0x100;
      }
      else if (iVar25 == 2) {
        uVar11 = (int)(iVar29 + uVar20 * -0x100) >> 1;
      }
      else {
        uVar11 = (int)(iVar29 + uVar20 * -0x100) / iVar25;
      }
      local_6c = (iVar6 << 0x10 | uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      if ((uVar12 == uVar3) || (iVar15 == 1)) {
        iVar6 = (uVar9 & 0xffff) - uVar27;
      }
      else if (iVar15 == 2) {
        iVar6 = (int)((uVar9 & 0xffff) - uVar27) >> 1;
      }
      else {
        iVar6 = (int)((uVar9 & 0xffff) - uVar27) / iVar15;
      }
      iVar29 = uVar24 * 0x100;
      if ((local_50 == local_60) || (iVar15 == 1)) {
        uVar11 = iVar29 + uVar20 * -0x100;
      }
      else if (iVar15 == 2) {
        uVar11 = (int)(iVar29 + uVar20 * -0x100) >> 1;
      }
      else {
        uVar11 = (int)(iVar29 + uVar20 * -0x100) / iVar15;
      }
      local_78 = (iVar6 << 0x10 | uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      if ((sVar19 == local_68) || (iVar25 == 1)) {
        sVar13 = sVar19 - local_68;
      }
      else if (iVar25 == 2) {
        sVar13 = (short)((int)((uint)bVar1 * 0x100 + uVar22 * -0x100) >> 1);
      }
      else {
        sVar13 = (short)((int)((uint)bVar1 * 0x100 + uVar22 * -0x100) / iVar25);
      }
      if ((sVar28 == local_68) || (iVar15 == 1)) {
        local_5c = iVar5 + uVar22 * -0x100;
      }
      else if (iVar15 == 2) {
        local_5c = (int)(iVar5 + uVar22 * -0x100) >> 1;
      }
      else {
        local_5c = (int)(iVar5 + uVar22 * -0x100) / iVar15;
      }
      local_5c = local_5c & 0xffff;
      uVar33 = iVar16 << 0x10;
      uVar8 = iVar31 << 0x10;
      iVar25 = iVar21;
      iVar5 = iVar23;
    }
    else {
      local_7c = iVar31 - iVar16;
      if (iVar6 == 1) {
        local_7c = local_7c * 0x10000;
      }
      else if (iVar6 == 2) {
        local_7c = local_7c * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < local_7c)) && (local_7c < 0x20)) {
        local_7c = *(int *)(iVar18 + (local_7c * 0x20 + iVar6) * 4);
      }
      else if (local_7c < 0) {
        local_7c = (local_7c * 0x10000) / iVar6;
      }
      else {
        local_7c = (local_7c * 0x10000) / iVar6;
      }
      iVar25 = local_7c - local_74;
      if (iVar25 < 1) {
        return;
      }
      if ((uVar12 == uVar3) || (iVar15 == 1)) {
        iVar7 = (uint)uVar12 - (uVar27 & 0xffff);
      }
      else if (iVar15 == 2) {
        iVar7 = (int)((uint)uVar12 - (uVar27 & 0xffff)) >> 1;
      }
      else {
        iVar7 = (int)((uint)uVar12 - (uVar27 & 0xffff)) / iVar15;
      }
      local_44 = (uint)uVar12;
      uVar27 = uVar27 & 0xffff;
      if ((local_50 == local_60) || (iVar15 == 1)) {
        uVar8 = uVar24 * 0x100 + uVar20 * -0x100;
      }
      else if (iVar15 == 2) {
        uVar8 = (int)(uVar24 * 0x100 + uVar20 * -0x100) >> 1;
      }
      else {
        uVar8 = (int)(uVar24 * 0x100 + uVar20 * -0x100) / iVar15;
      }
      local_78 = (iVar7 << 0x10 | uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      if ((uVar4 == uVar3) || (iVar6 == 1)) {
        iVar7 = uVar4 - uVar27;
      }
      else if (iVar6 == 2) {
        iVar7 = (int)(uVar4 - uVar27) >> 1;
      }
      else {
        iVar7 = (int)(uVar4 - uVar27) / iVar6;
      }
      local_48 = (uint)uVar4;
      local_6c = iVar7 - (local_78 >> 0x10);
      if (local_6c != 0) {
        local_6c = (int)(local_6c * 0x10000) / iVar25 << 0x10;
      }
      if ((local_30 == local_60) || (iVar6 == 1)) {
        iVar7 = uVar33 * 0x100 + uVar20 * -0x100;
      }
      else if (iVar6 == 2) {
        iVar7 = (int)(uVar33 * 0x100 + uVar20 * -0x100) >> 1;
      }
      else {
        iVar7 = (int)(uVar33 * 0x100 + uVar20 * -0x100) / iVar6;
      }
      local_40 = uVar33 * 0x100;
      if (iVar7 - (short)local_78 != 0) {
        local_6c = local_6c | ((iVar7 - (short)local_78) * 0x10000) / iVar25 & 0xffffU;
        local_6c = local_6c + (local_6c & 0x8000) * -2;
      }
      if ((sVar28 == local_68) || (iVar15 == 1)) {
        uVar33 = iVar5 + uVar22 * -0x100;
      }
      else if (iVar15 == 2) {
        uVar33 = (int)(iVar5 + uVar22 * -0x100) >> 1;
      }
      else {
        uVar33 = (int)(iVar5 + uVar22 * -0x100) / iVar15;
      }
      uVar9 = uVar33 & 0xffff;
      sVar13 = 0;
      if ((sVar19 == local_68) || (iVar6 == 1)) {
        local_38 = (uint)bVar1 * 0x100;
        iVar5 = local_38 + uVar22 * -0x100;
      }
      else if (iVar6 == 2) {
        local_38 = (uint)bVar1 * 0x100;
        iVar5 = (int)(local_38 + uVar22 * -0x100) >> 1;
      }
      else {
        local_38 = (uint)bVar1 * 0x100;
        iVar5 = (int)(local_38 + uVar22 * -0x100) / iVar6;
      }
      local_5c._0_2_ = (short)uVar33;
      if (iVar5 - (short)local_5c != 0) {
        sVar13 = (short)(((iVar5 - (short)local_5c) * 0x10000) / iVar25);
      }
      uVar33 = iVar16 << 0x10;
      if (iVar15 < iVar6) {
        iVar6 = iVar6 - iVar15;
        uVar8 = uVar33;
        while (iVar15 = iVar15 + -1, -1 < iVar15) {
          uVar33 = uVar33 + local_74;
          uVar8 = uVar8 + local_7c;
          iVar21 = iVar21 + local_78;
          iVar23 = iVar23 + uVar9;
          iVar25 = ((int)uVar33 >> 0x10) - ((int)uVar8 >> 0x10);
          if (iVar25 < 0) {
            local_28 = (short)iVar23;
            puVar32 = (ushort *)(iVar10 + ((int)uVar8 >> 0x10) * 2 + iVar25 * 2);
            uVar27 = *(uint *)(DAT_10079224 + ((uVar33 & 0x70000) >> 0x10) * 4) ^ uVar17 & 0xff;
            local_54 = iVar21;
            do {
              if ((uVar27 & 0xff) < uVar34) {
                iVar5 = local_54 + (uVar27 & 0xff);
                local_68 = (ushort)((uint)iVar5 >> 8);
                *puVar32 = (ushort)(CONCAT12((char)((uint)iVar5 >> 0x18),local_68 << 0xb) >> 5) |
                           local_28 >> 8;
              }
              local_28 = local_28 + sVar13;
              uVar27 = uVar27 ^ uVar27 >> 6;
              puVar32 = puVar32 + 1;
              local_54 = local_54 + local_6c;
              iVar25 = iVar25 + 1;
            } while (iVar25 < 0);
          }
          iVar10 = iVar10 + iVar2;
          uVar17 = uVar17 ^ uVar17 >> 6;
        }
        uVar33 = iVar29 << 0x10;
        iVar31 = iVar31 - iVar29;
        if (iVar6 == 1) {
          local_74 = iVar31 * 0x10000;
        }
        else if (iVar6 == 2) {
          local_74 = iVar31 * 0x8000;
        }
        else if (((iVar6 < 0x20) && (-0x20 < iVar31)) && (iVar31 < 0x20)) {
          local_74 = *(int *)(iVar18 + (iVar31 * 0x20 + iVar6) * 4);
        }
        else if (iVar31 < 0) {
          local_74 = (iVar31 * 0x10000) / iVar6;
        }
        else {
          local_74 = (iVar31 * 0x10000) / iVar6;
        }
        if ((uVar4 == uVar12) || (iVar6 == 1)) {
          iVar15 = local_48 - local_44;
        }
        else if (iVar6 == 2) {
          iVar15 = (int)(local_48 - local_44) >> 1;
        }
        else {
          iVar15 = (int)(local_48 - local_44) / iVar6;
        }
        local_78 = iVar15 << 0x10;
        if ((local_30 == local_50) || (iVar6 == 1)) {
          uVar9 = local_40 + uVar24 * -0x100;
        }
        else if (iVar6 == 2) {
          uVar9 = (int)(local_40 + uVar24 * -0x100) >> 1;
        }
        else {
          uVar9 = (int)(local_40 + uVar24 * -0x100) / iVar6;
        }
        if (uVar9 != 0) {
          local_78 = (local_78 | uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
        }
        local_5c = 0;
        if ((sVar19 == sVar28) || (iVar6 == 1)) {
          uVar11 = local_38 + uVar11 * -0x100;
        }
        else if (iVar6 == 2) {
          uVar11 = (int)(local_38 + uVar11 * -0x100) >> 1;
        }
        else {
          uVar11 = (int)(local_38 + uVar11 * -0x100) / iVar6;
        }
        iVar25 = iVar21;
        iVar5 = iVar23;
        iVar15 = iVar6;
        if (uVar11 != 0) {
          local_5c = uVar11 & 0xffff;
        }
      }
      else {
        iVar15 = iVar15 - iVar6;
        uVar11 = uVar33;
        while (iVar6 = iVar6 + -1, -1 < iVar6) {
          uVar33 = uVar33 + local_74;
          uVar11 = uVar11 + local_7c;
          iVar21 = iVar21 + local_78;
          iVar23 = iVar23 + uVar9;
          iVar25 = ((int)uVar33 >> 0x10) - ((int)uVar11 >> 0x10);
          if (iVar25 < 0) {
            local_28 = (short)iVar23;
            puVar32 = (ushort *)(iVar10 + ((int)uVar11 >> 0x10) * 2 + iVar25 * 2);
            uVar8 = *(uint *)(DAT_10079224 + ((uVar33 & 0x70000) >> 0x10) * 4) ^ uVar17 & 0xff;
            local_54 = iVar21;
            do {
              if ((uVar8 & 0xff) < uVar34) {
                iVar5 = (uVar8 & 0xff) + local_54;
                local_68 = (ushort)((uint)iVar5 >> 8);
                local_68 = (ushort)(CONCAT12((char)((uint)iVar5 >> 0x18),local_68 << 0xb) >> 5) |
                           local_28 >> 8;
                *puVar32 = local_68;
              }
              local_28 = local_28 + sVar13;
              puVar32 = puVar32 + 1;
              uVar8 = uVar8 ^ uVar8 >> 6;
              local_54 = local_54 + local_6c;
              iVar25 = iVar25 + 1;
            } while (iVar25 < 0);
          }
          iVar10 = iVar10 + iVar2;
          uVar17 = uVar17 ^ uVar17 >> 6;
        }
        if (iVar15 == 0) {
          return;
        }
        uVar8 = iVar31 << 0x10;
        iVar29 = iVar29 - iVar31;
        iVar25 = iVar21;
        iVar5 = iVar23;
        local_5c = uVar9;
        if (iVar15 == 1) {
          local_7c = iVar29 * 0x10000;
        }
        else if (iVar15 == 2) {
          local_7c = iVar29 * 0x8000;
        }
        else if (((iVar15 < 0x20) && (-0x20 < iVar29)) && (iVar29 < 0x20)) {
          local_7c = *(int *)(iVar18 + (iVar29 * 0x20 + iVar15) * 4);
        }
        else if (iVar29 < 0) {
          local_7c = (iVar29 * 0x10000) / iVar15;
        }
        else {
          local_7c = (iVar29 * 0x10000) / iVar15;
        }
      }
    }
  }
  while (-1 < iVar15 + -1) {
    uVar33 = uVar33 + local_74;
    uVar8 = uVar8 + local_7c;
    iVar21 = ((int)uVar33 >> 0x10) - ((int)uVar8 >> 0x10);
    if (iVar21 < 0) {
      local_28 = (short)(iVar5 + local_5c);
      puVar32 = (ushort *)(iVar10 + ((int)uVar8 >> 0x10) * 2 + iVar21 * 2);
      uVar11 = *(uint *)(DAT_10079224 + ((uVar33 & 0x70000) >> 0x10) * 4) ^ uVar17 & 0xff;
      local_54 = iVar25 + local_78;
      do {
        if ((uVar11 & 0xff) < uVar34) {
          iVar23 = local_54 + (uVar11 & 0xff);
          local_68 = (ushort)((uint)iVar23 >> 8);
          *puVar32 = (ushort)(CONCAT12((char)((uint)iVar23 >> 0x18),local_68 << 0xb) >> 5) |
                     local_28 >> 8;
        }
        local_28 = local_28 + sVar13;
        uVar11 = uVar11 ^ uVar11 >> 6;
        puVar32 = puVar32 + 1;
        local_54 = local_54 + local_6c;
        iVar21 = iVar21 + 1;
      } while (iVar21 < 0);
    }
    iVar10 = iVar10 + iVar2;
    uVar17 = uVar17 ^ uVar17 >> 6;
    iVar25 = iVar25 + local_78;
    iVar5 = iVar5 + local_5c;
    iVar15 = iVar15 + -1;
  }
  return;
}


