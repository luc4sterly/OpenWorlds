// 10036640 RwGetUserDrawAlignment [Global]
// program: RWL21.DLL

undefined4 RwGetUserDrawAlignment(int param_1)

{
                    /* 0x36640  263  RwGetUserDrawAlignment */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x2c);
  }
  FUN_1000cba0(1);
  return 0;
}


