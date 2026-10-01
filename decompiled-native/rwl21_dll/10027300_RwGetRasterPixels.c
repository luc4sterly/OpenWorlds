// 10027300 RwGetRasterPixels [Global]
// program: RWL21.DLL

undefined4 RwGetRasterPixels(int param_1)

{
  int iVar1;
  
                    /* 0x27300  235  RwGetRasterPixels */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (((*(uint *)(param_1 + 0x40) & 2) != 0) &&
     (*(code **)(PTR_DAT_1005b69c + 0x298) != (code *)0x0)) {
    iVar1 = (**(code **)(PTR_DAT_1005b69c + 0x298))(param_1);
    if (iVar1 == 0) {
      FUN_1000cba0(1);
      return 0;
    }
  }
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 1;
  return *(undefined4 *)(param_1 + 0x18);
}


