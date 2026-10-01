// 10002a30 RwSetClumpImmediateCallBack [Global]
// program: RWL21.DLL

void RwSetClumpImmediateCallBack(int param_1,undefined4 param_2)

{
                    /* 0x2a30  385  RwSetClumpImmediateCallBack */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x194) = param_2;
  }
  return;
}


