// 1000dac0 RwSetLightData [Global]
// programa: RWL21.DLL

int RwSetLightData(int param_1,undefined4 param_2)

{
                    /* 0xdac0  409  RwSetLightData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x88) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


