// 10018c50 FUN_10018c50 [Global]
// programa: RWL21.DLL

int FUN_10018c50(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  if (DAT_1005ac00 == 1) {
    local_8 = 1;
  }
  else {
    local_8 = DAT_1005abfc;
  }
  iVar2 = DAT_1005abfc + -1;
  *param_1 = 0;
  if (0 < local_8) {
    iVar2 = iVar2 * 4;
    iVar3 = local_8;
    do {
      piVar1 = (int *)(DAT_1005abf4 + iVar2);
      iVar2 = iVar2 + -4;
      iVar3 = iVar3 + -1;
      *param_1 = *param_1 + *(int *)(*piVar1 + 8);
    } while (iVar3 != 0);
  }
  if (*param_1 < 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(*param_1 << 3);
    if (iVar2 == 0) {
      FUN_1000cba0(3);
      return 0;
    }
    iVar3 = 0;
    if (local_8 != 0) {
      iVar6 = (DAT_1005abfc + -1) * 4;
      do {
        local_8 = local_8 + -1;
        iVar7 = 0;
        if (0 < *(int *)(*(int *)(DAT_1005abf4 + iVar6) + 8)) {
          iVar4 = 0;
          puVar5 = (undefined4 *)(iVar2 + iVar3 * 8);
          do {
            iVar7 = iVar7 + 1;
            iVar3 = iVar3 + 1;
            iVar4 = iVar4 + 8;
            *puVar5 = *(undefined4 *)(**(int **)(DAT_1005abf4 + iVar6) + -8 + iVar4);
            puVar5[1] = *(undefined4 *)(**(int **)(DAT_1005abf4 + iVar6) + -4 + iVar4);
            puVar5 = puVar5 + 2;
          } while (iVar7 < *(int *)(*(int *)(DAT_1005abf4 + iVar6) + 8));
        }
        iVar6 = iVar6 + -4;
      } while (local_8 != 0);
      return iVar2;
    }
  }
  return iVar2;
}


