// 00458ee0 FUN_00458ee0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00458ee0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (param_2 < 0 == iVar2 < 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = -1;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  if ((int)(0x7fffffff / (longlong)param_2) < iVar2) {
    return 0;
  }
  *param_1 = iVar2 * param_2 * iVar1;
  return 1;
}


