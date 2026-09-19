// 10001020 RwSetPolygonMaterial [Global]
// programa: RWL21.DLL

undefined4 * RwSetPolygonMaterial(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
                    /* 0x1020  437  RwSetPolygonMaterial */
  if (param_2 == (int *)0x0) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  if (param_1 != (undefined4 *)0x0) {
    puVar3 = param_1;
    if (param_1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
      FUN_1000cba0(1);
      goto LAB_1000105d;
    }
    do {
      piVar2 = (int *)*puVar3;
LAB_1000105d:
      if (piVar2 != param_2) {
        *puVar3 = param_2;
        param_2[0x10] = param_2[0x10] + 1;
        if (piVar2 != (int *)0x0) {
          if ((undefined4 *)puVar3[0xb] == puVar3) {
            FUN_10020cf0((int *)piVar2[0xf],(int)puVar3);
          }
          RwDestroyMaterial(piVar2);
        }
        if ((undefined4 *)puVar3[0xb] == puVar3) {
          piVar2 = FUN_10020c20((int *)param_2[0xf],(int)puVar3);
          param_2[0xf] = (int)piVar2;
        }
      }
      puVar3 = (undefined4 *)puVar3[0xc];
    } while (puVar3 != (undefined4 *)0x0);
  }
  iVar4 = param_1[0xd];
  if (iVar4 != 0) {
    if (*(int *)(iVar4 + 0xe0) != *param_2) {
      *(undefined4 *)(iVar4 + 0xd8) = 1;
    }
    iVar4 = 0;
    if (*(char *)((int)param_1 + 0x3a) != '\0') {
      piVar2 = param_1 + 0xf;
      do {
        iVar1 = *piVar2;
        piVar2 = piVar2 + 1;
        iVar4 = iVar4 + 1;
        FUN_10041ec0(iVar1);
      } while (iVar4 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
    }
    *(undefined4 *)(param_1[0xd] + 0xc0) = 0;
  }
  return param_1;
}


