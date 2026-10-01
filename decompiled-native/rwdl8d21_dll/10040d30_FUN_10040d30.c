// 10040d30 FUN_10040d30 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10040d30(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  bool bVar4;
  byte bVar5;
  undefined3 extraout_var;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  short sVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int local_30;
  short local_1c;
  short local_18;
  
  iVar7 = param_2;
  iVar16 = param_3;
  iVar9 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar7 = param_4;
      iVar16 = param_2;
      iVar9 = param_3;
    }
LAB_10040d77:
    param_3 = iVar7;
    param_4 = iVar16;
    param_2 = iVar9;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10040d77;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar11 = (int)sVar1 - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  iVar7 = *(int *)(param_2 + 0x58);
  iVar16 = *(int *)(param_2 + 0x20);
  uVar20 = iVar7 >> 8;
  iVar17 = (int)*(short *)(param_3 + 0x1a);
  iVar21 = (int)*(short *)(param_4 + 0x1a);
  iVar9 = *(int *)(param_3 + 0x58);
  uVar12 = iVar9 >> 8;
  iVar3 = *(int *)(param_3 + 0x20);
  iVar10 = *(int *)(param_4 + 0x58);
  iVar15 = *(int *)(param_4 + 0x20);
  uVar13 = iVar10 >> 8;
  DAT_1007b30c = *(int *)(param_2 + 100) >> 3;
  DAT_1007b310 = *(int *)(param_2 + 0x68) >> 3;
  DAT_1007b314 = *(int *)(param_3 + 100) >> 3;
  DAT_1007b31c = *(int *)(param_4 + 100) >> 3;
  DAT_1007b318 = *(int *)(param_3 + 0x68) >> 3;
  DAT_1007b320 = *(int *)(param_4 + 0x68) >> 3;
  _DAT_1007b324 = *(float *)(param_2 + 0x14);
  _DAT_1007b328 = *(float *)(param_3 + 0x14);
  _DAT_1007b32c = *(float *)(param_4 + 0x14);
  DAT_1007b330 = _DAT_1007b32c * _DAT_1007b328;
  DAT_1007b334 = _DAT_1007b32c * _DAT_1007b324;
  DAT_1007b338 = _DAT_1007b324 * _DAT_1007b328;
  fVar18 = DAT_1007b334;
  if ((int)DAT_1007b334 < (int)DAT_1007b330) {
    fVar18 = DAT_1007b330;
  }
  if ((int)fVar18 <= (int)DAT_1007b338) {
    fVar18 = DAT_1007b338;
  }
  _DAT_1007b33c = (int)fVar18 >> 0x17;
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
  DAT_1007b43c = (uint)(CONCAT31(extraout_var,bVar4) == 0);
  DAT_1007b2b4 = DAT_10075220;
  DAT_1007b2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2a0 = DAT_10077eb0;
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar6 = DAT_10075214 + 0x1000;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  iVar14 = DAT_10075228;
  if (DAT_1007b43c != 0) {
    iVar14 = DAT_10075230;
  }
  _DAT_1007b2a4 = *(undefined4 *)(iVar14 + (DAT_1007b284 & 7) * 4);
  sVar19 = (short)((uint)iVar7 >> 8);
  local_1c = (short)((uint)iVar9 >> 8);
  local_18 = (short)((uint)iVar10 >> 8);
  if (iVar11 < 1) {
    iVar7 = DAT_1007b280 - iVar17;
    if (iVar7 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      DAT_1007b2b4 = DAT_10075220;
      return;
    }
    local_30 = -((int)sVar1 - (int)sVar2);
    if (local_30 == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      DAT_1007b2b4 = DAT_10075220;
      return;
    }
    DAT_1007b3ac = DAT_1007b304;
    iVar9 = local_30 >> 1;
    iVar10 = iVar9;
    if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
      iVar10 = -iVar9;
    }
    DAT_1007b3b0 = (int)((DAT_1007b308 - DAT_1007b304) + iVar10) / local_30;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3b4;
    DAT_1007b38c = ((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
    uVar8 = DAT_1007b308 >> 0x10;
    DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * uVar8 - DAT_1007b38c) / local_30;
    DAT_1007b394 = ((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
    DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * uVar8 - DAT_1007b394) / local_30;
    DAT_1007b3c0 = DAT_1007b300;
    if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
      iVar9 = -iVar9;
    }
    DAT_1007b3c4 = (int)((DAT_1007b308 - DAT_1007b300) + iVar9) / local_30;
    _DAT_1007b3c8 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3c8;
    DAT_1007b39c = ((int)DAT_1007b30c >> (bVar5 & 0x1f)) * (DAT_1007b300 >> 0x10);
    DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * uVar8 - DAT_1007b39c) / local_30;
    DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar5 & 0x1f)) * (DAT_1007b300 >> 0x10);
    DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * uVar8 - DAT_1007b3a4) / local_30;
    iVar9 = iVar21 - iVar17;
    if (local_30 == 1) {
      DAT_1007b28c = iVar9 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007b28c = iVar9 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar9)) && (iVar9 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar6 + (iVar9 * 0x20 + local_30) * 4);
    }
    else if (iVar9 < 0) {
      DAT_1007b28c = (iVar9 * 0x10000) / local_30;
    }
    else {
      DAT_1007b28c = (iVar9 * 0x10000) / local_30;
    }
    iVar21 = iVar21 - DAT_1007b280;
    if (local_30 == 1) {
      DAT_1007b288 = iVar21 * 0x10000;
    }
    else if (local_30 == 2) {
      DAT_1007b288 = iVar21 * 0x8000;
    }
    else if (((local_30 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar6 + (iVar21 * 0x20 + local_30) * 4);
    }
    else if (iVar21 < 0) {
      DAT_1007b288 = (iVar21 * 0x10000) / local_30;
    }
    else {
      DAT_1007b288 = (iVar21 * 0x10000) / local_30;
    }
    if (DAT_1007b43c == 0) {
      if ((iVar3 == iVar16) || (iVar7 == 1)) {
        DAT_1007b2ec = iVar16 - iVar3;
      }
      else if (iVar7 == 2) {
        DAT_1007b2ec = iVar16 - iVar3 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar16 - iVar3) / iVar7;
      }
      iVar16 = iVar3;
      if ((iVar15 == iVar3) || (local_30 == 1)) {
        DAT_1007b2e8 = iVar15 - iVar3;
      }
      else if (local_30 == 2) {
        DAT_1007b2e8 = iVar15 - iVar3 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar15 - iVar3) / local_30;
      }
    }
    else {
      if ((iVar3 == iVar16) || (iVar7 == 1)) {
        DAT_1007b2ec = iVar3 - iVar16;
      }
      else if (iVar7 == 2) {
        DAT_1007b2ec = iVar3 - iVar16 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar3 - iVar16) / iVar7;
      }
      if ((iVar15 == iVar16) || (local_30 == 1)) {
        DAT_1007b2e8 = iVar15 - iVar16;
      }
      else if (local_30 == 2) {
        DAT_1007b2e8 = iVar15 - iVar16 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar15 - iVar16) / local_30;
      }
    }
    if (DAT_1007b43c == 0) {
      uVar8 = uVar12 & 0xffff;
      uVar20 = uVar20 & 0xffff;
      if ((local_1c == sVar19) || (iVar7 == 1)) {
        uVar20 = uVar20 - uVar8;
      }
      else if (iVar7 == 2) {
        uVar20 = (int)(uVar20 - uVar8) >> 1;
      }
      else {
        uVar20 = (int)(uVar20 - uVar8) / iVar7;
      }
      DAT_1007b2c8 = (uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
      DAT_1007b2c0 = uVar12;
      if ((local_1c == local_18) || (local_30 == 1)) goto LAB_1004259c;
      if (local_30 == 2) {
        uVar8 = (int)((uVar13 & 0xffff) - uVar8) >> 1;
      }
      else {
        uVar8 = (int)((uVar13 & 0xffff) - uVar8) / local_30;
      }
    }
    else {
      uVar12 = uVar12 & 0xffff;
      if ((local_1c == sVar19) || (iVar7 == 1)) {
        uVar12 = uVar12 - (uVar20 & 0xffff);
      }
      else if (iVar7 == 2) {
        uVar12 = (int)(uVar12 - (uVar20 & 0xffff)) >> 1;
      }
      else {
        uVar12 = (int)(uVar12 - (uVar20 & 0xffff)) / iVar7;
      }
      uVar8 = uVar20 & 0xffff;
      DAT_1007b2c8 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
      DAT_1007b2c0 = uVar20;
      if ((sVar19 == local_18) || (local_30 == 1)) {
LAB_1004259c:
        uVar8 = (uVar13 & 0xffff) - uVar8;
      }
      else if (local_30 == 2) {
        uVar8 = (int)((uVar13 & 0xffff) - uVar8) >> 1;
      }
      else {
        uVar8 = (int)((uVar13 & 0xffff) - uVar8) / local_30;
      }
    }
    DAT_1007b2c4 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    DAT_1007b2e4 = iVar16;
  }
  else {
    iVar7 = iVar17 - DAT_1007b280;
    if (iVar11 == 1) {
      DAT_1007b28c = iVar7 * 0x10000;
    }
    else if (iVar11 == 2) {
      DAT_1007b28c = iVar7 * 0x8000;
    }
    else if (((iVar11 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar6 + (iVar7 * 0x20 + iVar11) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1007b28c = (iVar7 * 0x10000) / iVar11;
    }
    else {
      DAT_1007b28c = (iVar7 * 0x10000) / iVar11;
    }
    DAT_1007b3ac = DAT_1007b300;
    iVar7 = iVar11 >> 1;
    iVar9 = iVar7;
    if ((int)(DAT_1007b304 - DAT_1007b300) < 0) {
      iVar9 = -iVar7;
    }
    DAT_1007b3b0 = (int)((DAT_1007b304 - DAT_1007b300) + iVar9) / iVar11;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b310 | DAT_1007b314 | DAT_1007b318 | DAT_1007b30c) >> 0x10] + 1;
    uVar8 = DAT_1007b300 >> 0x10;
    DAT_1007b38c = ((int)DAT_1007b30c >> (DAT_1007b3b4 & 0x1f)) * uVar8;
    uVar22 = DAT_1007b304 >> 0x10;
    DAT_1007b390 = (int)(((int)DAT_1007b314 >> (DAT_1007b3b4 & 0x1f)) * uVar22 - DAT_1007b38c) /
                   iVar11;
    DAT_1007b394 = ((int)DAT_1007b310 >> (DAT_1007b3b4 & 0x1f)) * uVar8;
    DAT_1007b398 = (int)(((int)DAT_1007b318 >> (DAT_1007b3b4 & 0x1f)) * uVar22 - DAT_1007b394) /
                   iVar11;
    iVar9 = (int)sVar2 - DAT_1007b284;
    if (0 < iVar9) {
      iVar7 = iVar21 - DAT_1007b280;
      if (iVar9 == 1) {
        DAT_1007b288 = iVar7 * 0x10000;
      }
      else if (iVar9 == 2) {
        DAT_1007b288 = iVar7 * 0x8000;
      }
      else if (((iVar9 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar6 + (iVar7 * 0x20 + iVar9) * 4);
      }
      else if (iVar7 < 0) {
        DAT_1007b288 = (iVar7 * 0x10000) / iVar9;
      }
      else {
        DAT_1007b288 = (iVar7 * 0x10000) / iVar9;
      }
      iVar7 = DAT_1007b288 - DAT_1007b28c;
      if (iVar7 < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        DAT_1007b2b4 = DAT_10075220;
        DAT_1007b3ac = DAT_1007b300;
        return;
      }
      DAT_1007b3c0 = DAT_1007b300;
      iVar10 = iVar9 >> 1;
      if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
        iVar10 = -iVar10;
      }
      DAT_1007b3c4 = (int)(iVar10 + (DAT_1007b308 - DAT_1007b300)) / iVar9;
      _DAT_1007b3c8 =
           (char)(&DAT_1007b7d0)
                 [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
      bVar5 = (byte)_DAT_1007b3c8;
      DAT_1007b39c = ((int)DAT_1007b30c >> (bVar5 & 0x1f)) * uVar8;
      DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b39c) / iVar9;
      DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar5 & 0x1f)) * uVar8;
      DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b3a4) / iVar9;
      if (DAT_1007b43c == 0) {
        if ((local_1c == sVar19) || (iVar11 == 1)) {
          uVar8 = (uVar12 & 0xffff) - (uVar20 & 0xffff);
        }
        else if (iVar11 == 2) {
          uVar8 = (int)((uVar12 & 0xffff) - (uVar20 & 0xffff)) >> 1;
        }
        else {
          uVar8 = (int)((uVar12 & 0xffff) - (uVar20 & 0xffff)) / iVar11;
        }
        uVar22 = uVar20 & 0xffff;
        DAT_1007b2c4 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
        if ((sVar19 == local_18) || (iVar9 == 1)) {
          iVar10 = (uVar13 & 0xffff) - uVar22;
        }
        else if (iVar9 == 2) {
          iVar10 = (int)((uVar13 & 0xffff) - uVar22) >> 1;
        }
        else {
          iVar10 = (int)((uVar13 & 0xffff) - uVar22) / iVar9;
        }
        iVar10 = iVar10 - (short)DAT_1007b2c4;
      }
      else {
        if ((sVar19 == local_18) || (iVar9 == 1)) {
          uVar8 = (uVar13 & 0xffff) - (uVar20 & 0xffff);
        }
        else if (iVar9 == 2) {
          uVar8 = (int)((uVar13 & 0xffff) - (uVar20 & 0xffff)) >> 1;
        }
        else {
          uVar8 = (int)((uVar13 & 0xffff) - (uVar20 & 0xffff)) / iVar9;
        }
        uVar22 = uVar20 & 0xffff;
        DAT_1007b2c4 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
        if ((local_1c == sVar19) || (iVar11 == 1)) {
          iVar10 = (uVar12 & 0xffff) - uVar22;
        }
        else if (iVar11 == 2) {
          iVar10 = (int)((uVar12 & 0xffff) - uVar22) >> 1;
        }
        else {
          iVar10 = (int)((uVar12 & 0xffff) - uVar22) / iVar11;
        }
        iVar10 = iVar10 - (short)DAT_1007b2c4;
      }
      DAT_1007b2c8 = 0;
      if (iVar10 != 0) {
        uVar8 = (iVar10 << 0x10) / iVar7;
        DAT_1007b2c8 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      }
      uVar12 = uVar12 & 0xffff;
      uVar13 = uVar13 & 0xffff;
      if (DAT_1007b43c == 0) {
        if ((iVar3 == iVar16) || (iVar11 == 1)) {
          DAT_1007b2e8 = iVar3 - iVar16;
        }
        else if (iVar11 == 2) {
          DAT_1007b2e8 = iVar3 - iVar16 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar3 - iVar16) / iVar11;
        }
        if ((iVar15 == iVar16) || (iVar9 == 1)) {
          iVar10 = iVar15 - iVar16;
        }
        else if (iVar9 == 2) {
          iVar10 = iVar15 - iVar16 >> 1;
        }
        else {
          iVar10 = (iVar15 - iVar16) / iVar9;
        }
        DAT_1007b2ec = iVar10 - DAT_1007b2e8;
      }
      else {
        if ((iVar15 == iVar16) || (iVar9 == 1)) {
          DAT_1007b2e8 = iVar15 - iVar16;
        }
        else if (iVar9 == 2) {
          DAT_1007b2e8 = iVar15 - iVar16 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar15 - iVar16) / iVar9;
        }
        if ((iVar3 == iVar16) || (iVar11 == 1)) {
          iVar10 = iVar3 - iVar16;
        }
        else if (iVar11 == 2) {
          iVar10 = iVar3 - iVar16 >> 1;
        }
        else {
          iVar10 = (iVar3 - iVar16) / iVar11;
        }
        DAT_1007b2ec = iVar10 - DAT_1007b2e8;
      }
      if ((DAT_1007b2ec != 0) && (iVar7 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / (iVar7 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar11 < iVar9) {
        local_30 = iVar9 - iVar11;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar16;
        DAT_1007b290 = iVar11;
        DAT_1007b2c0 = uVar20;
        FUN_10042610((uint *)&DAT_1007b280);
        DAT_1007b3ac = DAT_1007b304;
        iVar7 = local_30 >> 1;
        if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
          iVar7 = -iVar7;
        }
        DAT_1007b3b0 = (int)(iVar7 + (DAT_1007b308 - DAT_1007b304)) / local_30;
        _DAT_1007b3b4 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar5 = (byte)_DAT_1007b3b4;
        DAT_1007b38c = ((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b38c) / local_30;
        DAT_1007b394 = ((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b394) / local_30;
        DAT_1007b280 = iVar17 << 0x10;
        iVar21 = iVar21 - iVar17;
        if (local_30 == 1) {
          DAT_1007b28c = iVar21 * 0x10000;
        }
        else if (local_30 == 2) {
          DAT_1007b28c = iVar21 * 0x8000;
        }
        else if (((local_30 < 0x20) && (-0x20 < iVar21)) && (iVar21 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar6 + (iVar21 * 0x20 + local_30) * 4);
        }
        else if (iVar21 < 0) {
          DAT_1007b28c = (iVar21 * 0x10000) / local_30;
        }
        else {
          DAT_1007b28c = (iVar21 * 0x10000) / local_30;
        }
        if (DAT_1007b43c == 0) {
          DAT_1007b2c4 = 0;
          if ((local_1c == local_18) || (local_30 == 1)) {
            uVar13 = uVar13 - uVar12;
          }
          else if (local_30 == 2) {
            uVar13 = (int)(uVar13 - uVar12) >> 1;
          }
          else {
            uVar13 = (int)(uVar13 - uVar12) / local_30;
          }
          if (uVar13 != 0) {
            DAT_1007b2c4 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
          }
          if (iVar15 == iVar3) {
            DAT_1007b2e8 = iVar15 - iVar3;
          }
          else if (local_30 == 1) {
            DAT_1007b2e8 = iVar15 - iVar3;
          }
          else if (local_30 == 2) {
            DAT_1007b2e8 = iVar15 - iVar3 >> 1;
          }
          else {
            DAT_1007b2e8 = (iVar15 - iVar3) / local_30;
          }
        }
      }
      else {
        local_30 = iVar11 - iVar9;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar16;
        DAT_1007b290 = iVar9;
        DAT_1007b2c0 = uVar20;
        FUN_10042610((uint *)&DAT_1007b280);
        if (local_30 == 0) {
          return;
        }
        DAT_1007b3c0 = DAT_1007b308;
        iVar7 = local_30 >> 1;
        if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
          iVar7 = -iVar7;
        }
        DAT_1007b3c4 = (int)(iVar7 + (DAT_1007b304 - DAT_1007b308)) / local_30;
        _DAT_1007b3c8 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar5 = (byte)_DAT_1007b3c8;
        DAT_1007b39c = ((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b39c) / local_30;
        DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b3a4) / local_30;
        DAT_1007b284 = iVar21 << 0x10;
        iVar17 = iVar17 - iVar21;
        if (local_30 == 1) {
          DAT_1007b288 = iVar17 * 0x10000;
        }
        else if (local_30 == 2) {
          DAT_1007b288 = iVar17 * 0x8000;
        }
        else if (((local_30 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar6 + (iVar17 * 0x20 + local_30) * 4);
        }
        else if (iVar17 < 0) {
          DAT_1007b288 = (iVar17 * 0x10000) / local_30;
        }
        else {
          DAT_1007b288 = (iVar17 * 0x10000) / local_30;
        }
        if (DAT_1007b43c != 0) {
          DAT_1007b2c4 = 0;
          if ((local_1c == local_18) || (local_30 == 1)) {
            uVar12 = uVar12 - uVar13;
          }
          else if (local_30 == 2) {
            uVar12 = (int)(uVar12 - uVar13) >> 1;
          }
          else {
            uVar12 = (int)(uVar12 - uVar13) / local_30;
          }
          if (uVar12 != 0) {
            DAT_1007b2c4 = (uVar12 & 0xffff) + (uVar12 & 0x8000) * -2;
          }
          if (DAT_1007b43c != 0) {
            if (iVar15 == iVar3) {
              DAT_1007b2e8 = iVar3 - iVar15;
            }
            else if (local_30 == 1) {
              DAT_1007b2e8 = iVar3 - iVar15;
            }
            else if (local_30 == 2) {
              DAT_1007b2e8 = iVar3 - iVar15 >> 1;
            }
            else {
              DAT_1007b2e8 = (iVar3 - iVar15) / local_30;
            }
          }
        }
      }
      goto LAB_100425ef;
    }
    iVar9 = iVar21 - DAT_1007b280;
    if (iVar9 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      DAT_1007b2b4 = DAT_10075220;
      DAT_1007b3ac = DAT_1007b300;
      return;
    }
    iVar17 = iVar17 - iVar21;
    if (iVar11 == 1) {
      DAT_1007b288 = iVar17 * 0x10000;
    }
    else if (iVar11 == 2) {
      DAT_1007b288 = iVar17 * 0x8000;
    }
    else if (((iVar11 < 0x20) && (-0x20 < iVar17)) && (iVar17 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar6 + (iVar17 * 0x20 + iVar11) * 4);
    }
    else if (iVar17 < 0) {
      DAT_1007b288 = (iVar17 * 0x10000) / iVar11;
    }
    else {
      DAT_1007b288 = (iVar17 * 0x10000) / iVar11;
    }
    DAT_1007b3c0 = DAT_1007b308;
    if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
      iVar7 = -iVar7;
    }
    DAT_1007b3c4 = (int)((DAT_1007b304 - DAT_1007b308) + iVar7) / iVar11;
    _DAT_1007b3c8 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3c8;
    DAT_1007b39c = ((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
    DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar5 & 0x1f)) * uVar22 - DAT_1007b39c) / iVar11;
    DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
    DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar5 & 0x1f)) * uVar22 - DAT_1007b3a4) / iVar11;
    if (DAT_1007b43c == 0) {
      if ((iVar15 == iVar16) || (iVar9 == 1)) {
        DAT_1007b2ec = iVar15 - iVar16;
      }
      else if (iVar9 == 2) {
        DAT_1007b2ec = iVar15 - iVar16 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar15 - iVar16) / iVar9;
      }
      iVar15 = iVar16;
      if ((iVar3 == iVar16) || (iVar11 == 1)) {
        DAT_1007b2e8 = iVar3 - iVar16;
      }
      else if (iVar11 == 2) {
        DAT_1007b2e8 = iVar3 - iVar16 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar3 - iVar16) / iVar11;
      }
    }
    else {
      if ((iVar15 == iVar16) || (iVar9 == 1)) {
        DAT_1007b2ec = iVar16 - iVar15;
      }
      else if (iVar9 == 2) {
        DAT_1007b2ec = iVar16 - iVar15 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar16 - iVar15) / iVar9;
      }
      if ((iVar15 == iVar3) || (iVar11 == 1)) {
        DAT_1007b2e8 = iVar3 - iVar15;
      }
      else if (iVar11 == 2) {
        DAT_1007b2e8 = iVar3 - iVar15 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar3 - iVar15) / iVar11;
      }
    }
    if (DAT_1007b43c == 0) {
      uVar13 = uVar13 & 0xffff;
      if ((sVar19 == local_18) || (iVar9 == 1)) {
        uVar13 = uVar13 - (uVar20 & 0xffff);
      }
      else if (iVar9 == 2) {
        uVar13 = (int)(uVar13 - (uVar20 & 0xffff)) >> 1;
      }
      else {
        uVar13 = (int)(uVar13 - (uVar20 & 0xffff)) / iVar9;
      }
      uVar8 = uVar20 & 0xffff;
      DAT_1007b2c8 = (uVar13 & 0xffff) + (uVar13 & 0x8000) * -2;
      DAT_1007b2c0 = uVar20;
      if ((local_1c == sVar19) || (iVar11 == 1)) goto LAB_10042021;
      if (iVar11 == 2) {
        uVar8 = (int)((uVar12 & 0xffff) - uVar8) >> 1;
      }
      else {
        uVar8 = (int)((uVar12 & 0xffff) - uVar8) / iVar11;
      }
    }
    else {
      if ((sVar19 == local_18) || (iVar9 == 1)) {
        uVar20 = (uVar20 & 0xffff) - (uVar13 & 0xffff);
      }
      else if (iVar9 == 2) {
        uVar20 = (int)((uVar20 & 0xffff) - (uVar13 & 0xffff)) >> 1;
      }
      else {
        uVar20 = (int)((uVar20 & 0xffff) - (uVar13 & 0xffff)) / iVar9;
      }
      uVar8 = uVar13 & 0xffff;
      DAT_1007b2c8 = (uVar20 & 0xffff) + (uVar20 & 0x8000) * -2;
      DAT_1007b2c0 = uVar13;
      if ((local_1c == local_18) || (iVar11 == 1)) {
LAB_10042021:
        uVar8 = (uVar12 & 0xffff) - uVar8;
      }
      else if (iVar11 == 2) {
        uVar8 = (int)((uVar12 & 0xffff) - uVar8) >> 1;
      }
      else {
        uVar8 = (int)((uVar12 & 0xffff) - uVar8) / iVar11;
      }
    }
    DAT_1007b2c4 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
    DAT_1007b2e4 = iVar15;
    local_30 = iVar11;
    iVar17 = DAT_1007b280;
    DAT_1007b280 = iVar21;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar17 << 0x10;
  DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2f0;
LAB_100425ef:
  DAT_1007b290 = local_30;
  FUN_10042610((uint *)&DAT_1007b280);
  return;
}


