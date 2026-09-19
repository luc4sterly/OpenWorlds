// 1000bef0 FUN_1000bef0 [Global]
// programa: RWDL6D21.DLL

void FUN_1000bef0(uint *param_1,uint param_2,byte *param_3,uint *param_4)

{
  if ((param_2 & 1) == 0) {
    *param_1 = *param_4;
    param_1[1] = (uint)*param_3;
  }
  else {
    *param_1 = (uint)*param_3;
    param_1[1] = param_4[1];
  }
  if ((param_2 & 2) == 0) {
    param_1[2] = param_4[2];
    param_1[3] = (uint)param_3[1];
  }
  else {
    param_1[2] = (uint)param_3[1];
    param_1[3] = param_4[3];
  }
  if ((param_2 & 4) != 0) {
    param_1[4] = (uint)param_3[2];
    param_1[5] = param_4[5];
    return;
  }
  param_1[4] = param_4[4];
  param_1[5] = (uint)param_3[2];
  return;
}


