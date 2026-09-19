// 10003660 FUN_10003660 [Global]
// programa: RWL21.DLL

bool FUN_10003660(uint param_1,undefined4 *param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *local_4;
  
  uVar5 = 0;
  param_2[0xb] = param_2;
  pbVar1 = (byte *)((int)param_2 + 0x3a);
  local_4 = (undefined4 *)0x0;
  if (*(int *)(PTR_DAT_1005b69c + 0x2c8) == 0) {
    if (*pbVar1 != 0) {
      piVar4 = param_2 + 0xf;
      do {
        iVar3 = FUN_10042030(*piVar4,param_2);
        if (iVar3 == 0) break;
        piVar4 = piVar4 + 1;
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < (int)(uint)*pbVar1);
    }
  }
  else {
    uVar5 = (uint)*pbVar1;
  }
  if ((int)uVar5 < (int)(uint)*pbVar1) {
    if (uVar5 != 0) {
      piVar4 = param_2 + uVar5 + 0xe;
      do {
        uVar5 = uVar5 - 1;
        iVar3 = *piVar4;
        piVar4 = piVar4 + -1;
        FUN_10042180(iVar3,(int)param_2);
      } while (uVar5 != 0);
    }
    param_2[0xd] = 0;
    goto LAB_100037c0;
  }
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
  if (*(int *)(PTR_DAT_1005b69c + 0x2c8) == 0) {
    local_4 = (undefined4 *)FUN_10002d70((int)param_2);
  }
  else {
    local_4 = param_2;
  }
  if (local_4 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)param_2[0xc];
    puVar6 = param_2;
    if (puVar2 == (undefined4 *)0x0) {
LAB_10003736:
      if (local_4 == (undefined4 *)0x0) goto LAB_10003793;
      do {
        if (puVar6 == (undefined4 *)0x0) break;
        puVar6[0xd] = param_1;
        piVar4 = FUN_10020c20(*(int **)(param_1 + 0x98),(int)puVar6);
        if (piVar4 == (int *)0x0) {
          local_4 = (undefined4 *)0x0;
        }
        if (local_4 == (undefined4 *)0x0) break;
        *(int **)(param_1 + 0x98) = piVar4;
        if (*(int *)(PTR_DAT_1005b69c + 0x2c8) == 0) {
          FUN_10032980(param_1);
        }
        puVar6 = (undefined4 *)puVar6[0xc];
      } while (local_4 != (undefined4 *)0x0);
    }
    else {
      piVar4 = FUN_10020c20(*(int **)(param_1 + 0x9c),(int)param_2);
      if (piVar4 == (int *)0x0) {
        local_4 = (undefined4 *)0x0;
      }
      if (local_4 != (undefined4 *)0x0) {
        *(int **)(param_1 + 0x9c) = piVar4;
        param_2[0xd] = param_1;
        piVar4 = (int *)RwGetPolygonMaterial(param_2);
        RwSetPolygonMaterial(param_2,piVar4);
        puVar6 = puVar2;
        goto LAB_10003736;
      }
    }
    if (local_4 != (undefined4 *)0x0) goto LAB_100037c0;
  }
LAB_10003793:
  FUN_100035a0((int)param_2);
LAB_100037c0:
  return (bool)('\x01' - (local_4 == (undefined4 *)0x0));
}


