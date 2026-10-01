// 00439880 FUN_00439880 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00439880(void *this,undefined4 *param_1)

{
  if (*(int **)((int)this + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)((int)this + 0xc) + 4))(param_1);
    return param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


