// 10019d70 RwGetMaterialTextureModes [Global]
// program: RWL21.DLL

byte RwGetMaterialTextureModes(int param_1)

{
                    /* 0x19d70  206  RwGetMaterialTextureModes */
  if (param_1 != 0) {
    return *(byte *)(param_1 + 0x30) & 0x1f;
  }
  FUN_1000cba0(1);
  return 0;
}


