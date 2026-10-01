// 10005e30 FUN_10005e30 [Global]
// program: RWDLDD21.DLL

void FUN_10005e30(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10c) != 0) {
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x2c) + 0x34);
    if (iVar1 - DAT_1003a024 == -0xc) {
      DAT_1003a024 = 0;
    }
    FUN_10005340(iVar1);
    iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x2c);
    if (iVar1 != 0) {
      (**(code **)(DAT_100394fc + 0x358))(iVar1);
      *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x2c) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x2c) = 0;
    }
  }
  return;
}


