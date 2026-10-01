// 100016a0 RwGetPolygonNumSides [Global]
// program: RWL21.DLL

undefined1 RwGetPolygonNumSides(int param_1)

{
                    /* 0x16a0  223  RwGetPolygonNumSides */
  if (param_1 != 0) {
    return *(undefined1 *)(param_1 + 0x3a);
  }
  FUN_1000cba0(1);
  return 0;
}


