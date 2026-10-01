// 10020470 RwGetSplineData [Global]
// program: RWL21.DLL

undefined4 RwGetSplineData(int param_1)

{
                    /* 0x20470  245  RwGetSplineData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 8);
  }
  FUN_1000cba0(1);
  return 0;
}


