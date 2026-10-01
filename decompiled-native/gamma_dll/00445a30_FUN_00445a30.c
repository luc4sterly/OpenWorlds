// 00445a30 FUN_00445a30 [Global]
// program: gamma.dll

int FUN_00445a30(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *local_14;
  
  if (param_2 == (int *)0x0) {
    return -0x7fffbffd;
  }
  iVar2 = (**(code **)(*param_1 + 0x138))();
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = (**(code **)*param_2)(param_2,&DAT_004670d8,&local_14);
  if (iVar2 < 0) {
    param_1[0x28] = 0x30;
    param_1[0x29] = 0;
    param_1[0x30] = 0;
    param_1[0x2a] = 0;
    iVar2 = (**(code **)(*param_2 + 0x3c))(param_2);
    if (iVar2 == 0) {
      param_1[0x2a] = param_1[0x2a] | 4;
    }
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (iVar2 == 0) {
      param_1[0x2a] = param_1[0x2a] | 2;
    }
    iVar2 = (**(code **)(*param_2 + 0x1c))(param_2);
    if (iVar2 == 0) {
      param_1[0x2a] = param_1[0x2a] | 1;
    }
    iVar2 = (**(code **)(*param_2 + 0x14))(param_2,param_1 + 0x2c,param_1 + 0x2e);
    if (-1 < iVar2) {
      param_1[0x2a] = param_1[0x2a] | 0x110;
    }
    iVar2 = (**(code **)(*param_2 + 0x34))(param_2,param_1 + 0x31);
    if (iVar2 == 0) {
      param_1[0x2a] = param_1[0x2a] | 8;
    }
    (**(code **)(*param_2 + 0xc))(param_2,param_1 + 0x32);
    iVar2 = (**(code **)(*param_2 + 0x2c))(param_2);
    param_1[0x2b] = iVar2;
    iVar2 = (**(code **)(*param_2 + 0x10))(param_2);
    param_1[0x33] = iVar2;
  }
  else {
    iVar2 = (**(code **)(*local_14 + 0x4c))(local_14,0x30,param_1 + 0x28);
    (**(code **)(*local_14 + 8))(local_14);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  if ((param_1[0x2a] & 8U) == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0xd4))(param_1[0x31]);
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined1 *)(param_1 + 9) = 1;
  (**(code **)(*param_1 + 0xb4))(param_1);
  piVar1 = *(int **)(param_1[10] + 0x40);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,3,0x8004022a,0);
  }
  return -0x7ffbfe00;
}


