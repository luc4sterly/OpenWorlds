// 10031060 RwSetDebugOutputState [Global]
// programa: RWL21.DLL

void RwSetDebugOutputState(undefined4 param_1)

{
                    /* 0x31060  397  RwSetDebugOutputState */
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2d0) = param_1;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2cc) = param_1;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2d4) = param_1;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2d8) = param_1;
  return;
}


