// 00459200 FUN_00459200 [Global]
// program: gamma.dll

undefined4 FUN_00459200(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = FUN_0044dbf0(param_1,param_2,*param_3);
  if (*param_3 <= uVar1) {
    *param_3 = uVar1;
    return 0;
  }
  *param_3 = uVar1;
  return 1;
}


