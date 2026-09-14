// 00426eb0 FUN_00426eb0 [Global]
// programa: gamma.dll

void __cdecl FUN_00426eb0(float *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  float local_40 [4];
  float local_30 [4];
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  FUN_00427220(local_40,param_1);
  iVar1 = 0;
  if (0 < param_3) {
    do {
      local_20 = 0.0;
      local_1c = *param_4;
      local_18 = param_4[1];
      local_14 = param_4[2];
      FUN_004272c0(local_30,&local_20,local_40);
      FUN_004272c0(&local_20,param_1,local_30);
      iVar1 = iVar1 + 1;
      *param_2 = local_1c;
      param_2[1] = local_18;
      param_4 = param_4 + 3;
      param_2[2] = local_14;
      param_2 = param_2 + 3;
    } while (iVar1 < param_3);
  }
  return;
}


