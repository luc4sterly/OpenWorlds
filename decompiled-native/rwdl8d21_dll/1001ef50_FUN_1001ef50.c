// 1001ef50 FUN_1001ef50 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ef50(int *param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined3 extraout_var;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float fVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  short sVar20;
  uint uVar21;
  uint uVar22;
  int local_2c;
  short local_18;
  short local_14;
  char local_10;
  
  iVar10 = param_3;
  iVar14 = param_4;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar10 = param_2;
      param_2 = param_4;
      iVar14 = param_3;
    }
LAB_1001ef96:
    param_3 = param_2;
    param_4 = iVar10;
    param_2 = iVar14;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001ef96;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(param_3 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar6 = (int)sVar1 - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  iVar10 = *(int *)(param_2 + 0x58);
  iVar14 = *(int *)(param_2 + 0x20);
  uVar21 = iVar10 >> 8;
  iVar15 = (int)*(short *)(param_3 + 0x1a);
  iVar19 = (int)*(short *)(param_4 + 0x1a);
  iVar11 = *(int *)(param_3 + 0x58);
  uVar7 = iVar11 >> 8;
  iVar3 = *(int *)(param_3 + 0x20);
  iVar12 = *(int *)(param_4 + 0x58);
  iVar13 = *(int *)(param_4 + 0x20);
  uVar8 = iVar12 >> 8;
  DAT_1007b30c = *(uint *)(param_2 + 100);
  DAT_1007b310 = *(uint *)(param_2 + 0x68);
  DAT_1007b314 = *(uint *)(param_3 + 100);
  DAT_1007b318 = *(uint *)(param_3 + 0x68);
  DAT_1007b320 = *(uint *)(param_4 + 0x68);
  DAT_1007b31c = *(uint *)(param_4 + 100);
  _DAT_1007b324 = *(float *)(param_2 + 0x14);
  _DAT_1007b328 = *(float *)(param_3 + 0x14);
  _DAT_1007b32c = *(float *)(param_4 + 0x14);
  DAT_1007b330 = _DAT_1007b32c * _DAT_1007b328;
  DAT_1007b334 = _DAT_1007b32c * _DAT_1007b324;
  DAT_1007b338 = _DAT_1007b324 * _DAT_1007b328;
  fVar16 = DAT_1007b334;
  if ((int)DAT_1007b334 < (int)DAT_1007b330) {
    fVar16 = DAT_1007b330;
  }
  if ((int)fVar16 <= (int)DAT_1007b338) {
    fVar16 = DAT_1007b338;
  }
  _DAT_1007b33c = (int)fVar16 >> 0x17;
  local_10 = (char)((int)DAT_1007b330 >> 0x17);
  DAT_1007b300 = ((int)((uint)DAT_1007b330 & 0x7fffff | 0x800000) >>
                 ((char)_DAT_1007b33c - local_10 & 0x1fU)) << 7;
  DAT_1007b304 = ((int)((uint)DAT_1007b334 & 0x7fffff | 0x800000) >>
                 ((char)_DAT_1007b33c - (char)((int)DAT_1007b334 >> 0x17) & 0x1fU)) << 7;
  _DAT_1007b340 = _DAT_1007b33c - ((int)DAT_1007b338 >> 0x17);
  DAT_1007b308 = ((int)((uint)DAT_1007b338 & 0x7fffff | 0x800000) >> (DAT_1007b340 & 0x1f)) << 7;
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
  iVar9 = DAT_10075214 + 0x1000;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  iVar17 = DAT_10075228;
  if (DAT_1007b43c != 0) {
    iVar17 = DAT_10075230;
  }
  _DAT_1007b2a4 = *(undefined4 *)(iVar17 + (DAT_1007b284 & 7) * 4);
  sVar20 = (short)((uint)iVar10 >> 8);
  local_18 = (short)((uint)iVar11 >> 8);
  local_14 = (short)((uint)iVar12 >> 8);
  if (iVar6 < 1) {
    iVar10 = DAT_1007b280 - iVar15;
    if (iVar10 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      DAT_1007b2b4 = DAT_10075220;
      return;
    }
    local_2c = -((int)sVar1 - (int)sVar2);
    if (local_2c == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      DAT_1007b2b4 = DAT_10075220;
      return;
    }
    DAT_1007b3ac = DAT_1007b304;
    iVar11 = local_2c >> 1;
    iVar12 = iVar11;
    if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
      iVar12 = -iVar11;
    }
    DAT_1007b3b0 = (int)((DAT_1007b308 - DAT_1007b304) + iVar12) / local_2c;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3b4;
    DAT_1007b38c = ((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
    uVar18 = DAT_1007b308 >> 0x10;
    DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * uVar18 - DAT_1007b38c) / local_2c;
    DAT_1007b394 = ((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
    DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * uVar18 - DAT_1007b394) / local_2c;
    DAT_1007b3c0 = DAT_1007b300;
    if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
      iVar11 = -iVar11;
    }
    DAT_1007b3c4 = (int)((DAT_1007b308 - DAT_1007b300) + iVar11) / local_2c;
    _DAT_1007b3c8 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3c8;
    DAT_1007b39c = ((int)DAT_1007b30c >> (bVar5 & 0x1f)) * (DAT_1007b300 >> 0x10);
    DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * uVar18 - DAT_1007b39c) / local_2c;
    DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar5 & 0x1f)) * (DAT_1007b300 >> 0x10);
    DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * uVar18 - DAT_1007b3a4) / local_2c;
    iVar11 = iVar19 - iVar15;
    if (local_2c == 1) {
      DAT_1007b28c = iVar11 * 0x10000;
    }
    else if (local_2c == 2) {
      DAT_1007b28c = iVar11 * 0x8000;
    }
    else if (((local_2c < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar9 + (iVar11 * 0x20 + local_2c) * 4);
    }
    else if (iVar11 < 0) {
      DAT_1007b28c = (iVar11 * 0x10000) / local_2c;
    }
    else {
      DAT_1007b28c = (iVar11 * 0x10000) / local_2c;
    }
    iVar19 = iVar19 - DAT_1007b280;
    if (local_2c == 1) {
      DAT_1007b288 = iVar19 * 0x10000;
    }
    else if (local_2c == 2) {
      DAT_1007b288 = iVar19 * 0x8000;
    }
    else if (((local_2c < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar9 + (iVar19 * 0x20 + local_2c) * 4);
    }
    else if (iVar19 < 0) {
      DAT_1007b288 = (iVar19 * 0x10000) / local_2c;
    }
    else {
      DAT_1007b288 = (iVar19 * 0x10000) / local_2c;
    }
    if (DAT_1007b43c == 0) {
      if ((iVar3 == iVar14) || (iVar10 == 1)) {
        DAT_1007b2ec = iVar14 - iVar3;
      }
      else if (iVar10 == 2) {
        DAT_1007b2ec = iVar14 - iVar3 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar14 - iVar3) / iVar10;
      }
      iVar14 = iVar3;
      if ((iVar3 == iVar13) || (local_2c == 1)) {
        DAT_1007b2e8 = iVar13 - iVar3;
      }
      else if (local_2c == 2) {
        DAT_1007b2e8 = iVar13 - iVar3 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar13 - iVar3) / local_2c;
      }
    }
    else {
      if ((iVar3 == iVar14) || (iVar10 == 1)) {
        DAT_1007b2ec = iVar3 - iVar14;
      }
      else if (iVar10 == 2) {
        DAT_1007b2ec = iVar3 - iVar14 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar3 - iVar14) / iVar10;
      }
      if ((iVar14 == iVar13) || (local_2c == 1)) {
        DAT_1007b2e8 = iVar13 - iVar14;
      }
      else if (local_2c == 2) {
        DAT_1007b2e8 = iVar13 - iVar14 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar13 - iVar14) / local_2c;
      }
    }
    if (DAT_1007b43c == 0) {
      uVar18 = uVar7 & 0xffff;
      uVar21 = uVar21 & 0xffff;
      if ((local_18 == sVar20) || (iVar10 == 1)) {
        uVar21 = uVar21 - uVar18;
      }
      else if (iVar10 == 2) {
        uVar21 = (int)(uVar21 - uVar18) >> 1;
      }
      else {
        uVar21 = (int)(uVar21 - uVar18) / iVar10;
      }
      DAT_1007b2c8 = (uVar21 & 0xffff) + (uVar21 & 0x8000) * -2;
      DAT_1007b2c0 = uVar7;
      if ((local_14 == local_18) || (local_2c == 1)) goto LAB_1002078c;
      if (local_2c == 2) {
        uVar18 = (int)((uVar8 & 0xffff) - uVar18) >> 1;
      }
      else {
        uVar18 = (int)((uVar8 & 0xffff) - uVar18) / local_2c;
      }
    }
    else {
      uVar7 = uVar7 & 0xffff;
      if ((local_18 == sVar20) || (iVar10 == 1)) {
        uVar7 = uVar7 - (uVar21 & 0xffff);
      }
      else if (iVar10 == 2) {
        uVar7 = (int)(uVar7 - (uVar21 & 0xffff)) >> 1;
      }
      else {
        uVar7 = (int)(uVar7 - (uVar21 & 0xffff)) / iVar10;
      }
      uVar18 = uVar21 & 0xffff;
      DAT_1007b2c8 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
      DAT_1007b2c0 = uVar21;
      if ((local_14 == sVar20) || (local_2c == 1)) {
LAB_1002078c:
        uVar18 = (uVar8 & 0xffff) - uVar18;
      }
      else if (local_2c == 2) {
        uVar18 = (int)((uVar8 & 0xffff) - uVar18) >> 1;
      }
      else {
        uVar18 = (int)((uVar8 & 0xffff) - uVar18) / local_2c;
      }
    }
    DAT_1007b2c4 = (uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
    DAT_1007b2e4 = iVar14;
  }
  else {
    iVar10 = iVar15 - DAT_1007b280;
    if (iVar6 == 1) {
      DAT_1007b28c = iVar10 * 0x10000;
    }
    else if (iVar6 == 2) {
      DAT_1007b28c = iVar10 * 0x8000;
    }
    else if (((iVar6 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar9 + (iVar10 * 0x20 + iVar6) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1007b28c = (iVar10 * 0x10000) / iVar6;
    }
    else {
      DAT_1007b28c = (iVar10 * 0x10000) / iVar6;
    }
    DAT_1007b3ac = DAT_1007b300;
    iVar10 = iVar6 >> 1;
    iVar11 = iVar10;
    if ((int)(DAT_1007b304 - DAT_1007b300) < 0) {
      iVar11 = -iVar10;
    }
    DAT_1007b3b0 = (int)((DAT_1007b304 - DAT_1007b300) + iVar11) / iVar6;
    uVar18 = DAT_1007b300 >> 0x10;
    _DAT_1007b3b4 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b310 | DAT_1007b314 | DAT_1007b318 | DAT_1007b30c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3b4;
    uVar22 = DAT_1007b304 >> 0x10;
    DAT_1007b38c = ((int)DAT_1007b30c >> (bVar5 & 0x1f)) * uVar18;
    DAT_1007b390 = (int)(((int)DAT_1007b314 >> (bVar5 & 0x1f)) * uVar22 - DAT_1007b38c) / iVar6;
    DAT_1007b394 = ((int)DAT_1007b310 >> (bVar5 & 0x1f)) * uVar18;
    DAT_1007b398 = (int)(((int)DAT_1007b318 >> (bVar5 & 0x1f)) * uVar22 - DAT_1007b394) / iVar6;
    iVar11 = (int)sVar2 - DAT_1007b284;
    if (0 < iVar11) {
      iVar10 = iVar19 - DAT_1007b280;
      if (iVar11 == 1) {
        DAT_1007b288 = iVar10 * 0x10000;
      }
      else if (iVar11 == 2) {
        DAT_1007b288 = iVar10 * 0x8000;
      }
      else if (((iVar11 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar9 + (iVar10 * 0x20 + iVar11) * 4);
      }
      else if (iVar10 < 0) {
        DAT_1007b288 = (iVar10 * 0x10000) / iVar11;
      }
      else {
        DAT_1007b288 = (iVar10 * 0x10000) / iVar11;
      }
      iVar10 = DAT_1007b288 - DAT_1007b28c;
      if (iVar10 < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        DAT_1007b2b4 = DAT_10075220;
        DAT_1007b3ac = DAT_1007b300;
        return;
      }
      DAT_1007b3c0 = DAT_1007b300;
      iVar12 = iVar11 >> 1;
      if ((int)(DAT_1007b308 - DAT_1007b300) < 0) {
        iVar12 = -iVar12;
      }
      DAT_1007b3c4 = (int)(iVar12 + (DAT_1007b308 - DAT_1007b300)) / iVar11;
      _DAT_1007b3c8 =
           (char)(&DAT_1007b7d0)
                 [(int)(DAT_1007b320 | DAT_1007b310 | DAT_1007b31c | DAT_1007b30c) >> 0x10] + 1;
      bVar5 = (byte)_DAT_1007b3c8;
      DAT_1007b39c = ((int)DAT_1007b30c >> (bVar5 & 0x1f)) * uVar18;
      DAT_1007b3a0 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b39c) / iVar11;
      DAT_1007b3a4 = ((int)DAT_1007b310 >> (bVar5 & 0x1f)) * uVar18;
      DAT_1007b3a8 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                          DAT_1007b3a4) / iVar11;
      if (DAT_1007b43c == 0) {
        if ((local_18 == sVar20) || (iVar6 == 1)) {
          uVar18 = (uVar7 & 0xffff) - (uVar21 & 0xffff);
        }
        else if (iVar6 == 2) {
          uVar18 = (int)((uVar7 & 0xffff) - (uVar21 & 0xffff)) >> 1;
        }
        else {
          uVar18 = (int)((uVar7 & 0xffff) - (uVar21 & 0xffff)) / iVar6;
        }
        uVar22 = uVar21 & 0xffff;
        DAT_1007b2c4 = (uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
        if ((local_14 == sVar20) || (iVar11 == 1)) {
          iVar12 = (uVar8 & 0xffff) - uVar22;
        }
        else if (iVar11 == 2) {
          iVar12 = (int)((uVar8 & 0xffff) - uVar22) >> 1;
        }
        else {
          iVar12 = (int)((uVar8 & 0xffff) - uVar22) / iVar11;
        }
        iVar12 = iVar12 - (short)DAT_1007b2c4;
      }
      else {
        if ((local_14 == sVar20) || (iVar11 == 1)) {
          uVar18 = (uVar8 & 0xffff) - (uVar21 & 0xffff);
        }
        else if (iVar11 == 2) {
          uVar18 = (int)((uVar8 & 0xffff) - (uVar21 & 0xffff)) >> 1;
        }
        else {
          uVar18 = (int)((uVar8 & 0xffff) - (uVar21 & 0xffff)) / iVar11;
        }
        uVar22 = uVar21 & 0xffff;
        DAT_1007b2c4 = (uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
        if ((local_18 == sVar20) || (iVar6 == 1)) {
          iVar12 = (uVar7 & 0xffff) - uVar22;
        }
        else if (iVar6 == 2) {
          iVar12 = (int)((uVar7 & 0xffff) - uVar22) >> 1;
        }
        else {
          iVar12 = (int)((uVar7 & 0xffff) - uVar22) / iVar6;
        }
        iVar12 = iVar12 - (short)DAT_1007b2c4;
      }
      DAT_1007b2c8 = 0;
      if (iVar12 != 0) {
        uVar18 = (iVar12 << 0x10) / iVar10;
        DAT_1007b2c8 = (uVar18 & 0xffff) + (uVar18 & 0x8000) * -2;
      }
      uVar8 = uVar8 & 0xffff;
      uVar7 = uVar7 & 0xffff;
      if (DAT_1007b43c == 0) {
        if ((iVar3 == iVar14) || (iVar6 == 1)) {
          DAT_1007b2e8 = iVar3 - iVar14;
        }
        else if (iVar6 == 2) {
          DAT_1007b2e8 = iVar3 - iVar14 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar3 - iVar14) / iVar6;
        }
        if ((iVar14 == iVar13) || (iVar11 == 1)) {
          iVar12 = iVar13 - iVar14;
        }
        else if (iVar11 == 2) {
          iVar12 = iVar13 - iVar14 >> 1;
        }
        else {
          iVar12 = (iVar13 - iVar14) / iVar11;
        }
        DAT_1007b2ec = iVar12 - DAT_1007b2e8;
      }
      else {
        if ((iVar14 == iVar13) || (iVar11 == 1)) {
          DAT_1007b2e8 = iVar13 - iVar14;
        }
        else if (iVar11 == 2) {
          DAT_1007b2e8 = iVar13 - iVar14 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar13 - iVar14) / iVar11;
        }
        if ((iVar3 == iVar14) || (iVar6 == 1)) {
          iVar12 = iVar3 - iVar14;
        }
        else if (iVar6 == 2) {
          iVar12 = iVar3 - iVar14 >> 1;
        }
        else {
          iVar12 = (iVar3 - iVar14) / iVar6;
        }
        DAT_1007b2ec = iVar12 - DAT_1007b2e8;
      }
      if ((DAT_1007b2ec != 0) && (iVar10 >> 6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / (iVar10 >> 6) << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar6 < iVar11) {
        local_2c = iVar11 - iVar6;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar14;
        DAT_1007b290 = iVar6;
        DAT_1007b2c0 = uVar21;
        FUN_10020800((uint *)&DAT_1007b280);
        DAT_1007b3ac = DAT_1007b304;
        iVar10 = local_2c >> 1;
        if ((int)(DAT_1007b308 - DAT_1007b304) < 0) {
          iVar10 = -iVar10;
        }
        DAT_1007b3b0 = (int)(iVar10 + (DAT_1007b308 - DAT_1007b304)) / local_2c;
        _DAT_1007b3b4 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar5 = (byte)_DAT_1007b3b4;
        DAT_1007b38c = ((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b390 = (int)(((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b38c) / local_2c;
        DAT_1007b394 = ((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10);
        DAT_1007b398 = (int)(((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10) -
                            DAT_1007b394) / local_2c;
        DAT_1007b280 = iVar15 << 0x10;
        iVar19 = iVar19 - iVar15;
        if (local_2c == 1) {
          DAT_1007b28c = iVar19 * 0x10000;
        }
        else if (local_2c == 2) {
          DAT_1007b28c = iVar19 * 0x8000;
        }
        else if (((local_2c < 0x20) && (-0x20 < iVar19)) && (iVar19 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar9 + (iVar19 * 0x20 + local_2c) * 4);
        }
        else if (iVar19 < 0) {
          DAT_1007b28c = (iVar19 * 0x10000) / local_2c;
        }
        else {
          DAT_1007b28c = (iVar19 * 0x10000) / local_2c;
        }
        if (DAT_1007b43c == 0) {
          DAT_1007b2c4 = 0;
          if ((local_14 == local_18) || (local_2c == 1)) {
            uVar8 = uVar8 - uVar7;
          }
          else if (local_2c == 2) {
            uVar8 = (int)(uVar8 - uVar7) >> 1;
          }
          else {
            uVar8 = (int)(uVar8 - uVar7) / local_2c;
          }
          if (uVar8 != 0) {
            DAT_1007b2c4 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
          }
          if (iVar3 == iVar13) {
            DAT_1007b2e8 = iVar13 - iVar3;
          }
          else if (local_2c == 1) {
            DAT_1007b2e8 = iVar13 - iVar3;
          }
          else if (local_2c == 2) {
            DAT_1007b2e8 = iVar13 - iVar3 >> 1;
          }
          else {
            DAT_1007b2e8 = (iVar13 - iVar3) / local_2c;
          }
        }
      }
      else {
        local_2c = iVar6 - iVar11;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar14;
        DAT_1007b290 = iVar11;
        DAT_1007b2c0 = uVar21;
        FUN_10020800((uint *)&DAT_1007b280);
        if (local_2c == 0) {
          return;
        }
        DAT_1007b3c0 = DAT_1007b308;
        iVar10 = local_2c >> 1;
        if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
          iVar10 = -iVar10;
        }
        DAT_1007b3c4 = (int)(iVar10 + (DAT_1007b304 - DAT_1007b308)) / local_2c;
        _DAT_1007b3c8 =
             (char)(&DAT_1007b7d0)
                   [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
        bVar5 = (byte)_DAT_1007b3c8;
        DAT_1007b39c = ((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b39c) / local_2c;
        DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
        DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar5 & 0x1f)) * (DAT_1007b304 >> 0x10) -
                            DAT_1007b3a4) / local_2c;
        DAT_1007b284 = iVar19 << 0x10;
        iVar15 = iVar15 - iVar19;
        if (local_2c == 1) {
          DAT_1007b288 = iVar15 * 0x10000;
        }
        else if (local_2c == 2) {
          DAT_1007b288 = iVar15 * 0x8000;
        }
        else if (((local_2c < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar9 + (iVar15 * 0x20 + local_2c) * 4);
        }
        else if (iVar15 < 0) {
          DAT_1007b288 = (iVar15 * 0x10000) / local_2c;
        }
        else {
          DAT_1007b288 = (iVar15 * 0x10000) / local_2c;
        }
        if (DAT_1007b43c != 0) {
          DAT_1007b2c4 = 0;
          if ((local_14 == local_18) || (local_2c == 1)) {
            uVar7 = uVar7 - uVar8;
          }
          else if (local_2c == 2) {
            uVar7 = (int)(uVar7 - uVar8) >> 1;
          }
          else {
            uVar7 = (int)(uVar7 - uVar8) / local_2c;
          }
          if (uVar7 != 0) {
            DAT_1007b2c4 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
          }
          if (DAT_1007b43c != 0) {
            if (iVar3 == iVar13) {
              DAT_1007b2e8 = iVar3 - iVar13;
            }
            else if (local_2c == 1) {
              DAT_1007b2e8 = iVar3 - iVar13;
            }
            else if (local_2c == 2) {
              DAT_1007b2e8 = iVar3 - iVar13 >> 1;
            }
            else {
              DAT_1007b2e8 = (iVar3 - iVar13) / local_2c;
            }
          }
        }
      }
      goto LAB_100207df;
    }
    iVar11 = iVar19 - DAT_1007b280;
    if (iVar11 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      DAT_1007b2b4 = DAT_10075220;
      DAT_1007b3ac = DAT_1007b300;
      return;
    }
    iVar15 = iVar15 - iVar19;
    if (iVar6 == 1) {
      DAT_1007b288 = iVar15 * 0x10000;
    }
    else if (iVar6 == 2) {
      DAT_1007b288 = iVar15 * 0x8000;
    }
    else if (((iVar6 < 0x20) && (-0x20 < iVar15)) && (iVar15 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar9 + (iVar15 * 0x20 + iVar6) * 4);
    }
    else if (iVar15 < 0) {
      DAT_1007b288 = (iVar15 * 0x10000) / iVar6;
    }
    else {
      DAT_1007b288 = (iVar15 * 0x10000) / iVar6;
    }
    DAT_1007b3c0 = DAT_1007b308;
    if ((int)(DAT_1007b304 - DAT_1007b308) < 0) {
      iVar10 = -iVar10;
    }
    DAT_1007b3c4 = (int)((DAT_1007b304 - DAT_1007b308) + iVar10) / iVar6;
    _DAT_1007b3c8 =
         (char)(&DAT_1007b7d0)
               [(int)(DAT_1007b320 | DAT_1007b314 | DAT_1007b318 | DAT_1007b31c) >> 0x10] + 1;
    bVar5 = (byte)_DAT_1007b3c8;
    DAT_1007b39c = ((int)DAT_1007b31c >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
    DAT_1007b3a0 = (int)(((int)DAT_1007b314 >> (bVar5 & 0x1f)) * uVar22 - DAT_1007b39c) / iVar6;
    DAT_1007b3a4 = ((int)DAT_1007b320 >> (bVar5 & 0x1f)) * (DAT_1007b308 >> 0x10);
    DAT_1007b3a8 = (int)(((int)DAT_1007b318 >> (bVar5 & 0x1f)) * uVar22 - DAT_1007b3a4) / iVar6;
    if (DAT_1007b43c == 0) {
      if ((iVar14 == iVar13) || (iVar11 == 1)) {
        DAT_1007b2ec = iVar13 - iVar14;
      }
      else if (iVar11 == 2) {
        DAT_1007b2ec = iVar13 - iVar14 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar13 - iVar14) / iVar11;
      }
      iVar13 = iVar14;
      if ((iVar3 == iVar14) || (iVar6 == 1)) {
        DAT_1007b2e8 = iVar3 - iVar14;
      }
      else if (iVar6 == 2) {
        DAT_1007b2e8 = iVar3 - iVar14 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar3 - iVar14) / iVar6;
      }
    }
    else {
      if ((iVar14 == iVar13) || (iVar11 == 1)) {
        DAT_1007b2ec = iVar14 - iVar13;
      }
      else if (iVar11 == 2) {
        DAT_1007b2ec = iVar14 - iVar13 >> 1;
      }
      else {
        DAT_1007b2ec = (iVar14 - iVar13) / iVar11;
      }
      if ((iVar3 == iVar13) || (iVar6 == 1)) {
        DAT_1007b2e8 = iVar3 - iVar13;
      }
      else if (iVar6 == 2) {
        DAT_1007b2e8 = iVar3 - iVar13 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar3 - iVar13) / iVar6;
      }
    }
    if (DAT_1007b43c == 0) {
      uVar8 = uVar8 & 0xffff;
      if ((local_14 == sVar20) || (iVar11 == 1)) {
        uVar8 = uVar8 - (uVar21 & 0xffff);
      }
      else if (iVar11 == 2) {
        uVar8 = (int)(uVar8 - (uVar21 & 0xffff)) >> 1;
      }
      else {
        uVar8 = (int)(uVar8 - (uVar21 & 0xffff)) / iVar11;
      }
      uVar18 = uVar21 & 0xffff;
      DAT_1007b2c8 = (uVar8 & 0xffff) + (uVar8 & 0x8000) * -2;
      uVar7 = uVar7 & 0xffff;
      if ((local_18 == sVar20) || (iVar6 == 1)) {
        uVar7 = uVar7 - uVar18;
        DAT_1007b2c0 = uVar21;
      }
      else if (iVar6 == 2) {
        uVar7 = (int)(uVar7 - uVar18) >> 1;
        DAT_1007b2c0 = uVar21;
      }
      else {
        uVar7 = (int)(uVar7 - uVar18) / iVar6;
        DAT_1007b2c0 = uVar21;
      }
    }
    else {
      if ((local_14 == sVar20) || (iVar11 == 1)) {
        uVar21 = (uVar21 & 0xffff) - (uVar8 & 0xffff);
      }
      else if (iVar11 == 2) {
        uVar21 = (int)((uVar21 & 0xffff) - (uVar8 & 0xffff)) >> 1;
      }
      else {
        uVar21 = (int)((uVar21 & 0xffff) - (uVar8 & 0xffff)) / iVar11;
      }
      uVar18 = uVar8 & 0xffff;
      DAT_1007b2c8 = (uVar21 & 0xffff) + (uVar21 & 0x8000) * -2;
      uVar7 = uVar7 & 0xffff;
      DAT_1007b2c0 = uVar8;
      if ((local_14 == local_18) || (iVar6 == 1)) {
        uVar7 = uVar7 - uVar18;
      }
      else if (iVar6 == 2) {
        uVar7 = (int)(uVar7 - uVar18) >> 1;
      }
      else {
        uVar7 = (int)(uVar7 - uVar18) / iVar6;
      }
    }
    DAT_1007b2c4 = (uVar7 & 0xffff) + (uVar7 & 0x8000) * -2;
    DAT_1007b2e4 = iVar13;
    local_2c = iVar6;
    iVar15 = DAT_1007b280;
    DAT_1007b280 = iVar19;
  }
  DAT_1007b284 = DAT_1007b280 << 0x10;
  DAT_1007b280 = iVar15 << 0x10;
  DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2f0;
LAB_100207df:
  DAT_1007b290 = local_2c;
  FUN_10020800((uint *)&DAT_1007b280);
  return;
}


