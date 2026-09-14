// 00444a90 FUN_00444a90 [Global]
// programa: gamma.dll

undefined4 * __thiscall
FUN_00444a90(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004463e0(this,param_1,(undefined4 *)0x0);
  *(undefined **)((int)this + 0xc) = &DAT_00477514;
  *(undefined **)((int)this + 0xc) = &DAT_00479dec;
  *(undefined **)((int)this + 0x10) = &DAT_00477514;
  *(undefined **)((int)this + 0x10) = &DAT_00479dd0;
  *(undefined ***)this = &PTR_LAB_00479cdc;
  *(undefined ***)((int)this + 0xc) = &PTR_LAB_00479cf4;
  *(undefined ***)((int)this + 0x10) = &PTR_LAB_00479d44;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = param_6;
  *(undefined4 *)((int)this + 0x20) = param_3;
  *(undefined1 *)((int)this + 0x24) = 0;
  *(undefined1 *)((int)this + 0x25) = 0;
  *(undefined1 *)((int)this + 0x26) = 0;
  *(undefined4 *)((int)this + 0x28) = param_2;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 1;
  FUN_00448100((undefined4 *)((int)this + 0x34));
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x84) = 0xffffffff;
  *(undefined4 *)((int)this + 0x88) = 0x7fffffff;
  *(undefined4 *)((int)this + 0x90) = 0x3ff00000;
  *(undefined4 *)((int)this + 0x8c) = 0;
  if (param_5 != (undefined4 *)0x0) {
    iVar1 = FUN_0044b350((int)param_5);
    uVar2 = FUN_00450b60((iVar1 + 1) * 2);
    *(undefined4 *)((int)this + 0x14) = uVar2;
    if (*(undefined4 **)((int)this + 0x14) != (undefined4 *)0x0) {
      FUN_0044df50(*(undefined4 **)((int)this + 0x14),param_5,(iVar1 + 1) * 2);
    }
  }
  return this;
}


