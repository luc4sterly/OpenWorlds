// 10006dc0 FUN_10006dc0 [Global]
// program: RWDLDD21.DLL

void FUN_10006dc0(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if (*param_1 != 3) {
    piVar2 = (int *)param_1[0xb];
    if (piVar2 != (int *)0x0) {
      if (piVar2[0xb] != 0) {
        iVar6 = 0;
        if (0 < piVar2[9]) {
          iVar5 = 0;
          do {
            iVar3 = *(int *)(piVar2[0xb] + 4 + iVar5);
            if (iVar3 != -1) {
              puVar1 = (undefined4 *)(*(int *)(piVar2[0xc] + 0xc) + iVar3 * 0x18);
              *puVar1 = 0;
              puVar1[1] = 0;
              puVar1[2] = 0;
            }
            piVar4 = *(int **)(piVar2[0xb] + 8 + iVar5);
            if (piVar4 != (int *)0x0) {
              (**(code **)(*piVar4 + 8))(piVar4);
              *(undefined4 *)(piVar2[0xb] + 8 + iVar5) = 0;
            }
            iVar5 = iVar5 + 0x10;
            iVar6 = iVar6 + 1;
          } while (iVar6 < piVar2[9]);
        }
        (**(code **)(DAT_100394fc + 0x358))(piVar2[0xb]);
        piVar2[0xb] = 0;
      }
      piVar4 = (int *)*piVar2;
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 8))(piVar4);
        *piVar2 = 0;
      }
      (**(code **)(DAT_100394fc + 0x358))(piVar2);
      param_1[0xb] = 0;
    }
    iVar6 = 0;
    if (0 < DAT_10036180) {
      iVar5 = 0;
      do {
        if (*(int **)(DAT_1003617c + iVar5) == param_1) {
          *(int *)(DAT_1003617c + iVar5) = 0;
        }
        iVar5 = iVar5 + 4;
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_10036180);
    }
  }
  return;
}


