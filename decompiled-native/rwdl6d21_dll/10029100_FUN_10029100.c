// 10029100 FUN_10029100 [Global]
// program: RWDL6D21.DLL

void FUN_10029100(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  int iVar33;
  uint uVar34;
  uint uVar35;
  ushort uVar36;
  ushort *puVar37;
  ushort uVar38;
  ushort *puVar40;
  int local_a4;
  int local_a0;
  uint local_98;
  int local_94;
  uint local_90;
  int local_8c;
  uint local_88;
  short local_84;
  uint local_7c;
  int local_78;
  uint local_70;
  int local_6c;
  uint local_68;
  short local_64;
  int local_60;
  short local_5c;
  uint local_50;
  uint local_4c;
  int local_44;
  short local_3c;
  int local_38;
  int local_34;
  uint uVar16;
  short sVar39;
  
  iVar5 = DAT_1007beb0;
  iVar4 = DAT_1007bda4;
  iVar25 = param_3;
  iVar31 = param_4;
  iVar20 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar25 = param_2;
      iVar31 = param_3;
      iVar20 = param_4;
    }
LAB_1002913f:
    param_2 = iVar31;
    param_3 = iVar20;
    param_4 = iVar25;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1002913f;
  uVar21 = (uint)*(short *)(param_2 + 0x1e);
  local_a4 = (int)*(short *)(param_3 + 0x1e) - uVar21;
  iVar8 = (int)*(short *)(param_2 + 0x1a);
  uVar22 = *(uint *)(*param_1 + 8);
  uVar9 = (uVar22 & 0xf800) >> 0xb;
  uVar10 = (uVar22 & 0x7c0) >> 6;
  local_88 = (uint)*(byte *)((*(int *)(param_2 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 +
                            uVar10);
  uVar18 = local_88;
  uVar32 = (uint)*(byte *)((*(int *)(param_2 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar9) << 0x10
  ;
  uVar22 = uVar22 & 0x1f;
  local_38 = (local_88 | uVar32) << 8;
  iVar19 = *(int *)(param_2 + 0x20);
  iVar26 = (int)*(short *)(param_3 + 0x1a);
  bVar1 = *(byte *)((*(int *)(param_2 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar22);
  uVar11 = (uint)bVar1;
  local_34 = uVar11 * 0x100;
  uVar27 = (uint)*(byte *)((*(int *)(param_3 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar9) << 0x10
  ;
  local_88 = (uint)*(byte *)((*(int *)(param_3 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 +
                            uVar10);
  uVar35 = local_88;
  iVar28 = (uVar27 | local_88) << 8;
  iVar33 = (int)*(short *)(param_4 + 0x1a);
  bVar2 = *(byte *)((*(int *)(param_3 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar22);
  uVar12 = (uint)bVar2;
  iVar13 = uVar12 * 0x100;
  iVar25 = *(int *)(param_3 + 0x20);
  uVar29 = (uint)*(byte *)((*(int *)(param_4 + 0x58) >> 0x10) * 0x20 + DAT_10079220 + uVar9) << 0x10
  ;
  uVar34 = (uint)*(byte *)((*(int *)(param_4 + 0x5c) >> 0x10) * 0x20 + DAT_10079220 + 0x400 + uVar10
                          );
  iVar30 = (uVar29 | uVar34) << 8;
  bVar3 = *(byte *)((*(int *)(param_4 + 0x60) >> 0x10) * 0x20 + DAT_10079220 + 0x800 + uVar22);
  sVar6 = (ushort)bVar3 << 8;
  iVar31 = *(int *)(param_4 + 0x20);
  iVar14 = uVar21 * DAT_1007beb0 + DAT_10079210;
  uVar23 = (uint)*(byte *)(*param_1 + 4);
  iVar15 = DAT_10079214 + 0x1000;
  uVar24 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar20 = *(int *)(DAT_10079218 + uVar21 * 4);
  uVar22 = *(uint *)(DAT_10079228 + (uVar21 & 7) * 4);
  local_8c._0_2_ = (short)local_38;
  local_5c = (short)iVar28;
  local_3c = (short)iVar30;
  local_84 = (short)local_34;
  uVar16 = iVar30 >> 0x10;
  uVar10 = iVar28 >> 0x10;
  uVar9 = local_38 >> 0x10;
  uVar36 = (ushort)(uVar32 >> 8);
  uVar38 = (ushort)(uVar27 >> 8);
  uVar7 = (ushort)(uVar29 >> 8);
  sVar39 = (short)iVar13;
  if (local_a4 < 1) {
    iVar30 = iVar8 - iVar26;
    if (iVar30 < 1) {
      return;
    }
    local_a4 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_a4 == 0) {
      return;
    }
    local_94 = iVar33 - iVar26;
    if (local_a4 == 1) {
      local_94 = local_94 * 0x10000;
    }
    else if (local_a4 == 2) {
      local_94 = local_94 * 0x8000;
    }
    else if (((local_a4 < 0x20) && (-0x20 < local_94)) && (local_94 < 0x20)) {
      local_94 = *(int *)(iVar15 + (local_94 * 0x20 + local_a4) * 4);
    }
    else if (local_94 < 0) {
      local_94 = (local_94 * 0x10000) / local_a4;
    }
    else {
      local_94 = (local_94 * 0x10000) / local_a4;
    }
    iVar33 = iVar33 - iVar8;
    if (local_a4 == 1) {
      local_a0 = iVar33 * 0x10000;
    }
    else if (local_a4 == 2) {
      local_a0 = iVar33 * 0x8000;
    }
    else if (((local_a4 < 0x20) && (-0x20 < iVar33)) && (iVar33 < 0x20)) {
      local_a0 = *(int *)(iVar15 + (iVar33 * 0x20 + local_a4) * 4);
    }
    else if (iVar33 < 0) {
      local_a0 = (iVar33 * 0x10000) / local_a4;
    }
    else {
      local_a0 = (iVar33 * 0x10000) / local_a4;
    }
    if ((iVar25 == iVar19) || (iVar30 == 1)) {
      local_78 = iVar19 - iVar25;
    }
    else if (iVar30 == 2) {
      local_78 = iVar19 - iVar25 >> 1;
    }
    else {
      local_78 = (iVar19 - iVar25) / iVar30;
    }
    if ((iVar31 == iVar25) || (local_a4 == 1)) {
      local_6c = iVar31 - iVar25;
    }
    else if (local_a4 == 2) {
      local_6c = iVar31 - iVar25 >> 1;
    }
    else {
      local_6c = (iVar31 - iVar25) / local_a4;
    }
    if ((uVar38 == uVar36) || (iVar30 == 1)) {
      iVar31 = (uVar9 & 0xffff) - (uVar10 & 0xffff);
    }
    else if (iVar30 == 2) {
      iVar31 = (int)((uVar9 & 0xffff) - (uVar10 & 0xffff)) >> 1;
    }
    else {
      iVar31 = (int)((uVar9 & 0xffff) - (uVar10 & 0xffff)) / iVar30;
    }
    uVar10 = uVar10 & 0xffff;
    if ((uVar7 == uVar38) || (local_a4 == 1)) {
      iVar19 = (uVar16 & 0xffff) - uVar10;
    }
    else if (local_a4 == 2) {
      iVar19 = (int)((uVar16 & 0xffff) - uVar10) >> 1;
    }
    else {
      iVar19 = (int)((uVar16 & 0xffff) - uVar10) / local_a4;
    }
    iVar33 = uVar18 * 0x100;
    if ((local_5c == (short)local_8c) || (iVar30 == 1)) {
      uVar18 = iVar33 + local_88 * -0x100;
    }
    else if (iVar30 == 2) {
      uVar18 = (int)(iVar33 + local_88 * -0x100) >> 1;
    }
    else {
      uVar18 = (int)(iVar33 + local_88 * -0x100) / iVar30;
    }
    local_90 = (iVar31 << 0x10 | uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
    iVar31 = uVar34 * 0x100;
    if ((local_3c == local_5c) || (local_a4 == 1)) {
      uVar18 = iVar31 + local_88 * -0x100;
    }
    else if (local_a4 == 2) {
      uVar18 = (int)(iVar31 + local_88 * -0x100) >> 1;
    }
    else {
      uVar18 = (int)(iVar31 + local_88 * -0x100) / local_a4;
    }
    local_98 = (iVar19 << 0x10 | uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
    if ((sVar39 == local_84) || (iVar30 == 1)) {
      local_64 = local_84 + (ushort)bVar2 * -0x100;
    }
    else if (iVar30 == 2) {
      local_64 = (short)((int)(local_34 + uVar12 * -0x100) >> 1);
    }
    else {
      local_64 = (short)((int)(local_34 + uVar12 * -0x100) / iVar30);
    }
    iVar31 = (uint)bVar3 * 0x100;
    local_38 = iVar28;
    local_34 = iVar13;
    iVar19 = iVar25;
    iVar33 = iVar8;
    if ((sVar6 == sVar39) || (local_a4 == 1)) {
      local_70 = iVar31 + uVar12 * -0x100;
    }
    else if (local_a4 == 2) {
      local_70 = (int)(iVar31 + uVar12 * -0x100) >> 1;
    }
    else {
      local_70 = (int)(iVar31 + uVar12 * -0x100) / local_a4;
    }
  }
  else {
    local_94 = iVar26 - iVar8;
    if (local_a4 == 1) {
      local_94 = local_94 * 0x10000;
    }
    else if (local_a4 == 2) {
      local_94 = local_94 * 0x8000;
    }
    else if (((local_a4 < 0x20) && (-0x20 < local_94)) && (local_94 < 0x20)) {
      local_94 = *(int *)(iVar15 + (local_94 * 0x20 + local_a4) * 4);
    }
    else if (local_94 < 0) {
      local_94 = (local_94 * 0x10000) / local_a4;
    }
    else {
      local_94 = (local_94 * 0x10000) / local_a4;
    }
    iVar28 = (int)*(short *)(param_4 + 0x1e) - uVar21;
    if (0 < iVar28) {
      local_a0 = iVar33 - iVar8;
      if (iVar28 == 1) {
        local_a0 = local_a0 * 0x10000;
      }
      else if (iVar28 == 2) {
        local_a0 = local_a0 * 0x8000;
      }
      else if (((iVar28 < 0x20) && (-0x20 < local_a0)) && (local_a0 < 0x20)) {
        local_a0 = *(int *)(iVar15 + (local_a0 * 0x20 + iVar28) * 4);
      }
      else if (local_a0 < 0) {
        local_a0 = (local_a0 * 0x10000) / iVar28;
      }
      else {
        local_a0 = (local_a0 * 0x10000) / iVar28;
      }
      iVar30 = local_a0 - local_94;
      if (iVar30 < 1) {
        return;
      }
      if ((uVar38 == uVar36) || (local_a4 == 1)) {
        iVar17 = (uint)uVar38 - (uVar9 & 0xffff);
      }
      else if (local_a4 == 2) {
        iVar17 = (int)((uint)uVar38 - (uVar9 & 0xffff)) >> 1;
      }
      else {
        iVar17 = (int)((uint)uVar38 - (uVar9 & 0xffff)) / local_a4;
      }
      local_4c = (uint)uVar38;
      uVar9 = uVar9 & 0xffff;
      if ((local_5c == (short)local_8c) || (local_a4 == 1)) {
        uVar10 = local_88 * 0x100 + uVar18 * -0x100;
      }
      else if (local_a4 == 2) {
        uVar10 = (int)(local_88 * 0x100 + uVar18 * -0x100) >> 1;
      }
      else {
        uVar10 = (int)(local_88 * 0x100 + uVar18 * -0x100) / local_a4;
      }
      local_98 = (iVar17 << 0x10 | uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
      if ((uVar7 == uVar36) || (iVar28 == 1)) {
        iVar17 = uVar7 - uVar9;
      }
      else if (iVar28 == 2) {
        iVar17 = (int)(uVar7 - uVar9) >> 1;
      }
      else {
        iVar17 = (int)(uVar7 - uVar9) / iVar28;
      }
      local_50 = (uint)uVar7;
      local_90 = iVar17 - (local_98 >> 0x10);
      if (local_90 != 0) {
        local_90 = (int)(local_90 * 0x10000) / iVar30 << 0x10;
      }
      if ((local_3c == (short)local_8c) || (iVar28 == 1)) {
        iVar17 = uVar34 * 0x100 + uVar18 * -0x100;
      }
      else if (iVar28 == 2) {
        iVar17 = (int)(uVar34 * 0x100 + uVar18 * -0x100) >> 1;
      }
      else {
        iVar17 = (int)(uVar34 * 0x100 + uVar18 * -0x100) / iVar28;
      }
      local_8c = uVar34 * 0x100;
      if (iVar17 - (short)local_98 != 0) {
        local_90 = local_90 | ((iVar17 - (short)local_98) * 0x10000) / iVar30 & 0xffffU;
        local_90 = local_90 + (local_90 & 0x8000) * -2;
      }
      if ((sVar39 == local_84) || (local_a4 == 1)) {
        uVar18 = iVar13 + uVar11 * -0x100;
      }
      else if (local_a4 == 2) {
        uVar18 = (int)(iVar13 + uVar11 * -0x100) >> 1;
      }
      else {
        uVar18 = (int)(iVar13 + uVar11 * -0x100) / local_a4;
      }
      uVar9 = uVar18 & 0xffff;
      local_64 = 0;
      if ((sVar6 == local_84) || (iVar28 == 1)) {
        local_44 = (uint)bVar3 * 0x100;
        iVar13 = local_44 + uVar11 * -0x100;
      }
      else if (iVar28 == 2) {
        local_44 = (uint)bVar3 * 0x100;
        iVar13 = (int)(local_44 + uVar11 * -0x100) >> 1;
      }
      else {
        local_44 = (uint)bVar3 * 0x100;
        iVar13 = (int)(local_44 + uVar11 * -0x100) / iVar28;
      }
      local_70._0_2_ = (short)uVar18;
      if (iVar13 - (short)local_70 != 0) {
        local_64 = (short)(((iVar13 - (short)local_70) * 0x10000) / iVar30);
      }
      if ((iVar25 == iVar19) || (local_a4 == 1)) {
        local_6c = iVar25 - iVar19;
      }
      else if (local_a4 == 2) {
        local_6c = iVar25 - iVar19 >> 1;
      }
      else {
        local_6c = (iVar25 - iVar19) / local_a4;
      }
      if ((iVar31 == iVar19) || (iVar28 == 1)) {
        local_78 = iVar31 - iVar19;
      }
      else if (iVar28 == 2) {
        local_78 = iVar31 - iVar19 >> 1;
      }
      else {
        local_78 = (iVar31 - iVar19) / iVar28;
      }
      local_78 = local_78 - local_6c;
      if ((local_78 != 0) && (iVar30 >> 6 != 0)) {
        local_78 = local_78 / (iVar30 >> 6) << 10;
      }
      local_7c = iVar8 << 0x10;
      if (local_a4 < iVar28) {
        iVar28 = iVar28 - local_a4;
        iVar19 = uVar24 + iVar19;
        iVar8 = local_34;
        local_68 = local_7c;
        while (local_a4 = local_a4 + -1, -1 < local_a4) {
          local_7c = local_7c + local_94;
          local_68 = local_68 + local_a0;
          local_38 = local_38 + local_98;
          iVar8 = iVar8 + uVar9;
          iVar19 = iVar19 + local_6c;
          iVar30 = (int)local_68 >> 0x10;
          iVar13 = ((int)local_7c >> 0x10) - iVar30;
          if (iVar13 < 0) {
            local_34._0_2_ = (short)iVar8;
            puVar40 = (ushort *)(iVar14 + iVar30 * 2 + iVar13 * 2);
            puVar37 = (ushort *)(iVar20 + iVar30 * 2 + iVar13 * 2);
            uVar18 = *(uint *)(DAT_10079224 + ((local_7c & 0x70000) >> 0x10) * 4) ^ uVar22 & 0xff;
            local_88 = local_38;
            local_60 = iVar19;
            do {
              if (((uVar18 & 0xff) < uVar23) &&
                 (uVar36 = (ushort)((uint)local_60 >> 0x10), *puVar40 < uVar36)) {
                *puVar40 = uVar36;
                iVar30 = local_88 + (uVar18 & 0xff);
                local_84 = (short)((uint)iVar30 >> 8);
                *puVar37 = (ushort)(CONCAT12((char)((uint)iVar30 >> 0x18),local_84 << 0xb) >> 5) |
                           (short)local_34 >> 8;
              }
              puVar37 = puVar37 + 1;
              uVar18 = uVar18 ^ uVar18 >> 6;
              puVar40 = puVar40 + 1;
              local_88 = local_88 + local_90;
              local_34._0_2_ = (short)local_34 + local_64;
              local_60 = local_60 + local_78;
              iVar13 = iVar13 + 1;
            } while (iVar13 < 0);
          }
          iVar20 = iVar20 + iVar4;
          iVar14 = iVar14 + iVar5;
          uVar22 = uVar22 ^ uVar22 >> 6;
        }
        local_7c = iVar26 << 0x10;
        iVar33 = iVar33 - iVar26;
        if (iVar28 == 1) {
          local_94 = iVar33 * 0x10000;
        }
        else if (iVar28 == 2) {
          local_94 = iVar33 * 0x8000;
        }
        else if (((iVar28 < 0x20) && (-0x20 < iVar33)) && (iVar33 < 0x20)) {
          local_94 = *(int *)(iVar15 + (iVar33 * 0x20 + iVar28) * 4);
        }
        else if (iVar33 < 0) {
          local_94 = (iVar33 * 0x10000) / iVar28;
        }
        else {
          local_94 = (iVar33 * 0x10000) / iVar28;
        }
        if ((uVar7 == uVar38) || (iVar28 == 1)) {
          iVar26 = local_50 - local_4c;
        }
        else if (iVar28 == 2) {
          iVar26 = (int)(local_50 - local_4c) >> 1;
        }
        else {
          iVar26 = (int)(local_50 - local_4c) / iVar28;
        }
        local_98 = iVar26 << 0x10;
        if ((local_3c == local_5c) || (iVar28 == 1)) {
          uVar18 = local_8c + uVar35 * -0x100;
        }
        else if (iVar28 == 2) {
          uVar18 = (int)(local_8c + uVar35 * -0x100) >> 1;
        }
        else {
          uVar18 = (int)(local_8c + uVar35 * -0x100) / iVar28;
        }
        if (uVar18 != 0) {
          local_98 = (local_98 | uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
        }
        local_70 = 0;
        if ((sVar6 == sVar39) || (iVar28 == 1)) {
          uVar18 = local_44 + uVar12 * -0x100;
        }
        else if (iVar28 == 2) {
          uVar18 = (int)(local_44 + uVar12 * -0x100) >> 1;
        }
        else {
          uVar18 = (int)(local_44 + uVar12 * -0x100) / iVar28;
        }
        if (uVar18 != 0) {
          local_70 = uVar18 & 0xffff;
        }
        local_34 = iVar8;
        local_a4 = iVar28;
        if (iVar31 == iVar25) {
          local_6c = iVar31 - iVar25;
        }
        else if (iVar28 == 1) {
          local_6c = iVar31 - iVar25;
        }
        else if (iVar28 == 2) {
          local_6c = iVar31 - iVar25 >> 1;
        }
        else {
          local_6c = (iVar31 - iVar25) / iVar28;
        }
      }
      else {
        local_a4 = local_a4 - iVar28;
        iVar19 = uVar24 + iVar19;
        iVar25 = local_34;
        uVar18 = local_7c;
        while (iVar28 = iVar28 + -1, -1 < iVar28) {
          local_7c = local_7c + local_94;
          uVar18 = uVar18 + local_a0;
          local_38 = local_38 + local_98;
          iVar25 = iVar25 + uVar9;
          iVar19 = iVar19 + local_6c;
          iVar31 = (int)uVar18 >> 0x10;
          iVar8 = ((int)local_7c >> 0x10) - iVar31;
          if (iVar8 < 0) {
            puVar40 = (ushort *)(iVar20 + iVar31 * 2 + iVar8 * 2);
            uVar35 = *(uint *)(DAT_10079224 + ((local_7c & 0x70000) >> 0x10) * 4) ^ uVar22 & 0xff;
            puVar37 = (ushort *)(iVar14 + iVar31 * 2 + iVar8 * 2);
            local_34._0_2_ = (short)iVar25;
            local_88 = local_38;
            local_60 = iVar19;
            do {
              if (((uVar35 & 0xff) < uVar23) &&
                 (uVar36 = (ushort)((uint)local_60 >> 0x10), *puVar37 < uVar36)) {
                *puVar37 = uVar36;
                iVar31 = local_88 + (uVar35 & 0xff);
                local_84 = (short)((uint)iVar31 >> 8);
                *puVar40 = (ushort)(CONCAT12((char)((uint)iVar31 >> 0x18),local_84 << 0xb) >> 5) |
                           (short)local_34 >> 8;
              }
              puVar40 = puVar40 + 1;
              uVar35 = uVar35 ^ uVar35 >> 6;
              puVar37 = puVar37 + 1;
              local_88 = local_88 + local_90;
              local_34._0_2_ = (short)local_34 + local_64;
              local_60 = local_60 + local_78;
              iVar8 = iVar8 + 1;
            } while (iVar8 < 0);
          }
          iVar20 = iVar20 + iVar4;
          iVar14 = iVar14 + iVar5;
          uVar22 = uVar22 ^ uVar22 >> 6;
        }
        if (local_a4 == 0) {
          return;
        }
        local_68 = iVar33 << 0x10;
        iVar26 = iVar26 - iVar33;
        local_34 = iVar25;
        local_70 = uVar9;
        if (local_a4 == 1) {
          local_a0 = iVar26 * 0x10000;
        }
        else if (local_a4 == 2) {
          local_a0 = iVar26 * 0x8000;
        }
        else if (((local_a4 < 0x20) && (-0x20 < iVar26)) && (iVar26 < 0x20)) {
          local_a0 = *(int *)(iVar15 + (iVar26 * 0x20 + local_a4) * 4);
        }
        else if (iVar26 < 0) {
          local_a0 = (iVar26 * 0x10000) / local_a4;
        }
        else {
          local_a0 = (iVar26 * 0x10000) / local_a4;
        }
      }
      goto joined_r0x1002a644;
    }
    iVar28 = iVar33 - iVar8;
    if (iVar28 < 1) {
      return;
    }
    iVar26 = iVar26 - iVar33;
    if (local_a4 == 1) {
      local_a0 = iVar26 * 0x10000;
    }
    else if (local_a4 == 2) {
      local_a0 = iVar26 * 0x8000;
    }
    else if (((local_a4 < 0x20) && (-0x20 < iVar26)) && (iVar26 < 0x20)) {
      local_a0 = *(int *)(iVar15 + (iVar26 * 0x20 + local_a4) * 4);
    }
    else if (iVar26 < 0) {
      local_a0 = (iVar26 * 0x10000) / local_a4;
    }
    else {
      local_a0 = (iVar26 * 0x10000) / local_a4;
    }
    if ((iVar31 == iVar19) || (iVar28 == 1)) {
      local_78 = iVar31 - iVar19;
    }
    else if (iVar28 == 2) {
      local_78 = iVar31 - iVar19 >> 1;
    }
    else {
      local_78 = (iVar31 - iVar19) / iVar28;
    }
    if ((iVar25 == iVar19) || (local_a4 == 1)) {
      local_6c = iVar25 - iVar19;
    }
    else if (local_a4 == 2) {
      local_6c = iVar25 - iVar19 >> 1;
    }
    else {
      local_6c = (iVar25 - iVar19) / local_a4;
    }
    if ((uVar7 == uVar36) || (iVar28 == 1)) {
      iVar25 = (uVar16 & 0xffff) - (uVar9 & 0xffff);
    }
    else if (iVar28 == 2) {
      iVar25 = (int)((uVar16 & 0xffff) - (uVar9 & 0xffff)) >> 1;
    }
    else {
      iVar25 = (int)((uVar16 & 0xffff) - (uVar9 & 0xffff)) / iVar28;
    }
    uVar9 = uVar9 & 0xffff;
    iVar31 = uVar34 * 0x100;
    if ((local_3c == (short)local_8c) || (iVar28 == 1)) {
      uVar35 = iVar31 + uVar18 * -0x100;
    }
    else if (iVar28 == 2) {
      uVar35 = (int)(iVar31 + uVar18 * -0x100) >> 1;
    }
    else {
      uVar35 = (int)(iVar31 + uVar18 * -0x100) / iVar28;
    }
    local_90 = (iVar25 << 0x10 | uVar35 & 0xffff) + (uVar35 & 0x8000) * -2;
    if ((uVar38 == uVar36) || (local_a4 == 1)) {
      iVar25 = (uVar10 & 0xffff) - uVar9;
    }
    else if (local_a4 == 2) {
      iVar25 = (int)((uVar10 & 0xffff) - uVar9) >> 1;
    }
    else {
      iVar25 = (int)((uVar10 & 0xffff) - uVar9) / local_a4;
    }
    iVar31 = local_88 * 0x100;
    if ((local_5c == (short)local_8c) || (local_a4 == 1)) {
      uVar18 = iVar31 + uVar18 * -0x100;
    }
    else if (local_a4 == 2) {
      uVar18 = (int)(iVar31 + uVar18 * -0x100) >> 1;
    }
    else {
      uVar18 = (int)(iVar31 + uVar18 * -0x100) / local_a4;
    }
    local_98 = (iVar25 << 0x10 | uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
    iVar25 = (uint)bVar3 * 0x100;
    if ((sVar6 == local_84) || (iVar28 == 1)) {
      local_64 = (short)iVar25 + (ushort)bVar1 * -0x100;
    }
    else if (iVar28 == 2) {
      local_64 = (short)((int)(iVar25 + uVar11 * -0x100) >> 1);
    }
    else {
      local_64 = (short)((int)(iVar25 + uVar11 * -0x100) / iVar28);
    }
    iVar26 = iVar8;
    if ((sVar39 == local_84) || (local_a4 == 1)) {
      local_70 = iVar13 + uVar11 * -0x100;
    }
    else if (local_a4 == 2) {
      local_70 = (int)(iVar13 + uVar11 * -0x100) >> 1;
    }
    else {
      local_70 = (int)(iVar13 + uVar11 * -0x100) / local_a4;
    }
  }
  local_70 = local_70 & 0xffff;
  local_68 = iVar33 << 0x10;
  local_7c = iVar26 << 0x10;
  iVar19 = uVar24 + iVar19;
joined_r0x1002a644:
  while (-1 < local_a4 + -1) {
    local_7c = local_7c + local_94;
    local_68 = local_68 + local_a0;
    local_38 = local_38 + local_98;
    iVar26 = local_34 + local_70;
    iVar19 = iVar19 + local_6c;
    iVar31 = (int)local_68 >> 0x10;
    iVar25 = ((int)local_7c >> 0x10) - iVar31;
    if (iVar25 < 0) {
      puVar40 = (ushort *)(iVar14 + iVar31 * 2 + iVar25 * 2);
      local_34._0_2_ = (short)iVar26;
      puVar37 = (ushort *)(iVar20 + iVar31 * 2 + iVar25 * 2);
      uVar18 = *(uint *)(DAT_10079224 + ((local_7c & 0x70000) >> 0x10) * 4) ^ uVar22 & 0xff;
      local_88 = local_38;
      local_60 = iVar19;
      do {
        if (((uVar18 & 0xff) < uVar23) &&
           (uVar36 = (ushort)((uint)local_60 >> 0x10), *puVar40 < uVar36)) {
          *puVar40 = uVar36;
          iVar31 = local_88 + (uVar18 & 0xff);
          local_84 = (short)((uint)iVar31 >> 8);
          *puVar37 = (ushort)(CONCAT12((char)((uint)iVar31 >> 0x18),local_84 << 0xb) >> 5) |
                     (short)local_34 >> 8;
        }
        puVar37 = puVar37 + 1;
        uVar18 = uVar18 ^ uVar18 >> 6;
        puVar40 = puVar40 + 1;
        local_88 = local_88 + local_90;
        local_34._0_2_ = (short)local_34 + local_64;
        local_60 = local_60 + local_78;
        iVar25 = iVar25 + 1;
      } while (iVar25 < 0);
    }
    iVar20 = iVar20 + iVar4;
    iVar14 = iVar14 + iVar5;
    uVar22 = uVar22 ^ uVar22 >> 6;
    local_34 = iVar26;
    local_a4 = local_a4 + -1;
  }
  return;
}


