// 0044fe30 FUN_0044fe30 [Global]
// programa: gamma.dll

int __fastcall FUN_0044fe30(int param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8);
  return (int)((uVar1 + 1) - (uint)(uVar1 < 0x80000000)) >> 1;
}


