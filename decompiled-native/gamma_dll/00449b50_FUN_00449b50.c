// 00449b50 FUN_00449b50 [Global]
// programa: gamma.dll

void __thiscall FUN_00449b50(void *this,undefined4 param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x8c));
  *(undefined4 *)((int)this + 0xa8) = param_1;
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x8c));
  return;
}


