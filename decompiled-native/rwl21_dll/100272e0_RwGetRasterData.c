// 100272e0 RwGetRasterData [Global]
// program: RWL21.DLL

undefined4 RwGetRasterData(int param_1)

{
                    /* 0x272e0  232  RwGetRasterData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x30);
  }
  FUN_1000cba0(1);
  return 0;
}


