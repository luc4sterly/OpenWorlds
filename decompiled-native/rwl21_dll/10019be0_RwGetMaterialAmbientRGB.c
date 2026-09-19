// 10019be0 RwGetMaterialAmbientRGB [Global]
// programa: RWL21.DLL

undefined4 * RwGetMaterialAmbientRGB(int param_1,undefined4 *param_2)

{
                    /* 0x19be0  544  RwGetMaterialAmbientRGB */
  if (param_1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0xc);
      param_2[1] = *(undefined4 *)(param_1 + 0x10);
      param_2[2] = *(undefined4 *)(param_1 + 0x14);
      return param_2;
    }
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


