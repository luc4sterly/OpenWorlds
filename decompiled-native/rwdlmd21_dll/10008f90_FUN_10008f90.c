// 10008f90 FUN_10008f90 [Global]
// programa: rwdlmd21.dll

void FUN_10008f90(int param_1,int param_2)

{
  if (DAT_10087238 != 0) {
    (**(code **)(DAT_10089de0 + 0x358))(DAT_10087238);
  }
  DAT_10087238 = 0;
  DAT_10089ef4 = param_1 * 2;
  DAT_10089dd8 = param_2;
  DAT_10087238 = (**(code **)(DAT_10089de0 + 0x34c))(param_2 * DAT_10089ef4);
  return;
}


