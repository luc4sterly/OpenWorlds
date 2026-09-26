// 004016a2 FUN_004016a2 [Global]
// programa: gdkup.exe

int FUN_004016a2(int *param_1)

{
  int local_18;
  
  param_1[1] = param_1[1] + -1;
  if (param_1[1] == 0) {
    SetEvent(DAT_0040b010);
    (**(code **)(*param_1 + 0x1c))();
    local_18 = 0;
  }
  else {
    local_18 = param_1[1];
  }
  return local_18;
}


