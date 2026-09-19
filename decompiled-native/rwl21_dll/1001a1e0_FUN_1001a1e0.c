// 1001a1e0 FUN_1001a1e0 [Global]
// programa: RWL21.DLL

void FUN_1001a1e0(int param_1)

{
  if (*(int *)(param_1 + 0x34) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 0xd8) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 0xc0) = 0;
  }
  return;
}


