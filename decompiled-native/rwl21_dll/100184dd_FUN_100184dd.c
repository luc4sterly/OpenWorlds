// 100184dd FUN_100184dd [Global]
// programa: RWL21.DLL

undefined4 FUN_100184dd(void)

{
  int *piVar1;
  char *in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  bool in_ZF;
  
  if (!in_ZF) {
    iVar2 = FUN_10043e80(in_EAX,&stack0x00000000);
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
             (iVar3 = FUN_10043f20(&stack0x00000000,*(char **)(*piVar1 + iVar4)), iVar3 != 0))
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


