// 0040369d FUN_0040369d [Global]
// program: gdkup.exe

DWORD __fastcall FUN_0040369d(undefined4 param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBX;
  uint dwStackSize;
  undefined8 uVar1;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  char local_48 [24];
  undefined1 local_30 [4];
  undefined4 local_2c;
  HANDLE local_28;
  uint local_24;
  HANDLE local_20;
  HANDLE *local_1c;
  HANDLE local_18;
  DWORD local_14;
  
  if (DAT_00408b34 == -1) {
    uVar1 = FUN_0040518c(param_1,0xffffffff);
    if ((int)uVar1 == 0) {
      return (DWORD)((ulonglong)uVar1 >> 0x20);
    }
    FUN_0040529c();
    param_1 = extraout_ECX;
  }
  local_2c = param_1;
  local_28 = GetCurrentThread();
  dwStackSize = unaff_EBX + 0xfffU & 0xfffff000;
  uStack_50 = DAT_004083a0;
  uStack_4c = DAT_004083a4;
  local_48[0] = DAT_004083a8;
  local_24 = dwStackSize;
  GetCurrentThreadId();
  FUN_004028cf(extraout_ECX_00,local_48);
  local_20 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)&uStack_50);
  local_1c = &local_18;
  local_18 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,dwStackSize,
                          (LPTHREAD_START_ROUTINE)&LAB_004035f1,local_30,0,&local_14);
  if (local_18 == (HANDLE)0x0) {
    local_14 = 0xffffffff;
  }
  else {
    WaitForSingleObject(local_20,0xffffffff);
  }
  CloseHandle(local_20);
  return local_14;
}


