// 1001efd0 FUN_1001efd0 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001efd0(int *param_1,int param_2,int param_3,int param_4)

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
  int local_14;
  
  iVar7 = param_2;
  iVar9 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar7 = param_4;
      iVar9 = param_2;
      param_4 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1001f019;
  param_3 = iVar7;
  param_2 = param_4;
  param_4 = iVar9;
LAB_1001f019:
  DAT_1007f284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  local_14 = (int)sVar1 - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  iVar7 = (int)*(short *)(param_3 + 0x1a);
  iVar9 = (int)*(short *)(param_4 + 0x1a);
  DAT_1007f310 = *(uint *)(param_2 + 0x68);
  DAT_1007f30c = *(uint *)(param_2 + 100);
  DAT_1007f318 = *(uint *)(param_3 + 0x68);
  DAT_1007f314 = *(uint *)(param_3 + 100);
  DAT_1007f320 = *(uint *)(param_4 + 0x68);
  DAT_1007f31c = *(uint *)(param_4 + 100);
  _DAT_1007f324 = *(float *)(param_2 + 0x14);
  _DAT_1007f328 = *(float *)(param_3 + 0x14);
  _DAT_1007f32c = *(float *)(param_4 + 0x14);
  DAT_1007f330 = _DAT_1007f32c * _DAT_1007f328;
  DAT_1007f334 = _DAT_1007f32c * _DAT_1007f324;
  DAT_1007f338 = _DAT_1007f324 * _DAT_1007f328;
  fVar8 = DAT_1007f334;
  if ((int)DAT_1007f334 < (int)DAT_1007f330) {
    fVar8 = DAT_1007f330;
  }
  if ((int)fVar8 <= (int)DAT_1007f338) {
    fVar8 = DAT_1007f338;
  }
  DAT_1007f33c = (int)fVar8 >> 0x17;
  DAT_1007f300 = ((int)((uint)DAT_1007f330 & 0x7fffff | 0x800000) >>
                 ((char)DAT_1007f33c - (char)((int)DAT_1007f330 >> 0x17) & 0x1fU)) << 7;
  DAT_1007f304 = ((int)((uint)DAT_1007f334 & 0x7fffff | 0x800000) >>
                 ((char)DAT_1007f33c - (char)((int)DAT_1007f334 >> 0x17) & 0x1fU)) << 7;
  _DAT_1007f340 = DAT_1007f33c - ((int)DAT_1007f338 >> 0x17);
  DAT_1007f308 = ((int)((uint)DAT_1007f338 & 0x7fffff | 0x800000) >> ((byte)_DAT_1007f340 & 0x1f))
                 << 7;
  if ((short)(DAT_1007f300 >> 0x10) == 0) {
    DAT_1007f300 = 0x10000;
  }
  if ((short)(DAT_1007f304 >> 0x10) == 0) {
    DAT_1007f304 = 0x10000;
  }
  if ((short)(DAT_1007f308 >> 0x10) == 0) {
    DAT_1007f308 = 0x10000;
  }
  bVar3 = FUN_10005a70(param_2,param_3,param_4);
  DAT_1007f43c = (uint)(CONCAT31(extraout_var,bVar3) == 0);
  iVar11 = DAT_10079214 + 0x1000;
  DAT_1007f2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  iVar5 = DAT_10079228;
  if (DAT_1007f43c != 0) {
    iVar5 = DAT_10079230;
  }
  DAT_1007f2a4 = *(undefined4 *)(iVar5 + (DAT_1007f284 & 7) * 4);
  if (local_14 < 1) {
    if (DAT_1007f280 == iVar7 || DAT_1007f280 - iVar7 < 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    local_14 = -((int)sVar1 - (int)sVar2);
    if (local_14 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    DAT_1007f3ac = DAT_1007f304;
    iVar5 = local_14 >> 1;
    iVar6 = iVar5;
    if ((int)(DAT_1007f308 - DAT_1007f304) < 0) {
      iVar6 = -iVar5;
    }
    DAT_1007f3b0 = (int)((DAT_1007f308 - DAT_1007f304) + iVar6) / local_14;
    _DAT_1007f3b4 =
         (char)(&DAT_1007f7d0)
               [(int)(DAT_1007f320 | DAT_1007f314 | DAT_1007f318 | DAT_1007f31c) >> 0x10] + 1;
    bVar4 = (byte)_DAT_1007f3b4;
    uVar10 = DAT_1007f308 >> 0x10;
    DAT_1007f38c = ((int)DAT_1007f314 >> (bVar4 & 0x1f)) * (DAT_1007f304 >> 0x10);
    DAT_1007f390 = (int)(((int)DAT_1007f31c >> (bVar4 & 0x1f)) * uVar10 - DAT_1007f38c) / local_14;
    DAT_1007f394 = ((int)DAT_1007f318 >> (bVar4 & 0x1f)) * (DAT_1007f304 >> 0x10);
    DAT_1007f398 = (int)(((int)DAT_1007f320 >> (bVar4 & 0x1f)) * uVar10 - DAT_1007f394) / local_14;
    DAT_1007f3c0 = DAT_1007f300;
    if ((int)(DAT_1007f308 - DAT_1007f300) < 0) {
      iVar5 = -iVar5;
    }
    DAT_1007f3c4 = (int)((DAT_1007f308 - DAT_1007f300) + iVar5) / local_14;
    _DAT_1007f3c8 =
         (char)(&DAT_1007f7d0)
               [(int)(DAT_1007f320 | DAT_1007f310 | DAT_1007f31c | DAT_1007f30c) >> 0x10] + 1;
    bVar4 = (byte)_DAT_1007f3c8;
    DAT_1007f39c = ((int)DAT_1007f30c >> (bVar4 & 0x1f)) * (DAT_1007f300 >> 0x10);
    DAT_1007f3a0 = (int)(((int)DAT_1007f31c >> (bVar4 & 0x1f)) * uVar10 - DAT_1007f39c) / local_14;
    DAT_1007f3a4 = ((int)DAT_1007f310 >> (bVar4 & 0x1f)) * (DAT_1007f300 >> 0x10);
    DAT_1007f3a8 = (int)(((int)DAT_1007f320 >> (bVar4 & 0x1f)) * uVar10 - DAT_1007f3a4) / local_14;
    iVar5 = iVar9 - iVar7;
    if (local_14 == 1) {
      DAT_1007f28c = iVar5 * 0x10000;
    }
    else if (local_14 == 2) {
      DAT_1007f28c = iVar5 * 0x8000;
    }
    else if (((local_14 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar11 + (iVar5 * 0x20 + local_14) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007f28c = (iVar5 * 0x10000) / local_14;
    }
    else {
      DAT_1007f28c = (iVar5 * 0x10000) / local_14;
    }
    iVar9 = iVar9 - DAT_1007f280;
    if (local_14 == 1) {
      DAT_1007f288 = iVar9 * 0x10000;
    }
    else if (local_14 == 2) {
      DAT_1007f288 = iVar9 * 0x8000;
    }
    else if (((local_14 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar11 + (iVar9 * 0x20 + local_14) * 4);
    }
    else if (iVar9 < 0) {
      DAT_1007f288 = (iVar9 * 0x10000) / local_14;
    }
    else {
      DAT_1007f288 = (iVar9 * 0x10000) / local_14;
    }
    DAT_1007f284 = DAT_1007f280 << 0x10;
    DAT_1007f280 = iVar7 << 0x10;
  }
  else {
    iVar5 = iVar7 - DAT_1007f280;
    if (local_14 == 1) {
      DAT_1007f28c = iVar5 * 0x10000;
    }
    else if (local_14 == 2) {
      DAT_1007f28c = iVar5 * 0x8000;
    }
    else if (((local_14 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar11 + (iVar5 * 0x20 + local_14) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007f28c = (iVar5 * 0x10000) / local_14;
    }
    else {
      DAT_1007f28c = (iVar5 * 0x10000) / local_14;
    }
    DAT_1007f3ac = DAT_1007f300;
    iVar5 = local_14 >> 1;
    iVar6 = iVar5;
    if ((int)(DAT_1007f304 - DAT_1007f300) < 0) {
      iVar6 = -iVar5;
    }
    DAT_1007f3b0 = (int)((DAT_1007f304 - DAT_1007f300) + iVar6) / local_14;
    uVar10 = DAT_1007f300 >> 0x10;
    _DAT_1007f3b4 =
         (char)(&DAT_1007f7d0)
               [(int)(DAT_1007f310 | DAT_1007f314 | DAT_1007f318 | DAT_1007f30c) >> 0x10] + 1;
    bVar4 = (byte)_DAT_1007f3b4;
    uVar12 = DAT_1007f304 >> 0x10;
    DAT_1007f38c = ((int)DAT_1007f30c >> (bVar4 & 0x1f)) * uVar10;
    DAT_1007f390 = (int)(((int)DAT_1007f314 >> (bVar4 & 0x1f)) * uVar12 - DAT_1007f38c) / local_14;
    DAT_1007f394 = ((int)DAT_1007f310 >> (bVar4 & 0x1f)) * uVar10;
    DAT_1007f398 = (int)(((int)DAT_1007f318 >> (bVar4 & 0x1f)) * uVar12 - DAT_1007f394) / local_14;
    iVar6 = (int)sVar2 - DAT_1007f284;
    if (iVar6 < 1) {
      if (iVar9 == DAT_1007f280 || iVar9 - DAT_1007f280 < 0) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f3ac = DAT_1007f300;
        return;
      }
      iVar7 = iVar7 - iVar9;
      if (local_14 == 1) {
        DAT_1007f288 = iVar7 * 0x10000;
      }
      else if (local_14 == 2) {
        DAT_1007f288 = iVar7 * 0x8000;
      }
      else if (((local_14 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar11 + (iVar7 * 0x20 + local_14) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1007f288 = (iVar7 * 0x10000) / local_14;
      }
      else {
        DAT_1007f288 = (iVar7 * 0x10000) / local_14;
      }
      DAT_1007f3c0 = DAT_1007f308;
      if ((int)(DAT_1007f304 - DAT_1007f308) < 0) {
        iVar5 = -iVar5;
      }
      DAT_1007f3c4 = (int)((DAT_1007f304 - DAT_1007f308) + iVar5) / local_14;
      _DAT_1007f3c8 =
           (char)(&DAT_1007f7d0)
                 [(int)(DAT_1007f320 | DAT_1007f314 | DAT_1007f318 | DAT_1007f31c) >> 0x10] + 1;
      bVar4 = (byte)_DAT_1007f3c8;
      DAT_1007f39c = ((int)DAT_1007f31c >> (bVar4 & 0x1f)) * (DAT_1007f308 >> 0x10);
      DAT_1007f3a0 = (int)(((int)DAT_1007f314 >> (bVar4 & 0x1f)) * uVar12 - DAT_1007f39c) / local_14
      ;
      DAT_1007f3a4 = ((int)DAT_1007f320 >> (bVar4 & 0x1f)) * (DAT_1007f308 >> 0x10);
      DAT_1007f3a8 = (int)(((int)DAT_1007f318 >> (bVar4 & 0x1f)) * uVar12 - DAT_1007f3a4) / local_14
      ;
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = iVar9 << 0x10;
    }
    else {
      iVar5 = iVar9 - DAT_1007f280;
      if (iVar6 == 1) {
        DAT_1007f288 = iVar5 * 0x10000;
      }
      else if (iVar6 == 2) {
        DAT_1007f288 = iVar5 * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar11 + (iVar5 * 0x20 + iVar6) * 4);
      }
      else if (iVar5 < 0) {
        DAT_1007f288 = (iVar5 * 0x10000) / iVar6;
      }
      else {
        DAT_1007f288 = (iVar5 * 0x10000) / iVar6;
      }
      if (DAT_1007f288 == DAT_1007f28c || DAT_1007f288 - DAT_1007f28c < 0) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f3ac = DAT_1007f300;
        return;
      }
      DAT_1007f3c0 = DAT_1007f300;
      iVar5 = iVar6 >> 1;
      if ((int)(DAT_1007f308 - DAT_1007f300) < 0) {
        iVar5 = -iVar5;
      }
      DAT_1007f3c4 = (int)(iVar5 + (DAT_1007f308 - DAT_1007f300)) / iVar6;
      _DAT_1007f3c8 =
           (char)(&DAT_1007f7d0)
                 [(int)(DAT_1007f320 | DAT_1007f310 | DAT_1007f31c | DAT_1007f30c) >> 0x10] + 1;
      bVar4 = (byte)_DAT_1007f3c8;
      DAT_1007f39c = ((int)DAT_1007f30c >> (bVar4 & 0x1f)) * uVar10;
      DAT_1007f3a0 = (int)(((int)DAT_1007f31c >> (bVar4 & 0x1f)) * (DAT_1007f308 >> 0x10) -
                          DAT_1007f39c) / iVar6;
      DAT_1007f3a4 = ((int)DAT_1007f310 >> (bVar4 & 0x1f)) * uVar10;
      DAT_1007f3a8 = (int)(((int)DAT_1007f320 >> (bVar4 & 0x1f)) * (DAT_1007f308 >> 0x10) -
                          DAT_1007f3a4) / iVar6;
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (local_14 < iVar6) {
        iVar6 = iVar6 - local_14;
        DAT_1007f290 = local_14;
        FUN_1006f42c();
        DAT_1007f3ac = DAT_1007f304;
        iVar5 = iVar6 >> 1;
        if ((int)(DAT_1007f308 - DAT_1007f304) < 0) {
          iVar5 = -iVar5;
        }
        DAT_1007f3b0 = (int)(iVar5 + (DAT_1007f308 - DAT_1007f304)) / iVar6;
        _DAT_1007f3b4 =
             (char)(&DAT_1007f7d0)
                   [(int)(DAT_1007f320 | DAT_1007f314 | DAT_1007f318 | DAT_1007f31c) >> 0x10] + 1;
        bVar4 = (byte)_DAT_1007f3b4;
        DAT_1007f38c = ((int)DAT_1007f314 >> (bVar4 & 0x1f)) * (DAT_1007f304 >> 0x10);
        DAT_1007f390 = (int)(((int)DAT_1007f31c >> (bVar4 & 0x1f)) * (DAT_1007f308 >> 0x10) -
                            DAT_1007f38c) / iVar6;
        DAT_1007f394 = ((int)DAT_1007f318 >> (bVar4 & 0x1f)) * (DAT_1007f304 >> 0x10);
        DAT_1007f398 = (int)(((int)DAT_1007f320 >> (bVar4 & 0x1f)) * (DAT_1007f308 >> 0x10) -
                            DAT_1007f394) / iVar6;
        DAT_1007f280 = iVar7 << 0x10;
        iVar9 = iVar9 - iVar7;
        local_14 = iVar6;
        if (iVar6 == 1) {
          DAT_1007f28c = iVar9 * 0x10000;
        }
        else if (iVar6 == 2) {
          DAT_1007f28c = iVar9 * 0x8000;
        }
        else if (((iVar6 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar11 + (iVar9 * 0x20 + iVar6) * 4);
        }
        else if (iVar9 < 0) {
          DAT_1007f28c = (iVar9 * 0x10000) / iVar6;
        }
        else {
          DAT_1007f28c = (iVar9 * 0x10000) / iVar6;
        }
      }
      else {
        local_14 = local_14 - iVar6;
        DAT_1007f290 = iVar6;
        FUN_1006f42c();
        if (local_14 == 0) {
          return;
        }
        DAT_1007f3c0 = DAT_1007f308;
        iVar5 = local_14 >> 1;
        if ((int)(DAT_1007f304 - DAT_1007f308) < 0) {
          iVar5 = -iVar5;
        }
        DAT_1007f3c4 = (int)(iVar5 + (DAT_1007f304 - DAT_1007f308)) / local_14;
        _DAT_1007f3c8 =
             (char)(&DAT_1007f7d0)
                   [(int)(DAT_1007f320 | DAT_1007f314 | DAT_1007f318 | DAT_1007f31c) >> 0x10] + 1;
        bVar4 = (byte)_DAT_1007f3c8;
        DAT_1007f39c = ((int)DAT_1007f31c >> (bVar4 & 0x1f)) * (DAT_1007f308 >> 0x10);
        DAT_1007f3a0 = (int)(((int)DAT_1007f314 >> (bVar4 & 0x1f)) * (DAT_1007f304 >> 0x10) -
                            DAT_1007f39c) / local_14;
        DAT_1007f3a4 = ((int)DAT_1007f320 >> (bVar4 & 0x1f)) * (DAT_1007f308 >> 0x10);
        DAT_1007f3a8 = (int)(((int)DAT_1007f318 >> (bVar4 & 0x1f)) * (DAT_1007f304 >> 0x10) -
                            DAT_1007f3a4) / local_14;
        DAT_1007f284 = iVar9 << 0x10;
        iVar7 = iVar7 - iVar9;
        if (local_14 == 1) {
          DAT_1007f288 = iVar7 * 0x10000;
        }
        else if (local_14 == 2) {
          DAT_1007f288 = iVar7 * 0x8000;
        }
        else if (((local_14 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar11 + (iVar7 * 0x20 + local_14) * 4);
        }
        else if (iVar7 < 0) {
          DAT_1007f288 = (iVar7 * 0x10000) / local_14;
        }
        else {
          DAT_1007f288 = (iVar7 * 0x10000) / local_14;
        }
      }
    }
  }
  DAT_1007f290 = local_14;
  FUN_1006f42c();
  return;
}


