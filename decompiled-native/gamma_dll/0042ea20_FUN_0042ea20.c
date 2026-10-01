// 0042ea20 FUN_0042ea20 [Global]
// program: gamma.dll

void __fastcall FUN_0042ea20(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 8);
  uVar2 = *(int *)(param_1 + 4) * 0x4c + uVar1;
  while (uVar1 < uVar2) {
    uVar2 = uVar2 - 0x4c;
    FUN_0042bc60(uVar2);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


