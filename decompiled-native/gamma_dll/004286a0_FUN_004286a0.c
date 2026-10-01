// 004286a0 FUN_004286a0 [Global]
// program: gamma.dll

void __thiscall FUN_004286a0(void *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined ***)this = &PTR_LAB_0047339c;
  uVar1 = *(undefined4 *)(param_4 + 4);
  uVar2 = *(undefined4 *)(param_3 + 4);
  uVar3 = *(undefined4 *)(param_2 + 4);
  uVar4 = *(undefined4 *)(param_1 + 4);
  *(undefined ***)((int)this + 4) = &PTR_LAB_004733a8;
  *(undefined4 *)((int)this + 8) = uVar4;
  *(undefined4 *)((int)this + 0xc) = uVar3;
  *(undefined4 *)((int)this + 0x10) = uVar2;
  *(undefined4 *)((int)this + 0x14) = uVar1;
  uVar1 = *(undefined4 *)(param_4 + 8);
  uVar2 = *(undefined4 *)(param_3 + 8);
  uVar3 = *(undefined4 *)(param_2 + 8);
  uVar4 = *(undefined4 *)(param_1 + 8);
  *(undefined ***)((int)this + 0x18) = &PTR_LAB_004733a8;
  *(undefined4 *)((int)this + 0x1c) = uVar4;
  *(undefined4 *)((int)this + 0x20) = uVar3;
  *(undefined4 *)((int)this + 0x24) = uVar2;
  *(undefined4 *)((int)this + 0x28) = uVar1;
  uVar1 = *(undefined4 *)(param_4 + 0xc);
  uVar2 = *(undefined4 *)(param_3 + 0xc);
  uVar3 = *(undefined4 *)(param_2 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0xc);
  *(undefined ***)((int)this + 0x2c) = &PTR_LAB_004733a8;
  *(undefined4 *)((int)this + 0x30) = uVar4;
  *(undefined4 *)((int)this + 0x34) = uVar3;
  *(undefined4 *)((int)this + 0x38) = uVar2;
  *(undefined4 *)((int)this + 0x3c) = uVar1;
  return;
}


