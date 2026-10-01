// 00454530 FUN_00454530 [Global]
// program: gamma.dll

uint * __cdecl FUN_00454530(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  if ((*param_1 & 4) != 0) {
    return param_1;
  }
  uVar1 = param_1[-1];
  if ((uVar1 & 2) != 0) {
    return param_1;
  }
  puVar2 = (uint *)((int)param_1 - uVar1);
  *puVar2 = *puVar2 & 7;
  *puVar2 = *puVar2 | (*param_1 & 0xfffffff8) + uVar1 & 0xfffffff8;
  if ((*puVar2 & 2) == 0) {
    iVar3 = (*param_1 & 0xfffffff8) + uVar1;
    *(int *)(iVar3 + -4 + (int)puVar2) = iVar3;
  }
  if ((uint *)*param_2 == param_1) {
    *param_2 = ((uint *)*param_2)[3];
  }
  *(uint *)(param_1[3] + 8) = param_1[2];
  *(uint *)(*(int *)(param_1[3] + 8) + 0xc) = param_1[3];
  return puVar2;
}


