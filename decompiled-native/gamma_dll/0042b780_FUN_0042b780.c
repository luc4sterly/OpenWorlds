// 0042b780 FUN_0042b780 [Global]
// program: gamma.dll

void __cdecl FUN_0042b780(uint *param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  
  param_1[2] = param_1[2] | 1;
  while ((param_1 != param_2 && (puVar2 = (uint *)(param_1[2] & 0xfffffffe), (puVar2[2] & 1) != 0)))
  {
    piVar4 = (int *)(puVar2[2] & 0xfffffffe);
    if (puVar2 == (uint *)*piVar4) {
      iVar1 = piVar4[1];
      if ((iVar1 == 0) || ((*(uint *)(iVar1 + 8) & 1) == 0)) {
        if (param_1 == (uint *)puVar2[1]) {
          FUN_0042b990((uint)puVar2,(uint *)&param_2);
          param_1 = puVar2;
        }
        *(uint *)((param_1[2] & 0xfffffffe) + 8) =
             *(uint *)((param_1[2] & 0xfffffffe) + 8) & 0xfffffffe;
        uVar3 = *(uint *)((param_1[2] & 0xfffffffe) + 8) & 0xfffffffe;
        *(uint *)(uVar3 + 8) = *(uint *)(uVar3 + 8) | 1;
        FUN_0042b930((uint *)(*(uint *)((param_1[2] & 0xfffffffe) + 8) & 0xfffffffe),
                     (uint *)&param_2);
      }
      else {
        puVar2[2] = puVar2[2] & 0xfffffffe;
        *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xfffffffe;
        param_1 = (uint *)(*(uint *)((param_1[2] & 0xfffffffe) + 8) & 0xfffffffe);
        param_1[2] = param_1[2] | 1;
      }
    }
    else {
      iVar1 = *piVar4;
      if ((iVar1 == 0) || ((*(uint *)(iVar1 + 8) & 1) == 0)) {
        if (param_1 == (uint *)*puVar2) {
          FUN_0042b930(puVar2,(uint *)&param_2);
          param_1 = puVar2;
        }
        *(uint *)((param_1[2] & 0xfffffffe) + 8) =
             *(uint *)((param_1[2] & 0xfffffffe) + 8) & 0xfffffffe;
        uVar3 = *(uint *)((param_1[2] & 0xfffffffe) + 8) & 0xfffffffe;
        *(uint *)(uVar3 + 8) = *(uint *)(uVar3 + 8) | 1;
        FUN_0042b990(*(uint *)((param_1[2] & 0xfffffffe) + 8) & 0xfffffffe,(uint *)&param_2);
      }
      else {
        puVar2[2] = puVar2[2] & 0xfffffffe;
        *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xfffffffe;
        param_1 = (uint *)(*(uint *)((param_1[2] & 0xfffffffe) + 8) & 0xfffffffe);
        param_1[2] = param_1[2] | 1;
      }
    }
  }
  param_2[2] = param_2[2] & 0xfffffffe;
  return;
}


