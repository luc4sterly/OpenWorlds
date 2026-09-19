// 10008dd0 RwGetClumpRoot [Global]
// programa: RWL21.DLL

int RwGetClumpRoot(int param_1)

{
  int iVar1;
  
                    /* 0x8dd0  165  RwGetClumpRoot */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x174);
  while (iVar1 != 0) {
    param_1 = *(int *)(param_1 + 0x174);
    iVar1 = *(int *)(param_1 + 0x174);
  }
  return param_1;
}


