// 1002edd0 FUN_1002edd0 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002edd0(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  int iStack_10;
  
  iVar10 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar10 = param_2;
      param_2 = param_4;
      param_4 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1002ee16;
  param_3 = param_2;
  param_2 = param_4;
  param_4 = iVar10;
LAB_1002ee16:
  DAT_1008d284 = (int)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iStack_10 = sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  DAT_1008d330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar10 = (int)*(short *)(param_3 + 0x1a);
  iVar11 = (int)*(short *)(param_4 + 0x1a);
  DAT_1008d334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d470 = (float)*(int *)(param_2 + 100) * _DAT_10086110 * DAT_1008d330;
  DAT_1008d474 = (float)*(int *)(param_2 + 0x68) * _DAT_10086110 * DAT_1008d330;
  DAT_1008d478 = (float)*(int *)(param_3 + 100) * _DAT_10086110 * DAT_1008d334;
  DAT_1008d47c = (float)*(int *)(param_3 + 0x68) * _DAT_10086110 * DAT_1008d334;
  DAT_1008d480 = (float)*(int *)(param_4 + 100) * _DAT_10086110 * DAT_1008d338;
  DAT_1008d484 = (float)*(int *)(param_4 + 0x68) * _DAT_10086110 * DAT_1008d338;
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248 + 0x800;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  if ((DAT_1008a100 == 0) || (*(float *)(param_1[0xf] + 0x14) <= _DAT_10089dd0)) {
    DAT_1008dbe0._4_4_ = 0;
  }
  else {
    lVar12 = __ftol();
    iVar4 = (int)lVar12;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    iVar4 = 0x10000 - iVar4;
    uVar7 = iVar4 * DAT_10089ef8;
    uVar9 = iVar4 * DAT_10089ef0;
    uVar8 = iVar4 * DAT_10089de4;
    if (0x1e0000 < (int)(param_1[1] + uVar7)) {
      uVar7 = 0x1e0000 - param_1[1];
    }
    if (0x1e0000 < (int)(param_1[2] + uVar9)) {
      uVar9 = 0x1e0000 - param_1[2];
    }
    if (0x1e0000 < (int)(uVar8 + param_1[3])) {
      uVar8 = 0x1e0000 - param_1[3];
    }
    if ((int)uVar7 < 0) {
      uVar7 = 0;
    }
    if ((int)uVar9 < 0) {
      uVar9 = 0;
    }
    if ((int)uVar8 < 0) {
      uVar8 = 0;
    }
    uVar7 = (int)((uVar9 & 0x1f8000) >> 5 | uVar7 & 0x1f0000) >> 5 | (uVar8 & 0x1f0000) >> 0x10;
    DAT_1008dbe0._4_4_ = uVar7 | uVar7 << 0x10;
  }
  iVar4 = DAT_1008723c + 0x1000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  DAT_1008dbe0._0_4_ = DAT_1008dbe0._4_4_;
  if (iStack_10 < 1) {
    if (DAT_1008d280 == iVar10 || DAT_1008d280 - iVar10 < 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iStack_10 = -((int)sVar1 - (int)sVar2);
    if (iStack_10 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    _DAT_1008d46c = _DAT_10086114 / (float)iStack_10;
    _DAT_1008d448 = DAT_1008d478;
    _DAT_1008d440 = DAT_1008d334;
    _DAT_1008d450 = DAT_1008d47c;
    _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d46c;
    _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d46c;
    _DAT_1008d454 = (DAT_1008d484 - DAT_1008d47c) * _DAT_1008d46c;
    _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
    _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
    _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d484 - DAT_1008d474);
    _DAT_1008d458 = DAT_1008d330;
    _DAT_1008d460 = DAT_1008d470;
    _DAT_1008d468 = DAT_1008d474;
    iVar5 = iVar11 - iVar10;
    if (iStack_10 == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (iStack_10 == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((iStack_10 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar4 + (iVar5 * 0x20 + iStack_10) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / iStack_10;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / iStack_10;
    }
    iVar11 = iVar11 - DAT_1008d280;
    if (iStack_10 == 1) {
      DAT_1008d288 = iVar11 * 0x10000;
    }
    else if (iStack_10 == 2) {
      DAT_1008d288 = iVar11 * 0x8000;
    }
    else if (((iStack_10 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar4 + (iVar11 * 0x20 + iStack_10) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1008d288 = (iVar11 * 0x10000) / iStack_10;
    }
    else {
      DAT_1008d288 = (iVar11 * 0x10000) / iStack_10;
    }
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d280 = iVar10 << 0x10;
  }
  else {
    iVar5 = iVar10 - DAT_1008d280;
    if (iStack_10 == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (iStack_10 == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((iStack_10 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar4 + (iVar5 * 0x20 + iStack_10) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / iStack_10;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / iStack_10;
    }
    fVar3 = _DAT_10086114 / (float)iStack_10;
    _DAT_1008d448 = DAT_1008d470;
    _DAT_1008d440 = DAT_1008d330;
    _DAT_1008d444 = (DAT_1008d334 - DAT_1008d330) * fVar3;
    _DAT_1008d44c = (DAT_1008d478 - DAT_1008d470) * fVar3;
    _DAT_1008d454 = (DAT_1008d47c - DAT_1008d474) * fVar3;
    _DAT_1008d450 = DAT_1008d474;
    iVar5 = sVar2 - DAT_1008d284;
    if (iVar5 < 1) {
      if (iVar11 == DAT_1008d280 || iVar11 - DAT_1008d280 < 0) {
        DAT_1008d298 = DAT_10089ddc;
        _DAT_1008d440 = DAT_1008d330;
        return;
      }
      iVar10 = iVar10 - iVar11;
      if (iStack_10 == 1) {
        DAT_1008d288 = iVar10 * 0x10000;
      }
      else if (iStack_10 == 2) {
        DAT_1008d288 = iVar10 * 0x8000;
      }
      else if (((iStack_10 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar4 + (iVar10 * 0x20 + iStack_10) * 4);
      }
      else if (iVar10 < 0) {
        DAT_1008d288 = (iVar10 * 0x10000) / iStack_10;
      }
      else {
        DAT_1008d288 = (iVar10 * 0x10000) / iStack_10;
      }
      _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * fVar3;
      _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * fVar3;
      _DAT_1008d458 = DAT_1008d338;
      _DAT_1008d46c = (DAT_1008d47c - DAT_1008d484) * fVar3;
      DAT_1008d284 = iVar11 << 0x10;
      _DAT_1008d460 = DAT_1008d480;
      _DAT_1008d468 = DAT_1008d484;
      DAT_1008d280 = DAT_1008d280 << 0x10;
    }
    else {
      iVar6 = iVar11 - DAT_1008d280;
      if (iVar5 == 1) {
        DAT_1008d288 = iVar6 * 0x10000;
      }
      else if (iVar5 == 2) {
        DAT_1008d288 = iVar6 * 0x8000;
      }
      else if (((iVar5 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar4 + (iVar6 * 0x20 + iVar5) * 4);
      }
      else if (iVar6 < 0) {
        DAT_1008d288 = (iVar6 * 0x10000) / iVar5;
      }
      else {
        DAT_1008d288 = (iVar6 * 0x10000) / iVar5;
      }
      if (DAT_1008d288 == DAT_1008d28c || DAT_1008d288 - DAT_1008d28c < 0) {
        DAT_1008d298 = DAT_10089ddc;
        _DAT_1008d440 = DAT_1008d330;
        return;
      }
      _DAT_1008d46c = _DAT_10086114 / (float)iVar5;
      _DAT_1008d460 = DAT_1008d470;
      _DAT_1008d458 = DAT_1008d330;
      _DAT_1008d468 = DAT_1008d474;
      _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
      _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
      _DAT_1008d46c = (DAT_1008d484 - DAT_1008d474) * _DAT_1008d46c;
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iStack_10 < iVar5) {
        iVar5 = iVar5 - iStack_10;
        DAT_1008d290 = iStack_10;
        FUN_1007e350();
        _DAT_1008d454 = _DAT_10086114 / (float)iVar5;
        _DAT_1008d448 = DAT_1008d478;
        _DAT_1008d440 = DAT_1008d334;
        _DAT_1008d450 = DAT_1008d47c;
        _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d454;
        _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d454;
        _DAT_1008d454 = _DAT_1008d454 * (DAT_1008d484 - DAT_1008d47c);
        iVar11 = iVar11 - iVar10;
        DAT_1008d280 = iVar10 << 0x10;
        iStack_10 = iVar5;
        if (iVar5 == 1) {
          DAT_1008d28c = iVar11 * 0x10000;
        }
        else if (iVar5 == 2) {
          DAT_1008d28c = iVar11 * 0x8000;
        }
        else if (((iVar5 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar4 + (iVar11 * 0x20 + iVar5) * 4);
        }
        else if (iVar11 < 0) {
          DAT_1008d28c = (iVar11 * 0x10000) / iVar5;
        }
        else {
          DAT_1008d28c = (iVar11 * 0x10000) / iVar5;
        }
      }
      else {
        iStack_10 = iStack_10 - iVar5;
        DAT_1008d290 = iVar5;
        FUN_1007e350();
        if (iStack_10 == 0) {
          return;
        }
        _DAT_1008d46c = _DAT_10086114 / (float)iStack_10;
        _DAT_1008d458 = DAT_1008d338;
        _DAT_1008d460 = DAT_1008d480;
        _DAT_1008d468 = DAT_1008d484;
        _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * _DAT_1008d46c;
        _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * _DAT_1008d46c;
        _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d47c - DAT_1008d484);
        iVar10 = iVar10 - iVar11;
        DAT_1008d284 = iVar11 << 0x10;
        if (iStack_10 == 1) {
          DAT_1008d288 = iVar10 * 0x10000;
        }
        else if (iStack_10 == 2) {
          DAT_1008d288 = iVar10 * 0x8000;
        }
        else if (((iStack_10 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar4 + (iVar10 * 0x20 + iStack_10) * 4);
        }
        else if (iVar10 < 0) {
          DAT_1008d288 = (iVar10 * 0x10000) / iStack_10;
        }
        else {
          DAT_1008d288 = (iVar10 * 0x10000) / iStack_10;
        }
      }
    }
  }
  DAT_1008d290 = iStack_10;
  FUN_1007e350();
  return;
}


