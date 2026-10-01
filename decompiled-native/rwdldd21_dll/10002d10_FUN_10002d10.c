// 10002d10 FUN_10002d10 [Global]
// program: RWDLDD21.DLL

undefined4 FUN_10002d10(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined3 extraout_var_00;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  int local_4;
  
  iVar2 = FUN_100036e0(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  puVar9 = (ushort *)param_1[6];
  iVar2 = param_1[7];
  iVar7 = iVar2 - param_1[10] / 2;
  if (param_1[5] == 0) {
    iVar3 = 0;
    if (0 < param_1[8]) {
      do {
        iVar4 = 0;
        puVar10 = puVar9;
        if (0 < iVar2) {
          do {
            puVar9 = puVar10 + 1;
            if (*puVar10 == 0) {
              puVar5 = (undefined4 *)param_1[0xb];
              if (*param_1 == 3) {
                if (puVar5 == (undefined4 *)0x0) {
                  return 1;
                }
                if (puVar5[0xd] == 0) {
                  return 1;
                }
                piVar6 = *(int **)(puVar5[0xd] + 0x10);
                if (piVar6 == (int *)0x0) {
                  return 1;
                }
                iVar2 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
                if (iVar2 == -0x7789fe3e) {
                  FUN_10002fe0();
                  iVar2 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
                }
                if (iVar2 != 0) {
                  return 1;
                }
                param_1[6] = 0;
                param_1[0x10] = param_1[0x10] | 1;
                return 1;
              }
              if (puVar5 == (undefined4 *)0x0) {
                FUN_100033a0(param_1);
                FUN_100030f0((int)param_1);
                puVar5 = (undefined4 *)param_1[0xb];
                if (puVar5 == (undefined4 *)0x0) {
                  piVar6 = (int *)0x0;
                  goto LAB_10002f57;
                }
              }
              piVar6 = (int *)*puVar5;
LAB_10002f57:
              if (piVar6 != (int *)0x0) {
                iVar2 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
                if (iVar2 == -0x7789fe3e) {
                  FUN_10002fe0();
                  iVar2 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
                }
                if (iVar2 == 0) {
                  param_1[6] = 0;
                }
              }
              return 1;
            }
            iVar4 = iVar4 + 1;
            puVar10 = puVar9;
          } while (iVar4 < iVar2);
        }
        puVar9 = puVar9 + iVar7;
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[8]);
    }
  }
  else {
    local_4 = 0;
    uVar8 = param_1[5] & 0xffff;
    if (0 < param_1[8]) {
      do {
        iVar3 = iVar2;
        if (0 < iVar2) {
          do {
            uVar8 = (uint)((ushort)uVar8 & *puVar9);
            puVar9 = puVar9 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        if (uVar8 != param_1[5]) {
          puVar5 = (undefined4 *)param_1[0xb];
          if (*param_1 == 3) {
            if (puVar5 == (undefined4 *)0x0) {
              return 1;
            }
            if (puVar5[0xd] == 0) {
              return 1;
            }
            piVar6 = *(int **)(puVar5[0xd] + 0x10);
            if (piVar6 == (int *)0x0) {
              return 1;
            }
            iVar2 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
            if (iVar2 == -0x7789fe3e) {
              FUN_10002fe0();
              iVar2 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
            }
            if (iVar2 != 0) {
              return 1;
            }
            param_1[6] = 0;
            param_1[0x10] = param_1[0x10] | 1;
            return 1;
          }
          if (puVar5 == (undefined4 *)0x0) {
            FUN_100033a0(param_1);
            FUN_100030f0((int)param_1);
            puVar5 = (undefined4 *)param_1[0xb];
            if (puVar5 == (undefined4 *)0x0) {
              piVar6 = (int *)0x0;
              goto LAB_10002e5d;
            }
          }
          piVar6 = (int *)*puVar5;
LAB_10002e5d:
          if (piVar6 != (int *)0x0) {
            iVar2 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
            if (iVar2 == -0x7789fe3e) {
              FUN_10002fe0();
              iVar2 = (**(code **)(*piVar6 + 0x80))(piVar6,0);
            }
            if (iVar2 == 0) {
              param_1[6] = 0;
            }
          }
          return 1;
        }
        puVar9 = puVar9 + iVar7;
        local_4 = local_4 + 1;
      } while (local_4 < param_1[8]);
    }
  }
  puVar5 = (undefined4 *)param_1[0xb];
  if (*param_1 == 3) {
    if (puVar5 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar5[0xd] == 0) {
      return 0;
    }
    piVar6 = *(int **)(puVar5[0xd] + 0x10);
    if (piVar6 == (int *)0x0) {
      return 0;
    }
    bVar1 = FUN_10003050(piVar6);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0;
    }
    param_1[6] = 0;
    param_1[0x10] = param_1[0x10] | 1;
    return 0;
  }
  if (puVar5 == (undefined4 *)0x0) {
    FUN_100033a0(param_1);
    FUN_100030f0((int)param_1);
    puVar5 = (undefined4 *)param_1[0xb];
    if (puVar5 == (undefined4 *)0x0) {
      piVar6 = (int *)0x0;
      goto LAB_10002fb4;
    }
  }
  piVar6 = (int *)*puVar5;
LAB_10002fb4:
  if ((piVar6 != (int *)0x0) && (bVar1 = FUN_10003050(piVar6), CONCAT31(extraout_var_00,bVar1) != 0)
     ) {
    param_1[6] = 0;
  }
  return 0;
}


