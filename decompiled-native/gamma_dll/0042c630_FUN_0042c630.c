// 0042c630 FUN_0042c630 [Global]
// programa: gamma.dll

void __fastcall FUN_0042c630(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar2 = puVar1 + *(int *)(param_1 + 4) * 0x47;
  while (puVar1 < puVar2) {
    puVar2 = puVar2 + -0x47;
    FUN_0042be30(puVar2);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


