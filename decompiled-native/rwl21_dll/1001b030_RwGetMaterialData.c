// 1001b030 RwGetMaterialData [Global]
// program: RWL21.DLL

undefined4 RwGetMaterialData(int param_1)

{
                    /* 0x1b030  198  RwGetMaterialData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x38);
  }
  FUN_1000cba0(1);
  return 0;
}


