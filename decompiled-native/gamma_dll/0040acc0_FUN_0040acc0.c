// 0040acc0 FUN_0040acc0 [Global]
// programa: gamma.dll

undefined4 FUN_0040acc0(int *param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  *param_4 = 0;
  if (param_2 != 0) {
    return 0x80040110;
  }
  piVar1 = (int *)(**(code **)(*param_1 + 0x14))();
  if (piVar1 == (int *)0x0) {
    return 0x8007000e;
  }
  uVar2 = (**(code **)*piVar1)(piVar1,param_3,param_4);
  (**(code **)(*piVar1 + 8))(piVar1);
  return uVar2;
}


