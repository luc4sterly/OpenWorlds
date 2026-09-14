// 0044b240 FUN_0044b240 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0044b240(void *this,BOOL param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,param_1,0,(LPCSTR)0x0);
  *(HANDLE *)this = pvVar1;
  return this;
}


