// 004492f0 FUN_004492f0 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_004492f0(void *this,int param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [8];
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*(int *)this + 0xfc))(param_1,&local_1c,local_14);
  if (iVar1 < 0) {
    return 0;
  }
  if (iVar1 == 0) {
    SetEvent(*(HANDLE *)((int)this + 0x4c));
    return 1;
  }
  iVar1 = (**(code **)(**(int **)((int)this + 0x18) + 0x10))
                    (*(int **)((int)this + 0x18),*(undefined4 *)((int)this + 0x1c),
                     *(undefined4 *)((int)this + 0x20),local_1c,local_18,
                     *(undefined4 *)((int)this + 0x4c),(int)this + 0x60);
  if (-1 < iVar1) {
    return 1;
  }
  return 0;
}


