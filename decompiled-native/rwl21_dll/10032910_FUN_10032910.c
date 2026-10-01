// 10032910 FUN_10032910 [Global]
// program: RWL21.DLL

void FUN_10032910(int param_1)

{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 0x188) & 4) == 0) {
    uVar1 = (*(uint *)(param_1 + 0x188) & 2) >> 1;
  }
  else {
    uVar1 = 2;
  }
  if (uVar1 == 1) {
    if (*(int *)(param_1 + 0xac) == 0) {
      *(undefined4 *)(param_1 + 0xac) = 0;
    }
    else {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*(int *)(param_1 + 0xac));
    }
    if (*(int *)(param_1 + 0xa8) != 0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*(int *)(param_1 + 0xa8));
      return;
    }
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  return;
}


