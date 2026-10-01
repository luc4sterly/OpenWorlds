// 00458fc0 FUN_00458fc0 [Global]
// program: gamma.dll

int __cdecl FUN_00458fc0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 1;
  iVar3 = 1;
  if (param_1 < 0) {
    param_1 = -param_1;
    iVar1 = -1;
  }
  if (param_2 < 0) {
    param_2 = -param_2;
    iVar3 = -1;
  }
  iVar2 = param_1 * iVar1 - (param_1 / param_2) * iVar1 * iVar3 * param_2 * iVar3;
  if ((iVar2 != 0) && (iVar1 * iVar3 < 0)) {
    iVar2 = iVar2 + param_2 * iVar3;
  }
  return iVar2;
}


