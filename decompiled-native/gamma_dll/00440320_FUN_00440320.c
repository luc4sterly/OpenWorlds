// 00440320 FUN_00440320 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00440320(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined ***)this = &PTR_LAB_00477d54;
  *(undefined ***)this = &PTR_LAB_00478af4;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x34) = *(undefined4 *)((int)this + 0x38);
  puVar2 = (undefined4 *)((int)this + 0xc);
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x3c) = param_1;
  return this;
}


