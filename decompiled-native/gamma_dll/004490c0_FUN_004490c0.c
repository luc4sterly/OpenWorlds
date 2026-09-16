// 004490c0 FUN_004490c0 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_004490c0(int *param_1)

{
  if (param_1[0x12] != 0) {
    FUN_00447c10(param_1[0x12]);
  }
  (**(code **)(*param_1 + 0xcc))(1);
  return 0;
}


