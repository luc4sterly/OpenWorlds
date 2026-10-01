// 10030b70 FUN_10030b70 [Global]
// program: RWL21.DLL

void FUN_10030b70(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_1005e010;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


