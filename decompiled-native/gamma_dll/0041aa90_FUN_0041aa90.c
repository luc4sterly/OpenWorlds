// 0041aa90 FUN_0041aa90 [Global]
// programa: gamma.dll

void __cdecl FUN_0041aa90(int *param_1,undefined4 param_2,float *param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895d4);
  *param_3 = (float)fVar1;
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895d8);
  param_3[1] = (float)fVar1;
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895dc);
  param_3[2] = (float)fVar1;
  return;
}


