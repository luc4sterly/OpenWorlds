// 00424460 FUN_00424460 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00424460(void *this,undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  if (param_1 == param_2) {
    return param_1;
  }
  uVar1 = (*(int *)((int)this + 8) + *(int *)((int)this + 4)) - (int)param_2;
  if (uVar1 != 0) {
    FUN_0044df50(param_1,param_2,uVar1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) - ((int)param_2 - (int)param_1);
  return param_1;
}


