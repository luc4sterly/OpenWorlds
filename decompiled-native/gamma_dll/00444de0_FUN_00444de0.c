// 00444de0 FUN_00444de0 [Global]
// program: gamma.dll

int __thiscall FUN_00444de0(void *this,int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = (**(code **)(*(int *)this + 0xdc))(param_1);
  if (iVar2 < 0) {
    (**(code **)(*(int *)this + 0xe0))();
    return iVar2;
  }
  iVar2 = (**(code **)(*(int *)this + 0xd4))(param_2);
  if (iVar2 == 0) {
    *(int **)((int)this + 0x18) = param_1;
    (**(code **)(**(int **)((int)this + 0x18) + 4))(*(int **)((int)this + 0x18));
    (**(code **)(*(int *)this + 0xd8))(param_2);
    pvVar3 = this;
    if (this != (void *)0x0) {
      pvVar3 = (void *)((int)this + 0xc);
    }
    iVar2 = (**(code **)(*param_1 + 0x10))(param_1,pvVar3,param_2);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*(int *)this + 0xe4))(param_1);
      if (-1 < iVar2) {
        return iVar2;
      }
      (**(code **)(*param_1 + 0x14))(param_1);
    }
  }
  else if (((-1 < iVar2) || (iVar2 == -0x7fffbffb)) || (iVar2 == -0x7ff8ffa9)) {
    iVar2 = -0x7ffbfdd6;
  }
  (**(code **)(*(int *)this + 0xe0))();
  piVar1 = *(int **)((int)this + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)((int)this + 0x18) = 0;
  }
  return iVar2;
}


