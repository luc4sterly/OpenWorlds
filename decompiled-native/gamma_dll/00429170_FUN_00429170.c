// 00429170 FUN_00429170 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_00429170(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  uVar1 = *(undefined4 *)(param_2 + 4);
  fVar2 = _DAT_00473440 * *(float *)(param_2 + 8);
  fVar3 = _DAT_00473440 * *(float *)(param_2 + 0xc);
  fVar4 = _DAT_00473440 * *(float *)(param_2 + 0x10);
  *param_1 = &PTR_LAB_00473828;
  param_1[2] = fVar2;
  param_1[3] = fVar3;
  param_1[4] = fVar4;
  param_1[1] = uVar1;
  return param_1;
}


