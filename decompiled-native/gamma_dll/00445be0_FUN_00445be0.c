// 00445be0 FUN_00445be0 [Global]
// program: gamma.dll

int FUN_00445be0(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    return -0x7fffbffd;
  }
  *param_4 = 0;
  while( true ) {
    if (param_3 < 1) {
      return 0;
    }
    param_3 = param_3 + -1;
    iVar1 = (**(code **)(*param_1 + 0x120))(param_1,*(undefined4 *)(param_2 + *param_4 * 4));
    if (iVar1 != 0) break;
    *param_4 = *param_4 + 1;
  }
  return iVar1;
}


