// 100424f0 FUN_100424f0 [Global]
// program: RWL21.DLL

int FUN_100424f0(int *param_1,float param_2,float param_3,float param_4)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int local_8;
  int local_4;
  
  iVar3 = param_1[2];
  if (param_1[1] <= iVar3) {
    piVar2 = FUN_10041cb0(iVar3 / 2 + iVar3);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    iVar3 = FUN_10042410((int)piVar2,(int)param_1);
    if (iVar3 == 0) {
      if ((piVar2 != (int *)0x0) && (*piVar2 == 0)) {
        iVar3 = 8;
        if (8 < piVar2[2]) {
          piVar4 = piVar2 + 0x107;
          do {
            if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
              if (*(short *)((int)piVar4 + -2) == 6) {
                FUN_10037010(DAT_1005b8d0,(undefined4 *)*piVar4);
              }
              else {
                (**(code **)(PTR_DAT_1005b69c + 0x358))();
              }
            }
            piVar4 = piVar4 + 0x1d;
            iVar3 = iVar3 + 1;
          } while (iVar3 < piVar2[2]);
        }
        (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar2);
      }
      return 0;
    }
    iVar3 = 8;
    if (8 < param_1[2]) {
      piVar4 = piVar2 + 0xeb;
      piVar7 = param_1 + 0xeb;
      do {
        piVar8 = piVar7;
        piVar9 = piVar4;
        for (iVar5 = 0x1d; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar9 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar9 = piVar9 + 1;
        }
        piVar4 = piVar4 + 0x1d;
        iVar3 = iVar3 + 1;
        piVar7[0x1c] = 0;
        piVar7 = piVar7 + 0x1d;
      } while (iVar3 < param_1[2]);
    }
    local_4 = 0;
    iVar3 = *param_1;
    if (0 < **(int **)(iVar3 + 0x98)) {
      local_8 = 0;
      do {
        iVar5 = *(int *)(*(int *)(iVar3 + 0x98) + 8 + local_8);
        iVar6 = *(int *)(iVar5 + 0x2c);
        if (iVar6 == iVar5) {
          if (iVar5 != 0) {
            iVar6 = 0;
            if (*(char *)(iVar5 + 0x3a) != '\0') {
              piVar4 = (int *)(iVar5 + 0x3c);
              do {
                iVar6 = iVar6 + 1;
                *piVar4 = (int)(piVar2 + (((*piVar4 - *(int *)(*(int *)(iVar5 + 0x34) + 0x88)) +
                                          -0xc) / 0x74) * 0x1d + 3);
                piVar4 = piVar4 + 1;
              } while (iVar6 < (int)(uint)*(byte *)(iVar5 + 0x3a));
            }
            iVar5 = *(int *)(iVar5 + 0x30);
LAB_100426ca:
            FUN_10042820(iVar5,(int)piVar2);
          }
        }
        else if ((*(int *)(iVar5 + 0x30) == 0) && (iVar6 != 0)) {
          iVar5 = 0;
          if (*(char *)(iVar6 + 0x3a) != '\0') {
            piVar4 = (int *)(iVar6 + 0x3c);
            do {
              iVar5 = iVar5 + 1;
              *piVar4 = (int)(piVar2 + (((*piVar4 - *(int *)(*(int *)(iVar6 + 0x34) + 0x88)) + -0xc)
                                       / 0x74) * 0x1d + 3);
              piVar4 = piVar4 + 1;
            } while (iVar5 < (int)(uint)*(byte *)(iVar6 + 0x3a));
          }
          iVar5 = *(int *)(iVar6 + 0x30);
          goto LAB_100426ca;
        }
        local_8 = local_8 + 4;
        local_4 = local_4 + 1;
      } while (local_4 < **(int **)(iVar3 + 0x98));
    }
    *param_1 = 0;
    if (param_1 != (int *)0x0) {
      iVar5 = 8;
      if (8 < param_1[2]) {
        piVar4 = param_1 + 0x107;
        do {
          if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
            if (*(short *)((int)piVar4 + -2) == 6) {
              FUN_10037010(DAT_1005b8d0,(undefined4 *)*piVar4);
            }
            else {
              (**(code **)(PTR_DAT_1005b69c + 0x358))();
            }
          }
          piVar4 = piVar4 + 0x1d;
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_1[2]);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
    }
    *(int **)(iVar3 + 0x88) = piVar2;
    *piVar2 = iVar3;
    param_1 = piVar2;
  }
  iVar3 = param_1[2];
  if (iVar3 < param_1[1]) {
    param_1[2] = iVar3 + 1;
    pfVar1 = (float *)(param_1 + iVar3 * 0x1d + 3);
    iVar3 = *(int *)(PTR_DAT_1005b69c + 0x2c8);
    *(undefined1 *)(pfVar1 + 0x12) = 0x20;
    if (iVar3 == 0) {
      *(undefined1 *)(pfVar1 + 0x12) = 0;
    }
    *pfVar1 = param_2;
    pfVar1[1] = param_3;
    pfVar1[2] = param_4;
    FUN_100421e0((int)param_1,pfVar1);
    if (*param_1 != 0) {
      *(undefined4 *)(*param_1 + 200) = 0;
      *(undefined4 *)(*param_1 + 0xc4) = 0;
    }
    return ((int)pfVar1 + (-0xc - (int)param_1)) / 0x74 + -7;
  }
  return 0;
}


