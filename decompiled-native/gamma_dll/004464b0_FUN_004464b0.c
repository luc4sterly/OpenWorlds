// 004464b0 FUN_004464b0 [Global]
// program: gamma.dll

uint FUN_004464b0(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (*(uint *)(param_1 + 8) <= DAT_0047a278) {
    uVar1 = DAT_0047a278;
  }
  return uVar1;
}


