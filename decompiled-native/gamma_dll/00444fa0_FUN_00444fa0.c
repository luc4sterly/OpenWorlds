// 00444fa0 FUN_00444fa0 [Global]
// programa: gamma.dll

int __thiscall FUN_00444fa0(void *this,int *param_1,char *param_2)

{
  int iVar1;
  uint local_1c;
  int local_18;
  int *local_14;
  
  local_14 = (int *)0x0;
  if (param_2 != (char *)0x0) {
    iVar1 = FUN_00448170(param_2);
    if (iVar1 == 0) {
      iVar1 = FUN_00444de0(this,param_1,param_2);
      return iVar1;
    }
  }
  local_1c = 0;
  local_18 = -0x7ffbfdf9;
  do {
    if (local_1c == *(byte *)((int)this + 0x26)) {
      iVar1 = (**(code **)(*param_1 + 0x30))(param_1,&local_14);
    }
    else {
      iVar1 = (**(code **)(*(int *)this + 0xac))(this,&local_14);
    }
    if (-1 < iVar1) {
      iVar1 = FUN_00444ec0(this,param_1,param_2,local_14);
      (**(code **)(*local_14 + 8))(local_14);
      if (-1 < iVar1) {
        return 0;
      }
      if (((iVar1 != -0x7fffbffb) && (iVar1 != -0x7ff8ffa9)) && (iVar1 != -0x7ffbfdd6)) {
        local_18 = iVar1;
      }
    }
    local_1c = local_1c + 1;
  } while ((int)local_1c < 2);
  return local_18;
}


