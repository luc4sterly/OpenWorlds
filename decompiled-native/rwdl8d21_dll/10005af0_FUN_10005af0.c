// 10005af0 FUN_10005af0 [Global]
// program: RWDL8D21.DLL

undefined4
FUN_10005af0(byte *param_1,int param_2,undefined4 param_3,undefined4 *param_4,uint param_5)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  byte bVar7;
  byte *pbVar8;
  int iVar9;
  bool bVar10;
  
  iVar9 = param_4[0xd];
  if (param_4[9] == 0) {
    if ((param_5 & 1) == 0) {
      switch(param_3) {
      case 1:
      case 4:
      case 8:
        param_4[9] = 8;
        break;
      default:
        param_4[9] = 0x18;
      }
    }
    else {
      param_4[9] = 0x18;
    }
    if (param_4[9] == 0x18) {
      param_4[1] = 0x18;
      param_4[2] = 0xff0000;
      param_4[3] = 0xff00;
      param_4[4] = 0xff;
      param_4[5] = 0;
      *param_4 = 2;
    }
    else {
      *param_4 = 1;
      param_4[2] = 0;
      param_4[3] = 0;
      param_4[4] = 0;
      param_4[5] = 0;
      param_4[1] = 8;
    }
  }
  if (param_4[9] != 0x18) {
    switch(param_3) {
    case 1:
      uVar5 = param_2 + 7U & 0xfffffff8;
      pbVar8 = param_1 + (uVar5 - 1);
      pbVar6 = param_1 + ((int)(uVar5 + ((int)(param_2 + 7U) >> 0x1f & 7U)) >> 3) + -1;
      break;
    default:
      return 1;
    case 4:
      uVar5 = param_2 + 3U & 0xfffffffc;
      pbVar8 = param_1 + ((int)(uVar5 - ((int)(param_2 + 3U) >> 0x1f)) >> 1) + -1;
      for (pbVar6 = param_1 + (uVar5 - 1); param_1 < pbVar6; pbVar6 = pbVar6 + -2) {
        bVar7 = *pbVar8;
        pbVar8 = pbVar8 + -1;
        *pbVar6 = bVar7 & 0xf;
        pbVar6[-1] = bVar7 >> 4;
      }
      return 1;
    case 0x18:
    case 0x20:
      return 0;
    }
    while (param_1 < pbVar8) {
      bVar7 = *pbVar6;
      pbVar6 = pbVar6 + -1;
      iVar9 = 7;
      pbVar4 = pbVar8;
      do {
        pbVar8 = pbVar4 + -1;
        *pbVar4 = bVar7 & 1;
        bVar10 = iVar9 != 0;
        iVar9 = iVar9 + -1;
        pbVar4 = pbVar8;
        bVar7 = bVar7 >> 1;
      } while (bVar10);
    }
    return 1;
  }
  switch(param_3) {
  case 1:
    uVar5 = param_2 + 7U & 0xfffffff8;
    pbVar8 = param_1 + uVar5 * 3 + -1;
    pbVar6 = param_1 + ((int)(uVar5 + ((int)(param_2 + 7U) >> 0x1f & 7U)) >> 3) + -1;
    while (param_1 < pbVar8) {
      pbVar2 = pbVar6 + -1;
      bVar7 = *pbVar6;
      iVar3 = 7;
      pbVar4 = pbVar8;
      do {
        uVar5 = (uint)bVar7;
        bVar7 = bVar7 >> 1;
        pbVar8 = pbVar4 + -3;
        iVar1 = (uVar5 & 1) * 3;
        pbVar6 = (byte *)(iVar1 + iVar9);
        *pbVar4 = *(byte *)(iVar1 + 2 + iVar9);
        pbVar4[-1] = pbVar6[1];
        pbVar4[-2] = *pbVar6;
        bVar10 = iVar3 != 0;
        iVar3 = iVar3 + -1;
        pbVar4 = pbVar8;
        pbVar6 = pbVar2;
      } while (bVar10);
    }
    break;
  case 4:
    uVar5 = param_2 + 3U & 0xfffffffc;
    pbVar8 = param_1 + ((int)(uVar5 - ((int)(param_2 + 3U) >> 0x1f)) >> 1) + -1;
    for (pbVar6 = param_1 + uVar5 * 3 + -1; param_1 < pbVar6; pbVar6 = pbVar6 + -6) {
      bVar7 = *pbVar8;
      pbVar8 = pbVar8 + -1;
      pbVar4 = (byte *)((bVar7 & 0xf) * 3 + iVar9);
      *pbVar6 = pbVar4[2];
      pbVar6[-1] = pbVar4[1];
      iVar3 = (uint)(bVar7 >> 4) * 3;
      pbVar6[-2] = *pbVar4;
      pbVar4 = (byte *)(iVar3 + iVar9);
      pbVar6[-3] = *(byte *)(iVar3 + 2 + iVar9);
      pbVar6[-4] = pbVar4[1];
      pbVar6[-5] = *pbVar4;
    }
    break;
  case 8:
    pbVar8 = param_1 + param_2 + -1;
    for (pbVar6 = param_1 + param_2 * 3 + -1; param_1 < pbVar6; pbVar6 = pbVar6 + -3) {
      bVar7 = *pbVar8;
      pbVar8 = pbVar8 + -1;
      pbVar4 = (byte *)((uint)bVar7 * 3 + iVar9);
      *pbVar6 = *(byte *)((uint)bVar7 * 3 + 2 + iVar9);
      pbVar6[-1] = pbVar4[1];
      pbVar6[-2] = *pbVar4;
    }
    break;
  case 0x18:
    goto LAB_10005d1b;
  case 0x20:
    pbVar8 = param_1;
    pbVar6 = param_1;
    iVar9 = param_2;
    if (0 < param_2) {
      do {
        *pbVar6 = pbVar8[1];
        iVar9 = iVar9 + -1;
        pbVar6[1] = pbVar8[2];
        pbVar6[2] = pbVar8[3];
        pbVar8 = pbVar8 + 4;
        pbVar6 = pbVar6 + 3;
      } while (iVar9 != 0);
    }
LAB_10005d1b:
    if (((param_5 & 4) != 0) && (pbVar8 = param_1, 0 < param_2)) {
      do {
        bVar7 = *pbVar8;
        *pbVar8 = param_1[2];
        pbVar8[1] = param_1[1];
        pbVar8[2] = bVar7;
        pbVar8 = pbVar8 + 3;
        param_1 = param_1 + 3;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  return 1;
}


