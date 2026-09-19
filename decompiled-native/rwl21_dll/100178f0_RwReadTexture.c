// 100178f0 RwReadTexture [Global]
// programa: RWL21.DLL

int * RwReadTexture(char *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
                    /* 0x178f0  330  RwReadTexture */
  piVar2 = FUN_10037030(DAT_1005abf0);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    FUN_1000cba0(3);
  }
  else {
    *piVar2 = 0;
    piVar2[3] = 0;
    piVar2[4] = 0;
    piVar2[5] = 1;
    piVar2[1] = 0;
    piVar2[2] = 0;
    piVar2[6] = 0;
    piVar2[7] = 0;
    piVar2[8] = 0;
  }
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar3 = FUN_10017b60(param_1);
  if (piVar3 == (int *)0x0) {
    if (piVar2 != (int *)0x0) {
      piVar3 = (int *)*piVar2;
      if (piVar3 != (int *)0x0) {
        iVar4 = piVar3[2];
        iVar7 = 0;
        piVar1 = piVar3 + 2;
        if (0 < iVar4) {
          puVar6 = (undefined4 *)(*piVar3 + 4);
          do {
            if ((int *)*puVar6 == piVar2) goto LAB_10017aa0;
            puVar6 = puVar6 + 2;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar4);
        }
        iVar7 = -1;
LAB_10017aa0:
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
              iVar5 = *piVar3 + iVar4;
              iVar4 = iVar4 + 8;
              *(undefined4 *)(iVar5 + -4) = *(undefined4 *)(iVar5 + 4);
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
      return (int *)0x0;
    }
  }
  else {
    puVar6 = (undefined4 *)piVar3[0xc];
    piVar3[0xc] = 0;
    iVar4 = RwSetTextureRaster((int)piVar2,(int)piVar3);
    if (iVar4 != 0) {
      if (puVar6 != (undefined4 *)0x0) {
        iVar4 = RwSetTextureMipmapRaster((int)piVar2,(int)puVar6);
      }
      if (iVar4 != 0) {
        return piVar2;
      }
    }
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[0xf] = 0;
      RwDestroyRaster(puVar6);
    }
    iVar4 = 0;
    piVar3[0xf] = 0;
    RwDestroyRaster(piVar3);
    piVar2[7] = 0;
    piVar2[6] = 0;
    if (piVar2 != (int *)0x0) {
      piVar3 = (int *)*piVar2;
      if (piVar3 != (int *)0x0) {
        iVar7 = piVar3[2];
        piVar1 = piVar3 + 2;
        if (0 < iVar7) {
          puVar6 = (undefined4 *)(*piVar3 + 4);
          do {
            if ((int *)*puVar6 == piVar2) goto LAB_100179ce;
            puVar6 = puVar6 + 2;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar7);
        }
        iVar4 = -1;
LAB_100179ce:
        if (((iVar4 != -1) && (-1 < iVar4)) && (iVar4 < iVar7)) {
          iVar7 = *(int *)(*piVar3 + iVar4 * 8);
          if (iVar7 != 0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar7);
          }
          iVar4 = iVar4 + 1;
          **(undefined4 **)(*piVar3 + -4 + iVar4 * 8) = 0;
          if (iVar4 < *piVar1) {
            iVar7 = iVar4 * 8;
            do {
              iVar4 = iVar4 + 1;
              ((undefined4 *)(*piVar3 + iVar7))[-2] = *(undefined4 *)(*piVar3 + iVar7);
              iVar5 = *piVar3 + iVar7;
              iVar7 = iVar7 + 8;
              *(undefined4 *)(iVar5 + -4) = *(undefined4 *)(iVar5 + 4);
            } while (iVar4 < *piVar1);
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
      return (int *)0x0;
    }
  }
  FUN_1000cba0(1);
  return (int *)0x0;
}


