// 10001620 RwSetPolygonTag [Global]
// programa: RWL21.DLL

int RwSetPolygonTag(int param_1,undefined2 param_2)

{
                    /* 0x1620  442  RwSetPolygonTag */
  if (param_1 != 0) {
    *(undefined2 *)(param_1 + 0x38) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


