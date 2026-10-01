// 10019520 FUN_10019520 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10019520(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  undefined8 uVar21;
  int local_48;
  short local_38;
  short local_2c;
  uint local_20;
  uint local_1c;
  short local_10;
  
  iVar3 = param_3;
  iVar16 = param_4;
  iVar17 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar3 = param_2;
      iVar16 = param_3;
      iVar17 = param_4;
    }
LAB_10019566:
    param_4 = iVar3;
    param_2 = iVar16;
    param_3 = iVar17;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10019566;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  local_48 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar15 = *(uint *)(param_2 + 100);
  uVar14 = *(uint *)(param_2 + 0x68);
  uVar1 = *(int *)(param_2 + 0x58) >> 8;
  iVar16 = (int)*(short *)(param_3 + 0x1a);
  uVar12 = *(uint *)(param_3 + 100);
  uVar13 = *(uint *)(param_3 + 0x68);
  iVar17 = (int)*(short *)(param_4 + 0x1a);
  local_20 = *(int *)(param_3 + 0x58) >> 8;
  uVar18 = *(uint *)(param_4 + 100);
  uVar20 = *(uint *)(param_4 + 0x68);
  uVar2 = *(int *)(param_4 + 0x58) >> 8;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  iVar3 = DAT_10075214 + 0x1000;
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  local_10 = (short)((uint)*(int *)(param_4 + 0x58) >> 8);
  local_2c = (short)((uint)*(int *)(param_3 + 0x58) >> 8);
  local_38 = (short)((uint)*(int *)(param_2 + 0x58) >> 8);
  if (local_48 < 1) {
    iVar4 = DAT_1007b280 - iVar16;
    if (iVar4 < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    local_48 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_48 == 0) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    iVar11 = iVar17 - iVar16;
    if (local_48 == 1) {
      DAT_1007b28c = iVar11 * 0x10000;
    }
    else if (local_48 == 2) {
      DAT_1007b28c = iVar11 * 0x8000;
    }
    else if (((local_48 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar3 + (iVar11 * 0x20 + local_48) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1007b28c = (iVar11 * 0x10000) / local_48;
    }
    else {
      DAT_1007b28c = (iVar11 * 0x10000) / local_48;
    }
    iVar17 = iVar17 - DAT_1007b280;
    if (local_48 == 1) {
      DAT_1007b288 = iVar17 * 0x10000;
    }
    else if (local_48 == 2) {
      DAT_1007b288 = iVar17 * 0x8000;
    }
    else if (((local_48 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar3 + (iVar17 * 0x20 + local_48) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1007b288 = (iVar17 * 0x10000) / local_48;
    }
    else {
      DAT_1007b288 = (iVar17 * 0x10000) / local_48;
    }
    if ((uVar12 == uVar15) || (iVar4 == 1)) {
      uVar15 = uVar15 - uVar12;
    }
    else if (iVar4 == 2) {
      uVar15 = (int)(uVar15 - uVar12) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar12) / iVar4;
    }
    if ((uVar18 == uVar12) || (local_48 == 1)) {
      uVar18 = uVar18 - uVar12;
    }
    else if (local_48 == 2) {
      uVar18 = (int)(uVar18 - uVar12) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar12) / local_48;
    }
    if ((uVar13 == uVar14) || (iVar4 == 1)) {
      uVar14 = uVar14 - uVar13;
    }
    else if (iVar4 == 2) {
      uVar14 = (int)(uVar14 - uVar13) >> 1;
    }
    else {
      uVar14 = (int)(uVar14 - uVar13) / iVar4;
    }
    if ((uVar20 == uVar13) || (local_48 == 1)) {
      uVar20 = uVar20 - uVar13;
    }
    else if (local_48 == 2) {
      uVar20 = (int)(uVar20 - uVar13) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar13) / local_48;
    }
    uVar1 = uVar1 & 0xffff;
    if ((local_2c == local_38) || (iVar4 == 1)) {
      uVar1 = uVar1 - (local_20 & 0xffff);
    }
    else if (iVar4 == 2) {
      uVar1 = (int)(uVar1 - (local_20 & 0xffff)) >> 1;
    }
    else {
      uVar1 = (int)(uVar1 - (local_20 & 0xffff)) / iVar4;
    }
    uVar6 = local_20 & 0xffff;
    DAT_1007b2d4 = (uVar1 & 0xffff) + (uVar1 & 0x8000) * -2;
    uVar2 = uVar2 & 0xffff;
    if ((local_10 == local_2c) || (local_48 == 1)) {
      uVar2 = uVar2 - uVar6;
    }
    else if (local_48 == 2) {
      uVar2 = (int)(uVar2 - uVar6) >> 1;
    }
    else {
      uVar2 = (int)(uVar2 - uVar6) / local_48;
    }
    DAT_1007b2d0 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
    DAT_1007b284 = DAT_1007b280 << 0x10;
    DAT_1007b2c0 = (uVar12 & 0xfffe) >> 1 | (uVar13 & 0xfffe) << 0xf;
    uVar15 = (uVar14 & 0xfffe) << 0xf | (uVar15 & 0xfffe) >> 1;
    DAT_1007b2cc = local_20;
  }
  else {
    iVar4 = iVar16 - DAT_1007b280;
    if (local_48 == 1) {
      DAT_1007b28c = iVar4 * 0x10000;
    }
    else if (local_48 == 2) {
      DAT_1007b28c = iVar4 * 0x8000;
    }
    else if (((local_48 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar3 + (iVar4 * 0x20 + local_48) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1007b28c = (iVar4 * 0x10000) / local_48;
    }
    else {
      DAT_1007b28c = (iVar4 * 0x10000) / local_48;
    }
    iVar4 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (iVar4 < 1) {
      iVar4 = iVar17 - DAT_1007b280;
      if (iVar4 < 1) {
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      iVar16 = iVar16 - iVar17;
      if (local_48 == 1) {
        DAT_1007b288 = iVar16 * 0x10000;
      }
      else if (local_48 == 2) {
        DAT_1007b288 = iVar16 * 0x8000;
      }
      else if (((local_48 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar3 + (iVar16 * 0x20 + local_48) * 4);
      }
      else if (iVar16 < 0) {
        DAT_1007b288 = (iVar16 * 0x10000) / local_48;
      }
      else {
        DAT_1007b288 = (iVar16 * 0x10000) / local_48;
      }
      if ((uVar18 == uVar15) || (iVar4 == 1)) {
        uVar18 = uVar18 - uVar15;
      }
      else if (iVar4 == 2) {
        uVar18 = (int)(uVar18 - uVar15) >> 1;
      }
      else {
        uVar18 = (int)(uVar18 - uVar15) / iVar4;
      }
      if ((uVar20 == uVar14) || (iVar4 == 1)) {
        uVar20 = uVar20 - uVar14;
      }
      else if (iVar4 == 2) {
        uVar20 = (int)(uVar20 - uVar14) >> 1;
      }
      else {
        uVar20 = (int)(uVar20 - uVar14) / iVar4;
      }
      if ((uVar12 == uVar15) || (local_48 == 1)) {
        uVar12 = uVar12 - uVar15;
      }
      else if (local_48 == 2) {
        uVar12 = (int)(uVar12 - uVar15) >> 1;
      }
      else {
        uVar12 = (int)(uVar12 - uVar15) / local_48;
      }
      if ((uVar13 == uVar14) || (local_48 == 1)) {
        uVar13 = uVar13 - uVar14;
      }
      else if (local_48 == 2) {
        uVar13 = (int)(uVar13 - uVar14) >> 1;
      }
      else {
        uVar13 = (int)(uVar13 - uVar14) / local_48;
      }
      uVar2 = uVar2 & 0xffff;
      if ((local_10 == local_38) || (iVar4 == 1)) {
        uVar2 = uVar2 - (uVar1 & 0xffff);
      }
      else if (iVar4 == 2) {
        uVar2 = (int)(uVar2 - (uVar1 & 0xffff)) >> 1;
      }
      else {
        uVar2 = (int)(uVar2 - (uVar1 & 0xffff)) / iVar4;
      }
      uVar6 = uVar1 & 0xffff;
      DAT_1007b2d4 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
      local_20 = local_20 & 0xffff;
      if ((local_2c == local_38) || (local_48 == 1)) {
        local_20 = local_20 - uVar6;
      }
      else if (local_48 == 2) {
        local_20 = (int)(local_20 - uVar6) >> 1;
      }
      else {
        local_20 = (int)(local_20 - uVar6) / local_48;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b2d0 = (local_20 & 0xffff) + (local_20 & 0x8000) * -2;
      DAT_1007b284 = iVar17 << 0x10;
      DAT_1007b2c0 = (uVar15 & 0xfffe) >> 1 | (uVar14 & 0xfffe) << 0xf;
      DAT_1007b2c8 = (uVar20 & 0xfffe) << 0xf | (uVar18 & 0xfffe) >> 1;
      DAT_1007b2c4 = (uVar13 & 0xfffe) << 0xf | (uVar12 & 0xfffe) >> 1;
      DAT_1007b2cc = uVar1;
      goto LAB_1001a2cb;
    }
    iVar5 = iVar17 - DAT_1007b280;
    iVar11 = iVar4;
    if (iVar4 == 1) {
      DAT_1007b288 = iVar5 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007b288 = iVar5 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar3 + (iVar5 * 0x20 + iVar4) * 4);
      iVar11 = iVar3;
    }
    else if (iVar5 < 0) {
      DAT_1007b288 = (iVar5 * 0x10000) / iVar4;
      iVar11 = (iVar5 * 0x10000) % iVar4;
    }
    else {
      DAT_1007b288 = (iVar5 * 0x10000) / iVar4;
      iVar11 = (iVar5 * 0x10000) % iVar4;
    }
    uVar6 = DAT_1007b288 - DAT_1007b28c;
    if ((int)uVar6 < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    if ((uVar12 == uVar15) || (local_48 == 1)) {
      uVar7 = uVar12 - uVar15;
    }
    else if (local_48 == 2) {
      uVar7 = (int)(uVar12 - uVar15) >> 1;
    }
    else {
      uVar7 = (int)(uVar12 - uVar15) / local_48;
      iVar11 = (int)(uVar12 - uVar15) % local_48;
    }
    if ((uVar13 == uVar14) || (local_48 == 1)) {
      uVar8 = uVar13 - uVar14;
    }
    else if (local_48 == 2) {
      uVar8 = (int)(uVar13 - uVar14) >> 1;
    }
    else {
      uVar8 = (int)(uVar13 - uVar14) / local_48;
      iVar11 = (int)(uVar13 - uVar14) % local_48;
    }
    if ((uVar18 == uVar15) || (iVar4 == 1)) {
      iVar5 = uVar18 - uVar15;
    }
    else if (iVar4 == 2) {
      iVar5 = (int)(uVar18 - uVar15) >> 1;
    }
    else {
      iVar5 = (int)(uVar18 - uVar15) / iVar4;
      iVar11 = (int)(uVar18 - uVar15) % iVar4;
    }
    iVar5 = iVar5 - uVar7;
    uVar21 = CONCAT44(iVar11,iVar5);
    if (iVar5 != 0) {
      uVar21 = FUN_10063324(iVar5,iVar11,iVar5,uVar6);
    }
    iVar11 = (int)((ulonglong)uVar21 >> 0x20);
    local_1c = (uint)uVar21;
    if ((uVar20 == uVar14) || (iVar4 == 1)) {
      iVar5 = uVar20 - uVar14;
    }
    else if (iVar4 == 2) {
      iVar5 = (int)(uVar20 - uVar14) >> 1;
    }
    else {
      iVar5 = (int)(uVar20 - uVar14) / iVar4;
      iVar11 = (int)(uVar20 - uVar14) % iVar4;
    }
    iVar5 = iVar5 - uVar8;
    uVar9 = 0;
    if (iVar5 != 0) {
      uVar21 = FUN_10063324(iVar5,iVar11,iVar5,uVar6);
      uVar9 = (uint)uVar21;
    }
    uVar19 = uVar1 & 0xffff;
    if ((local_2c == local_38) || (local_48 == 1)) {
      uVar10 = (local_20 & 0xffff) - uVar19;
    }
    else if (local_48 == 2) {
      uVar10 = (int)((local_20 & 0xffff) - uVar19) >> 1;
    }
    else {
      uVar10 = (int)((local_20 & 0xffff) - uVar19) / local_48;
    }
    local_20 = local_20 & 0xffff;
    DAT_1007b2d4 = 0;
    DAT_1007b2d0 = (uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
    if ((local_10 == local_38) || (iVar4 == 1)) {
      iVar11 = (uVar2 & 0xffff) - uVar19;
    }
    else if (iVar4 == 2) {
      iVar11 = (int)((uVar2 & 0xffff) - uVar19) >> 1;
    }
    else {
      iVar11 = (int)((uVar2 & 0xffff) - uVar19) / iVar4;
    }
    uVar2 = uVar2 & 0xffff;
    if (iVar11 - (short)DAT_1007b2d0 != 0) {
      uVar6 = ((iVar11 - (short)DAT_1007b2d0) * 0x10000) / (int)uVar6;
      DAT_1007b2d4 = (uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
    }
    DAT_1007b280 = DAT_1007b280 << 0x10;
    DAT_1007b284 = DAT_1007b280;
    if (iVar4 <= local_48) {
      DAT_1007b2c0 = (uVar15 & 0xfffe) >> 1 | (uVar14 & 0xfffe) << 0xf;
      DAT_1007b2c8 = (uVar9 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
      DAT_1007b2c4 = (uVar8 & 0xfffe) << 0xf | (uVar7 & 0xfffe) >> 1;
      local_48 = local_48 - iVar4;
      DAT_1007b290 = iVar4;
      DAT_1007b2cc = uVar1;
      FUN_1001a2f0((uint *)&DAT_1007b280);
      if (local_48 == 0) {
        return;
      }
      DAT_1007b284 = iVar17 << 0x10;
      iVar16 = iVar16 - iVar17;
      if (local_48 == 1) {
        DAT_1007b288 = iVar16 * 0x10000;
      }
      else if (local_48 == 2) {
        DAT_1007b288 = iVar16 * 0x8000;
      }
      else if (((local_48 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar3 + (iVar16 * 0x20 + local_48) * 4);
      }
      else if (iVar16 < 0) {
        DAT_1007b288 = (iVar16 * 0x10000) / local_48;
      }
      else {
        DAT_1007b288 = (iVar16 * 0x10000) / local_48;
      }
      goto LAB_1001a2cb;
    }
    DAT_1007b2c0 = (uVar15 & 0xfffe) >> 1 | (uVar14 & 0xfffe) << 0xf;
    uVar15 = (uVar9 & 0xfffe) << 0xf | (local_1c & 0xfffe) >> 1;
    DAT_1007b2c4 = (uVar8 & 0xfffe) << 0xf | (uVar7 & 0xfffe) >> 1;
    iVar4 = iVar4 - local_48;
    DAT_1007b290 = local_48;
    DAT_1007b2c8 = uVar15;
    DAT_1007b2cc = uVar1;
    FUN_1001a2f0((uint *)&DAT_1007b280);
    iVar17 = iVar17 - iVar16;
    if (iVar4 == 1) {
      DAT_1007b28c = iVar17 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007b28c = iVar17 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar3 + (iVar17 * 0x20 + iVar4) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1007b28c = (iVar17 * 0x10000) / iVar4;
    }
    else {
      DAT_1007b28c = (iVar17 * 0x10000) / iVar4;
    }
    if ((uVar18 == uVar12) || (iVar4 == 1)) {
      uVar18 = uVar18 - uVar12;
    }
    else if (iVar4 == 2) {
      uVar18 = (int)(uVar18 - uVar12) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar12) / iVar4;
    }
    if ((uVar20 == uVar13) || (iVar4 == 1)) {
      uVar20 = uVar20 - uVar13;
    }
    else if (iVar4 == 2) {
      uVar20 = (int)(uVar20 - uVar13) >> 1;
    }
    else {
      uVar20 = (int)(uVar20 - uVar13) / iVar4;
    }
    DAT_1007b2d0 = 0;
    if ((local_10 == local_2c) || (iVar4 == 1)) {
      uVar2 = uVar2 - local_20;
    }
    else if (iVar4 == 2) {
      uVar2 = (int)(uVar2 - local_20) >> 1;
    }
    else {
      uVar2 = (int)(uVar2 - local_20) / iVar4;
    }
    local_48 = iVar4;
    if (uVar2 != 0) {
      DAT_1007b2d0 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
    }
  }
  DAT_1007b280 = iVar16 << 0x10;
  DAT_1007b2c4 = (uVar20 & 0xfffe) << 0xf | (uVar18 & 0xfffe) >> 1;
  DAT_1007b2c8 = uVar15;
LAB_1001a2cb:
  DAT_1007b290 = local_48;
  FUN_1001a2f0((uint *)&DAT_1007b280);
  return;
}


