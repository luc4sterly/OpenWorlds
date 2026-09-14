// 0042f1d0 FUN_0042f1d0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0042f1d0(void *this,undefined4 *param_1)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  
  if (this != param_1) {
    FUN_0042f260(this);
    if ((int *)param_1[1] != (int *)0x0) {
      puVar2 = FUN_0042c470((int *)param_1[1]);
      *(uint **)((int)this + 4) = puVar2;
      puVar2 = (uint *)(*(int *)((int)this + 4) + 8);
      *puVar2 = *puVar2 & 1 | (int)this + 4U;
    }
    *(undefined4 *)this = *param_1;
    *(undefined4 *)((int)this + 0xc) = param_1[3];
    if (*(int **)((int)this + 4) == (int *)0x0) {
      *(int *)((int)this + 0xc) = (int)this + 4;
    }
    else {
      piVar1 = *(int **)((int)this + 4);
      do {
        piVar3 = piVar1;
        piVar1 = (int *)*piVar3;
      } while (piVar1 != (int *)0x0);
      *(int **)((int)this + 0xc) = piVar3;
    }
    return this;
  }
  return this;
}


