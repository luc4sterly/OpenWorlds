// 1004f450 FUN_1004f450 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1004f450(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iStack_18;
  
  iVar4 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar4 = param_2;
      param_2 = param_4;
      param_4 = param_3;
    }
LAB_1004f497:
    param_3 = param_2;
    param_2 = param_4;
    param_4 = iVar4;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1004f497;
  DAT_1007b284 = (int)*(short *)(param_2 + 0x1e);
  iVar5 = *(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  iVar4 = *(int *)(param_2 + 0x20);
  iVar1 = *(int *)(param_4 + 0x20);
  DAT_1007b330 = *(float *)(param_4 + 0x14) * *(float *)(param_3 + 0x14);
  iVar11 = (int)*(short *)(param_3 + 0x1a);
  iVar6 = (int)*(short *)(param_4 + 0x1a);
  iVar2 = *(int *)(param_3 + 0x20);
  DAT_1007b334 = *(float *)(param_4 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007b338 = *(float *)(param_3 + 0x14) * *(float *)(param_2 + 0x14);
  DAT_1007b470 = (float)*(int *)(param_2 + 100) * _DAT_10074110 * DAT_1007b330;
  DAT_1007b474 = (float)*(int *)(param_2 + 0x68) * _DAT_10074110 * DAT_1007b330;
  DAT_1007b478 = (float)*(int *)(param_3 + 100) * _DAT_10074110 * DAT_1007b334;
  DAT_1007b47c = (float)*(int *)(param_3 + 0x68) * _DAT_10074110 * DAT_1007b334;
  DAT_1007b480 = (float)*(int *)(param_4 + 100) * _DAT_10074110 * DAT_1007b338;
  DAT_1007b484 = (float)*(int *)(param_4 + 0x68) * _DAT_10074110 * DAT_1007b338;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2a0 = DAT_10077eb0;
  iVar10 = DAT_10075214 + 0x1000;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  if (iVar5 < 1) {
    iVar5 = DAT_1007b280 - iVar11;
    if (iVar5 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iStack_18 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (iStack_18 == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    _DAT_1007b46c = _DAT_10074114 / (float)iStack_18;
    _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b46c;
    _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b46c;
    _DAT_1007b454 = (DAT_1007b484 - DAT_1007b47c) * _DAT_1007b46c;
    _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
    _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
    _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b484 - DAT_1007b474);
    iVar7 = iVar6 - iVar11;
    if (iStack_18 == 1) {
      DAT_1007b28c = iVar7 * 0x10000;
    }
    else if (iStack_18 == 2) {
      DAT_1007b28c = iVar7 * 0x8000;
    }
    else if (((iStack_18 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar10 + (iVar7 * 0x20 + iStack_18) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1007b28c = (iVar7 * 0x10000) / iStack_18;
    }
    else {
      DAT_1007b28c = (iVar7 * 0x10000) / iStack_18;
    }
    iVar6 = iVar6 - DAT_1007b280;
    if (iStack_18 == 1) {
      DAT_1007b288 = iVar6 * 0x10000;
    }
    else if (iStack_18 == 2) {
      DAT_1007b288 = iVar6 * 0x8000;
    }
    else if (((iStack_18 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar10 + (iVar6 * 0x20 + iStack_18) * 4);
    }
    else if (iVar6 < 0) {
      DAT_1007b288 = (iVar6 * 0x10000) / iStack_18;
    }
    else {
      DAT_1007b288 = (iVar6 * 0x10000) / iStack_18;
    }
    _DAT_1007b440 = DAT_1007b334;
    _DAT_1007b448 = DAT_1007b478;
    _DAT_1007b450 = DAT_1007b47c;
    iVar6 = DAT_1007b280;
    if (DAT_1007b43c == 0) {
      if ((iVar2 == iVar4) || (iVar5 == 1)) {
        DAT_1007b2ec = iVar4 - iVar2;
      }
      else if (iVar5 == 2) {
        DAT_1007b2ec = iVar4 - iVar2 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar4 - iVar2) / iVar5;
      }
      DAT_1007b2e4 = iVar2;
      if ((iVar1 == iVar2) || (iStack_18 == 1)) {
        DAT_1007b2e8 = iVar1 - iVar2;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
      }
      else if (iStack_18 == 2) {
        DAT_1007b2e8 = iVar1 - iVar2 >> 1;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
      }
      else {
        DAT_1007b2e8 = (iVar1 - iVar2) / iStack_18;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
      }
    }
    else {
      if ((iVar2 == iVar4) || (iVar5 == 1)) {
        DAT_1007b2ec = iVar2 - iVar4;
      }
      else if (iVar5 == 2) {
        DAT_1007b2ec = iVar2 - iVar4 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar2 - iVar4) / iVar5;
      }
      if (iVar1 == iVar4) {
        DAT_1007b2e8 = iVar1 - iVar4;
        DAT_1007b2e4 = iVar4;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
      }
      else if (iStack_18 == 1) {
        DAT_1007b2e8 = iVar1 - iVar4;
        DAT_1007b2e4 = iVar4;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
      }
      else if (iStack_18 == 2) {
        DAT_1007b2e8 = iVar1 - iVar4 >> 1;
        DAT_1007b2e4 = iVar4;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
      }
      else {
        DAT_1007b2e8 = (iVar1 - iVar4) / iStack_18;
        DAT_1007b2e4 = iVar4;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
      }
    }
  }
  else {
    iVar7 = iVar11 - DAT_1007b280;
    if (iVar5 == 1) {
      DAT_1007b28c = iVar7 * 0x10000;
    }
    else if (iVar5 == 2) {
      DAT_1007b28c = iVar7 * 0x8000;
    }
    else if (((iVar5 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar10 + (iVar7 * 0x20 + iVar5) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1007b28c = (iVar7 * 0x10000) / iVar5;
    }
    else {
      DAT_1007b28c = (iVar7 * 0x10000) / iVar5;
    }
    fVar3 = _DAT_10074114 / (float)iVar5;
    _DAT_1007b444 = (DAT_1007b334 - DAT_1007b330) * fVar3;
    _DAT_1007b44c = (DAT_1007b478 - DAT_1007b470) * fVar3;
    _DAT_1007b454 = (DAT_1007b47c - DAT_1007b474) * fVar3;
    iVar7 = *(short *)(param_4 + 0x1e) - DAT_1007b284;
    _DAT_1007b440 = DAT_1007b330;
    _DAT_1007b448 = DAT_1007b470;
    _DAT_1007b450 = DAT_1007b474;
    if (0 < iVar7) {
      iVar8 = iVar6 - DAT_1007b280;
      if (iVar7 == 1) {
        DAT_1007b288 = iVar8 * 0x10000;
      }
      else if (iVar7 == 2) {
        DAT_1007b288 = iVar8 * 0x8000;
      }
      else if (((iVar7 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar10 + (iVar8 * 0x20 + iVar7) * 4);
      }
      else if (iVar8 < 0) {
        DAT_1007b288 = (iVar8 * 0x10000) / iVar7;
      }
      else {
        DAT_1007b288 = (iVar8 * 0x10000) / iVar7;
      }
      if (DAT_1007b288 - DAT_1007b28c < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        return;
      }
      _DAT_1007b46c = _DAT_10074114 / (float)iVar7;
      _DAT_1007b45c = (DAT_1007b338 - DAT_1007b330) * _DAT_1007b46c;
      _DAT_1007b464 = (DAT_1007b480 - DAT_1007b470) * _DAT_1007b46c;
      _DAT_1007b46c = (DAT_1007b484 - DAT_1007b474) * _DAT_1007b46c;
      iVar8 = DAT_1007b288 - DAT_1007b28c >> 6;
      if (DAT_1007b43c == 0) {
        if ((iVar2 == iVar4) || (iVar5 == 1)) {
          DAT_1007b2e8 = iVar2 - iVar4;
        }
        else if (iVar5 == 2) {
          DAT_1007b2e8 = iVar2 - iVar4 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar2 - iVar4) / iVar5;
        }
        if ((iVar1 == iVar4) || (iVar7 == 1)) {
          iVar9 = iVar1 - iVar4;
        }
        else if (iVar7 == 2) {
          iVar9 = iVar1 - iVar4 >> 1;
        }
        else {
          iVar9 = (iVar1 - iVar4) / iVar7;
        }
        DAT_1007b2ec = iVar9 - DAT_1007b2e8;
      }
      else {
        if ((iVar1 == iVar4) || (iVar7 == 1)) {
          DAT_1007b2e8 = iVar1 - iVar4;
        }
        else if (iVar7 == 2) {
          DAT_1007b2e8 = iVar1 - iVar4 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar1 - iVar4) / iVar7;
        }
        if ((iVar2 == iVar4) || (iVar5 == 1)) {
          iVar9 = iVar2 - iVar4;
        }
        else if (iVar5 == 2) {
          iVar9 = iVar2 - iVar4 >> 1;
        }
        else {
          iVar9 = (iVar2 - iVar4) / iVar5;
        }
        DAT_1007b2ec = iVar9 - DAT_1007b2e8;
      }
      if ((DAT_1007b2ec != 0) && (iVar8 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / iVar8 << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar5 < iVar7) {
        iStack_18 = iVar7 - iVar5;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar4;
        DAT_1007b290 = iVar5;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
        FUN_1007171c();
        _DAT_1007b454 = _DAT_10074114 / (float)iStack_18;
        _DAT_1007b448 = DAT_1007b478;
        _DAT_1007b440 = DAT_1007b334;
        _DAT_1007b450 = DAT_1007b47c;
        _DAT_1007b444 = (DAT_1007b338 - DAT_1007b334) * _DAT_1007b454;
        _DAT_1007b44c = (DAT_1007b480 - DAT_1007b478) * _DAT_1007b454;
        _DAT_1007b454 = _DAT_1007b454 * (DAT_1007b484 - DAT_1007b47c);
        DAT_1007b280 = iVar11 << 0x10;
        iVar6 = iVar6 - iVar11;
        if (iStack_18 == 1) {
          DAT_1007b28c = iVar6 * 0x10000;
        }
        else if (iStack_18 == 2) {
          DAT_1007b28c = iVar6 * 0x8000;
        }
        else if (((iStack_18 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar10 + (iVar6 * 0x20 + iStack_18) * 4);
        }
        else if (iVar6 < 0) {
          DAT_1007b28c = (iVar6 * 0x10000) / iStack_18;
        }
        else {
          DAT_1007b28c = (iVar6 * 0x10000) / iStack_18;
        }
        if (DAT_1007b43c == 0) {
          if (iVar1 == iVar2) {
            DAT_1007b2e8 = iVar1 - iVar2;
          }
          else if (iStack_18 == 1) {
            DAT_1007b2e8 = iVar1 - iVar2;
          }
          else if (iStack_18 == 2) {
            DAT_1007b2e8 = iVar1 - iVar2 >> 1;
          }
          else {
            DAT_1007b2e8 = (iVar1 - iVar2) / iStack_18;
          }
        }
      }
      else {
        iStack_18 = iVar5 - iVar7;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar4;
        DAT_1007b290 = iVar7;
        _DAT_1007b458 = DAT_1007b330;
        _DAT_1007b460 = DAT_1007b470;
        _DAT_1007b468 = DAT_1007b474;
        FUN_1007171c();
        if (iStack_18 == 0) {
          return;
        }
        _DAT_1007b46c = _DAT_10074114 / (float)iStack_18;
        _DAT_1007b458 = DAT_1007b338;
        _DAT_1007b460 = DAT_1007b480;
        _DAT_1007b468 = DAT_1007b484;
        _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * _DAT_1007b46c;
        _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * _DAT_1007b46c;
        _DAT_1007b46c = _DAT_1007b46c * (DAT_1007b47c - DAT_1007b484);
        DAT_1007b284 = iVar6 << 0x10;
        iVar11 = iVar11 - iVar6;
        if (iStack_18 == 1) {
          DAT_1007b288 = iVar11 * 0x10000;
        }
        else if (iStack_18 == 2) {
          DAT_1007b288 = iVar11 * 0x8000;
        }
        else if (((iStack_18 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar10 + (iVar11 * 0x20 + iStack_18) * 4);
        }
        else if (iVar11 < 0) {
          DAT_1007b288 = (iVar11 * 0x10000) / iStack_18;
        }
        else {
          DAT_1007b288 = (iVar11 * 0x10000) / iStack_18;
        }
        if (DAT_1007b43c != 0) {
          if (iVar1 == iVar2) {
            DAT_1007b2e8 = iVar2 - iVar1;
          }
          else if (iStack_18 == 1) {
            DAT_1007b2e8 = iVar2 - iVar1;
          }
          else if (iStack_18 == 2) {
            DAT_1007b2e8 = iVar2 - iVar1 >> 1;
          }
          else {
            DAT_1007b2e8 = (iVar2 - iVar1) / iStack_18;
          }
        }
      }
      goto LAB_100501e7;
    }
    iVar7 = iVar6 - DAT_1007b280;
    if (iVar7 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar11 = iVar11 - iVar6;
    if (iVar5 == 1) {
      DAT_1007b288 = iVar11 * 0x10000;
    }
    else if (iVar5 == 2) {
      DAT_1007b288 = iVar11 * 0x8000;
    }
    else if (((iVar5 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar10 + (iVar11 * 0x20 + iVar5) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1007b288 = (iVar11 * 0x10000) / iVar5;
    }
    else {
      DAT_1007b288 = (iVar11 * 0x10000) / iVar5;
    }
    _DAT_1007b45c = (DAT_1007b334 - DAT_1007b338) * fVar3;
    _DAT_1007b464 = (DAT_1007b478 - DAT_1007b480) * fVar3;
    _DAT_1007b46c = (DAT_1007b47c - DAT_1007b484) * fVar3;
    _DAT_1007b458 = DAT_1007b338;
    _DAT_1007b460 = DAT_1007b480;
    _DAT_1007b468 = DAT_1007b484;
    iStack_18 = iVar5;
    iVar11 = DAT_1007b280;
    if (DAT_1007b43c == 0) {
      if ((iVar1 == iVar4) || (iVar7 == 1)) {
        DAT_1007b2ec = iVar1 - iVar4;
      }
      else if (iVar7 == 2) {
        DAT_1007b2ec = iVar1 - iVar4 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar1 - iVar4) / iVar7;
      }
      if ((iVar2 == iVar4) || (iVar5 == 1)) {
        DAT_1007b2e8 = iVar2 - iVar4;
        DAT_1007b2e4 = iVar4;
      }
      else if (iVar5 == 2) {
        DAT_1007b2e8 = iVar2 - iVar4 >> 1;
        DAT_1007b2e4 = iVar4;
      }
      else {
        DAT_1007b2e8 = (iVar2 - iVar4) / iVar5;
        DAT_1007b2e4 = iVar4;
      }
    }
    else {
      if ((iVar1 == iVar4) || (iVar7 == 1)) {
        DAT_1007b2ec = iVar4 - iVar1;
      }
      else if (iVar7 == 2) {
        DAT_1007b2ec = iVar4 - iVar1 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar4 - iVar1) / iVar7;
      }
      DAT_1007b2e4 = iVar1;
      if (iVar1 == iVar2) {
        DAT_1007b2e8 = iVar2 - iVar1;
      }
      else if (iVar5 == 1) {
        DAT_1007b2e8 = iVar2 - iVar1;
      }
      else if (iVar5 == 2) {
        DAT_1007b2e8 = iVar2 - iVar1 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar2 - iVar1) / iVar5;
      }
    }
  }
  DAT_1007b284 = iVar6 << 0x10;
  DAT_1007b280 = iVar11 << 0x10;
  DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2f0;
LAB_100501e7:
  DAT_1007b290 = iStack_18;
  FUN_1007171c();
  return;
}


