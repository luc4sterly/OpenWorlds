// 004542f0 FUN_004542f0 [Global]
// program: gamma.dll

uint * __cdecl FUN_004542f0(int param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = *(uint **)((*(uint *)(param_1 + 0xc) & 0xfffffff8) + param_1 + -4);
  if (puVar1 == (uint *)0x0) {
    return (uint *)0x0;
  }
  uVar3 = *puVar1 & 0xfffffff8;
  puVar2 = puVar1;
  uVar4 = uVar3;
  do {
    if (param_2 <= uVar3) {
      if (0x4f < uVar3 - param_2) {
        FUN_004544a0(puVar2,param_2);
      }
      *(uint *)((*(uint *)(param_1 + 0xc) & 0xfffffff8) + param_1 + -4) = puVar2[3];
      FUN_00454400(param_1,puVar2);
      return puVar2;
    }
    puVar2 = (uint *)puVar2[3];
    uVar3 = *puVar2 & 0xfffffff8;
    if (uVar4 < uVar3) {
      uVar4 = uVar3;
    }
  } while (puVar2 != puVar1);
  *(uint *)(param_1 + 8) = uVar4;
  return (uint *)0x0;
}


