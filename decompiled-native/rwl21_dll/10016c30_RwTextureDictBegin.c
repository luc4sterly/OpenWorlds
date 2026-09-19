// 10016c30 RwTextureDictBegin [Global]
// programa: RWL21.DLL

undefined4 RwTextureDictBegin(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *local_10;
  int iStack_8;
  int iStack_4;
  
                    /* 0x16c30  501  RwTextureDictBegin */
  local_10 = FUN_10037030(DAT_1005abec);
  if (local_10 == (int *)0x0) {
    FUN_1000cba0(3);
    local_10 = (int *)0x0;
  }
  else {
    iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x40);
    *local_10 = iVar4;
    if (iVar4 == 0) {
      FUN_10037010(DAT_1005abec,local_10);
      FUN_1000cba0(3);
      local_10 = (int *)0x0;
    }
    else {
      local_10[1] = 8;
      local_10[2] = 0;
    }
  }
  if (local_10 == (int *)0x0) {
    return 0;
  }
  iVar4 = DAT_1005abf4;
  iVar7 = DAT_1005abf8;
  if (DAT_1005abfc == DAT_1005abf8) {
    iVar7 = (DAT_1005abf8 >> 1) + DAT_1005abf8;
    iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(DAT_1005abf4,iVar7 * 4);
    if (iVar4 == 0) {
      FUN_1000cba0(3);
      iStack_4 = 0;
      if (0 < local_10[2]) {
        iStack_8 = 0;
        do {
          if (*(int *)(*local_10 + iStack_8) != 0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(*(int *)(*local_10 + iStack_8));
          }
          **(undefined4 **)(*local_10 + 4 + iStack_8) = 0;
          piVar2 = *(int **)(*local_10 + 4 + iStack_8);
          if (piVar2 == (int *)0x0) {
            FUN_1000cba0(1);
          }
          else {
            piVar3 = (int *)*piVar2;
            if (piVar3 != (int *)0x0) {
              iVar4 = piVar3[2];
              iVar7 = 0;
              piVar1 = piVar3 + 2;
              if (0 < iVar4) {
                puVar5 = (undefined4 *)(*piVar3 + 4);
                do {
                  if ((int *)*puVar5 == piVar2) goto LAB_10016d96;
                  puVar5 = puVar5 + 2;
                  iVar7 = iVar7 + 1;
                } while (iVar7 < iVar4);
              }
              iVar7 = -1;
LAB_10016d96:
              if (((iVar7 != -1) && (-1 < iVar7)) && (iVar7 < iVar4)) {
                iVar4 = *(int *)(*piVar3 + iVar7 * 8);
                if (iVar4 != 0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar4);
                }
                iVar7 = iVar7 + 1;
                **(undefined4 **)(*piVar3 + -4 + iVar7 * 8) = 0;
                if (iVar7 < *piVar1) {
                  iVar4 = iVar7 * 8;
                  do {
                    iVar7 = iVar7 + 1;
                    ((undefined4 *)(*piVar3 + iVar4))[-2] = *(undefined4 *)(*piVar3 + iVar4);
                    iVar6 = *piVar3 + iVar4;
                    iVar4 = iVar4 + 8;
                    *(undefined4 *)(iVar6 + -4) = *(undefined4 *)(iVar6 + 4);
                  } while (iVar7 < *piVar1);
                }
                *piVar1 = *piVar1 + -1;
              }
            }
            if (piVar2[6] != 0) {
              *(undefined4 *)(piVar2[6] + 0x3c) = 0;
              RwDestroyRaster((undefined4 *)piVar2[6]);
            }
            if (piVar2[7] != 0) {
              *(undefined4 *)(piVar2[7] + 0x3c) = 0;
              RwDestroyRaster((undefined4 *)piVar2[7]);
            }
            FUN_10037010(DAT_1005abf0,piVar2);
          }
          iStack_8 = iStack_8 + 8;
          iStack_4 = iStack_4 + 1;
        } while (iStack_4 < local_10[2]);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*local_10);
      FUN_10037010(DAT_1005abec,local_10);
      return 0;
    }
  }
  DAT_1005abf8 = iVar7;
  DAT_1005abf4 = iVar4;
  *(int **)(DAT_1005abf4 + DAT_1005abfc * 4) = local_10;
  DAT_1005abfc = DAT_1005abfc + 1;
  return 1;
}


