// 10003fe0 RwGetClumpNumVertices [Global]
// programa: RWL21.DLL

int RwGetClumpNumVertices(int param_1)

{
                    /* 0x3fe0  161  RwGetClumpNumVertices */
  if (param_1 != 0) {
    return *(int *)(*(int *)(param_1 + 0x88) + 8) + -8;
  }
  FUN_1000cba0(1);
  return -1;
}


