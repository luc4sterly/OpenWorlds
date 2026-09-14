// 00449a00 FUN_00449a00 [Global]
// programa: gamma.dll

void __fastcall FUN_00449a00(int param_1)

{
  if (*(UINT *)(param_1 + 0xb8) != 0) {
    timeKillEvent(*(UINT *)(param_1 + 0xb8));
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  return;
}


