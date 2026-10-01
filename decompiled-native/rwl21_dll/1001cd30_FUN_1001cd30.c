// 1001cd30 FUN_1001cd30 [Global]
// program: RWL21.DLL

void FUN_1001cd30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x34) = param_3;
  *(undefined4 *)(param_1 + 0x38) = param_4;
  *(undefined1 *)(param_1 + 0x40) = 0;
  *(undefined1 *)(param_1 + 0x41) = 1;
  return;
}


