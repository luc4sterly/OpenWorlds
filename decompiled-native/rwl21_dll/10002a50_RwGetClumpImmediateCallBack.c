// 10002a50 RwGetClumpImmediateCallBack [Global]
// programa: RWL21.DLL

undefined4 RwGetClumpImmediateCallBack(int param_1)

{
                    /* 0x2a50  152  RwGetClumpImmediateCallBack */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x194);
  }
  return 0;
}


