// 1000a290 FUN_1000a290 [Global]
// program: RWDL6D21.DLL

void FUN_1000a290(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  
  iVar2 = DAT_1007bda4;
  iVar7 = *param_2;
  if (DAT_1007bb4c != 8) {
    iVar7 = iVar7 * 2;
  }
  iVar9 = param_2[3];
  puVar8 = (undefined4 *)(iVar7 + *(int *)(DAT_10079218 + param_2[1] * 4));
  if (DAT_1007bb4c == 8) {
    if (iVar9 != 0) {
      uVar3 = (undefined1)*(undefined4 *)(param_1 + 0x9c);
      do {
        iVar9 = iVar9 + -1;
        uVar6 = param_2[2];
        puVar10 = puVar8;
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar10 = CONCAT22(CONCAT11(uVar3,uVar3),CONCAT11(uVar3,uVar3));
          puVar10 = puVar10 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar10 = uVar3;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        puVar8 = (undefined4 *)((int)puVar8 + iVar2);
      } while (iVar9 != 0);
      return;
    }
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x98);
    while (iVar9 != 0) {
      iVar9 = iVar9 + -1;
      uVar6 = param_2[2];
      if (-1 < (int)(uVar6 - 1)) {
        uVar4 = (undefined2)uVar1;
        puVar10 = puVar8;
        for (uVar5 = uVar6 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar10 = CONCAT22(uVar4,uVar4);
          puVar10 = puVar10 + 1;
        }
        for (uVar6 = (uint)((uVar6 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined2 *)puVar10 = uVar4;
          puVar10 = (undefined4 *)((int)puVar10 + 2);
        }
      }
      puVar8 = (undefined4 *)((int)puVar8 + iVar2);
    }
  }
  return;
}


