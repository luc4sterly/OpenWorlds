// 004252f0 FUN_004252f0 [Global]
// program: gamma.dll

void __cdecl FUN_004252f0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_3,DAT_0049d250,(float)fVar1);
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_3,DAT_0049d254,(float)fVar1);
  fVar1 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_3,DAT_0049d258,(float)fVar1);
  return;
}


