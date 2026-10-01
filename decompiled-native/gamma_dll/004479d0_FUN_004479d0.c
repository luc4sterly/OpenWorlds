// 004479d0 FUN_004479d0 [Global]
// program: gamma.dll

undefined4 * __thiscall
FUN_004479d0(void *this,undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  
  *(undefined **)this = &DAT_00477514;
  *(undefined **)this = &DAT_0047ac20;
  puVar1 = (undefined4 *)((int)this + 4);
  *puVar1 = &DAT_00477514;
  *puVar1 = &DAT_004774f0;
  *puVar1 = &DAT_0047ace8;
  FUN_004463e0((void *)((int)this + 8),param_1,param_2);
  *puVar1 = &PTR_LAB_0047ac78;
  *(undefined ***)((int)this + 8) = &PTR_LAB_0047acc8;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_0047ab20;
  *(undefined ***)((int)this + 4) = &PTR_LAB_0047ab78;
  *(undefined ***)((int)this + 8) = &PTR_LAB_0047abc8;
  *(int *)((int)this + 0x18) = param_4;
  if (param_4 == 0) {
    *param_3 = 0x80004003;
  }
  *(undefined ***)this = &PTR_LAB_0047aa20;
  *(undefined ***)((int)this + 4) = &PTR_LAB_0047aa78;
  *(undefined ***)((int)this + 8) = &PTR_LAB_0047aac8;
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 1;
  return this;
}


