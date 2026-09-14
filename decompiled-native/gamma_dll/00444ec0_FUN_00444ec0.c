// 00444ec0 FUN_00444ec0 [Global]
// programa: gamma.dll

int __thiscall FUN_00444ec0(void *this,int *param_1,char *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  void *local_18;
  undefined4 local_14;
  
  iVar1 = (**(code **)(*param_3 + 0x14))(param_3);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = 0;
  local_18 = (void *)0x0;
  local_14 = 0;
  do {
    iVar2 = (**(code **)(*param_3 + 0xc))(param_3,1,&local_18,&local_14);
    if (iVar2 != 0) {
      if (iVar1 == 0) {
        iVar1 = -0x7ffbfdf9;
      }
      return iVar1;
    }
    if (param_2 == (char *)0x0) {
LAB_00444f35:
      iVar2 = FUN_00444de0(this,param_1,local_18);
      if ((((iVar2 < 0) && (-1 < iVar1)) && (iVar2 != -0x7fffbffb)) &&
         ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))) {
        iVar1 = iVar2;
      }
    }
    else {
      iVar2 = FUN_004481e0(local_18,param_2);
      if (iVar2 != 0) goto LAB_00444f35;
      iVar2 = -0x7ffbfdf9;
    }
    FUN_004483c0(local_18);
    if (iVar2 == 0) {
      return 0;
    }
  } while( true );
}


