// 100308b0 RwSetSceneData [Global]
// program: RWL21.DLL

int RwSetSceneData(int param_1,undefined4 param_2)

{
                    /* 0x308b0  447  RwSetSceneData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x24) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


