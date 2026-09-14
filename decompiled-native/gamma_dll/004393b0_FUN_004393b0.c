// 004393b0 FUN_004393b0 [Global]
// programa: gamma.dll

void * __thiscall FUN_004393b0(void *this,void *param_1)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  FUN_00428f10(&local_20);
  local_20 = *(undefined4 *)((int)this + 8);
  uStack_1c = *(undefined4 *)((int)this + 0xc);
  uStack_18 = *(undefined4 *)((int)this + 0x10);
  uStack_14 = *(undefined4 *)((int)this + 0x14);
  uStack_10 = *(undefined4 *)((int)this + 0x18);
  FUN_00428df0(param_1,(int)&local_20);
  FUN_00428e50(&local_20);
  return param_1;
}


