// 0044f270 FUN_0044f270 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_0044f270(void *this,uint param_1,int param_2)

{
  void *this_00;
  undefined2 uVar1;
  int *piVar2;
  int local_30 [2];
  undefined1 local_25;
  
  if ((param_1 & 1) != 0) {
    *(int *)((int)this + 4) = (int)this + 8;
    *(undefined4 *)((int)this + 8) = &PTR_LAB_0046f410;
    *(undefined4 *)((int)this + 8) = &PTR_LAB_00480fb0;
  }
  *(undefined ***)this = &PTR_LAB_00480f98;
  **(undefined4 **)((int)this + 4) = &PTR_LAB_00480fa4;
  *(int *)(*(int *)((int)this + 4) + 0x3c) = (int)this + (8 - *(int *)((int)this + 4));
  this_00 = *(void **)((int)this + 4);
  FUN_00454dd0(this_00,param_2);
  *(undefined4 *)((int)this_00 + 0x34) = 0;
  FUN_004049b0(this_00,local_30);
  local_25 = DAT_0049e419;
  piVar2 = (int *)FUN_004500b0(local_30);
  uVar1 = (**(code **)(*piVar2 + 0x24))(0x20);
  FUN_00404dc0(local_30);
  *(undefined2 *)((int)this_00 + 0x38) = uVar1;
  return this;
}


