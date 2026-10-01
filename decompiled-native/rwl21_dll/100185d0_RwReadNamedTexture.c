// 100185d0 RwReadNamedTexture [Global]
// program: RWL21.DLL

int * RwReadNamedTexture(char *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char local_80 [128];
  
                    /* 0x185d0  320  RwReadNamedTexture */
  piVar2 = FUN_10017b60(param_1);
  if (piVar2 != (int *)0x0) {
    piVar3 = FUN_10037030(DAT_1005abf0);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
      FUN_1000cba0(3);
    }
    else {
      *piVar3 = 0;
      piVar3[3] = 0;
      piVar3[4] = 0;
      piVar3[5] = 1;
      piVar3[1] = 0;
      piVar3[2] = 0;
      piVar3[6] = 0;
      piVar3[7] = 0;
      piVar3[8] = 0;
    }
    if (piVar3 == (int *)0x0) {
      RwDestroyRaster(piVar2);
    }
    else {
      puVar1 = (undefined4 *)piVar2[0xc];
      piVar2[0xc] = 0;
      iVar4 = RwSetTextureRaster((int)piVar3,(int)piVar2);
      if (iVar4 != 0) {
        if (puVar1 != (undefined4 *)0x0) {
          iVar4 = RwSetTextureMipmapRaster((int)piVar3,(int)puVar1);
        }
        if (iVar4 != 0) {
          iVar4 = FUN_10043e80(param_1,local_80);
          if (iVar4 == 0) {
            if (piVar3 == (int *)0x0) {
              FUN_1000cba0(1);
            }
            else {
              piVar2 = (int *)*piVar3;
              if (piVar2 != (int *)0x0) {
                iVar4 = 0;
                if (0 < piVar2[2]) {
                  piVar5 = (int *)(*piVar2 + 4);
                  do {
                    if ((int *)*piVar5 == piVar3) goto LAB_10018801;
                    piVar5 = piVar5 + 2;
                    iVar4 = iVar4 + 1;
                  } while (iVar4 < piVar2[2]);
                }
                iVar4 = -1;
LAB_10018801:
                if (iVar4 != -1) {
                  FUN_10018880(piVar2,iVar4);
                }
              }
              if (piVar3[6] != 0) {
                *(undefined4 *)(piVar3[6] + 0x3c) = 0;
                RwDestroyRaster((undefined4 *)piVar3[6]);
              }
              if (piVar3[7] != 0) {
                *(undefined4 *)(piVar3[7] + 0x3c) = 0;
                RwDestroyRaster((undefined4 *)piVar3[7]);
              }
              FUN_10037010(DAT_1005abf0,piVar3);
            }
            FUN_1000cba0(0x2c);
            return (int *)0x0;
          }
          piVar2 = *(int **)(DAT_1005abf4 + -4 + DAT_1005abfc * 4);
          if (*piVar3 != 0) {
            FUN_1000cba0(0x69);
            return (int *)0x0;
          }
          iVar4 = 0;
          iVar7 = 0;
          if (0 < piVar2[2]) {
            do {
              if ((*(char **)(*piVar2 + iVar4) != (char *)0x0) &&
                 (iVar6 = FUN_10043f20(local_80,*(char **)(*piVar2 + iVar4)), iVar6 != 0))
              goto LAB_10018774;
              iVar4 = iVar4 + 8;
              iVar7 = iVar7 + 1;
            } while (iVar7 < piVar2[2]);
          }
          iVar7 = -1;
LAB_10018774:
          if (iVar7 == -1) {
            iVar4 = FUN_100169e0(piVar2,local_80,piVar3);
            return (int *)((iVar4 == -1) - 1 & (uint)piVar3);
          }
          **(undefined4 **)(*piVar2 + 4 + iVar7 * 8) = 0;
          iVar4 = RwDestroyTexture(*(int **)(*piVar2 + 4 + iVar7 * 8));
          if (iVar4 == 0) {
            *(undefined4 *)(*piVar2 + 4 + iVar7 * 8) = 0;
            return (int *)0x0;
          }
          *piVar3 = (int)piVar2;
          *(int **)(*piVar2 + 4 + iVar7 * 8) = piVar3;
          return piVar3;
        }
      }
      if (puVar1 != (undefined4 *)0x0) {
        puVar1[0xf] = 0;
        RwDestroyRaster(puVar1);
      }
      iVar4 = 0;
      piVar2[0xf] = 0;
      RwDestroyRaster(piVar2);
      piVar3[7] = 0;
      piVar3[6] = 0;
      if (piVar3 == (int *)0x0) {
        FUN_1000cba0(1);
      }
      else {
        piVar2 = (int *)*piVar3;
        if (piVar2 != (int *)0x0) {
          if (0 < piVar2[2]) {
            piVar5 = (int *)(*piVar2 + 4);
            do {
              if ((int *)*piVar5 == piVar3) goto LAB_100186b4;
              piVar5 = piVar5 + 2;
              iVar4 = iVar4 + 1;
            } while (iVar4 < piVar2[2]);
          }
          iVar4 = -1;
LAB_100186b4:
          if (iVar4 != -1) {
            FUN_10018880(piVar2,iVar4);
          }
        }
        if (piVar3[6] != 0) {
          *(undefined4 *)(piVar3[6] + 0x3c) = 0;
          RwDestroyRaster((undefined4 *)piVar3[6]);
        }
        if (piVar3[7] != 0) {
          *(undefined4 *)(piVar3[7] + 0x3c) = 0;
          RwDestroyRaster((undefined4 *)piVar3[7]);
        }
        FUN_10037010(DAT_1005abf0,piVar3);
      }
    }
  }
  return (int *)0x0;
}


