// 1001c9a0 FUN_1001c9a0 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001c9a0(int *param_1,int param_2,int param_3,int param_4)

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
  iVar9 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar2 = param_2;
      iVar7 = param_3;
      iVar9 = param_4;
    }
LAB_1001c9e4:
    param_2 = iVar7;
    param_4 = iVar2;
    param_3 = iVar9;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1001c9e4;
  DAT_1008d284 = (int)*(short *)(param_2 + 0x1e);
  iVar3 = *(short *)(param_3 + 0x1e) - DAT_1008d284;
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  iVar8 = (int)*(short *)(param_3 + 0x1a);
  iVar4 = (int)*(short *)(param_4 + 0x1a);
  iVar9 = *(int *)(param_2 + 0x20);
  iVar2 = *(int *)(param_3 + 0x20);
  iVar7 = *(int *)(param_4 + 0x20);
  DAT_1008d29c = DAT_10089ef4 * DAT_1008d284 + DAT_10087238;
  DAT_1008d2a0 = DAT_10089ef4;
  _DAT_1008d2a8 = (uint)*(byte *)(*param_1 + 4);
  uVar1 = *(uint *)(*param_1 + 8);
  _DAT_1008d2ac =
       (uint)(ushort)((ushort)*(byte *)((param_1[2] >> 0x10) * 0x20 + ((uVar1 & 0x7c0) >> 6) + 0x400
                                       + DAT_10087248) << 6 |
                      (ushort)*(byte *)((param_1[1] >> 0x10) * 0x20 + ((uVar1 & 0xf800) >> 0xb) +
                                       DAT_10087248) << 0xb |
                     (ushort)*(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                      DAT_10087248));
  iVar10 = DAT_1008723c + 0x1000;
  DAT_1008d2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1008d298 = DAT_10089ddc;
  DAT_1008d294 = *(undefined4 *)(DAT_10087240 + DAT_1008d284 * 4);
  if (iVar3 < 1) {
    iVar3 = DAT_1008d280 - iVar8;
    if (iVar3 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    local_18 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_18 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar5 = iVar4 - iVar8;
    if (local_18 == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar10 + (iVar5 * 0x20 + local_18) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / local_18;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / local_18;
    }
    iVar4 = iVar4 - DAT_1008d280;
    if (local_18 == 1) {
      DAT_1008d288 = iVar4 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1008d288 = iVar4 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar10 + (iVar4 * 0x20 + local_18) * 4);
    }
    else if (iVar4 < 0) {
      DAT_1008d288 = (iVar4 * 0x10000) / local_18;
    }
    else {
      DAT_1008d288 = (iVar4 * 0x10000) / local_18;
    }
    if ((iVar2 == iVar9) || (iVar3 == 1)) {
      DAT_1008d2ec = iVar9 - iVar2;
    }
    else if (iVar3 == 2) {
      DAT_1008d2ec = iVar9 - iVar2 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar9 - iVar2) / iVar3;
    }
    iVar9 = iVar2;
    iVar4 = DAT_1008d280;
    if ((iVar7 == iVar2) || (local_18 == 1)) {
      DAT_1008d2e8 = iVar7 - iVar2;
    }
    else if (local_18 == 2) {
      DAT_1008d2e8 = iVar7 - iVar2 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar7 - iVar2) / local_18;
    }
  }
  else {
    iVar5 = iVar8 - DAT_1008d280;
    if (iVar3 == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar10 + (iVar5 * 0x20 + iVar3) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / iVar3;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / iVar3;
    }
    iVar5 = *(short *)(param_4 + 0x1e) - DAT_1008d284;
    if (0 < iVar5) {
      iVar6 = iVar4 - DAT_1008d280;
      if (iVar5 == 1) {
        DAT_1008d288 = iVar6 * 0x10000;
      }
      else if (iVar5 == 2) {
        DAT_1008d288 = iVar6 * 0x8000;
      }
      else if (((iVar5 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar10 + (iVar6 * 0x20 + iVar5) * 4);
      }
      else if (iVar6 < 0) {
        DAT_1008d288 = (iVar6 * 0x10000) / iVar5;
      }
      else {
        DAT_1008d288 = (iVar6 * 0x10000) / iVar5;
      }
      if (DAT_1008d288 - DAT_1008d28c < 1) {
        DAT_1008d298 = DAT_10089ddc;
        DAT_1008d2a0 = DAT_10089ef4;
        return;
      }
      if ((iVar2 == iVar9) || (iVar3 == 1)) {
        DAT_1008d2e8 = iVar2 - iVar9;
      }
      else if (iVar3 == 2) {
        DAT_1008d2e8 = iVar2 - iVar9 >> 1;
      }
      else {
        DAT_1008d2e8 = (iVar2 - iVar9) / iVar3;
      }
      if ((iVar7 == iVar9) || (iVar5 == 1)) {
        iVar6 = iVar7 - iVar9;
      }
      else if (iVar5 == 2) {
        iVar6 = iVar7 - iVar9 >> 1;
      }
      else {
        iVar6 = (iVar7 - iVar9) / iVar5;
      }
      DAT_1008d2ec = iVar6 - DAT_1008d2e8;
      if ((DAT_1008d2ec != 0) && (iVar6 = DAT_1008d288 - DAT_1008d28c >> 6, iVar6 != 0)) {
        DAT_1008d2ec = DAT_1008d2ec / iVar6 << 10;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      if (iVar3 < iVar5) {
        local_18 = iVar5 - iVar3;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar9;
        DAT_1008d290 = iVar3;
        FUN_10078450();
        DAT_1008d280 = iVar8 << 0x10;
        iVar4 = iVar4 - iVar8;
        if (local_18 == 1) {
          DAT_1008d28c = iVar4 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1008d28c = iVar4 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar4)) && (iVar4 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar10 + (iVar4 * 0x20 + local_18) * 4);
        }
        else if (iVar4 < 0) {
          DAT_1008d28c = (iVar4 * 0x10000) / local_18;
        }
        else {
          DAT_1008d28c = (iVar4 * 0x10000) / local_18;
        }
        if (iVar7 == iVar2) {
          DAT_1008d2e8 = iVar7 - iVar2;
        }
        else if (local_18 == 1) {
          DAT_1008d2e8 = iVar7 - iVar2;
        }
        else if (local_18 == 2) {
          DAT_1008d2e8 = iVar7 - iVar2 >> 1;
        }
        else {
          DAT_1008d2e8 = (iVar7 - iVar2) / local_18;
        }
      }
      else {
        local_18 = iVar3 - iVar5;
        DAT_1008d2e4 = DAT_1008d2f0 + iVar9;
        DAT_1008d290 = iVar5;
        FUN_10078450();
        if (local_18 == 0) {
          return;
        }
        DAT_1008d284 = iVar4 << 0x10;
        iVar8 = iVar8 - iVar4;
        if (local_18 == 1) {
          DAT_1008d288 = iVar8 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1008d288 = iVar8 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar10 + (iVar8 * 0x20 + local_18) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1008d288 = (iVar8 * 0x10000) / local_18;
        }
        else {
          DAT_1008d288 = (iVar8 * 0x10000) / local_18;
        }
      }
      goto LAB_1001d1da;
    }
    iVar5 = iVar4 - DAT_1008d280;
    if (iVar5 < 1) {
      DAT_1008d298 = DAT_10089ddc;
      DAT_1008d2a0 = DAT_10089ef4;
      return;
    }
    iVar8 = iVar8 - iVar4;
    if (iVar3 == 1) {
      DAT_1008d288 = iVar8 * 0x10000;
    }
    else if (iVar3 == 2) {
      DAT_1008d288 = iVar8 * 0x8000;
    }
    else if (((iVar3 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar10 + (iVar8 * 0x20 + iVar3) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1008d288 = (iVar8 * 0x10000) / iVar3;
    }
    else {
      DAT_1008d288 = (iVar8 * 0x10000) / iVar3;
    }
    if ((iVar7 == iVar9) || (iVar5 == 1)) {
      DAT_1008d2ec = iVar7 - iVar9;
    }
    else if (iVar5 == 2) {
      DAT_1008d2ec = iVar7 - iVar9 >> 1;
    }
    else {
      DAT_1008d2ec = (iVar7 - iVar9) / iVar5;
    }
    local_18 = iVar3;
    iVar8 = DAT_1008d280;
    if ((iVar2 == iVar9) || (iVar3 == 1)) {
      DAT_1008d2e8 = iVar2 - iVar9;
    }
    else if (iVar3 == 2) {
      DAT_1008d2e8 = iVar2 - iVar9 >> 1;
    }
    else {
      DAT_1008d2e8 = (iVar2 - iVar9) / iVar3;
    }
  }
  DAT_1008d284 = iVar4 << 0x10;
  DAT_1008d280 = iVar8 << 0x10;
  DAT_1008d2e4 = DAT_1008d2f0 + iVar9;
LAB_1001d1da:
  DAT_1008d290 = local_18;
  FUN_10078450();
  return;
}


