// 004403c0 FUN_004403c0 [Global]
// programa: gamma.dll

void __fastcall FUN_004403c0(int param_1)

{
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00440ac0(param_1);
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x38);
  }
  CoUninitialize();
  return;
}


