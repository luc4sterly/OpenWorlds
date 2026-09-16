// 00453470 FUN_00453470 [Global]
// programa: gamma.dll

int FUN_00453470(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iStack_8;
  int iStack_4;
  
  iStack_4 = param_4;
  iStack_8 = param_3 - param_2;
  if (param_4 < param_3 - param_2) {
    piVar1 = &iStack_4;
  }
  else {
    piVar1 = &iStack_8;
  }
  return *piVar1;
}


