// 100097e0 FUN_100097e0 [Global]
// programa: RWDLDD21.DLL

undefined4
FUN_100097e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (**(code **)(DAT_100394fc + 0x354))(DAT_10036064,(DAT_1003605c * 5 + 5) * 8);
  if (iVar2 == 0) {
    return 0;
  }
  DAT_10036064 = iVar2;
  *(undefined4 *)(iVar2 + DAT_1003605c * 0x28) = param_1;
  *(undefined4 *)(DAT_10036064 + 4 + DAT_1003605c * 0x28) = param_2;
  *(undefined4 *)(DAT_10036064 + 8 + DAT_1003605c * 0x28) = param_3;
  *(undefined4 *)(DAT_10036064 + 0xc + DAT_1003605c * 0x28) = 1;
  *(undefined4 *)(DAT_10036064 + 0x10 + DAT_1003605c * 0x28) = param_4;
  if (param_5 == (undefined4 *)0x0) {
    *(undefined4 *)(DAT_10036064 + 0x14 + DAT_1003605c * 0x28) = 0;
    iVar2 = DAT_10036064;
    iVar1 = DAT_1003605c;
    *(undefined4 *)(DAT_10036064 + 0x18 + DAT_1003605c * 0x28) = 0;
    iVar2 = iVar2 + iVar1 * 0x28;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined4 *)(iVar2 + 0x20) = 0;
    *(undefined4 *)(iVar2 + 0x24) = 0;
  }
  else {
    *(undefined4 *)(DAT_10036064 + 0x14 + DAT_1003605c * 0x28) = 1;
    iVar2 = DAT_10036064;
    iVar1 = DAT_1003605c;
    *(undefined4 *)(DAT_10036064 + 0x18 + DAT_1003605c * 0x28) = *param_5;
    iVar2 = iVar2 + iVar1 * 0x28;
    *(undefined4 *)(iVar2 + 0x1c) = param_5[1];
    *(undefined4 *)(iVar2 + 0x20) = param_5[2];
    *(undefined4 *)(iVar2 + 0x24) = param_5[3];
  }
  DAT_1003605c = DAT_1003605c + 1;
  return 1;
}


