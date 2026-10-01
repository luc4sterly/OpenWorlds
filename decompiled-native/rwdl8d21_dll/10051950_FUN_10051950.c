// 10051950 FUN_10051950 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10051950(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  uint uVar11;
  short sVar12;
  uint uVar13;
  int local_20;
  short local_14;
  
  iVar6 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar6 = param_2;
      param_2 = param_4;
      param_4 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_10051997;
  param_3 = param_2;
  param_2 = param_4;
  param_4 = iVar6;
LAB_10051997:
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  local_20 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  uVar10 = *(int *)(param_2 + 0x58) >> 8;
  iVar2 = (int)*(short *)(param_3 + 0x1a);
  uVar13 = *(int *)(param_3 + 0x58) >> 8;
  DAT_1007b330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar3 = (int)*(short *)(param_4 + 0x1a);
  DAT_1007b334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  uVar4 = *(int *)(param_4 + 0x58) >> 8;
  DAT_1007b338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007b470 = (float)*(int *)(param_2 + 100) * _DAT_10074110 * DAT_1007b330;
  DAT_1007b474 = (float)*(int *)(param_2 + 0x68) * _DAT_10074110 * DAT_1007b330;
  DAT_1007b478 = (float)*(int *)(param_3 + 100) * _DAT_10074110 * DAT_1007b334;
  DAT_1007b47c = (float)*(int *)(param_3 + 0x68) * _DAT_10074110 * DAT_1007b334;
  DAT_1007b480 = (float)*(int *)(param_4 + 100) * _DAT_10074110 * DAT_1007b338;
  DAT_1007b484 = (float)*(int *)(param_4 + 0x68) * _DAT_10074110 * DAT_1007b338;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  iVar5 = DAT_10075214 + 0x1000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  iVar6 = DAT_10075228;
  if (DAT_1007b43c != 0) {
    iVar6 = DAT_10075230;
  }
  _DAT_1007b2a4 = *(undefined4 *)(iVar6 + (DAT_1007b284 & 7) * 4);
  sVar12 = (short)((uint)*(int *)(param_3 + 0x58) >> 8);
  sVar9 = (short)((uint)*(int *)(param_2 + 0x58) >> 8);
  local_14 = (short)((uint)*(int *)(param_4 + 0x58) >> 8);
  if (local_20 < 1) {
    iVar6 = DAT_1007b280 - iVar2;
    if (iVar6 < 1) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    local_20 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_20 == 0) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    _DAT_1007b46c = _DAT_10074114 / (float)local_20;
    _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b46c;
    _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b46c;
    _DAT_1007b454 = (DAT_1007b484 - DAT_1007b47c) * _DAT_1007b46c;
    _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
    _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
    _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b484 - DAT_1007b474);
    iVar7 = iVar3 - iVar2;
    if (local_20 == 1) {
      DAT_1007b28c = iVar7 * 0x10000;
    }
    else if (local_20 == 2) {
      DAT_1007b28c = iVar7 * 0x8000;
    }
    else if (((local_20 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar5 + (iVar7 * 0x20 + local_20) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1007b28c = (iVar7 * 0x10000) / local_20;
    }
    else {
      DAT_1007b28c = (iVar7 * 0x10000) / local_20;
    }
    iVar3 = iVar3 - DAT_1007b280;
    if (local_20 == 1) {
      DAT_1007b288 = iVar3 * 0x10000;
    }
    else if (local_20 == 2) {
      DAT_1007b288 = iVar3 * 0x8000;
    }
    else if (((local_20 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar5 + (iVar3 * 0x20 + local_20) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1007b288 = (iVar3 * 0x10000) / local_20;
    }
    else {
      DAT_1007b288 = (iVar3 * 0x10000) / local_20;
    }
    if (DAT_1007b43c == 0) {
      uVar10 = uVar10 & 0xffff;
      if ((sVar12 == sVar9) || (iVar6 == 1)) {
        uVar10 = uVar10 - (uVar13 & 0xffff);
      }
      else if (iVar6 == 2) {
        uVar10 = (int)(uVar10 - (uVar13 & 0xffff)) >> 1;
      }
      else {
        uVar10 = (int)(uVar10 - (uVar13 & 0xffff)) / iVar6;
      }
      uVar8 = uVar13 & 0xffff;
      DAT_1007b2d4 = (uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
      uVar4 = uVar4 & 0xffff;
      DAT_1007b2cc = uVar13;
      if ((local_14 == sVar12) || (local_20 == 1)) {
        uVar4 = uVar4 - uVar8;
      }
      else if (local_20 == 2) {
        uVar4 = (int)(uVar4 - uVar8) >> 1;
      }
      else {
        uVar4 = (int)(uVar4 - uVar8) / local_20;
      }
    }
    else {
      if ((sVar12 == sVar9) || (iVar6 == 1)) {
        uVar13 = (uVar13 & 0xffff) - (uVar10 & 0xffff);
      }
      else if (iVar6 == 2) {
        uVar13 = (int)((uVar13 & 0xffff) - (uVar10 & 0xffff)) >> 1;
      }
      else {
        uVar13 = (int)((uVar13 & 0xffff) - (uVar10 & 0xffff)) / iVar6;
      }
      uVar8 = uVar10 & 0xffff;
      DAT_1007b2d4 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
      uVar4 = uVar4 & 0xffff;
      if ((local_14 == sVar9) || (local_20 == 1)) {
        uVar4 = uVar4 - uVar8;
        DAT_1007b2cc = uVar10;
      }
      else if (local_20 == 2) {
        uVar4 = (int)(uVar4 - uVar8) >> 1;
        DAT_1007b2cc = uVar10;
      }
      else {
        uVar4 = (int)(uVar4 - uVar8) / local_20;
        DAT_1007b2cc = uVar10;
      }
    }
    DAT_1007b2d0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
    DAT_1007b284 = DAT_1007b280 << 0x10;
    DAT_1007b280 = iVar2 << 0x10;
    _DAT_1007b440 = DAT_1007b334;
    _DAT_1007b448 = DAT_1007b478;
    _DAT_1007b450 = DAT_1007b47c;
    _DAT_1007b458 = DAT_1007b330;
    _DAT_1007b460 = DAT_1007b470;
    _DAT_1007b468 = DAT_1007b474;
  }
  else {
    iVar6 = iVar2 - DAT_1007b280;
    if (local_20 == 1) {
      DAT_1007b28c = iVar6 * 0x10000;
    }
    else if (local_20 == 2) {
      DAT_1007b28c = iVar6 * 0x8000;
    }
    else if (((local_20 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar5 + (iVar6 * 0x20 + local_20) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b28c = (iVar6 * 0x10000) / local_20;
    }
    else {
      DAT_1007b28c = (iVar6 * 0x10000) / local_20;
    }
    fVar1 = _DAT_10074114 / (float)local_20;
    _DAT_1007b444 = (DAT_1007b334 - DAT_1007b330) * fVar1;
    _DAT_1007b44c = (DAT_1007b478 - DAT_1007b470) * fVar1;
    _DAT_1007b454 = (DAT_1007b47c - DAT_1007b474) * fVar1;
    iVar6 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    _DAT_1007b440 = DAT_1007b330;
    _DAT_1007b448 = DAT_1007b470;
    _DAT_1007b450 = DAT_1007b474;
    if (iVar6 < 1) {
      iVar6 = iVar3 - DAT_1007b280;
      if (iVar6 < 1) {
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      iVar2 = iVar2 - iVar3;
      if (local_20 == 1) {
        DAT_1007b288 = iVar2 * 0x10000;
      }
      else if (local_20 == 2) {
        DAT_1007b288 = iVar2 * 0x8000;
      }
      else if (((local_20 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar5 + (iVar2 * 0x20 + local_20) * 4);
      }
      else if (iVar2 < 0) {
        DAT_1007b288 = (iVar2 * 0x10000) / local_20;
      }
      else {
        DAT_1007b288 = (iVar2 * 0x10000) / local_20;
      }
      _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * fVar1;
      _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * fVar1;
      _DAT_1007b46c = (DAT_1007b47c - DAT_1007b484) * fVar1;
      if (DAT_1007b43c == 0) {
        uVar4 = uVar4 & 0xffff;
        if ((local_14 == sVar9) || (iVar6 == 1)) {
          uVar4 = uVar4 - (uVar10 & 0xffff);
        }
        else if (iVar6 == 2) {
          uVar4 = (int)(uVar4 - (uVar10 & 0xffff)) >> 1;
        }
        else {
          uVar4 = (int)(uVar4 - (uVar10 & 0xffff)) / iVar6;
        }
        uVar8 = uVar10 & 0xffff;
        DAT_1007b2d4 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
        uVar13 = uVar13 & 0xffff;
        if ((sVar12 == sVar9) || (local_20 == 1)) {
          uVar13 = uVar13 - uVar8;
          DAT_1007b2cc = uVar10;
        }
        else if (local_20 == 2) {
          uVar13 = (int)(uVar13 - uVar8) >> 1;
          DAT_1007b2cc = uVar10;
        }
        else {
          uVar13 = (int)(uVar13 - uVar8) / local_20;
          DAT_1007b2cc = uVar10;
        }
      }
      else {
        if ((local_14 == sVar9) || (iVar6 == 1)) {
          uVar10 = (uVar10 & 0xffff) - (uVar4 & 0xffff);
        }
        else if (iVar6 == 2) {
          uVar10 = (int)((uVar10 & 0xffff) - (uVar4 & 0xffff)) >> 1;
        }
        else {
          uVar10 = (int)((uVar10 & 0xffff) - (uVar4 & 0xffff)) / iVar6;
        }
        uVar8 = uVar4 & 0xffff;
        DAT_1007b2d4 = (uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
        uVar13 = uVar13 & 0xffff;
        DAT_1007b2cc = uVar4;
        if ((local_14 == sVar12) || (local_20 == 1)) {
          uVar13 = uVar13 - uVar8;
        }
        else if (local_20 == 2) {
          uVar13 = (int)(uVar13 - uVar8) >> 1;
        }
        else {
          uVar13 = (int)(uVar13 - uVar8) / local_20;
        }
      }
      DAT_1007b2d0 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = iVar3 << 0x10;
      _DAT_1007b458 = DAT_1007b338;
      _DAT_1007b460 = DAT_1007b480;
      _DAT_1007b468 = DAT_1007b484;
    }
    else {
      iVar7 = iVar3 - DAT_1007b280;
      if (iVar6 == 1) {
        DAT_1007b288 = iVar7 * 0x10000;
      }
      else if (iVar6 == 2) {
        DAT_1007b288 = iVar7 * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar5 + (iVar7 * 0x20 + iVar6) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1007b288 = (iVar7 * 0x10000) / iVar6;
      }
      else {
        DAT_1007b288 = (iVar7 * 0x10000) / iVar6;
      }
      if (DAT_1007b288 - DAT_1007b28c < 1) {
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      _DAT_1007b46c = _DAT_10074114 / (float)iVar6;
      _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
      _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
      _DAT_1007b46c = (DAT_1007b484 - DAT_1007b474) * _DAT_1007b46c;
      if (DAT_1007b43c == 0) {
        if ((sVar12 == sVar9) || (local_20 == 1)) {
          uVar8 = (uVar13 & 0xffff) - (uVar10 & 0xffff);
        }
        else if (local_20 == 2) {
          uVar8 = (int)((uVar13 & 0xffff) - (uVar10 & 0xffff)) >> 1;
        }
        else {
          uVar8 = (int)((uVar13 & 0xffff) - (uVar10 & 0xffff)) / local_20;
        }
        uVar11 = uVar10 & 0xffff;
        DAT_1007b2d0 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
        if ((local_14 == sVar9) || (iVar6 == 1)) {
          iVar7 = (uVar4 & 0xffff) - uVar11;
        }
        else if (iVar6 == 2) {
          iVar7 = (int)((uVar4 & 0xffff) - uVar11) >> 1;
        }
        else {
          iVar7 = (int)((uVar4 & 0xffff) - uVar11) / iVar6;
        }
        iVar7 = iVar7 - (short)DAT_1007b2d0;
      }
      else {
        if ((local_14 == sVar9) || (iVar6 == 1)) {
          uVar8 = (uVar4 & 0xffff) - (uVar10 & 0xffff);
        }
        else if (iVar6 == 2) {
          uVar8 = (int)((uVar4 & 0xffff) - (uVar10 & 0xffff)) >> 1;
        }
        else {
          uVar8 = (int)((uVar4 & 0xffff) - (uVar10 & 0xffff)) / iVar6;
        }
        uVar11 = uVar10 & 0xffff;
        DAT_1007b2d0 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
        if ((sVar12 == sVar9) || (local_20 == 1)) {
          iVar7 = (uVar13 & 0xffff) - uVar11;
        }
        else if (local_20 == 2) {
          iVar7 = (int)((uVar13 & 0xffff) - uVar11) >> 1;
        }
        else {
          iVar7 = (int)((uVar13 & 0xffff) - uVar11) / local_20;
        }
        iVar7 = iVar7 - (short)DAT_1007b2d0;
      }
      DAT_1007b2d4 = 0;
      if (iVar7 != 0) {
        uVar8 = (iVar7 << 0x10) / (DAT_1007b288 - DAT_1007b28c);
        DAT_1007b2d4 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      }
      uVar4 = uVar4 & 0xffff;
      uVar13 = uVar13 & 0xffff;
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (local_20 < iVar6) {
        iVar6 = iVar6 - local_20;
        DAT_1007b290 = local_20;
        DAT_1007b2cc = uVar10;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
        FUN_10072804();
        _DAT_1007b454 = _DAT_10074114 / (float)iVar6;
        _DAT_1007b448 = DAT_1007b478;
        _DAT_1007b440 = DAT_1007b334;
        _DAT_1007b450 = DAT_1007b47c;
        _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b454;
        _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b454;
        _DAT_1007b454 = _DAT_1007b454 * (DAT_1007b484 - DAT_1007b47c);
        DAT_1007b280 = iVar2 << 0x10;
        iVar3 = iVar3 - iVar2;
        if (iVar6 == 1) {
          DAT_1007b28c = iVar3 * 0x10000;
        }
        else if (iVar6 == 2) {
          DAT_1007b28c = iVar3 * 0x8000;
        }
        else if (((iVar6 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar5 + (iVar3 * 0x20 + iVar6) * 4);
        }
        else if (iVar3 < 0) {
          DAT_1007b28c = (iVar3 * 0x10000) / iVar6;
        }
        else {
          DAT_1007b28c = (iVar3 * 0x10000) / iVar6;
        }
        local_20 = iVar6;
        if (DAT_1007b43c == 0) {
          DAT_1007b2d0 = 0;
          if ((local_14 == sVar12) || (iVar6 == 1)) {
            uVar4 = uVar4 - uVar13;
          }
          else if (iVar6 == 2) {
            uVar4 = (int)(uVar4 - uVar13) >> 1;
          }
          else {
            uVar4 = (int)(uVar4 - uVar13) / iVar6;
          }
          if (uVar4 != 0) {
            DAT_1007b2d0 = (uVar4 & 0xffff) + (uVar4 & 0x8000) * -2;
          }
        }
      }
      else {
        local_20 = local_20 - iVar6;
        DAT_1007b290 = iVar6;
        DAT_1007b2cc = uVar10;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
        FUN_10072804();
        if (local_20 == 0) {
          return;
        }
        _DAT_1007b46c = _DAT_10074114 / (float)local_20;
        _DAT_1007b458 = DAT_1007b338;
        _DAT_1007b460 = DAT_1007b480;
        _DAT_1007b468 = DAT_1007b484;
        _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * _DAT_1007b46c;
        _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * _DAT_1007b46c;
        _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b47c - DAT_1007b484);
        DAT_1007b284 = iVar3 << 0x10;
        iVar2 = iVar2 - iVar3;
        if (local_20 == 1) {
          DAT_1007b288 = iVar2 * 0x10000;
        }
        else if (local_20 == 2) {
          DAT_1007b288 = iVar2 * 0x8000;
        }
        else if (((local_20 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar5 + (iVar2 * 0x20 + local_20) * 4);
        }
        else if (iVar2 < 0) {
          DAT_1007b288 = (iVar2 * 0x10000) / local_20;
        }
        else {
          DAT_1007b288 = (iVar2 * 0x10000) / local_20;
        }
        if (DAT_1007b43c != 0) {
          DAT_1007b2d0 = 0;
          if ((local_14 == sVar12) || (local_20 == 1)) {
            uVar13 = uVar13 - uVar4;
          }
          else if (local_20 == 2) {
            uVar13 = (int)(uVar13 - uVar4) >> 1;
          }
          else {
            uVar13 = (int)(uVar13 - uVar4) / local_20;
          }
          if (uVar13 != 0) {
            DAT_1007b2d0 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
          }
        }
      }
    }
  }
  DAT_1007b290 = local_20;
  FUN_10072804();
  return;
}


