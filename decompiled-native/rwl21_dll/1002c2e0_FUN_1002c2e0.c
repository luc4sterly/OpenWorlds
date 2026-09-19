// 1002c2e0 FUN_1002c2e0 [Global]
// programa: RWL21.DLL

void FUN_1002c2e0(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x178); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x184)) {
    FUN_1002c2e0(iVar1);
  }
  FUN_1002baf0(*(uint **)(param_1 + 0xb8));
  return;
}


