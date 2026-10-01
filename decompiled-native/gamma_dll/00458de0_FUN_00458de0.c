// 00458de0 FUN_00458de0 [Global]
// program: gamma.dll

undefined8 __cdecl FUN_00458de0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 1;
  iVar3 = 1;
  if (param_1 < 0) {
    param_1 = -param_1;
    iVar2 = -1;
  }
  if (param_2 < 0) {
    param_2 = -param_2;
    iVar3 = -1;
  }
  iVar1 = (param_1 / param_2) * iVar2 * iVar3;
  return CONCAT44(param_1 * iVar2 - iVar1 * param_2 * iVar3,iVar1);
}


