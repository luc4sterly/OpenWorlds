// 1001b510 RwCopyMaterial [Global]
// program: RWL21.DLL

undefined4 * RwCopyMaterial(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
                    /* 0x1b510  35  RwCopyMaterial */
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    if (param_2 != param_1) {
      puVar5 = param_2;
      for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *param_1;
        param_1 = param_1 + 1;
        puVar5 = puVar5 + 1;
      }
      piVar1 = (int *)param_2[0xf];
      iVar3 = 0;
      if (0 < *piVar1) {
        piVar4 = piVar1 + 2;
        do {
          iVar2 = *piVar4;
          if (*(int *)(iVar2 + 0x2c) == iVar2) {
            FUN_1001a2f0(iVar2);
          }
          piVar4 = piVar4 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < *piVar1);
      }
      piVar1 = (int *)param_2[0xf];
      iVar3 = 0;
      if (0 < *piVar1) {
        piVar4 = piVar1 + 2;
        do {
          iVar2 = *piVar4;
          if (*(int *)(iVar2 + 0x2c) == iVar2) {
            FUN_1001a1e0(iVar2);
          }
          piVar4 = piVar4 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < *piVar1);
      }
    }
    return param_2;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


