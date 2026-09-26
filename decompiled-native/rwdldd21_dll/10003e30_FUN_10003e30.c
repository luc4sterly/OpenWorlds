// 10003e30 FUN_10003e30 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_10003e30(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined **)(param_1 + 0x2c) = &DAT_10004000;
  }
  else {
    *(code **)(param_1 + 0x2c) = FUN_10003da0;
  }
  if (DAT_100360a8 != 1) {
    if (DAT_100360a8 != 0x10) {
      return 0;
    }
    if (param_2 == 0) {
      *(code **)(param_1 + 0x140) = FUN_1000a000;
      *(code **)(param_1 + 0x144) = FUN_1000ba10;
      *(code **)(param_1 + 0x150) = FUN_1000d580;
      *(code **)(param_1 + 0x154) = FUN_1000f6e0;
      *(code **)(param_1 + 0x160) = FUN_10011c60;
      *(code **)(param_1 + 0x164) = FUN_10013dd0;
      *(code **)(param_1 + 0x170) = FUN_10016310;
      *(code **)(param_1 + 0x174) = FUN_10019600;
      *(code **)(param_1 + 0x178) = FUN_100170a0;
      *(code **)(param_1 + 0x17c) = FUN_1001a410;
      *(code **)(param_1 + 400) = FUN_1001c370;
      *(code **)(param_1 + 0x194) = FUN_100200f0;
      *(code **)(param_1 + 0x198) = FUN_1001d670;
      *(code **)(param_1 + 0x19c) = FUN_10021400;
    }
    else {
      *(code **)(param_1 + 0x140) = FUN_1000acf0;
      *(code **)(param_1 + 0x144) = FUN_1000c7b0;
      *(code **)(param_1 + 0x150) = FUN_1000e610;
      *(code **)(param_1 + 0x154) = FUN_10010980;
      *(code **)(param_1 + 0x160) = FUN_10012d00;
      *(undefined1 **)(param_1 + 0x164) = &LAB_10015050;
      *(code **)(param_1 + 0x170) = FUN_100169c0;
      *(code **)(param_1 + 0x174) = FUN_10019cf0;
      *(code **)(param_1 + 0x178) = FUN_100180a0;
      *(code **)(param_1 + 0x17c) = FUN_1001b3d0;
      *(code **)(param_1 + 400) = FUN_1001cce0;
      *(undefined1 **)(param_1 + 0x194) = &LAB_10020a60;
      *(code **)(param_1 + 0x198) = FUN_1001e7a0;
      *(code **)(param_1 + 0x19c) = FUN_10022560;
    }
    *(code **)(param_1 + 0x40) = FUN_1000a000;
    *(code **)(param_1 + 0x44) = FUN_1000ba10;
    *(code **)(param_1 + 0x50) = FUN_1000d580;
    *(code **)(param_1 + 0x54) = FUN_1000f6e0;
    *(code **)(param_1 + 0x60) = FUN_10011c60;
    *(code **)(param_1 + 100) = FUN_10013dd0;
    *(code **)(param_1 + 0x70) = FUN_10016310;
    *(code **)(param_1 + 0x74) = FUN_10019600;
    *(code **)(param_1 + 0x78) = FUN_100170a0;
    *(code **)(param_1 + 0x7c) = FUN_1001a410;
    *(code **)(param_1 + 0x90) = FUN_1001c370;
    *(code **)(param_1 + 0x94) = FUN_100200f0;
    *(code **)(param_1 + 0x98) = FUN_1001d670;
    *(code **)(param_1 + 0x9c) = FUN_10021400;
  }
  return 1;
}


