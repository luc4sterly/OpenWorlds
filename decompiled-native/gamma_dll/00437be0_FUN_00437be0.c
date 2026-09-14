// 00437be0 FUN_00437be0 [Global]
// programa: gamma.dll

void __fastcall FUN_00437be0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar2 = puVar1 + *(int *)(param_1 + 4) * 0x47;
  while (puVar1 < puVar2) {
    puVar2 = puVar2 + -0x47;
    (**(code **)*puVar2)(0);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


