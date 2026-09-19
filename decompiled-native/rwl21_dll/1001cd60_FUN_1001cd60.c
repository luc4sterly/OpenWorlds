// 1001cd60 FUN_1001cd60 [Global]
// programa: RWL21.DLL

void FUN_1001cd60(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x30);
  param_2[1] = *(undefined4 *)(param_1 + 0x34);
  param_2[2] = *(undefined4 *)(param_1 + 0x38);
  return;
}


