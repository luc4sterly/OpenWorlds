// 10024c20 FUN_10024c20 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_10024c20(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  DAT_100362c0 = 0;
  DAT_10039600 = 0;
  _DAT_100394f4 = 0;
  DAT_10039088 = param_4;
  param_1[8] = &LAB_10025160;
  param_1[9] = FUN_10024fd0;
  param_1[10] = FUN_100250b0;
  param_1[0xb] = &LAB_10024f30;
  param_1[0x93] = FUN_10025200;
  param_1[0x94] = &LAB_100254d0;
  param_1[0x95] = &LAB_10025570;
  param_1[0xd] = FUN_10025580;
  param_1[0xe] = &LAB_100256a0;
  param_1[0x96] = &LAB_100256b0;
  param_1[0x97] = &LAB_10025890;
  param_1[0x98] = &LAB_10025d90;
  param_1[0xa3] = FUN_10024a80;
  param_1[0xa4] = &DAT_10024760;
  param_1[0xa1] = &LAB_10025cb0;
  param_1[0xa2] = &LAB_10025cd0;
  param_1[2] = 0x20;
  param_1[0x92] = FUN_100246b0;
  param_1[0xa0] = FUN_10033360;
  param_1[0x9b] = &LAB_10025cf0;
  param_1[0x9c] = &LAB_10026350;
  *param_1 = param_4;
  param_1[0xa5] = FUN_10025db0;
  param_1[0xa6] = FUN_10025fc0;
  param_1[0xa7] = &LAB_10026050;
  iVar2 = (**(code **)(DAT_100394fc + 0x34c))(0x2080);
  DAT_100362c4 = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  iVar5 = 0;
  iVar4 = -0x200000;
  do {
    iVar6 = 1;
    do {
      iVar3 = iVar4 / iVar6;
      iVar1 = iVar5 + iVar6;
      iVar6 = iVar6 + 1;
      *(int *)(iVar2 + iVar1 * 4) = iVar3;
    } while (iVar6 < 0x20);
    iVar5 = iVar5 + 0x20;
    iVar4 = iVar4 + 0x10000;
  } while (iVar4 < 0x200001);
  param_1[0x10] = &DAT_10026110;
  param_1[0x50] = &DAT_10026110;
  param_1[0x11] = &DAT_10026110;
  param_1[0x51] = &DAT_10026110;
  param_1[0x14] = &DAT_10026110;
  param_1[0x54] = &DAT_10026110;
  param_1[0x15] = &DAT_10026110;
  param_1[0x55] = &DAT_10026110;
  param_1[0x18] = &DAT_10026110;
  param_1[0x58] = &DAT_10026110;
  param_1[0x19] = &DAT_10026110;
  param_1[0x59] = &DAT_10026110;
  param_1[0x1c] = &DAT_10026110;
  param_1[0x5c] = &DAT_10026110;
  param_1[0x1d] = &DAT_10026110;
  param_1[0x5d] = &DAT_10026110;
  param_1[0x1e] = &DAT_10026110;
  param_1[0x5e] = &DAT_10026110;
  param_1[0x1f] = &DAT_10026110;
  param_1[0x5f] = &DAT_10026110;
  param_1[0x24] = &DAT_10026110;
  param_1[100] = &DAT_10026110;
  param_1[0x25] = &DAT_10026110;
  param_1[0x65] = &DAT_10026110;
  param_1[0x26] = &DAT_10026110;
  param_1[0x66] = &DAT_10026110;
  param_1[0x27] = &DAT_10026110;
  param_1[0x67] = &DAT_10026110;
  DAT_100362d0 = 0;
  switch(DAT_10039088) {
  case 1:
  case 2:
    break;
  default:
    return 0;
  case 8:
    DAT_10039080 = (**(code **)(DAT_100394fc + 0x34c))(0x2100);
    if (DAT_10039080 == 0) {
      return 0;
    }
    DAT_100362d0 = (DAT_10039080 & 0xffffff00) + 0x100;
    DAT_1003908c = DAT_100362d0;
    DAT_1003907c = (**(code **)(DAT_100394fc + 0x34c))(0x1320);
    if (DAT_1003907c == 0) {
      return 0;
    }
    DAT_100362cc = (DAT_1003907c & 0xffffff00) + 0x100;
    DAT_10039084 = DAT_100362cc;
    break;
  case 0xf:
  case 0x10:
    DAT_10039080 = (**(code **)(DAT_100394fc + 0x34c))(0xd00);
    if (DAT_10039080 == 0) {
      return 0;
    }
    DAT_100362d0 = (DAT_10039080 & 0xffffff00) + 0x100;
    DAT_1003908c = DAT_100362d0;
  }
  return 1;
}


