// 00458e90 FUN_00458e90 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00458e90(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 < 0) {
    if ((iVar1 < 0) && (param_2 < -0x80000000 - iVar1)) {
      return 0;
    }
  }
  else if ((0 < iVar1) && (0x7fffffff - iVar1 < param_2)) {
    return 0;
  }
  *param_1 = iVar1 + param_2;
  return 1;
}


