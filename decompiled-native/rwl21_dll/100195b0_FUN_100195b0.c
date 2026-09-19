// 100195b0 FUN_100195b0 [Global]
// programa: RWL21.DLL

undefined4 FUN_100195b0(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_14;
  int local_c;
  int local_8;
  int local_4;
  
  local_4 = 0;
  if (0 < DAT_1005abfc) {
    local_8 = 0;
    do {
      local_c = 0;
      piVar2 = *(int **)(DAT_1005abf4 + local_8);
      if (0 < piVar2[2]) {
        local_14 = 0;
        do {
          if (*(int *)(*piVar2 + local_14) != 0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(*(int *)(*piVar2 + local_14));
          }
          **(undefined4 **)(*piVar2 + 4 + local_14) = 0;
          piVar3 = *(int **)(*piVar2 + 4 + local_14);
          if (piVar3 == (int *)0x0) {
            FUN_1000cba0(1);
          }
          else {
            piVar4 = (int *)*piVar3;
            if (piVar4 != (int *)0x0) {
              iVar7 = piVar4[2];
              iVar8 = 0;
              piVar1 = piVar4 + 2;
              if (0 < iVar7) {
                puVar5 = (undefined4 *)(*piVar4 + 4);
                do {
                  if ((int *)*puVar5 == piVar3) goto LAB_1001967d;
                  puVar5 = puVar5 + 2;
                  iVar8 = iVar8 + 1;
                } while (iVar8 < iVar7);
              }
              iVar8 = -1;
LAB_1001967d:
              if (((iVar8 != -1) && (-1 < iVar8)) && (iVar8 < iVar7)) {
                iVar7 = *(int *)(*piVar4 + iVar8 * 8);
                if (iVar7 != 0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar7);
                }
                iVar8 = iVar8 + 1;
                **(undefined4 **)(*piVar4 + -4 + iVar8 * 8) = 0;
                if (iVar8 < *piVar1) {
                  iVar7 = iVar8 * 8;
                  do {
                    iVar8 = iVar8 + 1;
                    ((undefined4 *)(*piVar4 + iVar7))[-2] = *(undefined4 *)(*piVar4 + iVar7);
                    iVar6 = *piVar4 + iVar7;
                    iVar7 = iVar7 + 8;
                    *(undefined4 *)(iVar6 + -4) = *(undefined4 *)(iVar6 + 4);
                  } while (iVar8 < *piVar1);
                }
                *piVar1 = *piVar1 + -1;
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
          local_14 = local_14 + 8;
          local_c = local_c + 1;
        } while (local_c < piVar2[2]);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*piVar2);
      FUN_10037010(DAT_1005abec,piVar2);
      local_8 = local_8 + 4;
      local_4 = local_4 + 1;
    } while (local_4 < DAT_1005abfc);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(DAT_1005abf4);
  FUN_100370f0();
  FUN_100370f0();
  return 1;
}


