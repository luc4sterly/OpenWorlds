// 00427b30 FUN_00427b30 [Global]
// programa: gamma.dll

bool __cdecl FUN_00427b30(int *param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*param_1 == *param_2) && (param_1[1] == param_2[1])) {
    bVar1 = true;
  }
  return !bVar1;
}


