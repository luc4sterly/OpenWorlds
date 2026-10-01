// 0044a1c0 FUN_0044a1c0 [Global]
// program: gamma.dll

int __thiscall FUN_0044a1c0(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = param_2 * 0x68db8bad;
  uVar5 = param_2 / 10000;
  if ((1000 < (int)uVar5) || ((int)uVar5 < -1000)) {
    if (*(int *)(param_1 + 0xfc) < 2) {
      uVar5 = 0;
    }
    else if ((int)uVar5 < 1) {
      uVar5 = 0xfffffc18;
    }
    else {
      uVar5 = 1000;
    }
  }
  if (1 < *(int *)(param_1 + 0xfc)) {
    puVar1 = (uint *)(param_1 + 0x100);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar5;
    *(int *)(param_1 + 0x104) =
         *(int *)(param_1 + 0x104) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar2,uVar5);
    uVar5 = uVar5 * uVar5;
    iVar3 = (int)uVar5 >> 0x1f;
    puVar1 = (uint *)(param_1 + 0x108);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar5;
    *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + iVar3 + (uint)CARRY4(uVar2,uVar5);
  }
  if (2 < *(int *)(param_1 + 0xfc)) {
    uVar5 = param_3 / 10000;
    if ((1000 < (int)uVar5) || ((int)uVar5 < 0)) {
      uVar5 = 1000;
    }
    uVar4 = uVar5 * uVar5;
    puVar1 = (uint *)(param_1 + 0x118);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar4;
    *(int *)(param_1 + 0x11c) =
         *(int *)(param_1 + 0x11c) + ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar2,uVar4);
    iVar3 = (int)uVar5 >> 0x1f;
    puVar1 = (uint *)(param_1 + 0x120);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar5;
    *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + iVar3 + (uint)CARRY4(uVar2,uVar5);
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  return iVar3;
}


