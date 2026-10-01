// 00427c50 FUN_00427c50 [Global]
// program: gamma.dll

int * __cdecl FUN_00427c50(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_00402c10();
  iVar1 = param_2[1];
  iVar2 = param_3[1];
  *param_1 = (uint)(iVar1 + iVar2) / 1000 + *param_2 + *param_3;
  param_1[1] = (uint)(iVar1 + iVar2) % 1000;
  return param_1;
}


