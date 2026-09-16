// 00424070 FUN_00424070 [Global]
// programa: gamma.dll

int __thiscall FUN_00424070(int param_1,int param_2)

{
  if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 4)) {
    return -1;
  }
  if (param_2 != -1) {
    if (((*(byte *)(param_1 + 0x24) & 0x10) == 0) &&
       ((char)param_2 != *(char *)(*(uint *)(param_1 + 8) - 1))) {
      return -1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    **(char **)(param_1 + 8) = (char)param_2;
    return param_2;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  return 0;
}


