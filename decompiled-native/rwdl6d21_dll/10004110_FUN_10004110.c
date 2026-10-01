// 10004110 FUN_10004110 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_10004110(void)

{
  undefined4 local_14 [4];
  uint local_4;
  
  DAT_10079038 = 0;
  if (DAT_10079048 != 0) {
    if (DAT_10079044 == 0) {
      DAT_10079048 = 0;
    }
    else {
      FUN_10004b80(0,local_14);
      if ((DAT_10079050 != 0) || ((local_4 & 2) != 0)) {
        DAT_10079038 = 3;
        if (DAT_10079060 < 0x10) {
          DAT_10079064 = 8;
          return 3;
        }
        DAT_10079064 = 0x10;
        return 3;
      }
      DAT_10079048 = 0;
    }
  }
  if (DAT_10079040 != 0) {
    DAT_10079038 = 2;
    if (DAT_10079060 < 0x10) {
      DAT_10079064 = 8;
      return 2;
    }
    DAT_10079064 = 0x10;
    return 2;
  }
  if (DAT_1007903c != 0) {
    DAT_10079038 = 1;
    DAT_10079064 = 8;
    return 1;
  }
  if (DAT_10079034 == 3) {
    DAT_10079064 = 8;
    DAT_10079038 = 1;
    return 1;
  }
  if (DAT_10079044 == 0) {
    if (DAT_10079060 < 0x10) {
      DAT_10079038 = 2;
      DAT_10079064 = 8;
      return 2;
    }
    DAT_10079038 = 2;
    DAT_10079064 = 0x10;
    return 2;
  }
  FUN_10004b80(0,local_14);
  if ((DAT_10079050 == 0) && ((local_4 & 2) == 0)) {
    if (DAT_10079060 < 0x10) {
      DAT_10079038 = 2;
      DAT_10079064 = 8;
      return 2;
    }
    DAT_10079038 = 2;
    DAT_10079064 = 0x10;
    return 2;
  }
  if (DAT_10079060 < 0x10) {
    DAT_10079038 = 3;
    DAT_10079064 = 8;
    return 3;
  }
  DAT_10079038 = 3;
  DAT_10079064 = 0x10;
  return 3;
}


