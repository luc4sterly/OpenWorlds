// 004463e0 FUN_004463e0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004463e0(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  *(undefined **)this = &DAT_0047a2e4;
  InterlockedIncrement((LONG *)&DAT_004a042c);
  *(undefined ***)this = &PTR_FUN_0047a004;
  puVar1 = this;
  if (param_2 != (undefined4 *)0x0) {
    puVar1 = param_2;
  }
  *(undefined4 **)((int)this + 4) = puVar1;
  *(undefined4 *)((int)this + 8) = 0;
  return this;
}


