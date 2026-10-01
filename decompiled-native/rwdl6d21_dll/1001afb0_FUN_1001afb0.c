// 1001afb0 FUN_1001afb0 [Global]
// program: RWDL6D21.DLL

void FUN_1001afb0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  ushort *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  ushort *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int local_54;
  int local_4c;
  int local_3c;
  int local_34;
  
  iVar2 = DAT_1007beb0;
  iVar1 = DAT_1007bda4;
  iVar20 = param_3;
  iVar10 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar20 = param_2;
      param_2 = param_4;
      iVar10 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1001afe8;
  param_4 = iVar20;
  param_3 = param_2;
  param_2 = iVar10;
LAB_1001afe8:
  uVar4 = (uint)*(short *)(param_2 + 0x1e);
  iVar14 = (int)*(short *)(param_3 + 0x1e) - uVar4;
  iVar15 = (int)*(short *)(param_2 + 0x1a);
  iVar5 = (int)*(short *)(param_3 + 0x1a);
  iVar20 = *(int *)(param_2 + 0x20);
  iVar10 = *(int *)(param_3 + 0x20);
  iVar23 = *(int *)(param_4 + 0x20);
  iVar16 = (int)*(short *)(param_4 + 0x1a);
  iVar6 = uVar4 * DAT_1007beb0 + DAT_10079210;
  uVar7 = (uint)*(byte *)(*param_1 + 4);
  uVar18 = *(uint *)(*param_1 + 8);
  uVar11 = (ushort)*(byte *)((param_1[2] >> 0x10) * 0x20 + ((uVar18 & 0x7c0) >> 6) + 0x400 +
                            DAT_10079220) << 6 |
           (ushort)*(byte *)((param_1[1] >> 0x10) * 0x20 + ((uVar18 & 0xf800) >> 0xb) + DAT_10079220
                            ) << 0xb |
           (ushort)*(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar18 & 0x1f) + 0x800 + DAT_10079220);
  iVar8 = DAT_10079214 + 0x1000;
  uVar12 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar9 = *(int *)(DAT_10079218 + uVar4 * 4);
  uVar18 = *(uint *)(DAT_10079228 + (uVar4 & 7) * 4);
  if (iVar14 < 1) {
    local_3c = iVar15 - iVar5;
    if (local_3c < 1) {
      return;
    }
    iVar14 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iVar14 == 0) {
      return;
    }
    local_4c = iVar16 - iVar5;
    if (iVar14 == 1) {
      local_4c = local_4c * 0x10000;
    }
    else if (iVar14 == 2) {
      local_4c = local_4c * 0x8000;
    }
    else if (((iVar14 < 0x20) && (-0x20 < local_4c)) && (local_4c < 0x20)) {
      local_4c = *(int *)(iVar8 + (local_4c * 0x20 + iVar14) * 4);
    }
    else if (local_4c < 0) {
      local_4c = (local_4c * 0x10000) / iVar14;
    }
    else {
      local_4c = (local_4c * 0x10000) / iVar14;
    }
    iVar16 = iVar16 - iVar15;
    if (iVar14 == 1) {
      local_54 = iVar16 * 0x10000;
    }
    else if (iVar14 == 2) {
      local_54 = iVar16 * 0x8000;
    }
    else if (((iVar14 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      local_54 = *(int *)(iVar8 + (iVar16 * 0x20 + iVar14) * 4);
    }
    else if (iVar16 < 0) {
      local_54 = (iVar16 * 0x10000) / iVar14;
    }
    else {
      local_54 = (iVar16 * 0x10000) / iVar14;
    }
    if ((iVar10 == iVar20) || (local_3c == 1)) {
      local_3c = iVar20 - iVar10;
    }
    else if (local_3c == 2) {
      local_3c = iVar20 - iVar10 >> 1;
    }
    else {
      local_3c = (iVar20 - iVar10) / local_3c;
    }
    if ((iVar23 == iVar10) || (iVar14 == 1)) {
      local_34 = iVar23 - iVar10;
    }
    else if (iVar14 == 2) {
      local_34 = iVar23 - iVar10 >> 1;
    }
    else {
      local_34 = (iVar23 - iVar10) / iVar14;
    }
    uVar17 = iVar15 << 0x10;
    uVar4 = iVar5 << 0x10;
    iVar20 = iVar10 + uVar12;
  }
  else {
    local_4c = iVar5 - iVar15;
    if (iVar14 == 1) {
      local_4c = local_4c * 0x10000;
    }
    else if (iVar14 == 2) {
      local_4c = local_4c * 0x8000;
    }
    else if (((iVar14 < 0x20) && (-0x20 < local_4c)) && (local_4c < 0x20)) {
      local_4c = *(int *)(iVar8 + (local_4c * 0x20 + iVar14) * 4);
    }
    else if (local_4c < 0) {
      local_4c = (local_4c * 0x10000) / iVar14;
    }
    else {
      local_4c = (local_4c * 0x10000) / iVar14;
    }
    iVar21 = (int)*(short *)(param_4 + 0x1e) - uVar4;
    if (iVar21 < 1) {
      local_3c = iVar16 - iVar15;
      if (local_3c < 1) {
        return;
      }
      iVar5 = iVar5 - iVar16;
      if (iVar14 == 1) {
        local_54 = iVar5 * 0x10000;
      }
      else if (iVar14 == 2) {
        local_54 = iVar5 * 0x8000;
      }
      else if (((iVar14 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
        local_54 = *(int *)(iVar8 + (iVar5 * 0x20 + iVar14) * 4);
      }
      else if (iVar5 < 0) {
        local_54 = (iVar5 * 0x10000) / iVar14;
      }
      else {
        local_54 = (iVar5 * 0x10000) / iVar14;
      }
      if ((iVar23 == iVar20) || (local_3c == 1)) {
        local_3c = iVar23 - iVar20;
      }
      else if (local_3c == 2) {
        local_3c = iVar23 - iVar20 >> 1;
      }
      else {
        local_3c = (iVar23 - iVar20) / local_3c;
      }
      if ((iVar10 == iVar20) || (iVar14 == 1)) {
        local_34 = iVar10 - iVar20;
      }
      else if (iVar14 == 2) {
        local_34 = iVar10 - iVar20 >> 1;
      }
      else {
        local_34 = (iVar10 - iVar20) / iVar14;
      }
      uVar4 = iVar15 << 0x10;
      iVar20 = iVar20 + uVar12;
      uVar17 = iVar16 << 0x10;
    }
    else {
      local_54 = iVar16 - iVar15;
      if (iVar21 == 1) {
        local_54 = local_54 * 0x10000;
      }
      else if (iVar21 == 2) {
        local_54 = local_54 * 0x8000;
      }
      else if (((iVar21 < 0x20) && (-0x20 < local_54)) && (local_54 < 0x20)) {
        local_54 = *(int *)(iVar8 + (local_54 * 0x20 + iVar21) * 4);
      }
      else if (local_54 < 0) {
        local_54 = (local_54 * 0x10000) / iVar21;
      }
      else {
        local_54 = (local_54 * 0x10000) / iVar21;
      }
      if (local_54 - local_4c < 1) {
        return;
      }
      if ((iVar10 == iVar20) || (iVar14 == 1)) {
        local_34 = iVar10 - iVar20;
      }
      else if (iVar14 == 2) {
        local_34 = iVar10 - iVar20 >> 1;
      }
      else {
        local_34 = (iVar10 - iVar20) / iVar14;
      }
      if ((iVar23 == iVar20) || (iVar21 == 1)) {
        local_3c = iVar23 - iVar20;
      }
      else if (iVar21 == 2) {
        local_3c = iVar23 - iVar20 >> 1;
      }
      else {
        local_3c = (iVar23 - iVar20) / iVar21;
      }
      local_3c = local_3c - local_34;
      if ((local_3c != 0) && (iVar22 = local_54 - local_4c >> 6, iVar22 != 0)) {
        local_3c = local_3c / iVar22 << 10;
      }
      uVar4 = iVar15 << 0x10;
      if (iVar14 < iVar21) {
        iVar20 = iVar20 + uVar12;
        iVar21 = iVar21 - iVar14;
        uVar17 = uVar4;
        while (iVar14 = iVar14 + -1, -1 < iVar14) {
          uVar4 = uVar4 + local_4c;
          uVar17 = uVar17 + local_54;
          iVar20 = iVar20 + local_34;
          uVar12 = *(uint *)(DAT_10079224 + ((uVar4 & 0x70000) >> 0x10) * 4) ^ uVar18 & 0xff;
          iVar15 = (int)uVar17 >> 0x10;
          iVar22 = ((int)uVar4 >> 0x10) - iVar15;
          if (iVar22 < 0) {
            puVar19 = (ushort *)(iVar6 + iVar15 * 2 + iVar22 * 2);
            puVar13 = (ushort *)(iVar9 + iVar15 * 2 + iVar22 * 2);
            iVar15 = iVar20;
            do {
              if (((uVar12 & 0xff) < uVar7) &&
                 (uVar3 = (ushort)((uint)iVar15 >> 0x10), *puVar19 < uVar3)) {
                *puVar19 = uVar3;
                *puVar13 = uVar11;
              }
              puVar13 = puVar13 + 1;
              puVar19 = puVar19 + 1;
              uVar12 = uVar12 ^ uVar12 >> 6;
              iVar15 = iVar15 + local_3c;
              iVar22 = iVar22 + 1;
            } while (iVar22 < 0);
          }
          iVar9 = iVar9 + iVar1;
          iVar6 = iVar6 + iVar2;
          uVar18 = uVar18 ^ uVar18 >> 6;
        }
        uVar4 = iVar5 << 0x10;
        iVar16 = iVar16 - iVar5;
        if (iVar21 == 1) {
          local_4c = iVar16 * 0x10000;
        }
        else if (iVar21 == 2) {
          local_4c = iVar16 * 0x8000;
        }
        else if (((iVar21 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
          local_4c = *(int *)(iVar8 + (iVar16 * 0x20 + iVar21) * 4);
        }
        else if (iVar16 < 0) {
          local_4c = (iVar16 * 0x10000) / iVar21;
        }
        else {
          local_4c = (iVar16 * 0x10000) / iVar21;
        }
        iVar14 = iVar21;
        if (iVar23 == iVar10) {
          local_34 = iVar23 - iVar10;
        }
        else if (iVar21 == 1) {
          local_34 = iVar23 - iVar10;
        }
        else if (iVar21 == 2) {
          local_34 = iVar23 - iVar10 >> 1;
        }
        else {
          local_34 = (iVar23 - iVar10) / iVar21;
        }
      }
      else {
        iVar14 = iVar14 - iVar21;
        iVar20 = iVar20 + uVar12;
        uVar12 = uVar4;
        while (iVar21 = iVar21 + -1, -1 < iVar21) {
          uVar4 = uVar4 + local_4c;
          uVar12 = uVar12 + local_54;
          iVar20 = iVar20 + local_34;
          uVar17 = *(uint *)(DAT_10079224 + ((uVar4 & 0x70000) >> 0x10) * 4) ^ uVar18 & 0xff;
          iVar10 = (int)uVar12 >> 0x10;
          iVar23 = ((int)uVar4 >> 0x10) - iVar10;
          if (iVar23 < 0) {
            puVar19 = (ushort *)(iVar6 + iVar10 * 2 + iVar23 * 2);
            puVar13 = (ushort *)(iVar9 + iVar10 * 2 + iVar23 * 2);
            iVar10 = iVar20;
            do {
              if (((uVar17 & 0xff) < uVar7) &&
                 (uVar3 = (ushort)((uint)iVar10 >> 0x10), *puVar19 < uVar3)) {
                *puVar19 = uVar3;
                *puVar13 = uVar11;
              }
              puVar13 = puVar13 + 1;
              puVar19 = puVar19 + 1;
              uVar17 = uVar17 ^ uVar17 >> 6;
              iVar10 = iVar10 + local_3c;
              iVar23 = iVar23 + 1;
            } while (iVar23 < 0);
          }
          iVar9 = iVar9 + iVar1;
          iVar6 = iVar6 + iVar2;
          uVar18 = uVar18 ^ uVar18 >> 6;
        }
        if (iVar14 == 0) {
          return;
        }
        uVar17 = iVar16 << 0x10;
        iVar5 = iVar5 - iVar16;
        if (iVar14 == 1) {
          local_54 = iVar5 * 0x10000;
        }
        else if (iVar14 == 2) {
          local_54 = iVar5 * 0x8000;
        }
        else if (((iVar14 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
          local_54 = *(int *)(iVar8 + (iVar5 * 0x20 + iVar14) * 4);
        }
        else if (iVar5 < 0) {
          local_54 = (iVar5 * 0x10000) / iVar14;
        }
        else {
          local_54 = (iVar5 * 0x10000) / iVar14;
        }
      }
    }
  }
  while (-1 < iVar14 + -1) {
    uVar4 = uVar4 + local_4c;
    uVar17 = uVar17 + local_54;
    iVar20 = iVar20 + local_34;
    uVar12 = *(uint *)(DAT_10079224 + ((uVar4 & 0x70000) >> 0x10) * 4) ^ uVar18 & 0xff;
    iVar10 = (int)uVar17 >> 0x10;
    iVar23 = ((int)uVar4 >> 0x10) - iVar10;
    if (iVar23 < 0) {
      puVar19 = (ushort *)(iVar6 + iVar10 * 2 + iVar23 * 2);
      puVar13 = (ushort *)(iVar9 + iVar10 * 2 + iVar23 * 2);
      iVar10 = iVar20;
      do {
        if (((uVar12 & 0xff) < uVar7) && (uVar3 = (ushort)((uint)iVar10 >> 0x10), *puVar19 < uVar3))
        {
          *puVar19 = uVar3;
          *puVar13 = uVar11;
        }
        puVar13 = puVar13 + 1;
        puVar19 = puVar19 + 1;
        uVar12 = uVar12 ^ uVar12 >> 6;
        iVar10 = iVar10 + local_3c;
        iVar23 = iVar23 + 1;
      } while (iVar23 < 0);
    }
    iVar9 = iVar9 + iVar1;
    iVar6 = iVar6 + iVar2;
    uVar18 = uVar18 ^ uVar18 >> 6;
    iVar14 = iVar14 + -1;
  }
  return;
}


