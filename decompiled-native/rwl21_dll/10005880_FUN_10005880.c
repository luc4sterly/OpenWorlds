// 10005880 FUN_10005880 [Global]
// programa: RWL21.DLL

void FUN_10005880(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x17c) != 0) {
    *(undefined4 *)(param_2 + 0x184) = 0;
    *(undefined4 *)(param_2 + 0x180) = *(undefined4 *)(param_1 + 0x17c);
    *(int *)(*(int *)(param_1 + 0x17c) + 0x184) = param_2;
    *(int *)(param_1 + 0x17c) = param_2;
    return;
  }
  *(int *)(param_1 + 0x178) = param_2;
  *(int *)(param_1 + 0x17c) = param_2;
  *(undefined4 *)(param_2 + 0x180) = 0;
  *(undefined4 *)(param_2 + 0x184) = 0;
  return;
}


