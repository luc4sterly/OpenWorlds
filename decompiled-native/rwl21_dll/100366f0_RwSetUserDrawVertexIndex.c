// 100366f0 RwSetUserDrawVertexIndex [Global]
// program: RWL21.DLL

int RwSetUserDrawVertexIndex(int param_1,undefined4 param_2)

{
                    /* 0x366f0  485  RwSetUserDrawVertexIndex */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (*(int *)(param_1 + 0x28) == 2) {
    *(undefined4 *)(param_1 + 0x30) = param_2;
    return param_1;
  }
  FUN_1000cba0(0x33);
  return 0;
}


