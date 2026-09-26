// 1001c310 FUN_1001c310 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001c310(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_c;
  
  iVar2 = param_3;
  iVar5 = param_4;
  iVar6 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar2 = param_2;
      iVar5 = param_3;
      iVar6 = param_4;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1001c356;
  param_2 = iVar5;
  param_4 = iVar2;
  param_3 = iVar6;
LAB_1001c356:
  DAT_1008d284 = (int)*(short *)(param_2 + 0x1e);
  local_c = *(short *)(param_3 + 0x1e) - DAT_1008d284;
  iVar2 = (int)*(short *)(param_2 + 0x1a);
  iVar5 = (int)*(short *)(param_4 + 0x1a);
  iVar6 = (int)*(short *)(param_3 + 0x1a);
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  uVar1 = *(uint *)(*param_1 + 8);
  iVar7 = DAT_1008723c + 0x1000;
  _DAT_1008d2ac =
       (uint)(ushort)((ushort)*(byte *)((param_1[2] >> 0x10) * 0x20 + ((uVar1 & 0x7c0) >> 6) + 0x400
                                       + DAT_10087248) << 6 |
                      (ushort)*(byte *)((param_1[1] >> 0x10) * 0x20 + ((uVar1 & 0xf800) >> 0xb) +
                                       DAT_10087248) << 0xb |
                     (ushort)*(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                      DAT_10087248));
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  if (local_c < 1) {
    if (iVar2 == iVar6 || iVar2 - iVar6 < 0) {
      DAT_1008d280 = iVar2;
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    local_c = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_c == 0) {
      DAT_1008d280 = iVar2;
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar3 = iVar5 - iVar6;
    if (local_c == 1) {
      DAT_1008d28c = iVar3 * 0x10000;
    }
    else if (local_c == 2) {
      DAT_1008d28c = iVar3 * 0x8000;
    }
    else if (((local_c < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar7 + (iVar3 * 0x20 + local_c) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1008d28c = (iVar3 * 0x10000) / local_c;
    }
    else {
      DAT_1008d28c = (iVar3 * 0x10000) / local_c;
    }
    iVar5 = iVar5 - iVar2;
    if (local_c == 1) {
      DAT_1008d288 = iVar5 * 0x10000;
    }
    else if (local_c == 2) {
      DAT_1008d288 = iVar5 * 0x8000;
    }
    else if (((local_c < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar7 + (iVar5 * 0x20 + local_c) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d288 = (iVar5 * 0x10000) / local_c;
    }
    else {
      DAT_1008d288 = (iVar5 * 0x10000) / local_c;
    }
    DAT_1008d280 = iVar6 << 0x10;
    DAT_1008d284 = iVar2 << 0x10;
  }
  else {
    iVar3 = iVar6 - iVar2;
    if (local_c == 1) {
      DAT_1008d28c = iVar3 * 0x10000;
    }
    else if (local_c == 2) {
      DAT_1008d28c = iVar3 * 0x8000;
    }
    else if (((local_c < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar7 + (iVar3 * 0x20 + local_c) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1008d28c = (iVar3 * 0x10000) / local_c;
    }
    else {
      DAT_1008d28c = (iVar3 * 0x10000) / local_c;
    }
    iVar3 = *(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (iVar3 < 1) {
      if (iVar5 == iVar2 || iVar5 - iVar2 < 0) {
        DAT_1008d280 = iVar2;
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar6 = iVar6 - iVar5;
      if (local_c == 1) {
        DAT_1008d288 = iVar6 * 0x10000;
      }
      else if (local_c == 2) {
        DAT_1008d288 = iVar6 * 0x8000;
      }
      else if (((local_c < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar7 + (iVar6 * 0x20 + local_c) * 4);
      }
      else if (iVar6 < 0) {
        DAT_1008d288 = (iVar6 * 0x10000) / local_c;
      }
      else {
        DAT_1008d288 = (iVar6 * 0x10000) / local_c;
      }
      DAT_1008d284 = iVar5 << 0x10;
      DAT_1008d280 = iVar2 << 0x10;
    }
    else {
      iVar4 = iVar5 - iVar2;
      if (iVar3 == 1) {
        DAT_1008d288 = iVar4 * 0x10000;
      }
      else if (iVar3 == 2) {
        DAT_1008d288 = iVar4 * 0x8000;
      }
      else if (((iVar3 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar7 + (iVar4 * 0x20 + iVar3) * 4);
      }
      else if (iVar4 < 0) {
        DAT_1008d288 = (iVar4 * 0x10000) / iVar3;
      }
      else {
        DAT_1008d288 = (iVar4 * 0x10000) / iVar3;
      }
      if (DAT_1008d288 == DAT_1008d28c || DAT_1008d288 - DAT_1008d28c < 0) {
        DAT_1008d280 = iVar2;
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      DAT_1008d280 = iVar2 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (local_c < iVar3) {
        iVar3 = iVar3 - local_c;
        iVar5 = iVar5 - iVar6;
        DAT_1008d290 = local_c;
        FUN_10078200();
        DAT_1008d280 = iVar6 << 0x10;
        local_c = iVar3;
        if (iVar3 == 1) {
          DAT_1008d28c = iVar5 * 0x10000;
        }
        else if (iVar3 == 2) {
          DAT_1008d28c = iVar5 * 0x8000;
        }
        else if (((iVar3 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar7 + (iVar5 * 0x20 + iVar3) * 4);
        }
        else if (iVar5 < 0) {
          DAT_1008d28c = (iVar5 * 0x10000) / iVar3;
        }
        else {
          DAT_1008d28c = (iVar5 * 0x10000) / iVar3;
        }
      }
      else {
        local_c = local_c - iVar3;
        DAT_1008d290 = iVar3;
        FUN_10078200();
        if (local_c == 0) {
          return;
        }
        iVar6 = iVar6 - iVar5;
        DAT_1008d284 = iVar5 << 0x10;
        if (local_c == 1) {
          DAT_1008d288 = iVar6 * 0x10000;
        }
        else if (local_c == 2) {
          DAT_1008d288 = iVar6 * 0x8000;
        }
        else if (((local_c < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar7 + (iVar6 * 0x20 + local_c) * 4);
        }
        else if (iVar6 < 0) {
          DAT_1008d288 = (iVar6 * 0x10000) / local_c;
        }
        else {
          DAT_1008d288 = (iVar6 * 0x10000) / local_c;
        }
      }
    }
  }
  DAT_1008d290 = local_c;
  FUN_10078200();
  return;
}


