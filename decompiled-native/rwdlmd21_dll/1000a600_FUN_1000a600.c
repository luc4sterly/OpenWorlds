// 1000a600 FUN_1000a600 [Global]
// program: rwdlmd21.dll

undefined4
FUN_1000a600(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  DAT_10087238 = 0;
  DAT_10089ef4 = 0;
  DAT_10089dd8 = 0;
  DAT_10089b7c = param_4;
  param_1[8] = &LAB_1000ab40;
  param_1[9] = FUN_1000a9b0;
  param_1[10] = FUN_1000aa90;
  param_1[0xb] = &LAB_1000a910;
  param_1[0x93] = FUN_1000ac00;
  param_1[0x94] = &LAB_1000aed0;
  param_1[0x95] = &LAB_1000af70;
  param_1[0xd] = FUN_1000af80;
  param_1[0xe] = &LAB_1000b0a0;
  param_1[0x96] = &LAB_1000b0b0;
  param_1[0x97] = &LAB_1000b290;
  param_1[0x98] = &LAB_1000b790;
  param_1[0xa3] = FUN_1000a460;
  param_1[0xa4] = &DAT_1000a130;
  param_1[0xa1] = &LAB_1000b6b0;
  param_1[0xa2] = &LAB_1000b6d0;
  param_1[2] = 0x20;
  param_1[0x92] = FUN_1000a080;
  param_1[0xa0] = FUN_1006a650;
  param_1[0x9b] = &LAB_1000b6f0;
  param_1[0x9c] = &LAB_10007560;
  param_1[0xa5] = FUN_1000b7b0;
  *param_1 = param_4;
  param_1[0xa6] = FUN_1000b9c0;
  param_1[0xa7] = &LAB_1000ba50;
  param_1[0xa9] = &LAB_1000be00;
  iVar2 = (**(code **)(DAT_10089de0 + 0x34c))(0x2080);
  DAT_1008723c = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  iVar6 = 0;
  iVar4 = -0x200000;
  do {
    iVar5 = 1;
    do {
      iVar3 = iVar4 / iVar5;
      iVar1 = iVar6 + iVar5;
      iVar5 = iVar5 + 1;
      *(int *)(iVar2 + iVar1 * 4) = iVar3;
    } while (iVar5 < 0x20);
    iVar6 = iVar6 + 0x20;
    iVar4 = iVar4 + 0x10000;
  } while (iVar4 < 0x200001);
  param_1[0x10] = &DAT_1000bc00;
  param_1[0x50] = &DAT_1000bc00;
  param_1[0x11] = &DAT_1000bc00;
  param_1[0x51] = &DAT_1000bc00;
  param_1[0x14] = &DAT_1000bc00;
  param_1[0x54] = &DAT_1000bc00;
  param_1[0x15] = &DAT_1000bc00;
  param_1[0x55] = &DAT_1000bc00;
  param_1[0x18] = &DAT_1000bc00;
  param_1[0x58] = &DAT_1000bc00;
  param_1[0x19] = &DAT_1000bc00;
  param_1[0x59] = &DAT_1000bc00;
  param_1[0x1c] = &DAT_1000bc00;
  param_1[0x5c] = &DAT_1000bc00;
  param_1[0x1d] = &DAT_1000bc00;
  param_1[0x5d] = &DAT_1000bc00;
  param_1[0x1e] = &DAT_1000bc00;
  param_1[0x5e] = &DAT_1000bc00;
  param_1[0x1f] = &DAT_1000bc00;
  param_1[0x5f] = &DAT_1000bc00;
  param_1[0x24] = &DAT_1000bc00;
  param_1[100] = &DAT_1000bc00;
  param_1[0x25] = &DAT_1000bc00;
  param_1[0x65] = &DAT_1000bc00;
  param_1[0x26] = &DAT_1000bc00;
  param_1[0x66] = &DAT_1000bc00;
  param_1[0x27] = &DAT_1000bc00;
  param_1[0x67] = &DAT_1000bc00;
  DAT_10087248 = 0;
  switch(DAT_10089b7c) {
  case 1:
  case 2:
    break;
  default:
    return 0;
  case 8:
    DAT_10089b74 = (**(code **)(DAT_10089de0 + 0x34c))(0x2100);
    if (DAT_10089b74 == 0) {
      return 0;
    }
    DAT_10087248 = (DAT_10089b74 & 0xffffff00) + 0x100;
    DAT_10089b80 = DAT_10087248;
    DAT_10089b70 = (**(code **)(DAT_10089de0 + 0x34c))(0x1320);
    if (DAT_10089b70 == 0) {
      return 0;
    }
    DAT_10087244 = (DAT_10089b70 & 0xffffff00) + 0x100;
    DAT_10089b78 = DAT_10087244;
    break;
  case 0xf:
  case 0x10:
    DAT_10089b74 = (**(code **)(DAT_10089de0 + 0x34c))(0xd00);
    if (DAT_10089b74 == 0) {
      return 0;
    }
    DAT_10087248 = (DAT_10089b74 & 0xffffff00) + 0x100;
    DAT_10089b80 = DAT_10087248;
  }
  return 1;
}


