// 004393f0 FUN_004393f0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_004393f0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)((int)this + 0xc);
  uVar2 = *(undefined4 *)((int)this + 0x10);
  uVar3 = *(undefined4 *)((int)this + 0x14);
  *param_1 = &PTR_LAB_004732e8;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  return param_1;
}


