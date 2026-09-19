// 10019cc0 RwGetMaterialDiffuseRGB [Global]
// programa: RWL21.DLL

undefined4 * RwGetMaterialDiffuseRGB(int param_1,undefined4 *param_2)

{
                    /* 0x19cc0  545  RwGetMaterialDiffuseRGB */
  if (param_1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x18);
      param_2[1] = *(undefined4 *)(param_1 + 0x1c);
      param_2[2] = *(undefined4 *)(param_1 + 0x20);
      return param_2;
    }
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


