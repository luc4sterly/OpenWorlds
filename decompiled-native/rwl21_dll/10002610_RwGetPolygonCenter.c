// 10002610 RwGetPolygonCenter [Global]
// program: RWL21.DLL

undefined4 * RwGetPolygonCenter(int param_1,undefined4 *param_2)

{
                    /* 0x2610  214  RwGetPolygonCenter */
  if (param_1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x1c);
      param_2[1] = *(undefined4 *)(param_1 + 0x20);
      param_2[2] = *(undefined4 *)(param_1 + 0x24);
      return param_2;
    }
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


