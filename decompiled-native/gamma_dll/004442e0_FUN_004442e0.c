// 004442e0 FUN_004442e0 [Global]
// programa: gamma.dll

undefined4 FUN_004442e0(int param_1,int *param_2)

{
  int iVar1;
  uint *this;
  undefined4 uStack_14;
  
  if (param_2 != (int *)0x0) {
    uStack_14 = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0xb0))();
    if (*(int *)(param_1 + 0x10) == iVar1) {
      this = FUN_0044e010(0x30);
      if (this != (uint *)0x0) {
        FUN_00444020(this,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = (int)this;
      if (*param_2 == 0) {
        uStack_14 = 0x8007000e;
      }
    }
    else {
      *param_2 = 0;
      uStack_14 = 0x80040203;
    }
    return uStack_14;
  }
  return 0x80004003;
}


