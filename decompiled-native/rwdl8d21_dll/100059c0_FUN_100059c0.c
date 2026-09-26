// 100059c0 FUN_100059c0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_100059c0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool local_20;
  uint local_c;
  uint local_8;
  
  uVar1 = *(int *)(param_2 + 0x1c) - *(int *)(param_1 + 0x1c);
  uVar2 = *(int *)(param_2 + 0x20) - *(int *)(param_1 + 0x20);
  uVar3 = *(int *)(param_3 + 0x1c) - *(int *)(param_2 + 0x1c);
  uVar4 = *(int *)(param_3 + 0x20) - *(int *)(param_2 + 0x20);
  if ((uVar3 == 0) || (uVar2 == 0)) {
    local_c = 0;
  }
  else {
    local_c = uVar3 ^ uVar2;
  }
  if ((uVar1 == 0) || (uVar4 == 0)) {
    local_8 = 0;
  }
  else {
    local_8 = uVar4 ^ uVar1;
  }
  if ((int)(local_8 ^ local_c) < 0) {
    if ((int)local_c < 0) {
      local_20 = false;
    }
    else {
      local_20 = true;
    }
  }
  else {
    local_20 = _DAT_10074008 <=
               (double)(int)uVar2 * (double)(int)uVar3 - (double)(int)uVar1 * (double)(int)uVar4;
  }
  return local_20;
}


