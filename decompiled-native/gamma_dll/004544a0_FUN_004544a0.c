// 004544a0 FUN_004544a0 [Global]
// programa: gamma.dll

uint * __cdecl FUN_004544a0(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = *param_1;
  bVar5 = (uVar1 & 2) == 0;
  puVar3 = (uint *)((int)param_1 + param_2);
  uVar2 = param_1[1];
  uVar4 = (uint)!bVar5;
  FUN_00454460(param_1,param_2,uVar2 & 0xfffffffe,uVar1 & 4,uVar4);
  FUN_00454460(puVar3,(uVar1 & 0xfffffff8) - param_2,uVar2 & 0xfffffffe,uVar4,uVar4);
  if (bVar5) {
    puVar3[3] = param_1[3];
    *(uint **)(puVar3[3] + 8) = puVar3;
    puVar3[2] = (uint)param_1;
    param_1[3] = (uint)puVar3;
  }
  return puVar3;
}


