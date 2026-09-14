// 00429010 FUN_00429010 [Global]
// programa: gamma.dll

void __thiscall FUN_00429010(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)((int)this + 8);
  uVar2 = *(undefined4 *)((int)this + 0xc);
  uVar3 = *(undefined4 *)((int)this + 0x10);
  *param_1 = &PTR_LAB_004732e8;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  return;
}


