// 10004840 RwGetClumpMatrix [Global]
// programa: RWL21.DLL

longlong __fastcall RwGetClumpMatrix(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint extraout_EDX;
  longlong lVar1;
  
                    /* 0x4840  157  RwGetClumpMatrix */
  if ((param_3 != 0) && (param_4 != 0)) {
    lVar1 = FUN_100510e0(param_4,param_2,(undefined4 *)(param_3 + 0xec),(undefined4 *)param_4);
    return lVar1;
  }
  FUN_1000cba0(1);
  return (ulonglong)extraout_EDX << 0x20;
}


