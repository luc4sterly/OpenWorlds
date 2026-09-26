// 10059530 FUN_10059530 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10059530(int *param_1,int param_2,int param_3,int param_4)

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
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_10059579;
  param_3 = param_2;
  param_2 = param_4;
  param_4 = iVar4;
LAB_10059579:
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  iStack_c = (int)*(short *)(param_3 + 0x1e) - DAT_1008d284;
  iVar4 = (int)*(short *)(param_2 + 0x1a);
  DAT_1008d330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar5 = (int)*(short *)(param_3 + 0x1a);
  iVar6 = (int)*(short *)(param_4 + 0x1a);
  DAT_1008d334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d338 = *(float *)(param_2 + 0x14) * *(float *)(param_3 + 0x14);
  DAT_1008d470 = (float)*(int *)(param_2 + 100) * _DAT_10086130 * DAT_1008d330;
  DAT_1008d474 = (float)*(int *)(param_2 + 0x68) * _DAT_10086130 * DAT_1008d330;
  DAT_1008d478 = (float)*(int *)(param_3 + 100) * _DAT_10086130 * DAT_1008d334;
  DAT_1008d47c = (float)*(int *)(param_3 + 0x68) * _DAT_10086130 * DAT_1008d334;
  DAT_1008d480 = (float)*(int *)(param_4 + 100) * _DAT_10086130 * DAT_1008d338;
  DAT_1008d484 = (float)*(int *)(param_4 + 0x68) * _DAT_10086130 * DAT_1008d338;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar7 = DAT_1008723c + 0x1000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  _DAT_1008d2a4 = *(undefined4 *)(DAT_10087250 + (DAT_1008d284 & 7) * 4);
  if (iStack_c < 1) {
    if (iVar4 == iVar5 || iVar4 - iVar5 < 0) {
      DAT_1008d280 = iVar4;
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iStack_c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_c == 0) {
      DAT_1008d280 = iVar4;
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    _DAT_1008d46c = _DAT_10086134 / (float)iStack_c;
    _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d46c;
    _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d46c;
    _DAT_1008d454 = (DAT_1008d484 - DAT_1008d47c) * _DAT_1008d46c;
    _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
    _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
    _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d484 - DAT_1008d474);
    iVar2 = iVar6 - iVar5;
    if (iStack_c == 1) {
      DAT_1008d28c = iVar2 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1008d28c = iVar2 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar7 + (iVar2 * 0x20 + iStack_c) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1008d28c = (iVar2 * 0x10000) / iStack_c;
    }
    else {
      DAT_1008d28c = (iVar2 * 0x10000) / iStack_c;
    }
    iVar6 = iVar6 - iVar4;
    if (iStack_c == 1) {
      DAT_1008d288 = iVar6 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1008d288 = iVar6 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar7 + (iVar6 * 0x20 + iStack_c) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1008d288 = (iVar6 * 0x10000) / iStack_c;
    }
    else {
      DAT_1008d288 = (iVar6 * 0x10000) / iStack_c;
    }
    DAT_1008d280 = iVar5 << 0x10;
    DAT_1008d284 = iVar4 << 0x10;
    _DAT_1008d440 = DAT_1008d334;
    _DAT_1008d448 = DAT_1008d478;
    _DAT_1008d450 = DAT_1008d47c;
    _DAT_1008d458 = DAT_1008d330;
    _DAT_1008d460 = DAT_1008d470;
    _DAT_1008d468 = DAT_1008d474;
  }
  else {
    iVar2 = iVar5 - iVar4;
    if (iStack_c == 1) {
      DAT_1008d28c = iVar2 * 0x10000;
    }
    else if (iStack_c == 2) {
      DAT_1008d28c = iVar2 * 0x8000;
    }
    else if (((iStack_c < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar7 + (iVar2 * 0x20 + iStack_c) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1008d28c = (iVar2 * 0x10000) / iStack_c;
    }
    else {
      DAT_1008d28c = (iVar2 * 0x10000) / iStack_c;
    }
    fVar1 = _DAT_10086134 / (float)iStack_c;
    _DAT_1008d444 = (DAT_1008d334 - DAT_1008d330) * fVar1;
    _DAT_1008d44c = (DAT_1008d478 - DAT_1008d470) * fVar1;
    _DAT_1008d454 = (DAT_1008d47c - DAT_1008d474) * fVar1;
    iVar2 = (int)*(short *)(param_4 + 0x1e) - DAT_1008d284;
    _DAT_1008d440 = DAT_1008d330;
    _DAT_1008d448 = DAT_1008d470;
    _DAT_1008d450 = DAT_1008d474;
    if (iVar2 < 1) {
      if (iVar6 == iVar4 || iVar6 - iVar4 < 0) {
        DAT_1008d280 = iVar4;
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar5 = iVar5 - iVar6;
      if (iStack_c == 1) {
        DAT_1008d288 = iVar5 * 0x10000;
      }
      else if (iStack_c == 2) {
        DAT_1008d288 = iVar5 * 0x8000;
      }
      else if (((iStack_c < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar7 + (iVar5 * 0x20 + iStack_c) * 4);
      }
      else if (iVar5 < 0) {
        DAT_1008d288 = (iVar5 * 0x10000) / iStack_c;
      }
      else {
        DAT_1008d288 = (iVar5 * 0x10000) / iStack_c;
      }
      _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * fVar1;
      _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * fVar1;
      DAT_1008d280 = iVar4 << 0x10;
      _DAT_1008d46c = (DAT_1008d47c - DAT_1008d484) * fVar1;
      DAT_1008d284 = iVar6 << 0x10;
      _DAT_1008d458 = DAT_1008d338;
      _DAT_1008d460 = DAT_1008d480;
      _DAT_1008d468 = DAT_1008d484;
    }
    else {
      iVar3 = iVar6 - iVar4;
      if (iVar2 == 1) {
        DAT_1008d288 = iVar3 * 0x10000;
      }
      else if (iVar2 == 2) {
        DAT_1008d288 = iVar3 * 0x8000;
      }
      else if (((iVar2 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar7 + (iVar3 * 0x20 + iVar2) * 4);
      }
      else if (iVar3 < 0) {
        DAT_1008d288 = (iVar3 * 0x10000) / iVar2;
      }
      else {
        DAT_1008d288 = (iVar3 * 0x10000) / iVar2;
      }
      if (DAT_1008d288 == DAT_1008d28c || DAT_1008d288 - DAT_1008d28c < 0) {
        DAT_1008d280 = iVar4;
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      _DAT_1008d46c = _DAT_10086134 / (float)iVar2;
      _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
      _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
      _DAT_1008d46c = (DAT_1008d484 - DAT_1008d474) * _DAT_1008d46c;
      DAT_1008d280 = iVar4 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iStack_c < iVar2) {
        iVar2 = iVar2 - iStack_c;
        DAT_1008d290 = iStack_c;
        _DAT_1008d458 = DAT_1008d330;
        _DAT_1008d460 = DAT_1008d470;
        _DAT_1008d468 = DAT_1008d474;
        FUN_10059090((uint *)&DAT_1008d280);
        _DAT_1008d454 = _DAT_10086134 / (float)iVar2;
        _DAT_1008d448 = DAT_1008d478;
        _DAT_1008d440 = DAT_1008d334;
        _DAT_1008d450 = DAT_1008d47c;
        _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d454;
        _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d454;
        _DAT_1008d454 = _DAT_1008d454 * (DAT_1008d484 - DAT_1008d47c);
        iVar6 = iVar6 - iVar5;
        DAT_1008d280 = iVar5 << 0x10;
        iStack_c = iVar2;
        if (iVar2 == 1) {
          DAT_1008d28c = iVar6 * 0x10000;
        }
        else if (iVar2 == 2) {
          DAT_1008d28c = iVar6 * 0x8000;
        }
        else if (((iVar2 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar7 + (iVar6 * 0x20 + iVar2) * 4);
        }
        else if (iVar6 < 0) {
          DAT_1008d28c = (iVar6 * 0x10000) / iVar2;
        }
        else {
          DAT_1008d28c = (iVar6 * 0x10000) / iVar2;
        }
      }
      else {
        iStack_c = iStack_c - iVar2;
        DAT_1008d290 = iVar2;
        _DAT_1008d458 = DAT_1008d330;
        _DAT_1008d460 = DAT_1008d470;
        _DAT_1008d468 = DAT_1008d474;
        FUN_10059090((uint *)&DAT_1008d280);
        if (iStack_c == 0) {
          return;
        }
        _DAT_1008d46c = _DAT_10086134 / (float)iStack_c;
        _DAT_1008d458 = DAT_1008d338;
        _DAT_1008d460 = DAT_1008d480;
        _DAT_1008d468 = DAT_1008d484;
        _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * _DAT_1008d46c;
        _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * _DAT_1008d46c;
        _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d47c - DAT_1008d484);
        iVar5 = iVar5 - iVar6;
        DAT_1008d284 = iVar6 << 0x10;
        if (iStack_c == 1) {
          DAT_1008d288 = iVar5 * 0x10000;
        }
        else if (iStack_c == 2) {
          DAT_1008d288 = iVar5 * 0x8000;
        }
        else if (((iStack_c < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar7 + (iVar5 * 0x20 + iStack_c) * 4);
        }
        else if (iVar5 < 0) {
          DAT_1008d288 = (iVar5 * 0x10000) / iStack_c;
        }
        else {
          DAT_1008d288 = (iVar5 * 0x10000) / iStack_c;
        }
      }
    }
  }
  DAT_1008d290 = iStack_c;
  FUN_10059090((uint *)&DAT_1008d280);
  return;
}


