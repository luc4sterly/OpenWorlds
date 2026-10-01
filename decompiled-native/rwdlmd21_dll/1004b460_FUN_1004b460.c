// 1004b460 FUN_1004b460 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1004b460(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  byte bVar4;
  undefined3 extraout_var;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iStack_14;
  
  iVar7 = param_4;
  iVar9 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    iVar5 = param_3;
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar5 = param_2;
      iVar7 = param_3;
      iVar9 = param_4;
    }
  }
  else {
    iVar5 = param_3;
    if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1004b4a9;
  }
  param_4 = iVar5;
  param_2 = iVar7;
  param_3 = iVar9;
LAB_1004b4a9:
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iStack_14 = (int)sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  iVar7 = (int)*(short *)(param_3 + 0x1a);
  iVar9 = (int)*(short *)(param_4 + 0x1a);
  DAT_1008d30c = *(int *)(param_2 + 100) >> 3;
  DAT_1008d310 = *(int *)(param_2 + 0x68) >> 3;
  DAT_1008d314 = *(int *)(param_3 + 100) >> 3;
  DAT_1008d318 = *(int *)(param_3 + 0x68) >> 3;
  DAT_1008d320 = *(int *)(param_4 + 0x68) >> 3;
  DAT_1008d31c = *(int *)(param_4 + 100) >> 3;
  _DAT_1008d324 = *(float *)(param_2 + 0x14);
  _DAT_1008d328 = *(float *)(param_3 + 0x14);
  _DAT_1008d32c = *(float *)(param_4 + 0x14);
  DAT_1008d330 = _DAT_1008d32c * _DAT_1008d328;
  DAT_1008d334 = _DAT_1008d32c * _DAT_1008d324;
  DAT_1008d338 = _DAT_1008d324 * _DAT_1008d328;
  fVar8 = DAT_1008d334;
  if ((int)DAT_1008d334 < (int)DAT_1008d330) {
    fVar8 = DAT_1008d330;
  }
  if ((int)fVar8 <= (int)DAT_1008d338) {
    fVar8 = DAT_1008d338;
  }
  DAT_1008d33c = (int)fVar8 >> 0x17;
  DAT_1008d300 = ((int)((uint)DAT_1008d330 & 0x7fffff | 0x800000) >>
                 ((char)DAT_1008d33c - (char)((int)DAT_1008d330 >> 0x17) & 0x1fU)) << 7;
  DAT_1008d304 = ((int)((uint)DAT_1008d334 & 0x7fffff | 0x800000) >>
                 ((char)DAT_1008d33c - (char)((int)DAT_1008d334 >> 0x17) & 0x1fU)) << 7;
  _DAT_1008d340 = DAT_1008d33c - ((int)DAT_1008d338 >> 0x17);
  DAT_1008d308 = ((int)((uint)DAT_1008d338 & 0x7fffff | 0x800000) >> ((byte)_DAT_1008d340 & 0x1f))
                 << 7;
  if ((short)(DAT_1008d300 >> 0x10) == 0) {
    DAT_1008d300 = 0x10000;
  }
  if ((short)(DAT_1008d304 >> 0x10) == 0) {
    DAT_1008d304 = 0x10000;
  }
  if ((short)(DAT_1008d308 >> 0x10) == 0) {
    DAT_1008d308 = 0x10000;
  }
  bVar3 = FUN_10006240(param_2,param_3,param_4);
  DAT_1008d43c = (uint)(CONCAT31(extraout_var,bVar3) == 0);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248 + 0x800;
  iVar11 = DAT_1008723c + 0x1000;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  iVar5 = DAT_10087250;
  if (DAT_1008d43c != 0) {
    iVar5 = DAT_10087258;
  }
  _DAT_1008d2a4 = *(undefined4 *)(iVar5 + (DAT_1008d284 & 7) * 4);
  if (iStack_14 < 1) {
    if (DAT_1008d280 == iVar7 || DAT_1008d280 - iVar7 < 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iStack_14 = -((int)sVar1 - (int)sVar2);
    if (iStack_14 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    DAT_1008d3ac = DAT_1008d304;
    iVar5 = iStack_14 >> 1;
    iVar6 = iVar5;
    if ((int)(DAT_1008d308 - DAT_1008d304) < 0) {
      iVar6 = -iVar5;
    }
    DAT_1008d3b0 = (int)((DAT_1008d308 - DAT_1008d304) + iVar6) / iStack_14;
    _DAT_1008d3b4 =
         (char)(&DAT_1008d7d0)
               [(int)(DAT_1008d320 | DAT_1008d314 | DAT_1008d318 | DAT_1008d31c) >> 0x10] + 1;
    uVar10 = DAT_1008d308 >> 0x10;
    bVar4 = (byte)_DAT_1008d3b4;
    DAT_1008d38c = ((int)DAT_1008d314 >> (bVar4 & 0x1f)) * (DAT_1008d304 >> 0x10);
    DAT_1008d390 = (int)(((int)DAT_1008d31c >> (bVar4 & 0x1f)) * uVar10 - DAT_1008d38c) / iStack_14;
    DAT_1008d394 = ((int)DAT_1008d318 >> (bVar4 & 0x1f)) * (DAT_1008d304 >> 0x10);
    DAT_1008d398 = (int)(((int)DAT_1008d320 >> (bVar4 & 0x1f)) * uVar10 - DAT_1008d394) / iStack_14;
    DAT_1008d3c0 = DAT_1008d300;
    if ((int)(DAT_1008d308 - DAT_1008d300) < 0) {
      iVar5 = -iVar5;
    }
    DAT_1008d3c4 = (int)((DAT_1008d308 - DAT_1008d300) + iVar5) / iStack_14;
    _DAT_1008d3c8 =
         (char)(&DAT_1008d7d0)
               [(int)(DAT_1008d320 | DAT_1008d310 | DAT_1008d31c | DAT_1008d30c) >> 0x10] + 1;
    bVar4 = (byte)_DAT_1008d3c8;
    DAT_1008d39c = ((int)DAT_1008d30c >> (bVar4 & 0x1f)) * (DAT_1008d300 >> 0x10);
    DAT_1008d3a0 = (int)(((int)DAT_1008d31c >> (bVar4 & 0x1f)) * uVar10 - DAT_1008d39c) / iStack_14;
    DAT_1008d3a4 = ((int)DAT_1008d310 >> (bVar4 & 0x1f)) * (DAT_1008d300 >> 0x10);
    DAT_1008d3a8 = (int)(((int)DAT_1008d320 >> (bVar4 & 0x1f)) * uVar10 - DAT_1008d3a4) / iStack_14;
    iVar5 = iVar9 - iVar7;
    if (iStack_14 == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (iStack_14 == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((iStack_14 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar11 + (iVar5 * 0x20 + iStack_14) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / iStack_14;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / iStack_14;
    }
    iVar9 = iVar9 - DAT_1008d280;
    if (iStack_14 == 1) {
      DAT_1008d288 = iVar9 * 0x10000;
    }
    else if (iStack_14 == 2) {
      DAT_1008d288 = iVar9 * 0x8000;
    }
    else if (((iStack_14 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar11 + (iVar9 * 0x20 + iStack_14) * 4);
    }
    else if (iVar9 < 0) {
      DAT_1008d288 = (iVar9 * 0x10000) / iStack_14;
    }
    else {
      DAT_1008d288 = (iVar9 * 0x10000) / iStack_14;
    }
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d280 = iVar7 << 0x10;
  }
  else {
    iVar5 = iVar7 - DAT_1008d280;
    if (iStack_14 == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (iStack_14 == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((iStack_14 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar11 + (iVar5 * 0x20 + iStack_14) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / iStack_14;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / iStack_14;
    }
    DAT_1008d3ac = DAT_1008d300;
    iVar5 = iStack_14 >> 1;
    iVar6 = iVar5;
    if ((int)(DAT_1008d304 - DAT_1008d300) < 0) {
      iVar6 = -iVar5;
    }
    DAT_1008d3b0 = (int)((DAT_1008d304 - DAT_1008d300) + iVar6) / iStack_14;
    uVar10 = DAT_1008d300 >> 0x10;
    _DAT_1008d3b4 =
         (char)(&DAT_1008d7d0)
               [(int)(DAT_1008d310 | DAT_1008d314 | DAT_1008d318 | DAT_1008d30c) >> 0x10] + 1;
    bVar4 = (byte)_DAT_1008d3b4;
    uVar12 = DAT_1008d304 >> 0x10;
    DAT_1008d38c = ((int)DAT_1008d30c >> (bVar4 & 0x1f)) * uVar10;
    DAT_1008d390 = (int)(((int)DAT_1008d314 >> (bVar4 & 0x1f)) * uVar12 - DAT_1008d38c) / iStack_14;
    DAT_1008d394 = ((int)DAT_1008d310 >> (bVar4 & 0x1f)) * uVar10;
    DAT_1008d398 = (int)(((int)DAT_1008d318 >> (bVar4 & 0x1f)) * uVar12 - DAT_1008d394) / iStack_14;
    iVar6 = (int)sVar2 - DAT_1008d284;
    if (iVar6 < 1) {
      if (iVar9 == DAT_1008d280 || iVar9 - DAT_1008d280 < 0) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d3ac = DAT_1008d300;
        return;
      }
      iVar7 = iVar7 - iVar9;
      if (iStack_14 == 1) {
        DAT_1008d288 = iVar7 * 0x10000;
      }
      else if (iStack_14 == 2) {
        DAT_1008d288 = iVar7 * 0x8000;
      }
      else if (((iStack_14 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar11 + (iVar7 * 0x20 + iStack_14) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1008d288 = (iVar7 * 0x10000) / iStack_14;
      }
      else {
        DAT_1008d288 = (iVar7 * 0x10000) / iStack_14;
      }
      DAT_1008d3c0 = DAT_1008d308;
      if ((int)(DAT_1008d304 - DAT_1008d308) < 0) {
        iVar5 = -iVar5;
      }
      DAT_1008d3c4 = (int)((DAT_1008d304 - DAT_1008d308) + iVar5) / iStack_14;
      _DAT_1008d3c8 =
           (char)(&DAT_1008d7d0)
                 [(int)(DAT_1008d320 | DAT_1008d314 | DAT_1008d318 | DAT_1008d31c) >> 0x10] + 1;
      bVar4 = (byte)_DAT_1008d3c8;
      DAT_1008d39c = ((int)DAT_1008d31c >> (bVar4 & 0x1f)) * (DAT_1008d308 >> 0x10);
      DAT_1008d3a0 = (int)(((int)DAT_1008d314 >> (bVar4 & 0x1f)) * uVar12 - DAT_1008d39c) /
                     iStack_14;
      DAT_1008d3a4 = ((int)DAT_1008d320 >> (bVar4 & 0x1f)) * (DAT_1008d308 >> 0x10);
      DAT_1008d3a8 = (int)(((int)DAT_1008d318 >> (bVar4 & 0x1f)) * uVar12 - DAT_1008d3a4) /
                     iStack_14;
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = iVar9 << 0x10;
    }
    else {
      iVar5 = iVar9 - DAT_1008d280;
      if (iVar6 == 1) {
        DAT_1008d288 = iVar5 * 0x10000;
      }
      else if (iVar6 == 2) {
        DAT_1008d288 = iVar5 * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar11 + (iVar5 * 0x20 + iVar6) * 4);
      }
      else if (iVar5 < 0) {
        DAT_1008d288 = (iVar5 * 0x10000) / iVar6;
      }
      else {
        DAT_1008d288 = (iVar5 * 0x10000) / iVar6;
      }
      if (DAT_1008d288 == DAT_1008d28c || DAT_1008d288 - DAT_1008d28c < 0) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d3ac = DAT_1008d300;
        return;
      }
      DAT_1008d3c0 = DAT_1008d300;
      iVar5 = iVar6 >> 1;
      if ((int)(DAT_1008d308 - DAT_1008d300) < 0) {
        iVar5 = -iVar5;
      }
      DAT_1008d3c4 = (int)(iVar5 + (DAT_1008d308 - DAT_1008d300)) / iVar6;
      _DAT_1008d3c8 =
           (char)(&DAT_1008d7d0)
                 [(int)(DAT_1008d320 | DAT_1008d310 | DAT_1008d31c | DAT_1008d30c) >> 0x10] + 1;
      bVar4 = (byte)_DAT_1008d3c8;
      DAT_1008d39c = ((int)DAT_1008d30c >> (bVar4 & 0x1f)) * uVar10;
      DAT_1008d3a0 = (int)(((int)DAT_1008d31c >> (bVar4 & 0x1f)) * (DAT_1008d308 >> 0x10) -
                          DAT_1008d39c) / iVar6;
      DAT_1008d3a4 = ((int)DAT_1008d310 >> (bVar4 & 0x1f)) * uVar10;
      DAT_1008d3a8 = (int)(((int)DAT_1008d320 >> (bVar4 & 0x1f)) * (DAT_1008d308 >> 0x10) -
                          DAT_1008d3a4) / iVar6;
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iStack_14 < iVar6) {
        iVar6 = iVar6 - iStack_14;
        DAT_1008d290 = iStack_14;
        FUN_1004c270((uint *)&DAT_1008d280);
        DAT_1008d3ac = DAT_1008d304;
        iVar5 = iVar6 >> 1;
        if ((int)(DAT_1008d308 - DAT_1008d304) < 0) {
          iVar5 = -iVar5;
        }
        DAT_1008d3b0 = (int)(iVar5 + (DAT_1008d308 - DAT_1008d304)) / iVar6;
        _DAT_1008d3b4 =
             (char)(&DAT_1008d7d0)
                   [(int)(DAT_1008d320 | DAT_1008d314 | DAT_1008d318 | DAT_1008d31c) >> 0x10] + 1;
        bVar4 = (byte)_DAT_1008d3b4;
        DAT_1008d38c = ((int)DAT_1008d314 >> (bVar4 & 0x1f)) * (DAT_1008d304 >> 0x10);
        DAT_1008d390 = (int)(((int)DAT_1008d31c >> (bVar4 & 0x1f)) * (DAT_1008d308 >> 0x10) -
                            DAT_1008d38c) / iVar6;
        DAT_1008d394 = ((int)DAT_1008d318 >> (bVar4 & 0x1f)) * (DAT_1008d304 >> 0x10);
        DAT_1008d398 = (int)(((int)DAT_1008d320 >> (bVar4 & 0x1f)) * (DAT_1008d308 >> 0x10) -
                            DAT_1008d394) / iVar6;
        DAT_1008d280 = iVar7 << 0x10;
        iVar9 = iVar9 - iVar7;
        iStack_14 = iVar6;
        if (iVar6 == 1) {
          DAT_1008d28c = iVar9 * 0x10000;
        }
        else if (iVar6 == 2) {
          DAT_1008d28c = iVar9 * 0x8000;
        }
        else if (((iVar6 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar11 + (iVar9 * 0x20 + iVar6) * 4);
        }
        else if (iVar9 < 0) {
          DAT_1008d28c = (iVar9 * 0x10000) / iVar6;
        }
        else {
          DAT_1008d28c = (iVar9 * 0x10000) / iVar6;
        }
      }
      else {
        iStack_14 = iStack_14 - iVar6;
        DAT_1008d290 = iVar6;
        FUN_1004c270((uint *)&DAT_1008d280);
        if (iStack_14 == 0) {
          return;
        }
        DAT_1008d3c0 = DAT_1008d308;
        iVar5 = iStack_14 >> 1;
        if ((int)(DAT_1008d304 - DAT_1008d308) < 0) {
          iVar5 = -iVar5;
        }
        DAT_1008d3c4 = (int)(iVar5 + (DAT_1008d304 - DAT_1008d308)) / iStack_14;
        _DAT_1008d3c8 =
             (char)(&DAT_1008d7d0)
                   [(int)(DAT_1008d320 | DAT_1008d314 | DAT_1008d318 | DAT_1008d31c) >> 0x10] + 1;
        bVar4 = (byte)_DAT_1008d3c8;
        DAT_1008d39c = ((int)DAT_1008d31c >> (bVar4 & 0x1f)) * (DAT_1008d308 >> 0x10);
        DAT_1008d3a0 = (int)(((int)DAT_1008d314 >> (bVar4 & 0x1f)) * (DAT_1008d304 >> 0x10) -
                            DAT_1008d39c) / iStack_14;
        DAT_1008d3a4 = ((int)DAT_1008d320 >> (bVar4 & 0x1f)) * (DAT_1008d308 >> 0x10);
        DAT_1008d3a8 = (int)(((int)DAT_1008d318 >> (bVar4 & 0x1f)) * (DAT_1008d304 >> 0x10) -
                            DAT_1008d3a4) / iStack_14;
        DAT_1008d284 = iVar9 << 0x10;
        iVar7 = iVar7 - iVar9;
        if (iStack_14 == 1) {
          DAT_1008d288 = iVar7 * 0x10000;
        }
        else if (iStack_14 == 2) {
          DAT_1008d288 = iVar7 * 0x8000;
        }
        else if (((iStack_14 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar11 + (iVar7 * 0x20 + iStack_14) * 4);
        }
        else if (iVar7 < 0) {
          DAT_1008d288 = (iVar7 * 0x10000) / iStack_14;
        }
        else {
          DAT_1008d288 = (iVar7 * 0x10000) / iStack_14;
        }
      }
    }
  }
  DAT_1008d290 = iStack_14;
  FUN_1004c270((uint *)&DAT_1008d280);
  return;
}


