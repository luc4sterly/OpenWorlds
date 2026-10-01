// 1002bfe0 FUN_1002bfe0 [Global]
// program: RWL21.DLL

void FUN_1002bfe0(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar1 = *(uint **)(param_1 + 0xb8);
  if ((*puVar1 & 8) == 0) {
    FUN_1002bbd0(puVar1);
  }
  else {
    if (puVar1 == (uint *)0x0) {
      FUN_1000cba0(0x65);
      return;
    }
    uVar2 = puVar1[6];
    if (uVar2 == 0) {
      FUN_1000cba0(0x65);
      return;
    }
    puVar3 = *(uint **)(uVar2 + 8);
    puVar6 = puVar3;
    puVar5 = puVar3;
    while ((puVar4 = puVar6, puVar4 != (uint *)0x0 && (puVar4 != puVar1))) {
      puVar5 = puVar4;
      puVar6 = (uint *)puVar4[4];
    }
    if (puVar4 != (uint *)0x0) {
      if (puVar4 == puVar3) {
        *(uint *)(uVar2 + 8) = puVar4[4];
      }
      else {
        puVar5[4] = puVar4[4];
      }
      *(uint **)(*(int *)(uVar2 + 0xc) + *(int *)(uVar2 + 0x1c) * 4) = puVar1;
      *(int *)(uVar2 + 0x1c) = *(int *)(uVar2 + 0x1c) + 1;
      *puVar1 = *puVar1 & 0xfffffffe;
      return;
    }
  }
  return;
}


