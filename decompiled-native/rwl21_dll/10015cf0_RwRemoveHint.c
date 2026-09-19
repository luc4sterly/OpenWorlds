// 10015cf0 RwRemoveHint [Global]
// programa: RWL21.DLL

bool RwRemoveHint(uint param_1)

{
  int iVar1;
  
                    /* 0x15cf0  335  RwRemoveHint */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return false;
  }
  iVar1 = RwRemoveHintFromClump(**(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


