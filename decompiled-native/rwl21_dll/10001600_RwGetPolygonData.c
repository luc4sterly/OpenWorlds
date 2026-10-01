// 10001600 RwGetPolygonData [Global]
// program: RWL21.DLL

undefined4 RwGetPolygonData(int param_1)

{
                    /* 0x1600  216  RwGetPolygonData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x28);
  }
  FUN_1000cba0(1);
  return 0;
}


