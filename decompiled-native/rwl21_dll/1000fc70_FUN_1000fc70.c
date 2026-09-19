// 1000fc70 FUN_1000fc70 [Global]
// programa: RWL21.DLL

uint FUN_1000fc70(uint param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + -1;
  iVar1 = FUN_100329e0(param_1);
  return (iVar1 == 0) - 1 & param_1;
}


