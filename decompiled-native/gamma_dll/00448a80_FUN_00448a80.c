// 00448a80 FUN_00448a80 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_00448a80(void *this,int param_1)

{
  int iVar1;
  
  if (*(int *)(*(int *)((int)this + 0x70) + 0x18) == 0) {
    SetEvent(*(HANDLE *)((int)this + 0x54));
    return 0;
  }
  if (*(int *)((int)this + 0x68) == 1) {
    SetEvent(*(HANDLE *)((int)this + 0x54));
    return 0;
  }
  iVar1 = (**(code **)(*(int *)this + 0x144))();
  if ((iVar1 == 1) && (param_1 != 0)) {
    SetEvent(*(HANDLE *)((int)this + 0x54));
    return 0;
  }
  ResetEvent(*(HANDLE *)((int)this + 0x54));
  return 1;
}


