// 0042b930 FUN_0042b930 [Global]
// program: gamma.dll

void __cdecl FUN_0042b930(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_1;
  if ((uint *)*param_2 == param_1) {
    *param_2 = uVar1;
  }
  *param_1 = *(uint *)(uVar1 + 4);
  if (*(int *)(uVar1 + 4) != 0) {
    puVar2 = (uint *)(*(int *)(uVar1 + 4) + 8);
    *puVar2 = *puVar2 & 1 | (uint)param_1;
  }
  *(uint *)(uVar1 + 8) = *(uint *)(uVar1 + 8) & 1 | param_1[2] & 0xfffffffe;
  puVar2 = (uint *)(param_1[2] & 0xfffffffe);
  if (param_1 == (uint *)*puVar2) {
    *puVar2 = uVar1;
  }
  else {
    puVar2[1] = uVar1;
  }
  *(uint **)(uVar1 + 4) = param_1;
  param_1[2] = param_1[2] & 1 | uVar1;
  return;
}


