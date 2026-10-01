// 00401a27 FUN_00401a27 [Global]
// program: gdkup.exe

undefined4 FUN_00401a27(int *param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 local_28;
  
  *param_4 = 0;
  if (param_2 == 0) {
    piVar1 = (int *)(**(code **)(*param_1 + 0x14))();
    if (piVar1 == (int *)0x0) {
      local_28 = 0x8007000e;
    }
    else {
      local_28 = (**(code **)*piVar1)(piVar1,param_3,param_4);
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  else {
    local_28 = 0x80040110;
  }
  return local_28;
}


