// 10032550 FUN_10032550 [Global]
// program: RWL21.DLL

undefined4 FUN_10032550(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((param_2 < -7) || (*(int *)(*(int *)(param_1 + 0x88) + 8) + -7 <= param_2)) {
    FUN_1000cba0(0x19);
    return 0;
  }
  if ((*(uint *)(param_1 + 0xbc) & 0x3f00) != 0) {
    return 0;
  }
  iVar1 = FUN_10041c90(*(int *)(param_1 + 0x88),param_2);
  if (*(uint *)(param_1 + 0xbc) == 0) {
    if (param_3 != (int *)0x0) {
      *param_3 = *(int *)(iVar1 + 0x18) >> 0x10;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = *(int *)(iVar1 + 0x1c) >> 0x10;
    }
  }
  else {
    if (((*(uint *)(param_1 + 0xbc) & 0x30) != 0) &&
       ((*(float *)(iVar1 + 0x14) < *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x74) ||
        (*(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x78) <= *(float *)(iVar1 + 0x14))))) {
      return 0;
    }
    lVar2 = __ftol();
    lVar3 = __ftol();
    if (param_3 != (int *)0x0) {
      *param_3 = (int)lVar2 >> 0x10;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = (int)lVar3 >> 0x10;
      return 1;
    }
  }
  return 1;
}


