// 10019d50 RwGetMaterialTexture [Global]
// program: RWL21.DLL

undefined4 RwGetMaterialTexture(int param_1)

{
                    /* 0x19d50  205  RwGetMaterialTexture */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x34);
  }
  FUN_1000cba0(1);
  return 0;
}


