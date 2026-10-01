// 1002c320 FUN_1002c320 [Global]
// program: RWL21.DLL

void FUN_1002c320(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    return;
  }
  FUN_1000cba0(1);
  return;
}


