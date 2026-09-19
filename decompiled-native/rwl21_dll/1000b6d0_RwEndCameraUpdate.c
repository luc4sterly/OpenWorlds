// 1000b6d0 RwEndCameraUpdate [Global]
// programa: RWL21.DLL

int RwEndCameraUpdate(int param_1)

{
                    /* 0xb6d0  81  RwEndCameraUpdate */
  if (param_1 != 0) {
    if (*(int *)(PTR_DAT_1005b69c + 0x10) == param_1) {
      if (*(int *)(param_1 + 0x8c) == 2) {
        FUN_10041c20();
      }
      (**(code **)(PTR_DAT_1005b69c + 0x254))(*(undefined4 *)(PTR_DAT_1005b69c + 0x10));
      FUN_10036090(*(int *)(PTR_DAT_1005b69c + 0x10));
    }
    *(undefined4 *)(PTR_DAT_1005b69c + 0x10) = 0;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


