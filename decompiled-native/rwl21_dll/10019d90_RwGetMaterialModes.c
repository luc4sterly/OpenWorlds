// 10019d90 RwGetMaterialModes [Global]
// program: RWL21.DLL

byte RwGetMaterialModes(int param_1)

{
                    /* 0x19d90  202  RwGetMaterialModes */
  if (param_1 != 0) {
    return *(byte *)(param_1 + 0x30) & 0xc0;
  }
  FUN_1000cba0(1);
  return 0;
}


