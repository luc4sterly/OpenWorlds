// 1003c840 FUN_1003c840 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1003c840(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint extraout_ECX;
  uint uVar11;
  int iVar12;
  int iVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  undefined8 uVar22;
  int local_44;
  short local_2c;
  uint local_20;
  uint local_18;
  short local_10;
  
  iVar1 = param_3;
  iVar12 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      param_2 = param_4;
      iVar12 = param_3;
    }
LAB_1003c886:
    param_4 = iVar1;
    param_3 = param_2;
    param_2 = iVar12;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1003c886;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  local_44 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar19 = *(int *)(param_2 + 100) >> 3;
  uVar15 = *(int *)(param_2 + 0x68) >> 3;
  iVar1 = (int)*(short *)(param_3 + 0x1a);
  uVar16 = *(int *)(param_2 + 0x58) >> 8;
  uVar20 = *(int *)(param_3 + 100) >> 3;
  local_20 = *(int *)(param_3 + 0x58) >> 8;
  uVar17 = *(int *)(param_3 + 0x68) >> 3;
  iVar12 = (int)*(short *)(param_4 + 0x1a);
  uVar2 = *(int *)(param_4 + 0x58) >> 8;
  uVar18 = *(int *)(param_4 + 100) >> 3;
  uVar21 = *(int *)(param_4 + 0x68) >> 3;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar13 = DAT_10075214 + 0x1000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  sVar14 = (short)((uint)*(int *)(param_2 + 0x58) >> 8);
  local_10 = (short)((uint)*(int *)(param_4 + 0x58) >> 8);
  local_2c = (short)((uint)*(int *)(param_3 + 0x58) >> 8);
  if (local_44 < 1) {
    iVar3 = DAT_1007b280 - iVar1;
    if (iVar3 < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    local_44 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_44 == 0) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    iVar10 = iVar12 - iVar1;
    if (local_44 == 1) {
      DAT_1007b28c = iVar10 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1007b28c = iVar10 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar13 + (iVar10 * 0x20 + local_44) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007b28c = (iVar10 * 0x10000) / local_44;
    }
    else {
      DAT_1007b28c = (iVar10 * 0x10000) / local_44;
    }
    iVar12 = iVar12 - DAT_1007b280;
    if (local_44 == 1) {
      DAT_1007b288 = iVar12 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1007b288 = iVar12 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar13 + (iVar12 * 0x20 + local_44) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1007b288 = (iVar12 * 0x10000) / local_44;
    }
    else {
      DAT_1007b288 = (iVar12 * 0x10000) / local_44;
    }
    if ((uVar20 == uVar19) || (iVar3 == 1)) {
      uVar19 = uVar19 - uVar20;
    }
    else if (iVar3 == 2) {
      uVar19 = (int)(uVar19 - uVar20) >> 1;
    }
    else {
      uVar19 = (int)(uVar19 - uVar20) / iVar3;
    }
    if ((uVar20 == uVar18) || (local_44 == 1)) {
      uVar18 = uVar18 - uVar20;
    }
    else if (local_44 == 2) {
      uVar18 = (int)(uVar18 - uVar20) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar20) / local_44;
    }
    if ((uVar17 == uVar15) || (iVar3 == 1)) {
      uVar15 = uVar15 - uVar17;
    }
    else if (iVar3 == 2) {
      uVar15 = (int)(uVar15 - uVar17) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar17) / iVar3;
    }
    if ((uVar17 == uVar21) || (local_44 == 1)) {
      uVar21 = uVar21 - uVar17;
    }
    else if (local_44 == 2) {
      uVar21 = (int)(uVar21 - uVar17) >> 1;
    }
    else {
      uVar21 = (int)(uVar21 - uVar17) / local_44;
    }
    uVar16 = uVar16 & 0xffff;
    if ((local_2c == sVar14) || (iVar3 == 1)) {
      uVar16 = uVar16 - (local_20 & 0xffff);
    }
    else if (iVar3 == 2) {
      uVar16 = (int)(uVar16 - (local_20 & 0xffff)) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - (local_20 & 0xffff)) / iVar3;
    }
    uVar5 = local_20 & 0xffff;
    DAT_1007b2d4 = (uVar16 & 0xffff) + (uVar16 & 0x8000) * -2;
    uVar2 = uVar2 & 0xffff;
    if ((local_10 == local_2c) || (local_44 == 1)) {
      uVar2 = uVar2 - uVar5;
    }
    else if (local_44 == 2) {
      uVar2 = (int)(uVar2 - uVar5) >> 1;
    }
    else {
      uVar2 = (int)(uVar2 - uVar5) / local_44;
    }
    DAT_1007b2d0 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
    DAT_1007b284 = DAT_1007b280 << 0x10;
    DAT_1007b2c0 = (uVar17 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
    DAT_1007b2c8 = (uVar15 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    DAT_1007b2cc = local_20;
  }
  else {
    iVar3 = iVar1 - DAT_1007b280;
    if (local_44 == 1) {
      DAT_1007b28c = iVar3 * 0x10000;
    }
    else if (local_44 == 2) {
      DAT_1007b28c = iVar3 * 0x8000;
    }
    else if (((local_44 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar13 + (iVar3 * 0x20 + local_44) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1007b28c = (iVar3 * 0x10000) / local_44;
    }
    else {
      DAT_1007b28c = (iVar3 * 0x10000) / local_44;
    }
    iVar3 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (iVar3 < 1) {
      iVar3 = iVar12 - DAT_1007b280;
      if (iVar3 < 1) {
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      iVar1 = iVar1 - iVar12;
      if (local_44 == 1) {
        DAT_1007b288 = iVar1 * 0x10000;
      }
      else if (local_44 == 2) {
        DAT_1007b288 = iVar1 * 0x8000;
      }
      else if (((local_44 < 0x20) && (-0x20 < iVar1)) && (iVar1 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar13 + (iVar1 * 0x20 + local_44) * 4);
      }
      else if (iVar1 < 0) {
        DAT_1007b288 = (iVar1 * 0x10000) / local_44;
      }
      else {
        DAT_1007b288 = (iVar1 * 0x10000) / local_44;
      }
      if ((uVar19 == uVar18) || (iVar3 == 1)) {
        uVar18 = uVar18 - uVar19;
      }
      else if (iVar3 == 2) {
        uVar18 = (int)(uVar18 - uVar19) >> 1;
      }
      else {
        uVar18 = (int)(uVar18 - uVar19) / iVar3;
      }
      if ((uVar15 == uVar21) || (iVar3 == 1)) {
        uVar21 = uVar21 - uVar15;
      }
      else if (iVar3 == 2) {
        uVar21 = (int)(uVar21 - uVar15) >> 1;
      }
      else {
        uVar21 = (int)(uVar21 - uVar15) / iVar3;
      }
      if ((uVar20 == uVar19) || (local_44 == 1)) {
        uVar20 = uVar20 - uVar19;
      }
      else if (local_44 == 2) {
        uVar20 = (int)(uVar20 - uVar19) >> 1;
      }
      else {
        uVar20 = (int)(uVar20 - uVar19) / local_44;
      }
      if ((uVar17 == uVar15) || (local_44 == 1)) {
        uVar17 = uVar17 - uVar15;
      }
      else if (local_44 == 2) {
        uVar17 = (int)(uVar17 - uVar15) >> 1;
      }
      else {
        uVar17 = (int)(uVar17 - uVar15) / local_44;
      }
      uVar2 = uVar2 & 0xffff;
      if ((local_10 == sVar14) || (iVar3 == 1)) {
        uVar2 = uVar2 - (uVar16 & 0xffff);
      }
      else if (iVar3 == 2) {
        uVar2 = (int)(uVar2 - (uVar16 & 0xffff)) >> 1;
      }
      else {
        uVar2 = (int)(uVar2 - (uVar16 & 0xffff)) / iVar3;
      }
      uVar5 = uVar16 & 0xffff;
      DAT_1007b2d4 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
      local_20 = local_20 & 0xffff;
      if ((local_2c == sVar14) || (local_44 == 1)) {
        local_20 = local_20 - uVar5;
      }
      else if (local_44 == 2) {
        local_20 = (int)(local_20 - uVar5) >> 1;
      }
      else {
        local_20 = (int)(local_20 - uVar5) / local_44;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b2d0 = (local_20 & 0xffff) + (local_20 & 0x8000) * -2;
      DAT_1007b284 = iVar12 << 0x10;
      DAT_1007b2c0 = (uVar15 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
      DAT_1007b2c8 = (uVar21 & 0xfffe) << 0xf | (uVar18 & 0xfffe) >> 1;
      DAT_1007b2c4 = (uVar17 & 0xfffe) << 0xf | (uVar20 & 0xfffe) >> 1;
      DAT_1007b2cc = uVar16;
      goto LAB_1003d626;
    }
    iVar4 = iVar12 - DAT_1007b280;
    iVar10 = iVar3;
    if (iVar3 == 1) {
      DAT_1007b288 = iVar4 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1007b288 = iVar4 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar13 + (iVar4 * 0x20 + iVar3) * 4);
      iVar10 = iVar13;
    }
    else if (iVar4 < 0) {
      DAT_1007b288 = (iVar4 * 0x10000) / iVar3;
      iVar10 = (iVar4 * 0x10000) % iVar3;
    }
    else {
      DAT_1007b288 = (iVar4 * 0x10000) / iVar3;
      iVar10 = (iVar4 * 0x10000) % iVar3;
    }
    uVar5 = DAT_1007b288 - DAT_1007b28c;
    if ((int)uVar5 < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    if ((uVar20 == uVar19) || (local_44 == 1)) {
      uVar6 = uVar20 - uVar19;
    }
    else if (local_44 == 2) {
      uVar6 = (int)(uVar20 - uVar19) >> 1;
    }
    else {
      uVar6 = (int)(uVar20 - uVar19) / local_44;
      iVar10 = (int)(uVar20 - uVar19) % local_44;
    }
    if ((uVar17 == uVar15) || (local_44 == 1)) {
      uVar7 = uVar17 - uVar15;
    }
    else if (local_44 == 2) {
      uVar7 = (int)(uVar17 - uVar15) >> 1;
    }
    else {
      uVar7 = (int)(uVar17 - uVar15) / local_44;
      iVar10 = (int)(uVar17 - uVar15) % local_44;
    }
    if ((uVar19 == uVar18) || (iVar3 == 1)) {
      iVar4 = uVar18 - uVar19;
    }
    else if (iVar3 == 2) {
      iVar4 = (int)(uVar18 - uVar19) >> 1;
    }
    else {
      iVar4 = (int)(uVar18 - uVar19) / iVar3;
      iVar10 = (int)(uVar18 - uVar19) % iVar3;
    }
    iVar4 = iVar4 - uVar6;
    uVar22 = CONCAT44(iVar10,iVar4);
    uVar9 = 0;
    if (iVar4 != 0) {
      uVar22 = FUN_10063324(iVar4,iVar10,iVar4,uVar5);
      uVar9 = extraout_ECX;
    }
    iVar10 = (int)((ulonglong)uVar22 >> 0x20);
    local_18 = (uint)uVar22;
    if ((uVar15 == uVar21) || (iVar3 == 1)) {
      iVar4 = uVar21 - uVar15;
    }
    else if (iVar3 == 2) {
      iVar4 = (int)(uVar21 - uVar15) >> 1;
    }
    else {
      iVar4 = (int)(uVar21 - uVar15) / iVar3;
      iVar10 = (int)(uVar21 - uVar15) % iVar3;
      uVar9 = uVar15;
    }
    uVar8 = 0;
    if (iVar4 - uVar7 != 0) {
      uVar22 = FUN_10063324(uVar9,iVar10,iVar4 - uVar7,uVar5);
      uVar8 = (uint)uVar22;
    }
    if ((local_2c == sVar14) || (local_44 == 1)) {
      uVar9 = (local_20 & 0xffff) - (uVar16 & 0xffff);
    }
    else if (local_44 == 2) {
      uVar9 = (int)((local_20 & 0xffff) - (uVar16 & 0xffff)) >> 1;
    }
    else {
      uVar9 = (int)((local_20 & 0xffff) - (uVar16 & 0xffff)) / local_44;
    }
    local_20 = local_20 & 0xffff;
    uVar11 = uVar16 & 0xffff;
    DAT_1007b2d4 = 0;
    DAT_1007b2d0 = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    if ((local_10 == sVar14) || (iVar3 == 1)) {
      iVar10 = (uVar2 & 0xffff) - uVar11;
    }
    else if (iVar3 == 2) {
      iVar10 = (int)((uVar2 & 0xffff) - uVar11) >> 1;
    }
    else {
      iVar10 = (int)((uVar2 & 0xffff) - uVar11) / iVar3;
    }
    uVar2 = uVar2 & 0xffff;
    if (iVar10 - (short)DAT_1007b2d0 != 0) {
      uVar5 = ((iVar10 - (short)DAT_1007b2d0) * 0x10000) / (int)uVar5;
      DAT_1007b2d4 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
    }
    DAT_1007b280 = DAT_1007b280 << 0x10;
    DAT_1007b284 = DAT_1007b280;
    if (iVar3 <= local_44) {
      DAT_1007b2c0 = (uVar15 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
      DAT_1007b2c8 = (uVar8 & 0xfffe) << 0xf | (local_18 & 0xfffe) >> 1;
      local_44 = local_44 - iVar3;
      DAT_1007b2c4 = (uVar7 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
      DAT_1007b290 = iVar3;
      DAT_1007b2cc = uVar16;
      FUN_1003d650((uint *)&DAT_1007b280);
      if (local_44 == 0) {
        return;
      }
      DAT_1007b284 = iVar12 << 0x10;
      iVar1 = iVar1 - iVar12;
      if (local_44 == 1) {
        DAT_1007b288 = iVar1 * 0x10000;
      }
      else if (local_44 == 2) {
        DAT_1007b288 = iVar1 * 0x8000;
      }
      else if (((local_44 < 0x20) && (-0x20 < iVar1)) && (iVar1 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar13 + (iVar1 * 0x20 + local_44) * 4);
      }
      else if (iVar1 < 0) {
        DAT_1007b288 = (iVar1 * 0x10000) / local_44;
      }
      else {
        DAT_1007b288 = (iVar1 * 0x10000) / local_44;
      }
      goto LAB_1003d626;
    }
    DAT_1007b2c0 = (uVar15 & 0xfffe) << 0xf | (uVar19 & 0xfffe) >> 1;
    uVar19 = (uVar8 & 0xfffe) << 0xf | (local_18 & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar7 & 0xfffe) << 0xf | (uVar6 & 0xfffe) >> 1;
    iVar3 = iVar3 - local_44;
    DAT_1007b290 = local_44;
    DAT_1007b2c8 = uVar19;
    DAT_1007b2cc = uVar16;
    FUN_1003d650((uint *)&DAT_1007b280);
    iVar12 = iVar12 - iVar1;
    if (iVar3 == 1) {
      DAT_1007b28c = iVar12 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1007b28c = iVar12 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar13 + (iVar12 * 0x20 + iVar3) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1007b28c = (iVar12 * 0x10000) / iVar3;
    }
    else {
      DAT_1007b28c = (iVar12 * 0x10000) / iVar3;
    }
    if ((uVar20 == uVar18) || (iVar3 == 1)) {
      uVar18 = uVar18 - uVar20;
    }
    else if (iVar3 == 2) {
      uVar18 = (int)(uVar18 - uVar20) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar20) / iVar3;
    }
    if ((uVar17 == uVar21) || (iVar3 == 1)) {
      uVar21 = uVar21 - uVar17;
    }
    else if (iVar3 == 2) {
      uVar21 = (int)(uVar21 - uVar17) >> 1;
    }
    else {
      uVar21 = (int)(uVar21 - uVar17) / iVar3;
    }
    DAT_1007b2d0 = 0;
    if ((local_10 == local_2c) || (iVar3 == 1)) {
      uVar2 = uVar2 - local_20;
    }
    else if (iVar3 == 2) {
      uVar2 = (int)(uVar2 - local_20) >> 1;
    }
    else {
      uVar2 = (int)(uVar2 - local_20) / iVar3;
    }
    DAT_1007b2c8 = uVar19;
    local_44 = iVar3;
    if (uVar2 != 0) {
      DAT_1007b2d0 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
    }
  }
  DAT_1007b280 = iVar1 << 0x10;
  DAT_1007b2c4 = (uVar21 & 0xfffe) << 0xf | (uVar18 & 0xfffe) >> 1;
LAB_1003d626:
  DAT_1007b290 = local_44;
  FUN_1003d650((uint *)&DAT_1007b280);
  return;
}


