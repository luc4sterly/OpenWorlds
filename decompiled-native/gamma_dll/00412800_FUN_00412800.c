// 00412800 FUN_00412800 [Global]
// program: gamma.dll

void __cdecl FUN_00412800(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0xf8))
            (param_1,param_2,param_3,
             &param_3 +
             ((int)(&stack0x00000013 + -(int)&param_3 +
                   ((int)(&stack0x00000013 + -(int)&param_3) >> 0x1f & 3)) >> 2));
  return;
}


