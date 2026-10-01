// 004049e0 FUN_004049e0 [Global]
// program: gamma.dll

void __thiscall FUN_004049e0(void *this,undefined4 *param_1)

{
  int *piVar1;
  
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = param_1[1];
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  return;
}


