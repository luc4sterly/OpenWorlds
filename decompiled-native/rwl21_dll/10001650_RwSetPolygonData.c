// 10001650 RwSetPolygonData [Global]
// program: RWL21.DLL

int RwSetPolygonData(int param_1,undefined4 param_2)

{
                    /* 0x1650  433  RwSetPolygonData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x28) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


