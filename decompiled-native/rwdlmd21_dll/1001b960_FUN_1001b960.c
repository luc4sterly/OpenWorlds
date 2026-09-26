// 1001b960 FUN_1001b960 [Global]
// programa: rwdlmd21.dll

void FUN_1001b960(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort *puVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int local_44;
  int local_40;
  int local_34;
  int local_2c;
  int local_24;
  
  iVar2 = DAT_10089ef4;
  iVar1 = DAT_10089ddc;
  iVar9 = param_3;
  iVar17 = param_4;
  iVar8 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar9 = param_2;
      iVar17 = param_3;
      iVar8 = param_4;
    }
LAB_1001b996:
    param_2 = iVar17;
    param_4 = iVar9;
    param_3 = iVar8;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001b996;
  iVar12 = (int)*(short *)(param_2 + 0x1e);
  local_44 = *(short *)(param_3 + 0x1e) - iVar12;
  iVar3 = (int)*(short *)(param_3 + 0x1a);
  local_34 = (int)*(short *)(param_2 + 0x1a);
  iVar18 = (int)*(short *)(param_4 + 0x1a);
  iVar6 = *(int *)(param_2 + 0x20);
  iVar9 = *(int *)(param_4 + 0x20);
  iVar17 = *(int *)(param_3 + 0x20);
  iVar4 = iVar12 * DAT_10089ef4 + DAT_10087238;
  uVar5 = *(uint *)(*param_1 + 8);
  uVar10 = (ushort)*(byte *)((param_1[2] >> 0x10) * 0x20 + ((uVar5 & 0x7c0) >> 6) + 0x400 +
                            DAT_10087248) << 6 |
           (ushort)*(byte *)((param_1[1] >> 0x10) * 0x20 + ((uVar5 & 0xf800) >> 0xb) + DAT_10087248)
           << 0xb | (ushort)*(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar5 & 0x1f) + 0x800 +
                                     DAT_10087248);
  iVar13 = DAT_1008723c + 0x1000;
  uVar5 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar8 = *(int *)(DAT_10087240 + iVar12 * 4);
  if (local_44 < 1) {
    iVar19 = local_34 - iVar3;
    if (iVar19 < 1) {
      return;
    }
    local_44 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_44 == 0) {
      return;
    }
    local_40 = iVar18 - iVar3;
    if (local_44 == 1) {
      local_40 = local_40 * 0x10000;
    }
    else if (local_44 == 2) {
      local_40 = local_40 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < local_40)) && (local_40 < 0x20)) {
      local_40 = *(int *)(iVar13 + (local_40 * 0x20 + local_44) * 4);
    }
    else if (local_40 < 0) {
      local_40 = (local_40 * 0x10000) / local_44;
    }
    else {
      local_40 = (local_40 * 0x10000) / local_44;
    }
    iVar18 = iVar18 - local_34;
    if (local_44 == 1) {
      iVar20 = iVar18 * 0x10000;
    }
    else if (local_44 == 2) {
      iVar20 = iVar18 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
      iVar20 = *(int *)(iVar13 + (iVar18 * 0x20 + local_44) * 4);
    }
    else if (iVar18 < 0) {
      iVar20 = (iVar18 * 0x10000) / local_44;
    }
    else {
      iVar20 = (iVar18 * 0x10000) / local_44;
    }
    if ((iVar17 == iVar6) || (iVar19 == 1)) {
      iVar19 = iVar6 - iVar17;
    }
    else if (iVar19 == 2) {
      iVar19 = iVar6 - iVar17 >> 1;
    }
    else {
      iVar19 = (iVar6 - iVar17) / iVar19;
    }
    iVar6 = iVar17;
    iVar18 = local_34;
    if ((iVar9 == iVar17) || (local_44 == 1)) {
      local_2c = iVar9 - iVar17;
    }
    else if (local_44 == 2) {
      local_2c = iVar9 - iVar17 >> 1;
    }
    else {
      local_2c = (iVar9 - iVar17) / local_44;
    }
  }
  else {
    local_40 = iVar3 - local_34;
    if (local_44 == 1) {
      local_40 = local_40 * 0x10000;
    }
    else if (local_44 == 2) {
      local_40 = local_40 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < local_40)) && (local_40 < 0x20)) {
      local_40 = *(int *)(iVar13 + (local_40 * 0x20 + local_44) * 4);
    }
    else if (local_40 < 0) {
      local_40 = (local_40 * 0x10000) / local_44;
    }
    else {
      local_40 = (local_40 * 0x10000) / local_44;
    }
    iVar12 = *(short *)(param_4 + 0x1e) - iVar12;
    if (0 < iVar12) {
      iVar20 = iVar18 - local_34;
      if (iVar12 == 1) {
        iVar20 = iVar20 * 0x10000;
      }
      else if (iVar12 == 2) {
        iVar20 = iVar20 * 0x8000;
      }
      else if (((iVar12 < 0x20) && (-0x20 < iVar20)) && (iVar20 < 0x20)) {
        iVar20 = *(int *)(iVar13 + (iVar20 * 0x20 + iVar12) * 4);
      }
      else if (iVar20 < 0) {
        iVar20 = (iVar20 * 0x10000) / iVar12;
      }
      else {
        iVar20 = (iVar20 * 0x10000) / iVar12;
      }
      if (iVar20 - local_40 < 1) {
        return;
      }
      if ((iVar17 == iVar6) || (local_44 == 1)) {
        local_2c = iVar17 - iVar6;
      }
      else if (local_44 == 2) {
        local_2c = iVar17 - iVar6 >> 1;
      }
      else {
        local_2c = (iVar17 - iVar6) / local_44;
      }
      if ((iVar9 == iVar6) || (iVar12 == 1)) {
        iVar19 = iVar9 - iVar6;
      }
      else if (iVar12 == 2) {
        iVar19 = iVar9 - iVar6 >> 1;
      }
      else {
        iVar19 = (iVar9 - iVar6) / iVar12;
      }
      iVar19 = iVar19 - local_2c;
      if ((iVar19 != 0) && (iVar14 = iVar20 - local_40 >> 6, iVar14 != 0)) {
        iVar19 = iVar19 / iVar14 << 10;
      }
      local_34 = local_34 << 0x10;
      if (local_44 < iVar12) {
        iVar12 = iVar12 - local_44;
        iVar6 = uVar5 + iVar6;
        local_24 = local_34;
        while (local_44 = local_44 + -1, -1 < local_44) {
          local_34 = local_34 + local_40;
          local_24 = local_24 + iVar20;
          iVar6 = iVar6 + local_2c;
          iVar15 = local_24 >> 0x10;
          iVar14 = (local_34 >> 0x10) - iVar15;
          if (iVar14 < 0) {
            puVar16 = (ushort *)(iVar8 + iVar15 * 2 + iVar14 * 2);
            puVar7 = (ushort *)(iVar4 + iVar15 * 2 + iVar14 * 2);
            iVar15 = iVar6;
            do {
              uVar11 = (ushort)((uint)iVar15 >> 0x10);
              if (*puVar7 < uVar11) {
                *puVar7 = uVar11;
                *puVar16 = uVar10;
              }
              iVar15 = iVar15 + iVar19;
              puVar16 = puVar16 + 1;
              puVar7 = puVar7 + 1;
              iVar14 = iVar14 + 1;
            } while (iVar14 < 0);
          }
          iVar8 = iVar8 + iVar1;
          iVar4 = iVar4 + iVar2;
        }
        local_34 = iVar3 << 0x10;
        iVar18 = iVar18 - iVar3;
        if (iVar12 == 1) {
          local_40 = iVar18 * 0x10000;
        }
        else if (iVar12 == 2) {
          local_40 = iVar18 * 0x8000;
        }
        else if (((iVar12 < 0x20) && (-0x20 < iVar18)) && (iVar18 < 0x20)) {
          local_40 = *(int *)(iVar13 + (iVar18 * 0x20 + iVar12) * 4);
        }
        else if (iVar18 < 0) {
          local_40 = (iVar18 * 0x10000) / iVar12;
        }
        else {
          local_40 = (iVar18 * 0x10000) / iVar12;
        }
        local_44 = iVar12;
        if (iVar9 == iVar17) {
          local_2c = iVar9 - iVar17;
        }
        else if (iVar12 == 1) {
          local_2c = iVar9 - iVar17;
        }
        else if (iVar12 == 2) {
          local_2c = iVar9 - iVar17 >> 1;
        }
        else {
          local_2c = (iVar9 - iVar17) / iVar12;
        }
      }
      else {
        local_44 = local_44 - iVar12;
        iVar6 = uVar5 + iVar6;
        iVar9 = local_34;
        while (iVar12 = iVar12 + -1, -1 < iVar12) {
          local_34 = local_34 + local_40;
          iVar9 = iVar9 + iVar20;
          iVar6 = iVar6 + local_2c;
          iVar14 = iVar9 >> 0x10;
          iVar17 = (local_34 >> 0x10) - iVar14;
          if (iVar17 < 0) {
            puVar16 = (ushort *)(iVar4 + iVar14 * 2 + iVar17 * 2);
            puVar7 = (ushort *)(iVar8 + iVar14 * 2 + iVar17 * 2);
            iVar14 = iVar6;
            do {
              uVar11 = (ushort)((uint)iVar14 >> 0x10);
              if (*puVar16 < uVar11) {
                *puVar16 = uVar11;
                *puVar7 = uVar10;
              }
              iVar14 = iVar14 + iVar19;
              puVar7 = puVar7 + 1;
              puVar16 = puVar16 + 1;
              iVar17 = iVar17 + 1;
            } while (iVar17 < 0);
          }
          iVar8 = iVar8 + iVar1;
          iVar4 = iVar4 + iVar2;
        }
        if (local_44 == 0) {
          return;
        }
        local_24 = iVar18 << 0x10;
        iVar3 = iVar3 - iVar18;
        if (local_44 == 1) {
          iVar20 = iVar3 * 0x10000;
        }
        else if (local_44 == 2) {
          iVar20 = iVar3 * 0x8000;
        }
        else if (((local_44 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
          iVar20 = *(int *)(iVar13 + (iVar3 * 0x20 + local_44) * 4);
        }
        else if (iVar3 < 0) {
          iVar20 = (iVar3 * 0x10000) / local_44;
        }
        else {
          iVar20 = (iVar3 * 0x10000) / local_44;
        }
      }
      goto joined_r0x1001c1ec;
    }
    iVar19 = iVar18 - local_34;
    if (iVar19 < 1) {
      return;
    }
    iVar3 = iVar3 - iVar18;
    if (local_44 == 1) {
      iVar20 = iVar3 * 0x10000;
    }
    else if (local_44 == 2) {
      iVar20 = iVar3 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      iVar20 = *(int *)(iVar13 + (iVar3 * 0x20 + local_44) * 4);
    }
    else if (iVar3 < 0) {
      iVar20 = (iVar3 * 0x10000) / local_44;
    }
    else {
      iVar20 = (iVar3 * 0x10000) / local_44;
    }
    if ((iVar9 == iVar6) || (iVar19 == 1)) {
      iVar19 = iVar9 - iVar6;
    }
    else if (iVar19 == 2) {
      iVar19 = iVar9 - iVar6 >> 1;
    }
    else {
      iVar19 = (iVar9 - iVar6) / iVar19;
    }
    iVar3 = local_34;
    if ((iVar17 == iVar6) || (local_44 == 1)) {
      local_2c = iVar17 - iVar6;
    }
    else if (local_44 == 2) {
      local_2c = iVar17 - iVar6 >> 1;
    }
    else {
      local_2c = (iVar17 - iVar6) / local_44;
    }
  }
  local_24 = iVar18 << 0x10;
  local_34 = iVar3 << 0x10;
  iVar6 = uVar5 + iVar6;
joined_r0x1001c1ec:
  while (-1 < local_44 + -1) {
    local_34 = local_34 + local_40;
    local_24 = local_24 + iVar20;
    iVar6 = iVar6 + local_2c;
    iVar17 = local_24 >> 0x10;
    iVar9 = (local_34 >> 0x10) - iVar17;
    if (iVar9 < 0) {
      puVar16 = (ushort *)(iVar8 + iVar17 * 2 + iVar9 * 2);
      puVar7 = (ushort *)(iVar4 + iVar17 * 2 + iVar9 * 2);
      iVar17 = iVar6;
      do {
        uVar11 = (ushort)((uint)iVar17 >> 0x10);
        if (*puVar7 < uVar11) {
          *puVar7 = uVar11;
          *puVar16 = uVar10;
        }
        iVar17 = iVar17 + iVar19;
        puVar16 = puVar16 + 1;
        puVar7 = puVar7 + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    iVar8 = iVar8 + iVar1;
    iVar4 = iVar4 + iVar2;
    local_44 = local_44 + -1;
  }
  return;
}


