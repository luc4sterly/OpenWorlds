// 10019920 FUN_10019920 [Global]
// program: RWDL6D21.DLL

void FUN_10019920(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  iVar4 = param_3;
  iVar5 = param_4;
  iVar6 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar4 = param_2;
      iVar5 = param_3;
      iVar6 = param_4;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_10019966;
  param_2 = iVar5;
  param_4 = iVar4;
  param_3 = iVar6;
LAB_10019966:
  DAT_1007f284 = (int)*(short *)(param_2 + 0x1e);
  iVar4 = (int)*(short *)(param_2 + 0x1a);
  local_8 = *(short *)(param_3 + 0x1e) - DAT_1007f284;
  iVar6 = (int)*(short *)(param_3 + 0x1a);
  iVar7 = (int)*(short *)(param_4 + 0x1a);
  uVar1 = *(uint *)(*param_1 + 8);
  iVar5 = DAT_10079214 + 0x1000;
  DAT_1007f2ac = (uint)(ushort)((ushort)*(byte *)((param_1[2] >> 0x10) * 0x20 +
                                                  ((uVar1 & 0x7c0) >> 6) + 0x400 + DAT_10079220) <<
                                6 | (ushort)*(byte *)((param_1[1] >> 0x10) * 0x20 +
                                                      ((uVar1 & 0xf800) >> 0xb) + DAT_10079220) <<
                                    0xb |
                               (ushort)*(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar1 & 0x1f) +
                                                 0x800 + DAT_10079220));
  DAT_1007f298 = DAT_1007bda4;
  DAT_1007f294 = *(undefined4 *)(DAT_10079218 + DAT_1007f284 * 4);
  if (local_8 < 1) {
    if (iVar4 == iVar6 || iVar4 - iVar6 < 0) {
      DAT_1007f280 = iVar4;
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    local_8 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_8 == 0) {
      DAT_1007f280 = iVar4;
      DAT_1007f298 = DAT_1007bda4;
      return;
    }
    iVar2 = iVar7 - iVar6;
    if (local_8 == 1) {
      DAT_1007f28c = iVar2 * 0x10000;
    }
    else if (local_8 == 2) {
      DAT_1007f28c = iVar2 * 0x8000;
    }
    else if (((local_8 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar5 + (iVar2 * 0x20 + local_8) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007f28c = (iVar2 * 0x10000) / local_8;
    }
    else {
      DAT_1007f28c = (iVar2 * 0x10000) / local_8;
    }
    iVar7 = iVar7 - iVar4;
    if (local_8 == 1) {
      DAT_1007f288 = iVar7 * 0x10000;
    }
    else if (local_8 == 2) {
      DAT_1007f288 = iVar7 * 0x8000;
    }
    else if (((local_8 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
      DAT_1007f288 = *(int *)(iVar5 + (iVar7 * 0x20 + local_8) * 4);
    }
    else if (iVar7 < 0) {
      DAT_1007f288 = (iVar7 * 0x10000) / local_8;
    }
    else {
      DAT_1007f288 = (iVar7 * 0x10000) / local_8;
    }
    DAT_1007f280 = iVar6 << 0x10;
    DAT_1007f284 = iVar4 << 0x10;
  }
  else {
    iVar2 = iVar6 - iVar4;
    if (local_8 == 1) {
      DAT_1007f28c = iVar2 * 0x10000;
    }
    else if (local_8 == 2) {
      DAT_1007f28c = iVar2 * 0x8000;
    }
    else if (((local_8 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007f28c = *(int *)(iVar5 + (iVar2 * 0x20 + local_8) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007f28c = (iVar2 * 0x10000) / local_8;
    }
    else {
      DAT_1007f28c = (iVar2 * 0x10000) / local_8;
    }
    iVar2 = *(short *)(param_4 + 0x1e) - DAT_1007f284;
    if (iVar2 < 1) {
      if (iVar7 == iVar4 || iVar7 - iVar4 < 0) {
        DAT_1007f280 = iVar4;
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      iVar6 = iVar6 - iVar7;
      if (local_8 == 1) {
        DAT_1007f288 = iVar6 * 0x10000;
      }
      else if (local_8 == 2) {
        DAT_1007f288 = iVar6 * 0x8000;
      }
      else if (((local_8 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar5 + (iVar6 * 0x20 + local_8) * 4);
      }
      else if (iVar6 < 0) {
        DAT_1007f288 = (iVar6 * 0x10000) / local_8;
      }
      else {
        DAT_1007f288 = (iVar6 * 0x10000) / local_8;
      }
      DAT_1007f284 = iVar7 << 0x10;
      DAT_1007f280 = iVar4 << 0x10;
    }
    else {
      iVar3 = iVar7 - iVar4;
      if (iVar2 == 1) {
        DAT_1007f288 = iVar3 * 0x10000;
      }
      else if (iVar2 == 2) {
        DAT_1007f288 = iVar3 * 0x8000;
      }
      else if (((iVar2 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
        DAT_1007f288 = *(int *)(iVar5 + (iVar3 * 0x20 + iVar2) * 4);
      }
      else if (iVar3 < 0) {
        DAT_1007f288 = (iVar3 * 0x10000) / iVar2;
      }
      else {
        DAT_1007f288 = (iVar3 * 0x10000) / iVar2;
      }
      if (DAT_1007f288 == DAT_1007f28c || DAT_1007f288 - DAT_1007f28c < 0) {
        DAT_1007f280 = iVar4;
        DAT_1007f298 = DAT_1007bda4;
        return;
      }
      DAT_1007f280 = iVar4 << 0x10;
      DAT_1007f284 = DAT_1007f280;
      if (local_8 < iVar2) {
        iVar2 = iVar2 - local_8;
        iVar7 = iVar7 - iVar6;
        DAT_1007f290 = local_8;
        FUN_10069cd0();
        DAT_1007f280 = iVar6 << 0x10;
        local_8 = iVar2;
        if (iVar2 == 1) {
          DAT_1007f28c = iVar7 * 0x10000;
        }
        else if (iVar2 == 2) {
          DAT_1007f28c = iVar7 * 0x8000;
        }
        else if (((iVar2 < 0x20) && (-0x20 < iVar7)) && (iVar7 < 0x20)) {
          DAT_1007f28c = *(int *)(iVar5 + (iVar7 * 0x20 + iVar2) * 4);
        }
        else if (iVar7 < 0) {
          DAT_1007f28c = (iVar7 * 0x10000) / iVar2;
        }
        else {
          DAT_1007f28c = (iVar7 * 0x10000) / iVar2;
        }
      }
      else {
        local_8 = local_8 - iVar2;
        DAT_1007f290 = iVar2;
        FUN_10069cd0();
        if (local_8 == 0) {
          return;
        }
        iVar6 = iVar6 - iVar7;
        DAT_1007f284 = iVar7 << 0x10;
        if (local_8 == 1) {
          DAT_1007f288 = iVar6 * 0x10000;
        }
        else if (local_8 == 2) {
          DAT_1007f288 = iVar6 * 0x8000;
        }
        else if (((local_8 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
          DAT_1007f288 = *(int *)(iVar5 + (iVar6 * 0x20 + local_8) * 4);
        }
        else if (iVar6 < 0) {
          DAT_1007f288 = (iVar6 * 0x10000) / local_8;
        }
        else {
          DAT_1007f288 = (iVar6 * 0x10000) / local_8;
        }
      }
    }
  }
  DAT_1007f290 = local_8;
  FUN_10069cd0();
  return;
}


