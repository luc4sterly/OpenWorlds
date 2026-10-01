// 100159f0 RwSetHints [Global]
// program: RWL21.DLL

bool RwSetHints(uint param_1)

{
  int iVar1;
  
                    /* 0x159f0  403  RwSetHints */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  iVar1 = RwSetClumpHints(**(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


