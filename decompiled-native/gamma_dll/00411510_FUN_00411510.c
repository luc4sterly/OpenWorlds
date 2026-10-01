// 00411510 FUN_00411510 [Global]
// program: gamma.dll

uint __thiscall FUN_00411510(int param_1,uint param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    return 0xffffffff;
  }
  if ((*(char *)(param_1 + 0x42) == '\0') && (*(char *)(param_1 + 0x41) != '\0')) {
    if (param_2 == 0xffffffff) {
      return 0xffffffff;
    }
    uVar1 = FUN_004555b0(param_2,*(int *)(param_1 + 0x24));
    if (uVar1 == 0xffffffff) {
      return 0xffffffff;
    }
  }
  else {
    if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 4)) {
      return 0xffffffff;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    if (param_2 != 0xffffffff) {
      **(undefined1 **)(param_1 + 8) = (char)param_2;
    }
  }
  if (param_2 == 0xffffffff) {
    param_2 = 0;
  }
  return param_2;
}


