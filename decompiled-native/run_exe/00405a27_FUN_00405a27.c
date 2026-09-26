// 00405a27 FUN_00405a27 [Global]
// programa: run.exe

void FUN_00405a27(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0040bd20;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0040bbf4 = 0;
  DAT_0040bc0c = 0;
  DAT_0040be24 = 0;
  DAT_0040bc00 = 0;
  DAT_0040bc04 = 0;
  DAT_0040bc08 = 0;
  return;
}


