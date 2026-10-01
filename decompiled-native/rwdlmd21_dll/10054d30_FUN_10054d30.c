// 10054d30 FUN_10054d30 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10054d30(int *param_1,int param_2,int param_3,int param_4)

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
LAB_10054d76:
    param_3 = param_2;
    param_4 = iVar3;
    param_2 = iVar9;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10054d76;
  DAT_1008d284 = (int)*(short *)(param_2 + 0x1e);
  iVar4 = *(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  iVar1 = *(int *)(param_2 + 0x20);
  iVar3 = *(int *)(param_3 + 0x20);
  DAT_1008d330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar8 = (int)*(short *)(param_3 + 0x1a);
  iVar5 = (int)*(short *)(param_4 + 0x1a);
  iVar9 = *(int *)(param_4 + 0x20);
  DAT_1008d334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d470 = (float)*(int *)(param_2 + 100) * _DAT_10086130 * DAT_1008d330;
  DAT_1008d474 = (float)*(int *)(param_2 + 0x68) * _DAT_10086130 * DAT_1008d330;
  DAT_1008d478 = (float)*(int *)(param_3 + 100) * _DAT_10086130 * DAT_1008d334;
  DAT_1008d47c = (float)*(int *)(param_3 + 0x68) * _DAT_10086130 * DAT_1008d334;
  DAT_1008d480 = (float)*(int *)(param_4 + 100) * _DAT_10086130 * DAT_1008d338;
  DAT_1008d484 = (float)*(int *)(param_4 + 0x68) * _DAT_10086130 * DAT_1008d338;
  DAT_1008d29c = DAT_1008d284 * DAT_10089ef4 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248;
  iVar10 = DAT_1008723c + 0x1000;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  if (iVar4 < 1) {
    iVar4 = DAT_1008d280 - iVar8;
    if (iVar4 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    local_18 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_18 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    _DAT_1008d46c = _DAT_10086134 / (float)local_18;
    _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d46c;
    _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d46c;
    _DAT_1008d454 = (DAT_1008d484 - DAT_1008d47c) * _DAT_1008d46c;
    _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
    _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
    _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d484 - DAT_1008d474);
    iVar6 = iVar5 - iVar8;
    if (local_18 == 1) {
      DAT_1008d28c = iVar6 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1008d28c = iVar6 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar10 + (iVar6 * 0x20 + local_18) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1008d28c = (iVar6 * 0x10000) / local_18;
    }
    else {
      DAT_1008d28c = (iVar6 * 0x10000) / local_18;
    }
    iVar5 = iVar5 - DAT_1008d280;
    if (local_18 == 1) {
      DAT_1008d288 = iVar5 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1008d288 = iVar5 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar10 + (iVar5 * 0x20 + local_18) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d288 = (iVar5 * 0x10000) / local_18;
    }
    else {
      DAT_1008d288 = (iVar5 * 0x10000) / local_18;
    }
    if ((iVar3 == iVar1) || (iVar4 == 1)) {
      DAT_1008d2ec = iVar1 - iVar3;
    }
    else if (iVar4 == 2) {
      DAT_1008d2ec = iVar1 - iVar3 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar1 - iVar3) / iVar4;
    }
    _DAT_1008d440 = DAT_1008d334;
    _DAT_1008d448 = DAT_1008d478;
    _DAT_1008d450 = DAT_1008d47c;
    iVar1 = iVar3;
    iVar5 = DAT_1008d280;
    if ((iVar9 == iVar3) || (local_18 == 1)) {
      DAT_1008d2e8 = iVar9 - iVar3;
      _DAT_1008d458 = DAT_1008d330;
      _DAT_1008d460 = DAT_1008d470;
      _DAT_1008d468 = DAT_1008d474;
    }
    else if (local_18 == 2) {
      DAT_1008d2e8 = iVar9 - iVar3 >> 1;
      _DAT_1008d458 = DAT_1008d330;
      _DAT_1008d460 = DAT_1008d470;
      _DAT_1008d468 = DAT_1008d474;
    }
    else {
      DAT_1008d2e8 = (iVar9 - iVar3) / local_18;
      _DAT_1008d458 = DAT_1008d330;
      _DAT_1008d460 = DAT_1008d470;
      _DAT_1008d468 = DAT_1008d474;
    }
  }
  else {
    iVar6 = iVar8 - DAT_1008d280;
    if (iVar4 == 1) {
      DAT_1008d28c = iVar6 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1008d28c = iVar6 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar10 + (iVar6 * 0x20 + iVar4) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1008d28c = (iVar6 * 0x10000) / iVar4;
    }
    else {
      DAT_1008d28c = (iVar6 * 0x10000) / iVar4;
    }
    fVar2 = _DAT_10086134 / (float)iVar4;
    _DAT_1008d444 = (DAT_1008d334 - DAT_1008d330) * fVar2;
    _DAT_1008d44c = (DAT_1008d478 - DAT_1008d470) * fVar2;
    _DAT_1008d454 = (DAT_1008d47c - DAT_1008d474) * fVar2;
    iVar6 = *(short *)(param_4 + 0x1e) - DAT_1008d284;
    _DAT_1008d440 = DAT_1008d330;
    _DAT_1008d448 = DAT_1008d470;
    _DAT_1008d450 = DAT_1008d474;
    if (0 < iVar6) {
      iVar7 = iVar5 - DAT_1008d280;
      if (iVar6 == 1) {
        DAT_1008d288 = iVar7 * 0x10000;
      }
      else if (iVar6 == 2) {
        DAT_1008d288 = iVar7 * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar10 + (iVar7 * 0x20 + iVar6) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1008d288 = (iVar7 * 0x10000) / iVar6;
      }
      else {
        DAT_1008d288 = (iVar7 * 0x10000) / iVar6;
      }
      if (DAT_1008d288 - DAT_1008d28c < 1) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d2a0 = DAT_10089ef4;
        return;
      }
      _DAT_1008d46c = _DAT_10086134 / (float)iVar6;
      _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
      _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
      _DAT_1008d46c = (DAT_1008d484 - DAT_1008d474) * _DAT_1008d46c;
      if ((iVar3 == iVar1) || (iVar4 == 1)) {
        DAT_1008d2e8 = iVar3 - iVar1;
      }
      else if (iVar4 == 2) {
        DAT_1008d2e8 = iVar3 - iVar1 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar3 - iVar1) / iVar4;
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
      DAT_1008d2ec = iVar7 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && (iVar7 = DAT_1008d288 - DAT_1008d28c >> 6, iVar7 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / iVar7 << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar4 < iVar6) {
        local_18 = iVar6 - iVar4;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar1;
        DAT_1008d290 = iVar4;
        _DAT_1008d458 = DAT_1008d330;
        _DAT_1008d460 = DAT_1008d470;
        _DAT_1008d468 = DAT_1008d474;
        FUN_100546e0(&DAT_1008d280);
        _DAT_1008d454 = _DAT_10086134 / (float)local_18;
        _DAT_1008d448 = DAT_1008d478;
        _DAT_1008d440 = DAT_1008d334;
        _DAT_1008d450 = DAT_1008d47c;
        _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d454;
        _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d454;
        _DAT_1008d454 = _DAT_1008d454 * (DAT_1008d484 - DAT_1008d47c);
        DAT_1008d280 = iVar8 << 0x10;
        iVar5 = iVar5 - iVar8;
        if (local_18 == 1) {
          DAT_1008d28c = iVar5 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1008d28c = iVar5 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar10 + (iVar5 * 0x20 + local_18) * 4);
        }
        else if (iVar5 < 0) {
          DAT_1008d28c = (iVar5 * 0x10000) / local_18;
        }
        else {
          DAT_1008d28c = (iVar5 * 0x10000) / local_18;
        }
        if (iVar9 == iVar3) {
          DAT_1008d2e8 = iVar9 - iVar3;
        }
        else if (local_18 == 1) {
          DAT_1008d2e8 = iVar9 - iVar3;
        }
        else if (local_18 == 2) {
          DAT_1008d2e8 = iVar9 - iVar3 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar9 - iVar3) / local_18;
        }
      }
      else {
        local_18 = iVar4 - iVar6;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar1;
        DAT_1008d290 = iVar6;
        _DAT_1008d458 = DAT_1008d330;
        _DAT_1008d460 = DAT_1008d470;
        _DAT_1008d468 = DAT_1008d474;
        FUN_100546e0(&DAT_1008d280);
        if (local_18 == 0) {
          return;
        }
        _DAT_1008d46c = _DAT_10086134 / (float)local_18;
        _DAT_1008d458 = DAT_1008d338;
        _DAT_1008d460 = DAT_1008d480;
        _DAT_1008d468 = DAT_1008d484;
        _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * _DAT_1008d46c;
        _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * _DAT_1008d46c;
        _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d47c - DAT_1008d484);
        DAT_1008d284 = iVar5 << 0x10;
        iVar8 = iVar8 - iVar5;
        if (local_18 == 1) {
          DAT_1008d288 = iVar8 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1008d288 = iVar8 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar10 + (iVar8 * 0x20 + local_18) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1008d288 = (iVar8 * 0x10000) / local_18;
        }
        else {
          DAT_1008d288 = (iVar8 * 0x10000) / local_18;
        }
      }
      goto LAB_100558df;
    }
    iVar6 = iVar5 - DAT_1008d280;
    if (iVar6 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar8 = iVar8 - iVar5;
    if (iVar4 == 1) {
      DAT_1008d288 = iVar8 * 0x10000;
    }
    else if (iVar4 == 2) {
      DAT_1008d288 = iVar8 * 0x8000;
    }
    else if (((iVar4 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar10 + (iVar8 * 0x20 + iVar4) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1008d288 = (iVar8 * 0x10000) / iVar4;
    }
    else {
      DAT_1008d288 = (iVar8 * 0x10000) / iVar4;
    }
    _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * fVar2;
    _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * fVar2;
    _DAT_1008d46c = (DAT_1008d47c - DAT_1008d484) * fVar2;
    if ((iVar9 == iVar1) || (iVar6 == 1)) {
      DAT_1008d2ec = iVar9 - iVar1;
    }
    else if (iVar6 == 2) {
      DAT_1008d2ec = iVar9 - iVar1 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar9 - iVar1) / iVar6;
    }
    _DAT_1008d458 = DAT_1008d338;
    _DAT_1008d460 = DAT_1008d480;
    _DAT_1008d468 = DAT_1008d484;
    local_18 = iVar4;
    iVar8 = DAT_1008d280;
    if ((iVar3 == iVar1) || (iVar4 == 1)) {
      DAT_1008d2e8 = iVar3 - iVar1;
    }
    else if (iVar4 == 2) {
      DAT_1008d2e8 = iVar3 - iVar1 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar3 - iVar1) / iVar4;
    }
  }
  DAT_1008d284 = iVar5 << 0x10;
  DAT_1008d280 = iVar8 << 0x10;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar1;
LAB_100558df:
  DAT_1008d290 = local_18;
  FUN_100546e0(&DAT_1008d280);
  return;
}


