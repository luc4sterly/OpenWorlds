// 10036580 RwGetUserDrawData [Global]
// programa: RWL21.DLL

undefined4 RwGetUserDrawData(int param_1)

{
                    /* 0x36580  265  RwGetUserDrawData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 4);
  }
  FUN_1000cba0(1);
  return 0;
}


