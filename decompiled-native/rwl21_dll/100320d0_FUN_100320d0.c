// 100320d0 FUN_100320d0 [Global]
// programa: RWL21.DLL

bool FUN_100320d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = (3 < *(byte *)((int)param_2 + 0x3a)) - 1 & (uint)param_2;
  if (uVar4 == 0) {
    uVar1 = *(undefined4 *)(PTR_DAT_1005b69c + 0x1c);
    *(undefined4 *)(PTR_DAT_1005b69c + 0x1c) = 3;
    uVar4 = FUN_10002d70((int)param_2);
    *(undefined4 *)(PTR_DAT_1005b69c + 0x1c) = uVar1;
  }
  if (uVar4 != 0) {
    puVar2 = (undefined4 *)param_2[0xc];
    puVar5 = param_2;
    if (puVar2 == (undefined4 *)0x0) {
LAB_1003214e:
      if (uVar4 == 0) goto LAB_10032181;
      do {
        if (puVar5 == (undefined4 *)0x0) break;
        puVar5[0xd] = param_1;
        piVar3 = FUN_10020c20(*(int **)(param_1 + 0x98),(int)puVar5);
        if (piVar3 == (int *)0x0) {
          uVar4 = 0;
        }
        if (uVar4 == 0) break;
        *(int **)(param_1 + 0x98) = piVar3;
        puVar5 = (undefined4 *)puVar5[0xc];
      } while (uVar4 != 0);
    }
    else {
      piVar3 = FUN_10020c20(*(int **)(param_1 + 0x9c),(int)param_2);
      if (piVar3 == (int *)0x0) {
        uVar4 = 0;
      }
      if (uVar4 != 0) {
        *(int **)(param_1 + 0x9c) = piVar3;
        piVar3 = (int *)RwGetPolygonMaterial(param_2);
        RwSetPolygonMaterial(param_2,piVar3);
        puVar5 = puVar2;
        goto LAB_1003214e;
      }
    }
    if (uVar4 != 0) goto LAB_10032187;
  }
LAB_10032181:
  FUN_100035a0((int)param_2);
LAB_10032187:
  return (bool)('\x01' - (uVar4 == 0));
}


