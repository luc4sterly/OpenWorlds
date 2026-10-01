// 100184d0 FUN_100184d0 [Global]
// program: RWL21.DLL

undefined4 FUN_100184d0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char acStack_80 [128];
  
  if (param_1 != 0) {
    iVar2 = FUN_10043e80((char *)param_1,acStack_80);
    if (iVar2 == 0) {
      FUN_1000cba0(0x2c);
    }
    else {
      iVar2 = 0;
      piVar1 = *(int **)(DAT_1005abf4 + -4 + DAT_1005abfc * 4);
      if (0 < piVar1[2]) {
        iVar4 = 0;
        do {
          if ((*(char **)(*piVar1 + iVar4) != (char *)0x0) &&
             (iVar3 = FUN_10043f20(acStack_80,*(char **)(*piVar1 + iVar4)), iVar3 != 0))
          goto LAB_1001852f;
          iVar4 = iVar4 + 8;
          iVar2 = iVar2 + 1;
        } while (iVar2 < piVar1[2]);
      }
      iVar2 = -1;
LAB_1001852f:
      if (iVar2 != -1) {
        return *(undefined4 *)(**(int **)(DAT_1005abf4 + -4 + DAT_1005abfc * 4) + 4 + iVar2 * 8);
      }
    }
  }
  return 0;
}


