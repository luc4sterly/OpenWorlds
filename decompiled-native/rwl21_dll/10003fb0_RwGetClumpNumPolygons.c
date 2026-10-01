// 10003fb0 RwGetClumpNumPolygons [Global]
// program: RWL21.DLL

undefined4 RwGetClumpNumPolygons(int param_1)

{
                    /* 0x3fb0  159  RwGetClumpNumPolygons */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x94);
  }
  FUN_1000cba0(1);
  return 0xffffffff;
}


