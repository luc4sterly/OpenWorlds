// 00427b00 FUN_00427b00 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00427b00(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_1 == *param_2) && (param_1[1] == param_2[1])) {
    uVar1 = 1;
  }
  return uVar1;
}


