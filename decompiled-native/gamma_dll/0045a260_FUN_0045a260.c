// 0045a260 FUN_0045a260 [Global]
// programa: gamma.dll

void FUN_0045a260(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = &PTR_FUN_00484004; (code *)*ppuVar1 != (code *)0x0; ppuVar1 = ppuVar1 + 1) {
    (*(code *)*ppuVar1)();
  }
  return;
}


