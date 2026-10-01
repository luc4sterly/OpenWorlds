// 10001190 FUN_10001190 [Global]
// program: RWDLDD21.DLL

int FUN_10001190(int param_1,uint param_2,undefined4 *param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  int *unaff_EBP;
  int iVar12;
  int iVar13;
  int *piVar14;
  int unaff_EDI;
  int *piVar15;
  int *piStack_180;
  int *local_15c;
  undefined4 *local_158;
  undefined4 *local_154;
  int aiStack_144 [6];
  int iStack_12c;
  undefined4 auStack_fc [8];
  undefined4 uStack_dc;
  int local_d8 [20];
  undefined4 auStack_88 [6];
  undefined4 uStack_70;
  int iStack_6c;
  undefined4 uStack_20;
  
  iVar7 = *(int *)(param_1 + 0x10);
  piVar11 = (int *)&DAT_10038a98;
  if ((param_2 & 8) == 0) {
    piVar11 = (int *)&DAT_10038a20;
  }
  *param_3 = 0;
  local_158 = (undefined4 *)(*(undefined4 **)(param_1 + 0x18))[0xb];
  if (local_158 == (undefined4 *)0x0) {
    iVar12 = -1;
    FUN_100033a0(*(undefined4 **)(param_1 + 0x18));
    iVar10 = DAT_10036180;
    iVar6 = *(int *)(param_1 + 0x18);
    local_158 = *(undefined4 **)(iVar6 + 0x2c);
    iVar8 = 0;
    if (0 < DAT_10036180) {
      do {
        if (iVar6 == DAT_1003617c[iVar8]) goto LAB_100012e5;
        if ((iVar12 == -1) && (DAT_1003617c[iVar8] == 0)) {
          iVar12 = iVar8;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < DAT_10036180);
    }
    if (iVar12 == -1) {
      iVar12 = iVar10;
      if ((DAT_1003617c == (undefined4 *)0x0) || (DAT_10036180 == 0)) {
        puVar3 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))();
        if (puVar3 != (undefined4 *)0x0) {
          puVar9 = puVar3;
          for (iVar10 = 0x80; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
          DAT_10036180 = 0x80;
          DAT_1003617c = puVar3;
        }
      }
      else {
        puVar3 = (undefined4 *)(**(code **)(DAT_100394fc + 0x354))();
        if (puVar3 != (undefined4 *)0x0) {
          if (DAT_10036180 != 0 && SBORROW4(DAT_10036180 * 2,DAT_10036180) == DAT_10036180 < 0) {
            puVar9 = puVar3 + DAT_10036180;
            iVar10 = DAT_10036180;
            do {
              *puVar9 = 0;
              puVar9 = puVar9 + 1;
              iVar10 = iVar10 + 1;
            } while (iVar10 < DAT_10036180 * 2);
          }
          DAT_10036180 = DAT_10036180 * 2;
          DAT_1003617c = puVar3;
        }
      }
    }
    DAT_1003617c[iVar12] = iVar6;
  }
LAB_100012e5:
  local_154 = (undefined4 *)0x0;
  if (piVar11[0xb] != 0) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      local_154 = *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x2c);
    }
    if (((piVar11[0xb] != 0) && (*(undefined4 **)(param_1 + 0x1c) != (undefined4 *)0x0)) &&
       (local_154 == (undefined4 *)0x0)) {
      iVar12 = -1;
      FUN_100033a0(*(undefined4 **)(param_1 + 0x1c));
      iVar10 = DAT_10036180;
      iVar6 = *(int *)(param_1 + 0x1c);
      local_154 = *(undefined4 **)(iVar6 + 0x2c);
      iVar8 = 0;
      if (0 < DAT_10036180) {
        do {
          if (iVar6 == DAT_1003617c[iVar8]) goto LAB_10001437;
          if ((iVar12 == -1) && (DAT_1003617c[iVar8] == 0)) {
            iVar12 = iVar8;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < DAT_10036180);
      }
      if (iVar12 == -1) {
        iVar12 = iVar10;
        if ((DAT_1003617c == (undefined4 *)0x0) || (DAT_10036180 == 0)) {
          puVar3 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))();
          if (puVar3 != (undefined4 *)0x0) {
            puVar9 = puVar3;
            for (iVar10 = 0x80; iVar10 != 0; iVar10 = iVar10 + -1) {
              *puVar9 = 0;
              puVar9 = puVar9 + 1;
            }
            DAT_10036180 = 0x80;
            DAT_1003617c = puVar3;
          }
        }
        else {
          puVar3 = (undefined4 *)(**(code **)(DAT_100394fc + 0x354))();
          if (puVar3 != (undefined4 *)0x0) {
            if (DAT_10036180 != 0 && SBORROW4(DAT_10036180 * 2,DAT_10036180) == DAT_10036180 < 0) {
              puVar9 = puVar3 + DAT_10036180;
              iVar10 = DAT_10036180;
              do {
                *puVar9 = 0;
                puVar9 = puVar9 + 1;
                iVar10 = iVar10 + 1;
              } while (iVar10 < DAT_10036180 * 2);
            }
            DAT_10036180 = DAT_10036180 * 2;
            DAT_1003617c = puVar3;
          }
        }
      }
      DAT_1003617c[iVar12] = iVar6;
    }
  }
LAB_10001437:
  if ((local_158[9] == 0) || (local_15c = local_158 + 0xb, local_158[0xb] == 0)) {
    uVar4 = FUN_10002d10(*(int **)(param_1 + 0x18));
    local_158[10] = uVar4;
    if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
      uVar5 = FUN_10002d10(*(int **)(param_1 + 0x1c));
      local_158[10] = local_158[10] | uVar5;
    }
    local_15c = local_158 + 0xb;
    local_158[9] = *(int *)(*(int *)(param_1 + 0x18) + 0x20) /
                   *(int *)(*(int *)(param_1 + 0x18) + 0x1c);
    iVar6 = (**(code **)(DAT_100394fc + 0x34c))();
    *local_15c = iVar6;
    if (iVar6 == 0) {
      return 0;
    }
    piVar14 = aiStack_144;
    for (iVar6 = 0x1b; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar14 = 0;
      piVar14 = piVar14 + 1;
    }
    aiStack_144[0] = 0x6c;
    aiStack_144[1] = 0x1007;
    uStack_dc = 0x1800;
    if (local_154 != (undefined4 *)0x0) {
      aiStack_144[1] = 0x21007;
      uStack_dc = 0x401808;
      iStack_12c = piVar11[10];
    }
    aiStack_144[2] = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x1c);
    puVar3 = &DAT_10038b08;
    puVar9 = auStack_fc;
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar9 = puVar9 + 1;
    }
    iVar6 = 0;
    local_158[0xc] = 0;
    aiStack_144[3] = aiStack_144[2];
    if (0 < (int)local_158[9]) {
      iVar10 = 0;
      do {
        *(int *)(*local_15c + iVar10) = *(int *)(*(int *)(param_1 + 0x18) + 0x1c) * iVar6;
        *(undefined4 *)(*local_15c + 4 + iVar10) = 0xffffffff;
        piVar14 = aiStack_144;
        piStack_180 = (int *)0x1000158f;
        iVar12 = (**(code **)(*DAT_10036030 + 0x18))();
        if (iVar12 != 0) {
          if (-1 < iVar6 + -1) {
            iVar7 = (iVar6 + -1) * 0x10;
            do {
              piStack_180 = *(int **)(*unaff_EBP + 0xc + iVar7);
              if (piStack_180 != (int *)0x0) {
                (**(code **)(*piStack_180 + 8))();
                *(undefined4 *)(*unaff_EBP + 0xc + iVar7) = 0;
              }
              piStack_180 = *(int **)(*unaff_EBP + 8 + iVar7);
              if (piStack_180 != (int *)0x0) {
                (**(code **)(*piStack_180 + 8))();
                *(undefined4 *)(*unaff_EBP + 8 + iVar7) = 0;
              }
              iVar7 = iVar7 + -0x10;
            } while (-1 < iVar7);
          }
          piStack_180 = (int *)*unaff_EBP;
          (**(code **)(DAT_100394fc + 0x358))();
          *unaff_EBP = 0;
          *(undefined4 *)(unaff_EDI + 0x24) = 0;
          return 0;
        }
        local_15c = (int *)0x0;
        piStack_180 = (int *)&stack0xfffffea0;
        piVar15 = *(int **)(*unaff_EBP + 8 + iVar10);
        iVar12 = (**(code **)(*piVar15 + 0x74))(piVar15,8);
        if (iVar12 == -0x7789fe3e) {
          piVar15 = (int *)&LAB_10001b40;
          puVar3 = auStack_88;
          for (iVar12 = 0x1b; iVar12 != 0; iVar12 = iVar12 + -1) {
            *puVar3 = 0;
            puVar3 = puVar3 + 1;
          }
          auStack_88[0] = 0x6c;
          auStack_88[1] = 1;
          uStack_20 = 0x4000;
          (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_88,0);
          if (DAT_10036038 != (int *)0x0) {
            (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
          }
          if (DAT_1003603c != DAT_10036038) {
            (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
          }
          piVar15 = *(int **)(*piVar15 + 8 + iVar10);
          (**(code **)(*piVar15 + 0x74))(piVar15,8,&piStack_180);
        }
        puVar3 = *(undefined4 **)(*piVar14 + iVar10 + 8);
        iVar12 = (**(code **)*puVar3)(puVar3,&DAT_10034190,*piVar14 + iVar10 + 0xc);
        if (iVar12 == -0x7789fe3e) {
          piVar15 = (int *)&LAB_10001b40;
          piVar14 = local_d8;
          for (iVar12 = 0x1b; iVar12 != 0; iVar12 = iVar12 + -1) {
            *piVar14 = 0;
            piVar14 = piVar14 + 1;
          }
          local_d8[0] = 0x6c;
          local_d8[1] = 1;
          uStack_70 = 0x4000;
          piStack_180 = DAT_10036030;
          (**(code **)(*DAT_10036030 + 0x24))();
          if (DAT_10036038 != (int *)0x0) {
            (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
          }
          if (DAT_1003603c != DAT_10036038) {
            (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
          }
          puVar3 = *(undefined4 **)(*piVar15 + iVar10 + 8);
          iVar12 = (**(code **)*puVar3)(puVar3,&DAT_10034190,*piVar15 + iVar10 + 0xc);
        }
        if (iVar12 != 0) {
          piVar11 = *(int **)(iRam00000000 + 8 + iVar6 * 0x10);
          if (piVar11 != (int *)0x0) {
            (**(code **)(*piVar11 + 8))();
            *(undefined4 *)(iRam00000000 + 8 + iVar6 * 0x10) = 0;
          }
          if (-1 < iVar6 + -1) {
            iVar7 = (iVar6 + -1) * 0x10;
            do {
              piVar11 = *(int **)(iRam00000000 + 0xc + iVar7);
              if (piVar11 != (int *)0x0) {
                (**(code **)(*piVar11 + 8))();
                *(undefined4 *)(iRam00000000 + 0xc + iVar7) = 0;
              }
              piVar11 = *(int **)(iRam00000000 + 8 + iVar7);
              if (piVar11 != (int *)0x0) {
                (**(code **)(*piVar11 + 8))();
                *(undefined4 *)(iRam00000000 + 8 + iVar7) = 0;
              }
              iVar7 = iVar7 + -0x10;
            } while (-1 < iVar7);
          }
          (**(code **)(DAT_100394fc + 0x358))();
          iRam00000000 = 0;
          local_158[9] = 0;
          return 0;
        }
        iVar10 = iVar10 + 0x10;
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)local_158[9]);
    }
    iVar6 = FUN_10001b60(local_158,local_154,piVar11);
    if (iVar6 == 0) {
      return 0;
    }
  }
  local_d8[0] = iVar7 * 0x10;
  iVar7 = *(int *)(*local_15c + 4 + local_d8[0]);
  if (iVar7 != -1) {
    iVar7 = piVar11[3] + iVar7 * 0x18;
    iVar6 = *(int *)(iVar7 + 8) + 1;
    *(int *)(iVar7 + 8) = iVar6;
    if (piVar11[8] < iVar6) {
      piVar11[8] = iVar6;
    }
    iVar6 = piVar11[4];
    piVar11[4] = iVar6 + 1;
    if (piVar11[5] < iVar6 + 1) {
      iVar6 = piVar11[3];
      iVar10 = piVar11[7];
      iVar12 = piVar11[6];
      iVar8 = piVar11[8];
      iVar13 = 0;
      if (0 < piVar11[1]) {
        do {
          iVar2 = *(int *)(iVar6 + 8);
          *(int *)(iVar6 + 8) = iVar10;
          if (iVar8 >> 1 <= iVar2) {
            *(int *)(iVar6 + 8) = iVar12;
          }
          iVar6 = iVar6 + 0x18;
          iVar13 = iVar13 + 1;
          iStack_6c = iVar7;
        } while (iVar13 < piVar11[1]);
      }
      piVar11[8] = iVar12;
      piVar11[4] = 0;
    }
    if (((*(int **)(param_1 + 0x18))[0x10] & 1U) != 0) {
      uVar4 = FUN_10002d10(*(int **)(param_1 + 0x18));
      local_158[10] = uVar4;
      if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
        uVar5 = FUN_10002d10(*(int **)(param_1 + 0x1c));
        local_158[10] = local_158[10] | uVar5;
      }
      iVar6 = FUN_10001b60(local_158,local_154,piVar11);
      if (iVar6 == 0) {
        return 0;
      }
      piStack_180 = (int *)0x1000195e;
      iVar6 = FUN_10002880(*(int **)(iVar7 + 0x10),*(int **)(*local_15c + 8 + local_d8[0]),
                           (uint)(local_154 != (undefined4 *)0x0),piVar11);
      if (iVar6 == 0) {
        return 0;
      }
      puVar1 = (uint *)(*(int *)(param_1 + 0x18) + 0x40);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
    *(undefined4 *)(iVar7 + 0xc) = 1;
    *param_3 = local_158[10];
    return *(int *)(iVar7 + 0x14);
  }
  if (DAT_10038ac8 == 0) {
    FUN_10002a30((undefined4 *)&DAT_10038a98);
  }
  if (DAT_10038a50 == 0) {
    FUN_10002a30((undefined4 *)&DAT_10038a20);
  }
  do {
    iVar7 = piVar11[8];
    iVar10 = 0;
    iVar6 = -1;
    if (0 < piVar11[1]) {
      piVar14 = (int *)(piVar11[3] + 8);
      iVar12 = -1;
      do {
        iVar6 = iVar12;
        if (piVar14[1] == 0) {
          iVar6 = iVar10;
          if (piVar14[-1] == 0) break;
          if (piVar11[8] < *piVar14) {
            piVar11[8] = *piVar14;
          }
          iVar6 = iVar12;
          if (*piVar14 <= iVar7) {
            iVar7 = *piVar14;
            iVar6 = iVar10;
          }
        }
        piVar14 = piVar14 + 6;
        iVar10 = iVar10 + 1;
        iVar12 = iVar6;
      } while (iVar10 < piVar11[1]);
    }
    if (iVar6 != -1) {
      iVar7 = iVar6 * 0x18;
      puVar3 = *(undefined4 **)(piVar11[3] + iVar6 * 0x18);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = 0xffffffff;
        *(undefined4 *)(piVar11[3] + iVar7) = 0;
        *(undefined4 *)(piVar11[3] + 4 + iVar7) = 0;
      }
      piVar14 = (int *)(piVar11[3] + iVar7);
      if (((*(int **)(param_1 + 0x18))[0x10] & 1U) != 0) {
        uVar4 = FUN_10002d10(*(int **)(param_1 + 0x18));
        local_158[10] = uVar4;
        if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
          uVar5 = FUN_10002d10(*(int **)(param_1 + 0x1c));
          local_158[10] = local_158[10] | uVar5;
        }
        iVar7 = FUN_10001b60(local_158,local_154,piVar11);
        if (iVar7 == 0) {
          return 0;
        }
        puVar1 = (uint *)(*(int *)(param_1 + 0x18) + 0x40);
        *puVar1 = *puVar1 & 0xfffffffe;
      }
      piStack_180 = (int *)0x10001ad7;
      iVar7 = FUN_10002880((int *)piVar14[4],*(int **)(*local_15c + 8 + local_d8[0]),
                           (uint)(local_154 != (undefined4 *)0x0),piVar11);
      if (iVar7 == 0) {
        return 0;
      }
      piVar15 = (int *)(*local_15c + 4 + local_d8[0]);
      *piVar14 = (int)piVar15;
      *piVar15 = iVar6;
      local_158[0xc] = piVar11;
      piVar14[1] = *(int *)(param_1 + 0x18);
      iVar7 = piVar11[9];
      piVar14[2] = iVar7;
      if (piVar11[8] < iVar7) {
        piVar11[8] = iVar7;
      }
      piVar14[3] = 1;
      *param_3 = local_158[10];
      return piVar14[5];
    }
    FUN_10001080(DAT_1003a024);
  } while( true );
}


