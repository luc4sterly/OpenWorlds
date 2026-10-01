// 10033750 FUN_10033750 [Global]
// program: RWL21.DLL

undefined4 FUN_10033750(void)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int *extraout_ECX;
  int *piVar8;
  int extraout_EDX;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  float10 fVar13;
  float10 extraout_ST0;
  float fStack00000004;
  float fStack00000008;
  int *piStack0000000c;
  float fStack00000010;
  int iStack00000014;
  int iStack00000018;
  int *piStack00000020;
  float fStack00000024;
  int *piStack00000028;
  int *in_stack_0000002c;
  float in_stack_00000fcc;
  float fVar14;
  undefined4 in_stack_00000fd0;
  undefined4 in_stack_00000fd4;
  int in_stack_00001f70;
  
  FUN_10045470();
  if (**(int **)(in_stack_00001f70 + 0x98) == 0) {
    uVar3 = 1;
  }
  else {
    piVar4 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))();
    fStack00000004 = (float)**(int **)(in_stack_00001f70 + 0x98);
    if (piVar4 == (int *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      if (0 < (int)fStack00000004) {
        iVar10 = 0;
        piVar7 = piVar4;
        do {
          iVar9 = *(int *)(*(int *)(in_stack_00001f70 + 0x98) + 8 + iVar10);
          puVar5 = FUN_10037030(DAT_1005af00);
          if (puVar5 == (undefined4 *)0x0) {
            FUN_1000cba0(3);
            *piVar7 = 0;
          }
          else {
            puVar5[9] = 0;
            puVar5[8] = iVar9;
            *puVar5 = 0;
            puVar5[1] = 0;
            puVar5[2] = 0;
            fVar13 = FUN_10001100(iVar9,(float *)&stack0x0000002c,(float *)&stack0x00000fcc);
            puVar5[7] = (float)fVar13;
            puVar5[3] = in_stack_00000fcc;
            puVar5[4] = in_stack_00000fd0;
            puVar5[5] = in_stack_00000fd4;
            RwDotProduct(&stack0x0000002c,in_stack_00000fd4);
            puVar5[6] = (float)extraout_ST0;
            *piVar7 = (int)puVar5;
          }
          piVar7 = piVar7 + 1;
          iVar10 = iVar10 + 4;
          fStack00000004 = (float)((int)fStack00000004 + -1);
        } while (fStack00000004 != 0.0);
      }
      piStack00000020 = (int *)0x0;
      fStack00000004 = **(float **)(in_stack_00001f70 + 0x98);
      iVar10 = in_stack_00001f70;
      fStack00000010 = fStack00000004;
      piStack00000028 = piVar4;
      if (0 < (int)fStack00000004) {
        do {
          piVar7 = (int *)*piStack00000028;
          piVar6 = piVar7;
          if (piStack00000020 != (int *)0x0) {
            bVar2 = false;
            piStack0000000c = piStack00000020;
            piVar8 = piStack00000020;
            do {
              iStack00000014 = 0;
              iStack00000018 = 0;
              fStack00000008 = 0.0;
              fStack00000024 = 0.0;
              if (piStack0000000c != (int *)0x0) {
                puVar5 = &stack0x0000002c;
                puVar11 = (undefined4 *)&stack0x00000fcc;
                piVar6 = piStack0000000c;
                do {
                  iVar10 = FUN_10033cc0(piVar8,iVar10,(int)piVar6,(int)piVar7);
                  if (iVar10 == -1) {
                    *puVar11 = piVar6;
                    puVar11 = puVar11 + 1;
                    fStack00000024 = (float)piVar6[7] + fStack00000024;
                    iStack00000018 = iStack00000018 + 1;
                  }
                  else if (iVar10 == 1) {
                    *puVar5 = piVar6;
                    puVar5 = puVar5 + 1;
                    fStack00000008 = (float)piVar6[7] + fStack00000008;
                    iStack00000014 = iStack00000014 + 1;
                  }
                  else if (iVar10 == 2) {
                    piVar6[9] = 1;
                    piVar7[9] = 1;
                  }
                  piVar6 = (int *)piVar6[2];
                  piVar8 = extraout_ECX;
                  iVar10 = extraout_EDX;
                } while (piVar6 != (int *)0x0);
              }
              if ((iStack00000018 == 0) && (iStack00000014 == 0)) {
                iVar9 = 3;
              }
              else if (fStack00000024 <= fStack00000008) {
                if (0 < iStack00000018) {
                  piVar8 = (int *)(&stack0x00000fcc + iStack00000018 * 4);
                  iVar10 = 1;
                  do {
                    piVar6 = piVar8 + -1;
                    piVar8 = piVar8 + -1;
                    *(undefined4 *)(*piVar6 + 0x24) = 1;
                  } while (piVar8 != (int *)&stack0x00000fcc);
                  piVar7[9] = 1;
                }
                iVar9 = 1;
              }
              else {
                if (0 < iStack00000014) {
                  piVar8 = (int *)(&stack0x0000002c + iStack00000014);
                  iVar10 = 1;
                  do {
                    piVar6 = piVar8 + -1;
                    piVar8 = piVar8 + -1;
                    *(undefined4 *)(*piVar6 + 0x24) = 1;
                  } while ((int **)piVar8 != &stack0x0000002c);
                  piVar7[9] = 1;
                }
                iVar9 = -1;
              }
              if (iVar9 == -1) {
                piVar6 = (int *)*piStack0000000c;
                if ((int *)*piStack0000000c == (int *)0x0) {
                  *piStack0000000c = (int)piVar7;
                  goto LAB_10033a2c;
                }
              }
              else if (iVar9 == 1) {
                piVar8 = piStack0000000c + 1;
                piVar6 = (int *)piStack0000000c[1];
                if ((int *)piStack0000000c[1] == (int *)0x0) {
                  *piVar8 = (int)piVar7;
                  goto LAB_10033a2c;
                }
              }
              else {
                piVar6 = piStack0000000c;
                if (iVar9 == 3) {
                  piVar8 = (int *)piStack0000000c[2];
                  piVar7[2] = (int)piVar8;
                  piStack0000000c[2] = (int)piVar7;
LAB_10033a2c:
                  bVar2 = true;
                  piVar6 = piStack0000000c;
                }
              }
              piStack0000000c = piVar6;
              piVar6 = piStack00000020;
            } while (!bVar2);
          }
          piStack00000020 = piVar6;
          fStack00000004 = (float)((int)fStack00000004 + -1);
          piStack00000028 = piStack00000028 + 1;
        } while (fStack00000004 != 0.0);
      }
      piVar7 = piStack00000020;
      iVar10 = 0;
      piVar6 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))();
      if (piVar6 == (int *)0x0) {
        FUN_1000cba0(3);
      }
      else {
        iVar9 = 0;
        piVar8 = piVar6;
        while( true ) {
          for (; piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
            *piVar8 = (int)piVar7;
            piVar8 = piVar8 + 1;
          }
          piVar8 = piVar8 + -1;
          if (piVar8 < piVar6) break;
          iVar1 = *piVar8;
          if (iVar9 == 0) {
            iVar10 = *(int *)(iVar1 + 0x24);
          }
          if (iVar1 != 0) {
            piVar7 = piVar4 + iVar9;
            iVar12 = iVar1;
            do {
              if (*(int *)(iVar12 + 0x24) == iVar10) {
                *piVar7 = iVar12;
                piVar7 = piVar7 + 1;
                iVar9 = iVar9 + 1;
              }
              iVar12 = *(int *)(iVar12 + 8);
            } while (iVar12 != 0);
          }
          if (iVar1 != 0) {
            piVar7 = piVar4 + iVar9;
            iVar12 = iVar1;
            do {
              if (*(int *)(iVar12 + 0x24) != iVar10) {
                *piVar7 = iVar12;
                piVar7 = piVar7 + 1;
                iVar9 = iVar9 + 1;
              }
              iVar12 = *(int *)(iVar12 + 8);
            } while (iVar12 != 0);
          }
          iVar10 = *(int *)(piVar4[iVar9 + -1] + 0x24);
          piVar7 = *(int **)(iVar1 + 4);
        }
        iVar10 = 1;
        in_stack_0000002c = piVar6;
        (**(code **)(PTR_DAT_1005b69c + 0x358))();
      }
      if (iVar10 == 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))();
      }
      else {
        puVar5 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))();
        if (puVar5 == (undefined4 *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))();
        }
        else {
          *(undefined4 **)(in_stack_00001f70 + 0xac) = puVar5;
          piVar7 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))();
          if (piVar7 != (int *)0x0) {
            *(int **)(in_stack_00001f70 + 0xa8) = piVar7;
            iVar10 = 0;
            *(undefined4 *)(in_stack_00001f70 + 0xa4) = *(undefined4 *)(*piVar4 + 0x24);
            in_stack_0000002c = *(int **)(*piVar4 + 0x24);
            fStack00000004 = 0.0;
            piVar6 = piVar7;
            fVar14 = fStack00000010;
            if (0 < (int)fStack00000010) {
              do {
                if ((int *)*(float *)(*piVar4 + 0x24) != in_stack_0000002c) {
                  *piVar6 = iVar10;
                  piVar6 = piVar6 + 1;
                  iVar10 = 0;
                  fStack00000004 = (float)((int)fStack00000004 + 1);
                  in_stack_0000002c = *(int **)(*piVar4 + 0x24);
                }
                iVar10 = iVar10 + 1;
                *puVar5 = *(undefined4 *)(*piVar4 + 0x20);
                FUN_10037010(DAT_1005af00,(undefined4 *)*piVar4);
                fVar14 = (float)((int)fVar14 + -1);
                piVar4 = piVar4 + 1;
                puVar5 = puVar5 + 1;
              } while (fVar14 != 0.0);
            }
            piVar7[(int)fStack00000004] = iVar10;
            piVar7[(int)fStack00000004 + 1] = 0;
            (**(code **)(PTR_DAT_1005b69c + 0x358))();
            return 1;
          }
          *(undefined4 *)(in_stack_00001f70 + 0xac) = 0;
          (**(code **)(PTR_DAT_1005b69c + 0x358))();
          (**(code **)(PTR_DAT_1005b69c + 0x358))();
        }
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


