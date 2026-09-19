// 1000cb60 FUN_1000cb60 [Global]
// programa: RWL21.DLL

int FUN_1000cb60(int param_1)

{
  if (DAT_1005a0a4 == 0) {
    DAT_1005dfc0 = param_1;
    if (0x62 < param_1) {
      param_1 = 0x62;
    }
    DAT_1005a0a4 = param_1;
    return param_1;
  }
  if (0x62 < param_1) {
    param_1 = 0x62;
  }
  return param_1;
}


