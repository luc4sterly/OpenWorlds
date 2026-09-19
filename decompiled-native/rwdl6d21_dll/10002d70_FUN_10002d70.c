// 10002d70 FUN_10002d70 [Global]
// programa: RWDL6D21.DLL

void FUN_10002d70(int param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_4;
  
  iVar5 = *param_2;
  if (DAT_10079064 == 0x10) {
    iVar5 = iVar5 * 2;
  }
  iVar3 = param_2[2];
  uVar1 = *(int *)(DAT_10079218 + param_2[1] * 4) + iVar5;
  if (DAT_10079064 == 0x10) {
    iVar3 = iVar3 * 2;
  }
  uVar2 = uVar1 & 3;
  uVar4 = iVar3 + uVar2;
  local_4 = uVar1 - uVar2;
  if (DAT_10079064 == 8) {
    uVar1 = *(uint *)(param_1 + 0x9c) & 0xff;
    uVar1 = uVar1 | uVar1 << 8;
    FUN_10069b60(&local_4,uVar4,param_2[3],uVar1 | uVar1 << 0x10);
    return;
  }
  FUN_10069bd4(&local_4,uVar4,param_2[3],
               *(uint *)(param_1 + 0x98) & 0xffff | *(uint *)(param_1 + 0x98) << 0x10);
  return;
}


