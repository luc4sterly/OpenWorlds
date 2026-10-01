// 00453e80 FUN_00453e80 [Global]
// program: gamma.dll

undefined4 FUN_00453e80(void)

{
  int iVar1;
  BOOL BVar2;
  
  iVar1 = FUN_00453d80();
  if (iVar1 != 0) {
    BVar2 = FUN_00453de0(0);
    if (BVar2 != 0) {
      return 1;
    }
  }
  return 0;
}


