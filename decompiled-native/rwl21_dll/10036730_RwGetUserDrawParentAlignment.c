// 10036730 RwGetUserDrawParentAlignment [Global]
// programa: RWL21.DLL

undefined4 RwGetUserDrawParentAlignment(int param_1)

{
                    /* 0x36730  268  RwGetUserDrawParentAlignment */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((*(int *)(param_1 + 0x28) != 3) && (*(int *)(param_1 + 0x28) != 4)) {
    FUN_1000cba0(0x33);
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x30);
}


