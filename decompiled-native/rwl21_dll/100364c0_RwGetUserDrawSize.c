// 100364c0 RwGetUserDrawSize [Global]
// program: RWL21.DLL

int RwGetUserDrawSize(int param_1,undefined4 *param_2,undefined4 *param_3)

{
                    /* 0x364c0  269  RwGetUserDrawSize */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x10);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0x14);
      return param_1;
    }
  }
  return param_1;
}


