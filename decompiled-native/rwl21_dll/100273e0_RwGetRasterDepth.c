// 100273e0 RwGetRasterDepth [Global]
// programa: RWL21.DLL

undefined4 RwGetRasterDepth(int param_1)

{
                    /* 0x273e0  233  RwGetRasterDepth */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x24);
  }
  FUN_1000cba0(1);
  return 0xffffffff;
}


