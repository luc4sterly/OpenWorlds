// 0042c5e0 FUN_0042c5e0 [Global]
// programa: gamma.dll

void __fastcall FUN_0042c5e0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar2 = puVar1 + *(int *)(param_1 + 4) * 0x41;
  while (puVar1 < puVar2) {
    puVar2 = puVar2 + -0x41;
    (**(code **)*puVar2)(0);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


