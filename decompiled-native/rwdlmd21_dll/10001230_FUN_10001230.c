// 10001230 FUN_10001230 [Global]
// program: rwdlmd21.dll

undefined4 FUN_10001230(int param_1)

{
  if (DAT_10087088 == 0) {
    *(undefined **)(param_1 + 0x2c) = &DAT_10001410;
  }
  else {
    *(undefined4 *)(param_1 + 0x2c) = DAT_1008a334;
  }
  if (DAT_10087064 != 1) {
    if ((DAT_10087064 < 0xf) || (0x10 < DAT_10087064)) {
      return 0;
    }
    if (DAT_10087088 == 0) {
      *(code **)(param_1 + 0x140) = FUN_1000ca50;
      *(code **)(param_1 + 0x144) = FUN_1000cc40;
      *(code **)(param_1 + 0x150) = FUN_1001a8b0;
      *(code **)(param_1 + 0x154) = FUN_1001ae10;
      *(code **)(param_1 + 0x160) = FUN_1001af40;
      *(code **)(param_1 + 0x164) = FUN_1001b0a0;
      *(code **)(param_1 + 0x170) = FUN_1001b100;
      *(code **)(param_1 + 0x174) = FUN_100290b0;
      *(code **)(param_1 + 0x178) = FUN_1001c2a0;
      *(code **)(param_1 + 0x17c) = FUN_1002b4c0;
      *(code **)(param_1 + 400) = FUN_10010290;
      *(code **)(param_1 + 0x194) = FUN_1001a6d0;
      *(code **)(param_1 + 0x198) = FUN_10013570;
      *(code **)(param_1 + 0x19c) = FUN_1001a770;
    }
    else {
      *(undefined1 **)(param_1 + 0x140) = &LAB_1000cb20;
      *(code **)(param_1 + 0x144) = FUN_1000cd30;
      *(code **)(param_1 + 0x150) = FUN_1001ab00;
      *(code **)(param_1 + 0x154) = FUN_1001aeb0;
      *(code **)(param_1 + 0x160) = FUN_1001aff0;
      *(undefined1 **)(param_1 + 0x164) = &LAB_1001b0d0;
      *(code **)(param_1 + 0x170) = FUN_1001b8f0;
      *(code **)(param_1 + 0x174) = FUN_1002a170;
      *(code **)(param_1 + 0x178) = FUN_10001420;
      *(code **)(param_1 + 0x17c) = FUN_10001530;
      *(code **)(param_1 + 400) = FUN_100101f0;
      *(code **)(param_1 + 0x194) = FUN_1001a810;
      *(code **)(param_1 + 0x198) = FUN_100015e0;
      *(code **)(param_1 + 0x19c) = FUN_10001690;
    }
    *(undefined1 **)(param_1 + 0x40) = &LAB_10001740;
    *(undefined1 **)(param_1 + 0x44) = &LAB_10001770;
    *(undefined1 **)(param_1 + 0x50) = &LAB_100017a0;
    *(undefined1 **)(param_1 + 0x54) = &LAB_100017d0;
    *(undefined1 **)(param_1 + 0x60) = &LAB_10001800;
    *(undefined1 **)(param_1 + 100) = &LAB_10001830;
    *(undefined1 **)(param_1 + 0x70) = &LAB_10001860;
    *(undefined1 **)(param_1 + 0x74) = &LAB_10001890;
    *(undefined1 **)(param_1 + 0x78) = &LAB_100018c0;
    *(undefined1 **)(param_1 + 0x7c) = &LAB_100018f0;
    *(undefined1 **)(param_1 + 0x90) = &LAB_10001920;
    *(undefined1 **)(param_1 + 0x94) = &LAB_10001950;
    *(undefined1 **)(param_1 + 0x98) = &LAB_10001980;
    *(undefined1 **)(param_1 + 0x9c) = &LAB_100019b0;
  }
  return 1;
}


