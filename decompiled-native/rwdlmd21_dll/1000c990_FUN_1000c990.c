// 1000c990 FUN_1000c990 [Global]
// program: rwdlmd21.dll

undefined4 FUN_1000c990(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar2 = DAT_10089b8c;
  if (DAT_10089b94 != 0) {
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      uVar3 = uVar3 + 1;
      (**(code **)(iVar1 + DAT_10089b88))((undefined4 *)(iVar1 + DAT_10089b88) + 1);
    } while (uVar3 < DAT_10089b94);
  }
  if (DAT_10087370 < DAT_10089b84) {
    DAT_10087370 = DAT_10089b84;
  }
  DAT_1008736c = DAT_1008736c + 1 & 0x3f;
  if (DAT_1008736c == 0) {
    if ((DAT_10087370 >> 1) + DAT_10087370 < DAT_10089b90) {
      iVar1 = (**(code **)(DAT_10089de0 + 0x354))(DAT_10089b88,DAT_10087370);
      if (iVar1 != 0) {
        DAT_10089b90 = DAT_10087370;
        DAT_10089b88 = iVar1;
      }
    }
    DAT_10087370 = 0;
  }
  DAT_10089b84 = 0;
  DAT_10089b94 = 0;
  return 1;
}


