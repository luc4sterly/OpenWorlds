// 00427cb0 FUN_00427cb0 [Global]
// programa: gamma.dll

int * __cdecl FUN_00427cb0(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  FUN_00402c10();
  uVar1 = param_2[1];
  uVar2 = param_3[1];
  if (uVar1 < uVar2) {
    iVar4 = (uVar1 + 1000) - uVar2;
    iVar3 = (*param_2 - *param_3) + -1;
  }
  else {
    iVar4 = uVar1 - uVar2;
    iVar3 = *param_2 - *param_3;
  }
  *param_1 = iVar3;
  param_1[1] = iVar4;
  return param_1;
}


