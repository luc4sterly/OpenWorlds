// 0040441e FUN_0040441e [Global]
// program: gdkup.exe

uint * FUN_0040441e(void)

{
  uint uVar1;
  uint in_EAX;
  uint uVar2;
  int unaff_EBX;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  if (((in_EAX != 0) && (in_EAX < 0xfffffff5)) &&
     (uVar2 = in_EAX + 0xb & 0xfffffff8, uVar2 = (uVar2 - 0x10 & -(uint)(0xf < uVar2)) + 0x10,
     uVar2 <= *(uint *)(unaff_EBX + 0x14))) {
    puVar3 = *(uint **)(unaff_EBX + 0xc);
    uVar4 = *(uint *)(unaff_EBX + 0x10);
    if (uVar2 <= uVar4) {
      puVar3 = *(uint **)(unaff_EBX + 0x28);
      uVar4 = 0;
    }
    do {
      uVar1 = *puVar3;
      if (uVar2 <= uVar1) {
        *(uint *)(unaff_EBX + 0x10) = uVar4;
        *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x18) + 1;
        uVar4 = puVar3[2];
        if (uVar1 - uVar2 < 0x10) {
          *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + -1;
          uVar2 = puVar3[1];
          *(uint *)(uVar2 + 8) = uVar4;
          *(uint *)(uVar4 + 4) = uVar2;
          *(uint *)(unaff_EBX + 0xc) = uVar2;
        }
        else {
          puVar5 = (uint *)((int)puVar3 + uVar2);
          *(uint **)(unaff_EBX + 0xc) = puVar5;
          *puVar5 = uVar1 - uVar2;
          *puVar3 = uVar2;
          uVar2 = puVar3[1];
          puVar5[1] = uVar2;
          puVar5[2] = uVar4;
          *(uint **)(uVar2 + 8) = puVar5;
          *(uint **)(uVar4 + 4) = puVar5;
        }
        *puVar3 = *puVar3 | 1;
        return puVar3 + 1;
      }
      uVar4 = (uVar4 - uVar1 & -(uint)(uVar1 <= uVar4)) + uVar1;
      puVar3 = (uint *)puVar3[2];
    } while (puVar3 != (uint *)(unaff_EBX + 0x20U));
    *(uint *)(unaff_EBX + 0x14) = uVar4;
  }
  return (uint *)0x0;
}


