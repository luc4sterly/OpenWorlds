// 004578a0 FUN_004578a0 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_004578a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint local_34 [9];
  int local_10;
  
  puVar2 = param_1;
  puVar3 = local_34;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = FUN_00457730(local_34,&local_10);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  puVar3 = local_34;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return local_10;
}


