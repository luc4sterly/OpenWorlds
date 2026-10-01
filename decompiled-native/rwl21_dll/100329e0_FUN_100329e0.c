// 100329e0 FUN_100329e0 [Global]
// program: RWL21.DLL

undefined4 FUN_100329e0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0xa0) == 0) {
    if ((*(uint *)(param_1 + 0x188) & 4) == 0) {
      uVar2 = (*(uint *)(param_1 + 0x188) & 2) >> 1;
    }
    else {
      uVar2 = 2;
    }
    if (uVar2 == 1) {
      iVar1 = FUN_10033750();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}


