// 10027360 RwReleaseRasterPixels [Global]
// programa: RWL21.DLL

int RwReleaseRasterPixels(int param_1)

{
  int iVar1;
  
                    /* 0x27360  332  RwReleaseRasterPixels */
  if (((*(uint *)(param_1 + 0x40) & 2) != 0) &&
     (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) {
    iVar1 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1);
    if (iVar1 == 0) {
      FUN_1000cba0(1);
      return 0;
    }
  }
  return param_1;
}


