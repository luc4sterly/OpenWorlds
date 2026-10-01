// 004380f0 FUN_004380f0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_004380f0(void *this,void *param_1)

{
  uint uVar1;
  void *this_00;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  undefined **local_220;
  char acStack_21c [256];
  undefined **local_11c [65];
  int local_18;
  undefined4 local_14;
  
  FUN_0042f2c0(this);
  *(undefined ***)this = &PTR_LAB_004763a8;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  FUN_00436120((undefined4 *)((int)this + 0x14));
  *(undefined4 *)((int)this + 0x244) = 0xffffffff;
  *(undefined4 *)((int)this + 0x248) = 0xffffffff;
  *(undefined4 *)((int)this + 0x24c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x250) = 0xffffffff;
  _DAT_0049fcec = _DAT_0049fcec + 1;
  FUN_00436d50(param_1,(int)this + 0x14);
  if (param_1 == (void *)0x0) {
    FUN_00427390();
  }
  uVar1 = FUN_004361d0((int)this + 0x14);
  FUN_00438b90((void *)((int)this + 8),uVar1);
  this_00 = (void *)FUN_00436200((int)this + 0x14);
  while( true ) {
    pvVar4 = (void *)FUN_00436210((int)this + 0x14);
    if (this_00 == pvVar4) break;
    FUN_004359d0(this_00,&local_220);
    local_220 = &PTR_LAB_00471ff8;
    FUN_00427410(local_11c,acStack_21c,0xff);
    uVar2 = FUN_004296f0((int)local_11c);
    local_11c[0] = &PTR_LAB_00471ff8;
    iVar3 = FUN_00436200((int)this + 0x14);
    local_18 = ((int)this_00 - iVar3) / 0x11c;
    local_14 = uVar2;
    FUN_00438b30((void *)((int)this + 8),&local_18);
    this_00 = (void *)((int)this_00 + 0x11c);
  }
  FUN_00438800(*(undefined4 **)((int)this + 0x10),
               *(undefined4 **)((int)this + 0x10) + *(int *)((int)this + 0xc) * 2);
  return this;
}


