// 10019800 FUN_10019800 [Global]
// programa: RWL21.DLL

undefined4 FUN_10019800(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piStack_10;
  int iStack_8;
  int iStack_4;
  
  DAT_1005abec = FUN_100371c0(s_texturedictlist_1005ac14,0xc);
  DAT_1005abf0 = FUN_100371c0(s_texturelist_1005ac08,0x24);
  if (DAT_1005abec == (undefined4 *)0x0) {
    return 0;
  }
  if (DAT_1005abf0 == (undefined4 *)0x0) {
    return 0;
  }
  DAT_1005abf4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x10);
  if (DAT_1005abf4 == 0) {
    FUN_1000cba0(3);
  }
  else {
    DAT_1005abfc = 0;
    DAT_1005abf8 = 4;
    piStack_10 = FUN_10037030((int)DAT_1005abec);
    if (piStack_10 == (int *)0x0) {
      FUN_1000cba0(3);
      piStack_10 = (int *)0x0;
    }
    else {
      iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x40);
      *piStack_10 = iVar6;
      if (iVar6 == 0) {
        FUN_10037010((int)DAT_1005abec,piStack_10);
        FUN_1000cba0(3);
        piStack_10 = (int *)0x0;
      }
      else {
        piStack_10[1] = 8;
        piStack_10[2] = 0;
      }
    }
    if (piStack_10 == (int *)0x0) {
      bVar4 = false;
    }
    else {
      iVar6 = DAT_1005abf4;
      iVar9 = DAT_1005abf8;
      if (DAT_1005abfc == DAT_1005abf8) {
        iVar9 = (DAT_1005abf8 >> 1) + DAT_1005abf8;
        iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x354))(DAT_1005abf4,iVar9 * 4);
        if (iVar6 == 0) {
          FUN_1000cba0(3);
          iStack_4 = 0;
          if (0 < piStack_10[2]) {
            iStack_8 = 0;
            do {
              if (*(int *)(*piStack_10 + iStack_8) != 0) {
                (**(code **)(PTR_DAT_1005b69c + 0x358))(*(int *)(*piStack_10 + iStack_8));
              }
              **(undefined4 **)(*piStack_10 + 4 + iStack_8) = 0;
              piVar2 = *(int **)(*piStack_10 + 4 + iStack_8);
              if (piVar2 == (int *)0x0) {
                FUN_1000cba0(1);
              }
              else {
                piVar3 = (int *)*piVar2;
                if (piVar3 != (int *)0x0) {
                  iVar6 = piVar3[2];
                  iVar9 = 0;
                  piVar1 = piVar3 + 2;
                  if (0 < iVar6) {
                    puVar8 = (undefined4 *)(*piVar3 + 4);
                    do {
                      if ((int *)*puVar8 == piVar2) goto LAB_100199d7;
                      puVar8 = puVar8 + 2;
                      iVar9 = iVar9 + 1;
                    } while (iVar9 < iVar6);
                  }
                  iVar9 = -1;
LAB_100199d7:
                  if (((iVar9 != -1) && (-1 < iVar9)) && (iVar9 < iVar6)) {
                    iVar6 = *(int *)(*piVar3 + iVar9 * 8);
                    if (iVar6 != 0) {
                      (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar6);
                    }
                    iVar9 = iVar9 + 1;
                    **(undefined4 **)(*piVar3 + -4 + iVar9 * 8) = 0;
                    if (iVar9 < *piVar1) {
                      iVar6 = iVar9 * 8;
                      do {
                        iVar9 = iVar9 + 1;
                        ((undefined4 *)(*piVar3 + iVar6))[-2] = *(undefined4 *)(*piVar3 + iVar6);
                        iVar7 = *piVar3 + iVar6;
                        iVar6 = iVar6 + 8;
                        *(undefined4 *)(iVar7 + -4) = *(undefined4 *)(iVar7 + 4);
                      } while (iVar9 < *piVar1);
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
                FUN_10037010((int)DAT_1005abf0,piVar2);
              }
              iStack_8 = iStack_8 + 8;
              iStack_4 = iStack_4 + 1;
            } while (iStack_4 < piStack_10[2]);
          }
          (**(code **)(PTR_DAT_1005b69c + 0x358))(*piStack_10);
          FUN_10037010((int)DAT_1005abec,piStack_10);
          bVar4 = false;
          goto LAB_10019b01;
        }
      }
      DAT_1005abf8 = iVar9;
      DAT_1005abf4 = iVar6;
      *(int **)(DAT_1005abf4 + DAT_1005abfc * 4) = piStack_10;
      DAT_1005abfc = DAT_1005abfc + 1;
      bVar4 = true;
    }
LAB_10019b01:
    bVar5 = true;
    if (bVar4) goto LAB_10019b21;
    (**(code **)(PTR_DAT_1005b69c + 0x358))(DAT_1005abf4);
  }
  bVar5 = false;
LAB_10019b21:
  if (!bVar5) {
    return 0;
  }
  return 1;
}


