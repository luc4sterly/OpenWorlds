// 1002d200 FUN_1002d200 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002d200(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_18;
  
  iVar3 = param_3;
  iVar9 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar3 = param_2;
      param_2 = param_4;
      iVar9 = param_3;
    }
LAB_1002d246:
    param_3 = param_2;
    param_4 = iVar3;
    param_2 = iVar9;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1002d246;
  DAT_1007f284 = (int)*(short *)(param_2 + 0x1e);
  iVar4 = *(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  iVar1 = *(int *)(param_2 + 0x20);
  iVar3 = *(int *)(param_3 + 0x20);
  DAT_1007f330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar8 = (int)*(short *)(param_3 + 0x1a);
  iVar5 = (int)*(short *)(param_4 + 0x1a);
  iVar9 = *(int *)(param_4 + 0x20);
  DAT_1007f334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007f338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007f470 = (float)*(int *)(param_2 + 100) * _DAT_100780f8 * DAT_1007f330;
  DAT_1007f474 = (float)*(int *)(param_2 + 0x68) * _DAT_100780f8 * DAT_1007f330;
  DAT_1007f478 = (float)*(int *)(param_3 + 100) * _DAT_100780f8 * DAT_1007f334;
  DAT_1007f47c = (float)*(int *)(param_3 + 0x68) * _DAT_100780f8 * DAT_1007f334;
  DAT_1007f480 = (float)*(int *)(param_4 + 100) * _DAT_100780f8 * DAT_1007f338;
  DAT_1007f484 = (float)*(int *)(param_4 + 0x68) * _DAT_100780f8 * DAT_1007f338;
  DAT_1007f29c = DAT_1007f284 * DAT_1007beb0 + DAT_10079210;
  DAT_1007f2a0 = DAT_1007beb0;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007f2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10079220;
  _DAT_1007f2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10079220 + 0x400;
  _DAT_1007f2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10079220;
  iVar10 = DAT_10079214 + 0x1000;
  DAT_1007f2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  if (iVar4 < 1) {
    iVar4 = DAT_1007f280 - iVar8;
    if (iVar4 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    local_18 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_18 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    _DAT_1007f46c = _DAT_100780fc / (float)local_18;
    _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f46c;
    _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f46c;
    _DAT_1007f454 = (DAT_1007f484 - DAT_1007f47c) * _DAT_1007f46c;
    _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
    _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
    _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f484 - DAT_1007f474);
    iVar6 = iVar5 - iVar8;
    if (local_18 == 1) {
      DAT_1007f28c = iVar6 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1007f28c = iVar6 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar10 + (iVar6 * 0x20 + local_18) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007f28c = (iVar6 * 0x10000) / local_18;
    }
    else {
      DAT_1007f28c = (iVar6 * 0x10000) / local_18;
    }
    iVar5 = iVar5 - DAT_1007f280;
    if (local_18 == 1) {
      DAT_1007f288 = iVar5 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1007f288 = iVar5 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar10 + (iVar5 * 0x20 + local_18) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007f288 = (iVar5 * 0x10000) / local_18;
    }
    else {
      DAT_1007f288 = (iVar5 * 0x10000) / local_18;
    }
    if ((iVar3 == iVar1) || (iVar4 == 1)) {
      DAT_1007f2ec = iVar1 - iVar3;
    }
    else if (iVar4 == 2) {
      DAT_1007f2ec = iVar1 - iVar3 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar1 - iVar3) / iVar4;
    }
    _DAT_1007f440 = DAT_1007f334;
    _DAT_1007f448 = DAT_1007f478;
    _DAT_1007f450 = DAT_1007f47c;
    iVar1 = iVar3;
    iVar5 = DAT_1007f280;
    if ((iVar9 == iVar3) || (local_18 == 1)) {
      DAT_1007f2e8 = iVar9 - iVar3;
      _DAT_1007f458 = DAT_1007f330;
      _DAT_1007f460 = DAT_1007f470;
      _DAT_1007f468 = DAT_1007f474;
    }
    else if (local_18 == 2) {
      DAT_1007f2e8 = iVar9 - iVar3 >> 1;
      _DAT_1007f458 = DAT_1007f330;
      _DAT_1007f460 = DAT_1007f470;
      _DAT_1007f468 = DAT_1007f474;
    }
    else {
      DAT_1007f2e8 = (iVar9 - iVar3) / local_18;
      _DAT_1007f458 = DAT_1007f330;
      _DAT_1007f460 = DAT_1007f470;
      _DAT_1007f468 = DAT_1007f474;
    }
  }
  else {
    iVar6 = iVar8 - DAT_1007f280;
    if (iVar4 == 1) {
      DAT_1007f28c = iVar6 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007f28c = iVar6 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar10 + (iVar6 * 0x20 + iVar4) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007f28c = (iVar6 * 0x10000) / iVar4;
    }
    else {
      DAT_1007f28c = (iVar6 * 0x10000) / iVar4;
    }
    fVar2 = _DAT_100780fc / (float)iVar4;
    _DAT_1007f444 = (DAT_1007f334 - DAT_1007f330) * fVar2;
    _DAT_1007f44c = (DAT_1007f478 - DAT_1007f470) * fVar2;
    _DAT_1007f454 = (DAT_1007f47c - DAT_1007f474) * fVar2;
    iVar6 = *(short *)(param_4 + 0x1e) - DAT_1007f284;
    _DAT_1007f440 = DAT_1007f330;
    _DAT_1007f448 = DAT_1007f470;
    _DAT_1007f450 = DAT_1007f474;
    if (0 < iVar6) {
      iVar7 = iVar5 - DAT_1007f280;
      if (iVar6 == 1) {
        DAT_1007f288 = iVar7 * 0x10000;
      }
      else if (iVar6 == 2) {
        DAT_1007f288 = iVar7 * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar10 + (iVar7 * 0x20 + iVar6) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1007f288 = (iVar7 * 0x10000) / iVar6;
      }
      else {
        DAT_1007f288 = (iVar7 * 0x10000) / iVar6;
      }
      if (DAT_1007f288 - DAT_1007f28c < 1) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f2a0 = DAT_1007beb0;
        return;
      }
      _DAT_1007f46c = _DAT_100780fc / (float)iVar6;
      _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
      _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
      _DAT_1007f46c = (DAT_1007f484 - DAT_1007f474) * _DAT_1007f46c;
      if ((iVar3 == iVar1) || (iVar4 == 1)) {
        DAT_1007f2e8 = iVar3 - iVar1;
      }
      else if (iVar4 == 2) {
        DAT_1007f2e8 = iVar3 - iVar1 >> 1;
      }
      else {
        DAT_1007f2e8 = (iVar3 - iVar1) / iVar4;
      }
      if ((iVar9 == iVar1) || (iVar6 == 1)) {
        iVar7 = iVar9 - iVar1;
      }
      else if (iVar6 == 2) {
        iVar7 = iVar9 - iVar1 >> 1;
      }
      else {
        iVar7 = (iVar9 - iVar1) / iVar6;
      }
      DAT_1007f2ec = iVar7 - DAT_1007f2e8;
      if ((DAT_1007f2ec != 0) && (iVar7 = DAT_1007f288 - DAT_1007f28c >> 6, iVar7 != 0)) {
        DAT_1007f2ec = DAT_1007f2ec / iVar7 << 10;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iVar4 < iVar6) {
        local_18 = iVar6 - iVar4;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar1;
        DAT_1007f290 = iVar4;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_1002cbb0(&DAT_1007f280);
        _DAT_1007f454 = _DAT_100780fc / (float)local_18;
        _DAT_1007f448 = DAT_1007f478;
        _DAT_1007f440 = DAT_1007f334;
        _DAT_1007f450 = DAT_1007f47c;
        _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f454;
        _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f454;
        _DAT_1007f454 = _DAT_1007f454 * (DAT_1007f484 - DAT_1007f47c);
        DAT_1007f280 = iVar8 << 0x10;
        iVar5 = iVar5 - iVar8;
        if (local_18 == 1) {
          DAT_1007f28c = iVar5 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1007f28c = iVar5 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar10 + (iVar5 * 0x20 + local_18) * 4);
        }
        else if (iVar5 < 0) {
          DAT_1007f28c = (iVar5 * 0x10000) / local_18;
        }
        else {
          DAT_1007f28c = (iVar5 * 0x10000) / local_18;
        }
        if (iVar9 == iVar3) {
          DAT_1007f2e8 = iVar9 - iVar3;
        }
        else if (local_18 == 1) {
          DAT_1007f2e8 = iVar9 - iVar3;
        }
        else if (local_18 == 2) {
          DAT_1007f2e8 = iVar9 - iVar3 >> 1;
        }
        else {
          DAT_1007f2e8 = (iVar9 - iVar3) / local_18;
        }
      }
      else {
        local_18 = iVar4 - iVar6;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar1;
        DAT_1007f290 = iVar6;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_1002cbb0(&DAT_1007f280);
        if (local_18 == 0) {
          return;
        }
        _DAT_1007f46c = _DAT_100780fc / (float)local_18;
        _DAT_1007f458 = DAT_1007f338;
        _DAT_1007f460 = DAT_1007f480;
        _DAT_1007f468 = DAT_1007f484;
        _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * _DAT_1007f46c;
        _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * _DAT_1007f46c;
        _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f47c - DAT_1007f484);
        DAT_1007f284 = iVar5 << 0x10;
        iVar8 = iVar8 - iVar5;
        if (local_18 == 1) {
          DAT_1007f288 = iVar8 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1007f288 = iVar8 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar10 + (iVar8 * 0x20 + local_18) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1007f288 = (iVar8 * 0x10000) / local_18;
        }
        else {
          DAT_1007f288 = (iVar8 * 0x10000) / local_18;
        }
      }
      goto LAB_1002ddaf;
    }
    iVar6 = iVar5 - DAT_1007f280;
    if (iVar6 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar8 = iVar8 - iVar5;
    if (iVar4 == 1) {
      DAT_1007f288 = iVar8 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1007f288 = iVar8 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar10 + (iVar8 * 0x20 + iVar4) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1007f288 = (iVar8 * 0x10000) / iVar4;
    }
    else {
      DAT_1007f288 = (iVar8 * 0x10000) / iVar4;
    }
    _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * fVar2;
    _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * fVar2;
    _DAT_1007f46c = (DAT_1007f47c - DAT_1007f484) * fVar2;
    if ((iVar9 == iVar1) || (iVar6 == 1)) {
      DAT_1007f2ec = iVar9 - iVar1;
    }
    else if (iVar6 == 2) {
      DAT_1007f2ec = iVar9 - iVar1 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar9 - iVar1) / iVar6;
    }
    _DAT_1007f458 = DAT_1007f338;
    _DAT_1007f460 = DAT_1007f480;
    _DAT_1007f468 = DAT_1007f484;
    local_18 = iVar4;
    iVar8 = DAT_1007f280;
    if ((iVar3 == iVar1) || (iVar4 == 1)) {
      DAT_1007f2e8 = iVar3 - iVar1;
    }
    else if (iVar4 == 2) {
      DAT_1007f2e8 = iVar3 - iVar1 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar3 - iVar1) / iVar4;
    }
  }
  DAT_1007f284 = iVar5 << 0x10;
  DAT_1007f280 = iVar8 << 0x10;
  DAT_1007f2e4 = DAT_1007f2f0 + iVar1;
LAB_1002ddaf:
  DAT_1007f290 = local_18;
  FUN_1002cbb0(&DAT_1007f280);
  return;
}


