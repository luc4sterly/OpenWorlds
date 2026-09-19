// 10033600 FUN_10033600 [Global]
// programa: RWL21.DLL

uint FUN_10033600(int param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 2;
  if ((param_2 & 4) == 0) {
    uVar2 = (param_2 & 2) >> 1;
  }
  if ((uVar2 == 1) && (1000 < **(int **)(param_1 + 0x98))) {
    param_2 = param_2 | 4;
  }
  uVar2 = *(uint *)(param_1 + 0x188);
  uVar4 = 2;
  if ((uVar2 & 4) == 0) {
    uVar4 = (uVar2 & 2) >> 1;
  }
  uVar3 = 2;
  if ((param_2 & 4) == 0) {
    uVar3 = (param_2 & 2) >> 1;
  }
  if (uVar4 == uVar3) {
    return param_2;
  }
  if ((uVar2 & 4) == 0) {
    uVar2 = (uVar2 & 2) >> 1;
  }
  else {
    uVar2 = 2;
  }
  if (uVar2 == 1) {
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
  uVar4 = (param_2 ^ *(uint *)(param_1 + 0x188)) & 6 ^ *(uint *)(param_1 + 0x188);
  uVar2 = 2;
  *(uint *)(param_1 + 0x188) = uVar4;
  if ((param_2 & 4) == 0) {
    uVar2 = (param_2 & 2) >> 1;
  }
  if (uVar2 != 0) {
    if (uVar2 == 1) {
      *(undefined4 *)(param_1 + 0xac) = 0;
      *(undefined4 *)(param_1 + 0xa8) = 0;
    }
    else if (uVar2 != 2) {
      bVar1 = false;
      goto LAB_10033713;
    }
  }
  bVar1 = true;
LAB_10033713:
  if ((bVar1) && (*(int *)(param_1 + 0xa0) == 0)) {
    if ((uVar4 & 4) == 0) {
      uVar2 = (uVar4 & 2) >> 1;
    }
    else {
      uVar2 = 2;
    }
    if (uVar2 == 1) {
      FUN_10033750();
    }
  }
  return param_2;
}


