// 00454a60 FUN_00454a60 [Global]
// programa: gamma.dll

void __cdecl FUN_00454a60(undefined4 *param_1)

{
  uint uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee40);
    if ((param_1[-1] & 1) == 0) {
      uVar1 = *(uint *)(param_1[-1] + 8);
    }
    else {
      uVar1 = (param_1[-2] & 0xfffffff8) - 8;
    }
    if (uVar1 < 0x45) {
      FUN_00454990(param_1,uVar1);
    }
    else {
      FUN_00454790((int)param_1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee40);
    return;
  }
  return;
}


