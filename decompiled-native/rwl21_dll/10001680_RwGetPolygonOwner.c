// 10001680 RwGetPolygonOwner [Global]
// programa: RWL21.DLL

undefined4 RwGetPolygonOwner(int param_1)

{
                    /* 0x1680  225  RwGetPolygonOwner */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x34);
  }
  FUN_1000cba0(1);
  return 0;
}


