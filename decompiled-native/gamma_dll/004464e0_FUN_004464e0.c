// 004464e0 FUN_004464e0 [Global]
// program: gamma.dll

uint FUN_004464e0(int *param_1)

{
  LONG LVar1;
  uint uVar2;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if (LVar1 == 0) {
    param_1[2] = param_1[2] + 1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0xc))(1);
    }
    return 0;
  }
  uVar2 = param_1[2];
  if ((uint)param_1[2] <= DAT_0047a27c) {
    uVar2 = DAT_0047a27c;
  }
  return uVar2;
}


