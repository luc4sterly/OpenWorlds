// 10001230 FUN_10001230 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_10001230(int param_1)

{
  if (DAT_10079084 == 0) {
    *(undefined **)(param_1 + 0x2c) = &DAT_10001410;
  }
  else {
    *(undefined4 *)(param_1 + 0x2c) = DAT_1007c2f0;
  }
  if (DAT_10079064 != 1) {
    if ((DAT_10079064 < 0xf) || (0x10 < DAT_10079064)) {
      return 0;
    }
    if (DAT_10079084 == 0) {
      *(undefined1 **)(param_1 + 0x140) = &LAB_1000bf80;
      *(undefined1 **)(param_1 + 0x144) = &LAB_1000c170;
      *(code **)(param_1 + 0x150) = FUN_10019090;
      *(code **)(param_1 + 0x154) = FUN_100195e0;
      *(code **)(param_1 + 0x160) = FUN_10019700;
      *(undefined1 **)(param_1 + 0x164) = &LAB_10019850;
      *(code **)(param_1 + 0x170) = FUN_100198b0;
      *(code **)(param_1 + 0x174) = FUN_10025970;
      *(undefined1 **)(param_1 + 0x178) = &LAB_1001a7f0;
      *(code **)(param_1 + 0x17c) = FUN_10027d70;
      *(code **)(param_1 + 400) = FUN_1000f610;
      *(code **)(param_1 + 0x194) = FUN_10018eb0;
      *(code **)(param_1 + 0x198) = FUN_10012cd0;
      *(code **)(param_1 + 0x19c) = FUN_10018f50;
    }
    else {
      *(undefined1 **)(param_1 + 0x140) = &LAB_1000c050;
      *(code **)(param_1 + 0x144) = FUN_1000c260;
      *(code **)(param_1 + 0x150) = FUN_100192e0;
      *(undefined1 **)(param_1 + 0x154) = &LAB_10019670;
      *(code **)(param_1 + 0x160) = FUN_100197b0;
      *(undefined1 **)(param_1 + 0x164) = &LAB_10019880;
      *(undefined1 **)(param_1 + 0x170) = &LAB_10019f30;
      *(code **)(param_1 + 0x174) = FUN_10026a20;
      *(code **)(param_1 + 0x178) = FUN_1001af40;
      *(code **)(param_1 + 0x17c) = FUN_10029090;
      *(code **)(param_1 + 400) = FUN_1000f570;
      *(code **)(param_1 + 0x194) = FUN_10018ff0;
      *(code **)(param_1 + 0x198) = FUN_10012c30;
      *(code **)(param_1 + 0x19c) = FUN_10018e10;
    }
    *(undefined1 **)(param_1 + 0x40) = &LAB_1000bf80;
    *(undefined1 **)(param_1 + 0x44) = &LAB_1000c170;
    *(code **)(param_1 + 0x50) = FUN_10019090;
    *(code **)(param_1 + 0x54) = FUN_100195e0;
    *(code **)(param_1 + 0x60) = FUN_10019700;
    *(undefined1 **)(param_1 + 100) = &LAB_10019850;
    *(code **)(param_1 + 0x70) = FUN_100198b0;
    *(code **)(param_1 + 0x74) = FUN_10025970;
    *(undefined1 **)(param_1 + 0x78) = &LAB_1001a7f0;
    *(code **)(param_1 + 0x7c) = FUN_10027d70;
    *(code **)(param_1 + 0x90) = FUN_1000f610;
    *(code **)(param_1 + 0x94) = FUN_10018eb0;
    *(code **)(param_1 + 0x98) = FUN_10012cd0;
    *(code **)(param_1 + 0x9c) = FUN_10018f50;
  }
  return 1;
}


