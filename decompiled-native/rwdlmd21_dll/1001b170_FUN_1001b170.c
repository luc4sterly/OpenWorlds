// 1001b170 FUN_1001b170 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b170(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  undefined2 *puVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  int local_18;
  
  iVar4 = param_3;
  iVar11 = param_4;
  iVar3 = param_2;
  if (*(int *)(param_3 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    if (*(int *)(param_3 + 0x1c) < *(int *)(param_4 + 0x1c)) {
      iVar4 = param_2;
      iVar11 = param_3;
      iVar3 = param_4;
    }
  }
  else if (*(int *)(param_2 + 0x1c) <= *(int *)(param_4 + 0x1c)) goto LAB_1001b1b8;
  param_2 = iVar11;
  param_4 = iVar4;
  param_3 = iVar3;
LAB_1001b1b8:
  DAT_1008d284 = (int)*(short *)(param_2 + 0x1e);
  DAT_1008d280 = (int)*(short *)(param_2 + 0x1a);
  local_18 = *(short *)(param_3 + 0x1e) - DAT_1008d284;
  iVar11 = (int)*(short *)(param_3 + 0x1a);
  iVar3 = (int)*(short *)(param_4 + 0x1a);
  uVar1 = *(uint *)(*param_1 + 8);
  uVar10 = (ushort)*(byte *)((param_1[2] >> 0x10) * 0x20 + ((uVar1 & 0x7c0) >> 6) + 0x400 +
                            DAT_10087248) << 6 |
           (ushort)*(byte *)((param_1[1] >> 0x10) * 0x20 + ((uVar1 & 0xf800) >> 0xb) + DAT_10087248)
           << 0xb | (ushort)*(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                     DAT_10087248);
  _DAT_1008d2ac = (uint)uVar10;
  DAT_1008d298 = DAT_10089ddc;
  iVar4 = DAT_1008723c + 0x1000;
  DAT_1008d294 = *(int *)(DAT_10087240 + DAT_1008d284 * 4);
  if (local_18 < 1) {
    if (DAT_1008d280 == iVar11 || DAT_1008d280 - iVar11 < 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    local_18 = -((int)*(short *)(param_3 + 0x1e) - (int)*(short *)(param_4 + 0x1e));
    if (local_18 == 0) {
      DAT_1008d298 = DAT_10089ddc;
      return;
    }
    iVar5 = iVar3 - iVar11;
    if (local_18 == 1) {
      DAT_1008d28c = iVar5 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1008d28c = iVar5 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      DAT_1008d28c = *(int *)(iVar4 + (iVar5 * 0x20 + local_18) * 4);
    }
    else if (iVar5 < 0) {
      DAT_1008d28c = (iVar5 * 0x10000) / local_18;
    }
    else {
      DAT_1008d28c = (iVar5 * 0x10000) / local_18;
    }
    iVar3 = iVar3 - DAT_1008d280;
    if (local_18 == 1) {
      DAT_1008d288 = iVar3 * 0x10000;
    }
    else if (local_18 == 2) {
      DAT_1008d288 = iVar3 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
      DAT_1008d288 = *(int *)(iVar4 + (iVar3 * 0x20 + local_18) * 4);
    }
    else if (iVar3 < 0) {
      DAT_1008d288 = (iVar3 * 0x10000) / local_18;
    }
    else {
      DAT_1008d288 = (iVar3 * 0x10000) / local_18;
    }
    DAT_1008d284 = DAT_1008d280 << 0x10;
    DAT_1008d280 = iVar11 << 0x10;
  }
  else {
    iVar5 = iVar11 - DAT_1008d280;
    if (local_18 == 1) {
      iVar5 = iVar5 * 0x10000;
    }
    else if (local_18 == 2) {
      iVar5 = iVar5 * 0x8000;
    }
    else if (((local_18 < 0x20) && (-0x20 < iVar5)) && (iVar5 < 0x20)) {
      iVar5 = *(int *)(iVar4 + (iVar5 * 0x20 + local_18) * 4);
    }
    else if (iVar5 < 0) {
      iVar5 = (iVar5 * 0x10000) / local_18;
    }
    else {
      iVar5 = (iVar5 * 0x10000) / local_18;
    }
    iVar9 = *(short *)(param_4 + 0x1e) - DAT_1008d284;
    DAT_1008d28c = iVar5;
    if (iVar9 < 1) {
      if (iVar3 == DAT_1008d280 || iVar3 - DAT_1008d280 < 0) {
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      iVar11 = iVar11 - iVar3;
      if (local_18 == 1) {
        DAT_1008d288 = iVar11 * 0x10000;
      }
      else if (local_18 == 2) {
        DAT_1008d288 = iVar11 * 0x8000;
      }
      else if (((local_18 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
        DAT_1008d288 = *(int *)(iVar4 + (iVar11 * 0x20 + local_18) * 4);
      }
      else if (iVar11 < 0) {
        DAT_1008d288 = (iVar11 * 0x10000) / local_18;
      }
      else {
        DAT_1008d288 = (iVar11 * 0x10000) / local_18;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = iVar3 << 0x10;
    }
    else {
      iVar6 = iVar3 - DAT_1008d280;
      if (iVar9 == 1) {
        iVar6 = iVar6 * 0x10000;
      }
      else if (iVar9 == 2) {
        iVar6 = iVar6 * 0x8000;
      }
      else if (((iVar9 < 0x20) && (-0x20 < iVar6)) && (iVar6 < 0x20)) {
        iVar6 = *(int *)(iVar4 + (iVar6 * 0x20 + iVar9) * 4);
      }
      else if (iVar6 < 0) {
        iVar6 = (iVar6 * 0x10000) / iVar9;
      }
      else {
        iVar6 = (iVar6 * 0x10000) / iVar9;
      }
      if (iVar6 == iVar5 || iVar6 - iVar5 < 0) {
        DAT_1008d288 = iVar6;
        DAT_1008d298 = DAT_10089ddc;
        return;
      }
      DAT_1008d280 = DAT_1008d280 << 0x10;
      DAT_1008d284 = DAT_1008d280;
      DAT_1008d288 = iVar6;
      if (local_18 < iVar9) {
        iVar9 = iVar9 - local_18;
        while (local_18 = local_18 + -1, -1 < local_18) {
          DAT_1008d280 = DAT_1008d280 + iVar5;
          DAT_1008d284 = DAT_1008d284 + iVar6;
          iVar12 = (DAT_1008d280 >> 0x10) - (DAT_1008d284 >> 0x10);
          if (iVar12 < 0) {
            puVar7 = (ushort *)((DAT_1008d284 >> 0x10) * 2 + DAT_1008d294 + iVar12 * 2);
            do {
              *puVar7 = uVar10;
              puVar7 = puVar7 + 1;
              iVar12 = iVar12 + 1;
            } while (iVar12 < 0);
          }
          DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
        }
        DAT_1008d280 = iVar11 << 0x10;
        iVar3 = iVar3 - iVar11;
        local_18 = iVar9;
        if (iVar9 == 1) {
          DAT_1008d28c = iVar3 * 0x10000;
        }
        else if (iVar9 == 2) {
          DAT_1008d28c = iVar3 * 0x8000;
        }
        else if (((iVar9 < 0x20) && (-0x20 < iVar3)) && (iVar3 < 0x20)) {
          DAT_1008d28c = *(int *)(iVar4 + (iVar3 * 0x20 + iVar9) * 4);
        }
        else if (iVar3 < 0) {
          DAT_1008d28c = (iVar3 * 0x10000) / iVar9;
        }
        else {
          DAT_1008d28c = (iVar3 * 0x10000) / iVar9;
        }
      }
      else {
        local_18 = local_18 - iVar9;
        DAT_1008d290 = iVar9;
        while (iVar9 = iVar9 + -1, -1 < iVar9) {
          DAT_1008d280 = DAT_1008d280 + iVar5;
          DAT_1008d284 = DAT_1008d284 + iVar6;
          iVar12 = (DAT_1008d280 >> 0x10) - (DAT_1008d284 >> 0x10);
          if (iVar12 < 0) {
            puVar7 = (ushort *)((DAT_1008d284 >> 0x10) * 2 + DAT_1008d294 + iVar12 * 2);
            do {
              *puVar7 = uVar10;
              puVar7 = puVar7 + 1;
              iVar12 = iVar12 + 1;
            } while (iVar12 < 0);
          }
          DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
        }
        if (local_18 == 0) {
          return;
        }
        DAT_1008d284 = iVar3 << 0x10;
        iVar11 = iVar11 - iVar3;
        if (local_18 == 1) {
          DAT_1008d288 = iVar11 * 0x10000;
        }
        else if (local_18 == 2) {
          DAT_1008d288 = iVar11 * 0x8000;
        }
        else if (((local_18 < 0x20) && (-0x20 < iVar11)) && (iVar11 < 0x20)) {
          DAT_1008d288 = *(int *)(iVar4 + (iVar11 * 0x20 + local_18) * 4);
        }
        else if (iVar11 < 0) {
          DAT_1008d288 = (iVar11 * 0x10000) / local_18;
        }
        else {
          DAT_1008d288 = (iVar11 * 0x10000) / local_18;
        }
      }
    }
  }
  iVar11 = DAT_1008d28c;
  iVar4 = DAT_1008d288;
  uVar2 = DAT_1008d2ac;
  DAT_1008d290 = local_18;
  while (local_18 = local_18 + -1, -1 < local_18) {
    DAT_1008d280 = DAT_1008d280 + iVar11;
    DAT_1008d284 = DAT_1008d284 + iVar4;
    iVar3 = (DAT_1008d280 >> 0x10) - (DAT_1008d284 >> 0x10);
    if (iVar3 < 0) {
      puVar8 = (undefined2 *)((DAT_1008d284 >> 0x10) * 2 + DAT_1008d294 + iVar3 * 2);
      do {
        *puVar8 = uVar2;
        puVar8 = puVar8 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0);
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
  }
  return;
}


