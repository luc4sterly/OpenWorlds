// 1000cde0 FUN_1000cde0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000cde0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
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
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1000ce28;
  param_2 = iVar5;
  param_4 = iVar4;
  param_3 = iVar6;
LAB_1000ce28:
  DAT_1007b284 = (uint)*(short *)(param_2 + 0x1e);
  iVar4 = (int)*(short *)(param_2 + 0x1a);
  local_8 = (int)*(short *)(param_3 + 0x1e) - DAT_1007b284;
  iVar6 = (int)*(short *)(param_3 + 0x1a);
  iVar5 = (int)*(short *)(param_4 + 0x1a);
  if ((*(uint *)(*param_1 + 8) & 0x20) == 0) {
    iVar1 = param_1[1];
  }
  else {
    iVar1 = 0x1f0000 - param_1[1];
  }
  DAT_1007b2ac = (uint)*(byte *)((*(uint *)(*param_1 + 8) & 0xffe0) + (iVar1 >> 0x10) + DAT_1007521c
                                );
  iVar1 = DAT_10075214 + 0x1000;
  _DAT_1007b2a8 = (uint)*(byte *)(*param_1 + 4);
  DAT_1007b298 = DAT_10077da4;
  DAT_1007b294 = *(undefined4 *)(DAT_10075218 + DAT_1007b284 * 4);
  _DAT_1007b2a4 = *(undefined4 *)(DAT_10075228 + (DAT_1007b284 & 7) * 4);
  if (local_8 < 1) {
    if (iVar4 == iVar6 || iVar4 - iVar6 < 0) {
      DAT_1007b280 = iVar4;
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    local_8 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_8 == 0) {
      DAT_1007b280 = iVar4;
      DAT_1007b298 = DAT_10077da4;
      return;
    }
    iVar2 = iVar5 - iVar6;
    if (local_8 == 1) {
      DAT_1007b28c = iVar2 * 0x10000;
    }
    else if (local_8 == 2) {
      DAT_1007b28c = iVar2 * 0x8000;
    }
    else if (((local_8 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar1 + (iVar2 * 0x20 + local_8) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007b28c = (iVar2 * 0x10000) / local_8;
    }
    else {
      DAT_1007b28c = (iVar2 * 0x10000) / local_8;
    }
    iVar5 = iVar5 - iVar4;
    if (local_8 == 1) {
      DAT_1007b288 = iVar5 * 0x10000;
    }
    else if (local_8 == 2) {
      DAT_1007b288 = iVar5 * 0x8000;
    }
    else if (((local_8 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1007b288 = *(int *)(iVar1 + (iVar5 * 0x20 + local_8) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1007b288 = (iVar5 * 0x10000) / local_8;
    }
    else {
      DAT_1007b288 = (iVar5 * 0x10000) / local_8;
    }
    DAT_1007b280 = iVar6 << 0x10;
    DAT_1007b284 = iVar4 << 0x10;
  }
  else {
    iVar2 = iVar6 - iVar4;
    if (local_8 == 1) {
      DAT_1007b28c = iVar2 * 0x10000;
    }
    else if (local_8 == 2) {
      DAT_1007b28c = iVar2 * 0x8000;
    }
    else if (((local_8 < 0x20) && (-0x20 < iVar2)) && (iVar2 < 0x20)) {
      DAT_1007b28c = *(int *)(iVar1 + (iVar2 * 0x20 + local_8) * 4);
    }
    else if (iVar2 < 0) {
      DAT_1007b28c = (iVar2 * 0x10000) / local_8;
    }
    else {
      DAT_1007b28c = (iVar2 * 0x10000) / local_8;
    }
    iVar2 = (int)*(short *)(param_4 + 0x1e) - DAT_1007b284;
    if (iVar2 < 1) {
      if (iVar5 == iVar4 || iVar5 - iVar4 < 0) {
        DAT_1007b280 = iVar4;
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      iVar6 = iVar6 - iVar5;
      if (local_8 == 1) {
        DAT_1007b288 = iVar6 * 0x10000;
      }
      else if (local_8 == 2) {
        DAT_1007b288 = iVar6 * 0x8000;
      }
      else if (((local_8 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar1 + (iVar6 * 0x20 + local_8) * 4);
      }
      else if (iVar6 < 0) {
        DAT_1007b288 = (iVar6 * 0x10000) / local_8;
      }
      else {
        DAT_1007b288 = (iVar6 * 0x10000) / local_8;
      }
      DAT_1007b284 = iVar5 << 0x10;
      DAT_1007b280 = iVar4 << 0x10;
    }
    else {
      iVar3 = iVar5 - iVar4;
      if (iVar2 == 1) {
        DAT_1007b288 = iVar3 * 0x10000;
      }
      else if (iVar2 == 2) {
        DAT_1007b288 = iVar3 * 0x8000;
      }
      else if (((iVar2 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
        DAT_1007b288 = *(int *)(iVar1 + (iVar3 * 0x20 + iVar2) * 4);
      }
      else if (iVar3 < 0) {
        DAT_1007b288 = (iVar3 * 0x10000) / iVar2;
      }
      else {
        DAT_1007b288 = (iVar3 * 0x10000) / iVar2;
      }
      if (DAT_1007b288 == DAT_1007b28c || DAT_1007b288 - DAT_1007b28c < 0) {
        DAT_1007b280 = iVar4;
        DAT_1007b298 = DAT_10077da4;
        return;
      }
      DAT_1007b280 = iVar4 << 0x10;
      DAT_1007b284 = DAT_1007b280;
      if (local_8 < iVar2) {
        iVar2 = iVar2 - local_8;
        iVar5 = iVar5 - iVar6;
        DAT_1007b290 = local_8;
        FUN_1000d3b0((uint *)&DAT_1007b280);
        DAT_1007b280 = iVar6 << 0x10;
        local_8 = iVar2;
        if (iVar2 == 1) {
          DAT_1007b28c = iVar5 * 0x10000;
        }
        else if (iVar2 == 2) {
          DAT_1007b28c = iVar5 * 0x8000;
        }
        else if (((iVar2 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
          DAT_1007b28c = *(int *)(iVar1 + (iVar5 * 0x20 + iVar2) * 4);
        }
        else if (iVar5 < 0) {
          DAT_1007b28c = (iVar5 * 0x10000) / iVar2;
        }
        else {
          DAT_1007b28c = (iVar5 * 0x10000) / iVar2;
        }
      }
      else {
        local_8 = local_8 - iVar2;
        DAT_1007b290 = iVar2;
        FUN_1000d3b0((uint *)&DAT_1007b280);
        if (local_8 == 0) {
          return;
        }
        iVar6 = iVar6 - iVar5;
        DAT_1007b284 = iVar5 << 0x10;
        if (local_8 == 1) {
          DAT_1007b288 = iVar6 * 0x10000;
        }
        else if (local_8 == 2) {
          DAT_1007b288 = iVar6 * 0x8000;
        }
        else if (((local_8 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
          DAT_1007b288 = *(int *)(iVar1 + (iVar6 * 0x20 + local_8) * 4);
        }
        else if (iVar6 < 0) {
          DAT_1007b288 = (iVar6 * 0x10000) / local_8;
        }
        else {
          DAT_1007b288 = (iVar6 * 0x10000) / local_8;
        }
      }
    }
  }
  DAT_1007b290 = local_8;
  FUN_1000d3b0((uint *)&DAT_1007b280);
  return;
}


