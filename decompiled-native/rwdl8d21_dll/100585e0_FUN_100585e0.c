// 100585e0 FUN_100585e0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100585e0(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  uint uVar9;
  short sVar10;
  uint uVar11;
  short sVar12;
  uint uVar13;
  int local_1c;
  uint local_18;
  
  iVar5 = param_3;
  iVar4 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar5 = param_2;
      param_2 = param_4;
      iVar4 = param_3;
    }
LAB_10058626:
    param_3 = param_2;
    param_4 = iVar5;
    param_2 = iVar4;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10058626;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  local_1c = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar9 = *(int *)(param_2 + 0x58) >> 8;
  DAT_1007b330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar2 = (int)*(short *)(param_3 + 0x1a);
  uVar13 = *(int *)(param_3 + 0x58) >> 8;
  iVar3 = (int)*(short *)(param_4 + 0x1a);
  DAT_1007b334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  uVar11 = *(int *)(param_4 + 0x58) >> 8;
  DAT_1007b338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007b470 = (float)*(int *)(param_2 + 100) * _DAT_10074110 * DAT_1007b330;
  DAT_1007b474 = (float)*(int *)(param_2 + 0x68) * _DAT_10074110 * DAT_1007b330;
  DAT_1007b478 = (float)*(int *)(param_3 + 100) * _DAT_10074110 * DAT_1007b334;
  DAT_1007b47c = (float)*(int *)(param_3 + 0x68) * _DAT_10074110 * DAT_1007b334;
  DAT_1007b480 = (float)*(int *)(param_4 + 100) * _DAT_10074110 * DAT_1007b338;
  DAT_1007b484 = (float)*(int *)(param_4 + 0x68) * _DAT_10074110 * DAT_1007b338;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007b298 = DAT_10077da4;
  iVar4 = DAT_10075214 + 0x1000;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  iVar5 = DAT_10075228;
  if (DAT_1007b43c != 0) {
    iVar5 = DAT_10075230;
  }
  _DAT_1007b2a4 = *(undefined4 *)(iVar5 + (DAT_1007b284 & 7) * 4);
  sVar10 = (short)((uint)*(int *)(param_4 + 0x58) >> 8);
  sVar12 = (short)((uint)*(int *)(param_3 + 0x58) >> 8);
  sVar8 = (short)((uint)*(int *)(param_2 + 0x58) >> 8);
  if (local_1c < 1) {
    iVar5 = DAT_1007b280 - iVar2;
    if (iVar5 < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    local_1c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_1c == 0) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    _DAT_1007b46c = _DAT_10074114 / (float)local_1c;
    _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b46c;
    _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b46c;
    _DAT_1007b454 = (DAT_1007b484 - DAT_1007b47c) * _DAT_1007b46c;
    _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
    _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
    _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b484 - DAT_1007b474);
    iVar6 = iVar3 - iVar2;
    if (local_1c == 1) {
      DAT_1007b28c = iVar6 * 0x10000;
    }
    else if (local_1c == 2) {
      DAT_1007b28c = iVar6 * 0x8000;
    }
    else if (((local_1c < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar4 + (iVar6 * 0x20 + local_1c) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b28c = (iVar6 * 0x10000) / local_1c;
    }
    else {
      DAT_1007b28c = (iVar6 * 0x10000) / local_1c;
    }
    iVar3 = iVar3 - DAT_1007b280;
    if (local_1c == 1) {
      DAT_1007b288 = iVar3 * 0x10000;
    }
    else if (local_1c == 2) {
      DAT_1007b288 = iVar3 * 0x8000;
    }
    else if (((local_1c < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar4 + (iVar3 * 0x20 + local_1c) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1007b288 = (iVar3 * 0x10000) / local_1c;
    }
    else {
      DAT_1007b288 = (iVar3 * 0x10000) / local_1c;
    }
    if (DAT_1007b43c == 0) {
      uVar9 = uVar9 & 0xffff;
      if ((sVar12 == sVar8) || (iVar5 == 1)) {
        uVar9 = uVar9 - (uVar13 & 0xffff);
      }
      else if (iVar5 == 2) {
        uVar9 = (int)(uVar9 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        uVar9 = (int)(uVar9 - (uVar13 & 0xffff)) / iVar5;
      }
      uVar7 = uVar13 & 0xffff;
      DAT_1007b2d4 = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
      uVar11 = uVar11 & 0xffff;
      DAT_1007b2cc = uVar13;
      if ((sVar10 == sVar12) || (local_1c == 1)) {
        uVar11 = uVar11 - uVar7;
      }
      else if (local_1c == 2) {
        uVar11 = (int)(uVar11 - uVar7) >> 1;
      }
      else {
        uVar11 = (int)(uVar11 - uVar7) / local_1c;
      }
    }
    else {
      uVar13 = uVar13 & 0xffff;
      if ((sVar12 == sVar8) || (iVar5 == 1)) {
        uVar13 = uVar13 - (uVar9 & 0xffff);
      }
      else if (iVar5 == 2) {
        uVar13 = (int)(uVar13 - (uVar9 & 0xffff)) >> 1;
      }
      else {
        uVar13 = (int)(uVar13 - (uVar9 & 0xffff)) / iVar5;
      }
      uVar7 = uVar9 & 0xffff;
      DAT_1007b2d4 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
      uVar11 = uVar11 & 0xffff;
      if ((sVar10 == sVar8) || (local_1c == 1)) {
        uVar11 = uVar11 - uVar7;
        DAT_1007b2cc = uVar9;
      }
      else if (local_1c == 2) {
        uVar11 = (int)(uVar11 - uVar7) >> 1;
        DAT_1007b2cc = uVar9;
      }
      else {
        uVar11 = (int)(uVar11 - uVar7) / local_1c;
        DAT_1007b2cc = uVar9;
      }
    }
    DAT_1007b2d0 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
    DAT_1007b284 = DAT_1007b280 << 0x10;
    DAT_1007b280 = iVar2 << 0x10;
    _DAT_1007b440 = DAT_1007b334;
    _DAT_1007b448 = DAT_1007b478;
    _DAT_1007b450 = DAT_1007b47c;
    _DAT_1007b458 = DAT_1007b330;
    _DAT_1007b460 = DAT_1007b470;
    _DAT_1007b468 = DAT_1007b474;
    goto LAB_10059587;
  }
  iVar5 = iVar2 - DAT_1007b280;
  if (local_1c == 1) {
    DAT_1007b28c = iVar5 * 0x10000;
  }
  else if (local_1c == 2) {
    DAT_1007b28c = iVar5 * 0x8000;
  }
  else if (((local_1c < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
    DAT_1007b28c = *(int *)(iVar4 + (iVar5 * 0x20 + local_1c) * 4);
  }
  else if (iVar5 < 0) {
    DAT_1007b28c = (iVar5 * 0x10000) / local_1c;
  }
  else {
    DAT_1007b28c = (iVar5 * 0x10000) / local_1c;
  }
  fVar1 = _DAT_10074114 / (float)local_1c;
  _DAT_1007b444 = (DAT_1007b334 - DAT_1007b330) * fVar1;
  _DAT_1007b44c = (DAT_1007b478 - DAT_1007b470) * fVar1;
  _DAT_1007b454 = (DAT_1007b47c - DAT_1007b474) * fVar1;
  iVar5 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
  _DAT_1007b440 = DAT_1007b330;
  _DAT_1007b448 = DAT_1007b470;
  _DAT_1007b450 = DAT_1007b474;
  if (0 < iVar5) {
    iVar6 = iVar3 - DAT_1007b280;
    if (iVar5 == 1) {
      DAT_1007b288 = iVar6 * 0x10000;
    }
    else if (iVar5 == 2) {
      DAT_1007b288 = iVar6 * 0x8000;
    }
    else if (((iVar5 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar4 + (iVar6 * 0x20 + iVar5) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b288 = (iVar6 * 0x10000) / iVar5;
    }
    else {
      DAT_1007b288 = (iVar6 * 0x10000) / iVar5;
    }
    if (DAT_1007b288 - DAT_1007b28c < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    _DAT_1007b46c = _DAT_10074114 / (float)iVar5;
    _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
    _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
    _DAT_1007b46c = (DAT_1007b484 - DAT_1007b474) * _DAT_1007b46c;
    if (DAT_1007b43c == 0) {
      if ((sVar12 == sVar8) || (local_1c == 1)) {
        uVar7 = (uVar13 & 0xffff) - (uVar9 & 0xffff);
      }
      else if (local_1c == 2) {
        uVar7 = (int)((uVar13 & 0xffff) - (uVar9 & 0xffff)) >> 1;
      }
      else {
        uVar7 = (int)((uVar13 & 0xffff) - (uVar9 & 0xffff)) / local_1c;
      }
      local_18 = uVar9 & 0xffff;
      DAT_1007b2d0 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      if ((sVar10 == sVar8) || (iVar5 == 1)) {
        iVar6 = (uVar11 & 0xffff) - local_18;
      }
      else if (iVar5 == 2) {
        iVar6 = (int)((uVar11 & 0xffff) - local_18) >> 1;
      }
      else {
        iVar6 = (int)((uVar11 & 0xffff) - local_18) / iVar5;
      }
      iVar6 = iVar6 - (short)DAT_1007b2d0;
    }
    else {
      if ((sVar10 == sVar8) || (iVar5 == 1)) {
        uVar7 = (uVar11 & 0xffff) - (uVar9 & 0xffff);
      }
      else if (iVar5 == 2) {
        uVar7 = (int)((uVar11 & 0xffff) - (uVar9 & 0xffff)) >> 1;
      }
      else {
        uVar7 = (int)((uVar11 & 0xffff) - (uVar9 & 0xffff)) / iVar5;
      }
      local_18 = uVar9 & 0xffff;
      DAT_1007b2d0 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      if ((sVar12 == sVar8) || (local_1c == 1)) {
        iVar6 = (uVar13 & 0xffff) - local_18;
      }
      else if (local_1c == 2) {
        iVar6 = (int)((uVar13 & 0xffff) - local_18) >> 1;
      }
      else {
        iVar6 = (int)((uVar13 & 0xffff) - local_18) / local_1c;
      }
      iVar6 = iVar6 - (short)DAT_1007b2d0;
    }
    DAT_1007b2d4 = 0;
    if (iVar6 != 0) {
      uVar7 = (iVar6 << 0x10) / (DAT_1007b288 - DAT_1007b28c);
      DAT_1007b2d4 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
    }
    uVar11 = uVar11 & 0xffff;
    uVar13 = uVar13 & 0xffff;
    DAT_1007b280 = DAT_1007b280 << 0x10;
    DAT_1007b284 = DAT_1007b280;
    if (local_1c < iVar5) {
      iVar5 = iVar5 - local_1c;
      DAT_1007b290 = local_1c;
      DAT_1007b2cc = uVar9;
      _DAT_1007b458 = DAT_1007b330;
      _DAT_1007b460 = DAT_1007b470;
      _DAT_1007b468 = DAT_1007b474;
      FUN_100580b0((uint *)&DAT_1007b280);
      _DAT_1007b454 = _DAT_10074114 / (float)iVar5;
      _DAT_1007b448 = DAT_1007b478;
      _DAT_1007b440 = DAT_1007b334;
      _DAT_1007b450 = DAT_1007b47c;
      _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b454;
      _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b454;
      _DAT_1007b454 = _DAT_1007b454 * (DAT_1007b484 - DAT_1007b47c);
      DAT_1007b280 = iVar2 << 0x10;
      iVar3 = iVar3 - iVar2;
      if (iVar5 == 1) {
        DAT_1007b28c = iVar3 * 0x10000;
      }
      else if (iVar5 == 2) {
        DAT_1007b28c = iVar3 * 0x8000;
      }
      else if (((iVar5 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
        DAT_1007b28c = *(int *)(iVar4 + (iVar3 * 0x20 + iVar5) * 4);
      }
      else if (iVar3 < 0) {
        DAT_1007b28c = (iVar3 * 0x10000) / iVar5;
      }
      else {
        DAT_1007b28c = (iVar3 * 0x10000) / iVar5;
      }
      local_1c = iVar5;
      if (DAT_1007b43c == 0) {
        DAT_1007b2d0 = 0;
        if ((sVar10 == sVar12) || (iVar5 == 1)) {
          uVar11 = uVar11 - uVar13;
        }
        else if (iVar5 == 2) {
          uVar11 = (int)(uVar11 - uVar13) >> 1;
        }
        else {
          uVar11 = (int)(uVar11 - uVar13) / iVar5;
        }
        if (uVar11 != 0) {
          DAT_1007b2d0 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
        }
      }
    }
    else {
      local_1c = local_1c - iVar5;
      DAT_1007b290 = iVar5;
      DAT_1007b2cc = uVar9;
      _DAT_1007b458 = DAT_1007b330;
      _DAT_1007b460 = DAT_1007b470;
      _DAT_1007b468 = DAT_1007b474;
      FUN_100580b0((uint *)&DAT_1007b280);
      if (local_1c == 0) {
        return;
      }
      _DAT_1007b46c = _DAT_10074114 / (float)local_1c;
      _DAT_1007b458 = DAT_1007b338;
      _DAT_1007b460 = DAT_1007b480;
      _DAT_1007b468 = DAT_1007b484;
      _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * _DAT_1007b46c;
      _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * _DAT_1007b46c;
      _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b47c - DAT_1007b484);
      DAT_1007b284 = iVar3 << 0x10;
      iVar2 = iVar2 - iVar3;
      if (local_1c == 1) {
        DAT_1007b288 = iVar2 * 0x10000;
      }
      else if (local_1c == 2) {
        DAT_1007b288 = iVar2 * 0x8000;
      }
      else if (((local_1c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar4 + (iVar2 * 0x20 + local_1c) * 4);
      }
      else if (iVar2 < 0) {
        DAT_1007b288 = (iVar2 * 0x10000) / local_1c;
      }
      else {
        DAT_1007b288 = (iVar2 * 0x10000) / local_1c;
      }
      if (DAT_1007b43c != 0) {
        DAT_1007b2d0 = 0;
        if ((sVar12 == sVar10) || (local_1c == 1)) {
          uVar13 = uVar13 - uVar11;
        }
        else if (local_1c == 2) {
          uVar13 = (int)(uVar13 - uVar11) >> 1;
        }
        else {
          uVar13 = (int)(uVar13 - uVar11) / local_1c;
        }
        if (uVar13 != 0) {
          DAT_1007b2d0 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
        }
      }
    }
    goto LAB_10059587;
  }
  iVar5 = iVar3 - DAT_1007b280;
  if (iVar5 < 1) {
    DAT_1007b298 = DAT_10077da4;
    return;
  }
  iVar2 = iVar2 - iVar3;
  if (local_1c == 1) {
    DAT_1007b288 = iVar2 * 0x10000;
  }
  else if (local_1c == 2) {
    DAT_1007b288 = iVar2 * 0x8000;
  }
  else if (((local_1c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
    DAT_1007b288 = *(int *)(iVar4 + (iVar2 * 0x20 + local_1c) * 4);
  }
  else if (iVar2 < 0) {
    DAT_1007b288 = (iVar2 * 0x10000) / local_1c;
  }
  else {
    DAT_1007b288 = (iVar2 * 0x10000) / local_1c;
  }
  _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * fVar1;
  _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * fVar1;
  _DAT_1007b46c = (DAT_1007b47c - DAT_1007b484) * fVar1;
  if (DAT_1007b43c == 0) {
    uVar11 = uVar11 & 0xffff;
    if ((sVar10 == sVar8) || (iVar5 == 1)) {
      uVar11 = uVar11 - (uVar9 & 0xffff);
    }
    else if (iVar5 == 2) {
      uVar11 = (int)(uVar11 - (uVar9 & 0xffff)) >> 1;
    }
    else {
      uVar11 = (int)(uVar11 - (uVar9 & 0xffff)) / iVar5;
    }
    uVar7 = uVar9 & 0xffff;
    DAT_1007b2d4 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
    DAT_1007b2cc = uVar9;
    if ((sVar12 == sVar8) || (local_1c == 1)) goto LAB_100591a3;
    if (local_1c == 2) {
      uVar7 = (int)((uVar13 & 0xffff) - uVar7) >> 1;
    }
    else {
      uVar7 = (int)((uVar13 & 0xffff) - uVar7) / local_1c;
    }
  }
  else {
    if ((sVar10 == sVar8) || (iVar5 == 1)) {
      uVar9 = (uVar9 & 0xffff) - (uVar11 & 0xffff);
    }
    else if (iVar5 == 2) {
      uVar9 = (int)((uVar9 & 0xffff) - (uVar11 & 0xffff)) >> 1;
    }
    else {
      uVar9 = (int)((uVar9 & 0xffff) - (uVar11 & 0xffff)) / iVar5;
    }
    uVar7 = uVar11 & 0xffff;
    DAT_1007b2d4 = (uVar9 & 0xffff) + (uVar9 & 0x8000) * -2;
    DAT_1007b2cc = uVar11;
    if ((sVar12 == sVar10) || (local_1c == 1)) {
LAB_100591a3:
      uVar7 = (uVar13 & 0xffff) - uVar7;
    }
    else if (local_1c == 2) {
      uVar7 = (int)((uVar13 & 0xffff) - uVar7) >> 1;
    }
    else {
      uVar7 = (int)((uVar13 & 0xffff) - uVar7) / local_1c;
    }
  }
  DAT_1007b2d0 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
  DAT_1007b280 = DAT_1007b280 << 0x10;
  DAT_1007b284 = iVar3 << 0x10;
  _DAT_1007b458 = DAT_1007b338;
  _DAT_1007b460 = DAT_1007b480;
  _DAT_1007b468 = DAT_1007b484;
LAB_10059587:
  DAT_1007b290 = local_1c;
  FUN_100580b0((uint *)&DAT_1007b280);
  return;
}


