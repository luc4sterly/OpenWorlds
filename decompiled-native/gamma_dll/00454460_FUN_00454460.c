// 00454460 FUN_00454460 [Global]
// programa: gamma.dll

void __cdecl FUN_00454460(uint *param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  param_1[1] = param_3 | 1;
  *param_1 = param_2;
  if (param_4 != 0) {
    *param_1 = *param_1 | 4;
  }
  if (param_5 == 0) {
    *(uint *)((param_2 - 4) + (int)param_1) = param_2;
  }
  else {
    *param_1 = *param_1 | 2;
    *(uint *)(param_2 + (int)param_1) = *(uint *)(param_2 + (int)param_1) | 4;
  }
  return;
}


