// 10003050 FUN_10003050 [Global]
// programa: RWDLDD21.DLL

bool FUN_10003050(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x80))(param_1,0);
  if (iVar1 == -0x7789fe3e) {
    puVar2 = (undefined4 *)&stack0xffffff8c;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff8c,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar1 = (**(code **)(*param_1 + 0x80))(param_1,0);
  }
  return iVar1 == 0;
}


