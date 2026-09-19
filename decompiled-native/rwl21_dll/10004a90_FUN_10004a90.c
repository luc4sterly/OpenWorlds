// 10004a90 FUN_10004a90 [Global]
// programa: RWL21.DLL

void FUN_10004a90(int param_1,float param_2,float param_3,float param_4)

{
  if (*(uint **)(param_1 + 0xb8) != (uint *)0x0) {
    FUN_1002ba70(*(uint **)(param_1 + 0xb8));
  }
  FUN_100424f0(*(int **)(param_1 + 0x88),param_2,param_3,param_4);
  return;
}


