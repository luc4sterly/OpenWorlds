// 00429230 FUN_00429230 [Global]
// program: gamma.dll

undefined4 * __cdecl FUN_00429230(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = 0;
  FUN_00426eb0((float *)(param_2 + 4),&local_18,1,(undefined4 *)(param_3 + 4));
  *param_1 = &PTR_LAB_004732e8;
  param_1[1] = local_18;
  param_1[2] = local_14;
  param_1[3] = local_10;
  return param_1;
}


