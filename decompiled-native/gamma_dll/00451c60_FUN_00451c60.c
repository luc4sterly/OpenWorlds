// 00451c60 FUN_00451c60 [Global]
// program: gamma.dll

void __thiscall FUN_00451c60(void *this,undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  *(undefined ***)this = &PTR_LAB_0046d714;
  *(undefined4 *)((int)this + 4) = param_3;
  *(undefined ***)this = &PTR_LAB_00482348;
  *(undefined4 *)((int)this + 8) = param_1;
  *(undefined1 *)((int)this + 0xc) = param_2;
  if (*(int *)((int)this + 8) == 0) {
    *(undefined **)((int)this + 8) = &DAT_00481378;
    *(undefined1 *)((int)this + 0xc) = 0;
  }
  return;
}


