// 00445dc0 FUN_00445dc0 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00445dc0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0x24) = 0;
  if (*(int *)(param_1 + 0x98) == 0) {
    return 0x8004020a;
  }
  *(undefined1 *)(param_1 + 0x9d) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x18))(*(int **)(param_1 + 0x98));
  return uVar1;
}


