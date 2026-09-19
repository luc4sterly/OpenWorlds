// 1001d820 RwGetMatrixElement [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 RwGetMatrixElement(int param_1,int param_2,int param_3)

{
  float local_4;
  
                    /* 0x1d820  207  RwGetMatrixElement */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return (float10)0.0;
  }
  if ((((-1 < param_3) && (param_3 < 4)) && (-1 < param_2)) && (param_2 < 4)) {
    if (param_3 == 3) {
      local_4 = _DAT_10052180;
      if (param_2 == 3) {
        local_4 = _DAT_10052184;
      }
    }
    else {
      local_4 = *(float *)(param_1 + (param_3 + param_2 * 4) * 4);
    }
    return (float10)local_4;
  }
  FUN_1000cba0(0xb);
  return (float10)0.0;
}


