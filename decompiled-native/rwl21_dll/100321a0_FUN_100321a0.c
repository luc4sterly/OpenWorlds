// 100321a0 FUN_100321a0 [Global]
// program: RWL21.DLL

int FUN_100321a0(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x34), iVar1 != 0)) {
    bVar3 = false;
    if ((*(int *)(param_1 + 0x30) != 0) &&
       (iVar5 = *(byte *)(param_1 + 0x3a) - 1, *(byte *)(param_1 + 0x3a) != 0)) {
      piVar7 = (int *)(param_1 + 0x3c + iVar5 * 4);
      do {
        iVar2 = *piVar7;
        if ((*(int *)(iVar2 + 0x68) < 0) &&
           (iVar6 = *(ushort *)(iVar2 + 0x6c) - 1, *(ushort *)(iVar2 + 0x6c) != 0)) {
          piVar4 = (int *)(*(int *)(iVar2 + 0x70) + iVar6 * 4);
          do {
            iVar2 = *piVar4;
            if (((*(int *)(iVar2 + 0x2c) == param_1) && (param_1 != iVar2)) &&
               (3 < *(byte *)(iVar2 + 0x3a))) {
              bVar3 = true;
            }
            piVar4 = piVar4 + -1;
            bVar8 = iVar6 != 0;
            iVar6 = iVar6 + -1;
          } while (bVar8);
        }
        piVar7 = piVar7 + -1;
        bVar8 = 0 < iVar5;
        iVar5 = iVar5 + -1;
      } while (bVar8);
    }
    if (((*(int *)(param_1 + 0x30) != 0) || (*(byte *)(param_1 + 0x3a) < 4)) && (!bVar3)) {
      return 0;
    }
    if (*(int *)(iVar1 + 0xb8) != iVar1) {
      if ((*(int *)(param_1 + 0x2c) == param_1) && (*(int *)(param_1 + 0x30) != 0)) {
        FUN_10020cf0(*(int **)(iVar1 + 0x9c),param_1);
      }
      FUN_10020d30(*(int **)(iVar1 + 0x98),param_1);
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      FUN_100035a0(*(int *)(param_1 + 0x30));
      RwDestroyPolygon(*(int **)(param_1 + 0x30));
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  return param_1;
}


