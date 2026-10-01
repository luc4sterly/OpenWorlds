// 10036450 RwGetUserDrawOffset [Global]
// program: RWL21.DLL

int RwGetUserDrawOffset(int param_1,undefined4 *param_2,undefined4 *param_3)

{
                    /* 0x36450  266  RwGetUserDrawOffset */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 8);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0xc);
      return param_1;
    }
  }
  return param_1;
}


