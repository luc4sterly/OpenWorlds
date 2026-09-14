// 004456a0 FUN_004456a0 [Global]
// programa: gamma.dll

undefined4 * __thiscall
FUN_004456a0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00444a90(this,param_1,param_2,param_3,param_4,param_5,0);
  *(undefined **)((int)this + 0x94) = &DAT_00477514;
  *(undefined **)((int)this + 0x94) = &DAT_00479cb0;
  *(undefined ***)this = &PTR_LAB_00479b6c;
  *(undefined ***)((int)this + 0xc) = &PTR_LAB_00479b84;
  *(undefined ***)((int)this + 0x10) = &PTR_LAB_00479bd4;
  *(undefined ***)((int)this + 0x94) = &PTR_LAB_00479c60;
  *(undefined4 *)((int)this + 0x98) = 0;
  *(undefined1 *)((int)this + 0x9c) = 0;
  *(undefined1 *)((int)this + 0x9d) = 0;
  puVar2 = (undefined4 *)((int)this + 0xa0);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return this;
}


