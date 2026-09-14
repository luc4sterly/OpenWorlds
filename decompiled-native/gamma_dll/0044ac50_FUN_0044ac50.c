// 0044ac50 FUN_0044ac50 [Global]
// programa: gamma.dll

int __cdecl FUN_0044ac50(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  if (param_1 < 0x40000001) {
    for (; iVar1 * iVar1 < param_1; iVar1 = iVar1 * 2) {
    }
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (iVar1 * iVar1 + param_1) / (iVar1 * 2);
      if (-1 < iVar1) {
        iVar1 = (iVar1 * iVar1 + param_1) / (iVar1 * 2);
      }
      if (-1 < iVar1) {
        iVar1 = (iVar1 * iVar1 + param_1) / (iVar1 * 2);
      }
    }
  }
  else {
    iVar1 = 0x8000;
  }
  return iVar1;
}


