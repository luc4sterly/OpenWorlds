// 004392b0 FUN_004392b0 [Global]
// programa: gamma.dll

void __fastcall FUN_004392b0(int param_1)

{
  uint uVar1;
  
  for (uVar1 = *(int *)(param_1 + 4) * 8 + *(uint *)(param_1 + 8); *(uint *)(param_1 + 8) < uVar1;
      uVar1 = uVar1 - 8) {
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


