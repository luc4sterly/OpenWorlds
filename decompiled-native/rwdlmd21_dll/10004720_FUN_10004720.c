// 10004720 FUN_10004720 [Global]
// program: rwdlmd21.dll

undefined4 FUN_10004720(void)

{
  undefined4 local_14 [4];
  uint local_4;
  
  DAT_10087038 = 0;
  if (DAT_10087048 != 0) {
    if (DAT_10087044 == 0) {
      DAT_10087048 = 0;
    }
    else {
      FUN_100051c0(0,local_14);
      if ((DAT_10087050 != 0) || ((local_4 & 2) != 0)) {
        DAT_10087038 = 3;
        if (DAT_10087060 < 0x10) {
          DAT_10087064 = 8;
          return 3;
        }
        DAT_10087064 = 0x10;
        return 3;
      }
      DAT_10087048 = 0;
    }
  }
  if (DAT_10087040 != 0) {
    DAT_10087038 = 2;
    if (DAT_10087060 < 0x10) {
      DAT_10087064 = 8;
      return 2;
    }
    DAT_10087064 = 0x10;
    return 2;
  }
  if (DAT_1008703c != 0) {
    DAT_10087038 = 1;
    DAT_10087064 = 8;
    return 1;
  }
  if (DAT_10087034 == 3) {
    DAT_10087064 = 8;
    DAT_10087038 = 1;
    return 1;
  }
  if (DAT_10087044 == 0) {
    if (DAT_10087060 < 0x10) {
      DAT_10087038 = 2;
      DAT_10087064 = 8;
      return 2;
    }
    DAT_10087038 = 2;
    DAT_10087064 = 0x10;
    return 2;
  }
  FUN_100051c0(0,local_14);
  if ((DAT_10087050 == 0) && ((local_4 & 2) == 0)) {
    if (DAT_10087060 < 0x10) {
      DAT_10087038 = 2;
      DAT_10087064 = 8;
      return 2;
    }
    DAT_10087038 = 2;
    DAT_10087064 = 0x10;
    return 2;
  }
  if (DAT_10087060 < 0x10) {
    DAT_10087038 = 3;
    DAT_10087064 = 8;
    return 3;
  }
  DAT_10087038 = 3;
  DAT_10087064 = 0x10;
  return 3;
}


