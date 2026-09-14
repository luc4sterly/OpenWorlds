// 004295e0 FUN_004295e0 [Global]
// programa: gamma.dll

float10 __cdecl FUN_004295e0(int param_1,int param_2)

{
  return (float10)*(float *)(param_1 + 0xc) * (float10)*(float *)(param_2 + 0xc) +
         (float10)*(float *)(param_1 + 4) * (float10)*(float *)(param_2 + 4) +
         (float10)*(float *)(param_1 + 8) * (float10)*(float *)(param_2 + 8);
}


