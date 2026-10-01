// 0041c530 FUN_0041c530 [Global]
// program: gamma.dll

void __cdecl FUN_0041c530(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x8c))
            (param_1,param_2,param_3,
             &param_3 +
             ((int)(&stack0x00000013 + -(int)&param_3 +
                   ((int)(&stack0x00000013 + -(int)&param_3) >> 0x1f & 3)) >> 2));
  return;
}


