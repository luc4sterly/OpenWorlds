// 1000f6e0 FUN_1000f6e0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f6e0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  uint uVar13;
  int local_1c;
  short local_10;
  
  iVar5 = param_2;
  iVar12 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    iVar6 = param_3;
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar5 = param_4;
      iVar6 = param_2;
      iVar12 = param_3;
    }
  }
  else {
    iVar6 = param_3;
    if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1000f729;
  }
  param_4 = iVar6;
  param_3 = iVar5;
  param_2 = iVar12;
LAB_1000f729:
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  local_1c = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  iVar5 = (int)*(short *)(param_2 + 0x1a);
  uVar13 = *(uint *)(*param_1 + 8);
  uVar7 = uVar13 & 0x20;
  if (uVar7 == 0) {
    iVar12 = *(int *)(param_2 + 0x58);
  }
  else {
    iVar12 = 0x1f0000 - *(int *)(param_2 + 0x58);
  }
  iVar10 = (int)*(short *)(param_3 + 0x1a);
  iVar6 = (uVar13 & 0xe0) * 0x100;
  uVar13 = (iVar12 >> 8) + iVar6;
  if (uVar7 == 0) {
    iVar12 = *(int *)(param_3 + 0x58);
  }
  else {
    iVar12 = 0x1f0000 - *(int *)(param_3 + 0x58);
  }
  iVar1 = (int)*(short *)(param_4 + 0x1a);
  uVar9 = (iVar12 >> 8) + iVar6;
  if (uVar7 == 0) {
    iVar12 = *(int *)(param_4 + 0x58);
  }
  else {
    iVar12 = 0x1f0000 - *(int *)(param_4 + 0x58);
  }
  uVar7 = (iVar12 >> 8) + iVar6;
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar12 = DAT_10075214 + 0x1000;
  DAT_1007b2b4 = (*(uint *)(*param_1 + 8) & 0xff00) + DAT_1007521c;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  sVar11 = (short)uVar13;
  sVar8 = (short)uVar9;
  local_10 = (short)uVar7;
  if (local_1c < 1) {
    iVar6 = iVar5 - iVar10;
    if (iVar6 < 1) {
      DAT_1007b280 = iVar5;
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    local_1c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_1c == 0) {
      DAT_1007b280 = iVar5;
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    iVar2 = iVar1 - iVar10;
    if (local_1c == 1) {
      DAT_1007b28c = iVar2 * 0x10000;
    }
    else if (local_1c == 2) {
      DAT_1007b28c = iVar2 * 0x8000;
    }
    else if (((local_1c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar12 + (iVar2 * 0x20 + local_1c) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007b28c = (iVar2 * 0x10000) / local_1c;
    }
    else {
      DAT_1007b28c = (iVar2 * 0x10000) / local_1c;
    }
    iVar1 = iVar1 - iVar5;
    if (local_1c == 1) {
      DAT_1007b288 = iVar1 * 0x10000;
    }
    else if (local_1c == 2) {
      DAT_1007b288 = iVar1 * 0x8000;
    }
    else if (((local_1c < 0x20) && (-0x20 < iVar1)) && (iVar1 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar12 + (iVar1 * 0x20 + local_1c) * 4);
    }
    else if (iVar1 < 0) {
      DAT_1007b288 = (iVar1 * 0x10000) / local_1c;
    }
    else {
      DAT_1007b288 = (iVar1 * 0x10000) / local_1c;
    }
    uVar13 = uVar13 & 0xffff;
    if ((sVar8 == sVar11) || (iVar6 == 1)) {
      uVar13 = uVar13 - (uVar9 & 0xffff);
    }
    else if (iVar6 == 2) {
      uVar13 = (int)(uVar13 - (uVar9 & 0xffff)) >> 1;
    }
    else {
      uVar13 = (int)(uVar13 - (uVar9 & 0xffff)) / iVar6;
    }
    uVar3 = uVar9 & 0xffff;
    DAT_1007b2c8 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
    uVar7 = uVar7 & 0xffff;
    if ((local_10 == sVar8) || (local_1c == 1)) {
      uVar7 = uVar7 - uVar3;
    }
    else if (local_1c == 2) {
      uVar7 = (int)(uVar7 - uVar3) >> 1;
    }
    else {
      uVar7 = (int)(uVar7 - uVar3) / local_1c;
    }
    DAT_1007b280 = iVar10 << 0x10;
    DAT_1007b2c4 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
    DAT_1007b284 = iVar5 << 0x10;
    DAT_1007b2c0 = uVar9;
  }
  else {
    iVar6 = iVar10 - iVar5;
    if (local_1c == 1) {
      DAT_1007b28c = iVar6 * 0x10000;
    }
    else if (local_1c == 2) {
      DAT_1007b28c = iVar6 * 0x8000;
    }
    else if (((local_1c < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar12 + (iVar6 * 0x20 + local_1c) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b28c = (iVar6 * 0x10000) / local_1c;
    }
    else {
      DAT_1007b28c = (iVar6 * 0x10000) / local_1c;
    }
    iVar6 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (iVar6 < 1) {
      iVar6 = iVar1 - iVar5;
      if (iVar6 < 1) {
        DAT_1007b280 = iVar5;
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      iVar10 = iVar10 - iVar1;
      if (local_1c == 1) {
        DAT_1007b288 = iVar10 * 0x10000;
      }
      else if (local_1c == 2) {
        DAT_1007b288 = iVar10 * 0x8000;
      }
      else if (((local_1c < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar12 + (iVar10 * 0x20 + local_1c) * 4);
      }
      else if (iVar10 < 0) {
        DAT_1007b288 = (iVar10 * 0x10000) / local_1c;
      }
      else {
        DAT_1007b288 = (iVar10 * 0x10000) / local_1c;
      }
      uVar7 = uVar7 & 0xffff;
      if ((local_10 == sVar11) || (iVar6 == 1)) {
        uVar7 = uVar7 - (uVar13 & 0xffff);
      }
      else if (iVar6 == 2) {
        uVar7 = (int)(uVar7 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        uVar7 = (int)(uVar7 - (uVar13 & 0xffff)) / iVar6;
      }
      uVar3 = uVar13 & 0xffff;
      DAT_1007b2c8 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      uVar9 = uVar9 & 0xffff;
      if ((sVar8 == sVar11) || (local_1c == 1)) {
        uVar9 = uVar9 - uVar3;
      }
      else if (local_1c == 2) {
        uVar9 = (int)(uVar9 - uVar3) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - uVar3) / local_1c;
      }
      DAT_1007b280 = iVar5 << 0x10;
      DAT_1007b2c4 = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      DAT_1007b284 = iVar1 << 0x10;
      DAT_1007b2c0 = uVar13;
    }
    else {
      iVar2 = iVar1 - iVar5;
      if (iVar6 == 1) {
        DAT_1007b288 = iVar2 * 0x10000;
      }
      else if (iVar6 == 2) {
        DAT_1007b288 = iVar2 * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar12 + (iVar2 * 0x20 + iVar6) * 4);
      }
      else if (iVar2 < 0) {
        DAT_1007b288 = (iVar2 * 0x10000) / iVar6;
      }
      else {
        DAT_1007b288 = (iVar2 * 0x10000) / iVar6;
      }
      if (DAT_1007b288 - DAT_1007b28c < 1) {
        DAT_1007b280 = iVar5;
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      if ((sVar8 == sVar11) || (local_1c == 1)) {
        uVar3 = (uVar9 & 0xffff) - (uVar13 & 0xffff);
      }
      else if (local_1c == 2) {
        uVar3 = (int)((uVar9 & 0xffff) - (uVar13 & 0xffff)) >> 1;
      }
      else {
        uVar3 = (int)((uVar9 & 0xffff) - (uVar13 & 0xffff)) / local_1c;
      }
      uVar9 = uVar9 & 0xffff;
      uVar4 = uVar13 & 0xffff;
      DAT_1007b2c8 = 0;
      DAT_1007b2c4 = (uVar3 & 0xffff) + (uVar3 & 0x8000) * -2;
      if ((local_10 == sVar11) || (iVar6 == 1)) {
        iVar2 = (uVar7 & 0xffff) - uVar4;
      }
      else if (iVar6 == 2) {
        iVar2 = (int)((uVar7 & 0xffff) - uVar4) >> 1;
      }
      else {
        iVar2 = (int)((uVar7 & 0xffff) - uVar4) / iVar6;
      }
      uVar7 = uVar7 & 0xffff;
      if (iVar2 - (short)DAT_1007b2c4 != 0) {
        uVar3 = ((iVar2 - (short)DAT_1007b2c4) * 0x10000) / (DAT_1007b288 - DAT_1007b28c);
        DAT_1007b2c8 = (uVar3 & 0xffff) + (uVar3 & 0x8000) * -2;
      }
      DAT_1007b280 = iVar5 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (local_1c < iVar6) {
        iVar6 = iVar6 - local_1c;
        DAT_1007b290 = local_1c;
        DAT_1007b2c0 = uVar13;
        FUN_10010000((uint *)&DAT_1007b280);
        DAT_1007b280 = iVar10 << 0x10;
        iVar1 = iVar1 - iVar10;
        if (iVar6 == 1) {
          DAT_1007b28c = iVar1 * 0x10000;
        }
        else if (iVar6 == 2) {
          DAT_1007b28c = iVar1 * 0x8000;
        }
        else if (((iVar6 < 0x20) && (-0x20 < iVar1)) && (iVar1 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar12 + (iVar1 * 0x20 + iVar6) * 4);
        }
        else if (iVar1 < 0) {
          DAT_1007b28c = (iVar1 * 0x10000) / iVar6;
        }
        else {
          DAT_1007b28c = (iVar1 * 0x10000) / iVar6;
        }
        DAT_1007b2c4 = 0;
        if ((local_10 == sVar8) || (iVar6 == 1)) {
          uVar7 = uVar7 - uVar9;
        }
        else if (iVar6 == 2) {
          uVar7 = (int)(uVar7 - uVar9) >> 1;
        }
        else {
          uVar7 = (int)(uVar7 - uVar9) / iVar6;
        }
        local_1c = iVar6;
        if (uVar7 != 0) {
          DAT_1007b2c4 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
        }
      }
      else {
        local_1c = local_1c - iVar6;
        DAT_1007b290 = iVar6;
        DAT_1007b2c0 = uVar13;
        FUN_10010000((uint *)&DAT_1007b280);
        if (local_1c == 0) {
          return;
        }
        DAT_1007b284 = iVar1 << 0x10;
        iVar10 = iVar10 - iVar1;
        if (local_1c == 1) {
          DAT_1007b288 = iVar10 * 0x10000;
        }
        else if (local_1c == 2) {
          DAT_1007b288 = iVar10 * 0x8000;
        }
        else if (((local_1c < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar12 + (iVar10 * 0x20 + local_1c) * 4);
        }
        else if (iVar10 < 0) {
          DAT_1007b288 = (iVar10 * 0x10000) / local_1c;
        }
        else {
          DAT_1007b288 = (iVar10 * 0x10000) / local_1c;
        }
      }
    }
  }
  DAT_1007b290 = local_1c;
  FUN_10010000((uint *)&DAT_1007b280);
  return;
}


