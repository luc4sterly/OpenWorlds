// 00431300 FUN_00431300 [Global]
// program: gamma.dll

void __fastcall FUN_00431300(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar2 = puVar1 + *(int *)(param_1 + 4) * 0x44;
  while (puVar1 < puVar2) {
    puVar2[-2] = &PTR_LAB_00475040;
    if ((undefined4 *)puVar2[-1] != (undefined4 *)0x0) {
      FUN_0042f340((undefined4 *)puVar2[-1]);
    }
    FUN_0042f320(puVar2 + -2);
    puVar2[-0x44] = &PTR_LAB_00471ff8;
    puVar2 = puVar2 + -0x44;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


