// 0042bc60 FUN_0042bc60 [Global]
// programa: gamma.dll

int __fastcall FUN_0042bc60(int param_1)

{
  FUN_0042c440(param_1 + 0x40);
  FUN_0042c410(param_1 + 0x34);
  FUN_0042c410(param_1 + 0x28);
  FUN_0042c410(param_1 + 0x1c);
  FUN_0042c410(param_1 + 0x10);
  if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
    FUN_0042c1d0(*(undefined4 **)(param_1 + 4));
  }
  return param_1;
}


