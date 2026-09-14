// 00447b00 FUN_00447b00 [Global]
// programa: gamma.dll

int __thiscall FUN_00447b00(void *this,int *param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  LPCRITICAL_SECTION local_10;
  
  local_10 = (LPCRITICAL_SECTION)((int)this + 0x1c);
  EnterCriticalSection(local_10);
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,&local_20,&local_18);
  if (iVar1 < 0) {
    LeaveCriticalSection(local_10);
    return iVar1;
  }
  *(undefined4 *)((int)this + 0x34) = local_20;
  *(undefined4 *)((int)this + 0x38) = local_1c;
  *(undefined4 *)((int)this + 0x3c) = local_18;
  *(undefined4 *)((int)this + 0x40) = local_14;
  *(undefined4 *)((int)this + 0x44) = 0;
  LeaveCriticalSection(local_10);
  return 0;
}


