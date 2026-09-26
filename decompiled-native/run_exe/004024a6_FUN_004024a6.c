// 004024a6 FUN_004024a6 [Global]
// programa: run.exe

void __cdecl FUN_004024a6(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_00402471(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}


