// 100183c0 RwFindNamedTexture [Global]
// programa: RWL21.DLL

undefined4 RwFindNamedTexture(char *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_88;
  int local_84;
  char local_80 [128];
  
                    /* 0x183c0  91  RwFindNamedTexture */
  if (param_1 == (char *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    iVar2 = FUN_10043e80(param_1,local_80);
    if (iVar2 == 0) {
      FUN_1000cba0(0x2c);
    }
    else {
      local_84 = DAT_1005abfc + -1;
      if (DAT_1005ac00 == 1) {
        local_88 = 1;
      }
      else {
        local_88 = DAT_1005abfc;
      }
      if (local_88 != 0) {
        iVar2 = local_84 * 4;
        do {
          local_88 = local_88 + -1;
          iVar5 = 0;
          piVar1 = *(int **)(DAT_1005abf4 + iVar2);
          if (0 < piVar1[2]) {
            iVar4 = 0;
            do {
              if ((*(char **)(*piVar1 + iVar4) != (char *)0x0) &&
                 (iVar3 = FUN_10043f20(local_80,*(char **)(*piVar1 + iVar4)), iVar3 != 0))
              goto LAB_1001846f;
              iVar4 = iVar4 + 8;
              iVar5 = iVar5 + 1;
            } while (iVar5 < piVar1[2]);
          }
          iVar5 = -1;
LAB_1001846f:
          if (iVar5 != -1) {
            return *(undefined4 *)(**(int **)(DAT_1005abf4 + local_84 * 4) + 4 + iVar5 * 8);
          }
          iVar2 = iVar2 + -4;
          local_84 = local_84 + -1;
        } while (local_88 != 0);
      }
    }
  }
  return 0;
}


