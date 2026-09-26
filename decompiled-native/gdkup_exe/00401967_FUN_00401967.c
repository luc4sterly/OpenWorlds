// 00401967 FUN_00401967 [Global]
// programa: gdkup.exe

int FUN_00401967(int *param_1)

{
  int local_18;
  
  param_1[1] = param_1[1] + -1;
  if (param_1[1] == 0) {
    (**(code **)(*param_1 + 0x18))();
    local_18 = 0;
  }
  else {
    local_18 = param_1[1];
  }
  return local_18;
}


