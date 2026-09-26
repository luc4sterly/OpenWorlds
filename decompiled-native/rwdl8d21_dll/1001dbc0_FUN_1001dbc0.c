// 1001dbc0 FUN_1001dbc0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001dbc0(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  bool bVar4;
  byte bVar5;
  undefined3 extraout_var;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  uint uVar15;
  uint uVar16;
  short sVar17;
  uint uVar18;
  int iStack_24;
  short sStack_1c;
  short sStack_18;
  
  iVar7 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    iVar8 = param_3;
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar8 = param_2;
      param_2 = param_4;
      iVar7 = param_3;
    }
LAB_1001dc07:
    param_4 = iVar8;
    param_3 = param_2;
    param_2 = iVar7;
  }
  else {
    iVar8 = param_3;
    if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001dc07;
  }
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iStack_24 = (int)sVar1 - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  iVar9 = (int)*(short *)(param_3 + 0x1a);
  iVar13 = (int)*(short *)(param_4 + 0x1a);
  iVar7 = *(int *)(param_2 + 0x58);
  uVar18 = iVar7 >> 8;
  iVar8 = *(int *)(param_3 + 0x58);
  uVar10 = iVar8 >> 8;
  iVar3 = *(int *)(param_4 + 0x58);
  uVar11 = iVar3 >> 8;
  DAT_1007b30c = *(uint *)(param_2 + 100);
  DAT_1007b310 = *(uint *)(param_2 + 0x68);
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
  fVar14 = DAT_1007b334;
  if ((int)DAT_1007b334 < (int)DAT_1007b330) {
    fVar14 = DAT_1007b330;
  }
  if ((int)fVar14 <= (int)DAT_1007b338) {
    fVar14 = DAT_1007b338;
  }
  _DAT_1007b33c = (int)fVar14 >> 0x17;
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
  bVar4 = FUN_100059c0(param_2,param_3,param_4);
  DAT_1007b2b4 = DAT_10075220;
  DAT_1007b43c = (uint)(CONCAT31(extraout_var,bVar4) == 0);
  iVar6 = DAT_10075214 + 0x1000;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  iVar12 = DAT_10075228;
  if (DAT_1007b43c != 0) {
    iVar12 = DAT_10075230;
  }
  _DAT_1007b2a4 = *(undefined4 *)(iVar12 + (DAT_1007b284 & 7) * 4);
  sVar17 = (short)((uint)iVar7 >> 8);
  sStack_1c = (short)((uint)iVar8 >> 8);
  sStack_18 = (short)((uint)iVar3 >> 8);
  if (0 < iStack_24) {
    iVar7 = iVar9 - DAT_1007b280;
    if (iStack_24 == 1) {
      DAT_1007b28c = iVar7 * 0x10000;
    }
    else if (iStack_24 == 2) {
      DAT_1007b28c = iVar7 * 0x8000;
    }
    else if (((iStack_24 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar6 + (iVar7 * 0x20 + iStack_24) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1007b28c = (iVar7 * 0x10000) / iStack_24;
    }
    else {
      DAT_1007b28c = (iVar7 * 0x10000) / iStack_24;
    }
    DAT_1007b3ac = DAT_1007b300;
    iVar7 = iStack_24 >> 1;
    iVar8 = iVar7;
    if ((int)(DAT_1007b304 - DAT_1007b300) < 0) {
      iVar8 = -iVar7;
    }
    DAT_1007b3b0 = (int)((DAT_1007b304 - DAT_1007b300) + iVar8) / iStack_24;
    uVar16 = DAT_1007b300 >> 0x10;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b310 | DAT_1007b314 | DAT_1007b318 | DAT_1007b30c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3b4;
    DAT_1007b38c = ((int)DAT_1007b30c >> (bVar5 & 0x1f)) * uVar16;
    uVar15 = DAT_1007b304 >> 0x10;
    DAT_1007b390 = (int)(((int)DAT_1007b314 >> (bVar5 & 0x1f)) * uVar15 - DAT_1007b38c) / iStack_24;
    DAT_1007b394 = ((int)DAT_1007b310 >> (bVar5 & 0x1f)) * uVar16;
    DAT_1007b398 = (int)(((int)DAT_1007b318 >> (bVar5 & 0x1f)) * uVar15 - DAT_1007b394) / iStack_24;
    iVar8 = (int)sVar2 - DAT_1007b284;
    if (0 < iVar8) {
      iVar7 = iVar13 - DAT_1007b280;
      if (iVar8 == 1) {
        DAT_1007b288 = iVar7 * 0x10000;
      }
      else if (iVar8 == 2) {
        DAT_1007b288 = iVar7 * 0x8000;
      }
      else if (((iVar8 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar6 + (iVar7 * 0x20 + iVar8) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1007b288 = (iVar7 * 0x10000) / iVar8;
      }
      else {
        DAT_1007b288 = (iVar7 * 0x10000) / iVar8;
      }
      if (DAT_1007b288 - DAT_1007b28c < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2b4 = DAT_10075220;
        DAT_1007b3ac = DAT_1007b300;
        return;
      }
      DAT_1007b3c0 = DAT_1007b300;
      iVar7 = iVar8 >> 1;
      if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
        iVar7 = -iVar7;
      }
      DAT_1007b3c4 = (int)(iVar7 + (DAT_1007b308 - DAT_1007b300)) / iVar8;
      _DAT_1007b3c8 =
           (char)(&DAT_1007b7d0)
                 [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
      bVar5 = (byte)_DAT_1007b3c8;
      DAT_1007b39c = ((int)DAT_1007b30c >> (bVar5 & 0x1f)) * uVar16;
      DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b39c) / iVar8;
      DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar5 & 0x1f)) * uVar16;
      DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b3a4) / iVar8;
      if (DAT_1007b43c == 0) {
        if ((sStack_1c == sVar17) || (iStack_24 == 1)) {
          uVar15 = (uVar10 & 0xffff) - (uVar18 & 0xffff);
        }
        else if (iStack_24 == 2) {
          uVar15 = (int)((uVar10 & 0xffff) - (uVar18 & 0xffff)) >> 1;
        }
        else {
          uVar15 = (int)((uVar10 & 0xffff) - (uVar18 & 0xffff)) / iStack_24;
        }
        uVar16 = uVar18 & 0xffff;
        DAT_1007b2c4 = (uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
        if ((sStack_18 == sVar17) || (iVar8 == 1)) {
          iVar7 = (uVar11 & 0xffff) - uVar16;
        }
        else if (iVar8 == 2) {
          iVar7 = (int)((uVar11 & 0xffff) - uVar16) >> 1;
        }
        else {
          iVar7 = (int)((uVar11 & 0xffff) - uVar16) / iVar8;
        }
        iVar7 = iVar7 - (short)DAT_1007b2c4;
      }
      else {
        if ((sStack_18 == sVar17) || (iVar8 == 1)) {
          uVar15 = (uVar11 & 0xffff) - (uVar18 & 0xffff);
        }
        else if (iVar8 == 2) {
          uVar15 = (int)((uVar11 & 0xffff) - (uVar18 & 0xffff)) >> 1;
        }
        else {
          uVar15 = (int)((uVar11 & 0xffff) - (uVar18 & 0xffff)) / iVar8;
        }
        uVar16 = uVar18 & 0xffff;
        DAT_1007b2c4 = (uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
        if ((sStack_1c == sVar17) || (iStack_24 == 1)) {
          iVar7 = (uVar10 & 0xffff) - uVar16;
        }
        else if (iStack_24 == 2) {
          iVar7 = (int)((uVar10 & 0xffff) - uVar16) >> 1;
        }
        else {
          iVar7 = (int)((uVar10 & 0xffff) - uVar16) / iStack_24;
        }
        iVar7 = iVar7 - (short)DAT_1007b2c4;
      }
      DAT_1007b2c8 = 0;
      if (iVar7 != 0) {
        uVar15 = (iVar7 << 0x10) / (DAT_1007b288 - DAT_1007b28c);
        DAT_1007b2c8 = (uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
      }
      uVar10 = uVar10 & 0xffff;
      uVar11 = uVar11 & 0xffff;
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iStack_24 < iVar8) {
        iVar8 = iVar8 - iStack_24;
        DAT_1007b290 = iStack_24;
        DAT_1007b2c0 = uVar18;
        FUN_1006cd50();
        DAT_1007b3ac = DAT_1007b304;
        iVar7 = iVar8 >> 1;
        if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
          iVar7 = -iVar7;
        }
        DAT_1007b3b0 = (int)(iVar7 + (DAT_1007b308 - DAT_1007b304)) / iVar8;
        _DAT_1007b3b4 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar5 = (byte)_DAT_1007b3b4;
        DAT_1007b38c = ((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b38c) / iVar8;
        DAT_1007b394 = ((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b394) / iVar8;
        DAT_1007b280 = iVar9 << 0x10;
        iVar13 = iVar13 - iVar9;
        if (iVar8 == 1) {
          DAT_1007b28c = iVar13 * 0x10000;
        }
        else if (iVar8 == 2) {
          DAT_1007b28c = iVar13 * 0x8000;
        }
        else if (((iVar8 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar6 + (iVar13 * 0x20 + iVar8) * 4);
        }
        else if (iVar13 < 0) {
          DAT_1007b28c = (iVar13 * 0x10000) / iVar8;
        }
        else {
          DAT_1007b28c = (iVar13 * 0x10000) / iVar8;
        }
        iStack_24 = iVar8;
        if (DAT_1007b43c == 0) {
          DAT_1007b2c4 = 0;
          if ((sStack_18 == sStack_1c) || (iVar8 == 1)) {
            uVar11 = uVar11 - uVar10;
          }
          else if (iVar8 == 2) {
            uVar11 = (int)(uVar11 - uVar10) >> 1;
          }
          else {
            uVar11 = (int)(uVar11 - uVar10) / iVar8;
          }
          if (uVar11 != 0) {
            DAT_1007b2c4 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
          }
        }
      }
      else {
        iStack_24 = iStack_24 - iVar8;
        DAT_1007b290 = iVar8;
        DAT_1007b2c0 = uVar18;
        FUN_1006cd50();
        if (iStack_24 == 0) {
          return;
        }
        DAT_1007b3c0 = DAT_1007b308;
        iVar7 = iStack_24 >> 1;
        if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
          iVar7 = -iVar7;
        }
        DAT_1007b3c4 = (int)(iVar7 + (DAT_1007b304 - DAT_1007b308)) / iStack_24;
        _DAT_1007b3c8 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar5 = (byte)_DAT_1007b3c8;
        DAT_1007b39c = ((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b39c) / iStack_24;
        DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b3a4) / iStack_24;
        DAT_1007b284 = iVar13 << 0x10;
        iVar9 = iVar9 - iVar13;
        if (iStack_24 == 1) {
          DAT_1007b288 = iVar9 * 0x10000;
        }
        else if (iStack_24 == 2) {
          DAT_1007b288 = iVar9 * 0x8000;
        }
        else if (((iStack_24 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar6 + (iVar9 * 0x20 + iStack_24) * 4);
        }
        else if (iVar9 < 0) {
          DAT_1007b288 = (iVar9 * 0x10000) / iStack_24;
        }
        else {
          DAT_1007b288 = (iVar9 * 0x10000) / iStack_24;
        }
        if (DAT_1007b43c != 0) {
          DAT_1007b2c4 = 0;
          if ((sStack_18 == sStack_1c) || (iStack_24 == 1)) {
            uVar10 = uVar10 - uVar11;
          }
          else if (iStack_24 == 2) {
            uVar10 = (int)(uVar10 - uVar11) >> 1;
          }
          else {
            uVar10 = (int)(uVar10 - uVar11) / iStack_24;
          }
          if (uVar10 != 0) {
            DAT_1007b2c4 = (uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
          }
        }
      }
      goto LAB_1001ef2d;
    }
    iVar8 = iVar13 - DAT_1007b280;
    if (iVar8 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2b4 = DAT_10075220;
      DAT_1007b3ac = DAT_1007b300;
      return;
    }
    iVar9 = iVar9 - iVar13;
    if (iStack_24 == 1) {
      DAT_1007b288 = iVar9 * 0x10000;
    }
    else if (iStack_24 == 2) {
      DAT_1007b288 = iVar9 * 0x8000;
    }
    else if (((iStack_24 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar6 + (iVar9 * 0x20 + iStack_24) * 4);
    }
    else if (iVar9 < 0) {
      DAT_1007b288 = (iVar9 * 0x10000) / iStack_24;
    }
    else {
      DAT_1007b288 = (iVar9 * 0x10000) / iStack_24;
    }
    DAT_1007b3c0 = DAT_1007b308;
    if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
      iVar7 = -iVar7;
    }
    DAT_1007b3c4 = (int)((DAT_1007b304 - DAT_1007b308) + iVar7) / iStack_24;
    _DAT_1007b3c8 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3c8;
    DAT_1007b39c = ((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
    DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar5 & 0x1f)) * uVar15 - DAT_1007b39c) / iStack_24;
    DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
    DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar5 & 0x1f)) * uVar15 - DAT_1007b3a4) / iStack_24;
    if (DAT_1007b43c == 0) {
      uVar11 = uVar11 & 0xffff;
      if ((sStack_18 == sVar17) || (iVar8 == 1)) {
        uVar11 = uVar11 - (uVar18 & 0xffff);
      }
      else if (iVar8 == 2) {
        uVar11 = (int)(uVar11 - (uVar18 & 0xffff)) >> 1;
      }
      else {
        uVar11 = (int)(uVar11 - (uVar18 & 0xffff)) / iVar8;
      }
      uVar15 = uVar18 & 0xffff;
      DAT_1007b2c8 = (uVar11 & 0xffff) + (uVar11 & 0x8000) * -2;
      DAT_1007b2c0 = uVar18;
      if ((sStack_1c == sVar17) || (iStack_24 == 1)) goto LAB_1001ea71;
      if (iStack_24 == 2) {
        uVar15 = (int)((uVar10 & 0xffff) - uVar15) >> 1;
      }
      else {
        uVar15 = (int)((uVar10 & 0xffff) - uVar15) / iStack_24;
      }
    }
    else {
      if ((sStack_18 == sVar17) || (iVar8 == 1)) {
        uVar18 = (uVar18 & 0xffff) - (uVar11 & 0xffff);
      }
      else if (iVar8 == 2) {
        uVar18 = (int)((uVar18 & 0xffff) - (uVar11 & 0xffff)) >> 1;
      }
      else {
        uVar18 = (int)((uVar18 & 0xffff) - (uVar11 & 0xffff)) / iVar8;
      }
      uVar15 = uVar11 & 0xffff;
      DAT_1007b2c8 = (uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
      DAT_1007b2c0 = uVar11;
      if ((sStack_18 == sStack_1c) || (iStack_24 == 1)) {
LAB_1001ea71:
        uVar15 = (uVar10 & 0xffff) - uVar15;
      }
      else if (iStack_24 == 2) {
        uVar15 = (int)((uVar10 & 0xffff) - uVar15) >> 1;
      }
      else {
        uVar15 = (int)((uVar10 & 0xffff) - uVar15) / iStack_24;
      }
    }
    DAT_1007b2c4 = (uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
    DAT_1007b280 = DAT_1007b280 << 0x10;
    DAT_1007b284 = iVar13 << 0x10;
    goto LAB_1001ef2d;
  }
  iVar7 = DAT_1007b280 - iVar9;
  if (iVar7 < 1) {
    DAT_1007b298 = DAT_10077da4;
    DAT_1007b2b4 = DAT_10075220;
    return;
  }
  iStack_24 = -((int)sVar1 - (int)sVar2);
  if (iStack_24 == 0) {
    DAT_1007b298 = DAT_10077da4;
    DAT_1007b2b4 = DAT_10075220;
    return;
  }
  DAT_1007b3ac = DAT_1007b304;
  iVar8 = iStack_24 >> 1;
  iVar3 = iVar8;
  if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
    iVar3 = -iVar8;
  }
  DAT_1007b3b0 = (int)((DAT_1007b308 - DAT_1007b304) + iVar3) / iStack_24;
  _DAT_1007b3b4 =
       (char)(&DAT_1007b7d0)
             [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
  uVar15 = DAT_1007b308 >> 0x10;
  bVar5 = (byte)_DAT_1007b3b4;
  DAT_1007b38c = ((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
  DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * uVar15 - DAT_1007b38c) / iStack_24;
  DAT_1007b394 = ((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
  DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * uVar15 - DAT_1007b394) / iStack_24;
  DAT_1007b3c0 = DAT_1007b300;
  if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
    iVar8 = -iVar8;
  }
  DAT_1007b3c4 = (int)((DAT_1007b308 - DAT_1007b300) + iVar8) / iStack_24;
  _DAT_1007b3c8 =
       (char)(&DAT_1007b7d0)
             [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
  bVar5 = (byte)_DAT_1007b3c8;
  DAT_1007b39c = ((int)DAT_1007b30c >> (bVar5 & 0x1f)) * (DAT_1007b300 >> 0x10);
  DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * uVar15 - DAT_1007b39c) / iStack_24;
  DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar5 & 0x1f)) * (DAT_1007b300 >> 0x10);
  DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * uVar15 - DAT_1007b3a4) / iStack_24;
  iVar8 = iVar13 - iVar9;
  if (iStack_24 == 1) {
    DAT_1007b28c = iVar8 * 0x10000;
  }
  else if (iStack_24 == 2) {
    DAT_1007b28c = iVar8 * 0x8000;
  }
  else if (((iStack_24 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
    DAT_1007b28c = *(int *)(iVar6 + (iVar8 * 0x20 + iStack_24) * 4);
  }
  else if (iVar8 < 0) {
    DAT_1007b28c = (iVar8 * 0x10000) / iStack_24;
  }
  else {
    DAT_1007b28c = (iVar8 * 0x10000) / iStack_24;
  }
  iVar13 = iVar13 - DAT_1007b280;
  if (iStack_24 == 1) {
    DAT_1007b288 = iVar13 * 0x10000;
  }
  else if (iStack_24 == 2) {
    DAT_1007b288 = iVar13 * 0x8000;
  }
  else if (((iStack_24 < 0x20) && (-0x20 < iVar13)) && (iVar13 < 0x20)) {
    DAT_1007b288 = *(int *)(iVar6 + (iVar13 * 0x20 + iStack_24) * 4);
  }
  else if (iVar13 < 0) {
    DAT_1007b288 = (iVar13 * 0x10000) / iStack_24;
  }
  else {
    DAT_1007b288 = (iVar13 * 0x10000) / iStack_24;
  }
  if (DAT_1007b43c == 0) {
    uVar15 = uVar10 & 0xffff;
    uVar18 = uVar18 & 0xffff;
    if ((sStack_1c == sVar17) || (iVar7 == 1)) {
      uVar18 = uVar18 - uVar15;
    }
    else if (iVar7 == 2) {
      uVar18 = (int)(uVar18 - uVar15) >> 1;
    }
    else {
      uVar18 = (int)(uVar18 - uVar15) / iVar7;
    }
    DAT_1007b2c8 = (uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
    DAT_1007b2c0 = uVar10;
    if ((sStack_18 == sStack_1c) || (iStack_24 == 1)) goto LAB_1001eeee;
    if (iStack_24 == 2) {
      uVar15 = (int)((uVar11 & 0xffff) - uVar15) >> 1;
    }
    else {
      uVar15 = (int)((uVar11 & 0xffff) - uVar15) / iStack_24;
    }
  }
  else {
    uVar10 = uVar10 & 0xffff;
    if ((sStack_1c == sVar17) || (iVar7 == 1)) {
      uVar10 = uVar10 - (uVar18 & 0xffff);
    }
    else if (iVar7 == 2) {
      uVar10 = (int)(uVar10 - (uVar18 & 0xffff)) >> 1;
    }
    else {
      uVar10 = (int)(uVar10 - (uVar18 & 0xffff)) / iVar7;
    }
    uVar15 = uVar18 & 0xffff;
    DAT_1007b2c8 = (uVar10 & 0xffff) + (uVar10 & 0x8000) * -2;
    DAT_1007b2c0 = uVar18;
    if ((sStack_18 == sVar17) || (iStack_24 == 1)) {
LAB_1001eeee:
      uVar15 = (uVar11 & 0xffff) - uVar15;
    }
    else if (iStack_24 == 2) {
      uVar15 = (int)((uVar11 & 0xffff) - uVar15) >> 1;
    }
    else {
      uVar15 = (int)((uVar11 & 0xffff) - uVar15) / iStack_24;
    }
  }
  DAT_1007b2c4 = (uVar15 & 0xffff) + (uVar15 & 0x8000) * -2;
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar9 << 0x10;
LAB_1001ef2d:
  DAT_1007b290 = iStack_24;
  FUN_1006cd50();
  return;
}


