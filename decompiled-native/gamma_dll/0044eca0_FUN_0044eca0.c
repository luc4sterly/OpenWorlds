// 0044eca0 FUN_0044eca0 [Global]
// programa: gamma.dll

int __thiscall FUN_0044eca0(void *this,short *param_1,int param_2)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int local_18;
  int local_14;
  
  uVar3 = *(int *)((int)this + 0x18) - *(int *)((int)this + 0x14);
  local_14 = (int)((uVar3 + 1) - (uint)(uVar3 < 0x80000000)) >> 1;
  if (local_14 < param_2) {
    piVar4 = &local_14;
  }
  else {
    piVar4 = &param_2;
  }
  local_18 = *piVar4;
  if (0 < local_18) {
    FUN_00458960(*(undefined4 **)((int)this + 0x14),(undefined4 *)param_1,local_18);
    *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + local_18 * 2;
    param_1 = param_1 + local_18;
    param_2 = param_2 - local_18;
  }
  while( true ) {
    if (param_2 < 1) {
      return local_18;
    }
    sVar2 = *param_1;
    param_1 = param_1 + 1;
    if (*(uint *)((int)this + 0x14) < *(uint *)((int)this + 0x18)) {
      psVar1 = *(short **)((int)this + 0x14);
      *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + 2;
      *psVar1 = sVar2;
      sVar2 = *psVar1;
    }
    else {
      sVar2 = (**(code **)(*(int *)this + 0x30))(sVar2);
    }
    if (sVar2 == -1) break;
    param_2 = param_2 + -1;
    local_18 = local_18 + 1;
  }
  return local_18;
}


