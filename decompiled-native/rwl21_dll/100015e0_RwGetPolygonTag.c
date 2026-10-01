// 100015e0 RwGetPolygonTag [Global]
// program: RWL21.DLL

int RwGetPolygonTag(int param_1)

{
                    /* 0x15e0  227  RwGetPolygonTag */
  if (param_1 != 0) {
    return (int)*(short *)(param_1 + 0x38);
  }
  FUN_1000cba0(1);
  return 0;
}


