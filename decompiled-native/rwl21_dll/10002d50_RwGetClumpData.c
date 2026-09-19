// 10002d50 RwGetClumpData [Global]
// programa: RWL21.DLL

undefined4 RwGetClumpData(int param_1)

{
                    /* 0x2d50  148  RwGetClumpData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0xb0);
  }
  FUN_1000cba0(1);
  return 0;
}


