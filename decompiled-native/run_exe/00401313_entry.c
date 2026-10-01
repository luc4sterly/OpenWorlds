// 00401313 entry [Global]
// program: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  _EXCEPTION_POINTERS *local_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004080e8;
  puStack_10 = &LAB_00403400;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff88;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_0040ba50 = DVar1 >> 8 & 0xff;
  _DAT_0040ba4c = DVar1 & 0xff;
  _DAT_0040ba48 = _DAT_0040ba4c * 0x100 + _DAT_0040ba50;
  _DAT_0040ba44 = DVar1 >> 0x10;
  iVar2 = FUN_004032aa(0);
  if (iVar2 == 0) {
    FUN_0040142e((undefined *)0x1c);
  }
  local_8 = 0;
  FUN_00402f8a();
  DAT_0040cf98 = GetCommandLineA();
  DAT_0040ba2c = FUN_00402e58();
  FUN_00402c0b();
  FUN_00402b52();
  FUN_004016a8();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  FUN_00402afa();
  GetModuleHandleA((LPCSTR)0x0);
  UVar3 = FUN_00401000();
  FUN_004016d5(UVar3);
  FUN_00402976(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}


