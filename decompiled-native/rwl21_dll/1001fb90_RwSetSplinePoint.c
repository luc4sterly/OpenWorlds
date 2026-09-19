// 1001fb90 RwSetSplinePoint [Global]
// programa: RWL21.DLL

int * RwSetSplinePoint(int *param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  
                    /* 0x1fb90  452  RwSetSplinePoint */
  if ((param_1 == (int *)0x0) || (param_3 == (undefined4 *)0x0)) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  if (param_2 < 1) goto LAB_1001fc1a;
  if (param_1 == (int *)0x0) {
    iVar2 = 1;
LAB_1001fbd8:
    FUN_1000cba0(iVar2);
    iVar2 = 0;
  }
  else if (param_1[1] == 1) {
    iVar2 = *param_1 + -2;
  }
  else {
    if (param_1[1] != 2) {
      iVar2 = 0x11;
      goto LAB_1001fbd8;
    }
    iVar2 = *param_1 + -3;
  }
  if (param_2 <= iVar2) {
    iVar2 = param_1[3];
    *(undefined4 *)(iVar2 + -0xc + param_2 * 0xc) = *param_3;
    iVar2 = iVar2 + param_2 * 0xc;
    *(undefined4 *)(iVar2 + -8) = param_3[1];
    *(undefined4 *)(iVar2 + -4) = param_3[2];
    piVar1 = FUN_1001f440(param_1,(float *)param_1[3]);
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    return param_1;
  }
LAB_1001fc1a:
  FUN_1000cba0(0xb);
  return (int *)0x0;
}


