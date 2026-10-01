// 00406470 FUN_00406470 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00406470(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)this);
  return this;
}


