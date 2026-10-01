// 004316e0 FUN_004316e0 [Global]
// program: gamma.dll

float10 __fastcall FUN_004316e0(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x48) = 0;
  return (float10)fVar1;
}


