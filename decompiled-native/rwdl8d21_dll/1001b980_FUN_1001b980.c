// 1001b980 FUN_1001b980 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b980(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  undefined3 extraout_var;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iStack_24;
  
  iVar15 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      param_2 = param_3;
      iVar17 = param_4;
      param_4 = iVar15;
    }
    else {
LAB_1001b9c6:
      param_2 = param_4;
      iVar17 = iVar15;
      param_4 = param_3;
    }
  }
  else {
    iVar17 = param_3;
    if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001b9c6;
  }
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(iVar17 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar7 = (int)sVar1 - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  iVar15 = *(int *)(param_2 + 0x20);
  iVar3 = *(int *)(iVar17 + 0x20);
  iVar16 = (int)*(short *)(iVar17 + 0x1a);
  iVar8 = (int)*(short *)(param_4 + 0x1a);
  iVar4 = *(int *)(param_4 + 0x20);
  DAT_1007b30c = *(uint *)(param_2 + 100);
  DAT_1007b310 = *(uint *)(param_2 + 0x68);
  DAT_1007b314 = *(uint *)(iVar17 + 100);
  DAT_1007b318 = *(uint *)(iVar17 + 0x68);
  DAT_1007b31c = *(uint *)(param_4 + 100);
  DAT_1007b320 = *(uint *)(param_4 + 0x68);
  _DAT_1007b324 = *(float *)(param_2 + 0x14);
  _DAT_1007b328 = *(float *)(iVar17 + 0x14);
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
  bVar5 = FUN_100059c0(param_2,iVar17,param_4);
  DAT_1007b43c = (uint)(CONCAT31(extraout_var,bVar5) == 0);
  DAT_1007b2a0 = DAT_10077eb0;
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar17 = DAT_10075214 + 0x1000;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  if (DAT_1007b43c == 0) {
    _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  }
  else {
    _DAT_1007b2a4 = *(undefined4 *)(DAT_10075230 + (DAT_1007b284 & 7) * 4);
  }
  if (iVar7 < 1) {
    iVar7 = DAT_1007b280 - iVar16;
    if (iVar7 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iStack_24 = -((int)sVar1 - (int)sVar2);
    if (iStack_24 == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    DAT_1007b3ac = DAT_1007b304;
    iVar10 = iStack_24 >> 1;
    iVar13 = iVar10;
    if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
      iVar13 = -iVar10;
    }
    DAT_1007b3b0 = (int)(iVar13 + (DAT_1007b308 - DAT_1007b304)) / iStack_24;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
    DAT_1007b38c = ((int)DAT_1007b314 >> (DAT_1007b3b4 & 0x1f)) * (DAT_1007b304 >> 0x10);
    uVar11 = DAT_1007b308 >> 0x10;
    DAT_1007b390 = (int)(((int)DAT_1007b31c >> (DAT_1007b3b4 & 0x1f)) * uVar11 - DAT_1007b38c) /
                   iStack_24;
    DAT_1007b394 = ((int)DAT_1007b318 >> (DAT_1007b3b4 & 0x1f)) * (DAT_1007b304 >> 0x10);
    DAT_1007b398 = (int)(((int)DAT_1007b320 >> (DAT_1007b3b4 & 0x1f)) * uVar11 - DAT_1007b394) /
                   iStack_24;
    DAT_1007b3c0 = DAT_1007b300;
    if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
      iVar10 = -iVar10;
    }
    DAT_1007b3c4 = (int)(iVar10 + (DAT_1007b308 - DAT_1007b300)) / iStack_24;
    _DAT_1007b3c8 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
    DAT_1007b39c = ((int)DAT_1007b30c >> (DAT_1007b3c8 & 0x1f)) * (DAT_1007b300 >> 0x10);
    DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (DAT_1007b3c8 & 0x1f)) * uVar11 - DAT_1007b39c) /
                   iStack_24;
    DAT_1007b3a4 = ((int)DAT_1007b310 >> (DAT_1007b3c8 & 0x1f)) * (DAT_1007b300 >> 0x10);
    DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (DAT_1007b3c8 & 0x1f)) * uVar11 - DAT_1007b3a4) /
                   iStack_24;
    iVar10 = iVar8 - iVar16;
    if (iStack_24 == 1) {
      DAT_1007b28c = iVar10 * 0x10000;
    }
    else if (iStack_24 == 2) {
      DAT_1007b28c = iVar10 * 0x8000;
    }
    else if (((iStack_24 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar17 + (iVar10 * 0x20 + iStack_24) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007b28c = (iVar10 * 0x10000) / iStack_24;
    }
    else {
      DAT_1007b28c = (iVar10 * 0x10000) / iStack_24;
    }
    iVar8 = iVar8 - DAT_1007b280;
    if (iStack_24 == 1) {
      DAT_1007b288 = iVar8 * 0x10000;
    }
    else if (iStack_24 == 2) {
      DAT_1007b288 = iVar8 * 0x8000;
    }
    else if (((iStack_24 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar17 + (iVar8 * 0x20 + iStack_24) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1007b288 = (iVar8 * 0x10000) / iStack_24;
    }
    else {
      DAT_1007b288 = (iVar8 * 0x10000) / iStack_24;
    }
    iVar8 = DAT_1007b280;
    if (DAT_1007b43c == 0) {
      if ((iVar3 == iVar15) || (iVar7 == 1)) {
        DAT_1007b2ec = iVar15 - iVar3;
      }
      else if (iVar7 == 2) {
        DAT_1007b2ec = iVar15 - iVar3 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar15 - iVar3) / iVar7;
      }
      DAT_1007b2e4 = iVar3;
      if ((iVar4 == iVar3) || (iStack_24 == 1)) {
        DAT_1007b2e8 = iVar4 - iVar3;
      }
      else if (iStack_24 == 2) {
        DAT_1007b2e8 = iVar4 - iVar3 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar4 - iVar3) / iStack_24;
      }
    }
    else {
      if ((iVar3 == iVar15) || (iVar7 == 1)) {
        DAT_1007b2ec = iVar3 - iVar15;
      }
      else if (iVar7 == 2) {
        DAT_1007b2ec = iVar3 - iVar15 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar3 - iVar15) / iVar7;
      }
      if (iVar4 == iVar15) {
        DAT_1007b2e8 = iVar4 - iVar15;
        DAT_1007b2e4 = iVar15;
      }
      else if (iStack_24 == 1) {
        DAT_1007b2e8 = iVar4 - iVar15;
        DAT_1007b2e4 = iVar15;
      }
      else if (iStack_24 == 2) {
        DAT_1007b2e8 = iVar4 - iVar15 >> 1;
        DAT_1007b2e4 = iVar15;
      }
      else {
        DAT_1007b2e8 = (iVar4 - iVar15) / iStack_24;
        DAT_1007b2e4 = iVar15;
      }
    }
  }
  else {
    iVar10 = iVar16 - DAT_1007b280;
    if (iVar7 == 1) {
      DAT_1007b28c = iVar10 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1007b28c = iVar10 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar17 + (iVar10 * 0x20 + iVar7) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007b28c = (iVar10 * 0x10000) / iVar7;
    }
    else {
      DAT_1007b28c = (iVar10 * 0x10000) / iVar7;
    }
    DAT_1007b3ac = DAT_1007b300;
    iVar10 = iVar7 >> 1;
    iVar13 = iVar10;
    if ((int)(DAT_1007b304 - DAT_1007b300) < 0) {
      iVar13 = -iVar10;
    }
    DAT_1007b3b0 = (int)(iVar13 + (DAT_1007b304 - DAT_1007b300)) / iVar7;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b310 | DAT_1007b314 | DAT_1007b318 | DAT_1007b30c) >> 0x10] + 1;
    uVar11 = DAT_1007b300 >> 0x10;
    DAT_1007b38c = ((int)DAT_1007b30c >> (DAT_1007b3b4 & 0x1f)) * uVar11;
    uVar12 = DAT_1007b304 >> 0x10;
    DAT_1007b390 = (int)(((int)DAT_1007b314 >> (DAT_1007b3b4 & 0x1f)) * uVar12 - DAT_1007b38c) /
                   iVar7;
    DAT_1007b394 = ((int)DAT_1007b310 >> (DAT_1007b3b4 & 0x1f)) * uVar11;
    DAT_1007b398 = (int)(((int)DAT_1007b318 >> (DAT_1007b3b4 & 0x1f)) * uVar12 - DAT_1007b394) /
                   iVar7;
    iVar13 = (int)sVar2 - DAT_1007b284;
    if (0 < iVar13) {
      iVar10 = iVar8 - DAT_1007b280;
      if (iVar13 == 1) {
        DAT_1007b288 = iVar10 * 0x10000;
      }
      else if (iVar13 == 2) {
        DAT_1007b288 = iVar10 * 0x8000;
      }
      else if (((iVar13 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar17 + (iVar10 * 0x20 + iVar13) * 4);
      }
      else if (iVar10 < 0) {
        DAT_1007b288 = (iVar10 * 0x10000) / iVar13;
      }
      else {
        DAT_1007b288 = (iVar10 * 0x10000) / iVar13;
      }
      if (DAT_1007b288 - DAT_1007b28c < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        DAT_1007b3ac = DAT_1007b300;
        return;
      }
      DAT_1007b3c0 = DAT_1007b300;
      iVar10 = iVar13 >> 1;
      if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
        iVar10 = -iVar10;
      }
      DAT_1007b3c4 = (int)(iVar10 + (DAT_1007b308 - DAT_1007b300)) / iVar13;
      _DAT_1007b3c8 =
           (char)(&DAT_1007b7d0)
                 [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
      bVar6 = (byte)_DAT_1007b3c8;
      DAT_1007b39c = ((int)DAT_1007b30c >> (bVar6 & 0x1f)) * uVar11;
      DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar6 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b39c) / iVar13;
      DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar6 & 0x1f)) * uVar11;
      DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar6 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b3a4) / iVar13;
      iVar10 = DAT_1007b288 - DAT_1007b28c >> 6;
      if (DAT_1007b43c == 0) {
        if ((iVar3 == iVar15) || (iVar7 == 1)) {
          DAT_1007b2e8 = iVar3 - iVar15;
        }
        else if (iVar7 == 2) {
          DAT_1007b2e8 = iVar3 - iVar15 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar3 - iVar15) / iVar7;
        }
        if ((iVar4 == iVar15) || (iVar13 == 1)) {
          iVar14 = iVar4 - iVar15;
        }
        else if (iVar13 == 2) {
          iVar14 = iVar4 - iVar15 >> 1;
        }
        else {
          iVar14 = (iVar4 - iVar15) / iVar13;
        }
        DAT_1007b2ec = iVar14 - DAT_1007b2e8;
      }
      else {
        if ((iVar4 == iVar15) || (iVar13 == 1)) {
          DAT_1007b2e8 = iVar4 - iVar15;
        }
        else if (iVar13 == 2) {
          DAT_1007b2e8 = iVar4 - iVar15 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar4 - iVar15) / iVar13;
        }
        if ((iVar3 == iVar15) || (iVar7 == 1)) {
          iVar14 = iVar3 - iVar15;
        }
        else if (iVar7 == 2) {
          iVar14 = iVar3 - iVar15 >> 1;
        }
        else {
          iVar14 = (iVar3 - iVar15) / iVar7;
        }
        DAT_1007b2ec = iVar14 - DAT_1007b2e8;
      }
      if ((DAT_1007b2ec != 0) && (iVar10 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / iVar10 << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar7 < iVar13) {
        iStack_24 = iVar13 - iVar7;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar15;
        DAT_1007b290 = iVar7;
        FUN_1001cbf0((uint *)&DAT_1007b280);
        DAT_1007b3ac = DAT_1007b304;
        iVar15 = iStack_24 >> 1;
        if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
          iVar15 = -iVar15;
        }
        DAT_1007b3b0 = (int)(iVar15 + (DAT_1007b308 - DAT_1007b304)) / iStack_24;
        _DAT_1007b3b4 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar6 = (byte)_DAT_1007b3b4;
        DAT_1007b38c = ((int)DAT_1007b314 >> (bVar6 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar6 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b38c) / iStack_24;
        DAT_1007b394 = ((int)DAT_1007b318 >> (bVar6 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar6 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b394) / iStack_24;
        DAT_1007b280 = iVar16 << 0x10;
        iVar8 = iVar8 - iVar16;
        if (iStack_24 == 1) {
          DAT_1007b28c = iVar8 * 0x10000;
        }
        else if (iStack_24 == 2) {
          DAT_1007b28c = iVar8 * 0x8000;
        }
        else if (((iStack_24 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar17 + (iVar8 * 0x20 + iStack_24) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1007b28c = (iVar8 * 0x10000) / iStack_24;
        }
        else {
          DAT_1007b28c = (iVar8 * 0x10000) / iStack_24;
        }
        if (DAT_1007b43c == 0) {
          if (iVar4 == iVar3) {
            DAT_1007b2e8 = iVar4 - iVar3;
          }
          else if (iStack_24 == 1) {
            DAT_1007b2e8 = iVar4 - iVar3;
          }
          else if (iStack_24 == 2) {
            DAT_1007b2e8 = iVar4 - iVar3 >> 1;
          }
          else {
            DAT_1007b2e8 = (iVar4 - iVar3) / iStack_24;
          }
        }
      }
      else {
        iStack_24 = iVar7 - iVar13;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar15;
        DAT_1007b290 = iVar13;
        FUN_1001cbf0((uint *)&DAT_1007b280);
        if (iStack_24 == 0) {
          return;
        }
        DAT_1007b3c0 = DAT_1007b308;
        iVar15 = iStack_24 >> 1;
        if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
          iVar15 = -iVar15;
        }
        DAT_1007b3c4 = (int)(iVar15 + (DAT_1007b304 - DAT_1007b308)) / iStack_24;
        _DAT_1007b3c8 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar6 = (byte)_DAT_1007b3c8;
        DAT_1007b39c = ((int)DAT_1007b31c >> (bVar6 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar6 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b39c) / iStack_24;
        DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar6 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar6 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b3a4) / iStack_24;
        DAT_1007b284 = iVar8 << 0x10;
        iVar16 = iVar16 - iVar8;
        if (iStack_24 == 1) {
          DAT_1007b288 = iVar16 * 0x10000;
        }
        else if (iStack_24 == 2) {
          DAT_1007b288 = iVar16 * 0x8000;
        }
        else if (((iStack_24 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar17 + (iVar16 * 0x20 + iStack_24) * 4);
        }
        else if (iVar16 < 0) {
          DAT_1007b288 = (iVar16 * 0x10000) / iStack_24;
        }
        else {
          DAT_1007b288 = (iVar16 * 0x10000) / iStack_24;
        }
        if (DAT_1007b43c != 0) {
          if (iVar4 == iVar3) {
            DAT_1007b2e8 = iVar3 - iVar4;
          }
          else if (iStack_24 == 1) {
            DAT_1007b2e8 = iVar3 - iVar4;
          }
          else if (iStack_24 == 2) {
            DAT_1007b2e8 = iVar3 - iVar4 >> 1;
          }
          else {
            DAT_1007b2e8 = (iVar3 - iVar4) / iStack_24;
          }
        }
      }
      goto LAB_1001cbcf;
    }
    iVar13 = iVar8 - DAT_1007b280;
    if (iVar13 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      DAT_1007b3ac = DAT_1007b300;
      return;
    }
    iVar16 = iVar16 - iVar8;
    if (iVar7 == 1) {
      DAT_1007b288 = iVar16 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1007b288 = iVar16 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar17 + (iVar16 * 0x20 + iVar7) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1007b288 = (iVar16 * 0x10000) / iVar7;
    }
    else {
      DAT_1007b288 = (iVar16 * 0x10000) / iVar7;
    }
    DAT_1007b3c0 = DAT_1007b308;
    if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
      iVar10 = -iVar10;
    }
    DAT_1007b3c4 = (int)((DAT_1007b304 - DAT_1007b308) + iVar10) / iVar7;
    _DAT_1007b3c8 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
    DAT_1007b39c = ((int)DAT_1007b31c >> (DAT_1007b3c8 & 0x1f)) * (DAT_1007b308 >> 0x10);
    DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (DAT_1007b3c8 & 0x1f)) * uVar12 - DAT_1007b39c) /
                   iVar7;
    DAT_1007b3a4 = ((int)DAT_1007b320 >> (DAT_1007b3c8 & 0x1f)) * (DAT_1007b308 >> 0x10);
    DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (DAT_1007b3c8 & 0x1f)) * uVar12 - DAT_1007b3a4) /
                   iVar7;
    iStack_24 = iVar7;
    iVar16 = DAT_1007b280;
    if (DAT_1007b43c == 0) {
      if ((iVar4 == iVar15) || (iVar13 == 1)) {
        DAT_1007b2ec = iVar4 - iVar15;
      }
      else if (iVar13 == 2) {
        DAT_1007b2ec = iVar4 - iVar15 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar4 - iVar15) / iVar13;
      }
      if ((iVar3 == iVar15) || (iVar7 == 1)) {
        DAT_1007b2e8 = iVar3 - iVar15;
        DAT_1007b2e4 = iVar15;
      }
      else if (iVar7 == 2) {
        DAT_1007b2e8 = iVar3 - iVar15 >> 1;
        DAT_1007b2e4 = iVar15;
      }
      else {
        DAT_1007b2e8 = (iVar3 - iVar15) / iVar7;
        DAT_1007b2e4 = iVar15;
      }
    }
    else {
      if ((iVar4 == iVar15) || (iVar13 == 1)) {
        DAT_1007b2ec = iVar15 - iVar4;
      }
      else if (iVar13 == 2) {
        DAT_1007b2ec = iVar15 - iVar4 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar15 - iVar4) / iVar13;
      }
      DAT_1007b2e4 = iVar4;
      if (iVar4 == iVar3) {
        DAT_1007b2e8 = iVar3 - iVar4;
      }
      else if (iVar7 == 1) {
        DAT_1007b2e8 = iVar3 - iVar4;
      }
      else if (iVar7 == 2) {
        DAT_1007b2e8 = iVar3 - iVar4 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar3 - iVar4) / iVar7;
      }
    }
  }
  DAT_1007b284 = iVar8 << 0x10;
  DAT_1007b280 = iVar16 << 0x10;
  DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2f0;
LAB_1001cbcf:
  DAT_1007b290 = iStack_24;
  FUN_1001cbf0((uint *)&DAT_1007b280);
  return;
}


