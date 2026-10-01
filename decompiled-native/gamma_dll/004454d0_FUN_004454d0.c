// 004454d0 FUN_004454d0 [Global]
// program: gamma.dll

int FUN_004454d0(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    return -0x7fffbffd;
  }
  iVar1 = (**(code **)(*param_1 + 0xd4))(param_2);
  if (iVar1 < 0) {
    return 1;
  }
  return iVar1;
}


