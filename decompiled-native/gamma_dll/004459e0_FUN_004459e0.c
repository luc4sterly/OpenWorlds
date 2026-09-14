// 004459e0 FUN_004459e0 [Global]
// programa: gamma.dll

int __fastcall FUN_004459e0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x98);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1);
    if (iVar2 < 0) {
      return iVar2;
    }
    (**(code **)(**(int **)(param_1 + 0x98) + 8))(*(int **)(param_1 + 0x98));
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  return 0;
}


