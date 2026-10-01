// 10019fa0 FUN_10019fa0 [Global]
// program: RWDL6D21.DLL

void FUN_10019fa0(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_18;
  
  iVar2 = param_3;
  iVar7 = param_4;
  iVar10 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar2 = param_2;
      iVar7 = param_3;
      iVar10 = param_4;
    }
LAB_10019fe4:
    param_2 = iVar7;
    param_4 = iVar2;
    param_3 = iVar10;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_10019fe4;
  DAT_1007f284 = (int)*(short *)(param_2 + 0x1e);
  iVar3 = *(short *)(param_3 + 0x1e) - DAT_1007f284;
  DAT_1007f280 = (int)*(short *)(param_2 + 0x1a);
  iVar10 = *(int *)(param_2 + 0x20);
  iVar2 = *(int *)(param_3 + 0x20);
  iVar8 = (int)*(short *)(param_3 + 0x1a);
  iVar4 = (int)*(short *)(param_4 + 0x1a);
  iVar7 = *(int *)(param_4 + 0x20);
  DAT_1007f2a0 = DAT_1007beb0;
  DAT_1007f29c = DAT_1007f284 * DAT_1007beb0 + DAT_10079210;
  uVar1 = *(uint *)(*param_1 + 8);
  DAT_1007f2ac = (uint)(ushort)((ushort)*(byte *)((param_1[2] >> 0x10) * 0x20 +
                                                  ((uVar1 & 0x7c0) >> 6) + 0x400 + DAT_10079220) <<
                                6 | (ushort)*(byte *)((param_1[1] >> 0x10) * 0x20 +
                                                      ((uVar1 & 0xf800) >> 0xb) + DAT_10079220) <<
                                    0xb |
                               (ushort)*(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar1 & 0x1f) +
                                                 0x800 + DAT_10079220));
  iVar9 = DAT_10079214 + 0x1000;
  DAT_1007f2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  if (iVar3 < 1) {
    iVar3 = DAT_1007f280 - iVar8;
    if (iVar3 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    local_18 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_18 == 0) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar5 = iVar4 - iVar8;
    if (local_18 == 1) {
      DAT_1007f28c = iVar5 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1007f28c = iVar5 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar9 + (iVar5 * 0x20 + local_18) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007f28c = (iVar5 * 0x10000) / local_18;
    }
    else {
      DAT_1007f28c = (iVar5 * 0x10000) / local_18;
    }
    iVar4 = iVar4 - DAT_1007f280;
    if (local_18 == 1) {
      DAT_1007f288 = iVar4 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1007f288 = iVar4 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar9 + (iVar4 * 0x20 + local_18) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1007f288 = (iVar4 * 0x10000) / local_18;
    }
    else {
      DAT_1007f288 = (iVar4 * 0x10000) / local_18;
    }
    if ((iVar2 == iVar10) || (iVar3 == 1)) {
      DAT_1007f2ec = iVar10 - iVar2;
    }
    else if (iVar3 == 2) {
      DAT_1007f2ec = iVar10 - iVar2 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar10 - iVar2) / iVar3;
    }
    iVar10 = iVar2;
    iVar4 = DAT_1007f280;
    if ((iVar7 == iVar2) || (local_18 == 1)) {
      DAT_1007f2e8 = iVar7 - iVar2;
    }
    else if (local_18 == 2) {
      DAT_1007f2e8 = iVar7 - iVar2 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar7 - iVar2) / local_18;
    }
  }
  else {
    iVar5 = iVar8 - DAT_1007f280;
    if (iVar3 == 1) {
      DAT_1007f28c = iVar5 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1007f28c = iVar5 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar9 + (iVar5 * 0x20 + iVar3) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007f28c = (iVar5 * 0x10000) / iVar3;
    }
    else {
      DAT_1007f28c = (iVar5 * 0x10000) / iVar3;
    }
    iVar5 = *(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (0 < iVar5) {
      iVar6 = iVar4 - DAT_1007f280;
      if (iVar5 == 1) {
        DAT_1007f288 = iVar6 * 0x10000;
      }
      else if (iVar5 == 2) {
        DAT_1007f288 = iVar6 * 0x8000;
      }
      else if (((iVar5 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar9 + (iVar6 * 0x20 + iVar5) * 4);
      }
      else if (iVar6 < 0) {
        DAT_1007f288 = (iVar6 * 0x10000) / iVar5;
      }
      else {
        DAT_1007f288 = (iVar6 * 0x10000) / iVar5;
      }
      if (DAT_1007f288 - DAT_1007f28c < 1) {
        DAT_1007f298 = DAT_1007bda4;
        DAT_1007f2a0 = DAT_1007beb0;
        return;
      }
      if ((iVar2 == iVar10) || (iVar3 == 1)) {
        DAT_1007f2e8 = iVar2 - iVar10;
      }
      else if (iVar3 == 2) {
        DAT_1007f2e8 = iVar2 - iVar10 >> 1;
      }
      else {
        DAT_1007f2e8 = (iVar2 - iVar10) / iVar3;
      }
      if ((iVar7 == iVar10) || (iVar5 == 1)) {
        iVar6 = iVar7 - iVar10;
      }
      else if (iVar5 == 2) {
        iVar6 = iVar7 - iVar10 >> 1;
      }
      else {
        iVar6 = (iVar7 - iVar10) / iVar5;
      }
      DAT_1007f2ec = iVar6 - DAT_1007f2e8;
      if ((DAT_1007f2ec != 0) && (iVar6 = DAT_1007f288 - DAT_1007f28c >> 6, iVar6 != 0)) {
        DAT_1007f2ec = DAT_1007f2ec / iVar6 << 10;
      }
      DAT_1007f280 = DAT_1007f280 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (iVar3 < iVar5) {
        local_18 = iVar5 - iVar3;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar10;
        DAT_1007f290 = iVar3;
        FUN_10069d78();
        DAT_1007f280 = iVar8 << 0x10;
        iVar4 = iVar4 - iVar8;
        if (local_18 == 1) {
          DAT_1007f28c = iVar4 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1007f28c = iVar4 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar9 + (iVar4 * 0x20 + local_18) * 4);
        }
        else if (iVar4 < 0) {
          DAT_1007f28c = (iVar4 * 0x10000) / local_18;
        }
        else {
          DAT_1007f28c = (iVar4 * 0x10000) / local_18;
        }
        if (iVar7 == iVar2) {
          DAT_1007f2e8 = iVar7 - iVar2;
        }
        else if (local_18 == 1) {
          DAT_1007f2e8 = iVar7 - iVar2;
        }
        else if (local_18 == 2) {
          DAT_1007f2e8 = iVar7 - iVar2 >> 1;
        }
        else {
          DAT_1007f2e8 = (iVar7 - iVar2) / local_18;
        }
      }
      else {
        local_18 = iVar3 - iVar5;
        DAT_1007f2e4 = DAT_1007f2f0 + iVar10;
        DAT_1007f290 = iVar5;
        FUN_10069d78();
        if (local_18 == 0) {
          return;
        }
        DAT_1007f284 = iVar4 << 0x10;
        iVar8 = iVar8 - iVar4;
        if (local_18 == 1) {
          DAT_1007f288 = iVar8 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1007f288 = iVar8 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar9 + (iVar8 * 0x20 + local_18) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1007f288 = (iVar8 * 0x10000) / local_18;
        }
        else {
          DAT_1007f288 = (iVar8 * 0x10000) / local_18;
        }
      }
      goto LAB_1001a7d2;
    }
    iVar5 = iVar4 - DAT_1007f280;
    if (iVar5 < 1) {
      DAT_1007f298 = DAT_1007bda4;
      DAT_1007f2a0 = DAT_1007beb0;
      return;
    }
    iVar8 = iVar8 - iVar4;
    if (iVar3 == 1) {
      DAT_1007f288 = iVar8 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1007f288 = iVar8 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar9 + (iVar8 * 0x20 + iVar3) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1007f288 = (iVar8 * 0x10000) / iVar3;
    }
    else {
      DAT_1007f288 = (iVar8 * 0x10000) / iVar3;
    }
    if ((iVar7 == iVar10) || (iVar5 == 1)) {
      DAT_1007f2ec = iVar7 - iVar10;
    }
    else if (iVar5 == 2) {
      DAT_1007f2ec = iVar7 - iVar10 >> 1;
    }
    else {
      DAT_1007f2ec = (iVar7 - iVar10) / iVar5;
    }
    local_18 = iVar3;
    iVar8 = DAT_1007f280;
    if ((iVar2 == iVar10) || (iVar3 == 1)) {
      DAT_1007f2e8 = iVar2 - iVar10;
    }
    else if (iVar3 == 2) {
      DAT_1007f2e8 = iVar2 - iVar10 >> 1;
    }
    else {
      DAT_1007f2e8 = (iVar2 - iVar10) / iVar3;
    }
  }
  DAT_1007f284 = iVar4 << 0x10;
  DAT_1007f280 = iVar8 << 0x10;
  DAT_1007f2e4 = DAT_1007f2f0 + iVar10;
LAB_1001a7d2:
  DAT_1007f290 = local_18;
  FUN_10069d78();
  return;
}


