// 10009ee0 FUN_10009ee0 [Global]
// program: RWDL6D21.DLL

undefined4
FUN_10009ee0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  DAT_10079210 = 0;
  DAT_1007beb0 = 0;
  DAT_1007bda0 = 0;
  DAT_1007bb4c = param_4;
  param_1[8] = &LAB_1000a420;
  param_1[9] = FUN_1000a290;
  param_1[10] = FUN_1000a370;
  param_1[0xb] = &LAB_1000a1f0;
  param_1[0x93] = FUN_1000a4c0;
  param_1[0x94] = &LAB_1000a790;
  param_1[0x95] = &LAB_1000a830;
  param_1[0xd] = FUN_1000a840;
  param_1[0xe] = &LAB_1000a960;
  param_1[0x96] = &LAB_1000a970;
  param_1[0x97] = &LAB_1000ab50;
  param_1[0x98] = &LAB_1000b050;
  param_1[0xa3] = FUN_10009d40;
  param_1[0xa4] = &DAT_10009a20;
  param_1[0xa1] = &LAB_1000af70;
  param_1[0xa2] = &LAB_1000af90;
  param_1[2] = 0x20;
  param_1[0x92] = FUN_10009970;
  param_1[0xa0] = FUN_10069650;
  param_1[0x9b] = &LAB_1000afb0;
  param_1[0x9c] = &LAB_10006da0;
  *param_1 = param_4;
  param_1[0xa5] = FUN_1000b070;
  param_1[0xa6] = FUN_1000b280;
  param_1[0xa7] = &LAB_1000b310;
  iVar2 = (**(code **)(DAT_1007bda8 + 0x34c))(0x2080);
  DAT_10079214 = iVar2;
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
  param_1[0x10] = &DAT_1000b3d0;
  param_1[0x50] = &DAT_1000b3d0;
  param_1[0x11] = &DAT_1000b3d0;
  param_1[0x51] = &DAT_1000b3d0;
  param_1[0x14] = &DAT_1000b3d0;
  param_1[0x54] = &DAT_1000b3d0;
  param_1[0x15] = &DAT_1000b3d0;
  param_1[0x55] = &DAT_1000b3d0;
  param_1[0x18] = &DAT_1000b3d0;
  param_1[0x58] = &DAT_1000b3d0;
  param_1[0x19] = &DAT_1000b3d0;
  param_1[0x59] = &DAT_1000b3d0;
  param_1[0x1c] = &DAT_1000b3d0;
  param_1[0x5c] = &DAT_1000b3d0;
  param_1[0x1d] = &DAT_1000b3d0;
  param_1[0x5d] = &DAT_1000b3d0;
  param_1[0x1e] = &DAT_1000b3d0;
  param_1[0x5e] = &DAT_1000b3d0;
  param_1[0x1f] = &DAT_1000b3d0;
  param_1[0x5f] = &DAT_1000b3d0;
  param_1[0x24] = &DAT_1000b3d0;
  param_1[100] = &DAT_1000b3d0;
  param_1[0x25] = &DAT_1000b3d0;
  param_1[0x65] = &DAT_1000b3d0;
  param_1[0x26] = &DAT_1000b3d0;
  param_1[0x66] = &DAT_1000b3d0;
  param_1[0x27] = &DAT_1000b3d0;
  param_1[0x67] = &DAT_1000b3d0;
  DAT_10079220 = 0;
  switch(DAT_1007bb4c) {
  case 1:
  case 2:
    break;
  default:
    return 0;
  case 8:
    DAT_1007bb44 = (**(code **)(DAT_1007bda8 + 0x34c))(0x2100);
    if (DAT_1007bb44 == 0) {
      return 0;
    }
    DAT_10079220 = (DAT_1007bb44 & 0xffffff00) + 0x100;
    DAT_1007bb50 = DAT_10079220;
    DAT_1007bb40 = (**(code **)(DAT_1007bda8 + 0x34c))(0x1320);
    if (DAT_1007bb40 == 0) {
      return 0;
    }
    DAT_1007921c = (DAT_1007bb40 & 0xffffff00) + 0x100;
    DAT_1007bb48 = DAT_1007921c;
    break;
  case 0xf:
  case 0x10:
    DAT_1007bb44 = (**(code **)(DAT_1007bda8 + 0x34c))(0xd00);
    if (DAT_1007bb44 == 0) {
      return 0;
    }
    DAT_10079220 = (DAT_1007bb44 & 0xffffff00) + 0x100;
    DAT_1007bb50 = DAT_10079220;
  }
  return 1;
}


