// 100273a0 RwGetRasterWidth [Global]
// programa: RWL21.DLL

undefined4 RwGetRasterWidth(int param_1)

{
                    /* 0x273a0  237  RwGetRasterWidth */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x1c);
  }
  FUN_1000cba0(1);
  return 0xffffffff;
}


