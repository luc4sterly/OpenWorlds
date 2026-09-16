// 0044fa40 FUN_0044fa40 [Global]
// programa: gamma.dll

uint __thiscall FUN_0044fa40(int param_1,ushort param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    return 0xffffffff;
  }
  if ((*(char *)(param_1 + 0x52) == '\0') && (*(char *)(param_1 + 0x51) != '\0')) {
    if (param_2 == 0xffffffff) {
      return 0xffffffff;
    }
    uVar1 = FUN_004555b0((uint)param_2,*(int *)(param_1 + 0x24));
    if (uVar1 == 0xffffffff) {
      return 0xffffffff;
    }
  }
  else {
    if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 4)) {
      return 0xffffffff;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -2;
    if (param_2 != 0xffff) {
      **(ushort **)(param_1 + 8) = param_2;
    }
  }
  if (param_2 == 0xffff) {
    uVar1 = 0xffff0000;
  }
  else {
    uVar1 = (uint)param_2;
  }
  return uVar1;
}


