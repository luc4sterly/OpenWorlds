// 00416160 FUN_00416160 [Global]
// program: gamma.dll

void __thiscall FUN_00416160(void *this,int *param_1)

{
  if (*param_1 != 0) {
    FUN_004190a0(*param_1);
  }
  if (param_1[5] == 0) {
    *(int *)((int)this + 4) = param_1[4];
  }
  else {
    *(int *)(param_1[5] + 0x10) = param_1[4];
  }
  if (param_1[4] != 0) {
    *(int *)(param_1[4] + 0x14) = param_1[5];
  }
  FUN_0044e100(param_1);
  return;
}


