// 004279e0 FUN_004279e0 [Global]
// program: gamma.dll

uint * __fastcall FUN_004279e0(uint *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00402c10();
  *param_1 = uVar1 / 1000;
  param_1[1] = uVar1 % 1000;
  return param_1;
}


