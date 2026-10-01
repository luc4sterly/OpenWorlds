// 100040a0 FUN_100040a0 [Global]
// program: RWDL8D21.DLL

undefined4 FUN_100040a0(void)

{
  undefined4 local_14 [4];
  uint local_4;
  
  DAT_10075038 = 0;
  if (DAT_10075048 != 0) {
    if (DAT_10075044 == 0) {
      DAT_10075048 = 0;
    }
    else {
      FUN_10004b10(0,local_14);
      if ((DAT_10075050 != 0) || ((local_4 & 2) != 0)) {
        DAT_10075038 = 3;
        if (DAT_10075060 < 0x10) {
          DAT_10075064 = 8;
          return 3;
        }
        DAT_10075064 = 0x10;
        return 3;
      }
      DAT_10075048 = 0;
    }
  }
  if (DAT_10075040 != 0) {
    DAT_10075038 = 2;
    if (DAT_10075060 < 0x10) {
      DAT_10075064 = 8;
      return 2;
    }
    DAT_10075064 = 0x10;
    return 2;
  }
  if (DAT_1007503c != 0) {
    DAT_10075038 = 1;
    DAT_10075064 = 8;
    return 1;
  }
  if (DAT_10075034 == 3) {
    DAT_10075064 = 8;
    DAT_10075038 = 1;
    return 1;
  }
  if (DAT_10075044 == 0) {
    if (DAT_10075060 < 0x10) {
      DAT_10075038 = 2;
      DAT_10075064 = 8;
      return 2;
    }
    DAT_10075038 = 2;
    DAT_10075064 = 0x10;
    return 2;
  }
  FUN_10004b10(0,local_14);
  if ((DAT_10075050 == 0) && ((local_4 & 2) == 0)) {
    if (DAT_10075060 < 0x10) {
      DAT_10075038 = 2;
      DAT_10075064 = 8;
      return 2;
    }
    DAT_10075038 = 2;
    DAT_10075064 = 0x10;
    return 2;
  }
  if (DAT_10075060 < 0x10) {
    DAT_10075038 = 3;
    DAT_10075064 = 8;
    return 3;
  }
  DAT_10075038 = 3;
  DAT_10075064 = 0x10;
  return 3;
}


