// 100366b0 RwGetUserDrawVertexIndex [Global]
// programa: RWL21.DLL

undefined4 RwGetUserDrawVertexIndex(int param_1)

{
                    /* 0x366b0  271  RwGetUserDrawVertexIndex */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (*(int *)(param_1 + 0x28) == 2) {
    return *(undefined4 *)(param_1 + 0x30);
  }
  FUN_1000cba0(0x33);
  return 0;
}


