// 00426de0 FUN_00426de0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00426de0(float *param_1,float *param_2,float *param_3)

{
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  local_1c = *param_2 + *param_3;
  local_18 = param_2[1] + param_3[1];
  local_14 = param_2[2] + param_3[2];
  FUN_00427ff0(&local_1c);
  *param_1 = local_14 * param_2[2] + local_1c * *param_2 + local_18 * param_2[1];
  if ((byte)((byte)((ushort)((ushort)(NAN(*param_1) || NAN((float)_DAT_00471cf0)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*param_1 == (float)_DAT_00471cf0) << 0xe) >> 8)) == 0x40) {
    local_24 = *param_3;
    local_20 = param_3[1];
    local_28 = param_3[2];
    FUN_00427fb0(param_1 + 1,param_2,&local_28);
    FUN_00427ff0(param_1 + 1);
  }
  else {
    FUN_00427fb0(param_1 + 1,param_2,&local_1c);
  }
  return;
}


