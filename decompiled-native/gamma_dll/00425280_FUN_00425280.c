// 00425280 FUN_00425280 [Global]
// program: gamma.dll

void __cdecl FUN_00425280(int *param_1,undefined4 param_2,float *param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  *param_3 = (float)fVar1;
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  param_3[1] = (float)fVar1;
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  param_3[2] = (float)fVar1;
  return;
}


