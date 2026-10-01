// 10001740 RwReversePolygonFace [Global]
// program: RWL21.DLL

int RwReversePolygonFace(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
                    /* 0x1740  353  RwReversePolygonFace */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if (*(int *)(param_1 + 0x34) != 0) {
      uVar2 = RwGetClumpHints(*(int *)(param_1 + 0x34));
      if ((uVar2 & 4) == 0) {
        iVar3 = RwAddHintToClump(*(int *)(param_1 + 0x34),4);
        if (iVar3 == 0) {
          return 0;
        }
      }
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      RwReversePolygonFace(*(int *)(param_1 + 0x30));
    }
    *(float *)(param_1 + 0x10) = -*(float *)(param_1 + 0x10);
    *(float *)(param_1 + 0x14) = -*(float *)(param_1 + 0x14);
    iVar3 = 0;
    *(float *)(param_1 + 0x18) = -*(float *)(param_1 + 0x18);
    if ((*(byte *)(param_1 + 0x3a) & 0xfe) != 0) {
      do {
        uVar1 = *(undefined4 *)(param_1 + 0x3c + iVar3 * 4);
        *(undefined4 *)(param_1 + 0x3c + iVar3 * 4) =
             *(undefined4 *)(param_1 + 0x38 + ((uint)*(byte *)(param_1 + 0x3a) - iVar3) * 4);
        iVar4 = (uint)*(byte *)(param_1 + 0x3a) - iVar3;
        iVar3 = iVar3 + 1;
        *(undefined4 *)(param_1 + 0x38 + iVar4 * 4) = uVar1;
      } while (iVar3 < (int)(uint)(*(byte *)(param_1 + 0x3a) >> 1));
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      if ((*(int *)(param_1 + 0x2c) == param_1) && (iVar3 = 0, *(char *)(param_1 + 0x3a) != '\0')) {
        piVar5 = (int *)(param_1 + 0x3c);
        do {
          iVar4 = *piVar5;
          piVar5 = piVar5 + 1;
          iVar3 = iVar3 + 1;
          FUN_10041df0(iVar4);
        } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x3a));
      }
      *(undefined4 *)(*(int *)(param_1 + 0x34) + 0xc0) = 0;
      return param_1;
    }
  }
  return param_1;
}


