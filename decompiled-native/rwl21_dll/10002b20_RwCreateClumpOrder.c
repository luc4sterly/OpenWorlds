// 10002b20 RwCreateClumpOrder [Global]
// program: RWL21.DLL

void RwCreateClumpOrder(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
                    /* 0x2b20  39  RwCreateClumpOrder */
  piVar2 = FUN_10020b70(**(int **)(param_1 + 0x98));
  if (piVar2 != (int *)0x0) {
    iVar4 = 0;
    iVar1 = **(int **)(param_1 + 0x98);
    *piVar2 = iVar1;
    if (0 < iVar1) {
      piVar3 = piVar2 + 2;
      do {
        iVar1 = *param_2;
        param_2 = param_2 + 1;
        iVar4 = iVar4 + 1;
        *piVar3 = *(int *)(*(int *)(param_1 + 0x98) + 8 + iVar1 * 4);
        piVar3 = piVar3 + 1;
      } while (iVar4 < *piVar2);
    }
  }
  return;
}


