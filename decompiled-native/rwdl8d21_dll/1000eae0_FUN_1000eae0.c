// 1000eae0 FUN_1000eae0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000eae0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  short sVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int local_24;
  uint local_18;
  short local_c;
  
  iVar7 = param_4;
  iVar14 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    iVar1 = param_3;
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      iVar7 = param_3;
      iVar14 = param_4;
    }
LAB_1000eb27:
    param_4 = iVar1;
    param_2 = iVar7;
    param_3 = iVar14;
  }
  else {
    iVar1 = param_3;
    if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1000eb27;
  }
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar7 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar16 = *(uint *)(*param_1 + 8) & 0x20;
  if (uVar16 == 0) {
    iVar14 = *(int *)(param_2 + 0x58);
  }
  else {
    iVar14 = 0x1f0000 - *(int *)(param_2 + 0x58);
  }
  iVar8 = (*(uint *)(*param_1 + 8) & 0xe0) * 0x100;
  iVar1 = *(int *)(param_2 + 0x20);
  iVar11 = (int)*(short *)(param_3 + 0x1a);
  uVar15 = (iVar14 >> 8) + iVar8;
  if (uVar16 == 0) {
    iVar14 = *(int *)(param_3 + 0x58);
  }
  else {
    iVar14 = 0x1f0000 - *(int *)(param_3 + 0x58);
  }
  iVar2 = *(int *)(param_3 + 0x20);
  local_18 = (iVar14 >> 8) + iVar8;
  iVar14 = (int)*(short *)(param_4 + 0x1a);
  if (uVar16 == 0) {
    iVar12 = *(int *)(param_4 + 0x58);
  }
  else {
    iVar12 = 0x1f0000 - *(int *)(param_4 + 0x58);
  }
  iVar3 = *(int *)(param_4 + 0x20);
  uVar16 = iVar8 + (iVar12 >> 8);
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2a0 = DAT_10077eb0;
  DAT_1007b2b4 = (*(uint *)(*param_1 + 8) & 0xff00) + DAT_1007521c;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar8 = DAT_10075214 + 0x1000;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  sVar13 = (short)uVar15;
  local_c = (short)uVar16;
  sVar10 = (short)local_18;
  if (iVar7 < 1) {
    iVar7 = DAT_1007b280 - iVar11;
    if (iVar7 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    local_24 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_24 == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar12 = iVar14 - iVar11;
    if (local_24 == 1) {
      DAT_1007b28c = iVar12 * 0x10000;
    }
    else if (local_24 == 2) {
      DAT_1007b28c = iVar12 * 0x8000;
    }
    else if (((local_24 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar8 + (iVar12 * 0x20 + local_24) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1007b28c = (iVar12 * 0x10000) / local_24;
    }
    else {
      DAT_1007b28c = (iVar12 * 0x10000) / local_24;
    }
    iVar14 = iVar14 - DAT_1007b280;
    if (local_24 == 1) {
      DAT_1007b288 = iVar14 * 0x10000;
    }
    else if (local_24 == 2) {
      DAT_1007b288 = iVar14 * 0x8000;
    }
    else if (((local_24 < 0x20) && (-0x20 < iVar14)) && (iVar14 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar8 + (iVar14 * 0x20 + local_24) * 4);
    }
    else if (iVar14 < 0) {
      DAT_1007b288 = (iVar14 * 0x10000) / local_24;
    }
    else {
      DAT_1007b288 = (iVar14 * 0x10000) / local_24;
    }
    if ((iVar2 == iVar1) || (iVar7 == 1)) {
      DAT_1007b2ec = iVar1 - iVar2;
    }
    else if (iVar7 == 2) {
      DAT_1007b2ec = iVar1 - iVar2 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar1 - iVar2) / iVar7;
    }
    if ((iVar3 == iVar2) || (local_24 == 1)) {
      DAT_1007b2e8 = iVar3 - iVar2;
    }
    else if (local_24 == 2) {
      DAT_1007b2e8 = iVar3 - iVar2 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar3 - iVar2) / local_24;
    }
    uVar15 = uVar15 & 0xffff;
    uVar5 = local_18 & 0xffff;
    if ((sVar10 == sVar13) || (iVar7 == 1)) {
      uVar15 = uVar15 - uVar5;
    }
    else if (iVar7 == 2) {
      uVar15 = (int)(uVar15 - uVar5) >> 1;
    }
    else {
      uVar15 = (int)(uVar15 - uVar5) / iVar7;
    }
    DAT_1007b2c8 = (uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    uVar16 = uVar16 & 0xffff;
    if ((local_c == sVar10) || (local_24 == 1)) {
      uVar16 = uVar16 - uVar5;
    }
    else if (local_24 == 2) {
      uVar16 = (int)(uVar16 - uVar5) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - uVar5) / local_24;
    }
    DAT_1007b2c4 = (uVar16 & 0xffff) + (uVar16 & 0x8000) * -2;
    DAT_1007b2c0 = local_18;
  }
  else {
    iVar12 = iVar11 - DAT_1007b280;
    if (iVar7 == 1) {
      DAT_1007b28c = iVar12 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1007b28c = iVar12 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar12)) && (iVar12 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar8 + (iVar12 * 0x20 + iVar7) * 4);
    }
    else if (iVar12 < 0) {
      DAT_1007b28c = (iVar12 * 0x10000) / iVar7;
    }
    else {
      DAT_1007b28c = (iVar12 * 0x10000) / iVar7;
    }
    iVar12 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (0 < iVar12) {
      iVar4 = iVar14 - DAT_1007b280;
      if (iVar12 == 1) {
        DAT_1007b288 = iVar4 * 0x10000;
      }
      else if (iVar12 == 2) {
        DAT_1007b288 = iVar4 * 0x8000;
      }
      else if (((iVar12 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar8 + (iVar4 * 0x20 + iVar12) * 4);
      }
      else if (iVar4 < 0) {
        DAT_1007b288 = (iVar4 * 0x10000) / iVar12;
      }
      else {
        DAT_1007b288 = (iVar4 * 0x10000) / iVar12;
      }
      iVar4 = DAT_1007b288 - DAT_1007b28c;
      if (iVar4 < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        return;
      }
      if ((sVar10 == sVar13) || (iVar7 == 1)) {
        uVar5 = (local_18 & 0xffff) - (uVar15 & 0xffff);
      }
      else if (iVar7 == 2) {
        uVar5 = (int)((local_18 & 0xffff) - (uVar15 & 0xffff)) >> 1;
      }
      else {
        uVar5 = (int)((local_18 & 0xffff) - (uVar15 & 0xffff)) / iVar7;
      }
      local_18 = local_18 & 0xffff;
      uVar9 = uVar15 & 0xffff;
      DAT_1007b2c8 = 0;
      DAT_1007b2c4 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      if ((local_c == sVar13) || (iVar12 == 1)) {
        iVar6 = (uVar16 & 0xffff) - uVar9;
      }
      else if (iVar12 == 2) {
        iVar6 = (int)((uVar16 & 0xffff) - uVar9) >> 1;
      }
      else {
        iVar6 = (int)((uVar16 & 0xffff) - uVar9) / iVar12;
      }
      uVar16 = uVar16 & 0xffff;
      if (iVar6 - (short)DAT_1007b2c4 != 0) {
        uVar5 = ((iVar6 - (short)DAT_1007b2c4) * 0x10000) / iVar4;
        DAT_1007b2c8 = (uVar5 & 0xffff) + (uVar5 & 0x8000) * -2;
      }
      if ((iVar2 == iVar1) || (iVar7 == 1)) {
        DAT_1007b2e8 = iVar2 - iVar1;
      }
      else if (iVar7 == 2) {
        DAT_1007b2e8 = iVar2 - iVar1 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar2 - iVar1) / iVar7;
      }
      if ((iVar3 == iVar1) || (iVar12 == 1)) {
        iVar6 = iVar3 - iVar1;
      }
      else if (iVar12 == 2) {
        iVar6 = iVar3 - iVar1 >> 1;
      }
      else {
        iVar6 = (iVar3 - iVar1) / iVar12;
      }
      DAT_1007b2ec = iVar6 - DAT_1007b2e8;
      if ((DAT_1007b2ec != 0) && (iVar4 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / (iVar4 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar7 < iVar12) {
        local_24 = iVar12 - iVar7;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar7;
        DAT_1007b2c0 = uVar15;
        FUN_10064328();
        DAT_1007b280 = iVar11 << 0x10;
        iVar14 = iVar14 - iVar11;
        if (local_24 == 1) {
          DAT_1007b28c = iVar14 * 0x10000;
        }
        else if (local_24 == 2) {
          DAT_1007b28c = iVar14 * 0x8000;
        }
        else if (((local_24 < 0x20) && (-0x20 < iVar14)) && (iVar14 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar8 + (iVar14 * 0x20 + local_24) * 4);
        }
        else if (iVar14 < 0) {
          DAT_1007b28c = (iVar14 * 0x10000) / local_24;
        }
        else {
          DAT_1007b28c = (iVar14 * 0x10000) / local_24;
        }
        DAT_1007b2c4 = 0;
        if ((local_c == sVar10) || (local_24 == 1)) {
          uVar16 = uVar16 - local_18;
        }
        else if (local_24 == 2) {
          uVar16 = (int)(uVar16 - local_18) >> 1;
        }
        else {
          uVar16 = (int)(uVar16 - local_18) / local_24;
        }
        if (uVar16 != 0) {
          DAT_1007b2c4 = (uVar16 & 0xffff) + (uVar16 & 0x8000) * -2;
        }
        if (iVar3 == iVar2) {
          DAT_1007b2e8 = iVar3 - iVar2;
        }
        else if (local_24 == 1) {
          DAT_1007b2e8 = iVar3 - iVar2;
        }
        else if (local_24 == 2) {
          DAT_1007b2e8 = iVar3 - iVar2 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar3 - iVar2) / local_24;
        }
      }
      else {
        local_24 = iVar7 - iVar12;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar1;
        DAT_1007b290 = iVar12;
        DAT_1007b2c0 = uVar15;
        FUN_10064328();
        if (local_24 == 0) {
          return;
        }
        DAT_1007b284 = iVar14 << 0x10;
        iVar11 = iVar11 - iVar14;
        if (local_24 == 1) {
          DAT_1007b288 = iVar11 * 0x10000;
        }
        else if (local_24 == 2) {
          DAT_1007b288 = iVar11 * 0x8000;
        }
        else if (((local_24 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar8 + (iVar11 * 0x20 + local_24) * 4);
        }
        else if (iVar11 < 0) {
          DAT_1007b288 = (iVar11 * 0x10000) / local_24;
        }
        else {
          DAT_1007b288 = (iVar11 * 0x10000) / local_24;
        }
      }
      goto LAB_1000f653;
    }
    iVar12 = iVar14 - DAT_1007b280;
    if (iVar12 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar11 = iVar11 - iVar14;
    if (iVar7 == 1) {
      DAT_1007b288 = iVar11 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1007b288 = iVar11 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar8 + (iVar11 * 0x20 + iVar7) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1007b288 = (iVar11 * 0x10000) / iVar7;
    }
    else {
      DAT_1007b288 = (iVar11 * 0x10000) / iVar7;
    }
    if ((iVar3 == iVar1) || (iVar12 == 1)) {
      DAT_1007b2ec = iVar3 - iVar1;
    }
    else if (iVar12 == 2) {
      DAT_1007b2ec = iVar3 - iVar1 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar3 - iVar1) / iVar12;
    }
    if ((iVar2 == iVar1) || (iVar7 == 1)) {
      DAT_1007b2e8 = iVar2 - iVar1;
    }
    else if (iVar7 == 2) {
      DAT_1007b2e8 = iVar2 - iVar1 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar2 - iVar1) / iVar7;
    }
    uVar16 = uVar16 & 0xffff;
    if ((local_c == sVar13) || (iVar12 == 1)) {
      uVar16 = uVar16 - (uVar15 & 0xffff);
    }
    else if (iVar12 == 2) {
      uVar16 = (int)(uVar16 - (uVar15 & 0xffff)) >> 1;
    }
    else {
      uVar16 = (int)(uVar16 - (uVar15 & 0xffff)) / iVar12;
    }
    uVar5 = uVar15 & 0xffff;
    DAT_1007b2c8 = (uVar16 & 0xffff) + (uVar16 & 0x8000) * -2;
    local_18 = local_18 & 0xffff;
    if ((sVar10 == sVar13) || (iVar7 == 1)) {
      local_18 = local_18 - uVar5;
    }
    else if (iVar7 == 2) {
      local_18 = (int)(local_18 - uVar5) >> 1;
    }
    else {
      local_18 = (int)(local_18 - uVar5) / iVar7;
    }
    DAT_1007b2c4 = (local_18 & 0xffff) + (local_18 & 0x8000) * -2;
    DAT_1007b2c0 = uVar15;
    local_24 = iVar7;
    iVar2 = iVar1;
    iVar11 = DAT_1007b280;
    DAT_1007b280 = iVar14;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar11 << 0x10;
  DAT_1007b2e4 = DAT_1007b2f0 + iVar2;
LAB_1000f653:
  DAT_1007b290 = local_24;
  FUN_10064328();
  return;
}


