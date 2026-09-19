// 10019c50 RwGetMaterialSpecularRGB [Global]
// programa: RWL21.DLL

undefined4 * RwGetMaterialSpecularRGB(int param_1,undefined4 *param_2)

{
                    /* 0x19c50  546  RwGetMaterialSpecularRGB */
  if (param_1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x24);
      param_2[1] = *(undefined4 *)(param_1 + 0x28);
      param_2[2] = *(undefined4 *)(param_1 + 0x2c);
      return param_2;
    }
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


