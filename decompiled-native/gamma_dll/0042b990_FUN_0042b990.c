// 0042b990 FUN_0042b990 [Global]
// program: gamma.dll

void __cdecl FUN_0042b990(uint param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = *(uint **)(param_1 + 4);
  if (*param_2 == param_1) {
    *param_2 = (uint)puVar1;
  }
  *(uint *)(param_1 + 4) = *puVar1;
  if (*puVar1 != 0) {
    puVar2 = (uint *)(*puVar1 + 8);
    *puVar2 = *puVar2 & 1 | param_1;
  }
  puVar1[2] = puVar1[2] & 1 | *(uint *)(param_1 + 8) & 0xfffffffe;
  puVar2 = (uint *)(*(uint *)(param_1 + 8) & 0xfffffffe);
  if (param_1 == *puVar2) {
    *puVar2 = (uint)puVar1;
  }
  else {
    puVar2[1] = (uint)puVar1;
  }
  *puVar1 = param_1;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 1 | (uint)puVar1;
  return;
}


