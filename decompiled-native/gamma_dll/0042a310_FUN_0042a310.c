// 0042a310 FUN_0042a310 [Global]
// programa: gamma.dll

void __fastcall FUN_0042a310(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar2 = puVar1 + *(int *)(param_1 + 4) * 0x42;
  while (puVar1 < puVar2) {
    puVar2 = puVar2 + -0x42;
    *puVar2 = &PTR_LAB_00471ff8;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


