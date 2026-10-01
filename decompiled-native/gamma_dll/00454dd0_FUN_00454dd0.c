// 00454dd0 FUN_00454dd0 [Global]
// program: gamma.dll

void __thiscall FUN_00454dd0(void *this,int param_1)

{
  uint *this_00;
  int *piVar1;
  undefined1 auStack_44 [24];
  undefined1 *local_2c;
  uint *local_10;
  
  local_2c = auStack_44;
  *(int *)((int)this + 0x24) = param_1;
  *(undefined1 *)((int)this + 0x33) = 0;
  *(undefined1 *)((int)this + 0x32) = 1;
  *(bool *)((int)this + 0x32) = param_1 == 0;
  *(undefined2 *)((int)this + 0x30) = 0x1002;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x28) = 6;
  *(undefined4 *)((int)this + 0x20) = 0;
  this_00 = FUN_0044e010(8);
  if ((this_00 != (uint *)0x0) &&
     (local_10 = this_00, FUN_004049e0(this_00,&DAT_0049ed10), *local_10 == 0)) {
    piVar1 = (int *)FUN_004517c0();
    FUN_00411b30(local_10,piVar1);
  }
  *(uint **)((int)this + 0x20) = this_00;
  if (*(int *)((int)this + 0x20) == 0) {
    *(undefined1 *)((int)this + 0x32) = 1;
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  return;
}


