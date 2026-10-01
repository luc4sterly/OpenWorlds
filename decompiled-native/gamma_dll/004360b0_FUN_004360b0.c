// 004360b0 FUN_004360b0 [Global]
// program: gamma.dll

void __fastcall FUN_004360b0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 8);
  for (uVar2 = *(int *)(param_1 + 4) * 0x18 + uVar1; uVar1 < uVar2; uVar2 = uVar2 - 0x18) {
    FUN_00428e50((undefined4 *)(uVar2 - 0x14));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


