// 10018570 FUN_10018570 [Global]
// programa: RWL21.DLL

undefined4 FUN_10018570(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar3 = 0;
  if (0 < piVar1[2]) {
    piVar2 = (int *)(*piVar1 + 4);
    do {
      if ((int *)*piVar2 == param_1) goto LAB_100185a6;
      piVar2 = piVar2 + 2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < piVar1[2]);
  }
  iVar3 = -1;
LAB_100185a6:
  if (iVar3 != -1) {
    return *(undefined4 *)(*piVar1 + iVar3 * 8);
  }
  FUN_1000cba0(0x6a);
  return 0;
}


