// 004308e0 FUN_004308e0 [Global]
// programa: gamma.dll

int __thiscall FUN_004308e0(void *this,int param_1)

{
  if (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0) {
    FUN_0042f340(*(undefined4 **)((int)this + 4));
  }
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  if (*(int *)((int)this + 4) != 0) {
    FUN_0042f330(*(int *)((int)this + 4));
  }
  return (int)this;
}


