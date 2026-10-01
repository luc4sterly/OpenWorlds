// 10008860 FUN_10008860 [Global]
// program: RWDL6D21.DLL

void FUN_10008860(int param_1,int param_2)

{
  if (DAT_10079210 != 0) {
    (**(code **)(DAT_1007bda8 + 0x358))(DAT_10079210);
  }
  DAT_10079210 = 0;
  DAT_1007beb0 = param_1 * 2;
  DAT_1007bda0 = param_2;
  DAT_10079210 = (**(code **)(DAT_1007bda8 + 0x34c))(DAT_1007beb0 * param_2);
  return;
}


