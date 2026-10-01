// 1002f860 FUN_1002f860 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002f860(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  longlong lVar16;
  int iStack_1c;
  
  iVar6 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar6 = param_2;
      param_2 = param_4;
      param_4 = param_3;
    }
LAB_1002f8a7:
    param_3 = param_2;
    param_2 = param_4;
    param_4 = iVar6;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1002f8a7;
  DAT_1008d284 = (int)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar7 = sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  iVar3 = *(int *)(param_2 + 0x20);
  iVar6 = *(int *)(param_3 + 0x20);
  DAT_1008d330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar14 = (int)*(short *)(param_3 + 0x1a);
  iVar8 = (int)*(short *)(param_4 + 0x1a);
  iVar4 = *(int *)(param_4 + 0x20);
  DAT_1008d334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1008d470 = (float)*(int *)(param_2 + 100) * _DAT_10086110 * DAT_1008d330;
  DAT_1008d474 = (float)*(int *)(param_2 + 0x68) * _DAT_10086110 * DAT_1008d330;
  DAT_1008d478 = (float)*(int *)(param_3 + 100) * _DAT_10086110 * DAT_1008d334;
  DAT_1008d47c = (float)*(int *)(param_3 + 0x68) * _DAT_10086110 * DAT_1008d334;
  DAT_1008d480 = (float)*(int *)(param_4 + 100) * _DAT_10086110 * DAT_1008d338;
  DAT_1008d484 = (float)*(int *)(param_4 + 0x68) * _DAT_10086110 * DAT_1008d338;
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  if ((DAT_1008a100 == 0) || (*(float *)(param_1[0xf] + 0x14) <= _DAT_10089dd0)) {
    DAT_1008dbe0._4_4_ = 0;
  }
  else {
    lVar16 = __ftol();
    iVar9 = (int)lVar16;
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    iVar9 = 0x10000 - iVar9;
    uVar12 = DAT_10089ef8 * iVar9;
    uVar15 = DAT_10089ef0 * iVar9;
    uVar13 = iVar9 * DAT_10089de4;
    if (0x1e0000 < (int)(param_1[1] + uVar12)) {
      uVar12 = 0x1e0000 - param_1[1];
    }
    if (0x1e0000 < (int)(param_1[2] + uVar15)) {
      uVar15 = 0x1e0000 - param_1[2];
    }
    if (0x1e0000 < (int)(param_1[3] + uVar13)) {
      uVar13 = 0x1e0000 - param_1[3];
    }
    if ((int)uVar12 < 0) {
      uVar12 = 0;
    }
    if ((int)uVar15 < 0) {
      uVar15 = 0;
    }
    if ((int)uVar13 < 0) {
      uVar13 = 0;
    }
    uVar12 = (int)((uVar15 & 0x1f8000) >> 5 | uVar12 & 0x1f0000) >> 5 | (uVar13 & 0x1f0000) >> 0x10;
    DAT_1008dbe0._4_4_ = uVar12 | uVar12 << 0x10;
  }
  iVar9 = DAT_1008723c + 0x1000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  DAT_1008dbe0._0_4_ = DAT_1008dbe0._4_4_;
  if (iVar7 < 1) {
    iVar7 = DAT_1008d280 - iVar14;
    if (iVar7 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iStack_1c = -((int)sVar1 - (int)sVar2);
    if (iStack_1c == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    _DAT_1008d46c = _DAT_10086114 / (float)iStack_1c;
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
    iVar10 = iVar8 - iVar14;
    if (iStack_1c == 1) {
      DAT_1008d28c = iVar10 * 0x10000;
    }
    else if (iStack_1c == 2) {
      DAT_1008d28c = iVar10 * 0x8000;
    }
    else if (((iStack_1c < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar9 + (iVar10 * 0x20 + iStack_1c) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1008d28c = (iVar10 * 0x10000) / iStack_1c;
    }
    else {
      DAT_1008d28c = (iVar10 * 0x10000) / iStack_1c;
    }
    iVar8 = iVar8 - DAT_1008d280;
    if (iStack_1c == 1) {
      DAT_1008d288 = iVar8 * 0x10000;
    }
    else if (iStack_1c == 2) {
      DAT_1008d288 = iVar8 * 0x8000;
    }
    else if (((iStack_1c < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar9 + (iVar8 * 0x20 + iStack_1c) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1008d288 = (iVar8 * 0x10000) / iStack_1c;
    }
    else {
      DAT_1008d288 = (iVar8 * 0x10000) / iStack_1c;
    }
    if ((iVar3 == iVar6) || (iVar7 == 1)) {
      DAT_1008d2ec = iVar3 - iVar6;
    }
    else if (iVar7 == 2) {
      DAT_1008d2ec = iVar3 - iVar6 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar3 - iVar6) / iVar7;
    }
    iVar3 = iVar6;
    iVar8 = DAT_1008d280;
    if ((iVar4 == iVar6) || (iStack_1c == 1)) {
      DAT_1008d2e8 = iVar4 - iVar6;
    }
    else if (iStack_1c == 2) {
      DAT_1008d2e8 = iVar4 - iVar6 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar4 - iVar6) / iStack_1c;
    }
  }
  else {
    iVar10 = iVar14 - DAT_1008d280;
    if (iVar7 == 1) {
      DAT_1008d28c = iVar10 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1008d28c = iVar10 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar9 + (iVar10 * 0x20 + iVar7) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1008d28c = (iVar10 * 0x10000) / iVar7;
    }
    else {
      DAT_1008d28c = (iVar10 * 0x10000) / iVar7;
    }
    fVar5 = _DAT_10086114 / (float)iVar7;
    _DAT_1008d448 = DAT_1008d470;
    _DAT_1008d440 = DAT_1008d330;
    _DAT_1008d444 = (DAT_1008d334 - DAT_1008d330) * fVar5;
    _DAT_1008d44c = (DAT_1008d478 - DAT_1008d470) * fVar5;
    _DAT_1008d454 = (DAT_1008d47c - DAT_1008d474) * fVar5;
    _DAT_1008d450 = DAT_1008d474;
    iVar10 = sVar2 - DAT_1008d284;
    if (0 < iVar10) {
      iVar11 = iVar8 - DAT_1008d280;
      if (iVar10 == 1) {
        DAT_1008d288 = iVar11 * 0x10000;
      }
      else if (iVar10 == 2) {
        DAT_1008d288 = iVar11 * 0x8000;
      }
      else if (((iVar10 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar9 + (iVar11 * 0x20 + iVar10) * 4);
      }
      else if (iVar11 < 0) {
        DAT_1008d288 = (iVar11 * 0x10000) / iVar10;
      }
      else {
        DAT_1008d288 = (iVar11 * 0x10000) / iVar10;
      }
      if (DAT_1008d288 - DAT_1008d28c < 1) {
        DAT_1008d298 = DAT_10089ddc;
        _DAT_1008d440 = DAT_1008d330;
        return;
      }
      _DAT_1008d46c = _DAT_10086114 / (float)iVar10;
      _DAT_1008d460 = DAT_1008d470;
      _DAT_1008d458 = DAT_1008d330;
      _DAT_1008d468 = DAT_1008d474;
      _DAT_1008d45c = (DAT_1008d338 - DAT_1008d330) * _DAT_1008d46c;
      _DAT_1008d464 = (DAT_1008d480 - DAT_1008d470) * _DAT_1008d46c;
      _DAT_1008d46c = (DAT_1008d484 - DAT_1008d474) * _DAT_1008d46c;
      if ((iVar6 == iVar3) || (iVar7 == 1)) {
        DAT_1008d2e8 = iVar6 - iVar3;
      }
      else if (iVar7 == 2) {
        DAT_1008d2e8 = iVar6 - iVar3 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar6 - iVar3) / iVar7;
      }
      if ((iVar4 == iVar3) || (iVar10 == 1)) {
        iVar11 = iVar4 - iVar3;
      }
      else if (iVar10 == 2) {
        iVar11 = iVar4 - iVar3 >> 1;
      }
      else {
        iVar11 = (iVar4 - iVar3) / iVar10;
      }
      DAT_1008d2ec = iVar11 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && (iVar11 = DAT_1008d288 - DAT_1008d28c >> 6, iVar11 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / iVar11 << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar7 < iVar10) {
        iStack_1c = iVar10 - iVar7;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar3;
        DAT_1008d290 = iVar7;
        FUN_1007e548();
        _DAT_1008d454 = _DAT_10086114 / (float)iStack_1c;
        _DAT_1008d448 = DAT_1008d478;
        _DAT_1008d440 = DAT_1008d334;
        _DAT_1008d450 = DAT_1008d47c;
        _DAT_1008d444 = (DAT_1008d338 - DAT_1008d334) * _DAT_1008d454;
        _DAT_1008d44c = (DAT_1008d480 - DAT_1008d478) * _DAT_1008d454;
        _DAT_1008d454 = _DAT_1008d454 * (DAT_1008d484 - DAT_1008d47c);
        DAT_1008d280 = iVar14 << 0x10;
        iVar8 = iVar8 - iVar14;
        if (iStack_1c == 1) {
          DAT_1008d28c = iVar8 * 0x10000;
        }
        else if (iStack_1c == 2) {
          DAT_1008d28c = iVar8 * 0x8000;
        }
        else if (((iStack_1c < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar9 + (iVar8 * 0x20 + iStack_1c) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1008d28c = (iVar8 * 0x10000) / iStack_1c;
        }
        else {
          DAT_1008d28c = (iVar8 * 0x10000) / iStack_1c;
        }
        if (iVar4 == iVar6) {
          DAT_1008d2e8 = iVar4 - iVar6;
        }
        else if (iStack_1c == 1) {
          DAT_1008d2e8 = iVar4 - iVar6;
        }
        else if (iStack_1c == 2) {
          DAT_1008d2e8 = iVar4 - iVar6 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar4 - iVar6) / iStack_1c;
        }
      }
      else {
        iStack_1c = iVar7 - iVar10;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar3;
        DAT_1008d290 = iVar10;
        FUN_1007e548();
        if (iStack_1c == 0) {
          return;
        }
        _DAT_1008d46c = _DAT_10086114 / (float)iStack_1c;
        _DAT_1008d458 = DAT_1008d338;
        _DAT_1008d460 = DAT_1008d480;
        _DAT_1008d468 = DAT_1008d484;
        _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * _DAT_1008d46c;
        _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * _DAT_1008d46c;
        _DAT_1008d46c = _DAT_1008d46c * (DAT_1008d47c - DAT_1008d484);
        DAT_1008d284 = iVar8 << 0x10;
        iVar14 = iVar14 - iVar8;
        if (iStack_1c == 1) {
          DAT_1008d288 = iVar14 * 0x10000;
        }
        else if (iStack_1c == 2) {
          DAT_1008d288 = iVar14 * 0x8000;
        }
        else if (((iStack_1c < 0x20) && (-0x20 < iVar14)) && (iVar14 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar9 + (iVar14 * 0x20 + iStack_1c) * 4);
        }
        else if (iVar14 < 0) {
          DAT_1008d288 = (iVar14 * 0x10000) / iStack_1c;
        }
        else {
          DAT_1008d288 = (iVar14 * 0x10000) / iStack_1c;
        }
      }
      goto LAB_10030538;
    }
    iVar10 = iVar8 - DAT_1008d280;
    if (iVar10 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      _DAT_1008d440 = DAT_1008d330;
      return;
    }
    iVar14 = iVar14 - iVar8;
    if (iVar7 == 1) {
      DAT_1008d288 = iVar14 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1008d288 = iVar14 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar14)) && (iVar14 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar9 + (iVar14 * 0x20 + iVar7) * 4);
    }
    else if (iVar14 < 0) {
      DAT_1008d288 = (iVar14 * 0x10000) / iVar7;
    }
    else {
      DAT_1008d288 = (iVar14 * 0x10000) / iVar7;
    }
    _DAT_1008d45c = (DAT_1008d334 - DAT_1008d338) * fVar5;
    _DAT_1008d464 = (DAT_1008d478 - DAT_1008d480) * fVar5;
    _DAT_1008d458 = DAT_1008d338;
    _DAT_1008d460 = DAT_1008d480;
    _DAT_1008d468 = DAT_1008d484;
    _DAT_1008d46c = (DAT_1008d47c - DAT_1008d484) * fVar5;
    if ((iVar4 == iVar3) || (iVar10 == 1)) {
      DAT_1008d2ec = iVar4 - iVar3;
    }
    else if (iVar10 == 2) {
      DAT_1008d2ec = iVar4 - iVar3 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar4 - iVar3) / iVar10;
    }
    iStack_1c = iVar7;
    iVar14 = DAT_1008d280;
    if ((iVar6 == iVar3) || (iVar7 == 1)) {
      DAT_1008d2e8 = iVar6 - iVar3;
    }
    else if (iVar7 == 2) {
      DAT_1008d2e8 = iVar6 - iVar3 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar6 - iVar3) / iVar7;
    }
  }
  DAT_1008d284 = iVar8 << 0x10;
  DAT_1008d280 = iVar14 << 0x10;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar3;
LAB_10030538:
  DAT_1008d290 = iStack_1c;
  FUN_1007e548();
  return;
}


