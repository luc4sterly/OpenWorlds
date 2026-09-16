// 00448950 FUN_00448950 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_00448950(int param_1,int param_2)

{
  if (param_2 == 1) {
    ResetEvent(*(HANDLE *)(param_1 + 0x50));
  }
  else {
    SetEvent(*(HANDLE *)(param_1 + 0x50));
  }
  return 0;
}


