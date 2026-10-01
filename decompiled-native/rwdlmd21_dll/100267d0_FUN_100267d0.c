// 100267d0 FUN_100267d0 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100267d0(int *param_1,int param_2,int param_3,int param_4)

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
      iVar10 = param_4;
      param_4 = iVar15;
    }
    else {
LAB_10026816:
      param_2 = param_4;
      iVar10 = iVar15;
      param_4 = param_3;
    }
  }
  else {
    iVar10 = param_3;
    if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10026816;
  }
  DAT_1008d284 = (uint)*(short *)(param_2 + 0x1e);
  sVar1 = *(short *)(iVar10 + 0x1e);
  sVar2 = *(short *)(param_4 + 0x1e);
  iVar7 = (int)sVar1 - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  iVar15 = *(int *)(param_2 + 0x20);
  iVar3 = *(int *)(iVar10 + 0x20);
  iVar16 = (int)*(short *)(iVar10 + 0x1a);
  iVar8 = (int)*(short *)(param_4 + 0x1a);
  iVar4 = *(int *)(param_4 + 0x20);
  DAT_1008d30c = *(uint *)(param_2 + 100);
  DAT_1008d310 = *(uint *)(param_2 + 0x68);
  DAT_1008d314 = *(uint *)(iVar10 + 100);
  DAT_1008d318 = *(uint *)(iVar10 + 0x68);
  DAT_1008d31c = *(uint *)(param_4 + 100);
  DAT_1008d320 = *(uint *)(param_4 + 0x68);
  _DAT_1008d324 = *(float *)(param_2 + 0x14);
  _DAT_1008d328 = *(float *)(iVar10 + 0x14);
  _DAT_1008d32c = *(float *)(param_4 + 0x14);
  DAT_1008d330 = _DAT_1008d32c * _DAT_1008d328;
  DAT_1008d338 = _DAT_1008d324 * _DAT_1008d328;
  DAT_1008d334 = _DAT_1008d324 * _DAT_1008d32c;
  fVar9 = DAT_1008d334;
  if ((int)DAT_1008d334 < (int)DAT_1008d330) {
    fVar9 = DAT_1008d330;
  }
  if ((int)fVar9 <= (int)DAT_1008d338) {
    fVar9 = DAT_1008d338;
  }
  DAT_1008d33c = (int)fVar9 >> 0x17;
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
  bVar5 = FUN_10006240(param_2,iVar10,param_4);
  DAT_1008d43c = (uint)(CONCAT31(extraout_var,bVar5) == 0);
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  DAT_1008d2b0 = *(undefined4 *)(*(int *)(*param_1 + 0x34) + 4);
  DAT_1008d2b4 = (param_1[1] >> 0x10) * 0x20 + DAT_10087248;
  DAT_1008d2b8 = (param_1[2] >> 0x10) * 0x20 + DAT_10087248 + 0x400;
  DAT_1008d2bc = (param_1[3] >> 0x10) * 0x20 + DAT_10087248 + 0x800;
  iVar17 = DAT_1008723c + 0x1000;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  iVar10 = DAT_10087250;
  if (DAT_1008d43c != 0) {
    iVar10 = DAT_10087258;
  }
  _DAT_1008d2a4 = *(undefined4 *)(iVar10 + (DAT_1008d284 & 7) * 4);
  if (iVar7 < 1) {
    iVar10 = DAT_1008d280 - iVar16;
    if (iVar10 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iStack_24 = -((int)sVar1 - (int)sVar2);
    if (iStack_24 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    DAT_1008d3ac = DAT_1008d304;
    iVar7 = iStack_24 >> 1;
    iVar13 = iVar7;
    if ((int)(DAT_1008d308 - DAT_1008d304) < 0) {
      iVar13 = -iVar7;
    }
    DAT_1008d3b0 = (int)(iVar13 + (DAT_1008d308 - DAT_1008d304)) / iStack_24;
    _DAT_1008d3b4 =
         (char)(&DAT_1008d7d0)
               [(int)(DAT_1008d31c | DAT_1008d314 | DAT_1008d318 | DAT_1008d320) >> 0x10] + 1;
    bVar6 = (byte)_DAT_1008d3b4;
    DAT_1008d38c = ((int)DAT_1008d314 >> (bVar6 & 0x1f)) * (DAT_1008d304 >> 0x10);
    uVar11 = DAT_1008d308 >> 0x10;
    DAT_1008d390 = (int)(((int)DAT_1008d31c >> (bVar6 & 0x1f)) * uVar11 - DAT_1008d38c) / iStack_24;
    DAT_1008d394 = ((int)DAT_1008d318 >> (bVar6 & 0x1f)) * (DAT_1008d304 >> 0x10);
    DAT_1008d398 = (int)(((int)DAT_1008d320 >> (bVar6 & 0x1f)) * uVar11 - DAT_1008d394) / iStack_24;
    DAT_1008d3c0 = DAT_1008d300;
    if ((int)(DAT_1008d308 - DAT_1008d300) < 0) {
      iVar7 = -iVar7;
    }
    DAT_1008d3c4 = (int)(iVar7 + (DAT_1008d308 - DAT_1008d300)) / iStack_24;
    _DAT_1008d3c8 =
         (char)(&DAT_1008d7d0)
               [(int)(DAT_1008d31c | DAT_1008d30c | DAT_1008d320 | DAT_1008d310) >> 0x10] + 1;
    bVar6 = (byte)_DAT_1008d3c8;
    DAT_1008d39c = ((int)DAT_1008d30c >> (bVar6 & 0x1f)) * (DAT_1008d300 >> 0x10);
    DAT_1008d3a0 = (int)(((int)DAT_1008d31c >> (bVar6 & 0x1f)) * uVar11 - DAT_1008d39c) / iStack_24;
    DAT_1008d3a4 = ((int)DAT_1008d310 >> (bVar6 & 0x1f)) * (DAT_1008d300 >> 0x10);
    DAT_1008d3a8 = (int)(((int)DAT_1008d320 >> (bVar6 & 0x1f)) * uVar11 - DAT_1008d3a4) / iStack_24;
    iVar7 = iVar8 - iVar16;
    if (iStack_24 == 1) {
      DAT_1008d28c = iVar7 * 0x10000;
    }
    else if (iStack_24 == 2) {
      DAT_1008d28c = iVar7 * 0x8000;
    }
    else if (((iStack_24 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar17 + (iVar7 * 0x20 + iStack_24) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1008d28c = (iVar7 * 0x10000) / iStack_24;
    }
    else {
      DAT_1008d28c = (iVar7 * 0x10000) / iStack_24;
    }
    iVar8 = iVar8 - DAT_1008d280;
    if (iStack_24 == 1) {
      DAT_1008d288 = iVar8 * 0x10000;
    }
    else if (iStack_24 == 2) {
      DAT_1008d288 = iVar8 * 0x8000;
    }
    else if (((iStack_24 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar17 + (iVar8 * 0x20 + iStack_24) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1008d288 = (iVar8 * 0x10000) / iStack_24;
    }
    else {
      DAT_1008d288 = (iVar8 * 0x10000) / iStack_24;
    }
    iVar8 = DAT_1008d280;
    if (DAT_1008d43c == 0) {
      if ((iVar3 == iVar15) || (iVar10 == 1)) {
        DAT_1008d2ec = iVar15 - iVar3;
      }
      else if (iVar10 == 2) {
        DAT_1008d2ec = iVar15 - iVar3 >> 1;
      }
      else {
        DAT_1008d2ec = (iVar15 - iVar3) / iVar10;
      }
      DAT_1008d2e4 = iVar3;
      if ((iVar4 == iVar3) || (iStack_24 == 1)) {
        DAT_1008d2e8 = iVar4 - iVar3;
      }
      else if (iStack_24 == 2) {
        DAT_1008d2e8 = iVar4 - iVar3 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar4 - iVar3) / iStack_24;
      }
    }
    else {
      if ((iVar3 == iVar15) || (iVar10 == 1)) {
        DAT_1008d2ec = iVar3 - iVar15;
      }
      else if (iVar10 == 2) {
        DAT_1008d2ec = iVar3 - iVar15 >> 1;
      }
      else {
        DAT_1008d2ec = (iVar3 - iVar15) / iVar10;
      }
      if (iVar4 == iVar15) {
        DAT_1008d2e8 = iVar4 - iVar15;
        DAT_1008d2e4 = iVar15;
      }
      else if (iStack_24 == 1) {
        DAT_1008d2e8 = iVar4 - iVar15;
        DAT_1008d2e4 = iVar15;
      }
      else if (iStack_24 == 2) {
        DAT_1008d2e8 = iVar4 - iVar15 >> 1;
        DAT_1008d2e4 = iVar15;
      }
      else {
        DAT_1008d2e8 = (iVar4 - iVar15) / iStack_24;
        DAT_1008d2e4 = iVar15;
      }
    }
  }
  else {
    iVar10 = iVar16 - DAT_1008d280;
    if (iVar7 == 1) {
      DAT_1008d28c = iVar10 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1008d28c = iVar10 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar17 + (iVar10 * 0x20 + iVar7) * 4);
    }
    else if (iVar10 < 0) {
      DAT_1008d28c = (iVar10 * 0x10000) / iVar7;
    }
    else {
      DAT_1008d28c = (iVar10 * 0x10000) / iVar7;
    }
    DAT_1008d3ac = DAT_1008d300;
    iVar10 = iVar7 >> 1;
    iVar13 = iVar10;
    if ((int)(DAT_1008d304 - DAT_1008d300) < 0) {
      iVar13 = -iVar10;
    }
    DAT_1008d3b0 = (int)(iVar13 + (DAT_1008d304 - DAT_1008d300)) / iVar7;
    _DAT_1008d3b4 =
         (char)(&DAT_1008d7d0)
               [(int)(DAT_1008d314 | DAT_1008d318 | DAT_1008d30c | DAT_1008d310) >> 0x10] + 1;
    bVar6 = (byte)_DAT_1008d3b4;
    uVar11 = DAT_1008d300 >> 0x10;
    DAT_1008d38c = ((int)DAT_1008d30c >> (bVar6 & 0x1f)) * uVar11;
    uVar12 = DAT_1008d304 >> 0x10;
    DAT_1008d390 = (int)(((int)DAT_1008d314 >> (bVar6 & 0x1f)) * uVar12 - DAT_1008d38c) / iVar7;
    DAT_1008d394 = ((int)DAT_1008d310 >> (bVar6 & 0x1f)) * uVar11;
    DAT_1008d398 = (int)(((int)DAT_1008d318 >> (bVar6 & 0x1f)) * uVar12 - DAT_1008d394) / iVar7;
    iVar13 = (int)sVar2 - DAT_1008d284;
    if (0 < iVar13) {
      iVar10 = iVar8 - DAT_1008d280;
      if (iVar13 == 1) {
        DAT_1008d288 = iVar10 * 0x10000;
      }
      else if (iVar13 == 2) {
        DAT_1008d288 = iVar10 * 0x8000;
      }
      else if (((iVar13 < 0x20) && (-0x20 < iVar10)) && (iVar10 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar17 + (iVar10 * 0x20 + iVar13) * 4);
      }
      else if (iVar10 < 0) {
        DAT_1008d288 = (iVar10 * 0x10000) / iVar13;
      }
      else {
        DAT_1008d288 = (iVar10 * 0x10000) / iVar13;
      }
      if (DAT_1008d288 - DAT_1008d28c < 1) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d2a0 = DAT_10089ef4;
        DAT_1008d3ac = DAT_1008d300;
        return;
      }
      DAT_1008d3c0 = DAT_1008d300;
      iVar10 = iVar13 >> 1;
      if ((int)(DAT_1008d308 - DAT_1008d300) < 0) {
        iVar10 = -iVar10;
      }
      DAT_1008d3c4 = (int)(iVar10 + (DAT_1008d308 - DAT_1008d300)) / iVar13;
      _DAT_1008d3c8 =
           (char)(&DAT_1008d7d0)
                 [(int)(DAT_1008d31c | DAT_1008d30c | DAT_1008d320 | DAT_1008d310) >> 0x10] + 1;
      bVar6 = (byte)_DAT_1008d3c8;
      DAT_1008d39c = ((int)DAT_1008d30c >> (bVar6 & 0x1f)) * uVar11;
      DAT_1008d3a0 = (int)(((int)DAT_1008d31c >> (bVar6 & 0x1f)) * (DAT_1008d308 >> 0x10) -
                          DAT_1008d39c) / iVar13;
      DAT_1008d3a4 = ((int)DAT_1008d310 >> (bVar6 & 0x1f)) * uVar11;
      DAT_1008d3a8 = (int)(((int)DAT_1008d320 >> (bVar6 & 0x1f)) * (DAT_1008d308 >> 0x10) -
                          DAT_1008d3a4) / iVar13;
      iVar10 = DAT_1008d288 - DAT_1008d28c >> 6;
      if (DAT_1008d43c == 0) {
        if ((iVar3 == iVar15) || (iVar7 == 1)) {
          DAT_1008d2e8 = iVar3 - iVar15;
        }
        else if (iVar7 == 2) {
          DAT_1008d2e8 = iVar3 - iVar15 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar3 - iVar15) / iVar7;
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
        DAT_1008d2ec = iVar14 - DAT_1008d2e8;
      }
      else {
        if ((iVar4 == iVar15) || (iVar13 == 1)) {
          DAT_1008d2e8 = iVar4 - iVar15;
        }
        else if (iVar13 == 2) {
          DAT_1008d2e8 = iVar4 - iVar15 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar4 - iVar15) / iVar13;
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
        DAT_1008d2ec = iVar14 - DAT_1008d2e8;
      }
      if ((DAT_1008d2ec != 0) && (iVar10 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / iVar10 << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar7 < iVar13) {
        iStack_24 = iVar13 - iVar7;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar15;
        DAT_1008d290 = iVar7;
        FUN_10027a70((uint *)&DAT_1008d280);
        DAT_1008d3ac = DAT_1008d304;
        iVar15 = iStack_24 >> 1;
        if ((int)(DAT_1008d308 - DAT_1008d304) < 0) {
          iVar15 = -iVar15;
        }
        DAT_1008d3b0 = (int)(iVar15 + (DAT_1008d308 - DAT_1008d304)) / iStack_24;
        _DAT_1008d3b4 =
             (char)(&DAT_1008d7d0)
                   [(int)(DAT_1008d31c | DAT_1008d314 | DAT_1008d318 | DAT_1008d320) >> 0x10] + 1;
        bVar6 = (byte)_DAT_1008d3b4;
        DAT_1008d38c = ((int)DAT_1008d314 >> (bVar6 & 0x1f)) * (DAT_1008d304 >> 0x10);
        DAT_1008d390 = (int)(((int)DAT_1008d31c >> (bVar6 & 0x1f)) * (DAT_1008d308 >> 0x10) -
                            DAT_1008d38c) / iStack_24;
        DAT_1008d394 = ((int)DAT_1008d318 >> (bVar6 & 0x1f)) * (DAT_1008d304 >> 0x10);
        DAT_1008d398 = (int)(((int)DAT_1008d320 >> (bVar6 & 0x1f)) * (DAT_1008d308 >> 0x10) -
                            DAT_1008d394) / iStack_24;
        DAT_1008d280 = iVar16 << 0x10;
        iVar8 = iVar8 - iVar16;
        if (iStack_24 == 1) {
          DAT_1008d28c = iVar8 * 0x10000;
        }
        else if (iStack_24 == 2) {
          DAT_1008d28c = iVar8 * 0x8000;
        }
        else if (((iStack_24 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar17 + (iVar8 * 0x20 + iStack_24) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1008d28c = (iVar8 * 0x10000) / iStack_24;
        }
        else {
          DAT_1008d28c = (iVar8 * 0x10000) / iStack_24;
        }
        if (DAT_1008d43c == 0) {
          if (iVar4 == iVar3) {
            DAT_1008d2e8 = iVar4 - iVar3;
          }
          else if (iStack_24 == 1) {
            DAT_1008d2e8 = iVar4 - iVar3;
          }
          else if (iStack_24 == 2) {
            DAT_1008d2e8 = iVar4 - iVar3 >> 1;
          }
          else {
            DAT_1008d2e8 = (iVar4 - iVar3) / iStack_24;
          }
        }
      }
      else {
        iStack_24 = iVar7 - iVar13;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar15;
        DAT_1008d290 = iVar13;
        FUN_10027a70((uint *)&DAT_1008d280);
        if (iStack_24 == 0) {
          return;
        }
        DAT_1008d3c0 = DAT_1008d308;
        iVar15 = iStack_24 >> 1;
        if ((int)(DAT_1008d304 - DAT_1008d308) < 0) {
          iVar15 = -iVar15;
        }
        DAT_1008d3c4 = (int)(iVar15 + (DAT_1008d304 - DAT_1008d308)) / iStack_24;
        _DAT_1008d3c8 =
             (char)(&DAT_1008d7d0)
                   [(int)(DAT_1008d31c | DAT_1008d314 | DAT_1008d318 | DAT_1008d320) >> 0x10] + 1;
        bVar6 = (byte)_DAT_1008d3c8;
        DAT_1008d39c = ((int)DAT_1008d31c >> (bVar6 & 0x1f)) * (DAT_1008d308 >> 0x10);
        DAT_1008d3a0 = (int)(((int)DAT_1008d314 >> (bVar6 & 0x1f)) * (DAT_1008d304 >> 0x10) -
                            DAT_1008d39c) / iStack_24;
        DAT_1008d3a4 = ((int)DAT_1008d320 >> (bVar6 & 0x1f)) * (DAT_1008d308 >> 0x10);
        DAT_1008d3a8 = (int)(((int)DAT_1008d318 >> (bVar6 & 0x1f)) * (DAT_1008d304 >> 0x10) -
                            DAT_1008d3a4) / iStack_24;
        DAT_1008d284 = iVar8 << 0x10;
        iVar16 = iVar16 - iVar8;
        if (iStack_24 == 1) {
          DAT_1008d288 = iVar16 * 0x10000;
        }
        else if (iStack_24 == 2) {
          DAT_1008d288 = iVar16 * 0x8000;
        }
        else if (((iStack_24 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar17 + (iVar16 * 0x20 + iStack_24) * 4);
        }
        else if (iVar16 < 0) {
          DAT_1008d288 = (iVar16 * 0x10000) / iStack_24;
        }
        else {
          DAT_1008d288 = (iVar16 * 0x10000) / iStack_24;
        }
        if (DAT_1008d43c != 0) {
          if (iVar4 == iVar3) {
            DAT_1008d2e8 = iVar3 - iVar4;
          }
          else if (iStack_24 == 1) {
            DAT_1008d2e8 = iVar3 - iVar4;
          }
          else if (iStack_24 == 2) {
            DAT_1008d2e8 = iVar3 - iVar4 >> 1;
          }
          else {
            DAT_1008d2e8 = (iVar3 - iVar4) / iStack_24;
          }
        }
      }
      goto LAB_10027a47;
    }
    iVar13 = iVar8 - DAT_1008d280;
    if (iVar13 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      DAT_1008d3ac = DAT_1008d300;
      return;
    }
    iVar16 = iVar16 - iVar8;
    if (iVar7 == 1) {
      DAT_1008d288 = iVar16 * 0x10000;
    }
    else if (iVar7 == 2) {
      DAT_1008d288 = iVar16 * 0x8000;
    }
    else if (((iVar7 < 0x20) && (-0x20 < iVar16)) && (iVar16 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar17 + (iVar16 * 0x20 + iVar7) * 4);
    }
    else if (iVar16 < 0) {
      DAT_1008d288 = (iVar16 * 0x10000) / iVar7;
    }
    else {
      DAT_1008d288 = (iVar16 * 0x10000) / iVar7;
    }
    DAT_1008d3c0 = DAT_1008d308;
    if ((int)(DAT_1008d304 - DAT_1008d308) < 0) {
      iVar10 = -iVar10;
    }
    DAT_1008d3c4 = (int)((DAT_1008d304 - DAT_1008d308) + iVar10) / iVar7;
    _DAT_1008d3c8 =
         (char)(&DAT_1008d7d0)
               [(int)(DAT_1008d31c | DAT_1008d314 | DAT_1008d318 | DAT_1008d320) >> 0x10] + 1;
    bVar6 = (byte)_DAT_1008d3c8;
    DAT_1008d39c = ((int)DAT_1008d31c >> (bVar6 & 0x1f)) * (DAT_1008d308 >> 0x10);
    DAT_1008d3a0 = (int)(((int)DAT_1008d314 >> (bVar6 & 0x1f)) * uVar12 - DAT_1008d39c) / iVar7;
    DAT_1008d3a4 = ((int)DAT_1008d320 >> (bVar6 & 0x1f)) * (DAT_1008d308 >> 0x10);
    DAT_1008d3a8 = (int)(((int)DAT_1008d318 >> (bVar6 & 0x1f)) * uVar12 - DAT_1008d3a4) / iVar7;
    iStack_24 = iVar7;
    iVar16 = DAT_1008d280;
    if (DAT_1008d43c == 0) {
      if ((iVar4 == iVar15) || (iVar13 == 1)) {
        DAT_1008d2ec = iVar4 - iVar15;
      }
      else if (iVar13 == 2) {
        DAT_1008d2ec = iVar4 - iVar15 >> 1;
      }
      else {
        DAT_1008d2ec = (iVar4 - iVar15) / iVar13;
      }
      if ((iVar3 == iVar15) || (iVar7 == 1)) {
        DAT_1008d2e8 = iVar3 - iVar15;
        DAT_1008d2e4 = iVar15;
      }
      else if (iVar7 == 2) {
        DAT_1008d2e8 = iVar3 - iVar15 >> 1;
        DAT_1008d2e4 = iVar15;
      }
      else {
        DAT_1008d2e8 = (iVar3 - iVar15) / iVar7;
        DAT_1008d2e4 = iVar15;
      }
    }
    else {
      if ((iVar4 == iVar15) || (iVar13 == 1)) {
        DAT_1008d2ec = iVar15 - iVar4;
      }
      else if (iVar13 == 2) {
        DAT_1008d2ec = iVar15 - iVar4 >> 1;
      }
      else {
        DAT_1008d2ec = (iVar15 - iVar4) / iVar13;
      }
      DAT_1008d2e4 = iVar4;
      if (iVar4 == iVar3) {
        DAT_1008d2e8 = iVar3 - iVar4;
      }
      else if (iVar7 == 1) {
        DAT_1008d2e8 = iVar3 - iVar4;
      }
      else if (iVar7 == 2) {
        DAT_1008d2e8 = iVar3 - iVar4 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar3 - iVar4) / iVar7;
      }
    }
  }
  DAT_1008d284 = iVar8 << 0x10;
  DAT_1008d280 = iVar16 << 0x10;
  DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2f0;
LAB_10027a47:
  DAT_1008d290 = iStack_24;
  FUN_10027a70((uint *)&DAT_1008d280);
  return;
}


