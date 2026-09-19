// 10016b00 RwDestroyTexture [Global]
// programa: RWL21.DLL

undefined4 RwDestroyTexture(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_8;
  
                    /* 0x16b00  68  RwDestroyTexture */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  local_8 = 1;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    iVar6 = piVar2[2];
    iVar7 = 0;
    piVar1 = piVar2 + 2;
    if (0 < iVar6) {
      piVar4 = (int *)(*piVar2 + 4);
      do {
        if ((int *)*piVar4 == param_1) goto LAB_10016b4a;
        piVar4 = piVar4 + 2;
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar6);
    }
    iVar7 = -1;
LAB_10016b4a:
    if (((iVar7 != -1) && (-1 < iVar7)) && (iVar7 < iVar6)) {
      iVar6 = *(int *)(*piVar2 + iVar7 * 8);
      if (iVar6 != 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar6);
      }
      iVar7 = iVar7 + 1;
      puVar3 = *(undefined4 **)(*piVar2 + -4 + iVar7 * 8);
      *puVar3 = 0;
      if (iVar7 < *piVar1) {
        iVar6 = iVar7 * 8;
        do {
          iVar7 = iVar7 + 1;
          ((undefined4 *)(*piVar2 + iVar6))[-2] = *(undefined4 *)(*piVar2 + iVar6);
          iVar5 = *piVar2 + iVar6;
          iVar6 = iVar6 + 8;
          *(undefined4 *)(iVar5 + -4) = *(undefined4 *)(iVar5 + 4);
        } while (iVar7 < *piVar1);
      }
      *piVar1 = *piVar1 + -1;
      if (puVar3 != (undefined4 *)0x0) goto LAB_10016bc1;
    }
    local_8 = 0;
  }
LAB_10016bc1:
  if (param_1[6] != 0) {
    *(undefined4 *)(param_1[6] + 0x3c) = 0;
    iVar6 = RwDestroyRaster((undefined4 *)param_1[6]);
    if (iVar6 == 0) {
      local_8 = 0;
    }
  }
  if (param_1[7] != 0) {
    *(undefined4 *)(param_1[7] + 0x3c) = 0;
    iVar6 = RwDestroyRaster((undefined4 *)param_1[7]);
    if (iVar6 == 0) {
      local_8 = 0;
    }
  }
  FUN_10037010(DAT_1005abf0,param_1);
  return local_8;
}


