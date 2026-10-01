// 00427220 FUN_00427220 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00427220(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_2;
  fVar2 = (float)_DAT_00471e38 /
          (fVar1 * fVar1 +
          param_2[3] * param_2[3] + param_2[1] * param_2[1] + param_2[2] * param_2[2]);
  *param_1 = fVar1 * fVar2;
  param_1[1] = param_2[1];
  fVar2 = -fVar2;
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[1] = fVar2 * param_1[1];
  param_1[2] = fVar2 * param_1[2];
  param_1[3] = fVar2 * param_1[3];
  return;
}


