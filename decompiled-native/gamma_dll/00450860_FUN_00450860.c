// 00450860 FUN_00450860 [Global]
// program: gamma.dll

void FUN_00450860(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0049fa64;
  while (puVar1 != (undefined4 *)0x0) {
    DAT_0049fa64 = (undefined4 *)*puVar1;
    (*(code *)puVar1[1])();
    puVar1 = DAT_0049fa64;
  }
  DAT_0049fa64 = puVar1;
  return;
}


