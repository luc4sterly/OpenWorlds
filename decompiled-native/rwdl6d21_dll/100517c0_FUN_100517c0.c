// 100517c0 FUN_100517c0 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100517c0(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_c;
  
  iVar4 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar4 = param_2;
      param_2 = param_4;
      param_4 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_10051806;
  param_3 = param_2;
  param_2 = param_4;
  param_4 = iVar4;
LAB_10051806:
  DAT_1007f284 = (int)*(short *)(param_2 + 0x1e);
  iStack_c = *(short *)(param_3 + 0x1e) - DAT_1007f284;
  iVar5 = (int)*(short *)(param_2 + 0x1a);
  DAT_1007f330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar7 = (int)*(short *)(param_3 + 0x1a);
  iVar6 = (int)*(short *)(param_4 + 0x1a);
  DAT_1007f334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007f338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007f470 = (float)*(int *)(param_2 + 100) * _DAT_10078118 * DAT_1007f330;
  DAT_1007f474 = (float)*(int *)(param_2 + 0x68) * _DAT_10078118 * DAT_1007f330;
  DAT_1007f478 = (float)*(int *)(param_3 + 100) * _DAT_10078118 * DAT_1007f334;
  DAT_1007f47c = (float)*(int *)(param_3 + 0x68) * _DAT_10078118 * DAT_1007f334;
  DAT_1007f480 = (float)*(int *)(param_4 + 100) * _DAT_10078118 * DAT_1007f338;
  DAT_1007f484 = (float)*(int *)(param_4 + 0x68) * _DAT_10078118 * DAT_1007f338;
  iVar4 = DAT_10079214 + 0x1000;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  if (iStack_c < 1) {
    if (iVar5 == iVar7 || iVar5 - iVar7 < 0) {
      DAT_1007f280 = iVar5;
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    iStack_c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_c == 0) {
      DAT_1007f280 = iVar5;
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    _DAT_1007f46c = _DAT_1007811c / (float)iStack_c;
    _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f46c;
    _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f46c;
    _DAT_1007f454 = (DAT_1007f484 - DAT_1007f47c) * _DAT_1007f46c;
    _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
    _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
    _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f484 - DAT_1007f474);
    iVar2 = iVar6 - iVar7;
    if (iStack_c == 1) {
      DAT_1007f28c = iVar2 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1007f28c = iVar2 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar4 + (iVar2 * 0x20 + iStack_c) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007f28c = (iVar2 * 0x10000) / iStack_c;
    }
    else {
      DAT_1007f28c = (iVar2 * 0x10000) / iStack_c;
    }
    iVar6 = iVar6 - iVar5;
    if (iStack_c == 1) {
      DAT_1007f288 = iVar6 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1007f288 = iVar6 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar4 + (iVar6 * 0x20 + iStack_c) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007f288 = (iVar6 * 0x10000) / iStack_c;
    }
    else {
      DAT_1007f288 = (iVar6 * 0x10000) / iStack_c;
    }
    DAT_1007f280 = iVar7 << 0x10;
    DAT_1007f284 = iVar5 << 0x10;
    _DAT_1007f440 = DAT_1007f334;
    _DAT_1007f448 = DAT_1007f478;
    _DAT_1007f450 = DAT_1007f47c;
    _DAT_1007f458 = DAT_1007f330;
    _DAT_1007f460 = DAT_1007f470;
    _DAT_1007f468 = DAT_1007f474;
  }
  else {
    iVar2 = iVar7 - iVar5;
    if (iStack_c == 1) {
      DAT_1007f28c = iVar2 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1007f28c = iVar2 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar4 + (iVar2 * 0x20 + iStack_c) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007f28c = (iVar2 * 0x10000) / iStack_c;
    }
    else {
      DAT_1007f28c = (iVar2 * 0x10000) / iStack_c;
    }
    fVar1 = _DAT_1007811c / (float)iStack_c;
    _DAT_1007f444 = (DAT_1007f334 - DAT_1007f330) * fVar1;
    _DAT_1007f44c = (DAT_1007f478 - DAT_1007f470) * fVar1;
    _DAT_1007f454 = (DAT_1007f47c - DAT_1007f474) * fVar1;
    iVar2 = *(short *)(param_4 + 0x1e) - DAT_1007f284;
    _DAT_1007f440 = DAT_1007f330;
    _DAT_1007f448 = DAT_1007f470;
    _DAT_1007f450 = DAT_1007f474;
    if (iVar2 < 1) {
      if (iVar6 == iVar5 || iVar6 - iVar5 < 0) {
        DAT_1007f280 = iVar5;
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar7 = iVar7 - iVar6;
      if (iStack_c == 1) {
        DAT_1007f288 = iVar7 * 0x10000;
      }
      else if (iStack_c == 2) {
        DAT_1007f288 = iVar7 * 0x8000;
      }
      else if (((iStack_c < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar4 + (iVar7 * 0x20 + iStack_c) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1007f288 = (iVar7 * 0x10000) / iStack_c;
      }
      else {
        DAT_1007f288 = (iVar7 * 0x10000) / iStack_c;
      }
      _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * fVar1;
      _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * fVar1;
      DAT_1007f280 = iVar5 << 0x10;
      _DAT_1007f46c = (DAT_1007f47c - DAT_1007f484) * fVar1;
      DAT_1007f284 = iVar6 << 0x10;
      _DAT_1007f458 = DAT_1007f338;
      _DAT_1007f460 = DAT_1007f480;
      _DAT_1007f468 = DAT_1007f484;
    }
    else {
      iVar3 = iVar6 - iVar5;
      if (iVar2 == 1) {
        DAT_1007f288 = iVar3 * 0x10000;
      }
      else if (iVar2 == 2) {
        DAT_1007f288 = iVar3 * 0x8000;
      }
      else if (((iVar2 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar4 + (iVar3 * 0x20 + iVar2) * 4);
      }
      else if (iVar3 < 0) {
        DAT_1007f288 = (iVar3 * 0x10000) / iVar2;
      }
      else {
        DAT_1007f288 = (iVar3 * 0x10000) / iVar2;
      }
      if (DAT_1007f288 == DAT_1007f28c || DAT_1007f288 - DAT_1007f28c < 0) {
        DAT_1007f280 = iVar5;
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      _DAT_1007f46c = _DAT_1007811c / (float)iVar2;
      _DAT_1007f45c = (DAT_1007f338 - DAT_1007f330) * _DAT_1007f46c;
      _DAT_1007f464 = (DAT_1007f480 - DAT_1007f470) * _DAT_1007f46c;
      _DAT_1007f46c = (DAT_1007f484 - DAT_1007f474) * _DAT_1007f46c;
      DAT_1007f280 = iVar5 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iStack_c < iVar2) {
        iVar2 = iVar2 - iStack_c;
        DAT_1007f290 = iStack_c;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_100760d0();
        _DAT_1007f454 = _DAT_1007811c / (float)iVar2;
        _DAT_1007f448 = DAT_1007f478;
        _DAT_1007f440 = DAT_1007f334;
        _DAT_1007f450 = DAT_1007f47c;
        _DAT_1007f444 = (DAT_1007f338 - DAT_1007f334) * _DAT_1007f454;
        _DAT_1007f44c = (DAT_1007f480 - DAT_1007f478) * _DAT_1007f454;
        _DAT_1007f454 = _DAT_1007f454 * (DAT_1007f484 - DAT_1007f47c);
        iVar6 = iVar6 - iVar7;
        DAT_1007f280 = iVar7 << 0x10;
        iStack_c = iVar2;
        if (iVar2 == 1) {
          DAT_1007f28c = iVar6 * 0x10000;
        }
        else if (iVar2 == 2) {
          DAT_1007f28c = iVar6 * 0x8000;
        }
        else if (((iVar2 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar4 + (iVar6 * 0x20 + iVar2) * 4);
        }
        else if (iVar6 < 0) {
          DAT_1007f28c = (iVar6 * 0x10000) / iVar2;
        }
        else {
          DAT_1007f28c = (iVar6 * 0x10000) / iVar2;
        }
      }
      else {
        iStack_c = iStack_c - iVar2;
        DAT_1007f290 = iVar2;
        _DAT_1007f458 = DAT_1007f330;
        _DAT_1007f460 = DAT_1007f470;
        _DAT_1007f468 = DAT_1007f474;
        FUN_100760d0();
        if (iStack_c == 0) {
          return;
        }
        _DAT_1007f46c = _DAT_1007811c / (float)iStack_c;
        _DAT_1007f458 = DAT_1007f338;
        _DAT_1007f460 = DAT_1007f480;
        _DAT_1007f468 = DAT_1007f484;
        _DAT_1007f45c = (DAT_1007f334 - DAT_1007f338) * _DAT_1007f46c;
        _DAT_1007f464 = (DAT_1007f478 - DAT_1007f480) * _DAT_1007f46c;
        _DAT_1007f46c = _DAT_1007f46c * (DAT_1007f47c - DAT_1007f484);
        iVar7 = iVar7 - iVar6;
        DAT_1007f284 = iVar6 << 0x10;
        if (iStack_c == 1) {
          DAT_1007f288 = iVar7 * 0x10000;
        }
        else if (iStack_c == 2) {
          DAT_1007f288 = iVar7 * 0x8000;
        }
        else if (((iStack_c < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar4 + (iVar7 * 0x20 + iStack_c) * 4);
        }
        else if (iVar7 < 0) {
          DAT_1007f288 = (iVar7 * 0x10000) / iStack_c;
        }
        else {
          DAT_1007f288 = (iVar7 * 0x10000) / iStack_c;
        }
      }
    }
  }
  DAT_1007f290 = iStack_c;
  FUN_100760d0();
  return;
}


