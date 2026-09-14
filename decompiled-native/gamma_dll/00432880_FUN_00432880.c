// 00432880 FUN_00432880 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00432880(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  *(undefined4 *)this = 0;
  FUN_00434420((int)this + 4);
  *(bool *)((int)this + 5) = param_2 != 0;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00474bac;
  *(undefined4 *)((int)this + 8) = &PTR_LAB_00475468;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = &PTR_LAB_00474bac;
  *(undefined4 *)((int)this + 0x10) = &PTR_LAB_00475468;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0xffffffff;
  *(undefined4 *)((int)this + 0x34) = 1;
  *(undefined4 *)((int)this + 0x38) = 0;
  if (param_1 != 0) {
    puVar2 = FUN_0044e010(0x128);
    if (puVar2 != (uint *)0x0) {
      FUN_00431c80(puVar2);
    }
    *(uint **)this = puVar2;
    FUN_00433420((int)this);
    return this;
  }
                    /* WARNING: Could not recover jumptable at 0x0043293a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = (undefined4 *)(*_DAT_0047542c)();
  return puVar1;
}


