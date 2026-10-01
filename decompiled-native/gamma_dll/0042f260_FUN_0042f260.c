// 0042f260 FUN_0042f260 [Global]
// program: gamma.dll

void __fastcall FUN_0042f260(undefined4 *param_1)

{
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    FUN_0042c1d0((undefined4 *)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = param_1 + 1;
  }
  return;
}


