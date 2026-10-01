// 10027270 RwSetRasterData [Global]
// program: RWL21.DLL

int RwSetRasterData(int param_1,undefined4 param_2)

{
                    /* 0x27270  446  RwSetRasterData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x30) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


