// 10031160 RwSetDebugSeverity [Global]
// program: RWL21.DLL

void RwSetDebugSeverity(undefined4 param_1)

{
                    /* 0x31160  399  RwSetDebugSeverity */
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2e8) = param_1;
  return;
}


