// 0044ff10 FUN_0044ff10 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0044ff10(void *this,undefined4 param_1)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  int local_60 [2];
  undefined1 local_55;
  int *local_c;
  
  *(undefined ***)this = &PTR_LAB_00480fec;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  local_c = (int *)((int)this + 0x1c);
  FUN_004049e0(local_c,&DAT_0049ed10);
  if (*local_c == 0) {
    piVar2 = (int *)FUN_004517c0();
    FUN_00411b30(local_c,piVar2);
  }
  *(undefined ***)this = &PTR_LAB_00481028;
  *(undefined4 *)((int)this + 0x24) = param_1;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined1 *)((int)this + 0x50) = 0;
  *(undefined1 *)((int)this + 0x52) = 1;
  FUN_0044f3d0(this,local_60);
  local_55 = DAT_0049e41b;
  iVar3 = FUN_004501b0(local_60);
  *(int *)((int)this + 0x2c) = iVar3;
  FUN_00404dc0(local_60);
  uVar1 = (**(code **)(**(int **)((int)this + 0x2c) + 0x14))();
  *(undefined1 *)((int)this + 0x51) = uVar1;
  return this;
}


