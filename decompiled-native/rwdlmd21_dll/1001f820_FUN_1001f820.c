// 1001f820 FUN_1001f820 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f820(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  undefined8 uVar21;
  int local_3c;
  uint local_c;
  
  iVar2 = param_3;
  iVar19 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar2 = param_2;
      param_2 = param_4;
      iVar19 = param_3;
    }
LAB_1001f865:
    param_4 = iVar2;
    param_3 = param_2;
    param_2 = iVar19;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001f865;
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  iVar3 = (int)*(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  uVar13 = *(uint *)(param_2 + 100);
  uVar16 = *(uint *)(param_2 + 0x68);
  iVar2 = *(int *)(param_2 + 0x20);
  iVar17 = (int)*(short *)(param_3 + 0x1a);
  uVar14 = *(uint *)(param_3 + 100);
  uVar12 = *(uint *)(param_3 + 0x68);
  iVar1 = *(int *)(param_3 + 0x20);
  iVar15 = (int)*(short *)(param_4 + 0x1a);
  uVar20 = *(uint *)(param_4 + 100);
  uVar18 = *(uint *)(param_4 + 0x68);
  iVar19 = *(int *)(param_4 + 0x20);
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248 + 0x800;
  iVar4 = DAT_1008723c + 0x1000;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  if (iVar3 < 1) {
    iVar3 = DAT_1008d280 - iVar17;
    if (iVar3 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    local_3c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_3c == 0) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar5 = iVar15 - iVar17;
    if (local_3c == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar4 + (iVar5 * 0x20 + local_3c) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / local_3c;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / local_3c;
    }
    iVar15 = iVar15 - DAT_1008d280;
    if (local_3c == 1) {
      DAT_1008d288 = iVar15 * 0x10000;
    }
    else if (local_3c == 2) {
      DAT_1008d288 = iVar15 * 0x8000;
    }
    else if (((local_3c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar4 + (iVar15 * 0x20 + local_3c) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1008d288 = (iVar15 * 0x10000) / local_3c;
    }
    else {
      DAT_1008d288 = (iVar15 * 0x10000) / local_3c;
    }
    if ((iVar1 == iVar2) || (iVar3 == 1)) {
      DAT_1008d2ec = iVar2 - iVar1;
    }
    else if (iVar3 == 2) {
      DAT_1008d2ec = iVar2 - iVar1 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar2 - iVar1) / iVar3;
    }
    if ((iVar19 == iVar1) || (local_3c == 1)) {
      DAT_1008d2e8 = iVar19 - iVar1;
    }
    else if (local_3c == 2) {
      DAT_1008d2e8 = iVar19 - iVar1 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar19 - iVar1) / local_3c;
    }
    if ((uVar14 == uVar13) || (iVar3 == 1)) {
      uVar13 = uVar13 - uVar14;
    }
    else if (iVar3 == 2) {
      uVar13 = (int)(uVar13 - uVar14) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - uVar14) / iVar3;
    }
    if ((uVar20 == uVar14) || (local_3c == 1)) {
      uVar20 = uVar20 - uVar14;
    }
    else if (local_3c == 2) {
      uVar20 = (int)(uVar20 - uVar14) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar14) / local_3c;
    }
    if ((uVar12 == uVar16) || (iVar3 == 1)) {
      uVar16 = uVar16 - uVar12;
    }
    else if (iVar3 == 2) {
      uVar16 = (int)(uVar16 - uVar12) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar12) / iVar3;
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
    DAT_1008d2c8 = (uVar16 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
    DAT_1008d2c0 = (uVar12 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar18 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
  }
  else {
    iVar5 = iVar17 - DAT_1008d280;
    if (iVar3 == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar4 + (iVar5 * 0x20 + iVar3) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / iVar3;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / iVar3;
    }
    iVar5 = (int)*(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (0 < iVar5) {
      iVar6 = iVar15 - DAT_1008d280;
      iVar11 = iVar5;
      if (iVar5 == 1) {
        DAT_1008d288 = iVar6 * 0x10000;
      }
      else if (iVar5 == 2) {
        DAT_1008d288 = iVar6 * 0x8000;
      }
      else if (((iVar5 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar4 + (iVar6 * 0x20 + iVar5) * 4);
        iVar11 = iVar4;
      }
      else if (iVar6 < 0) {
        DAT_1008d288 = (iVar6 * 0x10000) / iVar5;
        iVar11 = (iVar6 * 0x10000) % iVar5;
      }
      else {
        DAT_1008d288 = (iVar6 * 0x10000) / iVar5;
        iVar11 = (iVar6 * 0x10000) % iVar5;
      }
      uVar7 = DAT_1008d288 - DAT_1008d28c;
      if ((int)uVar7 < 1) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d2a0 = DAT_10089ef4;
        return;
      }
      if ((uVar14 == uVar13) || (iVar3 == 1)) {
        uVar8 = uVar14 - uVar13;
      }
      else if (iVar3 == 2) {
        uVar8 = (int)(uVar14 - uVar13) >> 1;
      }
      else {
        uVar8 = (int)(uVar14 - uVar13) / iVar3;
        iVar11 = (int)(uVar14 - uVar13) % iVar3;
      }
      if ((uVar12 == uVar16) || (iVar3 == 1)) {
        uVar9 = uVar12 - uVar16;
      }
      else if (iVar3 == 2) {
        uVar9 = (int)(uVar12 - uVar16) >> 1;
      }
      else {
        uVar9 = (int)(uVar12 - uVar16) / iVar3;
        iVar11 = (int)(uVar12 - uVar16) % iVar3;
      }
      if ((uVar20 == uVar13) || (iVar5 == 1)) {
        iVar6 = uVar20 - uVar13;
      }
      else if (iVar5 == 2) {
        iVar6 = (int)(uVar20 - uVar13) >> 1;
      }
      else {
        iVar6 = (int)(uVar20 - uVar13) / iVar5;
        iVar11 = (int)(uVar20 - uVar13) % iVar5;
      }
      iVar6 = iVar6 - uVar8;
      uVar21 = CONCAT44(iVar11,iVar6);
      if (iVar6 != 0) {
        uVar21 = FUN_1006a324(iVar6,iVar11,iVar6,uVar7);
      }
      iVar11 = (int)((ulonglong)uVar21 >> 0x20);
      local_c = (uint)uVar21;
      if ((uVar18 == uVar16) || (iVar5 == 1)) {
        iVar6 = uVar18 - uVar16;
      }
      else if (iVar5 == 2) {
        iVar6 = (int)(uVar18 - uVar16) >> 1;
      }
      else {
        iVar6 = (int)(uVar18 - uVar16) / iVar5;
        iVar11 = (int)(uVar18 - uVar16) % iVar5;
      }
      iVar6 = iVar6 - uVar9;
      uVar10 = 0;
      if (iVar6 != 0) {
        uVar21 = FUN_1006a324(iVar6,iVar11,iVar6,uVar7);
        uVar10 = (uint)uVar21;
      }
      if ((iVar1 == iVar2) || (iVar3 == 1)) {
        DAT_1008d2e8 = iVar1 - iVar2;
      }
      else if (iVar3 == 2) {
        DAT_1008d2e8 = iVar1 - iVar2 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar1 - iVar2) / iVar3;
      }
      if ((iVar19 == iVar2) || (iVar5 == 1)) {
        iVar11 = iVar19 - iVar2;
      }
      else if (iVar5 == 2) {
        iVar11 = iVar19 - iVar2 >> 1;
      }
      else {
        iVar11 = (iVar19 - iVar2) / iVar5;
      }
      DAT_1008d2ec = iVar11 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && ((int)uVar7 >> 6 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / ((int)uVar7 >> 6) << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar3 < iVar5) {
        DAT_1008d2c0 = (uVar16 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
        uVar13 = (uVar10 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
        local_3c = iVar5 - iVar3;
        DAT_1008d2c4 = (uVar9 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar2;
        DAT_1008d290 = iVar3;
        DAT_1008d2c8 = uVar13;
        FUN_10020550((uint *)&DAT_1008d280);
        DAT_1008d280 = iVar17 << 0x10;
        iVar15 = iVar15 - iVar17;
        if (local_3c == 1) {
          DAT_1008d28c = iVar15 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1008d28c = iVar15 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar4 + (iVar15 * 0x20 + local_3c) * 4);
        }
        else if (iVar15 < 0) {
          DAT_1008d28c = (iVar15 * 0x10000) / local_3c;
        }
        else {
          DAT_1008d28c = (iVar15 * 0x10000) / local_3c;
        }
        if ((uVar20 == uVar14) || (local_3c == 1)) {
          uVar20 = uVar20 - uVar14;
        }
        else if (local_3c == 2) {
          uVar20 = (int)(uVar20 - uVar14) >> 1;
        }
        else {
          uVar20 = (int)(uVar20 - uVar14) / local_3c;
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
        if ((iVar19 == iVar1) || (local_3c == 1)) {
          DAT_1008d2e8 = iVar19 - iVar1;
        }
        else if (local_3c == 2) {
          DAT_1008d2e8 = iVar19 - iVar1 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar19 - iVar1) / local_3c;
        }
        DAT_1008d2c4 = (uVar18 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
        DAT_1008d2c8 = uVar13;
      }
      else {
        DAT_1008d2c0 = (uVar16 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
        DAT_1008d2c8 = (uVar10 & 0xfffe) << 0xf | (local_c & 0xfffe) >> 1;
        DAT_1008d2c4 = (uVar9 & 0xfffe) << 0xf | (uVar8 & 0xfffe) >> 1;
        local_3c = iVar3 - iVar5;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar2;
        DAT_1008d290 = iVar5;
        FUN_10020550((uint *)&DAT_1008d280);
        if (local_3c == 0) {
          return;
        }
        DAT_1008d284 = iVar15 << 0x10;
        iVar17 = iVar17 - iVar15;
        if (local_3c == 1) {
          DAT_1008d288 = iVar17 * 0x10000;
        }
        else if (local_3c == 2) {
          DAT_1008d288 = iVar17 * 0x8000;
        }
        else if (((local_3c < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar4 + (iVar17 * 0x20 + local_3c) * 4);
        }
        else if (iVar17 < 0) {
          DAT_1008d288 = (iVar17 * 0x10000) / local_3c;
        }
        else {
          DAT_1008d288 = (iVar17 * 0x10000) / local_3c;
        }
      }
      goto LAB_1002052c;
    }
    iVar5 = iVar15 - DAT_1008d280;
    if (iVar5 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar17 = iVar17 - iVar15;
    if (iVar3 == 1) {
      DAT_1008d288 = iVar17 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1008d288 = iVar17 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar4 + (iVar17 * 0x20 + iVar3) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1008d288 = (iVar17 * 0x10000) / iVar3;
    }
    else {
      DAT_1008d288 = (iVar17 * 0x10000) / iVar3;
    }
    if ((iVar19 == iVar2) || (iVar5 == 1)) {
      DAT_1008d2ec = iVar19 - iVar2;
    }
    else if (iVar5 == 2) {
      DAT_1008d2ec = iVar19 - iVar2 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar19 - iVar2) / iVar5;
    }
    if ((iVar1 == iVar2) || (iVar3 == 1)) {
      DAT_1008d2e8 = iVar1 - iVar2;
    }
    else if (iVar3 == 2) {
      DAT_1008d2e8 = iVar1 - iVar2 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar1 - iVar2) / iVar3;
    }
    if ((uVar20 == uVar13) || (iVar5 == 1)) {
      uVar20 = uVar20 - uVar13;
    }
    else if (iVar5 == 2) {
      uVar20 = (int)(uVar20 - uVar13) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar13) / iVar5;
    }
    if ((uVar18 == uVar16) || (iVar5 == 1)) {
      uVar18 = uVar18 - uVar16;
    }
    else if (iVar5 == 2) {
      uVar18 = (int)(uVar18 - uVar16) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar16) / iVar5;
    }
    if ((uVar14 == uVar13) || (iVar3 == 1)) {
      uVar14 = uVar14 - uVar13;
    }
    else if (iVar3 == 2) {
      uVar14 = (int)(uVar14 - uVar13) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar13) / iVar3;
    }
    if ((uVar12 == uVar16) || (iVar3 == 1)) {
      uVar12 = uVar12 - uVar16;
    }
    else if (iVar3 == 2) {
      uVar12 = (int)(uVar12 - uVar16) >> 1;
    }
    else {
      uVar12 = (int)(uVar12 - uVar16) / iVar3;
    }
    DAT_1008d2c0 = (uVar16 & 0xfffe) << 0xf | (uVar13 & 0xfffe) >> 1;
    DAT_1008d2c8 = (uVar18 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1008d2c4 = (uVar12 & 0xfffe) << 0xf | (uVar14 & 0xfffe) >> 1;
    local_3c = iVar3;
    iVar1 = iVar2;
    iVar17 = DAT_1008d280;
    DAT_1008d280 = iVar15;
  }
  DAT_1008d284 = DAT_1008d280 << 0x10;
  DAT_1008d280 = iVar17 << 0x10;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar1;
LAB_1002052c:
  DAT_1008d290 = local_3c;
  FUN_10020550((uint *)&DAT_1008d280);
  return;
}


