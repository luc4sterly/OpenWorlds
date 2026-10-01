// 10012650 FUN_10012650 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10012650(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  longlong lVar23;
  undefined8 uVar24;
  int local_3c;
  uint local_20;
  uint local_10;
  
  iVar4 = param_3;
  iVar21 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar4 = param_2;
      param_2 = param_4;
      iVar21 = param_3;
    }
LAB_10012696:
    param_4 = iVar4;
    param_3 = param_2;
    param_2 = iVar21;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10012696;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar5 = (int)sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar14 = *(uint *)(param_2 + 100);
  uVar20 = *(uint *)(param_2 + 0x68);
  iVar4 = *(int *)(param_2 + 0x20);
  iVar19 = (int)*(short *)(param_3 + 0x1a);
  uVar15 = *(uint *)(param_3 + 100);
  uVar12 = *(uint *)(param_3 + 0x68);
  iVar3 = *(int *)(param_3 + 0x20);
  iVar16 = (int)*(short *)(param_4 + 0x1a);
  uVar22 = *(uint *)(param_4 + 100);
  uVar18 = *(uint *)(param_4 + 0x68);
  iVar21 = *(int *)(param_4 + 0x20);
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248 + 0x800;
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  if ((DAT_1008a100 == 0) || (*(float *)(param_1[0xf] + 0x14) <= _DAT_10089dd0)) {
    DAT_1008dbe0._4_4_ = 0;
  }
  else {
    lVar23 = __ftol();
    iVar6 = (int)lVar23;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    iVar6 = 0x10000 - iVar6;
    uVar17 = DAT_10089ef8 * iVar6;
    local_20 = DAT_10089ef0 * iVar6;
    uVar13 = iVar6 * DAT_10089de4;
    if (0x1e0000 < (int)(param_1[1] + uVar17)) {
      uVar17 = 0x1e0000 - param_1[1];
    }
    if (0x1e0000 < (int)(local_20 + param_1[2])) {
      local_20 = 0x1e0000 - param_1[2];
    }
    if (0x1e0000 < (int)(param_1[3] + uVar13)) {
      uVar13 = 0x1e0000 - param_1[3];
    }
    if ((int)uVar17 < 0) {
      uVar17 = 0;
    }
    if ((int)local_20 < 0) {
      local_20 = 0;
    }
    if ((int)uVar13 < 0) {
      uVar13 = 0;
    }
    uVar13 = (int)((local_20 & 0x1f8000) >> 5 | uVar17 & 0x1f0000) >> 5 |
             (uVar13 & 0x1f0000) >> 0x10;
    DAT_1008dbe0._4_4_ = uVar13 | uVar13 << 0x10;
  }
  iVar6 = DAT_1008723c + 0x1000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  DAT_1008dbe0._0_4_ = DAT_1008dbe0._4_4_;
  if (iVar5 < 1) {
    iVar5 = DAT_1008d280 - iVar19;
    if (iVar5 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    local_3c = -((int)sVar1 - (int)sVar2);
    if (local_3c == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar7 = iVar16 - iVar19;
    if (local_3c == 1) {
      DAT_1008d28c = iVar7 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1008d28c = iVar7 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar6 + (iVar7 * 0x20 + local_3c) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1008d28c = (iVar7 * 0x10000) / local_3c;
    }
    else {
      DAT_1008d28c = (iVar7 * 0x10000) / local_3c;
    }
    iVar16 = iVar16 - DAT_1008d280;
    if (local_3c == 1) {
      DAT_1008d288 = iVar16 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1008d288 = iVar16 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar6 + (iVar16 * 0x20 + local_3c) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1008d288 = (iVar16 * 0x10000) / local_3c;
    }
    else {
      DAT_1008d288 = (iVar16 * 0x10000) / local_3c;
    }
    if ((iVar3 == iVar4) || (iVar5 == 1)) {
      DAT_1008d2ec = iVar4 - iVar3;
    }
    else if (iVar5 == 2) {
      DAT_1008d2ec = iVar4 - iVar3 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar4 - iVar3) / iVar5;
    }
    if ((iVar3 == iVar21) || (local_3c == 1)) {
      DAT_1008d2e8 = iVar21 - iVar3;
    }
    else if (local_3c == 2) {
      DAT_1008d2e8 = iVar21 - iVar3 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar21 - iVar3) / local_3c;
    }
    if ((uVar15 == uVar14) || (iVar5 == 1)) {
      uVar14 = uVar14 - uVar15;
    }
    else if (iVar5 == 2) {
      uVar14 = (int)(uVar14 - uVar15) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar15) / iVar5;
    }
    if ((uVar22 == uVar15) || (local_3c == 1)) {
      uVar22 = uVar22 - uVar15;
    }
    else if (local_3c == 2) {
      uVar22 = (int)(uVar22 - uVar15) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar15) / local_3c;
    }
    if ((uVar12 == uVar20) || (iVar5 == 1)) {
      uVar20 = uVar20 - uVar12;
    }
    else if (iVar5 == 2) {
      uVar20 = (int)(uVar20 - uVar12) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar12) / iVar5;
    }
    if ((uVar18 == uVar12) || (local_3c == 1)) {
      uVar18 = uVar18 - uVar12;
    }
    else if (local_3c == 2) {
      uVar18 = (int)(uVar18 - uVar12) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar12) / local_3c;
    }
    DAT_1008d2c0 = (uVar12 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
    DAT_1008d2c8 = (uVar20 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar18 & 0xfffe) << 0xf | (uVar22 & 0xfffe) >> 1;
  }
  else {
    iVar7 = iVar19 - DAT_1008d280;
    if (iVar5 == 1) {
      DAT_1008d28c = iVar7 * 0x10000;
    }
    else if (iVar5 == 2) {
      DAT_1008d28c = iVar7 * 0x8000;
    }
    else if (((iVar5 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar6 + (iVar7 * 0x20 + iVar5) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1008d28c = (iVar7 * 0x10000) / iVar5;
    }
    else {
      DAT_1008d28c = (iVar7 * 0x10000) / iVar5;
    }
    iVar7 = (int)sVar2 - DAT_1008d284;
    if (0 < iVar7) {
      iVar8 = iVar16 - DAT_1008d280;
      iVar11 = iVar7;
      if (iVar7 == 1) {
        DAT_1008d288 = iVar8 * 0x10000;
      }
      else if (iVar7 == 2) {
        DAT_1008d288 = iVar8 * 0x8000;
      }
      else if (((iVar7 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar6 + (iVar8 * 0x20 + iVar7) * 4);
        iVar11 = iVar6;
      }
      else if (iVar8 < 0) {
        DAT_1008d288 = (iVar8 * 0x10000) / iVar7;
        iVar11 = (iVar8 * 0x10000) % iVar7;
      }
      else {
        DAT_1008d288 = (iVar8 * 0x10000) / iVar7;
        iVar11 = (iVar8 * 0x10000) % iVar7;
      }
      uVar13 = DAT_1008d288 - DAT_1008d28c;
      if ((int)uVar13 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      if ((uVar15 == uVar14) || (iVar5 == 1)) {
        uVar17 = uVar15 - uVar14;
      }
      else if (iVar5 == 2) {
        uVar17 = (int)(uVar15 - uVar14) >> 1;
      }
      else {
        uVar17 = (int)(uVar15 - uVar14) / iVar5;
        iVar11 = (int)(uVar15 - uVar14) % iVar5;
      }
      if ((uVar12 == uVar20) || (iVar5 == 1)) {
        uVar9 = uVar12 - uVar20;
      }
      else if (iVar5 == 2) {
        uVar9 = (int)(uVar12 - uVar20) >> 1;
      }
      else {
        uVar9 = (int)(uVar12 - uVar20) / iVar5;
        iVar11 = (int)(uVar12 - uVar20) % iVar5;
      }
      if ((uVar22 == uVar14) || (iVar7 == 1)) {
        iVar8 = uVar22 - uVar14;
      }
      else if (iVar7 == 2) {
        iVar8 = (int)(uVar22 - uVar14) >> 1;
      }
      else {
        iVar8 = (int)(uVar22 - uVar14) / iVar7;
        iVar11 = (int)(uVar22 - uVar14) % iVar7;
      }
      iVar8 = iVar8 - uVar17;
      uVar24 = CONCAT44(iVar11,iVar8);
      if (iVar8 != 0) {
        uVar24 = FUN_1006a324(iVar8,iVar11,iVar8,uVar13);
      }
      iVar11 = (int)((ulonglong)uVar24 >> 0x20);
      local_10 = (uint)uVar24;
      if ((uVar18 == uVar20) || (iVar7 == 1)) {
        iVar8 = uVar18 - uVar20;
      }
      else if (iVar7 == 2) {
        iVar8 = (int)(uVar18 - uVar20) >> 1;
      }
      else {
        iVar8 = (int)(uVar18 - uVar20) / iVar7;
        iVar11 = (int)(uVar18 - uVar20) % iVar7;
      }
      iVar8 = iVar8 - uVar9;
      uVar10 = 0;
      if (iVar8 != 0) {
        uVar24 = FUN_1006a324(iVar8,iVar11,iVar8,uVar13);
        uVar10 = (uint)uVar24;
      }
      if ((iVar3 == iVar4) || (iVar5 == 1)) {
        DAT_1008d2e8 = iVar3 - iVar4;
      }
      else if (iVar5 == 2) {
        DAT_1008d2e8 = iVar3 - iVar4 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar3 - iVar4) / iVar5;
      }
      if ((iVar4 == iVar21) || (iVar7 == 1)) {
        iVar11 = iVar21 - iVar4;
      }
      else if (iVar7 == 2) {
        iVar11 = iVar21 - iVar4 >> 1;
      }
      else {
        iVar11 = (iVar21 - iVar4) / iVar7;
      }
      DAT_1008d2ec = iVar11 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && ((int)uVar13 >> 6 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / ((int)uVar13 >> 6) << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar5 < iVar7) {
        DAT_1008d2c0 = (uVar20 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
        uVar14 = (uVar10 & 0xfffe) << 0xf | (local_10 & 0xfffe) >> 1;
        local_3c = iVar7 - iVar5;
        DAT_1008d2c4 = (uVar9 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar4;
        DAT_1008d290 = iVar5;
        DAT_1008d2c8 = uVar14;
        FUN_10078db8();
        DAT_1008d280 = iVar19 << 0x10;
        iVar16 = iVar16 - iVar19;
        if (local_3c == 1) {
          DAT_1008d28c = iVar16 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1008d28c = iVar16 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar6 + (iVar16 * 0x20 + local_3c) * 4);
        }
        else if (iVar16 < 0) {
          DAT_1008d28c = (iVar16 * 0x10000) / local_3c;
        }
        else {
          DAT_1008d28c = (iVar16 * 0x10000) / local_3c;
        }
        if ((uVar22 == uVar15) || (local_3c == 1)) {
          uVar22 = uVar22 - uVar15;
        }
        else if (local_3c == 2) {
          uVar22 = (int)(uVar22 - uVar15) >> 1;
        }
        else {
          uVar22 = (int)(uVar22 - uVar15) / local_3c;
        }
        if ((uVar18 == uVar12) || (local_3c == 1)) {
          uVar18 = uVar18 - uVar12;
        }
        else if (local_3c == 2) {
          uVar18 = (int)(uVar18 - uVar12) >> 1;
        }
        else {
          uVar18 = (int)(uVar18 - uVar12) / local_3c;
        }
        if ((iVar3 == iVar21) || (local_3c == 1)) {
          DAT_1008d2e8 = iVar21 - iVar3;
        }
        else if (local_3c == 2) {
          DAT_1008d2e8 = iVar21 - iVar3 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar21 - iVar3) / local_3c;
        }
        DAT_1008d2c4 = (uVar18 & 0xfffe) << 0xf | (uVar22 & 0xfffe) >> 1;
        DAT_1008d2c8 = uVar14;
      }
      else {
        DAT_1008d2c0 = (uVar20 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
        DAT_1008d2c8 = (uVar10 & 0xfffe) << 0xf | (local_10 & 0xfffe) >> 1;
        DAT_1008d2c4 = (uVar9 & 0xfffe) << 0xf | (uVar17 & 0xfffe) >> 1;
        local_3c = iVar5 - iVar7;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar4;
        DAT_1008d290 = iVar7;
        FUN_10078db8();
        if (local_3c == 0) {
          return;
        }
        DAT_1008d284 = iVar16 << 0x10;
        iVar19 = iVar19 - iVar16;
        if (local_3c == 1) {
          DAT_1008d288 = iVar19 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1008d288 = iVar19 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar6 + (iVar19 * 0x20 + local_3c) * 4);
        }
        else if (iVar19 < 0) {
          DAT_1008d288 = (iVar19 * 0x10000) / local_3c;
        }
        else {
          DAT_1008d288 = (iVar19 * 0x10000) / local_3c;
        }
      }
      goto LAB_100134af;
    }
    iVar7 = iVar16 - DAT_1008d280;
    if (iVar7 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar19 = iVar19 - iVar16;
    if (iVar5 == 1) {
      DAT_1008d288 = iVar19 * 0x10000;
    }
    else if (iVar5 == 2) {
      DAT_1008d288 = iVar19 * 0x8000;
    }
    else if (((iVar5 < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar6 + (iVar19 * 0x20 + iVar5) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1008d288 = (iVar19 * 0x10000) / iVar5;
    }
    else {
      DAT_1008d288 = (iVar19 * 0x10000) / iVar5;
    }
    if ((iVar4 == iVar21) || (iVar7 == 1)) {
      DAT_1008d2ec = iVar21 - iVar4;
    }
    else if (iVar7 == 2) {
      DAT_1008d2ec = iVar21 - iVar4 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar21 - iVar4) / iVar7;
    }
    if ((iVar3 == iVar4) || (iVar5 == 1)) {
      DAT_1008d2e8 = iVar3 - iVar4;
    }
    else if (iVar5 == 2) {
      DAT_1008d2e8 = iVar3 - iVar4 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar3 - iVar4) / iVar5;
    }
    if ((uVar22 == uVar14) || (iVar7 == 1)) {
      uVar22 = uVar22 - uVar14;
    }
    else if (iVar7 == 2) {
      uVar22 = (int)(uVar22 - uVar14) >> 1;
    }
    else {
      uVar22 = (int)(uVar22 - uVar14) / iVar7;
    }
    if ((uVar18 == uVar20) || (iVar7 == 1)) {
      uVar18 = uVar18 - uVar20;
    }
    else if (iVar7 == 2) {
      uVar18 = (int)(uVar18 - uVar20) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar20) / iVar7;
    }
    if ((uVar15 == uVar14) || (iVar5 == 1)) {
      uVar15 = uVar15 - uVar14;
    }
    else if (iVar5 == 2) {
      uVar15 = (int)(uVar15 - uVar14) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar14) / iVar5;
    }
    if ((uVar12 == uVar20) || (iVar5 == 1)) {
      uVar12 = uVar12 - uVar20;
    }
    else if (iVar5 == 2) {
      uVar12 = (int)(uVar12 - uVar20) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar20) / iVar5;
    }
    DAT_1008d2c0 = (uVar20 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    DAT_1008d2c8 = (uVar18 & 0xfffe) << 0xf | (uVar22 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar12 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
    local_3c = iVar5;
    iVar3 = iVar4;
    iVar19 = DAT_1008d280;
    DAT_1008d280 = iVar16;
  }
  DAT_1008d284 = DAT_1008d280 << 0x10;
  DAT_1008d280 = iVar19 << 0x10;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar3;
LAB_100134af:
  DAT_1008d290 = local_3c;
  FUN_10078db8();
  return;
}


