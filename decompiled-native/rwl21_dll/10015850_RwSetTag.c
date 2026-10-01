// 10015850 RwSetTag [Global]
// program: RWL21.DLL

bool RwSetTag(undefined4 param_1)

{
  int iVar1;
  
                    /* 0x15850  468  RwSetTag */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  iVar1 = RwSetClumpTag(**(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


