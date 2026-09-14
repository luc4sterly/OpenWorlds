// 00433610 FUN_00433610 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00433610(void *this,undefined4 *param_1)

{
  undefined ***pppuVar1;
  undefined **local_30 [4];
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (*(int **)this == (int *)0x0) {
    local_20 = &PTR_LAB_00473390;
    pppuVar1 = &local_20;
    local_1c = 0;
    local_14 = 0;
    local_18 = 0;
  }
  else {
    (**(code **)(**(int **)this + 8))(local_30);
    pppuVar1 = local_30;
  }
  *param_1 = &PTR_LAB_00473390;
  param_1[1] = pppuVar1[1];
  param_1[2] = pppuVar1[2];
  param_1[3] = pppuVar1[3];
  return param_1;
}


