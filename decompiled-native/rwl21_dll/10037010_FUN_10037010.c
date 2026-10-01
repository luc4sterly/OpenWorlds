// 10037010 FUN_10037010 [Global]
// program: RWL21.DLL

void FUN_10037010(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 **)(param_1 + 0x10) = param_2;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  }
  return;
}


