// 00410b20 FUN_00410b20 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00410b20(void *this,uint param_1)

{
  undefined *puVar1;
  
  if (this != (void *)0x0) {
    if ((param_1 & 2) == 0) {
      *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (0x50 - *(int *)((int)this + 4));
      *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (0x50 - *(int *)((int)this + 4));
      *(undefined ***)this = &PTR_FUN_0046f3e8;
      **(undefined4 **)((int)this + 4) = &PTR_LAB_0046f3f4;
      *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (0x50 - *(int *)((int)this + 4));
      *(undefined ***)((int)this + 0xc) = &PTR_LAB_0046f3ac;
      puVar1 = *(undefined **)((int)this + 0x30);
      if (((puVar1 != &DAT_00482468) && (puVar1 != &DAT_004824bc)) && (puVar1 != &DAT_00482510)) {
        FUN_004118d0((int *)((int)this + 0xc));
      }
      *(undefined ***)((int)this + 0xc) = &PTR_LAB_0046f370;
      FUN_00404dc0((undefined4 *)((int)this + 0x28));
      *(undefined ***)this = &PTR_LAB_0046f358;
      **(undefined4 **)((int)this + 4) = &PTR_LAB_0046f364;
      *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (0xc - *(int *)((int)this + 4));
      *(undefined ***)((int)this + 0x50) = &PTR_LAB_0046f34c;
      FUN_00454d40((undefined4 *)((int)this + 0x50));
      if ((param_1 & 1) != 0) {
        FUN_0044e100(this);
      }
    }
    else {
      FUN_00451710((int)this,&LAB_00410780);
    }
  }
  return this;
}


