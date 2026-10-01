// 004240f0 FUN_004240f0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004240f0(void *this,int *param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *this_00;
  int *piVar4;
  
  *(undefined ***)this = &PTR_LAB_0046f370;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  this_00 = (int *)((int)this + 0x1c);
  FUN_004049e0(this_00,&DAT_0049ed10);
  if (*this_00 == 0) {
    piVar4 = (int *)FUN_004517c0();
    FUN_00411b30(this_00,piVar4);
  }
  *(undefined ***)this = &PTR_LAB_00471824;
  *(undefined1 *)((int)this + 0x24) = param_2;
  puVar1 = (undefined4 *)((int *)*param_1)[3];
  iVar2 = *(int *)*param_1;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  FUN_00424300((undefined4 *)((int)this + 0x28),puVar1,(int)puVar1 + iVar2);
  iVar2 = *(int *)((int)this + 0x2c);
  if (iVar2 != 0) {
    iVar3 = *(int *)((int)this + 0x30);
    if ((*(byte *)((int)this + 0x24) & 0x10) != 0) {
      *(int *)((int)this + 0x14) = iVar3;
      *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 0x14);
      *(int *)((int)this + 0x18) = iVar2 + iVar3;
      if ((*(byte *)((int)this + 0x24) & 3) != 0) {
        *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + iVar2;
      }
    }
    if ((*(byte *)((int)this + 0x24) & 8) != 0) {
      *(int *)((int)this + 4) = iVar3;
      *(int *)((int)this + 8) = iVar3;
      *(int *)((int)this + 0xc) = iVar3 + iVar2;
    }
  }
  return this;
}


