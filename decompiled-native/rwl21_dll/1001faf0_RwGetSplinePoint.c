// 1001faf0 RwGetSplinePoint [Global]
// programa: RWL21.DLL

undefined4 * RwGetSplinePoint(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
                    /* 0x1faf0  247  RwGetSplinePoint */
  if ((param_1 == (int *)0x0) || (param_3 == (undefined4 *)0x0)) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  if (param_2 < 1) goto LAB_1001fb63;
  if (param_1 == (int *)0x0) {
    iVar1 = 1;
LAB_1001fb30:
    FUN_1000cba0(iVar1);
    iVar1 = 0;
  }
  else if (param_1[1] == 1) {
    iVar1 = *param_1 + -2;
  }
  else {
    if (param_1[1] != 2) {
      iVar1 = 0x11;
      goto LAB_1001fb30;
    }
    iVar1 = *param_1 + -3;
  }
  if (param_2 <= iVar1) {
    iVar1 = param_1[3] + param_2 * 0xc;
    *param_3 = *(undefined4 *)(iVar1 + -0xc);
    param_3[1] = *(undefined4 *)(iVar1 + -8);
    param_3[2] = *(undefined4 *)(iVar1 + -4);
    return param_3;
  }
LAB_1001fb63:
  FUN_1000cba0(0xb);
  return (undefined4 *)0x0;
}


