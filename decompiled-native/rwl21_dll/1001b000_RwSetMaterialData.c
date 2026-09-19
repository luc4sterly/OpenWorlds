// 1001b000 RwSetMaterialData [Global]
// programa: RWL21.DLL

int RwSetMaterialData(int param_1,undefined4 param_2)

{
                    /* 0x1b000  417  RwSetMaterialData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x38) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


