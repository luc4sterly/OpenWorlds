// 00449930 FUN_00449930 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00449930(void *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  void *pvVar1;
  undefined4 uVar2;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x8c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)param_1 + 0x5c) == 0) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  *(undefined4 *)((int)param_1 + 0xb8) = 0;
  if (*(int **)((int)param_1 + 0x48) != (int *)0x0) {
    FUN_00447c60(*(int **)((int)param_1 + 0x48));
  }
  *(undefined4 *)((int)param_1 + 0x6c) = 1;
  pvVar1 = param_1;
  if (param_1 != (void *)0x0) {
    pvVar1 = (void *)((int)param_1 + 0xc);
  }
  uVar2 = FUN_00443eb0(param_1,1,0,(int)pvVar1);
  LeaveCriticalSection(lpCriticalSection);
  return uVar2;
}


