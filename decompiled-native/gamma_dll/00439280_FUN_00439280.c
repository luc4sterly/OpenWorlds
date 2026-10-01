// 00439280 FUN_00439280 [Global]
// program: gamma.dll

void __fastcall FUN_00439280(int param_1)

{
  uint uVar1;
  
  for (uVar1 = *(int *)(param_1 + 4) * 0x1c + *(uint *)(param_1 + 8); *(uint *)(param_1 + 8) < uVar1
      ; uVar1 = uVar1 - 0x1c) {
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


