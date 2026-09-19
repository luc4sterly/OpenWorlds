// 1001d9b0 RwCopyMatrix [Global]
// programa: RWL21.DLL

longlong __fastcall
RwCopyMatrix(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint extraout_EDX;
  longlong lVar1;
  
                    /* 0x1d9b0  36  RwCopyMatrix */
  if ((param_3 != (undefined4 *)0x0) && (param_4 != (undefined4 *)0x0)) {
    lVar1 = FUN_100510e0(param_1,param_2,param_3,param_4);
    return lVar1;
  }
  FUN_1000cba0(1);
  return (ulonglong)extraout_EDX << 0x20;
}


