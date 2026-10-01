// 10004b30 FUN_10004b30 [Global]
// program: RWDL6D21.DLL

bool FUN_10004b30(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x80))(param_1,0);
  if (iVar1 == -0x7789fe3e) {
    (**(code **)(*param_1 + 0x6c))(param_1);
    iVar1 = (**(code **)(*param_1 + 0x80))(param_1,0);
  }
  return iVar1 == 0;
}


