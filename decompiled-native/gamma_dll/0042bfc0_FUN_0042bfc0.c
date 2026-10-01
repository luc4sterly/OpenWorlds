// 0042bfc0 FUN_0042bfc0 [Global]
// program: gamma.dll

int __thiscall FUN_0042bfc0(void *this,int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  void *this_00;
  int iVar3;
  undefined1 auStack_30 [4];
  int local_2c;
  undefined1 *local_14;
  
  iVar3 = (param_2 - param_1) * -0x193d4bb7;
  iVar1 = (param_2 - param_1) / 0x11c;
  if (iVar1 != 0) {
    puVar2 = FUN_0044e010(iVar1 * 0x11c);
    *(uint **)((int)this + 8) = puVar2;
    *(int *)this = iVar1;
    local_2c = *(int *)((int)this + 8);
    for (iVar3 = param_1; iVar3 != param_2; iVar3 = iVar3 + 0x11c) {
      this_00 = (void *)FUN_00406440(0x11c,local_2c);
      if (this_00 != (void *)0x0) {
        local_14 = auStack_30;
        FUN_0042c070(this_00,iVar3);
      }
      local_2c = local_2c + 0x11c;
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
    }
  }
  return iVar3;
}


