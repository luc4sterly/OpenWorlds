// 0042af40 FUN_0042af40 [Global]
// program: gamma.dll

void __thiscall FUN_0042af40(void *this,int param_1)

{
  if (param_1 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  **(undefined1 **)(param_1 + 4) = 0;
  *(undefined1 *)(*(int *)(param_1 + 4) + 1) = 0;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (param_1 == *(int *)((int)this + 0x28)) {
    *(undefined4 *)((int)this + 0x30) = *(undefined4 *)(*(int *)((int)this + 0x28) + 0x10);
    *(undefined4 *)((int)this + 0x34) = *(undefined4 *)(*(int *)((int)this + 0x28) + 8);
    *(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 0x34);
    *(undefined4 *)((int)this + 0x20) = **(undefined4 **)((int)this + 0x28);
    *(undefined1 *)((int)this + 0x2c) = **(undefined1 **)((int)this + 0x34);
  }
  return;
}


