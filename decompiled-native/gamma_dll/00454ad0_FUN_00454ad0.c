// 00454ad0 FUN_00454ad0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454ad0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0049e768;
  if (DAT_0049e768 == 0) {
    return;
  }
  do {
    iVar1 = *(int *)(iVar2 + 4);
    FUN_004590c0(iVar2);
    iVar2 = iVar1;
  } while (iVar1 != DAT_0049e768);
  DAT_0049e768 = 0;
  DAT_0049edf8 = 0;
  DAT_0049edfc = 0;
  DAT_0049ee00 = 0;
  DAT_0049ee04 = 0;
  DAT_0049ee08 = 0;
  DAT_0049ee0c = 0;
  _DAT_0049ee10 = 0;
  _DAT_0049ee14 = 0;
  _DAT_0049ee18 = 0;
  _DAT_0049ee1c = 0;
  _DAT_0049ee20 = 0;
  _DAT_0049ee24 = 0;
  return;
}


