// 00445e10 FUN_00445e10 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00445e10(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0x28) + 0x14) == 0) {
    return 0x80040227;
  }
  if (*(char *)(param_1 + 0x9d) != '\0') {
    return 1;
  }
  if (*(char *)(param_1 + 0x24) != '\0') {
    return 0x8004020b;
  }
  return 0;
}


