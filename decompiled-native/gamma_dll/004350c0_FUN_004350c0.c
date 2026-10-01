// 004350c0 FUN_004350c0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004350c0(void *this,int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = FUN_0044e010(0x3c);
  if (puVar1 != (uint *)0x0) {
    FUN_00432880(puVar1,param_1,param_2);
  }
  *(uint **)this = puVar1;
  puVar1 = FUN_0044e010(0x38);
  if (puVar1 != (uint *)0x0) {
    *puVar1 = (uint)&PTR_LAB_00473390;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    FUN_00428f10(puVar1 + 4);
    FUN_004279e0(puVar1 + 9);
    puVar1[0xb] = 1;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
  }
  *(uint **)((int)this + 4) = puVar1;
  return this;
}


