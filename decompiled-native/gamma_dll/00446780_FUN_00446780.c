// 00446780 FUN_00446780 [Global]
// programa: gamma.dll

uint FUN_00446780(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  int *piStack_10;
  
  uVar1 = FUN_00446570((int *)(param_1 + 0x10),&DAT_00467178,0,param_5,(int *)&piStack_10);
  if (-1 < (int)uVar1) {
    uVar1 = (**(code **)(*piStack_10 + 0x28))(piStack_10,param_3,param_4,param_6);
    (**(code **)(*piStack_10 + 8))(piStack_10);
  }
  return uVar1;
}


