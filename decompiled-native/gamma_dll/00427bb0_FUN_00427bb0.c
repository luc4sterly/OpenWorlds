// 00427bb0 FUN_00427bb0 [Global]
// programa: gamma.dll

bool __cdecl FUN_00427bb0(uint *param_1,uint *param_2)

{
  bool bVar1;
  bool bVar2;
  
  bVar1 = true;
  if (*param_1 <= *param_2) {
    bVar2 = false;
    if ((*param_2 == *param_1) && (param_2[1] < param_1[1])) {
      bVar2 = true;
    }
    if (!bVar2) {
      bVar1 = false;
    }
  }
  return !bVar1;
}


