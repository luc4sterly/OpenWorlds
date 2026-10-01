// 1001d370 RwDestroyMatrix [Global]
// program: RWL21.DLL

undefined4 * RwDestroyMatrix(undefined4 *param_1)

{
                    /* 0x1d370  62  RwDestroyMatrix */
  if (param_1 != (undefined4 *)0x0) {
    FUN_10037010(DAT_1005ac38,param_1);
    return param_1;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


