// 1002d320 FUN_1002d320 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002d320(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  short sVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int local_2c;
  uint local_1c;
  short local_18;
  short local_14;
  
  iVar4 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar4 = param_2;
      param_2 = param_4;
      param_4 = param_3;
    }
LAB_1002d366:
    param_3 = param_2;
    param_2 = param_4;
    param_4 = iVar4;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1002d366;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar5 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  iVar4 = *(int *)(param_2 + 0x20);
  uVar14 = *(int *)(param_2 + 0x58) >> 8;
  iVar15 = (int)*(short *)(param_3 + 0x1a);
  iVar16 = (int)*(short *)(param_4 + 0x1a);
  uVar6 = *(int *)(param_3 + 0x58) >> 8;
  iVar1 = *(int *)(param_3 + 0x20);
  DAT_1007b330 = *(float *)(param_3 + 0x14) * *(float *)(param_4 + 0x14);
  iVar2 = *(int *)(param_4 + 0x20);
  uVar7 = *(int *)(param_4 + 0x58) >> 8;
  DAT_1007b334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007b338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007b470 = (float)*(int *)(param_2 + 100) * _DAT_100740f0 * DAT_1007b330;
  DAT_1007b474 = (float)*(int *)(param_2 + 0x68) * _DAT_100740f0 * DAT_1007b330;
  DAT_1007b478 = (float)*(int *)(param_3 + 100) * _DAT_100740f0 * DAT_1007b334;
  DAT_1007b47c = (float)*(int *)(param_3 + 0x68) * _DAT_100740f0 * DAT_1007b334;
  DAT_1007b480 = (float)*(int *)(param_4 + 100) * _DAT_100740f0 * DAT_1007b338;
  DAT_1007b484 = (float)*(int *)(param_4 + 0x68) * _DAT_100740f0 * DAT_1007b338;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2a0 = DAT_10077eb0;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  iVar8 = DAT_10075214 + 0x1000;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  iVar9 = DAT_10075228;
  if (DAT_1007b43c != 0) {
    iVar9 = DAT_10075230;
  }
  _DAT_1007b2a4 = *(undefined4 *)(iVar9 + (DAT_1007b284 & 7) * 4);
  sVar13 = (short)((uint)*(int *)(param_2 + 0x58) >> 8);
  local_18 = (short)((uint)*(int *)(param_3 + 0x58) >> 8);
  local_14 = (short)((uint)*(int *)(param_4 + 0x58) >> 8);
  if (iVar5 < 1) {
    iVar9 = DAT_1007b280 - iVar15;
    if (iVar9 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    local_2c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_2c == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    _DAT_1007b46c = _DAT_100740f4 / (float)local_2c;
    _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b46c;
    _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b46c;
    _DAT_1007b454 = (DAT_1007b484 - DAT_1007b47c) * _DAT_1007b46c;
    _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
    _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
    _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b484 - DAT_1007b474);
    iVar5 = iVar16 - iVar15;
    if (local_2c == 1) {
      DAT_1007b28c = iVar5 * 0x10000;
    }
    else if (local_2c == 2) {
      DAT_1007b28c = iVar5 * 0x8000;
    }
    else if (((local_2c < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar8 + (iVar5 * 0x20 + local_2c) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007b28c = (iVar5 * 0x10000) / local_2c;
    }
    else {
      DAT_1007b28c = (iVar5 * 0x10000) / local_2c;
    }
    iVar16 = iVar16 - DAT_1007b280;
    if (local_2c == 1) {
      DAT_1007b288 = iVar16 * 0x10000;
    }
    else if (local_2c == 2) {
      DAT_1007b288 = iVar16 * 0x8000;
    }
    else if (((local_2c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar8 + (iVar16 * 0x20 + local_2c) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1007b288 = (iVar16 * 0x10000) / local_2c;
    }
    else {
      DAT_1007b288 = (iVar16 * 0x10000) / local_2c;
    }
    if (DAT_1007b43c == 0) {
      if ((iVar1 == iVar4) || (iVar9 == 1)) {
        DAT_1007b2ec = iVar4 - iVar1;
      }
      else if (iVar9 == 2) {
        DAT_1007b2ec = iVar4 - iVar1 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar4 - iVar1) / iVar9;
      }
      DAT_1007b2e4 = iVar1;
      if ((iVar2 == iVar1) || (local_2c == 1)) {
        DAT_1007b2e8 = iVar2 - iVar1;
      }
      else if (local_2c == 2) {
        DAT_1007b2e8 = iVar2 - iVar1 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar2 - iVar1) / local_2c;
      }
    }
    else {
      if ((iVar1 == iVar4) || (iVar9 == 1)) {
        DAT_1007b2ec = iVar1 - iVar4;
      }
      else if (iVar9 == 2) {
        DAT_1007b2ec = iVar1 - iVar4 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar1 - iVar4) / iVar9;
      }
      if ((iVar2 == iVar4) || (local_2c == 1)) {
        DAT_1007b2e8 = iVar2 - iVar4;
        DAT_1007b2e4 = iVar4;
      }
      else if (local_2c == 2) {
        DAT_1007b2e8 = iVar2 - iVar4 >> 1;
        DAT_1007b2e4 = iVar4;
      }
      else {
        DAT_1007b2e8 = (iVar2 - iVar4) / local_2c;
        DAT_1007b2e4 = iVar4;
      }
    }
    if (DAT_1007b43c == 0) {
      uVar11 = uVar6 & 0xffff;
      uVar14 = uVar14 & 0xffff;
      if ((local_18 == sVar13) || (iVar9 == 1)) {
        uVar14 = uVar14 - uVar11;
      }
      else if (iVar9 == 2) {
        uVar14 = (int)(uVar14 - uVar11) >> 1;
      }
      else {
        uVar14 = (int)(uVar14 - uVar11) / iVar9;
      }
      DAT_1007b2d4 = (uVar14 & 0xffff) + (uVar14 & 0x8000) * -2;
      uVar7 = uVar7 & 0xffff;
      DAT_1007b2cc = uVar6;
      if ((local_14 == local_18) || (local_2c == 1)) {
        uVar7 = uVar7 - uVar11;
      }
      else if (local_2c == 2) {
        uVar7 = (int)(uVar7 - uVar11) >> 1;
      }
      else {
        uVar7 = (int)(uVar7 - uVar11) / local_2c;
      }
    }
    else {
      uVar6 = uVar6 & 0xffff;
      if ((local_18 == sVar13) || (iVar9 == 1)) {
        uVar6 = uVar6 - (uVar14 & 0xffff);
      }
      else if (iVar9 == 2) {
        uVar6 = (int)(uVar6 - (uVar14 & 0xffff)) >> 1;
      }
      else {
        uVar6 = (int)(uVar6 - (uVar14 & 0xffff)) / iVar9;
      }
      uVar11 = uVar14 & 0xffff;
      DAT_1007b2d4 = (uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
      uVar7 = uVar7 & 0xffff;
      if ((local_14 == sVar13) || (local_2c == 1)) {
        uVar7 = uVar7 - uVar11;
        DAT_1007b2cc = uVar14;
      }
      else if (local_2c == 2) {
        uVar7 = (int)(uVar7 - uVar11) >> 1;
        DAT_1007b2cc = uVar14;
      }
      else {
        uVar7 = (int)(uVar7 - uVar11) / local_2c;
        DAT_1007b2cc = uVar14;
      }
    }
    DAT_1007b2d0 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
    _DAT_1007b440 = DAT_1007b334;
    _DAT_1007b448 = DAT_1007b478;
    _DAT_1007b450 = DAT_1007b47c;
    _DAT_1007b458 = DAT_1007b330;
    _DAT_1007b460 = DAT_1007b470;
    _DAT_1007b468 = DAT_1007b474;
  }
  else {
    iVar9 = iVar15 - DAT_1007b280;
    if (iVar5 == 1) {
      DAT_1007b28c = iVar9 * 0x10000;
    }
    else if (iVar5 == 2) {
      DAT_1007b28c = iVar9 * 0x8000;
    }
    else if (((iVar5 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar8 + (iVar9 * 0x20 + iVar5) * 4);
    }
    else if (iVar9 < 0) {
      DAT_1007b28c = (iVar9 * 0x10000) / iVar5;
    }
    else {
      DAT_1007b28c = (iVar9 * 0x10000) / iVar5;
    }
    fVar3 = _DAT_100740f4 / (float)iVar5;
    _DAT_1007b444 = (DAT_1007b334 - DAT_1007b330) * fVar3;
    _DAT_1007b44c = (DAT_1007b478 - DAT_1007b470) * fVar3;
    _DAT_1007b454 = (DAT_1007b47c - DAT_1007b474) * fVar3;
    iVar9 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    _DAT_1007b440 = DAT_1007b330;
    _DAT_1007b448 = DAT_1007b470;
    _DAT_1007b450 = DAT_1007b474;
    if (0 < iVar9) {
      iVar10 = iVar16 - DAT_1007b280;
      if (iVar9 == 1) {
        DAT_1007b288 = iVar10 * 0x10000;
      }
      else if (iVar9 == 2) {
        DAT_1007b288 = iVar10 * 0x8000;
      }
      else if (((iVar9 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar8 + (iVar10 * 0x20 + iVar9) * 4);
      }
      else if (iVar10 < 0) {
        DAT_1007b288 = (iVar10 * 0x10000) / iVar9;
      }
      else {
        DAT_1007b288 = (iVar10 * 0x10000) / iVar9;
      }
      iVar10 = DAT_1007b288 - DAT_1007b28c;
      if (iVar10 < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        return;
      }
      _DAT_1007b46c = _DAT_100740f4 / (float)iVar9;
      _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
      _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
      _DAT_1007b46c = (DAT_1007b484 - DAT_1007b474) * _DAT_1007b46c;
      if (DAT_1007b43c == 0) {
        if ((local_18 == sVar13) || (iVar5 == 1)) {
          uVar11 = (uVar6 & 0xffff) - (uVar14 & 0xffff);
        }
        else if (iVar5 == 2) {
          uVar11 = (int)((uVar6 & 0xffff) - (uVar14 & 0xffff)) >> 1;
        }
        else {
          uVar11 = (int)((uVar6 & 0xffff) - (uVar14 & 0xffff)) / iVar5;
        }
        local_1c = uVar14 & 0xffff;
        DAT_1007b2d0 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
        if ((local_14 == sVar13) || (iVar9 == 1)) {
          iVar12 = (uVar7 & 0xffff) - local_1c;
        }
        else if (iVar9 == 2) {
          iVar12 = (int)((uVar7 & 0xffff) - local_1c) >> 1;
        }
        else {
          iVar12 = (int)((uVar7 & 0xffff) - local_1c) / iVar9;
        }
        iVar12 = iVar12 - (short)DAT_1007b2d0;
      }
      else {
        if ((local_14 == sVar13) || (iVar9 == 1)) {
          uVar11 = (uVar7 & 0xffff) - (uVar14 & 0xffff);
        }
        else if (iVar9 == 2) {
          uVar11 = (int)((uVar7 & 0xffff) - (uVar14 & 0xffff)) >> 1;
        }
        else {
          uVar11 = (int)((uVar7 & 0xffff) - (uVar14 & 0xffff)) / iVar9;
        }
        local_1c = uVar14 & 0xffff;
        DAT_1007b2d0 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
        if ((local_18 == sVar13) || (iVar5 == 1)) {
          iVar12 = (uVar6 & 0xffff) - local_1c;
        }
        else if (iVar5 == 2) {
          iVar12 = (int)((uVar6 & 0xffff) - local_1c) >> 1;
        }
        else {
          iVar12 = (int)((uVar6 & 0xffff) - local_1c) / iVar5;
        }
        iVar12 = iVar12 - (short)DAT_1007b2d0;
      }
      DAT_1007b2d4 = 0;
      if (iVar12 != 0) {
        uVar11 = (iVar12 << 0x10) / iVar10;
        DAT_1007b2d4 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      }
      uVar6 = uVar6 & 0xffff;
      uVar7 = uVar7 & 0xffff;
      if (DAT_1007b43c == 0) {
        if ((iVar1 == iVar4) || (iVar5 == 1)) {
          DAT_1007b2e8 = iVar1 - iVar4;
        }
        else if (iVar5 == 2) {
          DAT_1007b2e8 = iVar1 - iVar4 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar1 - iVar4) / iVar5;
        }
        if ((iVar2 == iVar4) || (iVar9 == 1)) {
          iVar12 = iVar2 - iVar4;
        }
        else if (iVar9 == 2) {
          iVar12 = iVar2 - iVar4 >> 1;
        }
        else {
          iVar12 = (iVar2 - iVar4) / iVar9;
        }
        DAT_1007b2ec = iVar12 - DAT_1007b2e8;
      }
      else {
        if ((iVar2 == iVar4) || (iVar9 == 1)) {
          DAT_1007b2e8 = iVar2 - iVar4;
        }
        else if (iVar9 == 2) {
          DAT_1007b2e8 = iVar2 - iVar4 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar2 - iVar4) / iVar9;
        }
        if ((iVar1 == iVar4) || (iVar5 == 1)) {
          iVar12 = iVar1 - iVar4;
        }
        else if (iVar5 == 2) {
          iVar12 = iVar1 - iVar4 >> 1;
        }
        else {
          iVar12 = (iVar1 - iVar4) / iVar5;
        }
        DAT_1007b2ec = iVar12 - DAT_1007b2e8;
      }
      if ((DAT_1007b2ec != 0) && (iVar10 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / (iVar10 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar5 < iVar9) {
        local_2c = iVar9 - iVar5;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar4;
        DAT_1007b290 = iVar5;
        DAT_1007b2cc = uVar14;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
        FUN_10070b60();
        _DAT_1007b454 = _DAT_100740f4 / (float)local_2c;
        _DAT_1007b448 = DAT_1007b478;
        _DAT_1007b440 = DAT_1007b334;
        _DAT_1007b450 = DAT_1007b47c;
        _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b454;
        _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b454;
        _DAT_1007b454 = _DAT_1007b454 * (DAT_1007b484 - DAT_1007b47c);
        DAT_1007b280 = iVar15 << 0x10;
        iVar16 = iVar16 - iVar15;
        if (local_2c == 1) {
          DAT_1007b28c = iVar16 * 0x10000;
        }
        else if (local_2c == 2) {
          DAT_1007b28c = iVar16 * 0x8000;
        }
        else if (((local_2c < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar8 + (iVar16 * 0x20 + local_2c) * 4);
        }
        else if (iVar16 < 0) {
          DAT_1007b28c = (iVar16 * 0x10000) / local_2c;
        }
        else {
          DAT_1007b28c = (iVar16 * 0x10000) / local_2c;
        }
        if (DAT_1007b43c == 0) {
          DAT_1007b2d0 = 0;
          if ((local_14 == local_18) || (local_2c == 1)) {
            uVar7 = uVar7 - uVar6;
          }
          else if (local_2c == 2) {
            uVar7 = (int)(uVar7 - uVar6) >> 1;
          }
          else {
            uVar7 = (int)(uVar7 - uVar6) / local_2c;
          }
          if (uVar7 != 0) {
            DAT_1007b2d0 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
          }
          if (iVar2 == iVar1) {
            DAT_1007b2e8 = iVar2 - iVar1;
          }
          else if (local_2c == 1) {
            DAT_1007b2e8 = iVar2 - iVar1;
          }
          else if (local_2c == 2) {
            DAT_1007b2e8 = iVar2 - iVar1 >> 1;
          }
          else {
            DAT_1007b2e8 = (iVar2 - iVar1) / local_2c;
          }
        }
      }
      else {
        local_2c = iVar5 - iVar9;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar4;
        DAT_1007b290 = iVar9;
        DAT_1007b2cc = uVar14;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
        FUN_10070b60();
        if (local_2c == 0) {
          return;
        }
        _DAT_1007b46c = _DAT_100740f4 / (float)local_2c;
        _DAT_1007b458 = DAT_1007b338;
        _DAT_1007b460 = DAT_1007b480;
        _DAT_1007b468 = DAT_1007b484;
        _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * _DAT_1007b46c;
        _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * _DAT_1007b46c;
        _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b47c - DAT_1007b484);
        DAT_1007b284 = iVar16 << 0x10;
        iVar15 = iVar15 - iVar16;
        if (local_2c == 1) {
          DAT_1007b288 = iVar15 * 0x10000;
        }
        else if (local_2c == 2) {
          DAT_1007b288 = iVar15 * 0x8000;
        }
        else if (((local_2c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar8 + (iVar15 * 0x20 + local_2c) * 4);
        }
        else if (iVar15 < 0) {
          DAT_1007b288 = (iVar15 * 0x10000) / local_2c;
        }
        else {
          DAT_1007b288 = (iVar15 * 0x10000) / local_2c;
        }
        if (DAT_1007b43c != 0) {
          DAT_1007b2d0 = 0;
          if ((local_14 == local_18) || (local_2c == 1)) {
            uVar6 = uVar6 - uVar7;
          }
          else if (local_2c == 2) {
            uVar6 = (int)(uVar6 - uVar7) >> 1;
          }
          else {
            uVar6 = (int)(uVar6 - uVar7) / local_2c;
          }
          if (uVar6 != 0) {
            DAT_1007b2d0 = (uVar6 & 0xffff) + (uVar6 & 0x8000) * -2;
          }
          if (DAT_1007b43c != 0) {
            if (iVar2 == iVar1) {
              DAT_1007b2e8 = iVar1 - iVar2;
            }
            else if (local_2c == 1) {
              DAT_1007b2e8 = iVar1 - iVar2;
            }
            else if (local_2c == 2) {
              DAT_1007b2e8 = iVar1 - iVar2 >> 1;
            }
            else {
              DAT_1007b2e8 = (iVar1 - iVar2) / local_2c;
            }
          }
        }
      }
      goto LAB_1002e78e;
    }
    iVar9 = iVar16 - DAT_1007b280;
    if (iVar9 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar15 = iVar15 - iVar16;
    if (iVar5 == 1) {
      DAT_1007b288 = iVar15 * 0x10000;
    }
    else if (iVar5 == 2) {
      DAT_1007b288 = iVar15 * 0x8000;
    }
    else if (((iVar5 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar8 + (iVar15 * 0x20 + iVar5) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007b288 = (iVar15 * 0x10000) / iVar5;
    }
    else {
      DAT_1007b288 = (iVar15 * 0x10000) / iVar5;
    }
    _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * fVar3;
    _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * fVar3;
    _DAT_1007b46c = (DAT_1007b47c - DAT_1007b484) * fVar3;
    if (DAT_1007b43c == 0) {
      if ((iVar2 == iVar4) || (iVar9 == 1)) {
        DAT_1007b2ec = iVar2 - iVar4;
      }
      else if (iVar9 == 2) {
        DAT_1007b2ec = iVar2 - iVar4 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar2 - iVar4) / iVar9;
      }
      if ((iVar1 == iVar4) || (iVar5 == 1)) {
        DAT_1007b2e8 = iVar1 - iVar4;
        DAT_1007b2e4 = iVar4;
      }
      else if (iVar5 == 2) {
        DAT_1007b2e8 = iVar1 - iVar4 >> 1;
        DAT_1007b2e4 = iVar4;
      }
      else {
        DAT_1007b2e8 = (iVar1 - iVar4) / iVar5;
        DAT_1007b2e4 = iVar4;
      }
    }
    else {
      if ((iVar2 == iVar4) || (iVar9 == 1)) {
        DAT_1007b2ec = iVar4 - iVar2;
      }
      else if (iVar9 == 2) {
        DAT_1007b2ec = iVar4 - iVar2 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar4 - iVar2) / iVar9;
      }
      DAT_1007b2e4 = iVar2;
      if (iVar2 == iVar1) {
        DAT_1007b2e8 = iVar1 - iVar2;
      }
      else if (iVar5 == 1) {
        DAT_1007b2e8 = iVar1 - iVar2;
      }
      else if (iVar5 == 2) {
        DAT_1007b2e8 = iVar1 - iVar2 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar1 - iVar2) / iVar5;
      }
    }
    if (DAT_1007b43c == 0) {
      uVar7 = uVar7 & 0xffff;
      if ((local_14 == sVar13) || (iVar9 == 1)) {
        uVar7 = uVar7 - (uVar14 & 0xffff);
      }
      else if (iVar9 == 2) {
        uVar7 = (int)(uVar7 - (uVar14 & 0xffff)) >> 1;
      }
      else {
        uVar7 = (int)(uVar7 - (uVar14 & 0xffff)) / iVar9;
      }
      uVar11 = uVar14 & 0xffff;
      DAT_1007b2d4 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      DAT_1007b2cc = uVar14;
      if ((local_18 == sVar13) || (iVar5 == 1)) goto LAB_1002e2a6;
      if (iVar5 == 2) {
        uVar11 = (int)((uVar6 & 0xffff) - uVar11) >> 1;
      }
      else {
        uVar11 = (int)((uVar6 & 0xffff) - uVar11) / iVar5;
      }
    }
    else {
      if ((local_14 == sVar13) || (iVar9 == 1)) {
        uVar14 = (uVar14 & 0xffff) - (uVar7 & 0xffff);
      }
      else if (iVar9 == 2) {
        uVar14 = (int)((uVar14 & 0xffff) - (uVar7 & 0xffff)) >> 1;
      }
      else {
        uVar14 = (int)((uVar14 & 0xffff) - (uVar7 & 0xffff)) / iVar9;
      }
      uVar11 = uVar7 & 0xffff;
      DAT_1007b2d4 = (uVar14 & 0xffff) + (uVar14 & 0x8000) * -2;
      DAT_1007b2cc = uVar7;
      if ((local_14 == local_18) || (iVar5 == 1)) {
LAB_1002e2a6:
        uVar11 = (uVar6 & 0xffff) - uVar11;
      }
      else if (iVar5 == 2) {
        uVar11 = (int)((uVar6 & 0xffff) - uVar11) >> 1;
      }
      else {
        uVar11 = (int)((uVar6 & 0xffff) - uVar11) / iVar5;
      }
    }
    DAT_1007b2d0 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
    _DAT_1007b458 = DAT_1007b338;
    _DAT_1007b460 = DAT_1007b480;
    _DAT_1007b468 = DAT_1007b484;
    local_2c = iVar5;
    iVar15 = DAT_1007b280;
    DAT_1007b280 = iVar16;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar15 << 0x10;
  DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2f0;
LAB_1002e78e:
  DAT_1007b290 = local_2c;
  FUN_10070b60();
  return;
}


