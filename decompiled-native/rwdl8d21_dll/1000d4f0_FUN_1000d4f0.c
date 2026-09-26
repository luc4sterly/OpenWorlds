// 1000d4f0 FUN_1000d4f0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000d4f0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_14;
  
  iVar1 = param_3;
  iVar7 = param_4;
  iVar9 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar1 = param_2;
      iVar7 = param_3;
      iVar9 = param_4;
    }
LAB_1000d534:
    param_2 = iVar7;
    param_4 = iVar1;
    param_3 = iVar9;
  }
  else if (*(int *)(param_4 + 0x1c) < *(int *)(param_2 + 0x1c)) goto LAB_1000d534;
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar2 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  DAT_1007b280 = (int)*(short *)(param_2 + 0x1a);
  iVar9 = *(int *)(param_2 + 0x20);
  iVar1 = *(int *)(param_3 + 0x20);
  iVar8 = (int)*(short *)(param_3 + 0x1a);
  iVar3 = (int)*(short *)(param_4 + 0x1a);
  iVar7 = *(int *)(param_4 + 0x20);
  DAT_1007b29c = DAT_1007b284 * DAT_10077eb0 + DAT_10075210;
  DAT_1007b2a0 = DAT_10077eb0;
  if ((*(uint *)(*param_1 + 8) & 0x20) == 0) {
    iVar4 = param_1[1];
  }
  else {
    iVar4 = 0x1f0000 - param_1[1];
  }
  DAT_1007b2ac = (uint)*(byte *)((*(uint *)(*param_1 + 8) & 0xffe0) + (iVar4 >> 0x10) + DAT_1007521c
                                );
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  iVar4 = DAT_10075214 + 0x1000;
  DAT_1007b2f0 = (int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000;
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  if (iVar2 < 1) {
    iVar2 = DAT_1007b280 - iVar8;
    if (iVar2 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    local_14 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_14 == 0) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar5 = iVar3 - iVar8;
    if (local_14 == 1) {
      DAT_1007b28c = iVar5 * 0x10000;
    }
    else if (local_14 == 2) {
      DAT_1007b28c = iVar5 * 0x8000;
    }
    else if (((local_14 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar4 + (iVar5 * 0x20 + local_14) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007b28c = (iVar5 * 0x10000) / local_14;
    }
    else {
      DAT_1007b28c = (iVar5 * 0x10000) / local_14;
    }
    iVar3 = iVar3 - DAT_1007b280;
    if (local_14 == 1) {
      DAT_1007b288 = iVar3 * 0x10000;
    }
    else if (local_14 == 2) {
      DAT_1007b288 = iVar3 * 0x8000;
    }
    else if (((local_14 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar4 + (iVar3 * 0x20 + local_14) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1007b288 = (iVar3 * 0x10000) / local_14;
    }
    else {
      DAT_1007b288 = (iVar3 * 0x10000) / local_14;
    }
    if ((iVar1 == iVar9) || (iVar2 == 1)) {
      DAT_1007b2ec = iVar9 - iVar1;
    }
    else if (iVar2 == 2) {
      DAT_1007b2ec = iVar9 - iVar1 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar9 - iVar1) / iVar2;
    }
    iVar9 = iVar1;
    iVar3 = DAT_1007b280;
    if ((iVar7 == iVar1) || (local_14 == 1)) {
      DAT_1007b2e8 = iVar7 - iVar1;
    }
    else if (local_14 == 2) {
      DAT_1007b2e8 = iVar7 - iVar1 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar7 - iVar1) / local_14;
    }
  }
  else {
    iVar5 = iVar8 - DAT_1007b280;
    if (iVar2 == 1) {
      DAT_1007b28c = iVar5 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b28c = iVar5 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar4 + (iVar5 * 0x20 + iVar2) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007b28c = (iVar5 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b28c = (iVar5 * 0x10000) / iVar2;
    }
    iVar5 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (0 < iVar5) {
      iVar6 = iVar3 - DAT_1007b280;
      if (iVar5 == 1) {
        DAT_1007b288 = iVar6 * 0x10000;
      }
      else if (iVar5 == 2) {
        DAT_1007b288 = iVar6 * 0x8000;
      }
      else if (((iVar5 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar4 + (iVar6 * 0x20 + iVar5) * 4);
      }
      else if (iVar6 < 0) {
        DAT_1007b288 = (iVar6 * 0x10000) / iVar5;
      }
      else {
        DAT_1007b288 = (iVar6 * 0x10000) / iVar5;
      }
      if (DAT_1007b288 - DAT_1007b28c < 1) {
        DAT_1007b298 = DAT_10077da4;
        DAT_1007b2a0 = DAT_10077eb0;
        return;
      }
      if ((iVar1 == iVar9) || (iVar2 == 1)) {
        DAT_1007b2e8 = iVar1 - iVar9;
      }
      else if (iVar2 == 2) {
        DAT_1007b2e8 = iVar1 - iVar9 >> 1;
      }
      else {
        DAT_1007b2e8 = (iVar1 - iVar9) / iVar2;
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
      DAT_1007b2ec = iVar6 - DAT_1007b2e8;
      if ((DAT_1007b2ec != 0) && (iVar6 = DAT_1007b288 - DAT_1007b28c >> 6, iVar6 != 0)) {
        DAT_1007b2ec = DAT_1007b2ec / iVar6 << 10;
      }
      DAT_1007b280 = DAT_1007b280 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (iVar2 < iVar5) {
        local_14 = iVar5 - iVar2;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar9;
        DAT_1007b290 = iVar2;
        FUN_1000dd00((uint *)&DAT_1007b280);
        DAT_1007b280 = iVar8 << 0x10;
        iVar3 = iVar3 - iVar8;
        if (local_14 == 1) {
          DAT_1007b28c = iVar3 * 0x10000;
        }
        else if (local_14 == 2) {
          DAT_1007b28c = iVar3 * 0x8000;
        }
        else if (((local_14 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar4 + (iVar3 * 0x20 + local_14) * 4);
        }
        else if (iVar3 < 0) {
          DAT_1007b28c = (iVar3 * 0x10000) / local_14;
        }
        else {
          DAT_1007b28c = (iVar3 * 0x10000) / local_14;
        }
        if (iVar7 == iVar1) {
          DAT_1007b2e8 = iVar7 - iVar1;
        }
        else if (local_14 == 1) {
          DAT_1007b2e8 = iVar7 - iVar1;
        }
        else if (local_14 == 2) {
          DAT_1007b2e8 = iVar7 - iVar1 >> 1;
        }
        else {
          DAT_1007b2e8 = (iVar7 - iVar1) / local_14;
        }
      }
      else {
        local_14 = iVar2 - iVar5;
        DAT_1007b2e4 = DAT_1007b2f0 + iVar9;
        DAT_1007b290 = iVar5;
        FUN_1000dd00((uint *)&DAT_1007b280);
        if (local_14 == 0) {
          return;
        }
        DAT_1007b284 = iVar3 << 0x10;
        iVar8 = iVar8 - iVar3;
        if (local_14 == 1) {
          DAT_1007b288 = iVar8 * 0x10000;
        }
        else if (local_14 == 2) {
          DAT_1007b288 = iVar8 * 0x8000;
        }
        else if (((local_14 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar4 + (iVar8 * 0x20 + local_14) * 4);
        }
        else if (iVar8 < 0) {
          DAT_1007b288 = (iVar8 * 0x10000) / local_14;
        }
        else {
          DAT_1007b288 = (iVar8 * 0x10000) / local_14;
        }
      }
      goto LAB_1000dce3;
    }
    iVar5 = iVar3 - DAT_1007b280;
    if (iVar5 < 1) {
      DAT_1007b298 = DAT_10077da4;
      DAT_1007b2a0 = DAT_10077eb0;
      return;
    }
    iVar8 = iVar8 - iVar3;
    if (iVar2 == 1) {
      DAT_1007b288 = iVar8 * 0x10000;
    }
    else if (iVar2 == 2) {
      DAT_1007b288 = iVar8 * 0x8000;
    }
    else if (((iVar2 < 0x20) && (-0x20 < iVar8)) && (iVar8 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar4 + (iVar8 * 0x20 + iVar2) * 4);
    }
    else if (iVar8 < 0) {
      DAT_1007b288 = (iVar8 * 0x10000) / iVar2;
    }
    else {
      DAT_1007b288 = (iVar8 * 0x10000) / iVar2;
    }
    if ((iVar7 == iVar9) || (iVar5 == 1)) {
      DAT_1007b2ec = iVar7 - iVar9;
    }
    else if (iVar5 == 2) {
      DAT_1007b2ec = iVar7 - iVar9 >> 1;
    }
    else {
      DAT_1007b2ec = (iVar7 - iVar9) / iVar5;
    }
    local_14 = iVar2;
    iVar8 = DAT_1007b280;
    if ((iVar1 == iVar9) || (iVar2 == 1)) {
      DAT_1007b2e8 = iVar1 - iVar9;
    }
    else if (iVar2 == 2) {
      DAT_1007b2e8 = iVar1 - iVar9 >> 1;
    }
    else {
      DAT_1007b2e8 = (iVar1 - iVar9) / iVar2;
    }
  }
  DAT_1007b284 = iVar3 << 0x10;
  DAT_1007b280 = iVar8 << 0x10;
  DAT_1007b2e4 = DAT_1007b2f0 + iVar9;
LAB_1000dce3:
  DAT_1007b290 = local_14;
  FUN_1000dd00((uint *)&DAT_1007b280);
  return;
}


