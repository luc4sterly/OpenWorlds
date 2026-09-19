// 10017740 RwCreateTexture [Global]
// programa: RWL21.DLL

int * RwCreateTexture(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
                    /* 0x17740  48  RwCreateTexture */
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
    return (int *)0x0;
  }
  iVar4 = RwSetTextureRaster((int)piVar3,param_1);
  if (iVar4 != 0) {
    return piVar3;
  }
  if (piVar3 == (int *)0x0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  piVar2 = (int *)*piVar3;
  if (piVar2 != (int *)0x0) {
    iVar4 = piVar2[2];
    iVar7 = 0;
    piVar1 = piVar2 + 2;
    if (0 < iVar4) {
      puVar6 = (undefined4 *)(*piVar2 + 4);
      do {
        if ((int *)*puVar6 == piVar3) goto LAB_100177e1;
        puVar6 = puVar6 + 2;
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar4);
    }
    iVar7 = -1;
LAB_100177e1:
    if (((iVar7 != -1) && (-1 < iVar7)) && (iVar7 < iVar4)) {
      iVar4 = *(int *)(*piVar2 + iVar7 * 8);
      if (iVar4 != 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar4);
      }
      iVar7 = iVar7 + 1;
      **(undefined4 **)(*piVar2 + -4 + iVar7 * 8) = 0;
      if (iVar7 < *piVar1) {
        iVar4 = iVar7 * 8;
        do {
          iVar7 = iVar7 + 1;
          ((undefined4 *)(*piVar2 + iVar4))[-2] = *(undefined4 *)(*piVar2 + iVar4);
          iVar5 = *piVar2 + iVar4;
          iVar4 = iVar4 + 8;
          *(undefined4 *)(iVar5 + -4) = *(undefined4 *)(iVar5 + 4);
        } while (iVar7 < *piVar1);
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
  return (int *)0x0;
}


