// 100262c0 FUN_100262c0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100262c0(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  byte bVar4;
  undefined3 extraout_var;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  int unaff_EBX;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  
  iVar8 = param_2;
  iVar10 = param_3;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar8 = param_4;
      iVar10 = param_2;
      param_4 = param_3;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_10026309;
  param_3 = iVar8;
  param_2 = param_4;
  param_4 = iVar10;
LAB_10026309:
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar7 = (int)sVar1 - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  iVar8 = (int)*(short *)(param_3 + 0x1a);
  iVar10 = (int)*(short *)(param_4 + 0x1a);
  DAT_1007b310 = *(uint *)(param_2 + 0x68);
  DAT_1007b30c = *(uint *)(param_2 + 100);
  DAT_1007b318 = *(uint *)(param_3 + 0x68);
  DAT_1007b314 = *(uint *)(param_3 + 100);
  DAT_1007b320 = *(uint *)(param_4 + 0x68);
  DAT_1007b31c = *(uint *)(param_4 + 100);
  _DAT_1007b324 = *(float *)(param_2 + 0x14);
  _DAT_1007b328 = *(float *)(param_3 + 0x14);
  _DAT_1007b32c = *(float *)(param_4 + 0x14);
  DAT_1007b330 = _DAT_1007b32c * _DAT_1007b328;
  DAT_1007b334 = _DAT_1007b32c * _DAT_1007b324;
  DAT_1007b338 = _DAT_1007b324 * _DAT_1007b328;
  fVar9 = DAT_1007b334;
  if ((int)DAT_1007b334 < (int)DAT_1007b330) {
    fVar9 = DAT_1007b330;
  }
  if ((int)fVar9 <= (int)DAT_1007b338) {
    fVar9 = DAT_1007b338;
  }
  _DAT_1007b33c = (int)fVar9 >> 0x17;
  DAT_1007b300 = ((int)((uint)DAT_1007b330 & 0x7fffff | 0x800000) >>
                 ((char)_DAT_1007b33c - (char)((int)DAT_1007b330 >> 0x17) & 0x1fU)) << 7;
  DAT_1007b304 = ((int)((uint)DAT_1007b334 & 0x7fffff | 0x800000) >>
                 ((char)_DAT_1007b33c - (char)((int)DAT_1007b334 >> 0x17) & 0x1fU)) << 7;
  _DAT_1007b340 = _DAT_1007b33c - ((int)DAT_1007b338 >> 0x17);
  DAT_1007b308 = ((int)((uint)DAT_1007b338 & 0x7fffff | 0x800000) >> ((byte)_DAT_1007b340 & 0x1f))
                 << 7;
  if ((short)(DAT_1007b300 >> 0x10) == 0) {
    DAT_1007b300 = 0x10000;
  }
  if ((short)(DAT_1007b304 >> 0x10) == 0) {
    DAT_1007b304 = 0x10000;
  }
  if ((short)(DAT_1007b308 >> 0x10) == 0) {
    DAT_1007b308 = 0x10000;
  }
  bVar3 = FUN_100059c0(param_2,param_3,param_4);
  DAT_1007b43c = (uint)(CONCAT31(extraout_var,bVar3) == 0);
  DAT_1007b2b4 = ((int)(param_1[1] & 0xffff00ffU) >> 8) + DAT_10075220;
  iVar12 = DAT_10075214 + 0x1000;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  iVar5 = DAT_10075228;
  if (DAT_1007b43c != 0) {
    iVar5 = DAT_10075230;
  }
  _DAT_1007b2a4 = *(undefined4 *)(iVar5 + (DAT_1007b284 & 7) * 4);
  if (iVar7 < 1) {
    if (DAT_1007b280 == iVar8 || DAT_1007b280 - iVar8 < 0) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    iVar7 = -((int)sVar1 - (int)sVar2);
    if (iVar7 == 0) {
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    DAT_1007b3ac = DAT_1007b304;
    iVar5 = iVar7 >> 1;
    iVar6 = iVar5;
    if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
      iVar6 = -iVar5;
    }
    DAT_1007b3b0 = (int)((DAT_1007b308 - DAT_1007b304) + iVar6) / iVar7;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
    bVar4 = (byte)_DAT_1007b3b4;
    uVar11 = DAT_1007b308 >> 0x10;
    DAT_1007b38c = ((int)DAT_1007b314 >> (bVar4 & 0x1f)) * (DAT_1007b304 >> 0x10);
    DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar4 & 0x1f)) * uVar11 - DAT_1007b38c) / iVar7;
    DAT_1007b394 = ((int)DAT_1007b318 >> (bVar4 & 0x1f)) * (DAT_1007b304 >> 0x10);
    DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar4 & 0x1f)) * uVar11 - DAT_1007b394) / iVar7;
    DAT_1007b3c0 = DAT_1007b300;
    if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
      iVar5 = -iVar5;
    }
    DAT_1007b3c4 = (int)((DAT_1007b308 - DAT_1007b300) + iVar5) / iVar7;
    _DAT_1007b3c8 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
    bVar4 = (byte)_DAT_1007b3c8;
    DAT_1007b39c = ((int)DAT_1007b30c >> (bVar4 & 0x1f)) * (DAT_1007b300 >> 0x10);
    DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar4 & 0x1f)) * uVar11 - DAT_1007b39c) / iVar7;
    DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar4 & 0x1f)) * (DAT_1007b300 >> 0x10);
    DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar4 & 0x1f)) * uVar11 - DAT_1007b3a4) / iVar7;
    iVar5 = iVar10 - iVar8;
    if (iVar7 == 1) {
      DAT_1007b28c = iVar5 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1007b28c = iVar5 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar12 + (iVar5 * 0x20 + iVar7) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007b28c = (iVar5 * 0x10000) / iVar7;
    }
    else {
      DAT_1007b28c = (iVar5 * 0x10000) / iVar7;
    }
    iVar10 = iVar10 - DAT_1007b280;
    if (iVar7 == 1) {
      DAT_1007b288 = iVar10 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1007b288 = iVar10 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar12 + (iVar10 * 0x20 + iVar7) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007b288 = (iVar10 * 0x10000) / iVar7;
    }
    else {
      DAT_1007b288 = (iVar10 * 0x10000) / iVar7;
    }
    DAT_1007b284 = DAT_1007b280 << 0x10;
    DAT_1007b280 = iVar8 << 0x10;
    DAT_1007b290 = unaff_EBX;
  }
  else {
    iVar5 = iVar8 - DAT_1007b280;
    if (iVar7 == 1) {
      DAT_1007b28c = iVar5 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1007b28c = iVar5 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar12 + (iVar5 * 0x20 + iVar7) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007b28c = (iVar5 * 0x10000) / iVar7;
    }
    else {
      DAT_1007b28c = (iVar5 * 0x10000) / iVar7;
    }
    DAT_1007b3ac = DAT_1007b300;
    iVar5 = iVar7 >> 1;
    iVar6 = iVar5;
    if ((int)(DAT_1007b304 - DAT_1007b300) < 0) {
      iVar6 = -iVar5;
    }
    DAT_1007b3b0 = (int)((DAT_1007b304 - DAT_1007b300) + iVar6) / iVar7;
    uVar11 = DAT_1007b300 >> 0x10;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b310 | DAT_1007b314 | DAT_1007b318 | DAT_1007b30c) >> 0x10] + 1;
    bVar4 = (byte)_DAT_1007b3b4;
    uVar13 = DAT_1007b304 >> 0x10;
    DAT_1007b38c = ((int)DAT_1007b30c >> (bVar4 & 0x1f)) * uVar11;
    DAT_1007b390 = (int)(((int)DAT_1007b314 >> (bVar4 & 0x1f)) * uVar13 - DAT_1007b38c) / iVar7;
    DAT_1007b394 = ((int)DAT_1007b310 >> (bVar4 & 0x1f)) * uVar11;
    DAT_1007b398 = (int)(((int)DAT_1007b318 >> (bVar4 & 0x1f)) * uVar13 - DAT_1007b394) / iVar7;
    iVar6 = (int)sVar2 - DAT_1007b284;
    if (iVar6 < 1) {
      if (iVar10 == DAT_1007b280 || iVar10 - DAT_1007b280 < 0) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b3ac = DAT_1007b300;
        return;
      }
      iVar8 = iVar8 - iVar10;
      if (iVar7 == 1) {
        DAT_1007b288 = iVar8 * 0x10000;
      }
      else if (iVar7 == 2) {
        DAT_1007b288 = iVar8 * 0x8000;
      }
      else if (((iVar7 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar12 + (iVar8 * 0x20 + iVar7) * 4);
      }
      else if (iVar8 < 0) {
        DAT_1007b288 = (iVar8 * 0x10000) / iVar7;
      }
      else {
        DAT_1007b288 = (iVar8 * 0x10000) / iVar7;
      }
      DAT_1007b3c0 = DAT_1007b308;
      if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
        iVar5 = -iVar5;
      }
      DAT_1007b3c4 = (int)((DAT_1007b304 - DAT_1007b308) + iVar5) / iVar7;
      _DAT_1007b3c8 =
           (char)(&DAT_1007b7d0)
                 [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
      bVar4 = (byte)_DAT_1007b3c8;
      DAT_1007b39c = ((int)DAT_1007b31c >> (bVar4 & 0x1f)) * (DAT_1007b308 >> 0x10);
      DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar4 & 0x1f)) * uVar13 - DAT_1007b39c) / iVar7;
      DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar4 & 0x1f)) * (DAT_1007b308 >> 0x10);
      DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar4 & 0x1f)) * uVar13 - DAT_1007b3a4) / iVar7;
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = iVar10 << 0x10;
      DAT_1007b290 = unaff_EBX;
    }
    else {
      iVar8 = iVar10 - DAT_1007b280;
      if (iVar6 == 1) {
        DAT_1007b288 = iVar8 * 0x10000;
      }
      else if (iVar6 == 2) {
        DAT_1007b288 = iVar8 * 0x8000;
      }
      else if (((iVar6 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar12 + (iVar8 * 0x20 + iVar6) * 4);
      }
      else if (iVar8 < 0) {
        DAT_1007b288 = (iVar8 * 0x10000) / iVar6;
      }
      else {
        DAT_1007b288 = (iVar8 * 0x10000) / iVar6;
      }
      if (DAT_1007b288 == DAT_1007b28c || DAT_1007b288 - DAT_1007b28c < 0) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b3ac = DAT_1007b300;
        return;
      }
      DAT_1007b3c0 = DAT_1007b300;
      iVar8 = iVar6 >> 1;
      if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
        iVar8 = -iVar8;
      }
      DAT_1007b3c4 = (int)(iVar8 + (DAT_1007b308 - DAT_1007b300)) / iVar6;
      _DAT_1007b3c8 =
           (char)(&DAT_1007b7d0)
                 [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
      bVar4 = (byte)_DAT_1007b3c8;
      DAT_1007b39c = ((int)DAT_1007b30c >> (bVar4 & 0x1f)) * uVar11;
      DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar4 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b39c) / iVar6;
      DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar4 & 0x1f)) * uVar11;
      DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar4 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b3a4) / iVar6;
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar7 < iVar6) {
        DAT_1007b290 = iVar7;
        FUN_1006c2e8();
        DAT_1007b3ac = DAT_1007b304;
        if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
          iVar5 = -iVar5;
        }
        DAT_1007b3b0 = (int)(iVar5 + (DAT_1007b308 - DAT_1007b304)) / iVar7;
        _DAT_1007b3b4 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar4 = (byte)_DAT_1007b3b4;
        DAT_1007b38c = ((int)DAT_1007b314 >> (bVar4 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar4 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b38c) / iVar7;
        DAT_1007b394 = ((int)DAT_1007b318 >> (bVar4 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar4 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b394) / iVar7;
        DAT_1007b280 = iVar10 << 0x10;
        iVar10 = (iVar6 - iVar7) - iVar10;
        if (iVar7 == 1) {
          DAT_1007b28c = iVar10 * 0x10000;
          DAT_1007b290 = iVar7;
        }
        else if (iVar7 == 2) {
          DAT_1007b28c = iVar10 * 0x8000;
          DAT_1007b290 = iVar7;
        }
        else if (((iVar7 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar12 + (iVar10 * 0x20 + iVar7) * 4);
          DAT_1007b290 = iVar7;
        }
        else if (iVar10 < 0) {
          DAT_1007b28c = (iVar10 * 0x10000) / iVar7;
          DAT_1007b290 = iVar7;
        }
        else {
          DAT_1007b28c = (iVar10 * 0x10000) / iVar7;
          DAT_1007b290 = iVar7;
        }
      }
      else {
        DAT_1007b290 = iVar6;
        FUN_1006c2e8();
        if (unaff_EBX == 0) {
          return;
        }
        DAT_1007b3c0 = DAT_1007b308;
        iVar8 = unaff_EBX >> 1;
        if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
          iVar8 = -iVar8;
        }
        DAT_1007b3c4 = (int)(iVar8 + (DAT_1007b304 - DAT_1007b308)) / unaff_EBX;
        _DAT_1007b3c8 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar4 = (byte)_DAT_1007b3c8;
        DAT_1007b39c = ((int)DAT_1007b31c >> (bVar4 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar4 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b39c) / unaff_EBX;
        DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar4 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar4 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b3a4) / unaff_EBX;
        DAT_1007b284 = iVar6 * 0x10000;
        iVar10 = iVar10 - iVar6;
        if (unaff_EBX == 1) {
          DAT_1007b288 = iVar10 * 0x10000;
          DAT_1007b290 = unaff_EBX;
        }
        else if (unaff_EBX == 2) {
          DAT_1007b288 = iVar10 * 0x8000;
          DAT_1007b290 = unaff_EBX;
        }
        else if (((unaff_EBX < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar12 + (iVar10 * 0x20 + unaff_EBX) * 4);
          DAT_1007b290 = unaff_EBX;
        }
        else if (iVar10 < 0) {
          DAT_1007b288 = (iVar10 * 0x10000) / unaff_EBX;
          DAT_1007b290 = unaff_EBX;
        }
        else {
          DAT_1007b288 = (iVar10 * 0x10000) / unaff_EBX;
          DAT_1007b290 = unaff_EBX;
        }
      }
    }
  }
  FUN_1006c2e8();
  return;
}


