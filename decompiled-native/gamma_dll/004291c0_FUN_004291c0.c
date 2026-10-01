// 004291c0 FUN_004291c0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004291c0(void *this,undefined4 *param_1,int param_2)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = 0;
  FUN_00426eb0((float *)((int)this + 4),&local_18,1,(undefined4 *)(param_2 + 4));
  *param_1 = &PTR_LAB_004732e8;
  param_1[1] = local_18;
  param_1[2] = local_14;
  param_1[3] = local_10;
  return param_1;
}


