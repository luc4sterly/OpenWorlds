// 0043a1f0 FUN_0043a1f0 [Global]
// program: gamma.dll

undefined4 * __thiscall
FUN_0043a1f0(int param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  FUN_00427c50(&iStack_28,(int *)(param_1 + 0x18),param_4);
  *(int *)(param_1 + 0x18) = iStack_28;
  *(undefined4 *)(param_1 + 0x1c) = uStack_24;
  bVar1 = FUN_00427c00((uint *)(param_1 + 0x18),(uint *)(param_1 + 0x20));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iStack_20 = *param_4;
    iStack_1c = param_4[1];
    (**(code **)(**(int **)(param_1 + 0x14) + 4))(param_2,param_3,&iStack_20);
    return param_2;
  }
  iStack_18 = *param_4;
  iStack_14 = param_4[1];
  FUN_00439fb0(param_1,iStack_14,param_2,param_3,&iStack_18);
  return param_2;
}


