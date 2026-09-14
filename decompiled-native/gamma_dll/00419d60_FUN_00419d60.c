// 00419d60 FUN_00419d60 [Global]
// programa: gamma.dll

void __cdecl FUN_00419d60(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  if (param_2 == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  RwSetClumpState(param_1,uVar1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


