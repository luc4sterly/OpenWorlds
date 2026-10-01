// 10002ba0 RwSetClumpOrder [Global]
// program: RWL21.DLL

int * RwSetClumpOrder(int param_1,int *param_2)

{
  int *piVar1;
  
                    /* 0x2ba0  388  RwSetClumpOrder */
  piVar1 = *(int **)(param_1 + 0x98);
  if ((*piVar1 == *param_2) && (*(int *)(param_2[2] + 0x34) == param_1)) {
    *(int **)(param_1 + 0x98) = param_2;
    return piVar1;
  }
  return (int *)0x0;
}


