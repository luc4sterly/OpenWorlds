// 10008f00 RwGetClumpJointMatrix [Global]
// program: RWL21.DLL

longlong __fastcall
RwGetClumpJointMatrix(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint extraout_EDX;
  longlong lVar1;
  
                    /* 0x8f00  153  RwGetClumpJointMatrix */
  if ((param_3 != 0) && (param_4 != 0)) {
    lVar1 = FUN_100510e0(param_4,param_2,(undefined4 *)(param_3 + 0x130),(undefined4 *)param_4);
    return lVar1;
  }
  FUN_1000cba0(1);
  return (ulonglong)extraout_EDX << 0x20;
}


