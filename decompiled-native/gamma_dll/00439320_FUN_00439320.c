// 00439320 FUN_00439320 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00439320(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  switch(*(undefined4 *)((int)this + 4)) {
  case 1:
  case 4:
  case 5:
  case 6:
    FUN_00428f10(&local_38);
    *(undefined4 *)((int)this + 8) = local_38;
    *(undefined4 *)((int)this + 0xc) = uStack_34;
    *(undefined4 *)((int)this + 0x10) = uStack_30;
    *(undefined4 *)((int)this + 0x14) = uStack_2c;
    *(undefined4 *)((int)this + 0x18) = uStack_28;
    FUN_00428e50(&local_38);
    break;
  case 2:
    *(undefined ***)((int)this + 8) = &PTR_LAB_004732e8;
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0x14) = 0;
    break;
  case 3:
    *(undefined4 *)((int)this + 8) = 0;
  }
  return this;
}


