// 10001080 FUN_10001080 [Global]
// program: RWDLDD21.DLL

undefined4 FUN_10001080(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (*(undefined1 **)(param_1 + 0x2c) == *(undefined1 **)(param_1 + 0x30)) {
    return 1;
  }
  **(undefined1 **)(param_1 + 0x30) = 0xb;
  *(undefined1 *)(*(int *)(param_1 + 0x30) + 1) = 0;
  *(undefined2 *)(*(int *)(param_1 + 0x30) + 2) = 0;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 4;
  piVar1 = *(int **)(param_1 + 0x10 + *(int *)(param_1 + 0x48) * 4);
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
  if (iVar2 != 0) {
    return 0;
  }
  puVar5 = (undefined4 *)&stack0xffffffcc;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,&stack0xffffffcc);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))
                    (*(int **)(param_1 + 8),piVar1,*(undefined4 *)(param_1 + 0xc),2);
  if (iVar2 != 0) {
    return 0;
  }
  FUN_100031f0();
  uVar3 = *(int *)(param_1 + 0x48) + 1;
  uVar4 = (int)uVar3 >> 0x1f;
  *(uint *)(param_1 + 0x48) = uVar3;
  *(uint *)(param_1 + 0x48) = ((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4;
  FUN_10001000(param_1);
  return 1;
}


