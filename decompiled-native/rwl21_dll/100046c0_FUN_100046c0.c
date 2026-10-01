// 100046c0 FUN_100046c0 [Global]
// program: RWL21.DLL

void FUN_100046c0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x174)) {
    if ((*(char *)(param_1 + 0x12d) != '\0') || (*(char *)(param_1 + 0x171) != '\0')) {
      iVar1 = param_1;
    }
  }
  if (iVar1 != 0) {
    FUN_10004700(iVar1,0,(float *)iVar1);
  }
  return;
}


