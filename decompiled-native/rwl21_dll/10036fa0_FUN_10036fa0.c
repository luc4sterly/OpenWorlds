// 10036fa0 FUN_10036fa0 [Global]
// program: RWL21.DLL

void FUN_10036fa0(undefined4 *param_1,undefined4 *param_2)

{
  if ((undefined4 *)param_1[1] == (undefined4 *)0x0) {
    *param_1 = param_2;
  }
  else {
    *(undefined4 *)param_1[1] = param_2;
  }
  *param_2 = 0;
  param_1[1] = param_2;
  param_1[2] = param_1[2] + 1;
  return;
}


