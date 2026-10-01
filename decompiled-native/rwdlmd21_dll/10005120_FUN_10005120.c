// 10005120 FUN_10005120 [Global]
// program: rwdlmd21.dll

bool FUN_10005120(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_2;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *param_2 = 0x6c;
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,param_2,1,0);
  if (iVar1 == -0x7789fe3e) {
    (**(code **)(*param_1 + 0x6c))(param_1);
    iVar1 = (**(code **)(*param_1 + 100))(param_1,0,param_2,1,0);
  }
  return iVar1 == 0;
}


