// 00454380 FUN_00454380 [Global]
// program: gamma.dll

void __cdecl FUN_00454380(int param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  uVar1 = *param_2;
  *param_2 = *param_2 & 0xfffffffd;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + (int)param_2);
  *puVar3 = *puVar3 & 0xfffffffb;
  puVar3[-1] = uVar1 & 0xfffffff8;
  puVar3 = (uint *)((*(uint *)(param_1 + 0xc) & 0xfffffff8) + param_1 + -4);
  if (*puVar3 == 0) {
    *puVar3 = (uint)param_2;
    param_2[2] = (uint)param_2;
    param_2[3] = (uint)param_2;
  }
  else {
    param_2[2] = *(uint *)(*puVar3 + 8);
    *(uint **)(param_2[2] + 0xc) = param_2;
    param_2[3] = *puVar3;
    *(uint **)(*puVar3 + 8) = param_2;
    *puVar3 = (uint)param_2;
    puVar2 = FUN_00454530((uint *)*puVar3,puVar3);
    *puVar3 = (uint)puVar2;
    FUN_004545b0((uint *)*puVar3,puVar3);
  }
  if (*(uint *)(param_1 + 8) < (*(uint *)*puVar3 & 0xfffffff8)) {
    *(uint *)(param_1 + 8) = *(uint *)*puVar3 & 0xfffffff8;
  }
  return;
}


