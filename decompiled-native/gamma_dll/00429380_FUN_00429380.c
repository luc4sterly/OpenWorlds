// 00429380 FUN_00429380 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_00429380(undefined4 *param_1,int param_2,int param_3)

{
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_10 = 0;
  local_14 = 0;
  local_1c = 1.0;
  local_18 = 0;
  FUN_00426de0(&local_1c,(float *)(param_2 + 4),(float *)(param_3 + 4));
  *param_1 = &PTR_LAB_00473828;
  param_1[2] = local_18;
  param_1[3] = local_14;
  param_1[4] = local_10;
  param_1[1] = local_1c;
  return param_1;
}


