// 10001000 FUN_10001000 [Global]
// program: RWDLDD21.DLL

undefined4 FUN_10001000(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = *(int **)(param_1 + 0x10 + *(int *)(param_1 + 0x48) * 4);
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_14 = 0x14;
  iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,&local_14);
  if (iVar2 != 0) {
    return 0;
  }
  *(int *)(param_1 + 0x20) = local_c;
  iVar2 = *(int *)(param_1 + 0x38 + *(int *)(param_1 + 0x48) * 4);
  *(int *)(param_1 + 0x24) = local_c;
  *(int *)(param_1 + 0x34) = iVar2 + local_c;
  *(int *)(param_1 + 0x28) = local_c;
  local_c = ((*(uint *)(param_1 + 0x38 + *(int *)(param_1 + 0x48) * 4) & 0xffffffc1) >> 1) + local_c
  ;
  *(int *)(param_1 + 0x2c) = local_c;
  *(int *)(param_1 + 0x30) = local_c;
  return 1;
}


