// 00423f00 FUN_00423f00 [Global]
// programa: gamma.dll

/* WARNING: Removing unreachable block (ram,0x00423f40) */

int __thiscall FUN_00423f00(int param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_38 [4];
  int iStack_34;
  undefined1 *puStack_18;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  puStack_18 = auStack_38;
  if ((*(byte *)(param_1 + 0x24) & 0x10) == 0) {
    return -1;
  }
  if (param_2 == -1) {
    return 0;
  }
  puVar1 = *(undefined1 **)(param_1 + 0x14);
  uStack_12 = (undefined1)param_2;
  if (puVar1 < *(undefined1 **)(param_1 + 0x18)) {
    *puVar1 = uStack_12;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    return param_2;
  }
  if (*(uint *)(param_1 + 0x28) <= *(uint *)(param_1 + 0x2c)) {
    iStack_34 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    iVar2 = *(int *)(param_1 + 0x10);
    uStack_11 = uStack_12;
    FUN_00424410((void *)(param_1 + 0x28),*(int *)(param_1 + 0x2c) + 1,&uStack_11);
    iVar3 = *(int *)(param_1 + 0x30);
    if ((*(byte *)(param_1 + 0x24) & 8) != 0) {
      *(int *)(param_1 + 4) = iVar3;
      *(int *)(param_1 + 8) = iVar3 + iStack_34;
      *(int *)(param_1 + 0xc) = iVar3 + *(int *)(param_1 + 0x2c);
    }
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x14);
    *(int *)(param_1 + 0x18) = iVar3 + *(int *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x14) = (int)(puVar1 + *(int *)(param_1 + 0x14) + (1 - iVar2));
    return param_2;
  }
  FUN_00424410((void *)(param_1 + 0x28),*(int *)(param_1 + 0x2c) + 1,&uStack_12);
  if ((*(byte *)(param_1 + 0x24) & 8) != 0) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 8);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x14);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  *(int *)(param_1 + 0x14) =
       *(int *)(param_1 + 0x14) + (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x10));
  return param_2;
}


