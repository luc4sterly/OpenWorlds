// 10032a30 FUN_10032a30 [Global]
// programa: RWL21.DLL

undefined4 FUN_10032a30(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if ((*(uint *)(param_2 + 0x188) & 4) == 0) {
    uVar4 = (*(uint *)(param_2 + 0x188) & 2) >> 1;
  }
  else {
    uVar4 = 2;
  }
  uVar3 = 2;
  uVar1 = *(uint *)(param_1 + 0x188);
  if ((uVar1 & 4) == 0) {
    uVar3 = (uVar1 & 2) >> 1;
  }
  if (uVar4 != uVar3) {
    if ((uVar1 & 4) == 0) {
      uVar4 = (uVar1 & 2) >> 1;
    }
    else {
      uVar4 = 2;
    }
    if (uVar4 == 1) {
      if (*(int *)(param_1 + 0xac) == 0) {
        *(undefined4 *)(param_1 + 0xac) = 0;
      }
      else {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(*(int *)(param_1 + 0xac));
      }
      if (*(int *)(param_1 + 0xa8) == 0) {
        *(undefined4 *)(param_1 + 0xa8) = 0;
      }
      else {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(*(int *)(param_1 + 0xa8));
      }
    }
    uVar4 = *(uint *)(param_2 + 0x188);
    *(uint *)(param_1 + 0x188) =
         (uVar4 ^ *(uint *)(param_1 + 0x188)) & 6 ^ *(uint *)(param_1 + 0x188);
    if ((uVar4 & 4) == 0) {
      uVar4 = (uVar4 & 2) >> 1;
    }
    else {
      uVar4 = 2;
    }
    if (uVar4 == 1) {
      *(undefined4 *)(param_1 + 0xac) = 0;
      *(undefined4 *)(param_1 + 0xa8) = 0;
    }
  }
  iVar2 = *(int *)(param_2 + 0xa0);
  *(int *)(param_1 + 0xa0) = iVar2;
  if (iVar2 == 0) {
    if ((*(uint *)(param_1 + 0x188) & 4) == 0) {
      uVar4 = (*(uint *)(param_1 + 0x188) & 2) >> 1;
    }
    else {
      uVar4 = 2;
    }
    if (uVar4 == 1) {
      FUN_10033750();
    }
  }
  return 1;
}


