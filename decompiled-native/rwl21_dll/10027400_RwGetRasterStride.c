// 10027400 RwGetRasterStride [Global]
// programa: RWL21.DLL

undefined4 RwGetRasterStride(int param_1)

{
                    /* 0x27400  236  RwGetRasterStride */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x28);
  }
  FUN_1000cba0(1);
  return 0xffffffff;
}


