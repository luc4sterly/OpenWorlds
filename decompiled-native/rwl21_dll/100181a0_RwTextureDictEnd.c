// 100181a0 RwTextureDictEnd [Global]
// program: RWL21.DLL

undefined4 RwTextureDictEnd(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int local_10;
  int local_c;
  undefined4 local_4;
  
                    /* 0x181a0  502  RwTextureDictEnd */
  if (DAT_1005abfc < 2) {
    FUN_1000cba0(0x22);
    return 0;
  }
  DAT_1005abfc = DAT_1005abfc + -1;
  local_4 = 1;
  local_c = 0;
  piVar2 = *(int **)(DAT_1005abf4 + DAT_1005abfc * 4);
  if (0 < piVar2[2]) {
    local_10 = 0;
    do {
      if (*(int *)(*piVar2 + local_10) != 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(*(int *)(*piVar2 + local_10));
      }
      **(undefined4 **)(*piVar2 + 4 + local_10) = 0;
      piVar3 = *(int **)(*piVar2 + 4 + local_10);
      if (piVar3 == (int *)0x0) {
        FUN_1000cba0(1);
LAB_10018341:
        local_4 = 0;
      }
      else {
        bVar5 = true;
        piVar4 = (int *)*piVar3;
        if (piVar4 != (int *)0x0) {
          iVar8 = piVar4[2];
          iVar9 = 0;
          piVar1 = piVar4 + 2;
          if (0 < iVar8) {
            puVar7 = (undefined4 *)(*piVar4 + 4);
            do {
              if ((int *)*puVar7 == piVar3) goto LAB_10018268;
              puVar7 = puVar7 + 2;
              iVar9 = iVar9 + 1;
            } while (iVar9 < iVar8);
          }
          iVar9 = -1;
LAB_10018268:
          if (((iVar9 != -1) && (-1 < iVar9)) && (iVar9 < iVar8)) {
            iVar8 = *(int *)(*piVar4 + iVar9 * 8);
            if (iVar8 != 0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar8);
            }
            iVar9 = iVar9 + 1;
            puVar7 = *(undefined4 **)(*piVar4 + -4 + iVar9 * 8);
            *puVar7 = 0;
            if (iVar9 < *piVar1) {
              iVar8 = iVar9 * 8;
              do {
                iVar9 = iVar9 + 1;
                ((undefined4 *)(*piVar4 + iVar8))[-2] = *(undefined4 *)(*piVar4 + iVar8);
                iVar6 = *piVar4 + iVar8;
                iVar8 = iVar8 + 8;
                *(undefined4 *)(iVar6 + -4) = *(undefined4 *)(iVar6 + 4);
              } while (iVar9 < *piVar1);
            }
            *piVar1 = *piVar1 + -1;
            if (puVar7 != (undefined4 *)0x0) goto LAB_100182db;
          }
          bVar5 = false;
        }
LAB_100182db:
        if (piVar3[6] != 0) {
          *(undefined4 *)(piVar3[6] + 0x3c) = 0;
          iVar8 = RwDestroyRaster((undefined4 *)piVar3[6]);
          if (iVar8 == 0) {
            bVar5 = false;
          }
        }
        if (piVar3[7] != 0) {
          *(undefined4 *)(piVar3[7] + 0x3c) = 0;
          iVar8 = RwDestroyRaster((undefined4 *)piVar3[7]);
          if (iVar8 == 0) {
            bVar5 = false;
          }
        }
        FUN_10037010(DAT_1005abf0,piVar3);
        if (!bVar5) goto LAB_10018341;
      }
      local_10 = local_10 + 8;
      local_c = local_c + 1;
    } while (local_c < piVar2[2]);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(*piVar2);
  FUN_10037010(DAT_1005abec,piVar2);
  return local_4;
}


