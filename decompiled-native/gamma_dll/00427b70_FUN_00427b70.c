// 00427b70 FUN_00427b70 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00427b70(uint *param_1,uint *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*param_2 <= *param_1) {
    bVar1 = false;
    if ((*param_1 == *param_2) && (param_1[1] < param_2[1])) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


