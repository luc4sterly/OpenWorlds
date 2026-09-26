// 1002ec20 FUN_1002ec20 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002ec20(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_c;
  
  iVar2 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar2 = param_2;
      param_2 = param_4;
      param_4 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1002ec66;
  param_3 = param_2;
  param_2 = param_4;
  param_4 = iVar2;
LAB_1002ec66:
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iStack_c = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  iVar5 = (int)*(short *)(param_2 + 0x1a);
  DAT_1007b330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar7 = (int)*(short *)(param_3 + 0x1a);
  iVar6 = (int)*(short *)(param_4 + 0x1a);
  DAT_1007b334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007b338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007b470 = (float)*(int *)(param_2 + 100) * _DAT_100740f0 * DAT_1007b330;
  DAT_1007b474 = (float)*(int *)(param_2 + 0x68) * _DAT_100740f0 * DAT_1007b330;
  DAT_1007b478 = (float)*(int *)(param_3 + 100) * _DAT_100740f0 * DAT_1007b334;
  DAT_1007b47c = (float)*(int *)(param_3 + 0x68) * _DAT_100740f0 * DAT_1007b334;
  DAT_1007b480 = (float)*(int *)(param_4 + 100) * _DAT_100740f0 * DAT_1007b338;
  DAT_1007b484 = (float)*(int *)(param_4 + 0x68) * _DAT_100740f0 * DAT_1007b338;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar4 = DAT_10075214 + 0x1000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  iVar2 = DAT_10075228;
  if (DAT_1007b43c != 0) {
    iVar2 = DAT_10075230;
  }
  _DAT_1007b2a4 = *(undefined4 *)(iVar2 + (DAT_1007b284 & 7) * 4);
  if (iStack_c < 1) {
    if (iVar5 == iVar7 || iVar5 - iVar7 < 0) {
      DAT_1007b280 = iVar5;
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    iStack_c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_c == 0) {
      DAT_1007b280 = iVar5;
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    _DAT_1007b46c = _DAT_100740f4 / (float)iStack_c;
    _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b46c;
    _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b46c;
    _DAT_1007b454 = (DAT_1007b484 - DAT_1007b47c) * _DAT_1007b46c;
    _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
    _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
    _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b484 - DAT_1007b474);
    iVar2 = iVar6 - iVar7;
    if (iStack_c == 1) {
      DAT_1007b28c = iVar2 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1007b28c = iVar2 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar4 + (iVar2 * 0x20 + iStack_c) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007b28c = (iVar2 * 0x10000) / iStack_c;
    }
    else {
      DAT_1007b28c = (iVar2 * 0x10000) / iStack_c;
    }
    iVar6 = iVar6 - iVar5;
    if (iStack_c == 1) {
      DAT_1007b288 = iVar6 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1007b288 = iVar6 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar4 + (iVar6 * 0x20 + iStack_c) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b288 = (iVar6 * 0x10000) / iStack_c;
    }
    else {
      DAT_1007b288 = (iVar6 * 0x10000) / iStack_c;
    }
    DAT_1007b280 = iVar7 << 0x10;
    DAT_1007b284 = iVar5 << 0x10;
    _DAT_1007b440 = DAT_1007b334;
    _DAT_1007b448 = DAT_1007b478;
    _DAT_1007b450 = DAT_1007b47c;
    _DAT_1007b458 = DAT_1007b330;
    _DAT_1007b460 = DAT_1007b470;
    _DAT_1007b468 = DAT_1007b474;
  }
  else {
    iVar2 = iVar7 - iVar5;
    if (iStack_c == 1) {
      DAT_1007b28c = iVar2 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1007b28c = iVar2 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar4 + (iVar2 * 0x20 + iStack_c) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007b28c = (iVar2 * 0x10000) / iStack_c;
    }
    else {
      DAT_1007b28c = (iVar2 * 0x10000) / iStack_c;
    }
    fVar1 = _DAT_100740f4 / (float)iStack_c;
    _DAT_1007b444 = (DAT_1007b334 - DAT_1007b330) * fVar1;
    _DAT_1007b44c = (DAT_1007b478 - DAT_1007b470) * fVar1;
    _DAT_1007b454 = (DAT_1007b47c - DAT_1007b474) * fVar1;
    iVar2 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    _DAT_1007b440 = DAT_1007b330;
    _DAT_1007b448 = DAT_1007b470;
    _DAT_1007b450 = DAT_1007b474;
    if (iVar2 < 1) {
      if (iVar6 == iVar5 || iVar6 - iVar5 < 0) {
        DAT_1007b280 = iVar5;
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      iVar7 = iVar7 - iVar6;
      if (iStack_c == 1) {
        DAT_1007b288 = iVar7 * 0x10000;
      }
      else if (iStack_c == 2) {
        DAT_1007b288 = iVar7 * 0x8000;
      }
      else if (((iStack_c < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar4 + (iVar7 * 0x20 + iStack_c) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1007b288 = (iVar7 * 0x10000) / iStack_c;
      }
      else {
        DAT_1007b288 = (iVar7 * 0x10000) / iStack_c;
      }
      _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * fVar1;
      _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * fVar1;
      DAT_1007b280 = iVar5 << 0x10;
      _DAT_1007b46c = (DAT_1007b47c - DAT_1007b484) * fVar1;
      DAT_1007b284 = iVar6 << 0x10;
      _DAT_1007b458 = DAT_1007b338;
      _DAT_1007b460 = DAT_1007b480;
      _DAT_1007b468 = DAT_1007b484;
    }
    else {
      iVar3 = iVar6 - iVar5;
      if (iVar2 == 1) {
        DAT_1007b288 = iVar3 * 0x10000;
      }
      else if (iVar2 == 2) {
        DAT_1007b288 = iVar3 * 0x8000;
      }
      else if (((iVar2 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar4 + (iVar3 * 0x20 + iVar2) * 4);
      }
      else if (iVar3 < 0) {
        DAT_1007b288 = (iVar3 * 0x10000) / iVar2;
      }
      else {
        DAT_1007b288 = (iVar3 * 0x10000) / iVar2;
      }
      if (DAT_1007b288 == DAT_1007b28c || DAT_1007b288 - DAT_1007b28c < 0) {
        DAT_1007b280 = iVar5;
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      _DAT_1007b46c = _DAT_100740f4 / (float)iVar2;
      _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
      _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
      _DAT_1007b46c = (DAT_1007b484 - DAT_1007b474) * _DAT_1007b46c;
      DAT_1007b280 = iVar5 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iStack_c < iVar2) {
        iVar2 = iVar2 - iStack_c;
        DAT_1007b290 = iStack_c;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
        FUN_1002e7b0((uint *)&DAT_1007b280);
        _DAT_1007b454 = _DAT_100740f4 / (float)iVar2;
        _DAT_1007b448 = DAT_1007b478;
        _DAT_1007b440 = DAT_1007b334;
        _DAT_1007b450 = DAT_1007b47c;
        _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b454;
        _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b454;
        _DAT_1007b454 = _DAT_1007b454 * (DAT_1007b484 - DAT_1007b47c);
        iVar6 = iVar6 - iVar7;
        DAT_1007b280 = iVar7 << 0x10;
        iStack_c = iVar2;
        if (iVar2 == 1) {
          DAT_1007b28c = iVar6 * 0x10000;
        }
        else if (iVar2 == 2) {
          DAT_1007b28c = iVar6 * 0x8000;
        }
        else if (((iVar2 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar4 + (iVar6 * 0x20 + iVar2) * 4);
        }
        else if (iVar6 < 0) {
          DAT_1007b28c = (iVar6 * 0x10000) / iVar2;
        }
        else {
          DAT_1007b28c = (iVar6 * 0x10000) / iVar2;
        }
      }
      else {
        iStack_c = iStack_c - iVar2;
        DAT_1007b290 = iVar2;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
        FUN_1002e7b0((uint *)&DAT_1007b280);
        if (iStack_c == 0) {
          return;
        }
        _DAT_1007b46c = _DAT_100740f4 / (float)iStack_c;
        _DAT_1007b458 = DAT_1007b338;
        _DAT_1007b460 = DAT_1007b480;
        _DAT_1007b468 = DAT_1007b484;
        _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * _DAT_1007b46c;
        _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * _DAT_1007b46c;
        _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b47c - DAT_1007b484);
        iVar7 = iVar7 - iVar6;
        DAT_1007b284 = iVar6 << 0x10;
        if (iStack_c == 1) {
          DAT_1007b288 = iVar7 * 0x10000;
        }
        else if (iStack_c == 2) {
          DAT_1007b288 = iVar7 * 0x8000;
        }
        else if (((iStack_c < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar4 + (iVar7 * 0x20 + iStack_c) * 4);
        }
        else if (iVar7 < 0) {
          DAT_1007b288 = (iVar7 * 0x10000) / iStack_c;
        }
        else {
          DAT_1007b288 = (iVar7 * 0x10000) / iStack_c;
        }
      }
    }
  }
  DAT_1007b290 = iStack_c;
  FUN_1002e7b0((uint *)&DAT_1007b280);
  return;
}


