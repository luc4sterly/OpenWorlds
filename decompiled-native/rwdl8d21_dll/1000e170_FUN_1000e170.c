// 1000e170 FUN_1000e170 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000e170(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  uint uVar13;
  int local_18;
  short local_8;
  
  iVar1 = param_3;
  iVar12 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      param_2 = param_4;
      iVar12 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1000e1b8;
  param_4 = iVar1;
  param_3 = param_2;
  param_2 = iVar12;
LAB_1000e1b8:
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  local_18 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  iVar1 = (int)*(short *)(param_2 + 0x1a);
  uVar4 = *(uint *)(*param_1 + 8);
  uVar2 = uVar4 & 0x20;
  if (uVar2 == 0) {
    iVar12 = *(int *)(param_2 + 0x58);
  }
  else {
    iVar12 = 0x1f0000 - *(int *)(param_2 + 0x58);
  }
  iVar10 = (int)*(short *)(param_3 + 0x1a);
  iVar9 = (uVar4 & 0xe0) * 0x100;
  uVar13 = (iVar12 >> 8) + iVar9;
  if (uVar2 == 0) {
    iVar12 = *(int *)(param_3 + 0x58);
  }
  else {
    iVar12 = 0x1f0000 - *(int *)(param_3 + 0x58);
  }
  iVar6 = (int)*(short *)(param_4 + 0x1a);
  uVar8 = (iVar12 >> 8) + iVar9;
  if (uVar2 == 0) {
    iVar12 = *(int *)(param_4 + 0x58);
  }
  else {
    iVar12 = 0x1f0000 - *(int *)(param_4 + 0x58);
  }
  uVar2 = (iVar12 >> 8) + iVar9;
  iVar12 = DAT_10075214 + 0x1000;
  DAT_1007b2b4 = (uVar4 & 0xff00) + DAT_1007521c;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  sVar11 = (short)uVar13;
  sVar7 = (short)uVar8;
  local_8 = (short)uVar2;
  if (local_18 < 1) {
    iVar9 = iVar1 - iVar10;
    if (iVar9 < 1) {
      DAT_1007b280 = iVar1;
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    local_18 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_18 == 0) {
      DAT_1007b280 = iVar1;
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    iVar3 = iVar6 - iVar10;
    if (local_18 == 1) {
      DAT_1007b28c = iVar3 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1007b28c = iVar3 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar12 + (iVar3 * 0x20 + local_18) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1007b28c = (iVar3 * 0x10000) / local_18;
    }
    else {
      DAT_1007b28c = (iVar3 * 0x10000) / local_18;
    }
    iVar6 = iVar6 - iVar1;
    if (local_18 == 1) {
      DAT_1007b288 = iVar6 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1007b288 = iVar6 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar12 + (iVar6 * 0x20 + local_18) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b288 = (iVar6 * 0x10000) / local_18;
    }
    else {
      DAT_1007b288 = (iVar6 * 0x10000) / local_18;
    }
    uVar13 = uVar13 & 0xffff;
    if ((sVar7 == sVar11) || (iVar9 == 1)) {
      uVar13 = uVar13 - (uVar8 & 0xffff);
    }
    else if (iVar9 == 2) {
      uVar13 = (int)(uVar13 - (uVar8 & 0xffff)) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - (uVar8 & 0xffff)) / iVar9;
    }
    uVar4 = uVar8 & 0xffff;
    DAT_1007b2c8 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
    uVar2 = uVar2 & 0xffff;
    if ((local_8 == sVar7) || (local_18 == 1)) {
      uVar2 = uVar2 - uVar4;
    }
    else if (local_18 == 2) {
      uVar2 = (int)(uVar2 - uVar4) >> 1;
    }
    else {
      uVar2 = (int)(uVar2 - uVar4) / local_18;
    }
    DAT_1007b280 = iVar10 << 0x10;
    DAT_1007b2c4 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
    DAT_1007b284 = iVar1 << 0x10;
    DAT_1007b2c0 = uVar8;
  }
  else {
    iVar9 = iVar10 - iVar1;
    if (local_18 == 1) {
      DAT_1007b28c = iVar9 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1007b28c = iVar9 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar12 + (iVar9 * 0x20 + local_18) * 4);
    }
    else if (iVar9 < 0) {
      DAT_1007b28c = (iVar9 * 0x10000) / local_18;
    }
    else {
      DAT_1007b28c = (iVar9 * 0x10000) / local_18;
    }
    iVar9 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (iVar9 < 1) {
      iVar9 = iVar6 - iVar1;
      if (iVar9 < 1) {
        DAT_1007b280 = iVar1;
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      iVar10 = iVar10 - iVar6;
      if (local_18 == 1) {
        DAT_1007b288 = iVar10 * 0x10000;
      }
      else if (local_18 == 2) {
        DAT_1007b288 = iVar10 * 0x8000;
      }
      else if (((local_18 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar12 + (iVar10 * 0x20 + local_18) * 4);
      }
      else if (iVar10 < 0) {
        DAT_1007b288 = (iVar10 * 0x10000) / local_18;
      }
      else {
        DAT_1007b288 = (iVar10 * 0x10000) / local_18;
      }
      uVar2 = uVar2 & 0xffff;
      if ((local_8 == sVar11) || (iVar9 == 1)) {
        uVar2 = uVar2 - (uVar13 & 0xffff);
      }
      else if (iVar9 == 2) {
        uVar2 = (int)(uVar2 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        uVar2 = (int)(uVar2 - (uVar13 & 0xffff)) / iVar9;
      }
      uVar4 = uVar13 & 0xffff;
      DAT_1007b2c8 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
      uVar8 = uVar8 & 0xffff;
      if ((sVar7 == sVar11) || (local_18 == 1)) {
        uVar8 = uVar8 - uVar4;
      }
      else if (local_18 == 2) {
        uVar8 = (int)(uVar8 - uVar4) >> 1;
      }
      else {
        uVar8 = (int)(uVar8 - uVar4) / local_18;
      }
      DAT_1007b280 = iVar1 << 0x10;
      DAT_1007b2c4 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      DAT_1007b284 = iVar6 << 0x10;
      DAT_1007b2c0 = uVar13;
    }
    else {
      iVar3 = iVar6 - iVar1;
      if (iVar9 == 1) {
        DAT_1007b288 = iVar3 * 0x10000;
      }
      else if (iVar9 == 2) {
        DAT_1007b288 = iVar3 * 0x8000;
      }
      else if (((iVar9 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar12 + (iVar3 * 0x20 + iVar9) * 4);
      }
      else if (iVar3 < 0) {
        DAT_1007b288 = (iVar3 * 0x10000) / iVar9;
      }
      else {
        DAT_1007b288 = (iVar3 * 0x10000) / iVar9;
      }
      if (DAT_1007b288 - DAT_1007b28c < 1) {
        DAT_1007b280 = iVar1;
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      if ((sVar7 == sVar11) || (local_18 == 1)) {
        uVar4 = (uVar8 & 0xffff) - (uVar13 & 0xffff);
      }
      else if (local_18 == 2) {
        uVar4 = (int)((uVar8 & 0xffff) - (uVar13 & 0xffff)) >> 1;
      }
      else {
        uVar4 = (int)((uVar8 & 0xffff) - (uVar13 & 0xffff)) / local_18;
      }
      uVar8 = uVar8 & 0xffff;
      uVar5 = uVar13 & 0xffff;
      DAT_1007b2c8 = 0;
      DAT_1007b2c4 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
      if ((local_8 == sVar11) || (iVar9 == 1)) {
        iVar3 = (uVar2 & 0xffff) - uVar5;
      }
      else if (iVar9 == 2) {
        iVar3 = (int)((uVar2 & 0xffff) - uVar5) >> 1;
      }
      else {
        iVar3 = (int)((uVar2 & 0xffff) - uVar5) / iVar9;
      }
      uVar2 = uVar2 & 0xffff;
      if (iVar3 - (short)DAT_1007b2c4 != 0) {
        uVar4 = ((iVar3 - (short)DAT_1007b2c4) * 0x10000) / (DAT_1007b288 - DAT_1007b28c);
        DAT_1007b2c8 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
      }
      DAT_1007b280 = iVar1 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (local_18 < iVar9) {
        iVar9 = iVar9 - local_18;
        DAT_1007b290 = local_18;
        DAT_1007b2c0 = uVar13;
        FUN_10064240();
        DAT_1007b280 = iVar10 << 0x10;
        iVar6 = iVar6 - iVar10;
        if (iVar9 == 1) {
          DAT_1007b28c = iVar6 * 0x10000;
        }
        else if (iVar9 == 2) {
          DAT_1007b28c = iVar6 * 0x8000;
        }
        else if (((iVar9 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar12 + (iVar6 * 0x20 + iVar9) * 4);
        }
        else if (iVar6 < 0) {
          DAT_1007b28c = (iVar6 * 0x10000) / iVar9;
        }
        else {
          DAT_1007b28c = (iVar6 * 0x10000) / iVar9;
        }
        DAT_1007b2c4 = 0;
        if ((local_8 == sVar7) || (iVar9 == 1)) {
          uVar2 = uVar2 - uVar8;
        }
        else if (iVar9 == 2) {
          uVar2 = (int)(uVar2 - uVar8) >> 1;
        }
        else {
          uVar2 = (int)(uVar2 - uVar8) / iVar9;
        }
        local_18 = iVar9;
        if (uVar2 != 0) {
          DAT_1007b2c4 = (uVar2 & 0xffff) + (uVar2 & 0x8000) * -2;
        }
      }
      else {
        local_18 = local_18 - iVar9;
        DAT_1007b290 = iVar9;
        DAT_1007b2c0 = uVar13;
        FUN_10064240();
        if (local_18 == 0) {
          return;
        }
        DAT_1007b284 = iVar6 << 0x10;
        iVar10 = iVar10 - iVar6;
        if (local_18 == 1) {
          DAT_1007b288 = iVar10 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1007b288 = iVar10 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar12 + (iVar10 * 0x20 + local_18) * 4);
        }
        else if (iVar10 < 0) {
          DAT_1007b288 = (iVar10 * 0x10000) / local_18;
        }
        else {
          DAT_1007b288 = (iVar10 * 0x10000) / local_18;
        }
      }
    }
  }
  DAT_1007b290 = local_18;
  FUN_10064240();
  return;
}


