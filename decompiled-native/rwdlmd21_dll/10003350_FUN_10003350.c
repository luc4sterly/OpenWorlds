// 10003350 FUN_10003350 [Global]
// programa: rwdlmd21.dll

void FUN_10003350(int param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_4;
  
  iVar5 = *param_2;
  if (DAT_10087064 == 0x10) {
    iVar5 = iVar5 * 2;
  }
  iVar3 = param_2[2];
  uVar1 = *(int *)(DAT_10087240 + param_2[1] * 4) + iVar5;
  if (DAT_10087064 == 0x10) {
    iVar3 = iVar3 * 2;
  }
  uVar2 = uVar1 & 3;
  uVar4 = iVar3 + uVar2;
  local_4 = uVar1 - uVar2;
  if (DAT_10087064 == 8) {
    uVar1 = *(uint *)(param_1 + 0x9c) & 0xff;
    uVar1 = uVar1 | uVar1 << 8;
    FUN_1006ab60(&local_4,uVar4,param_2[3],uVar1 | uVar1 << 0x10);
    return;
  }
  FUN_1006abd4(&local_4,uVar4,param_2[3],
               *(uint *)(param_1 + 0x98) & 0xffff | *(uint *)(param_1 + 0x98) << 0x10);
  return;
}


