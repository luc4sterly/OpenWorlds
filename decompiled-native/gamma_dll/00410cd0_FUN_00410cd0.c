// 00410cd0 FUN_00410cd0 [Global]
// program: gamma.dll

uint __thiscall FUN_00410cd0(void *this,byte *param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint *puVar4;
  uint local_18;
  uint local_14;
  
  local_14 = *(int *)((int)this + 0x18) - *(int *)((int)this + 0x14);
  if ((int)local_14 < (int)param_2) {
    puVar4 = &local_14;
  }
  else {
    puVar4 = &param_2;
  }
  local_18 = *puVar4;
  if (0 < (int)local_18) {
    FUN_0044df50(*(undefined4 **)((int)this + 0x14),(undefined4 *)param_1,local_18);
    param_1 = param_1 + local_18;
    *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + local_18;
    param_2 = param_2 - local_18;
  }
  while( true ) {
    if ((int)param_2 < 1) {
      return local_18;
    }
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    if (*(uint *)((int)this + 0x14) < *(uint *)((int)this + 0x18)) {
      pbVar2 = *(byte **)((int)this + 0x14);
      *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + 1;
      *pbVar2 = bVar1;
      uVar3 = (uint)*pbVar2;
    }
    else {
      uVar3 = (**(code **)(*(int *)this + 0x30))(bVar1);
    }
    if (uVar3 == 0xffffffff) break;
    param_2 = param_2 - 1;
    local_18 = local_18 + 1;
  }
  return local_18;
}


