// 1000b670 RwBeginCameraUpdate [Global]
// program: RWL21.DLL

int RwBeginCameraUpdate(int param_1,undefined4 param_2)

{
                    /* 0xb670  19  RwBeginCameraUpdate */
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x8c) == 2) {
      FUN_10041b80(param_1,(float *)(param_1 + 0x74));
      *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x88);
      FUN_10041c10();
    }
    *(int *)(PTR_DAT_1005b69c + 0x10) = param_1;
    (**(code **)(PTR_DAT_1005b69c + 0x34))(*(undefined4 *)(PTR_DAT_1005b69c + 0x10),param_2);
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


