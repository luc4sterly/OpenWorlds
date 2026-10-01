// 100273c0 RwGetRasterHeight [Global]
// program: RWL21.DLL

undefined4 RwGetRasterHeight(int param_1)

{
                    /* 0x273c0  234  RwGetRasterHeight */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x20);
  }
  FUN_1000cba0(1);
  return 0xffffffff;
}


