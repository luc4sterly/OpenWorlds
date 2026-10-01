// 00448eb0 FUN_00448eb0 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_00448eb0(void *this,int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  uint *this_00;
  undefined4 local_10;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)this + 0x74);
  EnterCriticalSection(lpCriticalSection);
  local_10 = 0;
  if (param_1 != 0) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  if (*(int *)((int)this + 0x70) == 0) {
    this_00 = FUN_0044e010(0xd4);
    if (this_00 != (uint *)0x0) {
      FUN_00449ba0(this_00,(int)this,&local_10,(undefined4 *)&DAT_0047b028);
    }
    *(uint **)((int)this + 0x70) = this_00;
  }
  uVar1 = *(undefined4 *)((int)this + 0x70);
  LeaveCriticalSection(lpCriticalSection);
  return uVar1;
}


