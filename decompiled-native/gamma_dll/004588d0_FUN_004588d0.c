// 004588d0 FUN_004588d0 [Global]
// program: gamma.dll

int FUN_004588d0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (DAT_0049fb98 == 0x100) {
      DAT_0049fb98 = 3;
    }
    iVar1 = DAT_0049fb98;
    if ((&DAT_0049f448)[DAT_0049fb98] == 0) break;
    DAT_0049fb98 = DAT_0049fb98 + 1;
    iVar2 = iVar2 + 1;
    if (0xff < iVar2) {
      return -1;
    }
  }
  DAT_0049fb98 = DAT_0049fb98 + 1;
  return iVar1;
}


